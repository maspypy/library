#define PROBLEM "https://yukicoder.me/problems/no/1526"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/beats_summax_chmin.hpp"

// test 用に、逆符号で実装
void solve() {
  LL(N);
  VEC(ll, A, N);
  for (auto&& x: A) --x;

  Beats_SumMax_Chmin<ll> X(N, [](int i) -> ll { return -(i + 1); });

  vvc<int> IDS(N + 1);
  FOR(i, N) IDS[A[i]].eb(i);

  ll ANS = 0;
  FOR(x, N + 1) {
    // ANS += (N + 1) * N - SUM<int>(dp);
    ANS += (N + 1) * N + X.prod(0, N).fi;
    auto& I = IDS[x];
    I.insert(I.begin(), -1);
    I.eb(N);
    FOR(t, len(I) - 1) {
      auto i = I[t], j = I[t + 1];
      // FOR(k, i + 1, j) chmax(dp[k], j + 1);
      X.chmin(i + 1, j, -(j + 1));
    }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}