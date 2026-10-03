# shellcheck shell=bash

COMPRO_SHELL_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export COMPRO_LIBRARY_DIR="$(cd "$COMPRO_SHELL_DIR/.." && pwd)"

copy_temp_cpp() {
  if command -v clip.exe >/dev/null 2>&1; then
    iconv -f UTF-8 -t UTF-16LE < temp.cpp | clip.exe
  elif command -v wl-copy >/dev/null 2>&1; then
    wl-copy < temp.cpp
  elif command -v xclip >/dev/null 2>&1; then
    xclip -selection clipboard < temp.cpp
  elif command -v xsel >/dev/null 2>&1; then
    xsel --clipboard --input < temp.cpp
  elif command -v pbcopy >/dev/null 2>&1; then
    pbcopy < temp.cpp
  else
    echo "Warning: clipboard command not found; skipping copy." >&2
  fi
  return 0
}

expand_main() {
  python3 "$COMPRO_LIBRARY_DIR/expander.py" main.cpp > temp.cpp
}

compile_debug() {
  expand_main || return
  copy_temp_cpp
  g++ -I "$COMPRO_LIBRARY_DIR" -DLOCAL -DUSE_PCH -DMASPY_NON_AVX2 \
    -std=c++2a -O2 -Wall -Wfatal-errors -D_GLIBCXX_DEBUG temp.cpp
}

compile_sanitize() {
  expand_main || return
  copy_temp_cpp
  g++ -I "$COMPRO_LIBRARY_DIR" -DLOCAL -DUSE_PCH -DMASPY_NON_AVX2 \
    -std=c++2a -O2 -fsanitize=address -fno-omit-frame-pointer -g \
    -fsanitize=undefined temp.cpp
}

compile_fast() {
  expand_main || return
  g++ -I "$COMPRO_LIBRARY_DIR" -DUSE_PCH -DMASPY_NON_AVX2 -std=c++2a -O2 temp.cpp
}

compile_fast_no_pch() {
  expand_main || return
  g++ -I "$COMPRO_LIBRARY_DIR" -DMASPY_NON_AVX2 -std=c++2a -O2 temp.cpp
}

test_samples() {
  copy_temp_cpp
  bash "$COMPRO_SHELL_DIR/sampletest.sh"
  rm -f a.out
}

shrink_temp() {
  python3 "$COMPRO_LIBRARY_DIR/shrink.py" --report temp.cpp > submit.cpp
}

precompile() {
  (
    cd "$COMPRO_LIBRARY_DIR" || return
    local pch_src="my_template_compiled.hpp"
    local out_dir="my_template_compiled.hpp.gch"
    awk '
      NR <= 3 { next }
      { lines[++n] = $0 }
      END { for (i = 1; i < n; i++) print lines[i] }
    ' my_template.hpp > "$pch_src"
    rm -rf "$out_dir"
    mkdir -p "$out_dir"

    g++ -o "$out_dir/debug.gch" -I . -DLOCAL -DUSE_PCH -DMASPY_NON_AVX2 \
      -std=c++2a -O2 -Wall -Wfatal-errors -D_GLIBCXX_DEBUG -x c++-header \
      "$pch_src" || return
    g++ -o "$out_dir/sanitize.gch" -I . -DLOCAL -DUSE_PCH -DMASPY_NON_AVX2 \
      -std=c++2a -O2 -fsanitize=address -fno-omit-frame-pointer -g \
      -fsanitize=undefined -x c++-header "$pch_src" || return
    g++ -o "$out_dir/fast.gch" -I . -DUSE_PCH -DMASPY_NON_AVX2 -std=c++2a -O2 \
      -x c++-header "$pch_src" || return
    echo "PCH built: non-AVX2"
  )
}

compile_oracle() {
  python3 "$COMPRO_LIBRARY_DIR/expander.py" ac.cpp > temp_ac.cpp || return
  g++ -I "$COMPRO_LIBRARY_DIR" -DMASPY_NON_AVX2 -std=c++2a -O2 temp_ac.cpp -o ./ac.out
}

randomtest() {
  compile_oracle || return
  ac_count=0
  while true; do
    python3 generate.py > test/sample-9.in
    ./ac.out < test/sample-9.in > test/sample-9.out
    if [ $? -ne 0 ]; then
      echo -e "\e[31mRE (ac.out crashed)\e[0m"; cat test/sample-9.in; break
    fi
    out1=$(./a.out < test/sample-9.in)
    if [ $? -ne 0 ]; then
      echo -e "\e[31mRE (a.out crashed)\e[0m"; cat test/sample-9.in; break
    fi
    out2=$(cat test/sample-9.out)
    if [ "$out1" != "$out2" ]; then
      echo -e "\e[31mWA\e[0m"
      echo "case: " "$(cat test/sample-9.in)"
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

randomtest_noout() {
  compile_oracle || return
  ac_count=0
  while true; do
    python3 generate.py > test/sample-9.in
    ./ac.out < test/sample-9.in > test/sample-9.out
    if [ $? -ne 0 ]; then
      echo -e "\e[31mRE (ac.out crashed)\e[0m"; cat test/sample-9.in; break
    fi
    out1=$(./a.out < test/sample-9.in)
    if [ $? -ne 0 ]; then
      echo -e "\e[31mRE (a.out crashed)\e[0m"; cat test/sample-9.in; break
    fi
    out2=$(cat test/sample-9.out)
    if [ "$out1" != "$out2" ]; then
      echo -e "\e[31mWA\e[0m"
      echo "case: " "$(cat test/sample-9.in)"
      echo "x: " "$out1"
      echo "o: " "$out2"
      break
    else
      ((ac_count++))
      echo -e "\e[32mAC\e[0m $ac_count"
    fi
  done
}

randomtest_real() {
  compile_oracle || return
  ac_count=0
  while true; do
    python3 generate.py > test/sample-9.in
    start_ac=$(date +%s%3N)
    ./ac.out < test/sample-9.in > test/sample-9.out
    status_ac=$?
    end_ac=$(date +%s%3N)
    time_ac=$((end_ac - start_ac))
    if [ "$status_ac" -ne 0 ]; then
      echo -e "\e[31mRE (ac.out crashed)\e[0m"; cat test/sample-9.in; break
    fi
    start_a=$(date +%s%3N)
    out1=$(./a.out < test/sample-9.in)
    status_a=$?
    end_a=$(date +%s%3N)
    time_a=$((end_a - start_a))
    if [ "$status_a" -ne 0 ]; then
      echo -e "\e[31mRE (a.out crashed)\e[0m"; cat test/sample-9.in; break
    fi
    out2=$(cat test/sample-9.out)
    diff=$(echo "scale=10; $out1 - $out2" | bc)
    abs_diff=$(echo "scale=10; if ($diff < 0) -1 * $diff else $diff" | bc)
    eps="0.000001"
    if (( $(echo "$abs_diff > $eps" | bc -l) )); then
      echo -e "\e[31mWA\e[0m"
      echo "case: " "$(cat test/sample-9.in)"
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
      echo "a.out time: ${time_a}ms"
      echo "ac.out time: ${time_ac}ms"
    fi
  done
}

alias python="python3"
ulimit -s unlimited
alias aa="./a.out"
alias cc="compile_debug"
alias cc2="compile_sanitize"
alias ccf="compile_fast"
alias ccf_no_pch="compile_fast_no_pch"
alias tt="test_samples"
alias rt="randomtest"
echo "compro: non-AVX2 mode"
