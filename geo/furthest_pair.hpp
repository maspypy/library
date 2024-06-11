#include "geo/base.hpp"
#include "geo/convex_hull.hpp"

template <typename T>
pair<int, int> furthest_pair(vc<Point<T>> point) {
  T best = -1;
  pair<int, int> ANS = {-1, -1};

  auto upd = [&](int i, int j) -> void {
    Point<T> p = point[i] - point[j];
    ll d = p.dot(p);
    if (chmax(best, d)) ANS = {i, j};
  };
  upd(0, 1);

  auto I = ConvexHull(point);
  int n = len(I);
  if (n == 1) return ANS;
  if (n == 2) { return {I[0], I[1]}; }
  /*
  直径と垂直な平行線 2 本で凸包をはさめる
  平行線 2 本ではさんで引っかかる 2 点が候補
  p[i]p[i+1] の反対側を候補とすればよい
  */
  FOR(i, n) I.eb(I[i]);

  vc<Point<T>> C = rearrange(point, I);
  int j = 1;
  FOR(i, n) {
    chmax(j, i);
    while (j < 2 * n && (C[i + 1] - C[i]).det(C[j + 1] - C[j]) > 0) ++j;
    upd(I[i], I[j]);
  }
  return ANS;
}
