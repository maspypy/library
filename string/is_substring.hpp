#include "string/zalgorithm.hpp"

// 連続部分列に含むかどうか。z-algo で線形時間
template <typename STRING>
bool is_substring(STRING& S, STRING& T) {
  int n = int(S.size()), m = int(T.size());
  STRING ST;
  for (auto&& x: S) ST.push_back(x);
  for (auto&& x: T) ST.push_back(x);
  auto Z = zalgorithm(ST);
  for (int i = n; i < n + m; ++i) {
    if (Z[i] >= n) return true;
  }
  return false;
}
