
#include "poly/poly_taylor_shift.hpp"
#include "poly/composition_f_ex.hpp"

// f(1-e^x)
template <typename mint>
vc<mint> composition_1_minus_ex(vc<mint> f) {
  f = poly_taylor_shift<mint>(f, 1);
  FOR(i, len(f)) if (i & 1) f[i] = -f[i];
  return composition_f_ex<mint>(f);
}
