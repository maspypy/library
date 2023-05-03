#define PROBLEM \
  "https://judge.yosupo.jp/problem/polynomial_composite_set_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/composition_sps.hpp"

using mint = modint998;
void solve() {
  LL(M, N);
  VEC(mint, f, M);
  VEC(mint, s, 1 << N);
  s = composition_poly_sps<mint, 20>(N, f, s);
  print(s);
}

signed main() {
  solve();
  return 0;
}