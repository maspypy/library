#!/bin/bash

# 色の定義
COLOR_INFO='\033[1;34m'      # 青（INFO用）
COLOR_SUCCESS='\033[1;32m'   # 緑（成功）
COLOR_FAIL='\033[1;31m'      # 赤（失敗）
COLOR_INPUT='\034[1;31m'
COLOR_OUTPUT='\034[1;31m'
COLOR_EXPECTED='\034[1;31m'
COLOR_RESET='\033[0m'

COLOR_INPUT='\033[1;34m'
COLOR_OUTPUT='\033[1;34m'
COLOR_EXPECTED='\033[1;34m'

MAX_LINES=20
MAX_LINE_LEN=100

trim_long_lines() {
    awk -v maxlen=$MAX_LINE_LEN '{
        if (length($0) > maxlen) {
            print substr($0,1,maxlen) "...";
        } else {
            print $0;
        }
    }'
}

for infile in test/*.in; do
    base=$(basename "$infile" .in)     # sample-1 など
    outfile="test/${base}.out"
    tmpfile=$(mktemp)

    echo -e "${COLOR_INFO}[INFO]${COLOR_RESET} ${base}"

    # 実行と時間計測
    start=$(date +%s.%N)
    ./a.out < "$infile" > "$tmpfile"
    status=$?
    end=$(date +%s.%N)
    elapsed=$(echo "$end - $start" | bc)

    echo -e "${COLOR_INFO}[INFO]${COLOR_RESET} time: $(printf "%.6f" "$elapsed") sec"

    input_total_lines=$(wc -l < "$infile" | awk '{print $1}')
    output_total_lines=$(wc -l < "$tmpfile" | awk '{print $1}')
    expected_total_lines=$(wc -l < "$outfile" | awk '{print $1}')

    input_total_lines=${input_total_lines:-0}
    output_total_lines=${output_total_lines:-0}
    expected_total_lines=${expected_total_lines:-0}

    input_content=$(head -n $MAX_LINES "$infile")
    output_content=$(head -n $MAX_LINES "$tmpfile")
    expected_content=$(head -n $MAX_LINES "$outfile")

    if [ "$status" -ne 0 ]; then
        echo -e "${COLOR_FAIL}[FAIL]${COLOR_RESET} Runtime error (exit code $status)"

        echo -e "${COLOR_INPUT}[input]${COLOR_RESET}"
        echo "$input_content" | trim_long_lines | while IFS= read -r line; do
            echo -e "${line}"
        done
        if [ "$input_total_lines" -gt $MAX_LINES ]; then
            echo -e "(...)"
        fi

    elif diff -q --ignore-trailing-space "$tmpfile" "$outfile" > /dev/null; then
        echo -e "${COLOR_SUCCESS}[SUCCESS]${COLOR_RESET} AC"
    else
        echo -e "${COLOR_FAIL}[FAIL]${COLOR_RESET}"

        echo -e "${COLOR_INPUT}[input]${COLOR_RESET}"
        echo "$input_content" | trim_long_lines | while IFS= read -r line; do
            echo -e "${line}"
        done
        if [ "$input_total_lines" -gt $MAX_LINES ]; then
            echo -e "(...)"
        fi

        echo -e "${COLOR_INPUT}[output]${COLOR_RESET}"
        echo "$output_content" | trim_long_lines | while IFS= read -r line; do
            echo -e "${line}"
        done
        if [ "$output_total_lines" -gt $MAX_LINES ]; then
            echo -e "${COLOR_OUTPUT}(...)${COLOR_RESET}"
        fi

        echo -e "${COLOR_EXPECTED}[expected]${COLOR_RESET}"
        echo "$expected_content" | trim_long_lines | while IFS= read -r line; do
            echo -e "${line}"
        done
        if [ "$expected_total_lines" -gt $MAX_LINES ]; then
            echo -e "(...)"
        fi
    fi

    echo -e "----------------------------------------------------------"
    rm "$tmpfile"
done
