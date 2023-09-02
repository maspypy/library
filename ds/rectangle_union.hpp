#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/minmincnt_add.hpp"

template <typename XY = int>
struct Rectangle_Union {
  using RECT = tuple<XY, XY, XY, XY>;
  vc<RECT> rectangles;
  vc<XY> X, Y;

  void add_rect(XY xl, XY xr, XY yl, XY yr) {
    assert(xl < xr && yl < yr);
    X.eb(xl), X.eb(xr), Y.eb(yl), Y.eb(yr);
    rectangles.eb(xl, xr, yl, yr);
  }

  template <typename ANS_TYPE = ll>
  ANS_TYPE calc() {
    int N = len(X);
    vc<int> ord_x = argsort(X);
    vc<int> ord_y = argsort(Y);
    vc<int> rk_y(N);
    FOR(i, N) rk_y[ord_y[i]] = i;
    X = rearrange(X, ord_x);
    Y = rearrange(Y, ord_y);

    using AM = ActedMonoid_MinMincnt_Add<XY>;
    Lazy_SegTree<AM> seg(N - 1, [&](int i) -> pair<XY, XY> {
      return {0, Y[i + 1] - Y[i]};
    });

    ANS_TYPE ANS = 0;
    XY total = Y.back() - Y[0];
    FOR(i, N - 1) {
      int k = ord_x[i] / 2;
      int a = (ord_x[i] & 1 ? -1 : 1);
      seg.apply(rk_y[2 * k], rk_y[2 * k + 1], a);
      auto [min, mincnt] = seg.prod_all();
      ANS_TYPE dy = total - (min == 0 ? mincnt : 0);
      ANS_TYPE dx = X[i + 1] - X[i];
      ANS += dx * dy;
    }
    return ANS;
  }
};
