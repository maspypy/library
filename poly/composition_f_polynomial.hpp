#include "poly/poly_taylor_shift.hpp"

// f(a+bx)
template <typename mint>
vc<mint> composition_f_polynomial_1(vc<mint> f, mint a, mint b) {
  f = poly_taylor_shift<mint>(f, a); // f(a+x)
  mint pow_b = 1;
  FOR(i, len(f)) f[i] *= pow_b, pow_b *= b;
  return f;
}