#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/multipoint.hpp"

using mint = modint998;
void solve() {
  LL(N);
  VEC(mint, X, N);
  VEC(mint, Y, N);
  print(multipoint_interpolate(X, Y));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
