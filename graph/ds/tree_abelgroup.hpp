#include "ds/fenwicktree/fenwicktree.hpp"
#include "graph/tree.hpp"

template <typename TREE, typename AbelGroup, bool edge, bool path_query,
          bool subtree_query>
struct Tree_AbelGroup {
  using MX = typename AbelGroup;
  using X = typename MX::value_type;
  TREE &tree;
  int N;
  FenwickTree<MX> bit, bit_subtree;

  Tree_AbelGroup(TREE &tree) : tree(tree), N(tree.N) {
    build([](int i) -> X { return MX::unit(); });
  }

  Tree_AbelGroup(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N) {
    build([&](int i) -> X { return dat[i]; });
  }

  template <typename F>
  Tree_AbelGroup(TREE &tree, F f) : tree(tree), N(tree.N) {
    build(f);
  }

  template <typename F>
  void build(F f) {
    vc<X> bit_raw_1(2 * N);
    vc<X> bit_raw_2(N);
    FOR(v, N) {
      X x = MX::unit();
      if (!edge) x = f(v);
      if (edge) x = (v == 0 ? MX::unit() : f(tree.v_to_e(v)));
      bit_raw_1[tree.ELID(v)] = x;
      bit_raw_1[tree.ERID(v)] = MX::inverse(x);
      bit_raw_2[tree.LID[v]] = x;
    }
    if constexpr (path_query) bit.build(bit_raw_1);
    if constexpr (subtree_query) bit_subtree.build(bit_raw_2);
  }

  void add(int i, X x) {
    int v = (edge ? tree.e_to_v(i) : i);
    if constexpr (path_query) {
      bit.add(tree.ELID(v), x);
      bit.add(tree.ERID(v), MX::inverse(x));
    }
    if constexpr (subtree_query) bit_subtree.add(tree.LID[v], x);
  }

  X prod_path(int frm, int to) {
    static_assert(path_query);
    int lca = tree.LCA(frm, to);
    // [frm, lca)
    X x1 = bit.prod(tree.ELID(lca) + 1, tree.ELID(frm) + 1);
    // edge なら (lca, to]、vertex なら [lca, to]
    X x2 = bit.prod(tree.ELID(lca) + edge, tree.ELID(to) + 1);
    return MX::op(x1, x2);
  }

  X prod_subtree(int u) {
    static_assert(subtree_query);
    int l = tree.LID[u], r = tree.RID[u];
    return bit_subtree.prod(l + edge, r);
  }
};
