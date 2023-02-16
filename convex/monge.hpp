#include "convex/larsch.hpp"
#include "convex/smawk.hpp"
#include "other/fibonacci_search.hpp"

// 定義域 [0, N] の範囲で f の monge 性を確認
template <typename T, typename F>
bool check_monge(int N, F f) {
  FOR(l, N + 1) FOR(k, l) FOR(j, k) FOR(i, j) {
    T lhs = f(i, l) + f(j, k);
    T rhs = f(i, k) + f(j, l);
    if (lhs < rhs) return false;
  }
  return true;
}

// newdp[j] = min (dp[i] + f(i,j))
template <typename T, typename F>
vc<T> monge_dp_update(int N, vc<T>& dp, F f) {
  assert(len(dp) == N + 1);
  auto select = [&](int i, int j, int k) -> int {
    if (i <= k) return j;
    return (dp[j] + f(j, i) > dp[k] + f(k, i) ? k : j);
  };
  vc<int> I = SMAWK(N + 1, N + 1, select);
  vc<T> newdp(N + 1, infty<T>);
  FOR(j, N + 1) {
    int i = I[j];
    chmin(newdp[j], dp[i] + f(i, j));
  }
  return newdp;
}

// 遷移回数を問わない場合
template <typename T, typename F>
vc<T> monge_shortest_path(int N, F f) {
  vc<T> dp(N + 1, infty<T>);
  dp[0] = 0;
  LARSCH<T> larsch(N, [&](int i, int j) -> T {
    ++i;
    if (i <= j) return infty<T>;
    return dp[j] + f(j, i);
  });
  FOR(r, 1, N + 1) {
    int l = larsch.get_argmin();
    dp[r] = dp[l] + f(l, r);
  }
  return dp;
}

// https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge
// |f| の上限 f_lim も渡す
// larsch が結構重いので、自前で dp できるならその方がよい
template <typename T, typename F>
T monge_shortest_path_d_edge(int N, int d, T f_lim, F f) {
  assert(d <= N);
  auto calc_L = [&](T lambda) -> T {
    auto cost = [&](int frm, int to) -> T { return f(frm, to) + lambda; };
    vc<T> dp = monge_shortest_path<T>(N, cost);
    return dp[N] - lambda * d;
  };

  auto [x, fx] = fibonacci_search<T, false>(calc_L, -3 * f_lim, 3 * f_lim);
  return fx;
}
