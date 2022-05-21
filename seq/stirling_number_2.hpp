#include "poly/convolution.hpp"
#include "poly/fps_pow.hpp"
#include "mod/powertable.hpp"

// n 個のもの (labeled) を k グループ (no label) に分ける方法
// label をつけることで、全射の数え上げに利用できる
template <typename mint>
vc<mint> stirling_number_2_n(int n, int k_max) {
  vc<mint> a = powertable_2<mint>(n, k_max + 1);
  FOR(i, k_max + 1) a[i] *= fact_inv<mint>(i);
  vc<mint> b(k_max + 1);
  FOR(i, 1, k_max + 1, 2) b[i] = -b[i];
  FOR(i, k_max + 1) b[i] *= fact_inv<mint>(i);
  auto f = convolution(a, b);
  f.resize(k_max + 1);
  return f;
}

// n 個のもの (labeled) を k グループ (no label) に分ける方法
// label をつけることで、全射の数え上げに利用できる
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
