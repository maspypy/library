#define PROBLEM "https://yukicoder.me/problems/no/1720"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/common_interval_decomposition.hpp"
#include "mod/modint.hpp"
#include "poly/convolution.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  VEC(int, A, N);
  for (auto&& x: A) --x;
  Common_Inverval_Decomposition<400000> X(A);

  auto dfs = [&](auto& dfs, auto n) -> vc<mint> {
    vc<mint> dp;
    if (n->ch.empty()) {
      dp.resize(K + 1);
      dp[1] = 1;
      return dp;
    }
    if (!n->inc && !n->dec) {
      for (auto&& c: n->ch) {
        auto dpc = dfs(dfs, c);
        if (dp.empty())
          dp = dpc;
        else {
          dp = convolution(dp, dpc);
        }
        dp.resize(K + 1);
      }
      dp[1] += mint(1);
      return dp;
    }
    vc<mint> dp1(K + 1);
    for (auto&& c: n->ch) {
      auto dpc = dfs(dfs, c);
      if (dp.empty()) {
        dp = dpc;
        dp1[1] = 1;
      } else {
        vc<mint> newdp(K + 1);
        FOR(a, K + 1) FOR(b, K - a + 1) { newdp[a + b] += dp[a] * dpc[b]; }
        FOR(k, K + 1) newdp[k] += dp1[k];
        FOR(k, K) dp1[k + 1] += dp[k];
        dp = newdp;
        assert(dp[1] == mint(1));
      }
    }
    return dp;
  };

  auto dp = dfs(dfs, X.root);
  FOR(k, 1, K + 1) print(dp[k]);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
