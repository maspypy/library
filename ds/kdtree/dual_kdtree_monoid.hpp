// 矩形作用と点取得
template <class Monoid, typename XY>
struct Dual_KDTree_Monoid {
  using MA = Monoid;
  using A = typename Monoid::value_type;

  // 小数も考慮すると、閉で持つ設計方針になる。ただし、クエリはいつもの半開を使う
  vc<tuple<XY, XY, XY, XY>> closed_range;
  vc<A> lazy;
  vc<int> size;
  vc<int> where;
  int n, log;

  Dual_KDTree_Monoid(vc<XY> xs, vc<XY> ys) : n(len(xs)) {
    assert(n > 0);
    log = 0;
    while ((1 << log) < n) ++log;
    lazy.resize(1 << (log + 1), MA::unit());
    closed_range.resize(1 << (log + 1));
    size.resize(1 << (log + 1));
    where.resize(n);
    vc<int> I(n);
    iota(all(I), 0);
    build(1, xs, ys, I);
  }

  // [xl, xr) x [yl, yr)
  void apply(XY xl, XY xr, XY yl, XY yr, A a) {
    assert(xl <= xr && yl <= yr);
    return apply_rec(1, xl, xr, yl, yr, a);
  }

  // コンストラクタで渡したインデックス
  A get(int i) {
    i = where[i];
    FOR_R(k, 1, log + 1) { push(i >> k); }
    return lazy[i];
  }

private:
  void build(int idx, vc<XY> xs, vc<XY> ys, vc<int> raw_idx, bool divx = true) {
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
      assert(len(raw_idx) == 1);
      where[raw_idx[0]] = idx;
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
    xs = rearrange(xs, I), ys = rearrange(ys, I),
    raw_idx = rearrange(raw_idx, I);
    build(2 * idx + 0, {xs.begin(), xs.begin() + m},
          {ys.begin(), ys.begin() + m}, {raw_idx.begin(), raw_idx.begin() + m},
          !divx);
    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},
          {raw_idx.begin() + m, raw_idx.end()}, !divx);
  }

  inline bool is_leaf(int idx) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    return xmin == xmax && ymin == ymax;
  }

  inline bool isin(XY x, XY y, int idx) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);
  }

  void apply_at(int idx, A a) { lazy[idx] = MA::op(lazy[idx], a); }

  void push(int idx) {
    if (lazy[idx] == MA::unit()) return;
    apply_at(2 * idx + 0, lazy[idx]), apply_at(2 * idx + 1, lazy[idx]);
    lazy[idx] = MA::unit();
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
  }
};