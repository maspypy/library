#include "nt/zeta.hpp"

template <typename T>
vc<T> mobius_table(int N) {
  vc<T> mu(N + 1);
  if (1 <= N) mu[1] = T(1);
  divisor_mobius(mu);
  return mu;
}