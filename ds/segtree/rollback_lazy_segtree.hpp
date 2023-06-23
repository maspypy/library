#include "ds/rollback_array.hpp"
// verify? https://qoj.ac/submission/114657
template <typename ActedMonoid>
struct Rollback_Lazy_SegTree {
  using AM = ActedMonoid;
  using MX = typename AM::Monoid_X;
  using MA = typename AM::Monoid_A;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  int n, log, size;
  Rollback_Array<X> dat;
  Rollback_Array<A> laz;

  Rollback_Lazy_SegTree() {}
  Rollback_Lazy_SegTree(int n) { build(n); }
  template <typename F>
  Rollback_Lazy_SegTree(int n, F f) {
    build(n, f);
  }
  Rollback_Lazy_SegTree(const vc<X>& v) { build(v); }

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
    dat = Rollback_Array<X>(vc<X>(size << 1, MX::unit()));
    laz = Rollback_Array<A>(vc<A>(size, MA::unit()));
    FOR(i, n) dat.set(size + i, f(i));
    FOR_R(i, 1, size) update(i);
  }

  void update(int k) { dat.set(k, MX::op(dat.get(2 * k), dat.get(2 * k + 1))); }
  void set(int p, X x) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    dat.set(p, x);
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  void multiply(int p, const X& x) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    dat.set(p, MX::op(dat.get(p), x));
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  X get(int p) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return dat.get(p);
  }

  vc<X> get_all() {
    auto tmp = dat.get_all();
    FOR(k, 1, size) push(k);
    return {tmp.begin() + size, tmp.begin() + size + n};
  }

  X prod(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return MX::unit();
    l += size, r += size;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    X xl = MX::unit(), xr = MX::unit();
    while (l < r) {
      if (l & 1) xl = MX::op(xl, dat.get(l++));
      if (r & 1) xr = MX::op(dat.get(--r), xr);
      l >>= 1, r >>= 1;
    }
    return MX::op(xl, xr);
  }

  X prod_all() { return dat.get(1); }

  void apply(int l, int r, A a) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return;
    l += size, r += size;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    int l2 = l, r2 = r;
    while (l < r) {
      if (l & 1) apply_at(l++, a);
      if (r & 1) apply_at(--r, a);
      l >>= 1, r >>= 1;
    }
    l = l2, r = r2;
    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template <typename F>
  int max_right(const F check, int l) {
    assert(0 <= l && l <= n);
    assert(check(MX::unit()));
    if (l == n) return n;
    l += size;
    for (int i = log; i >= 1; i--) push(l >> i);
    X sm = MX::unit();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!check(MX::op(sm, dat.get(l)))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (check(MX::op(sm, dat.get(l)))) { sm = MX::op(sm, dat.get(l++)); }
        }
        return l - size;
      }
      sm = MX::op(sm, dat.get(l++));
    } while ((l & -l) != l);
    return n;
  }

  template <typename F>
  int min_left(const F check, int r) {
    assert(0 <= r && r <= n);
    assert(check(MX::unit()));
    if (r == 0) return 0;
    r += size;
    for (int i = log; i >= 1; i--) push((r - 1) >> i);
    X sm = MX::unit();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!check(MX::op(dat.get(r), sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (check(MX::op(dat.get(r), sm))) { sm = MX::op(dat.get(r--), sm); }
        }
        return r + 1 - size;
      }
      sm = MX::op(dat.get(r), sm);
    } while ((r & -r) != r);
    return 0;
  }

  pair<int, int> time() { return {dat.time(), laz.time()}; }
  void rollback(pair<int, int> t) { dat.rollback(t.fi), laz.rollback(t.se); }

  void push(int k) {
    if (laz.get(k) == MA::unit()) return;
    apply_at(2 * k, laz.get(k)), apply_at(2 * k + 1, laz.get(k));
    laz.set(k, MA::unit());
  }

private:
  void apply_at(int k, A a) {
    ll sz = 1 << (log - topbit(k));
    dat.set(k, AM::act(dat.get(k), a, sz));
    if (k < size) laz.set(k, MA::op(laz.get(k), a));
  }
};