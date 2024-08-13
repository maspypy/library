#define PROBLEM \
  "https://judge.yosupo.jp/problem/power_projection_of_set_power_series"

#include "my_template.hpp"
#include "other/io.hpp"

#include "setfunc/power_projection_of_sps.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, A, 1 << N);
  VEC(mint, W, 1 << N);
  vc<mint> ANS = power_projection_of_sps<mint, 20>(W, A, M);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
