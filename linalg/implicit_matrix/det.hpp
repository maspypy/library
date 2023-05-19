#include "linalg/implicit_matrix/min_poly.hpp"

// 行列 A をかけることを表す線形変換 f を渡す
// auto f = [&](vc<mint> v) -> vc<mint> {};
template <typename mint, typename F>
mint implicit_matrix_det(int N, F f) {
  vc<mint> c(N);
  FOR(i, N) c[i] = RNG(1, mint::get_mod());
  mint r = 1;
  FOR(i, N) r *= c[i];
  auto g = [&](vc<mint> v) -> vc<mint> {
    FOR(i, N) v[i] *= c[i];
    return f(v);
  };
  auto P = implicit_matrix_min_poly<mint>(N, g);
  mint det = (len(P) == N ? P[0] : mint(0));
  if (N & 1) det *= -1;
  det /= r;
  return det;
}
