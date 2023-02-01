template <class ActedMonoid, typename XY>
struct KDTree_ActedMonoid {
  using AM = ActedMonoid;
  using MX = typename AM::Monoid_X;
  using MA = typename AM::Monoid_A;
  using X = typename AM::X;
  using A = typename AM::A;
  static_assert(MX::commute);

  // 小数も考慮すると、閉で持つ設計方針になる。ただし、クエリはいつもの半開を使う
  vc<tuple<XY, XY, XY, XY>> closed_range;
  vc<X> dat;
  vc<A> lazy;
  vc<int> size;
  int n;

  KDTree_ActedMonoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {
    assert(n > 0);
    int log = 0;
    while ((1 << log) < n) ++log;
    dat.resize(1 << (log + 1));
    lazy.assign(1 << log, MA::unit());
    closed_range.resize(1 << (log + 1));
    size.resize(1 << (log + 1));
    build(1, xs, ys, vs);
  }

  void multiply(XY x, XY y, const X& v) { multiply_rec(1, x, y, v); }

  // [xl, xr) x [yl, yr)
  X prod(XY xl, XY xr, XY yl, XY yr) {
    assert(xl <= xr && yl <= yr);
    return prod_rec(1, xl, xr, yl, yr);
  }

  X prod_all() { return dat[1]; }

  // [xl, xr) x [yl, yr)
  void apply(XY xl, XY xr, XY yl, XY yr, A a) {
    assert(xl <= xr && yl <= yr);
    return apply_rec(1, xl, xr, yl, yr, a);
  }

private:
  void build(int idx, vc<XY> xs, vc<XY> ys, vc<X> vs, bool divx = true) {
    int n = len(xs);
    size[idx] = n;
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    xmin = ymin = infty<XY>;
    xmax = ymax = -infty<XY>;

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

  void apply_at(int idx, A a) {
    dat[idx] = AM::act(dat[idx], a, size[idx]);
    if (!is_leaf(idx)) lazy[idx] = MA::op(lazy[idx], a);
  }

  void push(int idx) {
    if (lazy[idx] == MA::unit()) return;
    apply_at(2 * idx + 0, lazy[idx]), apply_at(2 * idx + 1, lazy[idx]);
    lazy[idx] = MA::unit();
  }

  bool multiply_rec(int idx, XY x, XY y, X v) {
    if (!isin(x, y, idx)) return false;
    if (is_leaf(idx)) {
      dat[idx] = MX::op(dat[idx], v);
      size[idx] += 1;
      return true;
    }
    push(idx);
    bool done = 0;
    if (multiply_rec(2 * idx + 0, x, y, v)) done = 1;
    if (!done && multiply_rec(2 * idx + 1, x, y, v)) done = 1;
    if (done) {
      dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);
      size[idx] = size[2 * idx + 0] + size[2 * idx + 1];
    }
    return done;
  }

  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    if (x2 <= xmin || xmax < x1) return MX::unit();
    if (y2 <= ymin || ymax < y1) return MX::unit();
    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }
    push(idx);
    return MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),
                  prod_rec(2 * idx + 1, x1, x2, y1, y2));
  }

  void apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    if (x2 <= xmin || xmax < x1) return;
    if (y2 <= ymin || ymax < y1) return;
    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) {
      return apply_at(idx, a);
    }
    push(idx);
    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);
    apply_rec(2 * idx + 1, x1, x2, y1, y2, a);
    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }
};
