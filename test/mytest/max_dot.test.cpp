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
    pair<int, int> ans = {infty<int>, -infty<int>};
    FOR(i, N) { chmin(ans.fi, p.dot(point[i])); }
    FOR(i, N) { chmax(ans.se, p.dot(point[i])); }
    auto [mi, i] = X.min_dot(p);
    auto [ma, j] = X.max_dot(p);
    assert(ans.fi == mi && ans.se == ma);
    assert(mi == p.dot(point[i]));
    assert(ma == p.dot(point[j]));
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
