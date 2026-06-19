#!/usr/bin/env bash
# Conker decomp toolchain bootstrap (native x86-64 Linux route).
# Run from anywhere:  ~/conker/setup.sh
# Installs system packages, creates the Python venv, installs deps.
# The ROM (baserom.us.z64) must already be in place; this script verifies it.

set -euo pipefail

REPO="$HOME/conker"
cd "$REPO"

echo "==> [1/4] Installing system packages (sudo)"
# NOTE: packages.txt lists 'libglib2.0' which does not exist on Debian/Ubuntu;
# the real package is libglib2.0-0. Use a corrected list here.
sudo apt-get update
sudo apt-get install -y \
  binutils-mips-linux-gnu \
  build-essential \
  git \
  less \
  libglib2.0-0 \
  python-is-python3 \
  python3 \
  python3-pip \
  python3-venv \
  unzip \
  wget

echo "==> [2/4] Creating Python venv (.venv)"
if [ ! -d .venv ]; then
  python3 -m venv .venv
fi
# shellcheck disable=SC1091
source .venv/bin/activate
python -m pip install --upgrade pip

echo "==> [3/5] Installing Python dependencies"
pip install -r requirements.txt
pip install -r tools/n64splat/requirements.txt
# m2c imports pycparser.plyparser, removed in pycparser 3.x — pin to 2.x.
pip install 'pycparser<3'

echo "==> [4/5] Patching n64splat for newer spimdisasm (idempotent)"
# This old splat predates spimdisasm 1.42's nonmatching/enddlabel marker labels
# and never disables them, so extraction emits markers that break the assembler
# and asm-processor. A git submodule update reverts this, so re-apply on setup.
SPLAT_DIS=tools/n64splat/src/splat/disassembler/spimdisasm_disassembler.py
if ! grep -q 'ASM_NM_LABEL = ""' "$SPLAT_DIS"; then
  python3 - "$SPLAT_DIS" <<'PY'
import sys
p = sys.argv[1]
s = open(p).read()
anchor = '        spimdisasm.common.GlobalConfig.ASM_EHTBL_LABEL = (\n            options.opts.asm_ehtable_label_macro\n        )\n'
patch = anchor + (
    '        spimdisasm.common.GlobalConfig.ASM_NM_LABEL = ""\n'
    '        spimdisasm.common.GlobalConfig.ASM_DATA_END_LABEL = ""\n'
)
assert anchor in s, "anchor not found; n64splat layout changed"
open(p, "w").write(s.replace(anchor, patch, 1))
print("  patched", p)
PY
else
  echo "  already patched"
fi

echo "==> [5/5] Sanity checks"
echo -n "make:               "; command -v make || { echo "MISSING"; exit 1; }
echo -n "mips-linux-gnu-as:  "; command -v mips-linux-gnu-as || { echo "MISSING"; exit 1; }
if [ -f baserom.us.z64 ]; then
  GOT=$(sha1sum baserom.us.z64 | cut -d' ' -f1)
  WANT=4cbadd3c4e0729dec46af64ad018050eada4f47a
  if [ "$GOT" = "$WANT" ]; then
    echo "baserom.us.z64:     OK ($GOT)"
  else
    echo "baserom.us.z64:     WRONG HASH ($GOT, want $WANT)"
  fi
else
  echo "baserom.us.z64:     MISSING (place it in $REPO)"
fi

# Activate the pre-commit gate guard (blocks tampering with the ROM verification SHA1s).
git config core.hooksPath tools/git-hooks 2>/dev/null && echo "git hooks:          core.hooksPath -> tools/git-hooks"

echo
echo "Done. Activate the venv with:  source ~/conker/.venv/bin/activate"
