#include "linalg/xor/transpose.hpp"

template <typename UINT>
vc<UINT> solve_linear(int n, int m, vc<UINT> A, UINT b) {
  vc<UINT> mat(m);
  UINT rhs = 0;

  FOR(i, len(A)) {
    UINT a = A[i];
    UINT c = b >> i & 1;
    FOR_R(j, m) {
      if (chmin(a, a ^ mat[j])) {
        c ^= (rhs >> j & 1);
      }
    }
    if (a == 0 && c) return {};
    if (a) {
      int k = topbit(a);
      FOR(j, k, m) {
        if (chmin(mat[j], mat[j] ^ a)) rhs ^= c << j;
      }
      mat[k] = a, rhs |= c << k;
    }
  }

  vc<UINT> ANS = {rhs};
  mat = transpose(m, m, mat, 0);
  FOR(i, m) {
    if (!(mat[i] >> i & 1)) ANS.eb(mat[i] | UINT(1) << i);
  }
  return ANS;
}
