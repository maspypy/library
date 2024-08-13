#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"
#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/convex_hull.hpp"
#include "geo/base.hpp"

using P = Point<ll>;
void solve() {
  LL(N);
  VEC(P, point, N);
  vc<int> I = ConvexHull(point);
  print(len(I));
  for (auto& i: I) print(point[i]);
}

signed main() {
  INT(T);
  FOR(T) solve();
}