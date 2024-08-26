#define PROBLEM "https://judge.yosupo.jp/problem/characteristic_polynomial"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/characteristic_poly.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VV(mint, A, N, N);
  auto f = characteristic_poly(A);
  print(f);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}