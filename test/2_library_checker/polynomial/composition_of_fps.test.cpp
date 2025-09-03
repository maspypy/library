#define PROBLEM \
  "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/composition.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, Q, N);
  VEC(mint, P, N);
  auto F = composition(Q, P);
  print(F);
}

signed main() {
  solve();

  return 0;
}
