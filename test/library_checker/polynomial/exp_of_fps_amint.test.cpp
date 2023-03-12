#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/dynamic_modint.hpp"

#include "poly/fps_exp.hpp"

void solve() {
  LL(N);
  using mint = dmint;
  mint::set_mod(998244353);
  VEC(mint, A, N);
  print(fps_exp(A));
}

signed main() {
  solve();
  return 0;
}
