#pragma once
template <class Monoid>
struct SegTree {
  using X = typename Monoid::value_type;
  using value_type = X;
  vc<X> dat;
  int n, log, size;

  SegTree() : SegTree(0) {}
  SegTree(int n) : SegTree(vc<X>(n, Monoid::unit())) {}
  SegTree(vc<X> v) : n(len(v)) {
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, Monoid::unit());
    FOR(i, n) dat[size + i] = v[i];
    FOR3_R(i, 1, size) update(i);
  }

  X operator[](int i) { return dat[size + i]; }

  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }

  void set(int i, X x) {
    assert(i < n);
    dat[i += size] = x;
    while (i >>= 1) update(i);
  }

  X prod(int L, int R) {
    assert(L <= R);
    assert(R <= n);
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
  int max_right(F &check, int L) {
    assert(0 <= L && L <= n && check(Monoid::unit()));
    if (L == n) return n;
    L += size;
    X sm = Monoid::unit();
    do {
      while (L % 2 == 0) L >>= 1;
      if (!check(Monoid::op(sm, dat[L]))) {
        while (L < size) {
          L = 2 * L;
          if (check(Monoid::op(sm, dat[L]))) {
            sm = Monoid::op(sm, dat[L]);
            L++;
          }
        }
        return L - size;
      }
      sm = Monoid::op(sm, dat[L]);
      L++;
    } while ((L & -L) != L);
    return n;
  }

  template <class F>
  int min_left(F &check, int R) {
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
          if (check(Monoid::op(dat[R], sm))) {
            sm = Monoid::op(dat[R], sm);
            R--;
          }
        }
        return R + 1 - size;
      }
      sm = Monoid::op(dat[R], sm);
    } while ((R & -R) != R);
    return 0;
  }

  void debug() { print("segtree", dat); }
};