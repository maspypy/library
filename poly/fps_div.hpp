#pragma once

#include "poly/count_terms.hpp"
#include "poly/fps_inv.hpp"

// f/g. f の長さで出力される.
template <typename mint, bool SPARSE = false>
vc<mint> fps_div(vc<mint> f, vc<mint> g) {
  if (SPARSE || count_terms(g) < 200) return fps_div_sparse(f, g);
  int n = len(f);
  g.resize(n);
  g = fps_inv<mint>(g);
  f = convolution(f, g);
  f.resize(n);
  return f;
}

// f/g ただし g は sparse
template <typename mint>
vc<mint> fps_div_sparse(vc<mint> f, vc<mint>& g) {
  if (g[0] != mint(1)) {
    mint cf = g[0].inverse();
    for (auto&& x: f) x *= cf;
    for (auto&& x: g) x *= cf;
  }

  vc<pair<int, mint>> dat;
  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i]);
  FOR(i, len(f)) {
    for (auto&& [j, x]: dat) {
      if (i >= j) f[i] += x * f[i - j];
    }
  }
  return f;
}