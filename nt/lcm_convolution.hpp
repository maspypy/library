#include "nt/zeta.hpp"

template <typename T>
vc<T> lcm_convolution(vc<T> A, vc<T>& B) {
  assert(len(A) == len(B));
  divisor_zeta(A);
  divisor_zeta(B);
  FOR(i, len(A)) A[i] *= B[i];
  divisor_mobius(A);
  return A;
}
