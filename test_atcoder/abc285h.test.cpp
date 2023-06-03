#define PROBLEM "https://atcoder.jp/contests/abc285/tasks/abc285_Ex"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/fps_pow.hpp"
#include "linalg/implicit_matrix/pascal.hpp"

using mint = modint107;

void solve() {
  LL(N, K);
  VEC(int, A, K);
  vc<mint> f = {1, -1};
  ll LIM = MAX(A);
  f.resize(LIM + 1);
  f = fps_pow_1<mint>(f, -N);
  vc<mint> dp(N + 1);
  FOR(k, N + 1) {
    mint x = 1;
    FOR(i, K) x *= f[A[i]];
    dp[k] = x;
    FOR(i, len(f) - 1) f[i + 1] -= f[i];
  }
  FOR(i, N + 1) dp[i] *= C<mint>(N, i);
  dp = pascal<mint>(dp, true, true);
  print(dp[0]);
}

signed main() {
  solve();
  return 0;
}