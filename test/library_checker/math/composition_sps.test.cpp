#define PROBLEM \
  "https://judge.yosupo.jp/problem/polynomial_composite_set_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/sps_composition.hpp"

using mint = modint998;
void solve() {
  LL(M, N);
  VEC(mint, f, M);
  VEC(mint, s, 1 << N);
  s = sps_composition_poly<mint, 20>(f, s);
  print(s);
}

signed main() {
  solve();
  return 0;
}
