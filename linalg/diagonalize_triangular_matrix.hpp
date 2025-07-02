
#include "linalg/transpose.hpp"
#include "linalg/matrix_inv.hpp"

// P^{-1}AP = diag(D) となる (D,P,P^{-1}) を返す
// https://codeforces.com/contest/1540/problem/E
template <typename mint>
tuple<vc<mint>, vvc<mint>, vvc<mint>> diagonalize_triangular_matrix(
    vvc<mint> A) {
  int N = len(A);
  bool lower = 1, upper = 1;
  FOR(i, N) FOR(j, N) {
    if (i < j) lower = lower && (A[i][j] == 0);
    if (i > j) upper = upper && (A[i][j] == 0);
  }
  assert(lower || upper);
  if (!upper) {
    A = transpose(A);
    auto [D, P, Q] = diagonalize_triangular_matrix(A);
    return {D, transpose(Q), transpose(P)};
  }
  assert(upper);

  vc<mint> D(N);
  vv(mint, P, N, N);
  FOR(k, N) D[k] = A[k][k];
  FOR(j, N) FOR(i, j) assert(D[i] != D[j]);

  FOR(k, N) {
    mint d = A[k][k];
    D[k] = d;
    vc<mint> X(N);
    X[k] = 1;
    FOR_R(i, k) {
      mint x = 0;
      FOR(j, i + 1, k + 1) x += A[i][j] * X[j];
      X[i] = x / (d - D[i]);
    }
    FOR(i, N) P[i][k] = X[i];
  }
  auto Q = matrix_inv<mint>(P).se;
  return {D, P, Q};
}
