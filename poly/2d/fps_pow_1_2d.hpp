#include "poly/fps_pow.hpp"

// f^e, sparse, O(NMK)
template <typename mint>
vvc<mint> fps_pow_1_sparse_2d(vvc<mint> f, mint n) {
  assert(f[0][0] == mint(1));
  int N = len(f), M = len(f[0]);
  vv(mint, dp, N, M);
  dp[0] = fps_pow_1_sparse<mint>(f[0], n);

  vc<tuple<int, int, mint>> dat;
  FOR(i, N) FOR(j, M) {
    if ((i > 0 || j > 0) && f[i][j] != mint(0)) dat.eb(i, j, f[i][j]);
  }
  FOR(i, 1, N) {
    FOR(j, M) {
      // F = f^n, f dF = n df F
      // [x^{i-1}y^j]
      mint lhs = 0, rhs = 0;
      for (auto&& [a, b, c] : dat) {
        if (a < i && b <= j) lhs += dp[i - a][j - b] * c * mint(i - a);
        if (a <= i && b <= j) rhs += dp[i - a][j - b] * c * mint(a);
      }
      dp[i][j] = (n * rhs - lhs) * inv<mint>(i);
    }
  }
  return dp;
}
