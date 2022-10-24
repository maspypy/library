#define PROBLEM "https://yukicoder.me/problems/no/1685"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/convolution.hpp"

using mint = modint107;

void solve() {
  LL(N, M);

  vc<mint> dp(M + 1);
  FOR(i, M + 1) if (i % 2 == 0) dp[i] = 1;
  vc<mint> comb = {1};

  int LIM_a = N / 2;
  int LIM_b = (N - 1) / 2;
  mint ANS = 0;
  FOR(s, min(N, M) + 1) {
    int lo = max<int>(0, s - LIM_b);
    int hi = min<int>(LIM_a, s);
    mint ans = 0;
    FOR(a, lo, hi + 1) {
      int b = s - a;
      int c = N - s;
      int shift = c - abs(a - b);
      mint cf = comb[a];
      mint x = dp[M - s];
      if ((N & 1) && (s + shift <= M)) x += dp[M - s - shift];
      ans += cf * x;
    }
    ANS += ans * fact_invs<mint>(s, N - s);
    FOR(j, M - s) dp[j + 1] += dp[j];
    comb.eb(0);
    FOR_R(j, len(comb) - 1) comb[j + 1] += comb[j];
  }
  ANS *= fact<mint>(N);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
