#pragma once

// dp[0] = 0
// dp[r] = min_{0 <= l < r} dp[l] + f(l, r)
// return: {dp, frm}
// minimize_cnt: Alien の復元に使う
template <typename T, typename F>
pair<vc<T>, vc<int>> monge_shortest_path(int N, F f, bool minimize_cnt = true) {
  vc<T> dp(N + 1, infty<T>);
  vc<int> frm(N + 1, 0);
  vc<int> cnt(N + 1, infty<int>);

  dp[0] = 0;
  cnt[0] = 0;

  auto better_tie = [&](int new_cnt, int old_cnt) -> bool {
    return minimize_cnt ? new_cnt < old_cnt : new_cnt > old_cnt;
  };
  auto check = [&](int r, int l) -> void {
    T x = dp[l] + f(l, r);
    int c = cnt[l] + 1;
    if (dp[r] > x || (dp[r] == x && better_tie(c, cnt[r]))) {
      dp[r] = x;
      frm[r] = l;
      cnt[r] = c;
    }
  };

  // simple larsch, https://noshi91.hatenablog.com/entry/2023/02/18/005856
  auto dfs = [&](auto& dfs, int l, int r) -> void {
    if (r - l == 1) return;
    int m = (l + r) / 2;
    FOR(k, frm[l], frm[r] + 1) check(m, k);
    dfs(dfs, l, m);
    FOR(k, l + 1, m + 1) check(r, k);
    dfs(dfs, m, r);
  };

  if (N > 0) {
    check(N, 0), dfs(dfs, 0, N);
  }
  return {dp, frm};
}

// #include "convex/larsch.hpp"
// // dp[r] = min_{0 <= l < r} dp[l] + f(l, r)
// // 遷移回数を問わない
// template <typename T, typename F>
// vc<T> monge_shortest_path_larsch(int N, F f) {
//   vc<T> dp(N + 1, infty<T>);
//   dp[0] = 0;

//   auto g = [&](int i, int j) -> T {
//     ++i;
//     if (i <= j) return infty<T>;
//     return dp[j] + f(j, i);
//   };

//   LARSCH<T, decltype(g)> larsch(N, g);
//   FOR(r, 1, N + 1) {
//     int l = larsch.get_argmin();
//     dp[r] = dp[l] + f(l, r);
//   }
//   return dp;
// }
