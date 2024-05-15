#include "graph/base.hpp"

// [0,n-1]^{n-1}, ただし末尾は n-1, という定式化 (n=1 ok)
vc<int> to_prufer_code(Graph<int, 0>& G) {
  // ラベル最小の葉をとる -> 親を列に追加
  int n = G.N;
  vc<int> par(n);
  {
    auto dfs = [&](auto& dfs, int v, int p) -> void {
      par[v] = p;
      for (auto& e: G[v])
        if (e.to != p) dfs(dfs, e.to, v);
    };
    dfs(dfs, n - 1, -1);
  }
  vc<int> deg = G.deg_array();
  vc<int> res(n - 1);
  int p = 0;
  int leaf = -1;
  FOR(i, n - 1) {
    if (leaf == -1) {
      while (deg[p] != 1) ++p;
      leaf = p;
    }
    res[i] = par[leaf];
    deg[leaf]--, deg[par[leaf]]--;
    leaf = (deg[par[leaf]] == 1 && par[leaf] < p ? par[leaf] : -1);
  }
  return res;
}

Graph<int, 0> from_prufer_code(vc<int> code) {
  int n = len(code) + 1;
  Graph<int, 0> G(n);
  if (n == 1) return G;
  assert(code.back() == n - 1);
  vc<int> deg(n, 1);
  for (auto& v: code) deg[v]++;

  int p = 0;
  int leaf = -1;
  FOR(i, n - 1) {
    if (leaf == -1) {
      while (deg[p] != 1) p++;
      leaf = p;
    }
    G.add(code[i], leaf);
    deg[leaf]--, deg[code[i]]--;
    leaf = (code[i] < p && deg[code[i]] == 1 ? code[i] : -1);
  }
  G.build();
  return G;
}
