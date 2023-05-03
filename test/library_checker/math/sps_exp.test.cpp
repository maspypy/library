#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/sps_exp.hpp"

using mint = modint998;
void solve() {
  LL(N);
  VEC(mint, s, 1 << N);
  s = sps_exp<mint, 20>(N, s);
  print(s);
}

signed main() {
  solve();
  return 0;
}