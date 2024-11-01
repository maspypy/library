#include "seq/famous/stirling_number_2.hpp"

// n 元集合からの全射の数え上げ
// O(klogk)
template <typename mint>
vc<mint> surjection_n(int n, int k_max) {
  auto f = stirling_number_2_n<mint>(n, k_max);
  mint fc = 1;
  FOR(i, k_max + 1) { f[i] *= fc, fc *= mint(1 + i); }
  return f;
}

// k 元集合へのの全射の数え上げ
// O(nlogn)
template <typename mint>
vc<mint> surjection_k(int k, int n_max) {
  auto f = stirling_number_2_k<mint>(k, n_max);
  mint fc = 1;
  FOR(i, 1, k + 1) fc *= i;
  FOR(i, n_max + 1) f[i] *= fc;
  return f;
}

template <typename mint>
vvc<mint> surjection_2d(int nmax, int kmax) {
  auto A = stirling_number_2_2d<mint>(nmax, kmax);
  mint fc = 1;
  FOR(k, kmax + 1) {
    FOR(n, nmax + 1) { A[n][k] *= fc; }
    fc *= 1 + k;
  }
  return A;
}