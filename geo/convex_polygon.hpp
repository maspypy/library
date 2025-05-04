#pragma once

#include "geo/base.hpp"
#include "geo/convex_hull.hpp"

// n=2 は現状サポートしていない
template <typename T>
struct ConvexPolygon {
  using P = Point<T>;
  int n;
  vc<P> point;
  T area2;

  ConvexPolygon(vc<P> point_) : n(len(point_)), point(point_) {
    assert(n >= 3);
    area2 = 0;
    FOR(i, n) {
      int j = nxt_idx(i), k = nxt_idx(j);
      assert((point[j] - point[i]).det(point[k] - point[i]) >= 0);
      area2 += point[i].det(point[j]);
    }
  }

  // 比較関数 comp(i,j)
  template <typename F>
  int periodic_min_comp(F comp) {
    int L = 0, M = n, R = n + n;
    while (1) {
      if (R - L == 2) break;
      int L1 = (L + M) / 2, R1 = (M + R + 1) / 2;
      if (comp(L1 % n, M % n)) { R = M, M = L1; }
      elif (comp(R1 % n, M % n)) { L = M, M = R1; }
      else {
        L = L1, R = R1;
      }
    }
    return M % n;
  }

  int nxt_idx(int i) { return (i + 1 == n ? 0 : i + 1); }
  int prev_idx(int i) { return (i == 0 ? n - 1 : i - 1); }

  // 中：1, 境界：0, 外：-1. test した.
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
    // on triangle p[0]p[L]p[R]
    if (p == point[0]) return 0;
    if (c != 0 && a == 0 && L != 1) return 1;
    if (c != 0 && b == 0 && R != n - 1) return 1;
    return 0;
  }

  // return {min, idx}. test した.
  pair<T, int> min_dot(P p) {
    int idx = periodic_min_comp([&](int i, int j) -> bool { return point[i].dot(p) < point[j].dot(p); });
    return {point[idx].dot(p), idx};
  }

  // return {max, idx}. test した.
  pair<T, int> max_dot(P p) {
    int idx = periodic_min_comp([&](int i, int j) -> bool { return point[i].dot(p) > point[j].dot(p); });
    return {point[idx].dot(p), idx};
  }

  // p から見える範囲. p 辺に沿って見えるところも見えるとする. test した.
  // 多角形からの反時計順は [l,r] だが p から見た偏角順は [r,l] なので注意
  pair<int, int> visible_range(P p) {
    int a = periodic_min_comp([&](int i, int j) -> bool { return ((point[i] - p).det(point[j] - p) < 0); });
    int b = periodic_min_comp([&](int i, int j) -> bool { return ((point[i] - p).det(point[j] - p) > 0); });
    if ((p - point[a]).det(p - point[prev_idx(a)]) == T(0)) a = prev_idx(a);
    if ((p - point[b]).det(p - point[nxt_idx(b)]) == T(0)) b = nxt_idx(b);
    return {a, b};
  }

  // 線分が「内部と」交わるか
  // https://codeforces.com/contest/1906/problem/D
  bool check_cross(P A, P B) {
    FOR(2) {
      swap(A, B);
      auto [a, b] = visible_range(A);
      if ((point[a] - A).det(B - A) >= 0) return 0;
      if ((point[b] - A).det(B - A) <= 0) return 0;
    }
    return 1;
  }

  vc<T> AREA;

  // point[i,...,j] (inclusive) の面積の 2 倍
  T area_between(int i, int j) {
    assert(i <= j && j <= i + n);
    if (j == i + n) return area2;
    i %= n, j %= n;
    if (i > j) j += n;
    if (AREA.empty()) build_AREA();
    return AREA[j] - AREA[i] + (point[j % n].det(point[i]));
  }

  void build_AREA() {
    AREA.resize(2 * n);
    FOR(i, n) AREA[n + i] = AREA[i] = point[i].det(point[nxt_idx(i)]);
    AREA = cumsum<T>(AREA);
  }

  // 直線の左側の面積. strict に 2 回交わることを仮定.
  // https://codeforces.com/contest/799/problem/G
  T left_area(Line<T> L) {
    static_assert(is_same<T, double>::value || is_same<T, long double>::value);
    Point<T> normal(L.a, L.b);
    int a = min_dot(normal).se;
    int b = max_dot(normal).se;
    if (b < a) b += n;
    assert(L.eval(point[a % n]) < 0 && L.eval(point[b % n]) > 0);
    int p = binary_search([&](int i) -> bool { return L.eval(point[i % n]) < 0; }, a, b);
    int q = binary_search([&](int i) -> bool { return L.eval(point[i % n]) > 0; }, b, a + n);
    T s, t;
    {
      T x = L.eval(point[p % n]);
      T y = L.eval(point[(p + 1) % n]);
      s = x / (x - y);
    }
    {
      T x = L.eval(point[q % n]);
      T y = L.eval(point[(q + 1) % n]);
      t = x / (x - y);
    }
    P A(point[p % n]), B(point[(p + 1) % n]);
    P C(point[q % n]), D(point[(q + 1) % n]);
    P X = B * s + A * (1 - s);
    P Y = D * t + C * (1 - t);
    T ANS = area_between(p, q);
    ANS -= (A - C).det(X - C);
    ANS += (Y - C).det(X - C);
    return ANS;
  }
};