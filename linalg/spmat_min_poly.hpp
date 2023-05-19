#include "seq/find_linear_rec.hpp"
#include "random/base.hpp"

template <typename mint>
vc<mint> spmat_min_poly(int N, vc<tuple<int, int, mint>> dat) {
  vc<mint> S(N + N + 10);
  vc<mint> c(N);
  vc<mint> v(N);
  FOR(i, N) c[i] = RNG(0, mint::get_mod());
  FOR(i, N) v[i] = RNG(0, mint::get_mod());
  FOR(k, N + N + 10) {
    FOR(i, N) S[k] += c[i] * v[i];
    vc<mint> w(N);
    for (auto&& [i, j, x]: dat) w[j] += x * v[i];
    swap(v, w);
  }
  vc<mint> f = find_linear_rec(S);
  reverse(all(f));
  return f;
}
