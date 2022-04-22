#include "nt/zeta.hpp"
#include "nt/factor.hpp"

ll euler_phi(ll n) {
  auto pf = factor(n);
  for (auto&& [p, e]: pf) n -= n / p;
  return n;
}

vi euler_phi_table(ll n) {
  vi A(n + 1);
  iota(all(A), 0);
  divisor_mobius(A);
  return A;
}
