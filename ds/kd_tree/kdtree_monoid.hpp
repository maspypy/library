// 同じ座標の複数の点がどのくらい集約されるかは保証がない。
// 子ノードが 2x, 2x+1 になるようにして、配列で作ってみる。
template <class Monoid, typename XY = long long>
struct KDTree_Monoid {
  using X = typename Monoid::value_type;
  vc<tuple<XY, XY, XY, XY>> range;
  vc<X> dat;
  int n;

  KDTree_Monoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {
    assert(Monoid::commute);
    int log = 0;
    while ((1 << log) < n) ++log;
    dat.resize(1 << (log + 1));
    range.resize(1 << (log + 1));
    build(1, xs, ys, vs);
  }

  void set(XY x, XY y, const X& v) { set_rec(1, x, y, v); }

  void multiply(XY x, XY y, const X& v) { multiply_rec(1, x, y, v); }

  X prod(XY xl, XY xr, XY yl, XY yr) {
    assert(xl <= xr && yl <= yr);
    return prod_rec(1, xl, xr, yl, yr);
  }

private:
  void build(int idx, vc<XY>& xs, vc<XY>& ys, vc<X>& vs, bool divx = true) {
    int n = len(xs);
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    xmin = numeric_limits<XY>::max();
    xmax = numeric_limits<XY>::lowest();
    ymin = numeric_limits<XY>::max();
    ymax = numeric_limits<XY>::lowest();

    FOR(i, n) {
      auto x = xs[i], y = ys[i];
      chmin(xmin, x);
      chmax(xmax, x);
      chmin(ymin, y);
      chmax(ymax, y);
    }
    if (xmin == xmax && ymin == ymax) {
      X x = Monoid::unit();
      for (auto&& v: vs) x = Monoid::op(x, v);
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
    vc<XY> lxs, rxs, lys, rys;
    vc<X> lvs, rvs;
    FOR(k, m) {
      int i = I[k];
      lxs.eb(xs[i]);
      lys.eb(ys[i]);
      lvs.eb(vs[i]);
    }
    FOR(k, m, n) {
      int i = I[k];
      rxs.eb(xs[i]);
      rys.eb(ys[i]);
      rvs.eb(vs[i]);
    }
    build(2 * idx + 0, lxs, lys, lvs, !divx);
    build(2 * idx + 1, rxs, rys, rvs, !divx);
    dat[idx] = Monoid::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  bool isin(const int& idx, const XY& x, const XY& y) {
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);
  }

  void set_rec(const int& idx, const XY& x, const XY& y, const X& v) {
    if (!isin(idx, x, y)) return;
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    if (xmin == xmax && ymin == ymax) {
      dat[idx] = v;
      return;
    }
    set_rec(2 * idx + 0, x, y, v);
    set_rec(2 * idx + 1, x, y, v);
    dat[idx] = Monoid::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  void multiply_rec(const int& idx, const XY& x, const XY& y, const X& v) {
    if (!isin(idx, x, y)) return;
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    if (xmin == xmax && ymin == ymax) {
      dat[idx] = Monoid::op(dat[idx], v);
      return;
    }
    multiply_rec(2 * idx + 0, x, y, v);
    multiply_rec(2 * idx + 1, x, y, v);
    dat[idx] = Monoid::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  X prod_rec(const int& idx, const XY& x1, const XY& x2, const XY& y1,
             const XY& y2) {
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    if (x2 <= xmin || xmax < x1) return Monoid::unit();
    if (y2 <= ymin || ymax < y1) return Monoid::unit();
    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }
    return Monoid::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),
                      prod_rec(2 * idx + 1, x1, x2, y1, y2));
  }
};