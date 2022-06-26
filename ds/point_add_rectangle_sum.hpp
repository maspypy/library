#include "ds/fenwick.hpp"

// 点群はクエリより前に全部入力すること (add_pt)。
// 同じ点群に対してクエリをやり直せる。
// SMALL=true にすると、座圧をしないため少し高速
template <typename AbelGroup, bool SMALL = false>
struct Point_Add_Rectangle_Sum {
  using G = typename AbelGroup::value_type;
  int Q;
  vi X, Y;
  vc<G> WT;
  vc<tuple<ll, ll, ll, ll>> rect;

  Point_Add_Rectangle_Sum() {}

  void add_query(ll x, ll y, G w) { X.eb(x), Y.eb(y), WT.eb(w); }

  void sum_query(ll xl, ll yl, ll xr, ll yr) { rect.eb(xl, yl, xr, yr); }

  vc<G> calc() {
    int N = len(X), Q = len(rect);
    if (N == 0) return vc<G>(Q, AbelGroup::unit());
    int NX = 0, NY = 0;
    if (!SMALL) {
      vi keyX = X, keyY = Y;
      UNIQUE(keyX), UNIQUE(keyY);
      NX = len(keyX), NY = len(keyY);
      for (auto&& x: X) x = LB(keyX, x);
      for (auto&& y: Y) y = LB(keyY, y);
      for (auto&& [xl, xr, yl, yr]: rect) {
        xl = LB(keyX, xl);
        xr = LB(keyX, xr);
        yl = LB(keyY, yl);
        yr = LB(keyY, yr);
      }
    }
    if (SMALL) {
      ll mx = MIN(X);
      ll my = MIN(Y);
      for (auto&& x: X) x -= mx;
      for (auto&& y: Y) y -= my;
      NX = MAX(X) + 1, NY = MAX(Y) + 1;
      for (auto&& [xl, yl, xr, yr]: rect) {
        xl -= mx, xr -= mx;
        yl -= my, yr -= my;
        xl = max(0, min<int>(xl, NX));
        xr = max(0, min<int>(xr, NX));
        yl = max(0, min<int>(yl, NY));
        yr = max(0, min<int>(yr, NY));
      }
    }
    vvc<pair<int, G>> ADD(NY + 1);
    vvc<tuple<int, int, int>> CALC_1(NY + 1);
    vvc<tuple<int, int, int>> CALC_2(NY + 1);
    FOR(n, N) { ADD[Y[n]].eb(X[n], WT[n]); }
    FOR(q, Q) {
      auto& [xl, yl, xr, yr] = rect[q];
      CALC_1[yr].eb(xl, xr, q);
      CALC_2[yl].eb(xl, xr, q);
    };

    vc<G> res(Q, AbelGroup::unit());
    FenwickTree<AbelGroup> bit(NX);

    FOR(y, NY + 1) {
      for (auto&& [xl, xr, q]: CALC_1[y]) {
        auto x = bit.sum(xl, xr);
        res[q] = AbelGroup::op(res[q], x);
      }
      for (auto&& [xl, xr, q]: CALC_2[y]) {
        auto x = AbelGroup::inverse(bit.sum(xl, xr));
        res[q] = AbelGroup::op(res[q], x);
      }
      for (auto&& [x, g]: ADD[y]) { bit.add(x, g); }
    }
    return res;
  }
};
