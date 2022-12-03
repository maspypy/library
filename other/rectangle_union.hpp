#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/minmincnt_add.hpp"

template <typename XY = int>
struct Rectangle_Union {
  using RECT = tuple<XY, XY, XY, XY>;
  vc<RECT> rectangles;
  vc<XY> X, Y;

  void add_rect(int xl, int xr, int yl, int yr) {
    assert(xl < xr && yl < yr);
    X.eb(xl), X.eb(xr), Y.eb(yl), Y.eb(yr);
    rectangles.eb(xl, xr, yl, yr);
  }

  template <typename ANS_TYPE = ll>
  ANS_TYPE calc() {
    UNIQUE(X), UNIQUE(Y);
    int N = len(X);
    vc<vc<pair<int, int>>> add(N), rm(N);
    for (auto &&[xl, xr, yl, yr]: rectangles) {
      xl = LB(X, xl), xr = LB(X, xr);
      yl = LB(Y, yl), yr = LB(Y, yr);
      add[xl].eb(yl, yr);
      rm[xr].eb(yl, yr);
    }

    using AM = ActedMonoid_MinMincnt_Add<XY>;
    using T = typename AM::Monoid_X::value_type;
    Lazy_SegTree<AM> seg(len(Y) - 1, [&](int i) -> T {
      return {Y[i + 1] - Y[i], 0, Y[i + 1] - Y[i]};
    });
    ANS_TYPE ANS = 0;
    FOR(i, len(X) - 1) {
      ANS_TYPE dx = X[i + 1] - X[i];
      for (auto &&[yl, yr]: add[i]) seg.apply(yl, yr, 1);
      for (auto &&[yl, yr]: rm[i]) seg.apply(yl, yr, -1);
      auto [min, mincnt] = seg.prod_all();
      ANS_TYPE n = Y.back() - Y[0];
      if (min == 0) n -= mincnt;
      ANS += n * dx;
    }
    return ANS;
  }
};
