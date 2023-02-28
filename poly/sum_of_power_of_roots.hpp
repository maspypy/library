#include "poly/fps_div.hpp"

// f = prod(1-a_ix) のとき、g[k] = sum_i a_i^k となる g の [0, LIM] を返す
template <typename mint>
vc<mint> sum_of_power_of_roots(vc<mint>& f, int LIM) {
  const int n = len(f) - 1;
  // n - xf'/f
  vc<mint> g(n + 1);
  FOR(i, n + 1) g[i] = mint(n - i) * f[i];
  g.resize(LIM + 1);
  return fps_div(g, f);
}