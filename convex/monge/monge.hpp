#include "convex/larsch.hpp"
#include "convex/smawk.hpp"
#include "other/fibonacci_search.hpp"

// 定義域 [0, N] の範囲で f の monge 性を確認
template <typename T, typename F>
bool check_monge(int N, F f) {
  FOR(l, N + 1) FOR(k, l) FOR(j, k) FOR(i, j) {
    T lhs = f(i, l) + f(j, k);
    T rhs = f(i, k) + f(j, l);
    if (lhs < rhs) {
      print("monge ng");
      print(i, j, k, l, f(i, k), f(i, l), f(j, k), f(j, l), lhs, rhs);
      return false;
    }
  }
  print("monge ok");
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
  auto g = [&](int i, int j) -> T {
    ++i;
    if (i <= j) return infty<T>;
    return dp[j] + f(j, i);
  };
  LARSCH<T, decltype(g)> larsch(N, g);
  FOR(r, 1, N + 1) {
    int l = larsch.get_argmin();
    dp[r] = dp[l] + f(l, r);
  }
  return dp;
}

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
