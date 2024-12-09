#!/bin/bash

#cd "$(dirname "S0")/.."
for hooks in $(find .git -name hooks); do
  cp scripts/clang_format.sh "${hooks}"/pre-commit
  chmod 733 "${hooks}"/pre-commit
done