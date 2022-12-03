// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_g
template <class Lazy, typename XY>
struct KDTree_Lazy {
  using Monoid_X = typename Lazy::X_structure;
  using Monoid_A = typename Lazy::A_structure;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  vc<tuple<XY, XY, XY, XY>> range;
  vc<X> dat;
  vc<A> lazy;
  int n;

  KDTree_Lazy(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {
    assert(Monoid_X::commute);
    int log = 0;
    while ((1 << log) < n) ++log;
    dat.resize(1 << (log + 1));
    lazy.resize(1 << (log + 1));
    range.resize(1 << (log + 1));
    build(1, xs, ys, vs);
  }

  void set(XY x, XY y, const X& v) { set_rec(1, x, y, v); }

  void multiply(XY x, XY y, const X& v) { multiply_rec(1, x, y, v); }

  X prod(XY xl, XY xr, XY yl, XY yr) {
    assert(xl <= xr && yl <= yr);
    return prod_rec(1, xl, xr, yl, yr);
  }

  X prod_all() {
    auto& [xmin, xmax, ymin, ymax] = range[1];
    return prod(xmin, ymin, xmax + 1, ymax + 1);
  }

  void apply(XY xl, XY xr, XY yl, XY yr, A a) {
    assert(xl <= xr && yl <= yr);
    return apply_rec(1, xl, xr, yl, yr, a);
  }

  vc<tuple<XY, XY, X>> get_all() {
    vc<tuple<XY, XY, X>> res;
    auto dfs = [&](auto& dfs, int idx) -> void {
      auto& [xmin, xmax, ymin, ymax] = range[idx];
      if (xmin == xmax && ymin == ymax) {
        res.eb(xmin, ymin, dat[idx]);
        return;
      }
      push(idx);
      dfs(dfs, 2 * idx + 0);
      dfs(dfs, 2 * idx + 1);
    };
    dfs(dfs, 1);
    return res;
  }

private:
  void build(int idx, vc<XY>& xs, vc<XY>& ys, vc<X> vs, bool divx = true) {
    lazy[idx] = Monoid_A::unit();
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
      X x = Monoid_X::unit();
      for (auto&& v: vs) x = Monoid_X::op(x, v);
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
    dat[idx] = Monoid_X::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  void push(const int& idx) {
    A& a = lazy[idx];
    if (a == Monoid_A::unit()) return;
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    if (xmin != xmax || ymin != ymax) {
      dat[2 * idx + 0] = Lazy::act(dat[2 * idx + 0], a);
      lazy[2 * idx + 0] = Monoid_A::op(lazy[2 * idx + 0], a);
      dat[2 * idx + 1] = Lazy::act(dat[2 * idx + 1], a);
      lazy[2 * idx + 1] = Monoid_A::op(lazy[2 * idx + 1], a);
    }
    a = Monoid_A::unit();
  }

  bool isin(const int& idx, const XY& x, const XY& y) {
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);
  }

  void set_rec(const int& idx, const XY& x, const XY& y, const X& v) {
    if (!isin(idx, x, y)) { return; }
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    if (xmin == xmax && ymin == ymax) {
      dat[idx] = v;
      return;
    }
    push(idx);
    set_rec(2 * idx + 0, x, y, v);
    set_rec(2 * idx + 1, x, y, v);
    dat[idx] = Monoid_X::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  void multiply_rec(const int& idx, const XY& x, const XY& y, const X& v) {
    if (!isin(idx, x, y)) return;
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    if (xmin == xmax && ymin == ymax) {
      dat[idx] = Monoid_X::op(dat[idx], v);
      lazy[idx] = Monoid_A::unit();
      return;
    }
    push(idx);
    multiply_rec(2 * idx + 0, x, y, v);
    multiply_rec(2 * idx + 1, x, y, v);
    dat[idx] = Monoid_X::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  X prod_rec(const int& idx, const XY& x1, const XY& x2, const XY& y1,
             const XY& y2) {
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    if (x2 <= xmin || xmax < x1) return Monoid_X::unit();
    if (y2 <= ymin || ymax < y1) return Monoid_X::unit();
    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }
    push(idx);
    return Monoid_X::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),
                        prod_rec(2 * idx + 1, x1, x2, y1, y2));
  }

  void apply_rec(const int& idx, const XY& x1, const XY& x2, const XY& y1,
                 const XY& y2, const A& a) {
    auto& [xmin, xmax, ymin, ymax] = range[idx];
    if (x2 <= xmin || xmax < x1) return;
    if (y2 <= ymin || ymax < y1) return;
    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) {
      dat[idx] = Lazy::act(dat[idx], a);
      lazy[idx] = Monoid_A::op(lazy[idx], a);
      return;
    }
    push(idx);
    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);
    apply_rec(2 * idx + 1, x1, x2, y1, y2, a);
    dat[idx] = Monoid_X::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }
};
