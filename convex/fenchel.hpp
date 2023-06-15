#include "geo/convex_hull.hpp"
#include "geo/base.hpp"

// (L,R,a,b)：傾きが [L,R) のとき (a,b) を通る
template <typename T>
vc<tuple<T, T, T, T>> Fenchel(vc<Point<T>> XY, string mode, bool sorted) {
  if (mode == "upper") {
    for (auto&& p: XY) p.y = -p.y;
    vc<tuple<T, T, T, T>> res;
    for (auto&& [L, R, a, b]: Fenchel(XY, "lower", sorted)) {
      T l = (R == infty<T> ? -infty<T> : 1 - R);
      T r = (L == -infty<T> ? infty<T> : 1 - L);
      chmax(l, -infty<T>), chmin(r, infty<T>);
      res.eb(l, r, a, -b);
    }
    reverse(all(res));
    return res;
  }
  auto I = ConvexHull(XY, "lower", false, sorted);
  XY = rearrange(XY, I);
  vc<tuple<T, T, T, T>> res;

  ll lo = -infty<ll>;
  FOR(i, len(XY)) {
    T hi = infty<T>;
    if (i + 1 < len(XY)) {
      chmin(hi, floor(XY[i + 1].y - XY[i].y, XY[i + 1].x - XY[i].x) + 1);
    };
    if (lo < hi) res.eb(lo, hi, XY[i].x, XY[i].y);
    lo = hi;
  }
  return res;
}