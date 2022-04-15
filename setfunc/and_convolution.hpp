#include "setfunc/zeta.hpp"
template <typename T>
vc<T> and_convolution(vc<T> A, vc<T> B) {
  superset_zeta(A);
  superset_zeta(B);
  FOR(i, len(A)) A[i] *= B[i];
  superset_mobius(A);
  return A;
}
