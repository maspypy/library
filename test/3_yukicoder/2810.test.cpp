#define PROBLEM "https://yukicoder.me/problems/no/2810"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "linalg/matrix_pow.hpp"

using mint = modint998;
using MAT6 = array<array<mint, 6>, 6>;
using MAT = array<array<mint, 12>, 12>;

void apply6(MAT6 A, array<mint, 12> &x) {
  array<mint, 12> y;
  FOR(i, 6) FOR(j, 6) {
    y[j] += A[i][j] * x[i];
    y[6 + j] += A[i][j] * x[6 + i];
  }
  x = y;
}

void apply(MAT A, array<mint, 12> &x) {
  array<mint, 12> y;
  FOR(i, 12) FOR(j, 12) { y[j] += A[i][j] * x[i]; }
  x = y;
}

MAT6 base;
MAT X;

MAT6 POW[30];

void solve(ll N, ll M, ll C) {
  array<mint, 12> A{};
  A[0] = 1;
  FOR(i, 30) if (C >> i & 1) apply6(POW[i], A);
  A[6] += A[0], A[0] = 0;
  apply(X, A);
  FOR(i, 30) if ((N - C) >> i & 1) apply6(POW[i], A);
  mint ANS = 0;
  FOR(i, 6, 12) ANS += A[i];
  print(ANS);
}

void solve() {
  LL(N, M, Q);

  FOR(i, 1, 6) { base[i][i - 1] = 1; }
  FOR(j, 6) base[0][j] = 1;

  auto tmp = matrix_pow<mint, 6>(base, N);
  FOR(i, 6) FOR(j, 6) X[i][j] = X[i + 6][j + 6] = tmp[i][j];
  FOR(i, 12) X[i][6] += X[i][0], X[i][0] = 0;
  X = matrix_pow<mint, 12>(X, M - 1);
  POW[0] = base;
  FOR(i, 29) POW[i + 1] = matrix_mul<mint, 6>(POW[i], POW[i]);

  FOR(Q) {
    LL(c);
    solve(N, M, c);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
