#define PROBLEM "https://yukicoder.me/problems/no/1867"

#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/monge_lichao_tree.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  vv(int, inv, N + 1, N + 1);
  FOR_R(L, N + 1) FOR(R, L, N + 1) {
    if (R - L <= 1) continue;
    inv[L][R]
        = inv[L + 1][R] + inv[L][R - 1] - inv[L + 1][R - 1] + (A[L] > A[R - 1]);
  }

  vc<int> dp(N + 1);
  FOR(n, 1, N + 1) {
    vc<int> newdp(N + 1, -infty<int>);
    auto f = [&](int i, int j) -> int { return dp[i] + inv[i][j]; };
    Monge_LiChao_Tree<int, false, decltype(f)> LCT(N + 1, f);
    FOR(i, N + 1) {
      chmax(newdp[i], LCT.query(i).fi);
      LCT.add_line(i);
    }
    swap(dp, newdp);
    int ans = inv[0][N] - dp[N];
    print(ans);
  }
}

signed main() {
  solve();
  return 0;
}
