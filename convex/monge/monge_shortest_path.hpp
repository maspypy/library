
template <typename T>
struct Monge_Shortest_Path {
  vc<T> dp;
  vc<int> cnt, frm;

  template <typename F>
  T solve(int N, F f, bool minimize_cnt = true) {
    dp.assign(N + 1, infty<T>);
    cnt.assign(N + 1, infty<int>);
    frm.assign(N + 1, 0);

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
        cnt[r] = c;
        frm[r] = l;
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
      check(N, 0);
      dfs(dfs, 0, N);
    }

    return dp[N];
  }

  vc<int> restore_path() {
    int N = len(dp) - 1;
    vc<int> path;
    for (int v = N; v > 0; v = frm[v]) path.eb(v);
    path.eb(0);
    reverse(all(path));
    return path;
  }
};

// yuki705 では simple larsch より低速だったし使わない想定でいく
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
