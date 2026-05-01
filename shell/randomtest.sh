# shellcheck shell=bash

randomtest() {
  python3 "$COMPRO_LIBRARY_DIR/expander.py" ac.cpp > temp_ac.cpp
  g++ -I "$COMPRO_LIBRARY_DIR" -std=c++2a -O2 temp_ac.cpp -o ./ac.out

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
  python3 "$COMPRO_LIBRARY_DIR/expander.py" ac.cpp > temp_ac.cpp
  g++ -I "$COMPRO_LIBRARY_DIR" -std=c++2a -O2 temp_ac.cpp -o ./ac.out

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
  python3 "$COMPRO_LIBRARY_DIR/expander.py" ac.cpp > temp_ac.cpp
  g++ -I "$COMPRO_LIBRARY_DIR" -std=c++2a -O2 temp_ac.cpp -o ./ac.out

  ac_count=0
  while true; do
    python3 generate.py > test/sample-9.in

    start_ac=$(date +%s%3N)
    ./ac.out < test/sample-9.in > test/sample-9.out
    status_ac=$?
    end_ac=$(date +%s%3N)
    time_ac=$((end_ac - start_ac))

    if [ "$status_ac" -ne 0 ]; then
      echo -e "\e[31mRE (ac.out crashed)\e[0m"
      cat test/sample-9.in
      break
    fi

    start_a=$(date +%s%3N)
    out1=$(./a.out < test/sample-9.in)
    status_a=$?
    end_a=$(date +%s%3N)
    time_a=$((end_a - start_a))

    if [ "$status_a" -ne 0 ]; then
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
      echo "ac.out time: ${time_ac}ms"
      echo "a.out time: ${time_a}ms"
    fi
  done
}

