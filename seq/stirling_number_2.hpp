#include "poly/convolution.hpp"
template <typename mint>
vc<mint> stirling_number_2(int n) {
  vc<mint> a(n + 1), b(n + 1);
  FOR(i, n + 1) a[i] = mint(i).pow(n);
  FOR(i, n + 1) b[i] = (i % 2 == 0 ? 1 : -1);
  FOR(i, n + 1) a[i] *= fact_inv<mint>(i);
  FOR(i, n + 1) b[i] *= fact_inv<mint>(i);
  auto f = convolution(a, b);
  f.resize(n + 1);
  return f;
}
