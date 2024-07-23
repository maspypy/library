
template <class Monoid>
struct DualSegTree_2D_Dense {
  using MX = Monoid;
  using X = typename MX::value_type;
  using value_type = X;
  static_assert(MX::commute);
  int H, W;
  vc<X> dat;

  DualSegTree_2D_Dense() : DualSegTree_2D_Dense(0, 0) {}
  DualSegTree_2D_Dense(int H, int W) : H(H), W(W), dat(4 * H * W, MX::unit()) {}

  X get(int x, int y) {
    X t = MX::unit();
    int a = x + H;
    while (a) {
      int b = y + W;
      while (b) { t = MX::op(t, dat[idx(a, b)]), b /= 2; }
      a /= 2;
    };
    return t;
  }

  vvc<X> get_all() {
    FOR(x, 1, H) { FOR(y, W) push_x(x, y); }
    FOR(x, 1, H) {
      FOR(y, 2 * W) {
        dat[idx(2 * x + 0, y)] = MX::op(dat[idx(2 * x + 0, y)], dat[idx(x, y)]);
        dat[idx(2 * x + 1, y)] = MX::op(dat[idx(2 * x + 1, y)], dat[idx(x, y)]);
        dat[idx(x, y)] = MX::unit();
      }
    }
    vv(X, res, H, W, MX::unit());
    FOR(x, H) FOR(y, W) { res[x][y] = dat[idx(x + H, y + W)]; }
    return res;
  }

  X apply(int xl, int xr, int yl, int yr, X x) {
    assert(0 <= xl && xl <= xr && xr <= H);
    assert(0 <= yl && yl <= yr && yr <= W);
    X res = MX::unit();
    xl += H, xr += H;
    while (xl < xr) {
      if (xl & 1) apply_x(xl++, yl, yr, x);
      if (xr & 1) apply_x(--xr, yl, yr, x);
      xl >>= 1, xr >>= 1;
    }
    return res;
  }

private:
  inline int idx(int x, int y) { return x * 2 * W + y; }
  void apply_x(int x, int yl, int yr, const X& t) {
    yl += W, yr += W;
    while (yl < yr) {
      if (yl & 1) { dat[idx(x, yl)] = MX::op(dat[idx(x, yl)], t), yl++; }
      if (yr & 1) { --yr, dat[idx(x, yr)] = MX::op(dat[idx(x, yr)], t); }
      yl >>= 1, yr >>= 1;
    }
  }

  void push_x(int x, int k) {
    dat[idx(x, 2 * k + 0)] = MX::op(dat[idx(x, 2 * k + 0)], dat[idx(x, k)]);
    dat[idx(x, 2 * k + 1)] = MX::op(dat[idx(x, 2 * k + 1)], dat[idx(x, k)]);
    dat[idx(x, k)] = MX::unit();
  }
};
