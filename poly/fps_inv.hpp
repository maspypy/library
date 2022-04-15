#include "poly/convolution.hpp"

template <typename mint>
vc<mint> fps_inv(const vc<mint>& F) {
  assert(F[0] != mint(0));
  vc<mint> G = {mint(1) / F[0]};
  G.reserve(len(F));
  ll N = len(F), n = 1;
  while (n < N) {
    vc<mint> f(2 * n), g(2 * n);
    FOR(i, min(N, 2 * n)) f[i] = F[i];
    FOR(i, n) g[i] = G[i];
    ntt(f, false);
    ntt(g, false);
    FOR(i, 2 * n) f[i] *= g[i];
    ntt(f, true);
    FOR(i, n) f[i] = 0;
    ntt(f, false);
    FOR(i, 2 * n) f[i] *= g[i];
    ntt(f, true);
    FOR3(i, n, 2 * n) G.eb(f[i] * mint(-1));
    n *= 2;
  }
  G.resize(N);
  return G;
}
