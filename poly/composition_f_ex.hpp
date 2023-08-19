#include "poly/sum_of_exp_bx.hpp"

// N 次多項式 f に対して、f(e^x) を N 次まで。O(Nlog^2N)
template <typename mint>
vc<mint> composition_f_ex(vc<mint> f) {
  int N = len(f) - 1;
  vc<pair<mint, mint>> AB;
  FOR(k, len(f)) AB.eb(f[k], mint(k));
  return sum_of_exp_bx(N, AB);
}
