#pragma once

template <class Monoid>
struct SegTree {
  using MX = Monoid;
  using X = typename MX::value_type;
  using value_type = X;
  vc<X> dat;
  int n, log, size;

  SegTree() {}
  SegTree(int n) { build(n); }
  template <typename F>
  SegTree(int n, F f) {
    build(n, f);
  }
  SegTree(const vc<X>& v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> X { return MX::unit(); });
  }
  void build(const vc<X>& v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m, log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, MX::unit());
    FOR(i, n) dat[size + i] = f(i);
    FOR_R(i, 1, size) update(i);
  }

  X get(int i) { return dat[size + i]; }
  vc<X> get_all() { return {dat.begin() + size, dat.begin() + size + n}; }

  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }
  void set(int i, const X& x) {
    assert(i < n);
    dat[i += size] = x;
    while (i >>= 1) update(i);
  }

  void multiply(int i, const X& x) {
    assert(i < n);
    i += size;
    dat[i] = Monoid::op(dat[i], x);
    while (i >>= 1) update(i);
  }

  X prod(int L, int R) {
    assert(0 <= L && L <= R && R <= n);
    X vl = Monoid::unit(), vr = Monoid::unit();
    L += size, R += size;
    while (L < R) {
      if (L & 1) vl = Monoid::op(vl, dat[L++]);
      if (R & 1) vr = Monoid::op(dat[--R], vr);
      L >>= 1, R >>= 1;
    }
    return Monoid::op(vl, vr);
  }

  X prod_all() { return dat[1]; }

  template <class F>
  int max_right(F check, int L) {
    assert(0 <= L && L <= n && check(Monoid::unit()));
    if (L == n) return n;
    L += size;
    X sm = Monoid::unit();
    do {
      while (L % 2 == 0) L >>= 1;
      if (!check(Monoid::op(sm, dat[L]))) {
        while (L < size) {
          L = 2 * L;
          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm, dat[L++]); }
        }
        return L - size;
      }
      sm = Monoid::op(sm, dat[L++]);
    } while ((L & -L) != L);
    return n;
  }

  template <class F>
  int min_left(F check, int R) {
    assert(0 <= R && R <= n && check(Monoid::unit()));
    if (R == 0) return 0;
    R += size;
    X sm = Monoid::unit();
    do {
      --R;
      while (R > 1 && (R % 2)) R >>= 1;
      if (!check(Monoid::op(dat[R], sm))) {
        while (R < size) {
          R = 2 * R + 1;
          if (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }
        }
        return R + 1 - size;
      }
      sm = Monoid::op(dat[R], sm);
    } while ((R & -R) != R);
    return 0;
  }

  // prod_{l<=i<r} A[i xor x]
  X xor_prod(int l, int r, int xor_val) {
    static_assert(Monoid::commute);
    X x = Monoid::unit();
    for (int k = 0; k < log + 1; ++k) {
      if (l >= r) break;
      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++) ^ xor_val)]); }
      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r) ^ xor_val)]); }
      l /= 2, r /= 2, xor_val /= 2;
    }
    return x;
  }
};
