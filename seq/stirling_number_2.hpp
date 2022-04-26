#include "poly/convolution.hpp"
#include "poly/fps_pow.hpp"

// n 個のもの (labeled) を k グループ (no label) に分ける方法
template <typename mint>
vc<mint> stirling_number_2_n(int n) {
  vc<mint> a(n + 1), b(n + 1);
  FOR(i, n + 1) a[i] = mint(i).pow(n);
  FOR(i, n + 1) b[i] = (i % 2 == 0 ? 1 : -1);
  FOR(i, n + 1) a[i] *= fact_inv<mint>(i);
  FOR(i, n + 1) b[i] *= fact_inv<mint>(i);
  auto f = convolution(a, b);
  f.resize(n + 1);
  return f;
}

// n 個のもの (labeled) を k グループ (no label) に分ける方法
template <typename mint>
vc<mint> stirling_number_2_k(int k, int n_max) {
  if (k > n_max) { return vc<mint>(n_max + 1); }
  int LIM = n_max - k;
  vc<mint> f(LIM + 1);
  FOR(i, LIM + 1) f[i] = fact_inv<mint>(i + 1);
  f = fps_pow(f, k);
  mint cf = fact_inv<mint>(k);

  vc<mint> res(n_max + 1);
  FOR(i, len(f)) res[k + i] = fact<mint>(k + i) * f[i] * cf;
  return res;
}
