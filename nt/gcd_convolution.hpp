#include "nt/zeta.hpp"

template <typename T>
vc<T> gcd_convolution(vc<T> A, vc<T>& B) {
  assert(len(A) == len(B));
  multiple_zeta(A);
  multiple_zeta(B);
  FOR(i, len(A)) A[i] *= B[i];
  multiple_mobius(A);
  return A;
}
