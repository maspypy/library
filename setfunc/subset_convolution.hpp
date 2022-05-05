#include "setfunc/ranked_zeta.hpp"

template <typename T>
vc<T> subset_convolution(vc<T>& A, vc<T>& B) {
  auto RA = ranked_zeta(A);
  auto RB = ranked_zeta(A);
  int n = len(RA[0]);
  FOR(s, len(RA)) {
    vc<T> f(n + 1);
    FOR(i, n + 1) FOR(j, n - i + 1) f[i + j] += RA[s][i] * RB[s][j];
    RA[s] = f;
  }
  FOR(s, len(RA)) RA[s] *= RB[s];
  return ranked_mobius(RA);
}
