#define PROBLEM "https://yukicoder.me/problems/no/2003"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/fenwicktree/fenwicktree_2d_dense.hpp"

using mint = modint998;

void solve() {
  LL(H, W, K);
  VEC(string, G, H);
  vv(mint, dp, H, W);
  FenwickTree_2D_Dense<Monoid_Add<mint>> bit(H, W);

  dp[0][0] = 1;
  bit.add(0, 0, 1);

  auto get_range = [&](int s) -> pair<int, int> {
    // x+y=s
    // 0<=x<=H-1
    // 0<=s-x<=W-1
    int lo = max<int>(0, s - W + 1);
    int hi = min<int>(H - 1, s);
    return {lo, hi + 1};
  };

  FOR(sm, 1, H + W - 1) {
    {
      auto [a, b] = get_range(sm - K - 1);
      FOR(x, a, b) {
        int y = sm - K - 1 - x;
        if (G[x][y] == '#') continue;
        bit.add(x, y, -dp[x][y]);
      }
    }
    {
      auto [a, b] = get_range(sm);
      FOR(x, a, b) {
        int y = sm - x;
        if (G[x][y] == '#') continue;
        dp[x][y] = bit.prefix_sum(x + 1, y + 1);
        bit.add(x, y, dp[x][y]);
      }
    }
  }

  print(dp[H - 1][W - 1]);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
