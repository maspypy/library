#include "poly/sparse_FODE.hpp"

// f^ng^m
template <typename mint>
vc<mint> sparse_pow_product(vc<mint>& f, vc<mint>& g, mint n, mint m) {
  const int N = len(f);
  assert(f[0] == mint(1));
  assert(g[0] == mint(1));
  using P = pair<int, mint>;
  vc<P> dat_f, dat_g;
  FOR(i, len(f)) if (f[i] != mint(0)) dat_f.eb(i, f[i]);
  FOR(i, len(g)) if (g[i] != mint(0)) dat_g.eb(i, g[i]);
  vc<mint> a(N), b(N);
  for (auto&& [i, x]: dat_f) {
    for (auto&& [j, y]: dat_g) {
      if (i + j >= N + 1) continue;
      mint xy = x * y;
      if (i + j < N) a[i + j] += xy;
      if (0 < i + j && i + j <= N) {
        b[i + j - 1] -= xy * (n * mint(i) + m * mint(j));
      }
    }
  }
  return sparse_FODE(a, b);
}