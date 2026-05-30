#!/bin/bash
# ─────────────────────────────────────────────────────────
#  CUDDLE — setup du tester Python
#  Lance ce script UNE FOIS, puis utilise run.sh
# ─────────────────────────────────────────────────────────
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
VENV="$SCRIPT_DIR/.venv"

echo "→ Création du virtualenv dans $VENV"
python3 -m venv "$VENV"

echo "→ Installation de 'rich'"
"$VENV/bin/pip" install --quiet rich

echo ""
echo "✓ Setup terminé !"
echo "  Lance les tests avec :  bash run.sh"
echo "  Ou directement avec  :  $VENV/bin/python3 test_cuddle.py"
