#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/fps_pow.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, A, N);
  print(fps_pow(A, M));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
