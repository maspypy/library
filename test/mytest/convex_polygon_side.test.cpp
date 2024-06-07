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

  Incremental_ConvexHull<ll> Y;
  for (auto& p: point) Y.add(p);

  auto I = ConvexHull(point);
  point = rearrange(point, I);
  N = len(point);
  if (N <= 2) return;

  ConvexPolygon<ll> X(point);

  FOR(x, -10, 11) FOR(y, -10, 11) {
    P p(x, y);
    int ans = 1;
    [&]() -> int {
      FOR(i, N) {
        P A = point[i], B = point[(i + 1) % N];
        if ((B - A).det(p - A) <= 0) chmin(ans, 0);
        if ((B - A).det(p - A) < 0) chmin(ans, -1);
      }
      return ans;
    }();
    assert(ans == X.side(p));
    assert(ans == Y.side(p));
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(10000) test();
  solve();
  return 0;
}
