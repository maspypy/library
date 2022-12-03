#pragma once

template <typename Monoid>
struct DualSegTree {
  using A = typename Monoid::value_type;
  int n, log, size;
  vc<A> laz;

  DualSegTree() : DualSegTree(0) {}
  DualSegTree(int n) { resize(n); }

  void reset() { fill(all(laz), Monoid::unit()); }
  void resize(int n_) {
    n = n_;
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    laz.assign(size << 1, Monoid::unit());
  }

  void all_apply(int k, A a) { laz[k] = Monoid::op(laz[k], a); }

  A get(int p) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return laz[p];
  }

  vc<A> get_all() {
    FOR(i, size) push(i);
    return {laz.begin() + size, laz.begin() + size + n};
  }

  void apply(int l, int r, A a) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return;

    l += size;
    r += size;

    if (!Monoid::commute) {
      for (int i = log; i >= 1; i--) {
        if (((l >> i) << i) != l) push(l >> i);
        if (((r >> i) << i) != r) push((r - 1) >> i);
      }
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) all_apply(l++, a);
        if (r & 1) all_apply(--r, a);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }
  }
  void debug() { print("dualsegtree getall:", get_all()); }

private:
  void push(int k) {
    all_apply(2 * k, laz[k]);
    all_apply(2 * k + 1, laz[k]);
    laz[k] = Monoid::unit();
  }
};
