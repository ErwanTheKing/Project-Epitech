#!/usr/bin/env python3
"""
╔═══════════════════════════════════════════════════════╗
║           CUDDLE — Python Test Suite                  ║
║     Re-implementation of pandas in C (libcuddle.a)    ║
╚═══════════════════════════════════════════════════════╝

Usage:
    python3 test_cuddle.py [--valgrind] [--verbose]

Requirements:
    pip install rich   (ou voir setup.sh)
"""

import subprocess
import tempfile
import os
import sys
import time
import argparse
import shutil
from pathlib import Path
from dataclasses import dataclass, field
from typing import Optional

try:
    from rich.console import Console
    from rich.panel import Panel
    from rich.table import Table
    from rich.progress import Progress, SpinnerColumn, BarColumn, TextColumn, TimeElapsedColumn
    from rich.syntax import Syntax
    from rich.text import Text
    from rich.columns import Columns
    from rich.rule import Rule
    from rich import box
    from rich.align import Align
    from rich.padding import Padding
    from rich.live import Live
    from rich.layout import Layout
    from rich.traceback import install
    install()
except ImportError:
    print("❌  'rich' not found. Run: pip install rich")
    sys.exit(1)

# ─────────────────────────────────────────────────────────────────────────────
# CONFIG
# ─────────────────────────────────────────────────────────────────────────────
console = Console()

COMPILER   = "gcc"
# Répertoire du script lui-même (fonctionne peu importe d'où on le lance)
SCRIPT_DIR = Path(__file__).resolve().parent
LIB_DIR    = SCRIPT_DIR.parent
LIB_PATH   = LIB_DIR / "libcuddle.a"
MY_LIB_PATH = None
INCLUDE    = LIB_DIR / "include"
BINARY     = Path(tempfile.mkdtemp()) / "cuddle_test_runner"
TMPDIR     = Path(tempfile.mkdtemp())

USE_VALGRIND = False
VERBOSE      = False

PALETTE = {
    "pass":    "#00e5a0",
    "fail":    "#ff4757",
    "warn":    "#ffa502",
    "info":    "#70a1ff",
    "dim":     "#57606f",
    "title":   "#eccc68",
    "section": "#a29bfe",
    "accent":  "#fd79a8",
}

# ─────────────────────────────────────────────────────────────────────────────
# DATA
# ─────────────────────────────────────────────────────────────────────────────
CSV_DATA = """\
name,age,city
Alice,25,Paris
Bob,30,London
Charlie,35,Berlin
Leo,25,Paris
Nathan,30,London
Alex,35,Berlin
Paul,25,Paris
"""

CSV_SEMICOLON = """\
name;age;city
Alice;25;Paris
Bob;30;London
"""

CSV_TYPES = """\
id,score,active,label
1,3.14,true,hello
2,2.71,false,world
-3,1.00,true,test
"""

CSV_MONEY = """\
name,amount
Alice,25
Bob,30
Leo,25
"""

CSV_NEGATIVE = """\
name,balance
Alice,-100
Bob,200
Charlie,-50
"""

# ─────────────────────────────────────────────────────────────────────────────
# RESULT
# ─────────────────────────────────────────────────────────────────────────────
@dataclass
class TestResult:
    name:     str
    passed:   bool
    section:  str
    stdout:   str = ""
    stderr:   str = ""
    expected: str = ""
    actual:   str = ""
    note:     str = ""

results: list[TestResult] = []

def record(name: str, passed: bool, section: str, **kw) -> TestResult:
    r = TestResult(name=name, passed=passed, section=section, **kw)
    results.append(r)
    return r

# ─────────────────────────────────────────────────────────────────────────────
# HELPERS
# ─────────────────────────────────────────────────────────────────────────────
def csv(name: str, content: str) -> Path:
    p = TMPDIR / name
    p.write_text(content)
    return p

def write_c(code: str) -> Path:
    p = TMPDIR / f"test_{abs(hash(code))}.c"
    p.write_text(code)
    return p

def compile_and_run(c_code: str, section: str, test_name: str,
                    extra_files: list[str] | None = None) -> tuple[int, str, str]:
    """
    Retourne (rc, stdout, stderr).
    rc est TOUJOURS le code du binaire (0 = succes logique),
    independamment de valgrind. Les fuites sont annotees separement.
    """
    src  = write_c(c_code)
    bin_ = TMPDIR / f"bin_{abs(hash(c_code))}"
    extra  = extra_files or []

    cmd = [
        COMPILER, "-Wall", "-Wno-unused-function",
        f"-I{INCLUDE}", str(src), *extra,
        f"-L{LIB_DIR}", f"-L{LIB_DIR / 'lib'}", "-lcuddle", "-lm",
        "-o", str(bin_)
    ]

    cp = subprocess.run(cmd, capture_output=True, text=True)
    if cp.returncode != 0:
        record(test_name, False, section,
               stderr=cp.stderr, note="Compilation failed")
        return -1, "", cp.stderr

    # Execution normale : on recupere le vrai rc du binaire
    rp = subprocess.run([str(bin_)], capture_output=True, text=True, timeout=10)
    prog_rc  = rp.returncode
    prog_out = rp.stdout.strip()
    prog_err = rp.stderr.strip()

    # Valgrind en parallele uniquement pour detecter les fuites
    if USE_VALGRIND:
        vg = subprocess.run(
            ["valgrind", "--leak-check=full", "--show-leak-kinds=all",
             "--error-exitcode=42", str(bin_)],
            capture_output=True, text=True, timeout=15
        )
        if vg.returncode == 42:
            leak_lines = [l for l in vg.stderr.splitlines()
                          if "definitely lost" in l or "indirectly lost" in l
                          or "ERROR SUMMARY" in l]
            leak_note = " | ".join(leak_lines[:3]) if leak_lines else "fuite memoire detectee"
            record(f"[Valgrind] {test_name}", False, section,
                   stderr=vg.stderr[-600:], note=leak_note)

    return prog_rc, prog_out, prog_err

# ─────────────────────────────────────────────────────────────────────────────
# SECTION PRINTER
# ─────────────────────────────────────────────────────────────────────────────
def print_section(title: str):
    console.print()
    console.print(Rule(
        f"[bold {PALETTE['section']}] {title} [/]",
        style=PALETTE["dim"]
    ))

def print_test(r: TestResult):
    icon  = f"[{PALETTE['pass']}]✓[/]" if r.passed else f"[{PALETTE['fail']}]✗[/]"
    color = PALETTE["pass"] if r.passed else PALETTE["fail"]
    line  = f"  {icon} [{color}]{r.name}[/]"
    if r.note:
        line += f" [dim]— {r.note}[/]"
    console.print(line)
    if not r.passed and VERBOSE:
        if r.expected or r.actual:
            console.print(f"     [dim]expected:[/] [yellow]{r.expected}[/]")
            console.print(f"     [dim]actual  :[/] [red]{r.actual}[/]")
        if r.stderr:
            console.print(Syntax(r.stderr[:400], "text", theme="monokai",
                                 background_color="default"))

# ─────────────────────────────────────────────────────────────────────────────
# ░░░  TEST CASES  ░░░
# ─────────────────────────────────────────────────────────────────────────────

# ── 1. READ / WRITE ──────────────────────────────────────────────────────────
def test_read_write():
    SEC = "df_read_csv / df_write_csv"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    # Basic read
    code = f"""
#include "dataframe.h"
#include <stdio.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    if (!df) return 1;
    printf("%d %d\\n", df->nb_rows, df->nb_columns);
    df_free(df);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "df_read_csv retourne non-NULL")
    passed = rc == 0 and out == "7 3"
    r = record("df_read_csv — nb_rows=7, nb_columns=3", passed, SEC,
               expected="7 3", actual=out)
    print_test(r)

    # Write + reread
    out_csv = TMPDIR / "out.csv"
    code = f"""
#include "dataframe.h"
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    if (!df) return 1;
    int r = df_write_csv(df, "{out_csv}");
    df_free(df);
    return r;
}}"""
    rc, out, err = compile_and_run(code, SEC, "df_write_csv retourne 0")
    passed = rc == 0
    r = record("df_write_csv retourne 0", passed, SEC)
    print_test(r)

    # Reread written file
    if out_csv.exists():
        code2 = f"""
#include "dataframe.h"
#include <stdio.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{out_csv}", NULL);
    if (!df) return 1;
    printf("%d %d\\n", df->nb_rows, df->nb_columns);
    df_free(df);
    return 0;
}}"""
        rc, out, err = compile_and_run(code2, SEC, "Relecture CSV écrit")
        passed = rc == 0 and out == "7 3"
        r = record("Relecture du CSV écrit — 7×3", passed, SEC,
                   expected="7 3", actual=out)
        print_test(r)

    # Custom separator
    semi = csv("semi.csv", CSV_SEMICOLON)
    code = f"""
#include "dataframe.h"
#include <stdio.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{semi}", ";");
    if (!df) return 1;
    printf("%d %d\\n", df->nb_rows, df->nb_columns);
    df_free(df);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "Séparateur ';'")
    passed = rc == 0 and out == "2 3"
    r = record("Séparateur personnalisé ';' — 2×3", passed, SEC,
               expected="2 3", actual=out)
    print_test(r)

    # Non-existent file
    code = f"""
#include "dataframe.h"
int main(void) {{
    dataframe_t *df = df_read_csv("/tmp/no_such_file_cuddle.csv", NULL);
    return df == NULL ? 0 : 1;
}}"""
    rc, out, err = compile_and_run(code, SEC, "Fichier inexistant => NULL")
    r = record("Fichier inexistant → NULL", rc == 0, SEC)
    print_test(r)


# ── 2. TYPES ─────────────────────────────────────────────────────────────────
def test_types():
    SEC = "Détection des types"
    print_section(SEC)
    types_csv = csv("types.csv", CSV_TYPES)

    cases = [
        ("unsigned int", "age", csv("data.csv", CSV_DATA)),
        ("string",       "name", csv("data.csv", CSV_DATA)),
        ("float",        "score", types_csv),
        ("bool",         "active", types_csv),
        ("int",          "id", types_csv),
    ]

    for expected_type, col, file in cases:
        code = f"""
#include "dataframe.h"
#include <stdio.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{file}", NULL);
    if (!df) return 1;
    df_info(df);
    df_free(df);
    return 0;
}}"""
        rc, out, err = compile_and_run(code, SEC, f"type {col}")
        passed = rc == 0 and expected_type in out
        r = record(f"Colonne '{col}' détectée comme {expected_type}",
                   passed, SEC, expected=expected_type, actual=out)
        print_test(r)


# ── 3. HEAD / TAIL ────────────────────────────────────────────────────────────
def test_head_tail():
    SEC = "df_head / df_tail"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    subtests = [
        ("head_3", "df_head(df, 3)", "3 3", "Alice", 0),
        ("head_0", "df_head(df, 0)", "0 3", None,    0),
        ("head_big","df_head(df,100)","7 3", "Alice", 0),
        ("tail_3", "df_tail(df, 3)", "3 3", "Nathan", 0),
        ("tail_0", "df_tail(df, 0)", "0 3", None,    0),
    ]

    for tag, call, shape, first_name, _ in subtests:
        out_csv = TMPDIR / f"{tag}.csv"
        code = f"""
#include "dataframe.h"
#include <stdio.h>
#include <string.h>
int main(void) {{
    dataframe_t *df  = df_read_csv("{data}", NULL);
    dataframe_t *sub = {call};
    if (!sub) {{ printf("NULL\\n"); return 1; }}
    printf("%d %d\\n", sub->nb_rows, sub->nb_columns);
    {"void *v = df_get_value(sub, 0, \"name\"); if(v) printf(\"%s\\n\", (char*)v);" if first_name else ""}
    df_free(df); df_free(sub);
    return 0;
}}"""
        rc, out, err = compile_and_run(code, SEC, tag)
        lines  = out.split("\n")
        passed = rc == 0 and lines[0] == shape
        if first_name and passed:
            passed = len(lines) > 1 and lines[1] == first_name
        label = f"{call} → shape={shape}" + (f", first={first_name}" if first_name else "")
        r = record(label, passed, SEC, expected=shape, actual=lines[0] if lines else "")
        print_test(r)


# ── 4. SHAPE ─────────────────────────────────────────────────────────────────
def test_shape():
    SEC = "df_shape"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    code = f"""
#include "dataframe.h"
#include <stdio.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    dataframe_shape_t s = df_shape(df);
    printf("%d %d\\n", s.nb_rows, s.nb_columns);
    df_free(df);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "shape")
    passed = rc == 0 and out == "7 3"
    r = record("df_shape → {nb_rows=7, nb_columns=3}", passed, SEC,
               expected="7 3", actual=out)
    print_test(r)


# ── 5. INFO ───────────────────────────────────────────────────────────────────
def test_info():
    SEC = "df_info"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    code = f"""
#include "dataframe.h"
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    df_info(df);
    df_free(df);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "info")

    checks = [
        ("Affiche le nombre de colonnes",    "3 columns" in out or "3 colonnes" in out),
        ("Affiche 'name' comme string",       "name" in out and "string" in out),
        ("Affiche 'age' comme unsigned int",  "age" in out and "unsigned int" in out),
        ("Affiche 'city' comme string",       "city" in out and "string" in out),
    ]
    for label, cond in checks:
        r = record(label, rc == 0 and cond, SEC, actual=out[:200])
        print_test(r)


# ── 6. DESCRIBE ───────────────────────────────────────────────────────────────
def test_describe():
    SEC = "df_describe"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    code = f"""
#include "dataframe.h"
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    df_describe(df);
    df_free(df);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "describe")

    checks = [
        ("Affiche la colonne 'age'",    "age" in out),
        ("Count == 7",                  "7" in out),
        ("Mean ≈ 29.29",               "29.29" in out or "29.28" in out),
        ("Min == 25.00",               "25.00" in out or "25" in out),
        ("Max == 35.00",               "35.00" in out or "35" in out),
    ]
    for label, cond in checks:
        r = record(label, rc == 0 and cond, SEC, actual=out[:300])
        print_test(r)


# ── 7. FILTER ─────────────────────────────────────────────────────────────────
def test_filter():
    SEC = "df_filter"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    # age > 30 → Charlie (35) + Alex (35) = 2 rows
    code = f"""
#include "dataframe.h"
#include <stdio.h>
#include <stdbool.h>
bool f(void *v) {{ return *(unsigned int*)v > 30; }}
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    dataframe_t *r  = df_filter(df, "age", f);
    if (!r) return 1;
    printf("%d\\n", r->nb_rows);
    void *n0 = df_get_value(r, 0, "name");
    void *n1 = df_get_value(r, 1, "name");
    if (n0) printf("%s\\n", (char*)n0);
    if (n1) printf("%s\\n", (char*)n1);
    df_free(df); df_free(r);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "filter age>30")
    lines  = out.split("\n")
    r = record("age > 30 → 2 lignes", rc == 0 and lines[0] == "2", SEC,
               expected="2", actual=lines[0] if lines else "")
    print_test(r)
    r = record("Résultats : Charlie & Alex", rc == 0 and "Charlie" in out and "Alex" in out,
               SEC, expected="Charlie, Alex", actual=out)
    print_test(r)

    # age == 25 → 3 rows
    code = f"""
#include "dataframe.h"
#include <stdio.h>
#include <stdbool.h>
bool f(void *v) {{ return *(unsigned int*)v == 25; }}
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    dataframe_t *r  = df_filter(df, "age", f);
    if (!r) return 1;
    printf("%d\\n", r->nb_rows);
    df_free(df); df_free(r);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "filter age==25")
    r = record("age == 25 → 3 lignes", rc == 0 and out == "3", SEC,
               expected="3", actual=out)
    print_test(r)

    # filter → 0 results
    code = f"""
#include "dataframe.h"
#include <stdio.h>
#include <stdbool.h>
bool f(void *v) {{ (void)v; return 0; }}
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    dataframe_t *r  = df_filter(df, "age", f);
    if (!r) return 1;
    printf("%d\\n", r->nb_rows);
    df_free(df); df_free(r);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "filter vide")
    r = record("Filtre vide → 0 lignes", rc == 0 and out == "0", SEC,
               expected="0", actual=out)
    print_test(r)

    # bad column
    code = f"""
#include "dataframe.h"
#include <stdbool.h>
bool f(void *v) {{ (void)v; return 1; }}
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    dataframe_t *r  = df_filter(df, "nonexistent", f);
    df_free(df);
    return r == NULL ? 0 : 1;
}}"""
    rc, out, err = compile_and_run(code, SEC, "colonne inexistante")
    r = record("Colonne inexistante → NULL", rc == 0, SEC)
    print_test(r)


# ── 8. SORT ───────────────────────────────────────────────────────────────────
def test_sort():
    SEC = "df_sort"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    code = f"""
#include "dataframe.h"
#include <stdio.h>
#include <stdbool.h>
bool asc(void *a, void *b)  {{ return *(unsigned int*)a > *(unsigned int*)b; }}
bool desc(void *a, void *b) {{ return *(unsigned int*)a < *(unsigned int*)b; }}
int main(void) {{
    dataframe_t *df   = df_read_csv("{data}", NULL);
    dataframe_t *sasc = df_sort(df, "age", asc);
    dataframe_t *sdsc = df_sort(df, "age", desc);
    if (!sasc || !sdsc) return 1;
    unsigned int *first_asc  = df_get_value(sasc, 0, "age");
    unsigned int *last_asc   = df_get_value(sasc, 6, "age");
    unsigned int *first_desc = df_get_value(sdsc, 0, "age");
    unsigned int *last_desc  = df_get_value(sdsc, 6, "age");
    printf("%u %u\\n", *first_asc,  *last_asc);
    printf("%u %u\\n", *first_desc, *last_desc);
    printf("%d\\n", sasc->nb_rows);
    df_free(df); df_free(sasc); df_free(sdsc);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "sort")
    lines = out.split("\n")

    checks = [
        ("Tri ASC : premier=25, dernier=35",  rc == 0 and len(lines) > 0 and lines[0] == "25 35"),
        ("Tri DESC: premier=35, dernier=25",  rc == 0 and len(lines) > 1 and lines[1] == "35 25"),
        ("Tri conserve nb_rows=7",            rc == 0 and len(lines) > 2 and lines[2] == "7"),
    ]
    for label, cond in checks:
        r = record(label, cond, SEC, actual=out[:200])
        print_test(r)

    code = f"""
#include "dataframe.h"
#include <stdbool.h>
bool f(void *a, void *b) {{ (void)a; (void)b; return 0; }}
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    dataframe_t *r  = df_sort(df, "nope", f);
    df_free(df);
    return r == NULL ? 0 : 1;
}}"""
    rc, _, _ = compile_and_run(code, SEC, "sort bad col")
    r = record("Colonne inexistante → NULL", rc == 0, SEC)
    print_test(r)


# ── 9. GROUPBY ────────────────────────────────────────────────────────────────
def test_groupby():
    SEC = "df_groupby"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    code = f"""
#include "dataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *agg(void **vals, int n) {{
    int *s = malloc(sizeof(int)); *s = 0;
    for (int i = 0; i < n; i++) *s += *(int*)vals[i];
    return s;
}}
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    const char *cols[] = {{"age", NULL}};
    dataframe_t *g  = df_groupby(df, "city", cols, agg);
    if (!g) return 1;
    printf("%d %d\\n", g->nb_rows, g->nb_columns);
    for (int i = 0; i < g->nb_rows; i++) {{
        char *city = df_get_value(g, i, "city");
        int  *age  = df_get_value(g, i, "age");
        if (city && age) printf("%s=%d\\n", city, *age);
    }}
    df_free(df); df_free(g);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "groupby city sum age")
    lines = out.split("\n")

    checks = [
        ("3 groupes, 2 colonnes",          rc == 0 and lines[0] == "3 2"),
        ("Paris  → sum=75",                rc == 0 and "Paris=75"  in out),
        ("London → sum=60",                rc == 0 and "London=60" in out),
        ("Berlin → sum=70",                rc == 0 and "Berlin=70" in out),
    ]
    for label, cond in checks:
        r = record(label, cond, SEC, actual=out[:300])
        print_test(r)


# ── 10. APPLY ─────────────────────────────────────────────────────────────────
def test_apply():
    SEC = "df_apply"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    code = f"""
#include "dataframe.h"
#include <stdio.h>
#include <stdlib.h>
void *dbl(void *v) {{
    unsigned int *r = malloc(sizeof(unsigned int));
    *r = *(unsigned int*)v * 2;
    return r;
}}
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    dataframe_t *ap = df_apply(df, "age", dbl);
    if (!ap) return 1;
    printf("%d\\n", ap->nb_rows);
    unsigned int *v0 = df_get_value(ap, 0, "age");
    unsigned int *v1 = df_get_value(ap, 1, "age");
    unsigned int *v2 = df_get_value(ap, 2, "age");
    char *name = df_get_value(ap, 0, "name");
    if (v0) printf("%u\\n", *v0);
    if (v1) printf("%u\\n", *v1);
    if (v2) printf("%u\\n", *v2);
    if (name) printf("%s\\n", name);
    df_free(df); df_free(ap);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "apply double")
    lines = out.split("\n")

    checks = [
        ("nb_rows conservé = 7",            rc == 0 and lines[0] == "7"),
        ("Alice: 25×2 = 50",                rc == 0 and len(lines) > 1 and lines[1] == "50"),
        ("Bob: 30×2 = 60",                  rc == 0 and len(lines) > 2 and lines[2] == "60"),
        ("Charlie: 35×2 = 70",              rc == 0 and len(lines) > 3 and lines[3] == "70"),
        ("Colonne 'name' inchangée",         rc == 0 and "Alice" in out),
    ]
    for label, cond in checks:
        r = record(label, cond, SEC, actual=out[:200])
        print_test(r)


# ── 11. TO_TYPE ───────────────────────────────────────────────────────────────
def test_to_type():
    SEC = "df_to_type"
    print_section(SEC)
    money = csv("money.csv", CSV_MONEY)

    subtests = [
        ("UINT → FLOAT",  "FLOAT",  money, "amount", 0, lambda o: "float" in o.lower()),
        ("UINT → STRING", "STRING", money, "amount", 0, lambda o: "string" in o.lower()),
        ("UINT → INT",    "INT",    money, "amount", 0, lambda o: o != "" and "NULL" not in o),
    ]
    for label, typ, file, col, _, check in subtests:
        code = f"""
#include "dataframe.h"
#include <stdio.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{file}", NULL);
    dataframe_t *t  = df_to_type(df, "{col}", {typ});
    if (!t) {{ printf("NULL\\n"); df_free(df); return 1; }}
    df_info(t);
    df_free(df); df_free(t);
    return 0;
}}"""
        rc, out, err = compile_and_run(code, SEC, label)
        r = record(label, rc == 0 and check(out), SEC, actual=out[:200])
        print_test(r)

    # Invalid conversion: STRING → INT
    bad = csv("bad.csv", "name,val\nAlice,hello\nBob,world\n")
    code = f"""
#include "dataframe.h"
int main(void) {{
    dataframe_t *df = df_read_csv("{bad}", NULL);
    dataframe_t *t  = df_to_type(df, "val", INT);
    df_free(df);
    return t == NULL ? 0 : 1;
}}"""
    rc, out, err = compile_and_run(code, SEC, "invalid STRING→INT")
    r = record("STRING 'hello' → INT invalide → NULL", rc == 0, SEC)
    print_test(r)


# ── 12. UTILITIES ─────────────────────────────────────────────────────────────
def test_utilities():
    SEC = "Utilitaires (get_value / get_values / get_unique)"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    # get_value
    code = f"""
#include "dataframe.h"
#include <stdio.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    char *name = df_get_value(df, 0, "name");
    unsigned int *age = df_get_value(df, 0, "age");
    char *city = df_get_value(df, 2, "city");
    void *bad_row = df_get_value(df, 999, "name");
    void *bad_col = df_get_value(df, 0, "nonexistent");
    if (name) printf("%s\\n", name);
    if (age)  printf("%u\\n", *age);
    if (city) printf("%s\\n", city);
    printf("%s\\n", bad_row == NULL ? "NULL" : "NOT_NULL");
    printf("%s\\n", bad_col == NULL ? "NULL" : "NOT_NULL");
    df_free(df);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "get_value")
    lines = out.split("\n")
    checks = [
        ("get_value(0,'name') == 'Alice'",       rc==0 and len(lines)>0 and lines[0]=="Alice"),
        ("get_value(0,'age') == 25",             rc==0 and len(lines)>1 and lines[1]=="25"),
        ("get_value(2,'city') == 'Berlin'",      rc==0 and len(lines)>2 and lines[2]=="Berlin"),
        ("get_value(999,'name') == NULL",        rc==0 and len(lines)>3 and lines[3]=="NULL"),
        ("get_value(0,'nonexistent') == NULL",   rc==0 and len(lines)>4 and lines[4]=="NULL"),
    ]
    for label, cond in checks:
        r = record(label, cond, SEC, actual=out[:200])
        print_test(r)

    # get_values
    code = f"""
#include "dataframe.h"
#include <stdio.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    void **vals = df_get_values(df, "age");
    if (!vals) return 1;
    int count = 0;
    while (vals[count]) count++;
    printf("%d\\n", count);
    printf("%u\\n", *(unsigned int*)vals[0]);
    void **bad = df_get_values(df, "nope");
    printf("%s\\n", bad == NULL ? "NULL" : "NOT_NULL");
    df_free(df);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "get_values")
    lines = out.split("\n")
    checks = [
        ("get_values('age') → 7 éléments",   rc==0 and len(lines)>0 and lines[0]=="7"),
        ("get_values[0] == 25",              rc==0 and len(lines)>1 and lines[1]=="25"),
        ("get_values('nope') == NULL",       rc==0 and len(lines)>2 and lines[2]=="NULL"),
    ]
    for label, cond in checks:
        r = record(label, cond, SEC, actual=out[:200])
        print_test(r)

    # get_unique_values
    code = f"""
#include "dataframe.h"
#include <stdio.h>
#include <string.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    void **uv = df_get_unique_values(df, "city");
    if (!uv) return 1;
    int count = 0;
    while (uv[count]) count++;
    printf("%d\\n", count);
    int has_paris=0, has_london=0, has_berlin=0;
    for (int i=0; i<count; i++) {{
        if (strcmp((char*)uv[i],"Paris")==0)  has_paris=1;
        if (strcmp((char*)uv[i],"London")==0) has_london=1;
        if (strcmp((char*)uv[i],"Berlin")==0) has_berlin=1;
    }}
    printf("%d %d %d\\n", has_paris, has_london, has_berlin);
    df_free(df);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "get_unique")
    lines = out.split("\n")
    checks = [
        ("3 villes uniques",          rc==0 and len(lines)>0 and lines[0]=="3"),
        ("Paris + London + Berlin",   rc==0 and len(lines)>1 and lines[1]=="1 1 1"),
    ]
    for label, cond in checks:
        r = record(label, cond, SEC, actual=out[:200])
        print_test(r)


# ── 13. FREE ──────────────────────────────────────────────────────────────────
def test_free():
    SEC = "df_free"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    code = f"""
#include "dataframe.h"
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    df_free(df);
    df_free(NULL);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "free")
    r = record("df_free + df_free(NULL) sans crash", rc == 0, SEC)
    print_test(r)

    if USE_VALGRIND:
        code2 = f"""
#include "dataframe.h"
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    df_free(df);
    return 0;
}}"""
        rc, out, err = compile_and_run(code2, SEC, "valgrind free")
        r = record("Valgrind — aucune fuite mémoire", rc == 0, SEC, note=err[:200] if rc else "")
        print_test(r)


# ── 14. INDEPENDENCE ──────────────────────────────────────────────────────────
def test_independence():
    SEC = "Indépendance des dataframes (deep copy)"
    print_section(SEC)
    data = csv("data.csv", CSV_DATA)

    code = f"""
#include "dataframe.h"
#include <stdio.h>
int main(void) {{
    dataframe_t *df = df_read_csv("{data}", NULL);
    dataframe_t *h  = df_head(df, 3);
    if (!h) return 1;
    /* Les pointeurs doivent être différents */
    void *ph = df_get_value(h,  0, "name");
    void *pd = df_get_value(df, 0, "name");
    printf("%s\\n", ph != pd ? "DIFF" : "SAME");
    /* Libérer df ne doit pas corrompre h */
    df_free(df);
    void *after = df_get_value(h, 0, "name");
    printf("%s\\n", (char*)after);
    df_free(h);
    return 0;
}}"""
    rc, out, err = compile_and_run(code, SEC, "independence")
    lines = out.split("\n")
    checks = [
        ("Pointeurs différents (deep copy)",         rc==0 and len(lines)>0 and lines[0]=="DIFF"),
        ("df_head valide après df_free(original)",   rc==0 and len(lines)>1 and lines[1]=="Alice"),
    ]
    for label, cond in checks:
        r = record(label, cond, SEC, actual=out[:200])
        print_test(r)


# ─────────────────────────────────────────────────────────────────────────────
# SUMMARY
# ─────────────────────────────────────────────────────────────────────────────
def print_summary():
    total   = len(results)
    passed  = sum(1 for r in results if r.passed)
    failed  = total - passed
    pct     = int(100 * passed / total) if total else 0

    console.print()
    console.print(Rule(style=PALETTE["dim"]))
    console.print()

    # Stats bar
    bar_width = 40
    filled    = int(bar_width * passed / total) if total else 0
    bar = (
        f"[{PALETTE['pass']}]{'█' * filled}[/]"
        f"[{PALETTE['fail']}]{'█' * (bar_width - filled)}[/]"
    )
    console.print(Align.center(bar))
    console.print()

    # Stats numbers
    stats = Table.grid(padding=(0, 4))
    stats.add_column(justify="center")
    stats.add_column(justify="center")
    stats.add_column(justify="center")
    stats.add_column(justify="center")
    stats.add_row(
        f"[{PALETTE['info']} bold]{total}[/]\n[dim]total[/]",
        f"[{PALETTE['pass']} bold]{passed}[/]\n[dim]passés[/]",
        f"[{PALETTE['fail']} bold]{failed}[/]\n[dim]échoués[/]",
        f"[{PALETTE['title']} bold]{pct}%[/]\n[dim]score[/]",
    )
    console.print(Align.center(stats))
    console.print()

    # Per-section table
    sections: dict[str, list[TestResult]] = {}
    for r in results:
        sections.setdefault(r.section, []).append(r)

    tbl = Table(
        box=box.ROUNDED,
        border_style=PALETTE["dim"],
        header_style=f"bold {PALETTE['section']}",
        show_lines=False,
        padding=(0, 1),
    )
    tbl.add_column("Section",  style="bold", min_width=36)
    tbl.add_column("Passés",   justify="center", min_width=8)
    tbl.add_column("Échoués",  justify="center", min_width=8)
    tbl.add_column("",         justify="center", min_width=10)

    for sec, rs in sections.items():
        sp = sum(1 for r in rs if r.passed)
        sf = len(rs) - sp
        dots = ""
        for r in rs:
            dots += f"[{PALETTE['pass']}]●[/]" if r.passed else f"[{PALETTE['fail']}]●[/]"
        tbl.add_row(
            sec,
            f"[{PALETTE['pass']}]{sp}[/]",
            f"[{PALETTE['fail']}]{sf}[/]" if sf else f"[{PALETTE['dim']}]{sf}[/]",
            dots,
        )

    console.print(Align.center(tbl))
    console.print()

    # Final verdict
    if failed == 0:
        verdict = Panel(
            Align.center(
                f"[bold {PALETTE['pass']}]✦  TOUS LES TESTS PASSENT  ✦[/]\n"
                f"[dim]Libcuddle est opérationnelle ![/]"
            ),
            border_style=PALETTE["pass"],
            padding=(1, 6),
        )
    else:
        verdict = Panel(
            Align.center(
                f"[bold {PALETTE['fail']}]✖  {failed} test(s) échoué(s)[/]\n"
                f"[dim]Lance avec --verbose pour voir les détails[/]"
            ),
            border_style=PALETTE["fail"],
            padding=(1, 6),
        )
    console.print(Align.center(verdict))
    console.print()

    return failed


# ─────────────────────────────────────────────────────────────────────────────
# HEADER
# ─────────────────────────────────────────────────────────────────────────────
def print_header():
    console.print()
    title = Text()
    title.append("  ╔═══════════════════════════════════════════╗\n", style=f"bold {PALETTE['dim']}")
    title.append("  ║  ", style=f"bold {PALETTE['dim']}")
    title.append("🐼  CUDDLE", style=f"bold {PALETTE['title']}")
    title.append("  —  Python Test Suite", style=f"bold {PALETTE['info']}")
    title.append("        ║\n", style=f"bold {PALETTE['dim']}")
    title.append("  ║  ", style=f"bold {PALETTE['dim']}")
    title.append("Re-implémentation de pandas en C", style=f"dim")
    title.append("         ║\n", style=f"bold {PALETTE['dim']}")
    title.append("  ╚═══════════════════════════════════════════╝", style=f"bold {PALETTE['dim']}")
    console.print(title)

    info = Table.grid(padding=(0, 2))
    info.add_column()
    info.add_column()
    info.add_row(f"[{PALETTE['dim']}]lib     :[/]", f"[{PALETTE['info']}]{LIB_PATH}[/]")
    info.add_row(f"[{PALETTE['dim']}]include :[/]", f"[{PALETTE['info']}]{INCLUDE}[/]")
    info.add_row(f"[{PALETTE['dim']}]my_lib  :[/]", f"[{PALETTE['info']}]{MY_LIB_PATH}[/]")
    info.add_row(f"[{PALETTE['dim']}]valgrind:[/]",
                 f"[{PALETTE['pass']}]activé[/]" if USE_VALGRIND else f"[{PALETTE['dim']}]désactivé (--valgrind)[/]")
    console.print(Padding(info, (1, 2)))


# ─────────────────────────────────────────────────────────────────────────────
# MAIN
# ─────────────────────────────────────────────────────────────────────────────
def main():
    global USE_VALGRIND, VERBOSE

    parser = argparse.ArgumentParser(description="CUDDLE Python Tester")
    parser.add_argument("--valgrind", action="store_true", help="Active Valgrind")
    parser.add_argument("--verbose",  action="store_true", help="Affiche les détails des échecs")
    args = parser.parse_args()
    USE_VALGRIND = args.valgrind
    VERBOSE      = args.verbose

    if not LIB_PATH.exists():
        console.print(f"[bold {PALETTE['fail']}]❌  libcuddle.a introuvable à {LIB_PATH}[/]")
        console.print(f"[dim]Lance 'make' dans le répertoire parent d'abord.[/]")
        sys.exit(1)
    # No check for libmy.a: it is not required anymore

    print_header()

    all_tests = [
        test_read_write,
        test_types,
        test_head_tail,
        test_shape,
        test_info,
        test_describe,
        test_filter,
        test_sort,
        test_groupby,
        test_apply,
        test_to_type,
        test_utilities,
        test_free,
        test_independence,
    ]

    with Progress(
        SpinnerColumn(style=PALETTE["accent"]),
        TextColumn("[progress.description]{task.description}"),
        BarColumn(bar_width=30, style=PALETTE["dim"],
                  complete_style=PALETTE["pass"]),
        TextColumn("[progress.percentage]{task.percentage:>3.0f}%"),
        TimeElapsedColumn(),
        console=console,
        transient=True,
    ) as progress:
        task = progress.add_task(
            f"[{PALETTE['info']}]Compilation & exécution des tests...",
            total=len(all_tests)
        )
        for fn in all_tests:
            progress.update(task, description=f"[{PALETTE['info']}]{fn.__name__}")
            fn()
            progress.advance(task)

    failed = print_summary()
    sys.exit(84 if failed else 0)


if __name__ == "__main__":
    main()
