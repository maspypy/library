#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/matrix_inv.hpp"

using mint = modint998;
void solve() {
  LL(N);
  VV(mint, A, N, N);
  auto [det, inv] = matrix_inv(A);
  if (inv.empty()) return print(-1);
  FOR(n, N) print(inv[n]);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
