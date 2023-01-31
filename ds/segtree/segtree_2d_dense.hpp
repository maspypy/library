#pragma once

template <class Monoid>
struct SegTree_2D_Dense {
  using MX = Monoid;
  using X = typename MX::value_type;
  using value_type = X;
  static_assert(MX::commute);
  int H, W;
  vc<X> dat;

  SegTree_2D_Dense() : SegTree_2D_Dense(0, 0) {}
  SegTree_2D_Dense(int H, int W) : H(H), W(W), dat(4 * H * W, MX::unit()) {}
  SegTree_2D_Dense(vc<vc<X>> &v) {
    H = len(v), W = (H == 0 ? 0 : len(v[0]));
    dat.assign(4 * H * W, MX::unit());
    FOR(x, H) FOR(y, W) { dat[idx(H + x, W + y)] = v[x][y]; }
    FOR(y, W, W + W) FOR_R(x, H) {
      dat[idx(x, y)] = MX::op(dat[idx(2 * x + 0, y)], dat[idx(2 * x + 1, y)]);
    }
    FOR(x, H + H) FOR_R(y, W) {
      dat[idx(x, y)] = MX::op(dat[idx(x, 2 * y + 0)], dat[idx(x, 2 * y + 1)]);
    }
  }

  void set(int x, int y, X e) {
    x += H, y += W;
    dat[idx(x, y)] = e;
    int i = x;
    while (i >>= 1) {
      dat[idx(i, y)] = MX::op(dat[idx(2 * i + 0, y)], dat[idx(2 * i + 1, y)]);
    }
    i = x;
    while (i) {
      int j = y;
      while (j >>= 1) {
        dat[idx(i, j)] = MX::op(dat[idx(i, 2 * j + 0)], dat[idx(i, 2 * j + 1)]);
      }
      i >>= 1;
    }
  }

  X prod(int xl, int xr, int yl, int yr) {
    assert(0 <= xl && xl <= xr && xr <= H);
    assert(0 <= yl && yl <= yr && yr <= W);
    X res = MX::unit();
    xl += H, xr += H;
    while (xl < xr) {
      if (xl & 1) res = MX::op(res, prod_x(xl++, yl, yr));
      if (xr & 1) res = MX::op(res, prod_x(--xr, yl, yr));
      xl >>= 1, xr >>= 1;
    }
    return res;
  }

private:
  inline int idx(int x, int y) { return x * 2 * W + y; }
  X prod_x(int x, int yl, int yr) {
    X res = MX::unit();
    yl += W, yr += W;
    while (yl < yr) {
      if (yl & 1) res = MX::op(res, dat[idx(x, yl++)]);
      if (yr & 1) res = MX::op(res, dat[idx(x, --yr)]);
      yl >>= 1, yr >>= 1;
    }
    return res;
  }
};