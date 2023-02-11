#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "geo/range_closest_pair_query.hpp"

void test() {
  FOR(N, 2, 100) {
    FOR(Q, 1, 100) {
      vc<pair<int, int>> point(N), query(Q);
      FOR(i, N) {
        int x = RNG(0, 20);
        int y = RNG(0, 20);
        point[i] = {x, y};
      }
      FOR(q, Q) {
        while (1) {
          int L = RNG(0, N);
          int R = RNG(0, N);
          if (L + 1 <= R) {
            query[q] = {L, R + 1};
            break;
          }
        }
      }
      Range_Closest_Pair_Query X;
      for (auto&& [a, b]: point) X.add_point(a, b);
      for (auto&& [l, r]: query) X.add_query(l, r);
      vi ANS = X.calc();
      FOR(q, Q) {
        ll ans = infty<ll>;
        auto [L, R] = query[q];
        FOR(i, L, R) FOR(j, L, R) {
          if (i == j) continue;
          auto [x1, y1] = point[i];
          auto [x2, y2] = point[j];
          ll dx = x1 - x2, dy = y1 - y2;
          chmin(ans, dx * dx + dy * dy);
        }
        assert(ans == ANS[q]);
      }
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}