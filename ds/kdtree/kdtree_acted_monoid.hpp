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
  vc<int> pos; // raw data -> index
  int n, log;

  KDTree_ActedMonoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {
    assert(n > 0);
    log = 0;
    while ((1 << log) < n) ++log;
    dat.resize(1 << (log + 1));
    lazy.assign(1 << log, MA::unit());
    closed_range.assign(1 << (log + 1), {infty<XY>, -infty<XY>, infty<XY>, -infty<XY>});
    size.resize(1 << (log + 1));
    vc<int> ids(n);
    pos.resize(n);
    FOR(i, n) ids[i] = i;
    build(1, xs, ys, vs, ids);
  }

  void set(int i, const X& v) {
    i = pos[i];
    for (int k = log; k >= 1; k--) { push(i >> k); }
    dat[i] = v;
    while (i > 1) i /= 2, dat[i] = MX::op(dat[2 * i], dat[2 * i + 1]);
  }
  void multiply(int i, const X& v) {
    i = pos[i];
    for (int k = log; k >= 1; k--) { push(i >> k); }
    dat[i] = MX::op(dat[i], v);
    while (i > 1) i /= 2, dat[i] = MX::op(dat[2 * i], dat[2 * i + 1]);
  }

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
  void build(int idx, vc<XY> xs, vc<XY> ys, vc<X> vs, vc<int> ids, bool divx = true) {
    int n = len(xs);
    size[idx] = n;
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    xmin = ymin = infty<XY>;
    xmax = ymax = -infty<XY>;

    FOR(i, n) {
      auto x = xs[i], y = ys[i];
      chmin(xmin, x), chmax(xmax, x), chmin(ymin, y), chmax(ymax, y);
    }
    if (n == 1) {
      dat[idx] = vs[0];
      pos[ids[0]] = idx;
      return;
    }

    int m = n / 2;
    vc<int> I(n);
    iota(all(I), 0);
    if (divx) {
      nth_element(I.begin(), I.begin() + m, I.end(), [xs](int i, int j) { return xs[i] < xs[j]; });
    } else {
      nth_element(I.begin(), I.begin() + m, I.end(), [ys](int i, int j) { return ys[i] < ys[j]; });
    }
    xs = rearrange(xs, I), ys = rearrange(ys, I), vs = rearrange(vs, I), ids = rearrange(ids, I);
    build(2 * idx + 0, {xs.begin(), xs.begin() + m}, {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin() + m}, {ids.begin(), ids.begin() + m}, !divx);
    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()}, {vs.begin() + m, vs.end()}, {ids.begin() + m, ids.end()}, !divx);
    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }

  inline bool isin(XY x, XY y, int idx) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);
  }

  void apply_at(int idx, A a) {
    dat[idx] = AM::act(dat[idx], a, size[idx]);
    if (idx < (1 << log)) lazy[idx] = MA::op(lazy[idx], a);
  }

  void push(int idx) {
    if (lazy[idx] == MA::unit()) return;
    apply_at(2 * idx + 0, lazy[idx]), apply_at(2 * idx + 1, lazy[idx]);
    lazy[idx] = MA::unit();
  }

  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {
    if (idx >= len(closed_range)) return MX::unit();
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    if (xmin > xmax) return MX::unit();
    if (x2 <= xmin || xmax < x1) return MX::unit();
    if (y2 <= ymin || ymax < y1) return MX::unit();
    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }
    push(idx);
    return MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2), prod_rec(2 * idx + 1, x1, x2, y1, y2));
  }

  void apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a) {
    if (idx >= len(closed_range)) return;
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    if (xmin > xmax) return;
    if (x2 <= xmin || xmax < x1) return;
    if (y2 <= ymin || ymax < y1) return;
    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return apply_at(idx, a); }
    push(idx);
    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);
    apply_rec(2 * idx + 1, x1, x2, y1, y2, a);
    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);
  }
};
