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
    if (path_query) { bit = FenwickTree<AbelGroup>(2 * N); }
    if (subtree_query) { bit_subtree = FenwickTree<AbelGroup>(N); }
  }

  Tree_AbelGroup(TREE &tree, vc<X> dat) : tree(tree), N(tree.N) {
    if (path_query) {
      vc<X> bit_raw(2 * N);
      if (!edge) {
        assert(len(dat) == N);
        FOR(v, N) {
          bit_raw[tree.ELID(v)] = dat[v];
          bit_raw[tree.ERID(v)] = AbelGroup::inverse(dat[v]);
        }
      } else {
        assert(len(dat) == N - 1);
        FOR(e, N - 1) {
          int v = tree.e_to_v(e);
          bit_raw[tree.ELID(v)] = dat[e];
          bit_raw[tree.ERID(v)] = AbelGroup::inverse(dat[e]);
        }
      }
      bit = FenwickTree<AbelGroup>(bit_raw);
    }
    if (subtree_query) {
      vc<X> bit_raw(N);
      if (!edge) {
        assert(len(dat) == N);
        FOR(v, N) bit_raw[tree.LID[v]] = dat[v];
      } else {
        assert(len(dat) == N - 1);
        FOR(e, N - 1) {
          int v = tree.e_to_v(e);
          bit_raw[tree.LID[v]] = dat[e];
        }
      }
      bit_subtree = FenwickTree<AbelGroup>(bit_raw);
    }
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

  void debug() {
    tree.debug();
    bit.debug();
    bit_subtree.debug();
  }
};
