#include "ds/segtree/lazy_segtree.hpp"
#include "graph/tree.hpp"

template <typename TREE, typename ActedMonoid, bool edge>
struct Lazy_Tree_Monoid {
  using MX = typename ActedMonoid::Monoid_X;
  using MA = typename ActedMonoid::Monoid_A;
  static_assert(MX::commute);
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  TREE &tree;
  int N;
  Lazy_SegTree<ActedMonoid> seg;

  Lazy_Tree_Monoid(TREE &tree) : tree(tree), N(tree.N) {
    build([](int i) -> X { return MX::unit(); });
  }

  Lazy_Tree_Monoid(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N) {
    build([&](int i) -> X { return dat[i]; });
  }

  template <typename F>
  Lazy_Tree_Monoid(TREE &tree, F f) : tree(tree), N(tree.N) {
    build(f);
  }

  template <typename F>
  void build(F f) {
    vc<X> seg_raw(N, MX::unit());
    if (!edge) {
      seg.build(N, [&](int i) -> X { return f(tree.V[i]); });
    } else {
      seg.build(N, [&](int i) -> X {
        return (i == 0 ? MX::unit() : f(tree.v_to_e(tree.V[i])));
      });
    }
  }

  void set(int i, X x) {
    if (edge) i = tree.e_to_v(i);
    i = tree.LID[i];
    seg.set(i, x);
  }

  X get(int v) { return seg.get(tree.LID[v]); }
  vc<X> get_all() {
    vc<X> dat = seg.get_all();
    vc<X> res(N);
    FOR(v, N) res[v] = dat[tree.LID[v]];
    return res;
  }

  X prod_path(int u, int v) {
    auto pd = tree.get_path_decomposition(u, v, edge);
    X val = MX::unit();
    for (auto &&[a, b]: pd) {
      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));
      val = MX::op(val, x);
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
    X val = MX::unit();
    for (auto &&[a, b]: pd) {
      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));
      if (check(MX::op(val, x))) {
        val = MX::op(val, x);
        u = (tree.V[b]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x)); };
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
    if (!check(MX::unit())) return -1;
    int lca = tree.lca(u, v);
    auto pd = tree.get_path_decomposition(u, lca, edge);
    X val = MX::unit();

    // climb
    for (auto &&[a, b]: pd) {
      assert(a >= b);
      X x = seg.prod(b, a + 1);
      if (check(MX::op(val, x))) {
        val = MX::op(val, x);
        u = (tree.parent[tree.V[b]]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x)); };
      auto i = seg.min_left(check_tmp, a + 1);
      if (i == a + 1) return u;
      return tree.parent[tree.V[i]];
    }
    // down
    pd = tree.get_path_decomposition(lca, v, edge);
    for (auto &&[a, b]: pd) {
      assert(a <= b);
      X x = seg.prod(a, b + 1);
      if (check(MX::op(val, x))) {
        val = MX::op(val, x);
        u = (tree.V[b]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x)); };
      auto i = seg.max_right(check_tmp, a);
      return (i == a ? u : tree.V[i - 1]);
    }
    return v;
  }
};
