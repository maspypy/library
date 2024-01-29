#include "poly/fps_exp.hpp"
#include "graph/count/count_labeled_tree.hpp"

// https://oeis.org/A001858
template <typename mint>
vc<mint> count_labeled_forest(int N) {
  vc<mint> f = count_labeled_tree<mint>(N);
  FOR(i, len(f)) f[i] *= fact_inv<mint>(i);
  f = fps_exp(f);
  FOR(i, len(f)) f[i] *= fact<mint>(i);
  return f;
}
