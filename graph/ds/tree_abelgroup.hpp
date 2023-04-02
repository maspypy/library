#include "ds/fenwicktree/fenwicktree.hpp"
#include "graph/tree.hpp"

template <typename TREE, typename AbelGroup, bool edge, bool path_query,
          bool subtree_query>
struct Tree_AbelGroup {
  using X = typename AbelGroup::value_type;
  TREE &tree;
  int N;
  FenwickTree<AbelGroup> bit, bit_subtree;

  Tree_AbelGroup(TREE &tree) : tree(tree), N(tree.N) {
    build([](int i) -> X { return AbelGroup::unit(); });
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
    if (!edge) {
      FOR(v, N) {
        X x = f(v);
        bit_raw_1[tree.ELID(v)] = x;
        bit_raw_1[tree.ERID(v)] = AbelGroup::inverse(x);
        bit_raw_2[tree.LID[v]] = x;
      }
    } else {
      FOR(e, N - 1) {
        int v = tree.e_to_v(e);
        X x = f(v);
        bit_raw_1[tree.ELID(v)] = x;
        bit_raw_1[tree.ERID(v)] = AbelGroup::inverse(x);
        bit_raw_2[tree.LID[v]] = x;
      }
    }
    bit.build(bit_raw_1);
    bit_subtree.build(bit_raw_2);
  }

  void add(int i, X x) {
    int v = (edge ? tree.e_to_v(i) : i);
    if (path_query) {
      X inv_x = AbelGroup::inverse(x);
      bit.add(tree.ELID(v), x);
      bit.add(tree.ERID(v), inv_x);
    }
    if (subtree_query) bit_subtree.add(tree.LID[v], x);
  }

  X prod_path(int frm, int to) {
    assert(path_query);
    int lca = tree.LCA(frm, to);
    // [frm, lca)
    X x1 = bit.prod(tree.ELID(lca) + 1, tree.ELID(frm) + 1);
    // edge なら (lca, to]、vertex なら [lca, to]
    X x2 = bit.prod(tree.ELID(lca) + edge, tree.ELID(to) + 1);
    return AbelGroup::op(x1, x2);
  }

  X prod_subtree(int u) {
    assert(subtree_query);
    int l = tree.LID[u], r = tree.RID[u];
    return bit_subtree.prod(l + edge, r);
  }
};
