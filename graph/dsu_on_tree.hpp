#include "graph/hld.hpp"

// add(v) : 頂点 v のデータを追加する
// query(v) : 頂点 v におけるクエリに答える
// reset() : データが空の状態に戻す。
// データ構造によっては、履歴を使って高速に reset する。
template <typename HLD, typename F1, typename F2, typename F3>
void DSU_on_Tree(HLD& hld, F1& add, F2& query, F3& reset) {
  auto& G = hld.G;

  auto dfs = [&](auto& dfs, int v) -> void {
    int heavy = -1;
    // solve light edge
    for (auto&& e: G[v]) {
      if (e.to == hld.parent[v]) continue;
      if (hld.head[e.to] == e.to) {
        dfs(dfs, e.to);
      } else {
        heavy = e.to;
      }
    }
    // solve heavy edge (keep subtree data)
    if (heavy != -1) { dfs(dfs, heavy); }

    // collect data in light subtree
    for (auto&& e: G[v]) {
      if (e.to == hld.parent[v]) continue;
      if (e.to == heavy) continue;
      FOR(idx, hld.LID[e.to], hld.RID[e.to]) { add(hld.V[idx]); }
    }
    add(v);
    query(v);

    if (hld.head[v] == v) reset();
  };

  int root = hld.V[0];
  dfs(dfs, root);
}