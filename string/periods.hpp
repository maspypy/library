#include "string/z_algorithm.hpp"

template <typename STRING>
vc<int> periods(const STRING& S, bool is_divisor) {
  int N = len(S);
  auto Z = z_algorithm(S);
  vc<int> res;
  FOR(p, 1, N + 1) {
    if (is_divisor && (N % p != 0)) continue;
    if (p == N || Z[p] == N - p) res.eb(p);
  }
  return res;
}