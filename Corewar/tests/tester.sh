#!/usr/bin/env bash
set -euo pipefail

BIN="${1:-./robot-factory}"
CHAMPION_DIR="${2:-./champion}"
CORRECT_DIR="${3:-./correct}"

BIN_ABS="$(realpath "$BIN")"

if [[ ! -x "$BIN_ABS" ]]; then
    printf '%s
' "Erreur: binaire introuvable/non exécutable: $BIN"
    exit 1
fi
if [[ ! -d "$CHAMPION_DIR" ]]; then
    printf '%s
' "Erreur: dossier champion introuvable: $CHAMPION_DIR"
    exit 1
fi
if [[ ! -d "$CORRECT_DIR" ]]; then
    printf '%s
' "Erreur: dossier correct introuvable: $CORRECT_DIR"
    exit 1
fi

shopt -s nullglob
sources=("$CHAMPION_DIR"/*.s)
if [[ ${#sources[@]} -eq 0 ]]; then
    printf '%s
' "Aucun .s trouvé dans $CHAMPION_DIR"
    exit 1
fi

passed=0
failed=0

for src in "${sources[@]}"; do
    base="$(basename "${src%.s}")"
    expected="${CORRECT_DIR}/${base}.cor"
    src_abs="$(realpath "$src")"

    if [[ ! -f "$expected" ]]; then
        printf '%s
' "[FAIL] $src: fichier attendu manquant ($expected)"
        failed=$((failed + 1))
        continue
    fi

    tmpdir="$(mktemp -d)"

    output=""
    if ! output="$(cd "$tmpdir" && "$BIN_ABS" "$src_abs" 2>&1)"; then
        printf '%s
' "[FAIL] $src: exécution KO"
        printf '%s
' "       $output"
        rm -rf "$tmpdir"
        failed=$((failed + 1))
        continue
    fi

    generated1="${src%.*}.cor"
    generated2="${tmpdir}/${base}.cor"

    generated=""
    if [[ -f "$generated1" ]]; then
        generated="$generated1"
    elif [[ -f "$generated2" ]]; then
        generated="$generated2"
    else
        mapfile -t found < <(find "$tmpdir" -maxdepth 1 -type f -name "*.cor" | sort)
        if [[ ${#found[@]} -gt 0 ]]; then
            generated="${found[0]}"
        fi
    fi

    if [[ -z "$generated" || ! -f "$generated" ]]; then
        printf '%s
' "[FAIL] $src: .cor non généré"
        [[ -n "$output" ]] && printf '%s
' "       $output"
        rm -rf "$tmpdir"
        failed=$((failed + 1))
        continue
    fi

    if cmp -s "$generated" "$expected"; then
        printf '%s
' "[OK]   $src"
        passed=$((passed + 1))
    else
        printf '%s
' "[FAIL] $src: différent de $expected (généré: $generated)"
        failed=$((failed + 1))
    fi

    rm -rf "$tmpdir"
done

printf '
'printf '%s
' "Résultat: $passed OK, $failed FAIL"
[[ $failed -eq 0 ]]