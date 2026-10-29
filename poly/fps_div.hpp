// Source: https://github.com/maspypy/library/blob/main/poly/fps_div.hpp

#include "poly/count_terms.hpp"
#include "poly/fps_inv.hpp"

// f/g ただし g は sparse
template <typename mint>
vc<mint> fps_div_sparse(vc<mint> f, const vc<mint>& g) {
  assert(!g.empty() && g[0] != 0);
  mint c = g[0].inverse();
  if (c != mint(1)) {
    for (auto&& x : f) x *= c;
  }

  vc<pair<int, mint>> dat;
  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i] * c);
  FOR(i, len(f)) {
    for (auto&& [j, x] : dat) {
      if (i >= j) f[i] += x * f[i - j];
    }
  }
  return f;
}

// f/g. f の長さで出力される.
template <typename mint, bool SPARSE = false>
vc<mint> fps_div(vc<mint> f, vc<mint> g) {
  assert(!g.empty() && g[0] != 0);
  if (SPARSE || count_terms(g) < 200) return fps_div_sparse(move(f), g);
  int n = len(f);
  g.resize(n);
  g = fps_inv<mint>(g);
  f = convolution(f, g);
  f.resize(n);
  return f;
}
