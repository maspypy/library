#include "poly/poly_divmod.hpp"

// f^n mod g
template <typename mint>
vc<mint> poly_mod_pow(vc<mint> f, ll n, vc<mint>& g) {
  if (n == 0) return {1};
  if (n == 1) return f;
  vc<mint> F = poly_mod_pow(f, n / 2, g);
  F = convolution<mint>(F, F);
  F = poly_divmod(F, g).se;
  if (n & 1) {
    F = convolution<mint>(F, f);
    F = poly_divmod(F, g).se;
  }
  return F;
}
