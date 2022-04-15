#include "nt/zeta.hpp"

template<typename T>
vc<T> mobius_table(int N){
  vc<T> mu(N + 1);
  mu[1] = T(1);
  divisor_mobius(mu);
  return mu;
}