#define PROBLEM "https://yukicoder.me/problems/no/1956"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/crt.hpp"

using T = uint16_t;
T dp[46][100001];

void solve() {
  LL(N, M, C);
  ll NC = min(C, N - C);
  VEC(ll, A, N);
  ll S = SUM<ll>(A);
  vc<int> mods = {65536, 65535, 65533, 65531, 65527, 65521};
  const int K = len(mods);
  vv(T, ans, K, S + 1);

  FOR(k, K) {
    int mod = mods[k];
    FOR(x, NC + 1) FOR(y, S + 1) dp[x][y] = 0;
    dp[0][0] = 1;
    for (auto&& a: A) {
      FOR_R(n, NC) {
        FOR(x, S - a + 1) {
          int v = int(dp[n + 1][x + a]) + dp[n][x];
          if (v >= mod) v -= mod;
          dp[n + 1][x + a] = v;
        }
      }
    }
    FOR(x, S + 1) ans[k][x] = dp[NC][x];
  }

  vc<int> ANS(S + 1);
  FOR(s, S + 1) {
    vc<int> vals(K);
    FOR(k, K) vals[k] = ans[k][s];
    ANS[s] = CRT(vals, mods) % M;
  }
  if (C != NC) reverse(all(ANS));
  ANS.erase(ANS.begin());
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
