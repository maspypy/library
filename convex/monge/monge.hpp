#include "convex/larsch.hpp"
#include "convex/smawk.hpp"
#include "other/fibonacci_search.hpp"

// https://codeforces.com/contest/2183/problem/H
template <typename T, typename F>
T monge_shortest_path_d_edge(int N, int d, T flim, F f) {
  assert(1 <= d && d <= N);
  if (d == 1) return f(0, N);
  if (d == N) {
    T ans = 0;
    FOR(i, N) ans += f(i, i + 1);
    return ans;
  }
  if (d == 2) {
    T ans = infty<T>;
    FOR(i, 1, N) chmin(ans, f(0, i) + f(i, N));
    return ans;
  }

  vc<pair<T, int>> dp(N + 1);
  map<T, pair<T, int>> MP;
  T ANS = -infty<T>;
  auto calc = [&](T lambda) -> pair<T, int> {
    if (MP.count(lambda)) return MP[lambda];
    dp[0] = {0, 0};
    auto eval = [&](int i, int j) -> T {
      ++i;
      if (i <= j) return infty<T>;
      return dp[j].fi + f(j, i);
    };
    LARSCH<T, decltype(eval)> larsch(N, eval);

    FOR(r, 1, N + 1) {
      int l = larsch.get_argmin();
      dp[r].fi = dp[l].fi + f(l, r) + lambda;
      dp[r].se = dp[l].se + 1;
    }
    chmax(ANS, dp[N].fi - lambda * d);
    return MP[lambda] = dp[N];
  };

  T lo = -3 * flim - 10, hi = 3 * flim + 10;
  while (lo + 1 < hi) {
    T mi = (lo + hi) / 2;
    int k = calc(mi).se;
    if (k == d) break;
    (k > d ? lo : hi) = mi;
  }
  return ANS;
}

// https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html
// Prop 1
// 上三角 monge A, B
// C[i][j] = min_k (A[i][k] + B[k][j])
template <typename T, typename F1, typename F2>
vvc<T> monge_matrix_product(int N, F1 A, F2 B) {
  vv(T, C, N + 1, N + 1, infty<T>);
  vc<int> K(N + 1);
  FOR(i, N + 1) C[i][i] = A(i, i) + B(i, i), K[i] = i;
  FOR(s, 1, N + 1) {
    vc<int> newK(N + 1 - s);
    FOR(i, N + 1 - s) {
      int j = i + s;
      int p = K[i], q = K[i + 1];
      FOR(k, p, q + 1) if (chmin(C[i][j], A(i, k) + B(k, j))) newK[i] = k;
    }
    swap(K, newK);
  }
  return C;
}
