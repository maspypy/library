#include "ds/my_bitset.hpp"

// https://contest.ucup.ac/contest/1784/problem/9246
// C[i][k] |= A[i][j] && B[j][k]
template <int K = 8>
vc<My_Bitset> matrix_mul_and_or(vc<My_Bitset>& A, vc<My_Bitset>& B, int N1 = -1, int N2 = -1, int N3 = -1) {
  static_assert(64 % K == 0);
  using BS = My_Bitset;
  if (N1 == -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }
  vc<BS> C(N1, BS(N3));
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