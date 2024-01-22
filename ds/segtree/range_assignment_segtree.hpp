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
    build(m, [](int i) -> X { return MX::unit(); });
  }
  void build(const vc<X> &v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m;
    seg.build(m, f), cut.build(n, [&](int i) -> int { return 1; });
    dat = seg.get_all();
    cut.insert(0);
  }

  X prod(int l, int r) {
    split(l), split(r);
    return seg.prod(l, r);
  }

  void assign(int l, int r, X x) {
    split(l), split(r);
    cut.enumerate(l + 1, r, [&](int i) -> void {
      seg.set(i, MX::unit());
      cut.erase(i);
    });
    dat[l] = x;
    seg.set(l, monoid_pow<MX>(x, r - l));
  }

private:
  void split(int p) {
    if (p == 0 || p == n) return;
    int a = cut.prev(p);
    if (a == p) return;
    int b = cut.next(p);
    // [a,b) -> [a,p), [p,b)
    X x = dat[a];
    dat[p] = x;
    seg.set(a, monoid_pow<MX>(x, p - a));
    seg.set(p, monoid_pow<MX>(x, b - p));
    cut.insert(p);
  }
};
