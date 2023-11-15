#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/matrix_pow.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  INT(N);
  U64(K);
  VV(mint, A, N, N);
  A = matrix_pow(A, K);
  FOR(i, N) print(A[i]);
}

signed main() {
  solve();
  return 0;
}