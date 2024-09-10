#define PROBLEM "https://yukicoder.me/problems/no/1340"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/bitset/matrix_mul_and_or.hpp"

using BS = My_Bitset;

void solve() {
  LL(N, M, T);
  vc<BS> A(N, BS(N));
  FOR(M) {
    INT(a, b);
    A[a][b] = 1;
  }
  vc<BS> B(N, BS(N));
  FOR(i, N) B[i][i] = 1;
  while (T) {
    if (T & 1) B = matrix_mul_and_or(B, A);
    A = matrix_mul_and_or(A, A);
    T /= 2;
  }
  ll ANS = B[0].count();
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}