template <class Lazy>
struct kDTree {
  using Monoid_X = typename Lazy::X_structure;
  using Monoid_A = typename Lazy::A_structure;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  kDTree *l = nullptr, *r = nullptr;
  ll xmin = LLONG_MAX, xmax = LLONG_MIN, ymin = LLONG_MAX, ymax = LLONG_MIN;
  X dat;
  A lazy;
  kDTree(vi xs, vi ys, vc<X> vs, bool divx = true) {
    dat = Monoid_X::unit;
    lazy = Monoid_A::unit;
    const int n = len(xs);
    FOR(i, n) {
      auto x = xs[i], y = ys[i];
      chmin(xmin, x);
      chmax(xmax, x);
      chmin(ymin, y);
      chmax(ymax, y);
      dat = Monoid_X::op(dat, vs[i]);
    }
    if (n <= 1) return;
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
    vi lxs, rxs, lys, rys;
    vc<X> lvs, rvs;
    FOR(k, n) {
      int i = I[k];
      if (k < m) {
        lxs.eb(xs[i]);
        lys.eb(ys[i]);
        lvs.eb(vs[i]);
      } else {
        rxs.eb(xs[i]);
        rys.eb(ys[i]);
        rvs.eb(vs[i]);
      }
    }
    l = new kDTree(lxs, lys, lvs, !divx);
    r = new kDTree(rxs, rys, rvs, !divx);
  }

  void prop() {
    if (lazy == Monoid_A::unit) return;
    l->lazy = Monoid_A::op(l->lazy, lazy);
    r->lazy = Monoid_A::op(r->lazy, lazy);
    dat = Lazy::act(dat, lazy);
    lazy = Monoid_A::unit;
  }

  void apply_cl(ll x1, ll x2, ll y1, ll y2, A& a) {
    if (x2 < xmin || xmax < x1 || y2 < ymin || ymax < y1) return;
    if (x1 <= xmin && xmax <= x2 && y1 <= ymin && ymax <= y2) {
      lazy = Monoid_A::op(lazy, a);
      return;
    }
    prop();
    l->apply_cl(x1, x2, y1, y2, a);
    r->apply_cl(x1, x2, y1, y2, a);
    X vl = Lazy::act(l->dat, l->lazy);
    X vr = Lazy::act(r->dat, r->lazy);
    dat = Monoid_X::op(vl, vr);
  }

  X prod_cl(ll x1, ll x2, ll y1, ll y2) {
    if (x2 < xmin || xmax < x1 || y2 < ymin || ymax < y1) return Monoid_X::unit;
    if (x1 <= xmin && xmax <= x2 && y1 <= ymin && ymax <= y2) {
      return Lazy::act(dat, lazy);
    }
    prop();
    return Monoid_X::op(l->prod_cl(x1, x2, y1, y2), r->prod_cl(x1, x2, y1, y2));
  }

  void apply(ll xl, ll yl, ll xr, ll yr, A& a) {
    apply_cl(xl, xr - 1, yl, yr - 1, a);
  }

  X prod(ll xl, ll yl, ll xr, ll yr) { return prod_cl(xl, xr - 1, yl, yr - 1); }
};
