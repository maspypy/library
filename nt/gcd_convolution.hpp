#include "nt/zeta.hpp"

template <typename T>
vc<T> gcd_convolution(vc<T> A, vc<T>& B) {
  assert(len(A) == len(B));
  multiplier_zeta(A);
  multiplier_zeta(B);
  FOR(i, len(A)) A[i] *= B[i];
  multiplier_mobius(A);
  return A;
}
