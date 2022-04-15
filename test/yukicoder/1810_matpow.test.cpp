#define PROBLEM "https://yukicoder.me/problems/no/1810"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/mat_mul.hpp"
#include "linalg/mat_pow.hpp"
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
  auto QP = mat_mul(Q, P);
  LL(T);
  FOR_(T) {
    LL(t);
    auto X = mat_pow(QP, t / 2);
    if (t & 1) X = mat_mul(P, X);
    mint ANS = 0;
    FOR(i, 3) FOR(j, 2) ANS += X[i][j];
    print(ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
