
#include "ds/fastset.hpp"

// [0, x] x [0, y] を追加 -> 和集合面積を取得
template <typename XY, typename AREA, bool SMALL_XY>
struct Incremental_Rectangle_Union {
  FastSet ss;
  vc<XY> ht;
  map<XY, XY> MP; // right end -> height
  ll area;

  Incremental_Rectangle_Union() : area(AREA(0)) {
    static_assert(!SMALL_XY);
    MP[0] = infty<XY>;
    MP[infty<XY>] = 0;
  }

  Incremental_Rectangle_Union(int LIM)
      : ss(LIM + 1), ht(LIM + 1), area(AREA(0)) {
    static_assert(SMALL_XY);
    ht[0] = infty<XY>, ht[LIM] = 0, ss.insert(0), ss.insert(LIM);
  }

  AREA add(XY x, XY y) {
    if constexpr (SMALL_XY) add_fast(x, y);
    if constexpr (!SMALL_XY) add_MP(x, y);
    return area;
  }

private:
  void add_MP(XY x, XY y) {
    if (x == 0 || y == 0) return;
    auto it = MP.lower_bound(x);
    auto [rx, ry] = *it;
    if (ry >= y) return;

    // split
    if (x < rx) MP[x] = ry;
    it = MP.find(x);
    while (1) {
      auto [x2, y2] = *it;
      it = prev(MP.erase(it));
      auto [x1, y1] = *it;
      // [x1,x2]: y2 -> 0
      area -= AREA(x2 - x1) * AREA(y2);
      if (y1 >= y) break;
    }
    auto [x1, y1] = *it;
    // [x1, x]: 0 -> y
    MP[x] = y, area += AREA(x - x1) * AREA(y);
    return;
  }

  void add_fast(XY x, XY y) {
    if (x == 0 || y == 0) return;
    int rx = ss.next(x);
    int ry = ht[rx];
    if (ry >= y) return;

    // split
    if (x < rx) ss.insert(x), ht[x] = ry;
    int x2 = x;
    while (1) {
      XY y2 = ht[x2];
      ss.erase(x2);
      int x1 = ss.prev(x2);
      XY y1 = ht[x1];
      // [x1,x2]: y2 -> 0
      area -= AREA(x2 - x1) * AREA(y2);
      x2 = x1;
      if (y1 >= y) break;
    }
    ss.insert(x), ht[x] = y, area += AREA(x - x2) * AREA(y);
    return;
  }
};
