#include "ds/segtree/segtree.hpp"
#include "alg/monoid_pow.hpp"
#include "ds/fastset.hpp"

template <typename Monoid>
struct Range_Assignment_SegTree {
  using MX = Monoid;
  using X = typename MX::value_type;
  int n;
  SegTree<MX> seg;
  FastSet cut;
  vc<X> dat;

  Range_Assignment_SegTree() {}
  Range_Assignment_SegTree(int n) { build(n); }
  template <typename F>
  Range_Assignment_SegTree(int n, F f) {
    build(n, f);
  }
  Range_Assignment_SegTree(const vc<X> &v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> X { return MX::id(); });
  }
  void build(const vc<X> &v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m;
    cut.build(n);
    cut.fill_one();
    dat.resize(m);
    seg.build(m, [&](int i) { return dat[i] = f(i); });
  }

  X prod(int l, int r) {
    int a = cut.prev(l), c = cut.prev(r);
    if (a == c) {
      return monoid_pow<MX>(dat[a], r - l);
    };
    int b = cut.next(l);
    assert(b <= c);
    X x = monoid_pow<MX>(dat[a], b - l);
    X y = seg.prod(b, c);
    X z = monoid_pow<MX>(dat[c], r - c);
    return MX::op(MX::op(x, y), z);
  }

  X prod_all() { return seg.prod_all(); }

  void assign(int l, int r, X x) {
    if (l == r) return;

    int a = cut.prev(l);
    int b = cut.next(r);

    bool has_left = (a < l);
    bool has_right = (r < b);

    X left, right;
    if (has_left) {
      left = monoid_pow<MX>(dat[a], l - a);
    }

    if (has_right) {
      X y = dat[cut.prev(r)];
      dat[r] = y;
      right = monoid_pow<MX>(y, b - r);
    }

    X mid = monoid_pow<MX>(x, r - l);

    vc<int> I;
    if (has_left) I.eb(a);
    I.eb(l);
    cut.enumerate(l + 1, r, [&](int i) { I.eb(i); }, true);

    if (has_right) I.eb(r);

    // ここで I は strictly increasing
    dat[l] = x;
    cut.insert(l);
    if (has_right) cut.insert(r);

    seg.set_many_sorted(move(I), [&](int i) -> X {
      if (has_left && i == a) return left;
      if (i == l) return mid;
      if (has_right && i == r) return right;
      return MX::id();
    });
  }

  vc<X> get_all() {
    vc<X> ANS(n);
    int p = 0;
    while (p < n) {
      int q = cut.next(p + 1);
      FOR(i, p, q) ANS[i] = dat[p];
      p = q;
    }
    return ANS;
  }
};
