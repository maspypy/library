#include "geo3d/base.hpp"

// 0: 交点なし
// 1: 一意な交点
// 2：2 つ以上の交点
template <typename T>
int count_cross(Line_3d<T> L1, Line_3d<T> L2) {
  static_assert(!std::is_floating_point<T>::value);
  if (L1.is_parallel(L2)) {
    if (L1.contain(L2.a)) return 2;
    return 0;
  }
  Point_3d<T> norm = L1.d.cross(L2.d);
  return ((L1.a - L2.a).dot(norm) == 0 ? 1 : 0);
}

// count_cross == 1 のときにだけ呼ぶこと
template <typename REAL, typename T>
Point_3d<REAL> cross_point(Line_3d<T> L1, Line_3d<T> L2) {
  Point_3d<T> d1 = L1.d;
  Point_3d<T> d2 = L2.d;
  Point_3d<T> a = L2.a - L1.a;
  REAL t1 = [&]() -> REAL {
    FOR(3) {
      d1 = {d1.y, d1.z, d1.x};
      d2 = {d2.y, d2.z, d2.x};
      a = {a.y, a.z, a.x};
      T det = d1.x * d2.y - d1.y * d2.x;
      if (det != 0) { return REAL(a.x * d2.y - a.y * d2.x) / REAL(det); }
    }
    assert(0);
    return 0;
  }();
  REAL x = REAL(L1.a.x) + t1 * REAL(L1.d.x);
  REAL y = REAL(L1.a.y) + t1 * REAL(L1.d.y);
  REAL z = REAL(L1.a.z) + t1 * REAL(L1.d.z);
  return {x, y, z};
}
