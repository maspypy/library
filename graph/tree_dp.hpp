#include "graph/base.hpp"

// 木全体に対する結果を return する。
// 部分木ごとに処理したい場合は、fev の最後に行うようにせよ。
template <typename Graph, typename Data, typename F1, typename F2, typename F3>
Data tree_dp(Graph& G, F1 fee, F2 fev, F3 fve, Data unit, int root = 0) {
  int N = G.N;

  auto dfs = [&](auto& dfs, int v, int p) -> Data {
    Data x = unit;
    for (auto&& e: G[v]) {
      if (e.to == p) continue;
      x = fee(x, fve(dfs(dfs, e.to, v), e));
    }
    return fev(x, v);
  };
  return dfs(dfs, root, -1);
}
