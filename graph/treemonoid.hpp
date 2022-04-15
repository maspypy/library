#include "ds/segtree.hpp"
#include "graph/hld.hpp"
#include "alg/monoid_reverse.hpp"

template <typename HLD, typename Monoid, bool edge = false>
struct TreeMonoid {
  using RevMonoid = Monoid_Reverse<Monoid>;
  using X = typename Monoid::value_type;
  HLD &hld;
  int N;
  SegTree<Monoid> seg;
  SegTree<RevMonoid> seg_r;

  TreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {
    if (!Monoid::commute) seg_r = SegTree<RevMonoid>(hld.N);
  }

  TreeMonoid(HLD &hld, vc<X> &dat) : hld(hld), N(hld.N) {
    vc<X> seg_raw(N, Monoid::unit());
    if (!edge) {
      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];
    } else {
      FOR(e, N - 1) {
        int v = hld.e_to_v(e);
        seg_raw[hld.LID[v]] = dat[e];
      }
    }
    seg = SegTree<Monoid>(seg_raw);
    if (!Monoid::commute) seg_r = SegTree<RevMonoid>(seg_raw);
  }

  void set(int i, X x) {
    if (edge) i = hld.e_to_v(i);
    i = hld.LID[i];
    seg.set(i, x);
    if (!Monoid::commute) seg_r.set(i, x);
  }

  X prod_path(int u, int v) {
    auto pd = hld.get_path_decomposition(u, v, edge);
    X val = Monoid::unit();
    for (auto &&[a, b]: pd) {
      X x = (a <= b ? seg.prod(a, b + 1)
                    : (Monoid::commute ? seg.prod(b, a + 1)
                                       : seg_r.prod(b, a + 1)));
      val = Monoid::op(val, x);
    }
    return val;
  }

  // uv path 上で prod_path(u, x) が check を満たす最後の x
  // なければ -1
  // https://codeforces.com/contest/1059/problem/E
  template <class F>
  int max_path(F &check, int u, int v) {
    if (!check(prod_path(u, u))) return -1;
    auto pd = hld.get_path_decomposition(u, v, edge);
    X val = Monoid::unit();
    for (auto &&[a, b]: pd) {
      X x = (a <= b ? seg.prod(a, b + 1)
                    : (Monoid::commute ? seg.prod(b, a + 1)
                                       : seg_r.prod(b, a + 1)));
      if (check(Monoid::op(val, x))) {
        val = Monoid::op(val, x);
        u = (hld.V[b]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(Monoid::op(val, x)); };
      if (a <= b) {
        auto i = seg.max_right(check_tmp, a);
        return (i == a ? u : hld.V[i - 1]);
      } else {
        auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)
                                  : seg_r.min_left(check_tmp, a + 1));
        return (i == a + 1 ? u : hld.V[i]);
      }
    }
    return v;
  }

  X prod_subtree(int u) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.prod(l + edge, r);
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
