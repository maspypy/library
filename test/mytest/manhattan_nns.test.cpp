#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "geo/manhattan_nns.hpp"

void test() {
  FOR(n, 1, 20) FOR(m, 1, 20) {
    vc<pi> A, B;
    FOR(n) {
      int a = RNG(0, 100);
      int b = RNG(0, 100);
      A.eb(a, b);
    }
    FOR(m) {
      int a = RNG(0, 100);
      int b = RNG(0, 100);
      B.eb(a, b);
    }
    auto [dist, J] = manhattan_nns(A, B);
    FOR(i, n) {
      FOR(j, m) {
        auto [x1, y1] = A[i];
        auto [x2, y2] = B[j];
        int d = abs(x1 - x2) + abs(y1 - y2);
        assert(dist[i] <= d);
        assert(j != J[i] || dist[i] == d);
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