#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/fps_exp.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, A, N);
  print(fps_exp(A));
}

signed main() {
  solve();
  return 0;
}
