#include "ds/disjoint_sparse/disjointsparse.hpp"
#include "graph/tree.hpp"
#include "alg/monoid/monoid_reverse.hpp"

template <typename TREE, typename Monoid, bool edge = false>
struct StaticTreeMonoid {
  using RevMonoid = Monoid_Reverse<Monoid>;
  using X = typename Monoid::value_type;
  TREE &tree;
  int N;
  DisjointSparse<Monoid> seg;
  DisjointSparse<RevMonoid> seg_r;

  StaticTreeMonoid(TREE &tree) : tree(tree), N(tree.N), seg(tree.N) {
    if (!Monoid::commute) seg_r = DisjointSparse<RevMonoid>(tree.N);
  }

  StaticTreeMonoid(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N) {
    vc<X> seg_raw(N, Monoid::unit());
    if (!edge) {
      FOR(v, N) seg_raw[tree.LID[v]] = dat[v];
    } else {
      FOR(e, N - 1) {
        int v = tree.e_to_v(e);
        seg_raw[tree.LID[v]] = dat[e];
      }
    }
    seg = DisjointSparse<Monoid>(seg_raw);
    if (!Monoid::commute) seg_r = DisjointSparse<RevMonoid>(seg_raw);
  }

  X prod_path(int u, int v) {
    auto pd = tree.get_path_decomposition(u, v, edge);
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
  // https://codeforces.com/contest/1230/problem/E
  // edge: https://atcoder.jp/contests/tkppc3/tasks/tkppc3_i
  // edge が特に怪しいかも
  template <class F>
  int max_path(F &check, int u, int v) {
    if (edge) return max_path_edge(check, u, v);
    if (!check(prod_path(u, u))) return -1;
    auto pd = tree.get_path_decomposition(u, v, edge);
    X val = Monoid::unit();
    for (auto &&[a, b]: pd) {
      X x = (a <= b ? seg.prod(a, b + 1)
                    : (Monoid::commute ? seg.prod(b, a + 1)
                                       : seg_r.prod(b, a + 1)));
      if (check(Monoid::op(val, x))) {
        val = Monoid::op(val, x);
        u = (tree.V[b]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(Monoid::op(val, x)); };
      if (a <= b) {
        // 下り
        auto i = seg.max_right(check_tmp, a);
        return (i == a ? u : tree.V[i - 1]);
      } else {
        // 上り
        auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)
                                  : seg_r.min_left(check_tmp, a + 1));
        if (i == a + 1) return u;
        return (edge ? tree.parent[tree.V[i]] : tree.V[i]);
      }
    }
    return v;
  }

  X prod_subtree(int u) {
    int l = tree.LID[u], r = tree.RID[u];
    return seg.prod(l + edge, r);
  }

  void debug() {
    print("tree_monoid");
    tree.debug();
    seg.debug();
    seg_r.debug();
  }

private:
  template <class F>
  int max_path_edge(F &check, int u, int v) {
    assert(edge);
    if (!check(Monoid::unit())) return -1;
    int lca = tree.lca(u, v);
    auto pd = tree.get_path_decomposition(u, lca, edge);
    X val = Monoid::unit();

    // climb
    for (auto &&[a, b]: pd) {
      assert(a >= b);
      X x = (Monoid::commute ? seg.prod(b, a + 1) : seg_r.prod(b, a + 1));
      if (check(Monoid::op(val, x))) {
        val = Monoid::op(val, x);
        u = (tree.parent[tree.V[b]]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(Monoid::op(val, x)); };
      auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)
                                : seg_r.min_left(check_tmp, a + 1));
      if (i == a + 1) return u;
      return tree.parent[tree.V[i]];
    }
    // down
    pd = tree.get_path_decomposition(lca, v, edge);
    for (auto &&[a, b]: pd) {
      assert(a <= b);
      X x = seg.prod(a, b + 1);
      if (check(Monoid::op(val, x))) {
        val = Monoid::op(val, x);
        u = (tree.V[b]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(Monoid::op(val, x)); };
      auto i = seg.max_right(check_tmp, a);
      return (i == a ? u : tree.V[i - 1]);
    }
    return v;
  }
};
