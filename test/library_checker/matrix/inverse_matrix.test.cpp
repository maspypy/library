#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/mat_inv.hpp"

using mint = modint998;
void solve() {
  LL(N);
  VV(mint, A, N, N);
  auto B = mat_inv(A);
  if (B.empty()) return print(-1);
  FOR(n, N) print(B[n]);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
