#define PROBLEM "https://yukicoder.me/problems/no/1547"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "seq/interpolate_linear_rec.hpp"

using mint = modint998;

void solve() {
  LL(MA, NA, S, MB, NB, T, K);
  mint PA = mint(MA) / mint(NA);
  mint PB = mint(MB) / mint(NB);
  mint QA = mint(1) - PA;
  mint QB = mint(1) - PB;

  /*
  X = T からはじめる。
  X = 0, S + T：以降動かない
  S + T + 1 状態で、行列
  */
  vc<mint> dp(S + T + 1);
  dp[T] = 1;
  vc<mint> A, B;

  FOR(2 * (S + T) + 10) {
    A.eb(dp[S + T]);
    B.eb(dp[0]);
    {
      // 確率 PA で、X を増加
      vc<mint> newdp(S + T + 1);
      FOR(x, S + T + 1) {
        if (x == 0 || x == S + T) {
          newdp[x] += dp[x];
          continue;
        }
        newdp[x] += QA * dp[x];
        dp[x + 1] += PA * dp[x];
      }
      swap(dp, newdp);
    }
    {
      // 確率 PB で X を減少
      vc<mint> newdp(S + T + 1);
      FOR_R(x, S + T + 1) {
        if (x == 0 || x == S + T) {
          newdp[x] += dp[x];
          continue;
        }
        newdp[x] += QB * dp[x];
        dp[x - 1] += PB * dp[x];
      }
      swap(dp, newdp);
    }
  }

  print(interpolate_linear_rec<mint>(A, K, 0));
  print(interpolate_linear_rec<mint>(B, K, 0));
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
