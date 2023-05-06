#include "setfunc/sps_exp.hpp"
#include "enumerate/bits.hpp"

// 隣接行列に対して完全マッチングを数える。
template <typename mint, int LIM = 20>
mint Hufnian(vc<vc<mint>>& mat) {
  int N = len(mat);
  int n = N / 2;
  assert(n <= LIM);
  vc<mint> cyc(1 << n);

  FOR(i, N / 2) {
    int A = 2 * i + 0, B = 2 * i + 1;
    int K = 2 * i;
    cyc[1 << i] += mat[A][B];
    vc<mint> dp(K << i);
    for (int j = 0; j < i; ++j) {
      int j0 = 2 * j + 0, j1 = 2 * j + 1;
      dp[(K << j) + j0] += mat[A][j1], dp[(K << j) + j1] += mat[A][j0];
    }
    for (int s = 0; s < (1 << i); ++s) {
      for (int j = 0; j < i; ++j) {
        int j0 = 2 * j + 0, j1 = 2 * j + 1;
        cyc[s | 1 << i] += dp[K * s + j0] * mat[B][j0];
        cyc[s | 1 << i] += dp[K * s + j1] * mat[B][j1];
        enumerate_bits_32((1 << i) - 1 - s, [&](int k) -> void {
          int k0 = 2 * k + 0, k1 = 2 * k + 1;
          int t = s | 1 << k;
          dp[K * t + k0] += dp[K * s + j0] * mat[j0][k1];
          dp[K * t + k0] += dp[K * s + j1] * mat[j1][k1];
          dp[K * t + k1] += dp[K * s + j0] * mat[j0][k0];
          dp[K * t + k1] += dp[K * s + j1] * mat[j1][k0];
        });
      }
    }
  }
  return sps_exp<mint, LIM>(n, cyc).back();
}
