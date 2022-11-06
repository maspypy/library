#include "poly/sparse_FODE.hpp"

// exp(f/g) で f,g が sparse
template <typename mint>
vc<mint> sparse_exp_of_div(const vc<mint>& f, const vc<mint>& g) {
  const int N = len(f);
  assert(f[0] == mint(0));
  assert(g[0] == mint(1));
  using P = pair<int, mint>;
  vc<P> dat_f, dat_g;
  FOR(i, len(f)) if (f[i] != mint(0)) dat_f.eb(i, f[i]);
  FOR(i, len(g)) if (g[i] != mint(0)) dat_g.eb(i, g[i]);
  vc<mint> a(N), b(N);
  // a = g^2, b = fg'-f'g
  for (auto&& [i, x]: dat_g) {
    for (auto&& [j, y]: dat_g) {
      if (i + j < N) { a[i + j] += x * y; }
    }
  }
  for (auto&& [i, x]: dat_f) {
    for (auto&& [j, y]: dat_g) {
      if (i + j - 1 >= N) continue;
      b[i + j - 1] += x * y * mint(j - i);
    }
  }
  return sparse_FODE(a, b);
}