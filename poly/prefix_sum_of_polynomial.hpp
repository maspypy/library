#include "seq/famous/bernoulli.hpp"

// f: polynomial.
// sum_{k in [0,n)}f(k)=g(n) となる g を返す
template <typename mint>
vc<mint> prefix_sum_of_polynomial(vc<mint> f, bool include_right_end) {
  if (!include_right_end) {
    auto F = prefix_sum_of_polynomial(f, false);
    FOR(i, len(f)) F[i] -= f[i];
    return F;
  }
  if (f.empty()) return {0};
  if (len(f) == 1) return {f[0], f[0]};
  static vc<mint> B = {1};
  ll d = len(f) - 1;
  if (d >= len(B)) {
    ll n = max(d, len(B) * 2);
    B = bernoulli_number<mint>(n);
    B[1] = inv<mint>(2);
  }
  FOR(i, d + 1) f[i] *= fact<mint>(i);
  vc<mint> b(d + 1);
  FOR(i, d + 1) b[d - i] = B[i] * fact_inv<mint>(i);
  vc<mint> F = convolution<mint>(f, b);
  F = {F.begin() + d - 1, F.end()};
  F[0] = f[0];
  FOR(i, len(F)) F[i] *= fact_inv<mint>(i);
  return F;
}