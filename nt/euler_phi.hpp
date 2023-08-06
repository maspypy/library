#include "nt/zeta.hpp"
#include "nt/factor.hpp"

ll euler_phi(ll n) {
  auto pf = factor(n);
  for (auto&& [p, e]: pf) n -= n / p;
  return n;
}

template <typename T>
vc<T> euler_phi_table(ll n) {
  vc<T> A(n + 1);
  FOR(i, 1, n + 1) A[i] = T(i);
  divisor_mobius(A);
  return A;
}
