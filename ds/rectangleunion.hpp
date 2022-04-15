#include "ds/lazysegtree.hpp"
#include "alg/lazy_cntminmincnt_add.hpp"

struct RectangleUnion {
  using RECT = tuple<ll, ll, ll, ll>;
  vc<RECT> rectangles;
  vi X, Y;

  void add_rect(ll xl, ll yl, ll xr, ll yr) {
    assert(xl < xr && yl < yr);
    X.eb(xl), X.eb(xr), Y.eb(yl), Y.eb(yr);
    rectangles.eb(xl, xr, yl, yr);
  }

  ll calc() {
    UNIQUE(X), UNIQUE(Y);
    ll N = len(X);
    vc<vc<pi>> add(N), rm(N);
    for (auto &&[xl, xr, yl, yr]: rectangles) {
      xl = LB(X, xl), xr = LB(X, xr);
      yl = LB(Y, yl), yr = LB(Y, yr);
      add[xl].eb(yl, yr);
      rm[xr].eb(yl, yr);
    }

    using Lazy = Lazy_CntMinMincnt_Add<1LL << 60>;

    vc<typename Lazy::X> seg_raw(len(Y) - 1);
    FOR(i, len(Y) - 1) seg_raw[i] = {Y[i + 1] - Y[i], 0, Y[i + 1] - Y[i]};
    LazySegTree<Lazy> seg(seg_raw);
    ll ANS = 0;
    FOR(i, len(X) - 1) {
      ll dx = X[i + 1] - X[i];
      for (auto &&[yl, yr]: add[i]) seg.apply(yl, yr, 1);
      for (auto &&[yl, yr]: rm[i]) seg.apply(yl, yr, -1);
      auto [cnt, min, mincnt] = seg.prod_all();
      ll n = cnt;
      if (min == 0) n -= mincnt;
      ANS += n * dx;
    }
    return ANS;
  }
};
