#include "poly/from_log_differentiation.hpp"

// exp(f/g) で f,g が sparse
template <typename mint>
vc<mint> sparse_exp_of_div(int N, const vc<mint>& f, const vc<mint>& g) {
  assert(f[0] == mint(0));
  assert(g[0] == mint(1));
  using P = pair<int, mint>;
  vc<P> dat_f, dat_g;
  FOR(i, len(f)) if (f[i] != mint(0)) dat_f.eb(i, f[i]);
  FOR(i, len(g)) if (g[i] != mint(0)) dat_g.eb(i, g[i]);

  vc<mint> a(len(f) + len(g) - 2), b(2 * len(g) - 1);
  // a = f'g-fg', b = g^2
  for (auto&& [i, x]: dat_f) {
    for (auto&& [j, y]: dat_g) { a[i + j - 1] += x * y * mint(i - j); }
  }
  for (auto&& [i, x]: dat_g) {
    for (auto&& [j, y]: dat_g) { b[i + j] += x * y; }
  }
  return from_log_differentiation(N, a, b);
}