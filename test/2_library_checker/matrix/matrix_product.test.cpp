#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "linalg/matrix_mul.hpp"
using mint = modint998;

void solve() {
  LL(N, M, K);
  VV(mint, A, N, M);
  VV(mint, B, M, K);
  auto C = matrix_mul(A, B);
  FOR(n, len(C)) print(C[n]);
}

signed main() {
  solve();
  return 0;
}