#include "ds/segtree/segtree.hpp"

// INF+x==INF みたいな処理は入れていない
// N=Q=10^6 で lazysegtree より 40% 程度高速
template <typename T>
struct Range_Add_Range_Min {
  struct Mono {
    using value_type = pair<T, T>;
    using X = value_type;
    static X op(X L, X R) { return {L.fi + R.fi, min(L.se, L.fi + R.se)}; }
    static constexpr X unit() { return {0, infty<ll>}; }
    static constexpr bool commute = false;
  };
  int n;
  SegTree<Mono> seg;

  Range_Add_Range_Min() {}
  Range_Add_Range_Min(int n) { build(n); }
  template <typename F>
  Range_Add_Range_Min(int n, F f) {
    build(n, f);
  }
  Range_Add_Range_Min(const vc<T>& v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> T { return infty<T>; });
  }
  void build(const vc<T>& v) {
    build(len(v), [&](int i) -> T { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m;
    T pre = 0;
    seg.build(n, [&](int i) -> pair<T, T> {
      T t = f(i) - pre;
      pre += t;
      return {t, t};
    });
  }

  T prod(int L, int R) {
    if (L == R) return infty<T>;
    ll ans = seg.prod(L, R).se;
    L += seg.size;
    for (; L > 0; L /= 2) {
      if (L & 1) ans += seg.dat[--L].fi;
    }
    return ans;
  }

  void apply(int L, int R, T x) {
    T l = seg.get(L).fi + x;
    seg.set(L, {l, l});
    if (R == n) return;
    T r = seg.get(R).fi - x;
    seg.set(R, {r, r});
  }
};