#!/bin/bash

#cd "$(dirname "S0")/.."

STYLE=$(git config --get hooks.clangformat.style)
STYLEARG=""

if [ -n "${STYLE}" ]; then
  STYLEARG="-style=${STYLE}"
else
  STYLE=$(git rev-parse --show-toplevel)/.clang-format
  if [ -n "${STYLE}" ]; then
    STYLEARG="-style=file"
  else
    STYLEARG=""
  fi
fi

format_file(){
  file=${1}
  if [ -n "${STYLEARG}" ]; then
    clang-format -i ${STYLEARG} ${file}
    echo "clang-format -i ${STYLEARG} ${file}"
    git add "${file}"
  fi
}

is_need_format(){
  need=1
  file=${1}
  if [ x"${file##*.}" != x"cpp" -a x"${file##*.}" != x"cc" -a x"${file##*.}" != x"h" -a x"${file##*.}" != x"hpp" ]; then
    need=0
  else
    if [ -f "${1}" ]; then
      need=1
    else
      need=0
    fi
  fi

  return ${need}
}

case "${1}" in
  --about )
    echo "Run clang-format on .cc/.cpp/.h files"
    ;;
  * )
    for file in $(git diff-index --cached --name-only HEAD); do
      is_need_format "${file}"
      if [[ $? -eq 1 ]]; then
        format_file "${file}"
      fi
    done
    ;;
esac
