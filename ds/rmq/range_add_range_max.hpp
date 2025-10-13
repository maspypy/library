#include "ds/segtree/dynamic_segtree_sparse.hpp"
#include "ds/segtree/segtree.hpp"

// INF+x==INF みたいな処理は入れていない
// N=Q=10^6 で lazysegtree より 40% 程度高速
template <typename T>
struct Range_Add_Range_Max {
  struct Mono {
    using value_type = pair<T, T>;
    using X = value_type;
    static X op(X L, X R) { return {L.fi + R.fi, max(L.se, L.fi + R.se)}; }
    static constexpr X unit() { return {0, -2 * infty<T>}; }
    static constexpr bool commute = false;
  };
  int n;
  T lazy;
  SegTree<Mono> seg;

  Range_Add_Range_Max() {}
  // (n) だけだと 0 埋めで初期化します
  Range_Add_Range_Max(int n) { build(n); }
  template <typename F>
  Range_Add_Range_Max(int n, F f) {
    build(n, f);
  }
  Range_Add_Range_Max(const vc<T> &v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> T { return 0; });
  }
  void build(const vc<T> &v) {
    build(len(v), [&](int i) -> T { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    lazy = 0;
    n = m;
    T pre = 0;
    seg.build(n, [&](int i) -> pair<T, T> {
      T t = f(i) - pre;
      pre += t;
      return {t, t};
    });
  }

  T prod(int L, int R) {
    if (L == R) return -infty<T>;
    ll ans = seg.prod(L, R).se;
    L += seg.size;
    for (; L > 0; L /= 2) {
      if (L & 1) ans += seg.dat[--L].fi;
    }
    return ans + lazy;
  }

  T prod_all() { return prod(0, n); }

  // 基本デバッグ用というつもりでさぼり O(NlogN) になっている
  vc<T> get_all() {
    vc<T> ANS(n);
    FOR(i, n) ANS[i] = prod(i, i + 1);
    return ANS;
  }

  void apply(int L, int R, T x) { apply_suffix(L, x), apply_suffix(R, -x); }

  // [0,i)
  void apply_prefix(int i, T x) {
    lazy += x;
    apply_suffix(i, -x);
  }

  // [i,n)
  void apply_suffix(int i, T x) {
    if (i == n) return;
    T t = seg.get(i).fi + x;
    seg.set(i, {t, t});
  }
  void apply_all(T x) { lazy += x; }

  void set(int i, T x) {
    T now = prod(i, i + 1);
    apply(i, i + 1, x - now);
  }

  void multiply(int i, T x) {
    T now = prod(i, i + 1);
    if (now < x) apply(i, i + 1, x - now);
  }
};

// 座標は long long. ほぼ verify されていない
// https://codeforces.com/contest/542/problem/B
template <typename T>
struct Dynamic_Range_Add_Range_Max {
  struct Mono {
    using value_type = pair<T, T>;
    using X = value_type;
    static X op(X L, X R) { return {L.fi + R.fi, max(L.se, L.fi + R.se)}; }
    static constexpr X unit() { return {0, 0}; }
    static constexpr bool commute = false;
  };
  int n;
  Dynamic_SegTree_Sparse<Mono, false> seg;
  T lazy;
  using np = typename decltype(seg)::np;
  np root;

  // range apply * 2 くらいのノード数
  Dynamic_Range_Add_Range_Max(int NODES, ll L, ll R)
      : seg(NODES, L, R), lazy(0) {
    root = seg.new_root();
  }

  T prod(ll L, ll R) {
    if (L == R) return -infty<T>;
    ll ans = seg.prod(root, L, R).se;
    ans += seg.prod(root, seg.L0, L).fi;
    return ans + lazy;
  }

  void apply(ll L, ll R, T x) { apply_suffix(L, x), apply_suffix(R, -x); }

  // [i,n)
  void apply_suffix(ll i, T x) {
    if (i == seg.R0) return;
    T t = seg.get(root, i).fi + x;
    root = seg.set(root, i, {t, t});
  }
  void apply_all(T x) { lazy += x; }
};
