#include "seq/find_linear_rec.hpp"
#include "random/base.hpp"

// 行列 A をかけることを表す線形変換 f を渡す
// auto f = [&](vc<mint> v) -> vc<mint> {};
template <typename mint, typename F>
vc<mint> implicit_matrix_min_poly(int N, F f) {
  vc<mint> S(N + N + 10);
  vc<mint> c(N);
  vc<mint> v(N);
  FOR(i, N) c[i] = RNG(0, mint::get_mod());
  FOR(i, N) v[i] = RNG(0, mint::get_mod());
  FOR(k, N + N + 10) {
    FOR(i, N) S[k] += c[i] * v[i];
    v = f(v);
  }
  S = find_linear_rec(S);
  reverse(all(S));
  return S;
}
