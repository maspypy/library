#include "graph/base.hpp"

// 辺の列 or 頂点列の vector を返す
// 見つからなかった場合には、空 vector
template <typename Graph>
vc<int> cycle_detection(Graph& G, bool is_edge = 0) {
  assert(G.is_directed());
  assert(G.is_prepared());
  if (!is_edge) {
    auto C = cycle_detection(G, true);
    if (len(C) == 0) return C;
    vc<int> ANS(len(C));
    FOR(i, len(C)) {
      auto e = G.edges[C[i]];
      ANS[i] = e.frm;
    }
    return ANS;
  }

  int N = G.N;
  vc<int> used(N);
  vc<int> path; // edge
  vc<pair<int, int>> par(N);
  vector<int> ANS;

  auto dfs = [&](auto self, int v) -> void {
    used[v] = 1;
    for (auto&& e: G[v]) {
      if (len(ANS)) return;
      if (!used[e.to]) {
        par[e.to] = {v, e.id};
        self(self, e.to);
      }
      elif (used[e.to] == 1) {
        ANS = {e.id};
        int cur = v;
        while (cur != e.to) {
          ANS.eb(par[cur].se);
          cur = par[cur].fi;
        }
        reverse(all(ANS));
        return;
      }
    }
    used[v] = 2;
  };
  FOR(v, N) if (!used[v]) dfs(dfs, v);
  return ANS;
}