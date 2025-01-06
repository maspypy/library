#include "poly/fps_pow.hpp"
#include "poly/poly_taylor_shift.hpp"
#include "poly/fps_div.hpp"

template <typename mint>
vvc<mint> stirling_number_1_2d(int nmax, int kmax) {
  vv(mint, A, nmax + 1, kmax + 1);
  A[0][0] = 1;
  for (int i = 1; i <= nmax; ++i) {
    for (int j = 0; j < i + 1; ++j) {
      if (j > kmax) break;
      mint &x = A[i][j];
      if (j) x += A[i - 1][j - 1];
      x -= A[i - 1][j] * mint(i - 1);
    }
  }
  return A;
}

// x(x+1)...(x+n-1) の係数 c(n, k)
// [n] の順列のうち、k 個のサイクルに分かれるものの個数。
// n を固定したときの列挙を O(n log n) で行う。
template <typename mint>
vc<mint> stirling_number_1_n(int n, bool sgn = false) {
  auto dfs = [&](auto self, int n) -> vc<mint> {
    if (n == 0) return {1};
    if (n == 1) return {0, 1};
    auto f = self(self, n / 2);
    auto g = poly_taylor_shift(f, mint(n / 2));
    f = convolution(f, g);
    if (n & 1) {
      g = {(n - 1), 1};
      f = convolution(f, g);
    }
    return f;
  };
  auto f = dfs(dfs, n);
  if (sgn) { FOR(i, n + 1) if ((n + i) % 2 == 1) f[i] = -f[i]; }
  return f;
}

// k を固定したときの c(n, k) の列挙。
template <typename mint>
vc<mint> stirling_number_1_k(int k, int n_max, bool sgn = false) {
  if (n_max < k) {
    vc<mint> f(n_max + 1);
    return f;
  }
  int LIM = n_max - k;
  vc<mint> f(LIM + 1);
  FOR(i, LIM + 1) f[i] = inv<mint>(i + 1);
  f = fps_pow(f, k);
  if (sgn) { FOR(i, LIM + 1) if (i % 2 == 1) f[i] = -f[i]; }

  mint cf = fact_inv<mint>(k);
  vc<mint> res(n_max + 1);
  FOR(i, len(f)) res[k + i] = cf * f[i] * fact<mint>(k + i);

  return res;
}

// s(n,i) を逆順に並べたもの
// (1+0x)(1+1x)(1+2x)...(1+(N-1)x) を [x^K] まで
template <typename mint>
vc<mint> stirling_number_1_suffix(ll N, ll K) {
  // まずは e^{Nx}-1 / e^x-1 を [x^K] まで
  vc<mint> num(K + 1), den(K + 1);
  mint powN = 1;
  FOR(k, K + 1) {
    powN *= N;
    num[k] = fact_inv<mint>(k + 1) * powN;
    den[k] = fact_inv<mint>(k + 1);
  }
  vc<mint> S = fps_div<mint>(num, den);
  FOR(i, K + 1) S[i] *= fact<mint>(i);
  vc<mint> LOG_F(K + 1);
  FOR(i, 1, K + 1) LOG_F[i] = S[i] * inv<mint>(i) * (2 * (i & 1) - 1);
  return fps_exp(LOG_F);
}
