#include "alg/monoid/monoid_reverse.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "graph/tree.hpp"

template <typename TREE, typename ActedMonoid, bool edge>
struct Lazy_Tree_Monoid {
  using MX = typename ActedMonoid::Monoid_X;
  using MA = typename ActedMonoid::Monoid_A;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  struct RevAM {
    using Monoid_X = Monoid_Reverse<MX>;
    using Monoid_A = MA;
    using X = typename Monoid_X::value_type;
    using A = typename Monoid_A::value_type;
    static X act(const X &x, const A &a, const ll &size) { return ActedMonoid::act(x, a, size); }
  };

  TREE &tree;
  int N;
  Lazy_SegTree<ActedMonoid> seg;
  Lazy_SegTree<RevAM> seg_r;

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
    if (!edge) {
      auto f_v = [&](int i) -> X { return f(tree.V[i]); };
      seg.build(N, f_v);
      if constexpr (!MX::commute) { seg_r.build(N, f_v); }
    } else {
      auto f_e = [&](int i) -> X { return (i == 0 ? MX::unit() : f(tree.v_to_e(tree.V[i]))); };
      seg.build(N, f_e);
      if constexpr (!MX::commute) { seg_r.build(N, f_e); }
    }
  }

  void set(int i, X x) {
    if constexpr (edge) i = tree.e_to_v(i);
    i = tree.LID[i];
    seg.set(i, x);
    if constexpr (!MX::commute) { seg_r.set(i, x); }
  }

  X get(int v) { return seg.get(tree.LID[v]); }
  vc<X> get_all() {
    vc<X> dat = seg.get_all();
    if (!edge) {
      vc<X> res(N);
      FOR(v, N) res[v] = dat[tree.LID[v]];
      return res;
    } else {
      vc<X> res(N - 1);
      FOR(i, N - 1) { res[i] = dat[tree.LID[tree.e_to_v(i)]]; }
      return res;
    }
  }

  X prod_path(int u, int v) {
    auto pd = tree.get_path_decomposition(u, v, edge);
    X val = MX::unit();
    for (auto &&[a, b]: pd) { val = MX::op(val, get_prod(a, b)); }
    return val;
  }

  X prod_subtree(int u, int root = -1) {
    if (root == u) return prod_all();
    if (root == -1 || tree.in_subtree(u, root)) {
      int l = tree.LID[u], r = tree.RID[u];
      return seg.prod(l + edge, r);
    }
    assert(!edge); // さぼり
    u = tree.jump(u, root, 1);
    int L = tree.LID[u], R = tree.RID[u];
    return MX::op(seg.prod(0, L), seg.prod(R, N));
  }

  X prod_all() {
    static_assert(MX::commute);
    return seg.prod_all();
  }

  void apply_path(int u, int v, A a) {
    auto pd = tree.get_path_decomposition(u, v, edge);
    for (auto &&[x, y]: pd) {
      int l = min(x, y), r = max(x, y);
      seg.apply(l, r + 1, a);
      if constexpr (!MX::commute) { seg_r.apply(l, r + 1, a); }
    }
  }

  void apply_subtree(int u, A a) {
    int l = tree.LID[u], r = tree.RID[u];
    seg.apply(l + edge, r, a);
    if constexpr (!MX::commute) { seg_r.apply(l + edge, r, a); }
  }

  void apply_outtree(int u, A a) {
    int l = tree.LID[u], r = tree.RID[u];
    seg.apply(0 + edge, l + edge, a);
    seg.apply(r, N, a);
    if constexpr (!MX::commute) {
      seg_r.apply(0 + edge, l + edge, a);
      seg_r.apply(r, N, a);
    }
  }

  template <class F>
  int max_path(F check, int u, int v) {
    if constexpr (edge) return max_path_edge(check, u, v);
    if (!check(prod_path(u, u))) return -1;
    auto pd = tree.get_path_decomposition(u, v, edge);
    X val = MX::unit();
    for (auto &&[a, b]: pd) {
      X x = get_prod(a, b);
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
        int i = 0;
        if constexpr (MX::commute) i = seg.min_left(check_tmp, a + 1);
        if constexpr (!MX::commute) i = seg_r.min_left(check_tmp, a + 1);
        if (i == a + 1) return u;
        return tree.V[i];
      }
    }
    return v;
  }

  // closed range [a,b] を heavy path の形式に応じて
  inline X get_prod(int a, int b) {
    if constexpr (MX::commute) return (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));
    return (a <= b ? seg.prod(a, b + 1) : seg_r.prod(b, a + 1));
  }

private:
  template <class F>
  int max_path_edge(F check, int u, int v) {
    static_assert(edge);
    if (!check(MX::unit())) return -1;
    int lca = tree.lca(u, v);
    auto pd = tree.get_path_decomposition(u, lca, edge);
    X val = MX::unit();

    // climb
    for (auto &&[a, b]: pd) {
      assert(a >= b);
      X x = get_prod(a, b);
      if (check(MX::op(val, x))) {
        val = MX::op(val, x);
        u = (tree.parent[tree.V[b]]);
        continue;
      }
      auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x)); };
      int i = 0;
      if constexpr (MX::commute) i = seg.min_left(check_tmp, a + 1);
      if constexpr (!MX::commute) i = seg_r.min_left(check_tmp, a + 1);
      if (i == a + 1) return u;
      return tree.parent[tree.V[i]];
    }
    // down
    pd = tree.get_path_decomposition(lca, v, edge);
    for (auto &&[a, b]: pd) {
      assert(a <= b);
      X x = get_prod(a, b);
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
