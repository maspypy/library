#include "graph/tree.hpp"
#include "ds/segtree/dual_segtree.hpp"

template <typename TREE, typename Monoid, bool edge>
struct Dual_Tree_Monoid {
  using MX = Monoid;
  using X = typename MX::value_type;
  TREE &tree;
  int N;
  Dual_SegTree<MX> seg;

  Dual_Tree_Monoid(TREE &tree) : tree(tree), N(tree.N), seg(tree.N) {}

  X get(int i) {
    int v = (edge ? tree.e_to_v(i) : i);
    return seg.get(tree.LID[v]);
  }

  vc<X> get_all() {
    vc<X> tmp = seg.get_all();
    vc<X> res(N - edge);
    FOR(i, N - edge) {
      int v = (edge ? tree.e_to_v(i) : i);
      res[i] = tmp[tree.LID[v]];
    }
    return res;
  }

  void apply_path(int u, int v, X x) {
    auto pd = tree.get_path_decomposition(u, v, edge);
    for (auto &&[a, b] : pd) {
      (a <= b ? seg.apply(a, b + 1, x) : seg.apply(b, a + 1, x));
    }
    return;
  }

  void apply_subtree(int u, X x) {
    int l = tree.LID[u], r = tree.RID[u];
    return seg.apply(l + edge, r, x);
  }

  void apply_outtree(int u, X a) {
    int l = tree.LID[u], r = tree.RID[u];
    seg.apply(0 + edge, l + edge, a);
    seg.apply(r, N, a);
  }
};
