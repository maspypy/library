#include "ds/sparse_table/disjoint_sparse_table.hpp"
#include "graph/tree.hpp"
#include "alg/monoid/monoid_reverse.hpp"

template <typename TREE, typename Monoid, bool edge>
struct Static_Tree_Monoid {
  using RevMonoid = Monoid_Reverse<Monoid>;
  using X = typename Monoid::value_type;
  TREE &tree;
  int N;
  Disjoint_Sparse_Table<Monoid> seg;
  Disjoint_Sparse_Table<RevMonoid> seg_r;

  Static_Tree_Monoid(TREE &tree) : tree(tree), N(tree.N) {
    build([](int i) -> X { return Monoid::unit(); });
  }

  Static_Tree_Monoid(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N) {
    build([&](int i) -> X { return dat[i]; });
  }

  template <typename F>
  Static_Tree_Monoid(TREE &tree, F f) : tree(tree), N(tree.N) {
    build(f);
  }

  template <typename F>
  void build(F f) {
    vc<X> seg_raw(N, Monoid::unit());
    if (!edge) {
      seg.build(N, [&](int i) -> X { return f(tree.V[i]); });
      if (!Monoid::commute) {
        seg_r.build(N, [&](int i) -> X { return f(tree.V[i]); });
      }
    } else {
      seg.build(N, [&](int i) -> X {
        return (i == 0 ? Monoid::unit() : f(tree.v_to_e(tree.V[i])));
      });
      if (!Monoid::commute) {
        seg_r.build(N, [&](int i) -> X {
          return (i == 0 ? Monoid::unit() : f(tree.v_to_e(tree.V[i])));
        });
      }
    }
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
