#include "linalg/blackbox/min_poly.hpp"

template <typename mint, typename F>
mint blackbox_det(int N, F apply) {
  vc<mint> c(N);
  FOR(i, N) c[i] = RNG(1, mint::get_mod());
  mint r = 1;
  FOR(i, N) r *= c[i];
  auto g = [&](vc<mint> v) -> vc<mint> {
    FOR(i, N) v[i] *= c[i];
    return apply(v);
  };
  auto f = blackbox_min_poly<mint>(N, g);
  mint det = (len(f) == N + 1 ? f[0] : mint(0));
  if (N & 1) det *= -1;
  det /= r;
  return det;
}
