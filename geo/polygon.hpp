#include "geo/base.hpp"
#include "geo/cross_point.hpp"

template <typename T>
struct Polygon {
  vc<Point<T>> point;
  T a;

  Polygon(vc<Point<T>> point) : point(point) { build(); }

  int size() { return len(point); }

  template <typename REAL>
  REAL area() {
    return a * 0.5;
  }

  T area_2() { return a; }

  bool is_convex() {
    FOR(j, len(point)) {
      int i = (j == 0 ? len(point) - 1 : j - 1);
      int k = (j == len(point) - 1 ? 0 : j + 1);
      if ((point[j] - point[i]).det(point[k] - point[j]) < 0) return false;
    }
    return true;
  }

  // 中：1, 境界：0, 外：-1.
  int side(Point<T> p) {
    int n = len(point);
    FOR(i, n) if (point[i] == p) return 0;
    FOR(i, n) {
      Point<T> A = point[i], B = point[(i + 1) % n];
      if ((p - A).det(B - A) != 0) continue;
      if ((p - A).dot(B - A) >= 0 && (p - B).dot(A - B) >= 0) return 0;
    }
    // p から x 方向に (+1, +eps) 方向にのびる半直線との交差を考える
    int cnt = 0;
    FOR(i, n) {
      Point<T> A = point[i], B = point[(i + 1) % n];
      FOR(2) {
        swap(A, B);
        if (A.y > p.y) continue;
        if (B.y <= p.y) continue;
        if ((A - p).det(B - p) > 0) ++cnt;
      }
    }
    return (cnt % 2 == 0 ? -1 : 1);
  }

  // point[i] の近傍だけで見た side
  // https://github.com/maspypy/library/blob/main/geo/polygon_side.png
  int side_at(int i, Point<T> p) {
    int n = len(point);
    p -= point[i];
    if (p.x == T(0) && p.y == T(0)) return 0;
    Point<T> L = point[(i + 1) % n] - point[i];
    Point<T> R = point[(i + n - 1) % n] - point[i];
    auto sgn = [&](T x) -> int {
      if (x == T(0)) return 0;
      return (x > T(0) ? 1 : -1);
    };
    int x = sgn(L.det(p)) + sgn(p.det(R)) + sgn(R.det(L));
    if (x == 0) return x;
    return (x > 0 ? 1 : -1);
  }

  // 線分が内部・外部それぞれを通るか
  // https://atcoder.jp/contests/jag2016-domestic/tasks/jag2016secretspring_e
  // https://atcoder.jp/contests/JAG2014Spring/tasks/icpc2014spring_f
  pair<bool, bool> side_segment(Point<T> L, Point<T> R) {
    Segment<T> S(L, R);
    // まず線分と非自明に交わるパターン
    int n = len(point);
    FOR(i, n) {
      Segment<T> S2(point[i], point[(i + 1) % n]);
      if (count_cross(S, S2, false) == 1) {
        return {1, 1};
      }
    }
    bool in = 0, out = 0;
    if (side(L) == 1 || side(R) == 1) in = 1;
    if (side(L) == -1 || side(R) == -1) out = 1;
    FOR(i, n) {
      if (!S.contain(point[i])) continue;
      for (auto& p : {L, R}) {
        int k = side_at(i, p);
        if (k == 1) in = 1;
        if (k == -1) out = 1;
      }
    }
    return {in, out};
  }

  // polygon と line の共通部分を line 上の区間列として返す。
  // return される Segment：退化ケースもある
  // https://codeforces.com/contest/598/problem/F
  template <typename REAL>
  vc<Segment<REAL>> cross_line(Line<T> L, bool allow_perimeter) {
    static_assert(is_integral_v<T>);
    using RP = Point<REAL>;
    int N = len(point);
    vc<int> side(N);
    auto sgn = [&](T x) -> int { return (x > 0 ? 1 : x < 0 ? -1 : 0); };

    FOR(i, N) side[i] = sgn(L.eval(point[i]));
    vc<pair<RP, int>> event;

    FOR(i, N) {
      int j = (i + 1) % N;

      if (side[i] == 0) {
        int k = (i + N - 1) % N;
        int c = side[k] - side[j];
        event.eb(RP(point[i]), c);
      }

      if (side[i] * side[j] < 0) {
        RP p = cross_point<REAL>(L, Line<T>(point[i], point[j]));
        int c = side[i] - side[j];
        event.eb(p, c);
      }
    }

    if (L.b != 0) {
      sort(all(event), [&](auto& x, auto& y) {
        if (x.fi.x != y.fi.x) return x.fi.x < y.fi.x;
        return x.fi.y < y.fi.y;
      });
    } else {
      sort(all(event), [&](auto& x, auto& y) {
        if (x.fi.y != y.fi.y) return x.fi.y < y.fi.y;
        return x.fi.x < y.fi.x;
      });
    }

    vc<Segment<REAL>> ANS;
    int in = 0;

    if (allow_perimeter) {
      int l = 0;
      FOR(i, len(event)) {
        in += event[i].se;
        if (i + 1 == len(event) || in == 0) {
          ANS.eb(event[l].fi, event[i].fi);
          l = i + 1;
        }
      }
    } else {
      FOR(i, len(event)) {
        in += event[i].se;
        if (i + 1 < len(event) && abs(in) == 2) {
          ANS.eb(event[i].fi, event[i + 1].fi);
        }
      }
    }

    assert(in == 0);
    return ANS;
  }

 private:
  void build() {
    a = 0;
    FOR(i, len(point)) {
      int j = (i + 1 == len(point) ? 0 : i + 1);
      a += point[i].det(point[j]);
    }
    if (a < 0) {
      reverse(all(point));
    }
  }
};