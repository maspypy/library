#include "graph/base.hpp"

// 1 辺消したときに
// u,v が連結か / 連結成分数 / v の連結成分サイズ
struct Remove_One_Edge_Connectivity {
  int N, M;
  int n_comp_base;
  vc<pair<int, int>> edge;
  vc<int> root;
  vc<int> LID, RID;
  vc<bool> bridge;

  template <typename GT>
  Remove_One_Edge_Connectivity(GT& G) {
    build(G);
  }

  template <typename GT>
  void build(GT& G) {
    N = G.N, M = G.M;
    edge.resize(M);
    for (auto& e: G.edges) edge[e.id] = {e.frm, e.to};
    root.assign(N, -1);
    LID.assign(N, -1), RID.assign(N, -1);
    bridge.assign(M, 0);
    vc<int> low(N, -1);
    n_comp_base = 0;
    int p = 0;
    auto dfs = [&](auto& dfs, int v, int last_e) -> void {
      low[v] = LID[v] = p++;
      for (auto&& e: G[v]) {
        if (e.id == last_e) continue;
        if (root[e.to] == -1) {
          root[e.to] = root[v];
          dfs(dfs, e.to, e.id);
          chmin(low[v], low[e.to]);
          bridge[e.id] = (low[e.to] == LID[e.to]);
        } else {
          chmin(low[v], LID[e.to]);
        }
      }
      RID[v] = p;
    };
    FOR(v, N) {
      if (root[v] == -1) { n_comp_base++, root[v] = v, dfs(dfs, v, -1); }
    }
    for (auto& [a, b]: edge) {
      if (in_subtree(a, b)) swap(a, b);
    }
  }

  int n_comp(int eid) { return n_comp_base + (bridge[eid] ? 1 : 0); }

  bool is_connected(int eid, int u, int v) {
    if (root[u] != root[v]) return false;
    if (!bridge[eid]) return true;
    auto [a, b] = edge[eid];
    return (in_subtree(u, b) == in_subtree(v, b));
  }

  int size(int eid, int v) {
    int r = root[v];
    if (!bridge[eid]) { return subtree_size(r); }
    auto [a, b] = edge[eid];
    if (root[a] != r) { return subtree_size(r); }
    if (in_subtree(v, b)) return subtree_size(b);
    return subtree_size(r) - subtree_size(b);
  }

private:
  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }
  int subtree_size(int v) { return RID[v] - LID[v]; }
};
