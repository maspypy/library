#pragma once

template <typename ActedMonoid>
struct LazySegTree {
  using Monoid_X = typename ActedMonoid::Monoid_X;
  using Monoid_A = typename ActedMonoid::Monoid_A;
  static_assert(Monoid_X::commute);
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  int n, log, size;
  vc<X> dat;
  vc<A> laz;

  LazySegTree() {}
  LazySegTree(int n) { build(n); }
  template <typename F>
  LazySegTree(int n, F f) {
    build(n, f);
  }
  LazySegTree(vc<X> v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> X { return Monoid_X::unit(); });
  }
  void build(vc<X> v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m, log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, Monoid_X::unit());
    laz.assign(size, Monoid_A::unit());
    FOR(i, n) dat[size + i] = f(i);
    FOR_R(i, 1, size) update(i);
  }

  void update(int k) { dat[k] = Monoid_X::op(dat[2 * k], dat[2 * k + 1]); }
  void apply_at(int k, A a) {
    int sz = 1 << (log - topbit(k));
    dat[k] = ActedMonoid::act(dat[k], a, sz);
    if (k < size) laz[k] = Monoid_A::op(laz[k], a);
  }
  void push(int k) {
    apply_at(2 * k, laz[k]);
    apply_at(2 * k + 1, laz[k]);
    laz[k] = Monoid_A::unit();
  }
  void set(int p, X x) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    dat[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  X get(int p) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return dat[p];
  }

  vc<X> get_all() {
    for (int i = log; i >= 1; i--) {
      FOR(k, size >> i, (size + size) >> i) { push(k); }
    }
    return {dat.begin() + size, dat.begin() + size + n};
  }

  X prod(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return Monoid_X::unit();

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    X x = Monoid_X::unit();
    while (l < r) {
      if (l & 1) x = Monoid_X::op(x, dat[l++]);
      if (r & 1) x = Monoid_X::op(x, dat[--r]);
      l >>= 1;
      r >>= 1;
    }

    return x;
  }

  X prod_all() { return dat[1]; }

  void apply(int l, int r, A a) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return;

    l += size;
    r += size;

    if (!Monoid_A::commute) {
      for (int i = log; i >= 1; i--) {
        if (((l >> i) << i) != l) push(l >> i);
        if (((r >> i) << i) != r) push((r - 1) >> i);
      }
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) apply_at(l++, a);
        if (r & 1) apply_at(--r, a);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template <typename F>
  int max_right(const F& check, int l) {
    assert(0 <= l && l <= n);
    assert(check(Monoid_X::unit()));
    if (l == n) return n;
    l += size;
    for (int i = log; i >= 1; i--) push(l >> i);
    X sm = Monoid_X::unit();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!check(Monoid_X::op(sm, dat[l]))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (check(Monoid_X::op(sm, dat[l]))) {
            sm = Monoid_X::op(sm, dat[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = Monoid_X::op(sm, dat[l]);
      l++;
    } while ((l & -l) != l);
    return n;
  }

  template <typename F>
  int min_left(const F& check, int r) {
    assert(0 <= r && r <= n);
    assert(check(Monoid_X::unit()));
    if (r == 0) return 0;
    r += size;
    for (int i = log; i >= 1; i--) push((r - 1) >> i);
    X sm = Monoid_X::unit();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!check(Monoid_X::op(dat[r], sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (check(Monoid_X::op(dat[r], sm))) {
            sm = Monoid_X::op(dat[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = Monoid_X::op(dat[r], sm);
    } while ((r & -r) != r);
    return 0;
  }
};
