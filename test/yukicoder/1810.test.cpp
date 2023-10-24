#define PROBLEM "https://yukicoder.me/problems/no/1810"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/matrix_mul.hpp"
#include "linalg/matrix_pow.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  mint A, B;
  read(A), read(B);
  vv(mint, P, 3, 3);
  vv(mint, Q, 3, 3);
  P[0] = {1, 0, 0};
  P[1] = {0, 1, 0};
  P[2] = {A, B, 1};
  Q[0] = {0, 0, 1};
  Q[1] = {1, 0, 0};
  Q[2] = {0, 0, 0};
  auto QP = matrix_mul(Q, P);
  LL(T);
  FOR(T) {
    LL(t);
    auto X = matrix_pow(QP, t / 2);
    if (t & 1) X = matrix_mul(P, X);
    mint ANS = 0;
    FOR(i, 3) FOR(j, 2) ANS += X[i][j];
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}