
#include "setfunc/bitwise_transform.hpp"

template <typename T, int LIM>
vc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {
  int n = topbit(len(f));
  assert(n <= LIM);
  assert(len(f) == 1 << n);
  vc<array<T, LIM + 1>> Rf(1 << n);
  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];
  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);
  return Rf;
}

template <typename T, int LIM>
vc<T> ranked_mobius(vc<array<T, LIM + 1>>& Rf) {
  bitwise::bitwise_transform<bitwise::trans_type::ranked_mobius>(Rf);
  vc<T> f(len(Rf));
  for (int s = 0; s < len(f); ++s) f[s] = Rf[s][popcnt(s)];
  return f;
}