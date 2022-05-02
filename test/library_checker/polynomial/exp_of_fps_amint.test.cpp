#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/fps_exp.hpp"


void solve() {
  LL(N);
  using mint = amint;
  mint::set_mod(998244353);
  VEC(mint, A, N);
  print(fps_exp(A));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
