#include "seq/stirling_number_2.hpp"

// n 元集合からの全射の数え上げ
template <typename mint>
vc<mint> surjection_n(int n, int k_max) {
  auto f = stirling_number_2_n<mint>(n, k_max);
  FOR(i, k_max + 1) f[i] *= fact<mint>(i);
  return f;
}

// k 元集合へのの全射の数え上げ
template <typename mint>
vc<mint> surjection_k(int k, int n_max) {
  auto f = stirling_number_2_k<mint>(k, n_max);
  FOR(i, n_max + 1) f[i] *= fact<mint>(k);
  return f;
}
