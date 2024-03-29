#include "geo/base.hpp"
#include "geo/convex_hull.hpp"

// ほとんどテストされていないのであやしい
// n=2 は現状サポートしていない
// 同一直線上に複数の点があると正しく動かない説がある
template <typename T>
struct ConvexPolygon {
  using P = Point<T>;
  int n;
  vc<P> point;

  ConvexPolygon(vc<P> point_, bool is_conv) : n(len(point_)), point(point_) {
    if (!is_conv) {
      vc<int> I = ConvexHull<T>(point_, "full");
      point = rearrange(point_, I);
    }
    // assert(n >= 3);
    // counter clockwise になおす
    if (n >= 3) {
      if ((point[1] - point[0]).det(point[2] - point[0]) < 0) {
        reverse(all(point));
      }
    }
  }

  // 比較関数 comp(i,j)
  template <typename F>
  int periodic_min_comp(F comp) {
    int L = 0, M = n, R = n + n;
    while (1) {
      if (R - L == 2) break;
      int L1 = (L + M) / 2, R1 = (M + R + 1) / 2;
      if (comp(L1, M)) { R = M, M = L1; }
      elif (comp(R1, M)) { L = M, M = R1; }
      else {
        L = L1, R = R1;
      }
    }
    return M % n;
  }

  int nxt_idx(int i) { return (i + 1 == n ? 0 : i + 1); }
  int prev_idx(int i) { return (i == 0 ? n - 1 : i - 1); }

  // 中：1, 境界：0, 外：-1
  int side(P p) {
    int L = 1, R = n - 1;
    T a = (point[L] - point[0]).det(p - point[0]);
    T b = (point[R] - point[0]).det(p - point[0]);
    if (a < 0 || b > 0) return -1;
    // p は 0 から見て [L,R] 方向
    while (R - L >= 2) {
      int M = (L + R) / 2;
      T c = (point[M] - point[0]).det(p - point[0]);
      if (c < 0)
        R = M, b = c;
      else
        L = M, a = c;
    }
    T c = (point[R] - point[L]).det(p - point[L]);
    T x = min({a, -b, c});
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
  }

  pair<int, T> min_dot(P p) {
    int idx = periodic_min_comp([&](int i, int j) -> bool {
      return point[i % n].dot(p) < point[j % n].dot(p);
    });
    return {idx, point[idx].dot(p)};
  }
  pair<int, T> max_dot(P p) {
    int idx = periodic_min_comp([&](int i, int j) -> bool {
      return point[i % n].dot(p) > point[j % n].dot(p);
    });
    return {idx, point[idx].dot(p)};
  }
  // pair<int, int> visible_range(P p) {}
};