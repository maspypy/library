#include "random/base.hpp"

template <typename T>
void shuffle(vc<T>& A) {
  FOR(i, len(A)) swap(A[i], A[RNG(0, i + 1)]);
}