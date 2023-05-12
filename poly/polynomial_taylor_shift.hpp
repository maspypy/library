#include "mod/powertable.hpp"
#include "poly/convolution.hpp"

// f(x) -> f(x+c)
template <typename mint>
vc<mint> polynomial_taylor_shift(vc<mint> f, mint c) {
  ll N = len(f);
  FOR(i, N) f[i] *= fact<mint>(i);
  auto b = powertable_1<mint>(c, N);
  FOR(i, N) b[i] *= fact_inv<mint>(i);
  reverse(all(f));
  f = convolution(f, b);
  f.resize(N);
  reverse(all(f));
  FOR(i, N) f[i] *= fact_inv<mint>(i);
  return f;
}
