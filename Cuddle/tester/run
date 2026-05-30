#!/bin/bash
# ─────────────────────────────────────────────────────────
#  CUDDLE — lanceur du tester
#  Usage: bash run.sh [--valgrind] [--verbose]
# ─────────────────────────────────────────────────────────
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
VENV="$SCRIPT_DIR/.venv"

if [ ! -f "$VENV/bin/python3" ]; then
    echo "❌  Virtualenv manquant. Lance d'abord : bash setup.sh"
    exit 1
fi

"$VENV/bin/python3" "$SCRIPT_DIR/test_cuddle.py" "$@"
