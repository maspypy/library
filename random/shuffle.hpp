#include "random/base.hpp"

template <typename T>
void shuffle(vc<T>& A) {
  FOR(i, len(A)) {
    int j = RNG(0, i + 1);
    if (i != j) swap(A[i], A[j]);
  }
}