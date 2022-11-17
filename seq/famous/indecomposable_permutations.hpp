#include "poly/fps_inv.hpp"

// 非空な prefix < suffix に分割できないもの
// ng: [1][2][3], [1][32], [21][3]
// ok: [231], [312], [321]
// https://oeis.org/A003319  0, 1, 1, 3, 13, 71
template <typename mint>
vc<mint> indecomposable_permutations(const int N) {
  vc<mint> f(N + 1);
  FOR(i, N + 1) f[i] = fact<mint>(i);
  f = fps_inv(f);
  for (auto&& x: f) x = -x;
  f[0] += mint(1);
  return f;
}