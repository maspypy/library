#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/det.hpp"

using mint = modint998;
void solve() {
  LL(N);
  VV(mint, A, N, N);
  print(det(A));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
