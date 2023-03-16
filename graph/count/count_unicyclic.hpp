#include "poly/fps_log.hpp"

// https://oeis.org/A057500
template <typename mint>
vc<mint> count_unicyclic(ll nmax) {
  // サイクルの大きさが k であるもの：長さ k の根付き木の列を (2k) で割る
  // sum f^{k} / (2k) の形になるので、log で数えられる
  vc<mint> f(nmax + 1);
  FOR(n, 1, nmax) {
    f[n] = mint(n).pow(n - 1) * fact_inv<mint>(n); // rooted
  }
  vc<mint> F(nmax + 1);
  F[0] = 1;
  FOR(i, 1, nmax + 1) F[i] = -f[i];
  F = fps_log(F);
  FOR(i, nmax + 1) F[i] = -F[i];
  // k = 1
  FOR(i, nmax + 1) F[i] -= f[i];
  // k = 2
  f = convolution(f, f);
  FOR(i, nmax + 1) F[i] -= f[i] * inv<mint>(2);
  FOR(i, nmax + 1) F[i] *= fact<mint>(i) * inv<mint>(2);
  return F;
}
