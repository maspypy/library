#pragma once

// https://codeforces.com/contest/1301/problem/E
template <class Monoid>
struct SegTree2D_dense {
  using X = typename Monoid::value_type;
  using value_type = X;
  vc<X> dat;
  int H, W;

  int get_idx(int x, int y) { return x * 2 * W + y; }

  SegTree2D_dense() : SegTree2D_dense(0, 0) {}
  SegTree2D_dense(int H, int W) : H(H), W(W), dat(4 * H * W, Monoid::unit()) {}
  SegTree2D_dense(vc<vc<X>> &v) {
    H = len(v);
    W = (H == 0 ? 0 : len(v[0]));
    dat.assign(4 * H * W, Monoid::unit());
    FOR(x, H) FOR(y, W) { dat[get_idx(H + x, W + y)] = v[x][y]; }
    FOR3(y, W, W + W) FOR_R(x, H) {
      dat[get_idx(x, y)]
          = Monoid::op(dat[get_idx(2 * x + 0, y)], dat[get_idx(2 * x + 1, y)]);
    }
    FOR(x, H + H) {
      FOR_R(y, W) {
        dat[get_idx(x, y)] = Monoid::op(dat[get_idx(x, 2 * y + 0)],
                                        dat[get_idx(x, 2 * y + 1)]);
      }
    }
  }

  void set(int x, int y, X e) {
    x += H, y += W;
    dat[get_idx(x, y)] = e;
    int i = x;
    while (i >>= 1) {
      dat[get_idx(i, y)]
          = Monoid::op(dat[get_idx(2 * i + 0, y)], dat[get_idx(2 * i + 1, y)]);
    }
    i = x;
    while (i) {
      int j = y;
      while (j >>= 1) {
        dat[get_idx(i, j)] = Monoid::op(dat[get_idx(i, 2 * j + 0)],
                                        dat[get_idx(i, 2 * j + 1)]);
      }
      i >>= 1;
    }
  }

  X prod_at(int x, int yl, int yr) {
    X res = Monoid::unit();
    yl += W, yr += W;
    while (yl < yr) {
      if (yl & 1) res = Monoid::op(res, dat[get_idx(x, yl++)]);
      if (yr & 1) res = Monoid::op(res, dat[get_idx(x, --yr)]);
      yl >>= 1, yr >>= 1;
    }
    return res;
  }

  X prod(int xl, int xr, int yl, int yr) {
    assert(0 <= xl && xl <= xr && xr <= H);
    assert(0 <= yl && yl <= yr && yr <= W);
    X res = Monoid::unit();
    xl += H, xr += H;
    while (xl < xr) {
      if (xl & 1) res = Monoid::op(res, prod_at(xl++, yl, yr));
      if (xr & 1) res = Monoid::op(res, prod_at(--xr, yl, yr));
      xl >>= 1, xr >>= 1;
    }
    return res;
  }

  void debug() { print("segtree", dat); }
};