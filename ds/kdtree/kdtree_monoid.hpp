template <class Monoid, typename XY>
struct KDTree_Monoid {
  using MX = Monoid;
  using X = typename MX::value_type;
  static_assert(MX::commute);

  // 小数も考慮すると、閉で持つ設計方針になる。ただし、クエリはいつもの半開を使う
  vc<tuple<XY, XY, XY, XY>> closed_range;
  vc<X> dat;
  int n;

  KDTree_Monoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {
    assert(n > 0);
    int log = 0;
    while ((1 << log) < n) ++log;
    dat.resize(1 << (log + 1));
    closed_range.resize(1 << (log + 1));
    build(1, xs, ys, vs);
  }

  void multiply(XY x, XY y, const X& v) { multiply_rec(1, x, y, v); }

  // [xl, xr) x [yl, yr)
  X prod(XY xl, XY xr, XY yl, XY yr) {
    assert(xl <= xr && yl <= yr);
    return prod_rec(1, xl, xr, yl, yr);
  }

  X prod_all() { return dat[1]; }

private:
  void build(int idx, vc<XY> xs, vc<XY> ys, vc<X> vs, bool divx = true) {
    int n = len(xs);
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    xmin = ymin = INF<XY>;
    xmax = ymax = -INF<XY>;

    FOR(i, n) {
      auto x = xs[i], y = ys[i];
      chmin(xmin, x), chmax(xmax, x), chmin(ymin, y), chmax(ymax, y);
    }
    if (xmin == xmax && ymin == ymax) {
      X x = MX::unit();
      for (auto&& v: vs) x = MX::op(x, v);
      dat[idx] = x;
      return;
    }

    int m = n / 2;
    vc<int> I(n);
    iota(all(I), 0);
    if (divx) {
      nth_element(I.begin(), I.begin() + m, I.end(),
                  [xs](int i, int j) { return xs[i] < xs[j]; });
    } else {
      nth_element(I.begin(), I.begin() + m, I.end(),
                  [ys](int i, int j) { return ys[i] < ys[j]; });
    }
    xs = rearrange(xs, I), ys = rearrange(ys, I), vs = rearrange(vs, I);
    build(2 * idx + 0, {xs.begin(), xs.begin() + m},
          {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin() + m}, !divx);
    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},
          {vs.begin() + m, vs.end()}, !divx);
    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  inline bool is_leaf(int idx) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    return xmin == xmax && ymin == ymax;
  }

  inline bool isin(XY x, XY y, int idx) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);
  }

  bool multiply_rec(int idx, XY x, XY y, X v) {
    if (!isin(x, y, idx)) return false;
    if (is_leaf(idx)) {
      dat[idx] = MX::op(dat[idx], v);
      return true;
    }
    bool done = 0;
    if (multiply_rec(2 * idx + 0, x, y, v)) done = 1;
    if (!done && multiply_rec(2 * idx + 1, x, y, v)) done = 1;
    if (done) { dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]); }
    return done;
  }

  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    if (x2 <= xmin || xmax < x1) return MX::unit();
    if (y2 <= ymin || ymax < y1) return MX::unit();
    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }
    return MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),
                  prod_rec(2 * idx + 1, x1, x2, y1, y2));
  }
};
