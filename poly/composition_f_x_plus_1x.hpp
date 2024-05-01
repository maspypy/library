
#include "poly/poly_taylor_shift.hpp"

// x^nf(x+1/x), O(logN) time
// 2^17: 0.1sec, 2^20: 0.8 sec
template <typename mint>
vc<mint> composition_f_x_plus_1x(vc<mint> f) {
  int n = len(f) - 1;
  f = poly_taylor_shift<mint>(f, 2);
  reverse(all(f));
  f = poly_taylor_shift(f, -inv<mint>(4));
  f.resize(2 * n + 1);
  FOR_R(i, n + 1) f[2 * i] = f[i];
  FOR(i, n) f[2 * i + 1] = 0;
  f = poly_taylor_shift(f, inv<mint>(2));
  reverse(all(f));
  f = poly_taylor_shift<mint>(f, -1);
  return f;
}
