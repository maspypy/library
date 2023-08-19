
#include "poly/poly_taylor_shift.hpp"
#include "poly/composition_f_ex.hpp"

// f(1-e^x)
template <typename mint>
vc<mint> composition_f_ex_minus_1(vc<mint> f) {
  f = poly_taylor_shift<mint>(f, -1);
  return composition_f_ex<mint>(f);
}
