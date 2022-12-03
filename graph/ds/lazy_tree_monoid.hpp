#include "ds/segtree/lazy_segtree.hpp"
#include "graph/tree.hpp"

template <typename TREE, typename ActedMonoid, bool edge = false>
struct Lazy_Tree_Monoid {
  using MonoX = typename ActedMonoid::Monoid_X;
  using MonoA = typename ActedMonoid::Monoid_A;
  using X = typename MonoX::value_type;
  using A = typename MonoA::value_type;
  TREE &tree;
  int N;
  Lazy_SegTree<ActedMonoid> seg;

  Lazy_Tree_Monoid(TREE &tree) : tree(tree), N(tree.N), seg(tree.N) {
    assert(MonoX::commute);
  }

  Lazy_Tree_Monoid(TREE &tree, vc<X> dat) : tree(tree), N(tree.N) {
    vc<X> seg_raw(N, MonoX::unit());
    if (!edge) {
      FOR(v, N) seg_raw[tree.LID[v]] = dat[v];
    } else {
      FOR(e, N - 1) {
        int v = tree.e_to_v(e);
        seg_raw[tree.LID[v]] = dat[e];
      }
    }
    seg = Lazy_SegTree<ActedMonoid>(seg_raw);
    assert(MonoX::commute);
  }

  void set(int i, X x) {
    if (edge) i = tree.e_to_v(i);
    i = tree.LID[i];
    seg.set(i, x);
  }

  X prod_path(int u, int v) {
    auto pd = tree.get_path_decomposition(u, v, edge);
    X val = MonoX::unit();
    for (auto &&[a, b]: pd) {
      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));
      val = MonoX::op(val, x);
    }
    return val;
  }

  X prod_subtree(int u) {
    int l = tree.LID[u], r = tree.RID[u];
    return seg.prod(l + edge, r);
  }

  X prod_all() { return seg.prod_all(); }

  void apply_path(int u, int v, A a) {
    auto pd = tree.get_path_decomposition(u, v, edge);
    for (auto &&[x, y]: pd) {
      int l = min(x, y), r = max(x, y);
      seg.apply(l, r + 1, a);
    }
  }

  void apply_subtree(int u, A a) {
    int l = tree.LID[u], r = tree.RID[u];
    return seg.apply(l + edge, r, a);
  }

  template <class F>
  int max_path(F &check, int u, int v) {
    if (edge) return max_path_edge(check, u, v);
    if (!check(prod_path(u, u))) return -1;
    auto pd = tree.get_path_decomposition(u, v, edge);
    X val = MonoX::unit();
    for (auto &&[a, b]: pd) {
      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));
      if (check(MonoX::op(val, x))) {
        val = MonoX::op(val, x);
        u = (tree.V[b]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(MonoX::op(val, x)); };
      if (a <= b) {
        // 下り
        auto i = seg.max_right(check_tmp, a);
        return (i == a ? u : tree.V[i - 1]);
      } else {
        // 上り
        auto i = seg.min_left(check_tmp, a + 1);
        if (i == a + 1) return u;
        return tree.V[i];
      }
    }
    return v;
  }

private:
  template <class F>
  int max_path_edge(F &check, int u, int v) {
    assert(edge);
    if (!check(MonoX::unit())) return -1;
    int lca = tree.lca(u, v);
    auto pd = tree.get_path_decomposition(u, lca, edge);
    X val = MonoX::unit();

    // climb
    for (auto &&[a, b]: pd) {
      assert(a >= b);
      X x = seg.prod(b, a + 1);
      if (check(MonoX::op(val, x))) {
        val = MonoX::op(val, x);
        u = (tree.parent[tree.V[b]]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(MonoX::op(val, x)); };
      auto i = seg.min_left(check_tmp, a + 1);
      if (i == a + 1) return u;
      return tree.parent[tree.V[i]];
    }
    // down
    pd = tree.get_path_decomposition(lca, v, edge);
    for (auto &&[a, b]: pd) {
      assert(a <= b);
      X x = seg.prod(a, b + 1);
      if (check(MonoX::op(val, x))) {
        val = MonoX::op(val, x);
        u = (tree.V[b]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(MonoX::op(val, x)); };
      auto i = seg.max_right(check_tmp, a);
      return (i == a ? u : tree.V[i - 1]);
    }
    return v;
  }
};
