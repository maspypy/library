#include "poly/sum_of_rationals.hpp"
#include "poly/fps_inv.hpp"
#include "poly/fps_exp.hpp"

// (a+bx)^c の積を n まで求める
// O(nlogn + mlog^2m)
template <typename mint>
vc<mint> product_of_pow_of_linear(int N, vc<mint> A, vc<mint> B, vi C) {
  using poly = vc<mint>;
  vc<mint> wt, a;
  mint cf = 1;
  FOR(i, len(A)) {
    assert(A[i] != mint(0));
    cf *= A[i].pow(C[i]);
    B[i] /= A[i];
    wt.eb(B[i] * mint(C[i]));
    a.eb(-B[i]);
  }
  auto [f, g] = sum_of_rationals_1(a, wt);
  g.resize(N + 1);
  f = convolution(f, fps_inv(g));
  f.resize(N + 1);
  FOR_R(i, N) f[i + 1] = f[i] * inv<mint>(i + 1);
  f[0] = 0;
  f = fps_exp(f);
  for (auto&& x: f) x *= cf;
  return f;
}