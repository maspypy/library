#define PROBLEM "https://atcoder.jp/contests/abc213/tasks/abc213_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/sps_log.hpp"

using mint = modint998;
void solve() {
  LL(N, M);
  vc<int> dp(1 << N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    int s = (1 << a) | (1 << b);
    dp[s] += 1;
  }
  FOR(i, N) FOR(s, 1 << N) {
    int t = s | 1 << i;
    if (s < t) dp[t] += dp[s];
  }
  vc<mint> f(1 << N);
  FOR(s, 1 << N) f[s] = mint(2).pow(dp[s]);
  f = sps_log<mint, 17>(f);

  vc<mint> ANS(N);
  int full = (1 << N) - 1;
  FOR(s, 1 << N) if (s & 1) {
    FOR(i, 1, N) if (s >> i & 1) { ANS[i] += f[s] * mint(2).pow(dp[full - s]); }
  }
  FOR(i, 1, N) print(ANS[i]);
}

signed main() {
  solve();
  return 0;
}
