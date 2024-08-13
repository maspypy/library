#define PROBLEM "https://yukicoder.me/problems/no/2161"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/offline_query/point_add_rectangle_sum.hpp"

void solve() {
  LL(N, K, L, P);
  VEC(pi, AB, N);
  using T = tuple<int, ll, ll>;

  auto calc = [&](int L, int R) -> vc<T> {
    vc<T> dp = {{0, 0, 0}};
    dp.reserve(1 << (R - L));
    FOR(i, R - L) {
      auto [x, y] = AB[L + i];
      FOR(s, 1 << i) {
        auto [a, b, c] = dp[s];
        dp.eb(a + 1, b + x, c + y);
      }
    }
    return dp;
  };
  auto dp1 = calc(0, N / 2);
  auto dp2 = calc(N / 2, N);
  ll ANS = 0;
  FOR(sz, N / 2 + 1) {
    // 左側の大きさが sz
    if (sz > K) break;
    Point_Add_Rectangle_Sum<Monoid_Add<int>, ll, 0> X;
    for (auto&& [a, b, c]: dp1) {
      if (sz == a) X.add_query(b, c, 1);
    }
    for (auto&& [a, b, c]: dp2) {
      if (sz + a <= K) X.sum_query(-infty<ll>, L - b + 1, P - c, infty<ll>);
    }
    ANS += SUM<ll>(X.calc());
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}