#include "poly/sum_of_rationals.hpp"
#include "poly/fps_inv.hpp"

// sum a e^{bx} を [0,NN 次まで。O(Mlog^2M + NlogN)
template <typename mint>
vc<mint> sum_of_exp_bx(int N, vc<pair<mint, mint>> AB) {
  using poly = vc<mint>;
  vc<pair<poly, poly>> fracs;
  for (auto&& [a, b]: AB) {
    poly num = {a};
    poly den = {mint(1), -b};
    fracs.eb(num, den);
  }
  auto [f, g] = sum_of_rationals<mint>(fracs);
  g.resize(N + 1);
  f = convolution(f, fps_inv(g));
  f.resize(N + 1);
  FOR(n, N + 1) f[n] *= fact_inv<mint>(n);
  return f;
}
