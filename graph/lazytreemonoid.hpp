// https://codeforces.com/contest/916/problem/E
#include "ds/lazysegtree.hpp"
#include "graph/hld.hpp"
#include "alg/lazy_reverse.hpp"

template <typename HLD, typename Lazy, bool edge = false>
struct LazyTreeMonoid {
  using MonoX = typename Lazy::X_structure;
  using MonoA = typename Lazy::A_structure;
  using X = typename MonoX::value_type;
  using A = typename MonoA::value_type;
  using RevLazy = Lazy_Reverse<Lazy>;
  HLD &hld;
  int N;
  LazySegTree<Lazy> seg;
  LazySegTree<RevLazy> seg_r;

  LazyTreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {
    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(hld.N);
  }

  LazyTreeMonoid(HLD &hld, vc<X> &dat) : hld(hld), N(hld.N) {
    vc<X> seg_raw(N, MonoX::unit());
    if (!edge) {
      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];
    } else {
      FOR(e, N - 1) {
        int v = hld.e_to_v(e);
        seg_raw[hld.LID[v]] = dat[e];
      }
    }
    seg = LazySegTree<Lazy>(seg_raw);
    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(seg_raw);
  }

  void set(int i, X x) {
    if (edge) i = hld.e_to_v(i);
    i = hld.LID[i];
    seg.set(i, x);
    if (!MonoX::commute) seg_r.set(i, x);
  }

  X prod_path(int u, int v) {
    auto pd = hld.get_path_decomposition(u, v, edge);
    X val = MonoX::unit();
    for (auto &&[a, b]: pd) {
      X x = (a <= b ? seg.prod(a, b + 1)
                    : (MonoX::commute ? seg.prod(b, a + 1)
                                       : seg_r.prod(b, a + 1)));
      val = MonoX::op(val, x);
    }
    return val;
  }

  X prod_subtree(int u) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.prod(l + edge, r);
  }

  X prod_all() {
    return seg.prod_all();
  }

  void apply_path(int u, int v, A a) {
    auto pd = hld.get_path_decomposition(u, v, edge);
    for (auto &&[x, y]: pd) {
      int l = min(x, y), r = max(x, y);
      seg.apply(l, r + 1, a);
      if(!MonoX::commute) seg_r.apply(l, r + 1, a);
    }
  }

  void apply_subtree(int u, A a) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.apply(l + edge, r, a);
  }

  void debug() {
    print("tree_monoid");
    hld.debug();
    seg.debug();
    seg_r.debug();
  }

  void doc() {
    print("HL分解 + セグ木。");
    print("部分木クエリ O(logN) 時間、パスクエリ O(log^2N) 時間。");
  }
};
