#include "poly/fps_exp.hpp"

// https://oeis.org/A001858
template <typename mint>
vc<mint> count_forest(ll nmax) {
  vc<mint> f = count_tree<mint>(nmax);
  FOR(i, len(f)) f[i] *= fact_inv<mint>(i);
  f = fps_exp(f);
  FOR(i, len(f)) f[i] *= fact<mint>(i);
  return f;
}