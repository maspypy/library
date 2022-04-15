#include "geo/convexhull.hpp"
#include "geo/base.hpp"

// 最遠点対となる 2 点の index をかえす。空集合はエラー。
template <typename T>
pair<int, int> points_diameter(vc<Point<T>>& XY) {
  ll N = len(XY);
  assert(N >= 1);
  if (N == 1) return {0, 0};
  auto I = ConvexHull(XY, "full");
  pi res = {0, 0};
  ll best = 0;
  ll s = 0;
  FOR(k, len(I)) {
    ll i = (k == 0 ? I.back() : I[k - 1]), j = I[k];
    Point<T> A = XY[i], B = XY[j];
    ll dx = B.x - A.x, dy = B.y - A.y;
    Point<T> vec = {-dy, dx};
    while (1) {
      Point<T> p = XY[I[s]], q = XY[I[(s + 1) % len(I)]];
      if (vec.dot(p - q) < 0)
        s = (s + 1) % len(I);
      else
        break;
    }
    Point<T> C = XY[I[s]];
    if (chmax(best, (A - C).dot(A - C))) res = {i, I[s]};
    if (chmax(best, (B - C).dot(B - C))) res = {j, I[s]};
  }
  return res;
}
