#include "geo/convex_polygon.hpp"
#include "geo/angle_sort.hpp"
#include "geo/convex_hull.hpp"

// https://codeforces.com/contest/87/problem/E
template <typename T>
vc<Point<T>> minkowski_sum(vc<Point<T>> A, vc<Point<T>> B) {
  using P = Point<T>;
  vc<P> F;
  P p(0, 0);
  FOR(2) {
    swap(A, B);
    vc<P> point = A;
    int n = len(point);
    FOR(i, n) {
      int j = (i + 1) % n;
      F.eb(point[j] - point[i]);
    }
    p = p + MIN(point);
  }
  auto I = angle_sort(F);
  int n = len(I);
  F = rearrange(F, I);
  vc<P> point(n);
  FOR(i, n - 1) point[i + 1] = point[i] + F[i];
  P add = p - MIN(point);
  for (auto& x: point) x = x + add;
  I = ConvexHull(point);
  point = rearrange(point, I);
  return point;
}
