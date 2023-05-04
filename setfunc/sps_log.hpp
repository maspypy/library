#include "setfunc/sps_composition.hpp"

template <typename mint, int LIM>
vc<mint> sps_log(int N, vc<mint> s) {
  assert(len(s) == (1 << N) && s[0] == mint(1));
  vc<mint> f(N + 1);
  FOR(i, 1, N + 1) f[i] = -fact<mint>(i - 1);
  for (auto&& x: s) x = -x;
  s[0] = 0;
  return sps_composition_egf<mint, LIM>(N, f, s);
}
