# 🐼 Cuddle — DataFrame Library for C
![Pandas Logo](https://raw.githubusercontent.com/pandas-dev/pandas/main/web/pandas/static/img/pandas.svg)

Cuddle is a C library that brings a **pandas-inspired DataFrame API** to C.
It reads and writes CSV files, auto-detects column types, and exposes a
consistent functional interface for querying, transforming, filtering,
sorting and aggregating tabular data.

> ⚡️ **All utility functions (formerly libmy) are now part of libcuddle!**

---

## 🗂️ Repository Layout

```text
Cuddle/
├── Makefile                    🛠️ Top-level build / test / coverage orchestrator
├── Src/                       🏁 Application entry point (main.c)
├── include/                   📚 Public headers (dataframe.h · my.h · linked_lists.h · defines.h …)
├── lib/
│   └── Cuddle/                 🧩 libcuddle sources (Aggregation · Basics · Core · Filtering · Sorting · Transformation · Utilities · all utility functions)
├── tests/                     🧪 Criterion unit tests + Makefile
├── Logs/                      📝 Build logs · valgrind report · coverage HTML
├── Utilities/                 📊 Sample CSV files for manual testing
└── Doc/                       📄 README · architecture diagram · policies
```

---

## 🚀 Quick Start

```sh
make          # build libcuddle + cuddle binary
make run      # run ./cuddle
make help     # show help and API reference in the terminal
```

---

## 🏗️ Make Targets

| Command | Description |
|---|---|
| `make` / `make all` | Build libcuddle (includes all utility functions) then link `cuddle` |
| `make manu_test` | Quick one-shot compile (no lib rebuild) |
| `make run ARGUMENTS="…"` | Run `./cuddle` with optional arguments |
| `make debug` | Debug build (-g3) + Valgrind full memory report → `Logs/valgrind.log` |
| `make unit_tests` | Build Criterion unit-tests binary |
| `make tests_run` | Execute tests → logs in `Logs/` |
| `make coverage` | Execute tests → HTML coverage report at `Logs/coverage/index.html` |
| `make clean` | Remove `.o` files (project + libs + tests) |
| `make fclean` | Remove binaries, tests and coverage artefacts |
| `make re` | Full rebuild (`fclean` + `all`) |
| `make help` | Show help menu and API reference |

---

## ✨ Features

- Read/write CSV files with automatic type inference (bool, int, uint, float, string)
- DataFrame API: head, tail, shape, info, describe
- Filtering, sorting, transformation, aggregation (groupby)
- Utilities: get value(s), unique values, free, type detection, conversions
- All utility functions (strings, math, memory, I/O, lists) are now part of libcuddle
- Full unit test suite (Criterion) and code coverage (gcovr)
- Valgrind integration for memory checks

---

## 📝 Example Usage

```c
#include "dataframe.h"

dataframe_t *df = df_read_csv("data.csv", ',');
df_info(df);
dataframe_t *sorted = df_sort(df, "age", cmp_int);
df_free(df);
df_free(sorted);
```

---

## 📚 Documentation

- See `Doc/README.md` for project policies and additional documentation.
- See `Doc/schem.mmd` for the full architecture diagram (Mermaid format).
- Run `make help` for a full API and target reference in the terminal.

---

## 🛡️ License

MIT License (see LICENSE file)
