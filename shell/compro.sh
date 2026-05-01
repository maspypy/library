# shellcheck shell=bash

# このファイル自身の場所から library dir を決める
_COMPRO_SHELL_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export MASPY_LIBRARY_DIR="$(cd "$_COMPRO_SHELL_DIR/.." && pwd)"

alias python="python3"
ulimit -s unlimited

maspy_randomtest(){
  python3 "$MASPY_LIBRARY_DIR/expander.py" ac.cpp > temp_ac.cpp
  g++ -I "$MASPY_LIBRARY_DIR" -std=c++2a -O2 temp_ac.cpp -o ./ac.out

  ac_count=0
  while true; do 
      python3 generate.py > test/sample-9.in

      ./ac.out < test/sample-9.in > test/sample-9.out
      if [ $? -ne 0 ]; then
          echo -e "\e[31mRE (ac.out crashed)\e[0m"
          cat test/sample-9.in
          break
      fi

      out1=$(./a.out < test/sample-9.in)
      if [ $? -ne 0 ]; then
          echo -e "\e[31mRE (a.out crashed)\e[0m"
          cat test/sample-9.in
          break
      fi

      out2=$(cat test/sample-9.out)

      if [ "$out1" != "$out2" ]; then
          echo -e "\e[31mWA\e[0m"
          echo "case: " $(cat test/sample-9.in)
          echo "x: " "$out1"
          echo "o: " "$out2"
          break
      else
          ((ac_count++))
          echo -e "\e[32mAC\e[0m $ac_count"
          echo "$out1"
      fi
  done
}

maspy_randomtest_noout(){
  python3 "$MASPY_LIBRARY_DIR/expander.py" ac.cpp > temp_ac.cpp
  g++ -I "$MASPY_LIBRARY_DIR" -std=c++2a -O2 temp_ac.cpp -o ./ac.out

  ac_count=0
  while true; do 
      python3 generate.py > test/sample-9.in

      ./ac.out < test/sample-9.in > test/sample-9.out
      if [ $? -ne 0 ]; then
          echo -e "\e[31mRE (ac.out crashed)\e[0m"
          cat test/sample-9.in
          break
      fi

      out1=$(./a.out < test/sample-9.in)
      if [ $? -ne 0 ]; then
          echo -e "\e[31mRE (a.out crashed)\e[0m"
          cat test/sample-9.in
          break
      fi

      out2=$(cat test/sample-9.out)

      if [ "$out1" != "$out2" ]; then
          echo -e "\e[31mWA\e[0m"
          echo "case: " $(cat test/sample-9.in)
          echo "x: " "$out1"
          echo "o: " "$out2"
          break
      else
          ((ac_count++))
          echo -e "\e[32mAC\e[0m $ac_count"
          # echo "$out1"
      fi
  done
}

maspy_randomtest_real(){
  python3 "$MASPY_LIBRARY_DIR/expander.py" ac.cpp > temp_ac.cpp
  g++ -I "$MASPY_LIBRARY_DIR" -std=c++2a -O2 temp_ac.cpp -o ./ac.out

  ac_count=0
  while true; do 
      python3 generate.py > test/sample-9.in

      start_ac=$(date +%s%3N)
      ./ac.out < test/sample-9.in > test/sample-9.out
      status_ac=$?
      end_ac=$(date +%s%3N)
      time_ac=$((end_ac - start_ac))

      if [ $status_ac -ne 0 ]; then
          echo -e "\e[31mRE (ac.out crashed)\e[0m"
          cat test/sample-9.in
          break
      fi

      start_a=$(date +%s%3N)
      out1=$(./a.out < test/sample-9.in)
      status_a=$?
      end_a=$(date +%s%3N)
      time_a=$((end_a - start_a))

      if [ $status_a -ne 0 ]; then
          echo -e "\e[31mRE (a.out crashed)\e[0m"
          cat test/sample-9.in
          break
      fi

      out2=$(cat test/sample-9.out)

      diff=$(echo "scale=10; $out1 - $out2" | bc)
      abs_diff=$(echo "scale=10; if ($diff < 0) -1 * $diff else $diff" | bc)
      eps="0.000001"

      if (( $(echo "$abs_diff > $eps" | bc -l) )); then
          echo -e "\e[31mWA\e[0m"
          echo "case: " $(cat test/sample-9.in)
          echo "x: " "$out1"
          echo "o: " "$out2"
          echo "abs_diff: $abs_diff"
          echo "a.out time: ${time_a}ms"
          echo "ac.out time: ${time_ac}ms"
          break
      else
          ((ac_count++))
          echo -e "\e[32mAC\e[0m $ac_count"
          echo "out: $out1"
          echo "ac.out time: ${time_ac}ms"
          echo "a.out time: ${time_a}ms"
      fi
  done
}

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
  python3 "$MASPY_LIBRARY_DIR/expander.py" main.cpp > temp.cpp
}

cc() {
  expand_main || return

  copy_temp_cpp

  g++ \
    -I "$MASPY_LIBRARY_DIR" \
    -DLOCAL \
    -std=c++2a \
    -O2 \
    -Wall \
    -Wfatal-errors \
    -D_GLIBCXX_DEBUG \
    temp.cpp
}

cc2() {
  expand_main || return

  copy_temp_cpp

  g++ \
    -I "$MASPY_LIBRARY_DIR" \
    -DLOCAL \
    -std=c++2a \
    -O2 \
    -fsanitize=address \
    -fno-omit-frame-pointer \
    -g \
    -fsanitize=undefined \
    temp.cpp
}

ccf() {
  expand_main || return

  g++ \
    -I "$MASPY_LIBRARY_DIR" \
    -std=c++2a \
    -O2 \
    temp.cpp
}

tt() {
  copy_temp_cpp
  bash "$_MASPY_SHELL_DIR/sampletest.sh"
  rm -f a.out
}

maspy_precompile() {
  (
    cd "$MASPY_LIBRARY_DIR" || return

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

alias rt="maspy_randomtest"
alias aa="./a.out"