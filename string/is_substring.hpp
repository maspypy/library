#include "string/zalgorithm.hpp"

// 連続部分列に含むかどうか。z-algo で線形時間
template <typename STRING>
bool is_substring(STRING S, STRING T) {
  int n = len(S), m = len(T);
  S += T;
  auto Z = zalgorithm(S);
  FOR3(i, n, n + m) {
    if (Z[i] >= n) return true;
  }
  return false;
}