#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "linalg/mat_mul.hpp"
using mint = modint998;

void solve() {
  LL(N, M, K);
  VV(mint, A, N, M);
  VV(mint, B, M, K);
  auto C = mat_mul(A, B);
  FOR(n, len(C)) print(C[n]);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
