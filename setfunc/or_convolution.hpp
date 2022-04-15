#include "setfunc/zeta.hpp"
template <typename T>
vc<T> or_convolution(vc<T> A, vc<T> B) {
  subset_zeta(A);
  subset_zeta(B);
  FOR(i, len(A)) A[i] *= B[i];
  subset_mobius(A);
  return A;
}
