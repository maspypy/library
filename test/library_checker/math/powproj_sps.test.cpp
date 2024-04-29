#define PROBLEM \
  "https://judge.yosupo.jp/problem/power_projection_of_set_power_series"

#include "my_template.hpp"
#include "other/io.hpp"

#include "setfunc/power_projection_of_sps.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, s, 1 << N);
  VEC(mint, wt, 1 << N);
  vc<mint> ANS = power_projection_of_sps<mint, 20>(wt, s, M);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}