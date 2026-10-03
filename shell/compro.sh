# shellcheck shell=bash

# CPU 機能に応じて AVX2 版または non-AVX2 版を読み込む入口。
COMPRO_SHELL_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

cpu_has_avx2_and_popcnt() {
  if [ -r /proc/cpuinfo ]; then
    grep -qiE '(^|[[:space:]])avx2([[:space:]]|$)' /proc/cpuinfo &&
      grep -qiE '(^|[[:space:]])popcnt([[:space:]]|$)' /proc/cpuinfo
    return
  fi

  if command -v sysctl >/dev/null 2>&1; then
    local flags
    flags="$(sysctl -a 2>/dev/null | tr '[:upper:]' '[:lower:]')"
    [[ "$flags" =~ (^|[[:space:]])avx2([[:space:]]|$) ]] &&
      [[ "$flags" =~ (^|[[:space:]])popcnt([[:space:]]|$) ]]
    return
  fi

  return 1
}

if cpu_has_avx2_and_popcnt; then
  source "$COMPRO_SHELL_DIR/compro_avx2.sh"
else
  source "$COMPRO_SHELL_DIR/compro_non_avx2.sh"
fi
