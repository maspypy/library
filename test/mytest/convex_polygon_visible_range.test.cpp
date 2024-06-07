#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "geo/base.hpp"
#include "geo/convex_hull.hpp"
#include "geo/convex_polygon.hpp"
#include "geo/incremental_convexhull.hpp"
#include "random/base.hpp"

using P = Point<ll>;

void test() {
  int N = RNG(3, 10);
  vc<P> point(N);
  FOR(i, N) point[i] = P(RNG(-5, 5), RNG(-5, 5));
  auto I = ConvexHull(point);
  point = rearrange(point, I);
  N = len(point);
  if (N <= 2) return;

  ConvexPolygon<ll> X(point);
  FOR(x, -10, 11) FOR(y, -10, 11) {
    P p(x, y);
    if (X.side(p) == 1) continue;
    auto [l, r] = X.visible_range(p);
    vc<int> can(N);
    {
      int i = l;
      while (1) {
        can[i] = 1;
        if (i == r) break;
        i = (i + 1) % N;
      }
    }
    FOR(i, N) {
      int j = (i + N - 1) % N, k = (i + 1) % N;
      P A = point[j], B = point[i], C = point[k];
      int ok = 0;
      if ((B - A).det(p - A) <= 0) ok = 1;
      if ((B - C).det(p - C) >= 0) ok = 1;
      assert(can[i] == ok);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(30000) test();
  solve();
  return 0;
}
