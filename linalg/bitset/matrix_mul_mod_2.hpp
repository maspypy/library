#include "ds/my_bitset.hpp"

// Method of Four Russians O(NMK/wlogN)
vc<My_Bitset> matrix_mul_mod_2(vc<My_Bitset>& A, vc<My_Bitset>& B, int N1 = -1, int N2 = -1, int N3 = -1) {
  using BS = My_Bitset;
  if (N1 == -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }
  vc<BS> C(N1, BS(N3));

  /*
  前計算 MK2^t/t
  後計算 NMK/t
  (N) -> (2^t/t + N/t)
  */
  vc<BS> tmp(1 << 8, BS(N3));

  for (int L = 0; L < N2; L += 8) {
    int R = min(L + 8, N2);
    int n = R - L;
    FOR(i, n) FOR(s, 1 << i) tmp[s | 1 << i] = tmp[s] ^ B[L + i];
    FOR(i, N1) {
      u32 s = A[i].dat[L / 64] >> (L & 63) & 255;
      C[i] ^= tmp[s];
    }
  }
  return C;
}