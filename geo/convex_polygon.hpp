#include "geo/base.hpp"
#include "geo/convex_hull.hpp"

// strict: n>=3 の反時計回り狭義凸多角形
// non-strict: n=1 の点、n=2 の線分、または n>=3 の反時計回り凸多角形
template <typename T, bool is_strict = true>
struct Convex_Polygon {
  using P = Point<T>;
  int n;
  vc<P> point;
  T area2;

  Convex_Polygon(vc<P> point_) : n(len(point_)), point(point_) {
    assert(n >= 1);
    if constexpr (is_strict) assert(n >= 3);
    area2 = 0;
    FOR(i, n) {
      int j = nxt_idx(i);
      if (n >= 2) assert(point[i] != point[j]);
      area2 += point[i].det(point[j]);
    }
    assert(area2 >= T(0));
    if (n >= 3) assert(area2 > T(0));
    if (n >= 3) FOR(i, n) {
        int j = nxt_idx(i), k = nxt_idx(j);
        T det = (point[j] - point[i]).det(point[k] - point[i]);
        if constexpr (is_strict)
          assert(det > T(0));
        else
          assert(det >= T(0));
      }
  }

  template <typename F>
  int periodic_min_comp(F comp) const {
    static_assert(is_strict);
    int L = 0, M = n, R = n + n;
    while (R - L != 2) {
      int L1 = (L + M) / 2, R1 = (M + R + 1) / 2;
      if (comp(L1 % n, M % n)) R = M, M = L1;
      elif (comp(R1 % n, M % n)) L = M, M = R1;
      else L = L1, R = R1;
    }
    return M % n;
  }

  int nxt_idx(int i) const { return (i + 1 == n ? 0 : i + 1); }
  int prev_idx(int i) const { return (i == 0 ? n - 1 : i - 1); }

  // 中：1, 境界：0, 外：-1.
  int side(P p) const {
    if (n == 1) return (p == point[0] ? 0 : -1);
    if (n == 2) {
      P A = point[0], B = point[1];
      if ((B - A).det(p - A) == 0 && (B - A).dot(p - A) >= 0 &&
          (A - B).dot(p - B) >= 0)
        return 0;
      return -1;
    }
    int L = 1, R = n - 1;
    T a = (point[L] - point[0]).det(p - point[0]);
    T b = (point[R] - point[0]).det(p - point[0]);
    if (a < 0 || b > 0) return -1;
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
    if (p == point[0]) return 0;
    if (c != 0 && a == 0 && L != 1) return 1;
    if (c != 0 && b == 0 && R != n - 1) return 1;
    return 0;
  }

  // return {min, i, j}. i==j は頂点, i!=j は最適辺 i -> j.
  tuple<T, int, int> min_dot(P p) const {
    static_assert(is_strict);
    assert(p != P(0, 0));
    int idx = periodic_min_comp(
        [&](int i, int j) { return point[i].dot(p) < point[j].dot(p); });
    T val = point[idx].dot(p);
    int prv = prev_idx(idx), nxt = nxt_idx(idx);
    if (point[prv].dot(p) == val) return {val, prv, idx};
    if (point[nxt].dot(p) == val) return {val, idx, nxt};
    return {val, idx, idx};
  }

  // return {max, i, j}. i==j は頂点, i!=j は最適辺 i -> j.
  tuple<T, int, int> max_dot(P p) const {
    static_assert(is_strict);
    assert(p != P(0, 0));
    int idx = periodic_min_comp(
        [&](int i, int j) { return point[i].dot(p) > point[j].dot(p); });
    T val = point[idx].dot(p);
    int prv = prev_idx(idx), nxt = nxt_idx(idx);
    if (point[prv].dot(p) == val) return {val, prv, idx};
    if (point[nxt].dot(p) == val) return {val, idx, nxt};
    return {val, idx, idx};
  }

  pair<int, int> visible_range(P p) const {
    static_assert(is_strict);
    int a = periodic_min_comp(
        [&](int i, int j) { return (point[i] - p).det(point[j] - p) < 0; });
    int b = periodic_min_comp(
        [&](int i, int j) { return (point[i] - p).det(point[j] - p) > 0; });
    if ((p - point[a]).det(p - point[prev_idx(a)]) == T(0)) a = prev_idx(a);
    if ((p - point[b]).det(p - point[nxt_idx(b)]) == T(0)) b = nxt_idx(b);
    return {a, b};
  }

  bool check_cross(P A, P B) const {
    static_assert(is_strict);
    FOR(2) {
      swap(A, B);
      auto [a, b] = visible_range(A);
      if ((point[a] - A).det(B - A) >= 0) return false;
      if ((point[b] - A).det(B - A) <= 0) return false;
    }
    return true;
  }

  T area_between(int i, int j) const {
    assert(i <= j && j <= i + n);
    if (j == i + n) return area2;
    i %= n, j %= n;
    if (i > j) j += n;
    if (AREA.empty()) build_AREA();
    return AREA[j] - AREA[i] + point[j % n].det(point[i]);
  }

  T left_area(Line<T> L) const {
    static_assert(is_strict);
    static_assert(is_same<T, double>::value || is_same<T, long double>::value);
    Point<T> normal(L.a, L.b);
    auto [min_value, a, min_j] = min_dot(normal);
    auto [max_value, b, max_j] = max_dot(normal);
    if (b < a) b += n;
    assert(L.eval(point[a % n]) < 0 && L.eval(point[b % n]) > 0);
    int p =
        binary_search([&](int i) { return L.eval(point[i % n]) < 0; }, a, b);
    int q = binary_search(
        [&](int i) { return L.eval(point[i % n]) > 0; }, b, a + n);
    T s = L.eval(point[p % n]) /
          (L.eval(point[p % n]) - L.eval(point[(p + 1) % n]));
    T t = L.eval(point[q % n]) /
          (L.eval(point[q % n]) - L.eval(point[(q + 1) % n]));
    P A = point[p % n], B = point[(p + 1) % n];
    P C = point[q % n], D = point[(q + 1) % n];
    P X = B * s + A * (1 - s), Y = D * t + C * (1 - t);
    T ans = area_between(p, q);
    ans -= (A - C).det(X - C);
    ans += (Y - C).det(X - C);
    return ans;
  }

 private:
  mutable vc<T> AREA;

  void build_AREA() const {
    AREA.resize(2 * n);
    FOR(i, n) AREA[n + i] = AREA[i] = point[i].det(point[nxt_idx(i)]);
    AREA = cumsum<T>(AREA);
  }
};
