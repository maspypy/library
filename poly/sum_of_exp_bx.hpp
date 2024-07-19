#include "poly/sum_of_rationals.hpp"
#include "poly/fps_inv.hpp"

// sum a e^{bx} を [0,NN 次まで。O(Mlog^2M + NlogN)
template <typename mint>
vc<mint> sum_of_exp_bx(int N, vc<mint> A, vc<mint> B) {
  auto [f, g] = sum_of_rationals_1<mint>(B, A);
  g.resize(N + 1);
  f = convolution(f, fps_inv(g));
  f.resize(N + 1);
  FOR(n, N + 1) f[n] *= fact_inv<mint>(n);
  return f;
}
