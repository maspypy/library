#include "ds/my_bitset.hpp"

// Boolean Matrix Multiplication C[i][k] |= A[i][j] && B[j][k]
// https://contest.ucup.ac/contest/1784/problem/9246
// https://codeforces.com/contest/1338/problem/E N=8000, 2sec, 静的配列で高速化したら通ったやつ
vc<My_Bitset> matrix_mul_and_or(vc<My_Bitset>& A, vc<My_Bitset>& B, int N1 = -1, int N2 = -1, int N3 = -1) {
  using BS = My_Bitset;
  if (N1 == -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }
  vc<BS> C(N1, BS(N3));
  if (N1 < 50) {
    FOR(i, N1) FOR(j, N2) {
      if (A[i][j]) C[i] |= B[j];
    }
    return C;
  }
  const int K = (N1 < 1200 ? 4 : 8);
  vc<BS> tmp(1 << K, BS(N3));
  for (int L = 0; L < N2; L += K) {
    int R = min(L + K, N2);
    int n = R - L;
    FOR(i, n) FOR(s, 1 << i) tmp[s | 1 << i] = tmp[s] | B[L + i];
    FOR(i, N1) {
      u32 s = A[i].dat[L / 64] >> (L & 63) & ((1 << K) - 1);
      C[i] |= tmp[s];
    }
  }
  return C;
}
