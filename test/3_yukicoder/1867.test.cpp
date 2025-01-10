#define PROBLEM "https://yukicoder.me/problems/no/1867"

#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/lichao.hpp"

vvc<int> inv;
vc<int> dp;

struct F {
  using value_type = int; // operator() の戻り値
  int i;
  int operator()(int j) {
    if (i == -1) return -infty<int>;
    return dp[i] + inv[i][j];
  }
};

void solve() {
  LL(N);
  VEC(int, A, N);
  inv.assign(N + 2, vc<int>(N + 2, 0));

  FOR_R(L, N + 1) FOR(R, L, N + 1) {
    if (R - L <= 1) continue;
    inv[L][R] = inv[L + 1][R] + inv[L][R - 1] - inv[L + 1][R - 1] + (A[L] > A[R - 1]);
  }

  dp.assign(N + 1, 0);
  FOR(n, 1, N + 1) {
    vc<int> newdp(N + 1, -infty<int>);
    LiChao_Tree<F, false, false> LCT(0, N + 1, F{-1});
    FOR(i, N + 1) {
      chmax(newdp[i], LCT.query(i).fi);
      LCT.chmax_line(F{int(i)});
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