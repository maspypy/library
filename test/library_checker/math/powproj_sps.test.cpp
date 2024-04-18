#define PROBLEM \
  "https://judge.yosupo.jp/problem/power_projection_of_set_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/transposed_sps_composition.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, A, 1 << N);
  VEC(mint, B, 1 << N);
  vc<mint> ANS = transposed_sps_composition_poly<mint, 20>(A, B, M);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}