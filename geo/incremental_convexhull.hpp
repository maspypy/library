#include "geo/base.hpp"

// 下側凸包
template <typename T, bool strict = true>
struct IncrementalConvexHull_Lower {
  using P = Point<T>;
  set<P> S;

  IncrementalConvexHull_Lower() {}

  int size() { return len(S); }

  template <typename ADD_V, typename RM_V, typename ADD_E, typename RM_E>
  void add(Point<T> p, ADD_V add_v, RM_V rm_v, ADD_E add_e, RM_E rm_e) {
    int s = side(p);
    if (strict && s >= 0) return;
    if (!strict && s > 0) return;

    // 点追加
    add_v(p);
    S.insert(p);

    vc<P> left;
    {
      auto it = S.find(p);
      while (it != S.begin()) {
        --it;
        if (left.empty()) {
          left.eb(*it);
          continue;
        }
        auto a = *it;
        auto b = left.back();
        T det = (b - a).det(p - a);
        if (strict && det > 0) break;
        if (!strict && det >= 0) break;
        left.eb(a);
      }
    }

    vc<P> right;
    {
      auto it = S.find(p);
      while (1) {
        ++it;
        if (it == S.end()) break;
        if (right.empty()) {
          right.eb(*it);
          continue;
        }
        auto a = right.back();
        auto b = *it;
        T det = (a - p).det(b - p);
        if (strict && det > 0) break;
        if (!strict && det >= 0) break;
        right.eb(b);
      }
    }

    // 点削除
    if (len(left) > 1) { S.erase(next(S.find(left.back())), S.find(p)); }
    if (len(right) > 1) { S.erase(next(S.find(p)), S.find(right.back())); }
    FOR(i, len(left) - 1) rm_v(left[i]);
    FOR(i, len(right) - 1) rm_v(right[i]);

    // 辺削除
    if (len(left) && len(right)) {
      auto a = left[0], b = right[0];
      rm_e(a, b);
    }
    FOR(i, len(left) - 1) {
      auto a = left[i + 1], b = left[i];
      rm_e(a, b);
    }
    FOR(i, len(right) - 1) {
      auto a = right[i], b = right[i + 1];
      rm_e(a, b);
    }
    // 辺追加
    if (len(left)) { add_e(left.back(), p); }
    if (len(right)) { add_e(p, right.back()); }
  }

  // 中：1, 境界：0, 外：-1
  int side(Point<T> p) {
    auto r = S.lower_bound(p);
    if (r == S.begin() || r == S.end()) return -1;
    auto l = prev(r);
    auto p1 = *l, p2 = *r;
    T det = (p - p1).det(p2 - p1);
    if (det == 0) return 0;
    return (det > 0 ? -1 : 1);
  }
};

template <typename T, bool strict = true>
struct Incremental_ConvexHull {
  using P = Point<T>;
  IncrementalConvexHull_Lower<T, strict> LOWER, UPPER;
  int cnt_V, cnt_E;
  T det_sum;

  Incremental_ConvexHull() : cnt_V(-2), cnt_E(0), det_sum(0) {}

  int size() { return V(); }

  bool empty() { return cnt_V == -2; }

  int V() {
    if (det_sum == 0) return -1; // どうしよ
    return cnt_V;
  }

  int E() { return cnt_E; }

  template <typename REAL>
  REAL area() {
    return det_sum * 0.5;
  }

  template <typename ADD_V, typename RM_V, typename ADD_E, typename RM_E>
  void add(Point<T> p, ADD_V add_v, RM_V rm_v, ADD_E add_e, RM_E rm_e) {
    LOWER.add(
        p,
        [&](Point<T> p) {
          add_v(p);
          ++cnt_V;
        },
        [&](Point<T> p) {
          rm_v(p);
          --cnt_V;
        },
        [&](Point<T> a, Point<T> b) {
          add_e(a, b);
          ++cnt_E;
          det_sum += a.det(b);
        },
        [&](Point<T> a, Point<T> b) {
          rm_e(a, b);
          --cnt_E;
          det_sum -= a.det(b);
        });
    UPPER.add(
        -p,
        [&](Point<T> p) {
          add_v(-p);
          ++cnt_V;
        },
        [&](Point<T> p) {
          rm_v(-p);
          --cnt_V;
        },
        [&](Point<T> a, Point<T> b) {
          add_e(-a, -b);
          ++cnt_E;
          det_sum += a.det(b);
        },
        [&](Point<T> a, Point<T> b) {
          rm_e(-a, -b);
          --cnt_E;
          det_sum -= a.det(b);
        });
  }
  void add(Point<T> p) {
    add(
        p, [](Point<T> p) {}, [](Point<T> p) {}, [](Point<T> s, Point<T> t) {},
        [](Point<T> s, Point<T> t) {});
  }

  // 中：1、境界：0、外：-1
  int side(Point<T> p) {
    int a = LOWER.side(p);
    int b = UPPER.side(-p);
    if (a == 0 || b == 0) return 0;
    return min(a, b);
  }
};
