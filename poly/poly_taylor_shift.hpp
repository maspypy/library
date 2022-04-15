#include "mod/powertable.hpp"
#include "poly/convolution.hpp"

template <typename mint>
vc<mint> poly_taylor_shift(vc<mint> a, mint c) {
  ll N = len(a);
  FOR(i, N) a[i] *= fact<mint>(i);
  auto b = powertable_1<mint>(c, N);
  FOR(i, N) b[i] *= fact_inv<mint>(i);
  reverse(all(a));
  auto f = convolution(a, b);
  f.resize(N);
  reverse(all(f));
  FOR(i, N) f[i] *= fact_inv<mint>(i);
  return f;
}
