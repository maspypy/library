template <class Monoid, typename XY>
struct KDTree_Monoid {
  using MX = Monoid;
  using X = typename MX::value_type;
  static_assert(MX::commute);
  vc<tuple<XY, XY, XY, XY>> closed_range;
  vc<X> dat;
  int n;

  KDTree_Monoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {
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
  void build(int idx, vc<XY>& xs, vc<XY>& ys, vc<X>& vs, bool divx = true) {
    int n = len(xs);
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    xmin = ymin = numeric_limits<XY>::max();
    xmax = ymax = numeric_limits<XY>::lowest();

    FOR(i, n) {
      XY x = xs[i], y = ys[i];
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
                  [&xs](int i, int j) { return xs[i] < xs[j]; });
    } else {
      nth_element(I.begin(), I.begin() + m, I.end(),
                  [&ys](int i, int j) { return ys[i] < ys[j]; });
    }
    vc<XY> lxs, rxs, lys, rys;
    vc<X> lvs, rvs;
    FOR(k, m) { lxs.eb(xs[I[k]]), lys.eb(ys[I[k]]), lvs.eb(vs[I[k]]); }
    FOR(k, m, n) { rxs.eb(xs[I[k]]), rys.eb(ys[I[k]]), rvs.eb(vs[I[k]]); }
    build(2 * idx + 0, lxs, lys, lvs, !divx);
    build(2 * idx + 1, rxs, rys, rvs, !divx);
    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  bool isin(const int& idx, const XY& x, const XY& y) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);
  }

  void multiply_rec(const int& idx, const XY& x, const XY& y, const X& v) {
    if (!isin(idx, x, y)) return;
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    if (xmin == xmax && ymin == ymax) {
      dat[idx] = MX::op(dat[idx], v);
      return;
    }
    multiply_rec(2 * idx + 0, x, y, v);
    multiply_rec(2 * idx + 1, x, y, v);
    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    if (x2 <= xmin || xmax < x1) return MX::unit();
    if (y2 <= ymin || ymax < y1) return MX::unit();
    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) return dat[idx];
    return MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),
                  prod_rec(2 * idx + 1, x1, x2, y1, y2));
  }
};