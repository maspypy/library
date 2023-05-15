#include "graph/ds/tree_abelgroup.hpp"
#include "ds/fastset.hpp"

// 木は固定。頂点重みを +1 できる。
// cent: 重心
// max_subtree
template <typename TREE>
struct Incremental_Centroid {
  TREE& tree;
  int N;
  int cent;
  pair<int, int> max_subtree; // (adj, size)
  int wt_sm;
  Tree_AbelGroup<TREE, Monoid_Add<int>, 0, 0, 1> TA;
  FastSet ss;

  Incremental_Centroid(TREE& tree)
      : tree(tree),
        N(tree.N),
        cent(0),
        max_subtree(0, 0),
        wt_sm(0),
        TA(tree),
        ss(N) {}

  int get_subtree_wt(int v) {
    assert(v != cent);
    // cent から見て v 方向
    if (tree.in_subtree(v, cent)) {
      return TA.prod_subtree(tree.jump(cent, v, 1));
    }
    return wt_sm - TA.prod_subtree(cent);
  }

  int move_to(int v) {
    // 圧縮木上で cent から v に進む
    if (tree.in_subtree(v, cent)) {
      // v 方向にある重みの lca
      int a = tree.jump(cent, v, 1);
      int L = tree.LID[a], R = tree.RID[a];
      L = ss.next(L), R = ss.prev(R - 1);
      int x = tree.V[L], y = tree.V[R];
      return tree.lca(x, y);
    }
    int L = tree.LID[cent], R = tree.RID[cent];
    int x = v;
    vc<int> I;
    I.eb(ss.next(0)), I.eb(ss.prev(L - 1));
    I.eb(ss.next(R)), I.eb(ss.prev(N - 1));
    for (auto&& idx: I) {
      if (idx == -1 || idx == N) continue;
      if (L <= idx && idx < R) continue;
      int y = tree.V[idx];
      x = tree.lca_root(x, y, cent);
    }
    return x;
  }

  void add(int v) {
    ss.insert(tree.LID[v]), TA.add(v, 1), wt_sm++;
    if (v == cent) return;
    int wt = get_subtree_wt(v);
    if (max_subtree.se < wt) max_subtree = {tree.jump(cent, v, 1), wt};
    if (2 * wt <= wt_sm) return;
    int k = wt;
    assert(wt_sm == 2 * k - 1);
    int to = move_to(v);
    max_subtree = {tree.jump(to, cent, 1), k - 1};
    cent = to;
  }
};
