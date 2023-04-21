#include "graph/tree.hpp"

// add(v) : 頂点 v のデータを追加する
// query(v) : 頂点 v におけるクエリに答える
// reset() : データが空の状態に戻す。
// データ構造によっては、履歴を使って高速に reset する。
template <typename TREE, typename F1, typename F2, typename F3>
void DSU_on_Tree(TREE& tree, F1& add, F2& query, F3& reset) {
  int N = tree.N;
  FOR_R(i, N) {
    int v = tree.V[i];
    int heavy = -1;
    // solve light edge
    for (auto&& e: (*(tree.G_ptr))[v]) {
      if (e.to == tree.parent[v]) continue;
      if (tree.head[e.to] == e.to) {
        dfs(dfs, e.to);
      } else {
        heavy = e.to;
      }
    }
    // solve heavy edge (keep subtree data)
    if (heavy != -1) { dfs(dfs, heavy); }

    // collect data in light subtree
    for (auto&& e: (*tree.G_ptr)[v]) {
      if (e.to == tree.parent[v]) continue;
      if (e.to == heavy) continue;
      FOR(idx, tree.LID[e.to], tree.RID[e.to]) { add(tree.V[idx]); }
    }
    add(v);
    query(v);

    if (tree.head[v] == v) reset();
  }
}
