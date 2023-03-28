#include "graph/tree.hpp"
#include "ds/segtree/dual_segtree.hpp"

template <typename TREE, typename Monoid, bool edge>
struct Dual_Tree_Monoid {
  using X = typename Monoid::value_type;
  TREE &tree;
  int N;
  Dual_SegTree<Monoid> seg;

  Dual_Tree_Monoid(TREE &tree) : tree(tree), N(tree.N), seg(tree.N) {}

  X get(int i) {
    int v = i;
    if (edge) {
      auto &&e = tree.G.edges[i];
      v = (tree.parent[e.frm] == e.to ? e.frm : e.to);
    }
    return seg.get(tree.LID[v]);
  }

  vc<X> get_all() {
    vc<X> tmp = seg.get_all();
    vc<X> res;
    FOR(i, N) {
      if (edge && i == N - 1) break;
      int v = i;
      if (edge) {
        auto &&e = tree.G.edges[i];
        v = (tree.parent[e.frm] == e.to ? e.frm : e.to);
      }
      res.eb(tmp[tree.LID[v]]);
    }
    return res;
  }

  void apply_path(int u, int v, X x) {
    auto pd = tree.get_path_decomposition(u, v, edge);
    for (auto &&[a, b]: pd) {
      (a <= b ? seg.apply(a, b + 1, x) : seg.apply(b, a + 1, x));
    }
    return;
  }

  void apply_subtree(int u, X x) {
    int l = tree.LID[u], r = tree.RID[u];
    return seg.apply(l + edge, r, x);
  }
};
