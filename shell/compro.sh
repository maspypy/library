# shellcheck shell=bash

# このファイル自身の場所から library dir を決める
COMPRO_SHELL_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export COMPRO_LIBRARY_DIR="$(cd "$COMPRO_SHELL_DIR/.." && pwd)"

# temp.cpp をクリップボードにコピーする
copy_temp_cpp() {
  if command -v clip.exe >/dev/null 2>&1; then
    iconv -f UTF-8 -t UTF-16LE < temp.cpp | clip.exe
  elif command -v pbcopy >/dev/null 2>&1; then
    pbcopy < temp.cpp
  elif command -v wl-copy >/dev/null 2>&1; then
    wl-copy < temp.cpp
  elif command -v xclip >/dev/null 2>&1; then
    xclip -selection clipboard < temp.cpp
  else
    echo "No clipboard command found" >&2
    return 1
  fi
}

# main.cpp を展開して temp.cpp を作る
expand_main() {
  python3 "$COMPRO_LIBRARY_DIR/expander.py" main.cpp > temp.cpp
}

compile_debug() {
  expand_main || return

  copy_temp_cpp

  g++ \
    -I "$COMPRO_LIBRARY_DIR" \
    -DLOCAL \
    -std=c++2a \
    -O2 \
    -Wall \
    -Wfatal-errors \
    -D_GLIBCXX_DEBUG \
    temp.cpp
}

compile_sanitize() {
  expand_main || return

  copy_temp_cpp

  g++ \
    -I "$COMPRO_LIBRARY_DIR" \
    -DLOCAL \
    -std=c++2a \
    -O2 \
    -fsanitize=address \
    -fno-omit-frame-pointer \
    -g \
    -fsanitize=undefined \
    temp.cpp
}

compile_fast() {
  expand_main || return

  g++ \
    -I "$COMPRO_LIBRARY_DIR" \
    -std=c++2a \
    -O2 \
    temp.cpp
}


test_samples() {
  copy_temp_cpp
  bash "$COMPRO_SHELL_DIR/sampletest.sh"
  rm -f a.out
}

precompile() {
  (
    cd "$COMPRO_LIBRARY_DIR" || return

    local pch_src="my_template_compiled.hpp"
    local out_dir="my_template.hpp.gch"

    # my_template.hpp から PCH 用ヘッダを生成する
    # 前提:
    #   1行目: #if defined(LOCAL)
    #   2行目: #include <my_template_compiled.hpp>
    #   3行目: #else
    #   最終行: #endif
    awk '
      NR <= 3 { next }
      { lines[++n] = $0 }
      END {
        for (i = 1; i < n; i++) print lines[i]
      }
    ' my_template.hpp > "$pch_src"

    mkdir -p "$out_dir"

    g++ \
      -o my_template_cc.hpp.gch \
      -I . \
      -DLOCAL \
      -std=c++2a \
      -O2 \
      -Wall \
      -Wfatal-errors \
      -D_GLIBCXX_DEBUG \
      "$pch_src" || return

    g++ \
      -o my_template_cc2.hpp.gch \
      -I . \
      -DLOCAL \
      -std=c++2a \
      -O2 \
      -fsanitize=address \
      -fno-omit-frame-pointer \
      -g \
      -fsanitize=undefined \
      "$pch_src" || return

    g++ \
      -o my_template_ccfast.hpp.gch \
      -I . \
      -std=c++2a \
      -O2 \
      "$pch_src" || return

    mv \
      my_template_cc.hpp.gch \
      my_template_cc2.hpp.gch \
      my_template_ccfast.hpp.gch \
      "$out_dir"/
  )
}

source "$COMPRO_SHELL_DIR/randomtest.sh"

alias python="python3"
ulimit -s unlimited

alias aa="./a.out"
alias cc="compile_debug"
alias cc2="compile_sanitize"
alias ccf="compile_fast"
alias tt="test_samples"
alias rt="randomtest"
