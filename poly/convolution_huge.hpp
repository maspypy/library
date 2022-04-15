#include "poly/convolution.hpp"
template<typename mint>
vc<mint> convolution_huge(const vc<mint>& A, const vc<mint>& B) {
  int N = len(A), M = len(B);
  if (N + M - 1 <= (1 << 23)) return convolution(A, B);
  ll L = 22;
  vv(mint, C, 4, 2 << L);
  vv(mint, D, 4, 2 << L);
  int mask = (1 << L) - 1;
  FOR(i, N) C[i >> L][i & mask] = A[i];
  FOR(i, M) D[i >> L][i & mask] = B[i];
  FOR(i, 4) ntt(C[i], false);
  FOR(i, 4) ntt(D[i], false);

  vc<mint> ANS(8 << L);

  FOR(i, 7) {
    vc<mint> E(2 << L);
    FOR(c, 4) FOR(d, 4) if(c + d == i) {
      FOR(k, 2 << L) E[k] += C[c][k] * D[d][k];
    }
    ntt(E, true);
    FOR(k, 2 << L) ANS[(i << L) + k] += E[k];
  }
  ANS.resize(N + M - 1);
  return ANS;
}
