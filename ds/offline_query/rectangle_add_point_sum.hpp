#include "ds/fenwick/fenwick.hpp"

template <typename AbelGroup, bool SMALL>
struct Rectangle_Add_Point_Sum {
  using G = typename AbelGroup::value_type;
  vc<tuple<ll, ll, ll, ll>> rect;
  vc<G> WT;
  vc<pi> point;

  Rectangle_Add_Point_Sum() {}

  void add_query(ll xl, ll xr, ll yl, ll yr, G g) {
    rect.eb(xl, xr, yl, yr);
    WT.eb(g);
  }

  void sum_query(ll x, ll y) { point.eb(x, y); }

  vc<G> calc() {
    int N = len(rect), Q = len(point);
    if (N == 0) return vc<G>(Q, AbelGroup::unit());
    vi keyX, keyY;
    keyX.reserve(2 * N + Q);
    keyY.reserve(2 * N + Q);
    for (auto&& [xl, xr, yl, yr]: rect) {
      keyX.eb(xl), keyX.eb(xr), keyY.eb(yl), keyY.eb(yr);
    }
    for (auto&& [x, y]: point) { keyX.eb(x), keyY.eb(y); }
    int NX = 0, NY = 0;
    if (!SMALL) {
      UNIQUE(keyX), UNIQUE(keyY);
      NX = len(keyX), NY = len(keyY);
      for (auto&& [xl, xr, yl, yr]: rect) {
        xl = LB(keyX, xl), xr = LB(keyX, xr);
        yl = LB(keyY, yl), yr = LB(keyY, yr);
      }
      for (auto&& [x, y]: point) {
        x = LB(keyX, x);
        y = LB(keyY, y);
      }
    } else {
      ll mx = MIN(keyX), my = MIN(keyY);
      NX = MAX(keyX) - mx + 1, NY = MAX(keyY) - my + 1;
      for (auto&& [xl, xr, yl, yr]: rect) {
        xl = xl - mx, xr = xr - mx;
        yl = yl - my, yr = yr - my;
      }
      for (auto&& [x, y]: point) { x = x - mx, y = y - my; }
    }
    vvc<tuple<int, int, G>> ADD(NY);
    vvc<int> CALC(NY);
    FOR(i, N) {
      auto [xl, xr, yl, yr] = rect[i];
      ADD[yl].eb(xl, xr, WT[i]);
      ADD[yr].eb(xl, xr, AbelGroup::inverse(WT[i]));
    }
    FOR(q, Q) {
      auto [x, y] = point[q];
      CALC[y].eb(q);
    }
    vc<G> res(Q);
    FenwickTree<AbelGroup> bit(NX);
    FOR(y, NY) {
      for (auto&& [xl, xr, g]: ADD[y]) {
        bit.add(xl, g);
        bit.add(xr, AbelGroup::inverse(g));
      }
      for (auto&& q: CALC[y]) {
        auto [x, y] = point[q];
        res[q] = bit.prod(x + 1);
      }
    }
    return res;
  }
};
