#define PROBLEM \
  "https://judge.yosupo.jp/problem/composition_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/fps_composition.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, Q, N);
  VEC(mint, P, N);
  auto F = fps_composition(Q, P);
  print(F);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
