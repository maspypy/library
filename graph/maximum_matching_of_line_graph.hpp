#include "graph/base.hpp"

// 同じ頂点に接続する 2 辺をマッチできる
template <typename GT>
vc<pair<int, int>> maximum_matching_of_line_graph(GT& G) {
  assert(!G.is_directed());
  assert(G.is_prepared());
  const int N = G.N, M = G.M;
  vc<pair<int, int>> ANS;
  vc<int> V;
  vc<int> par(N, -1); // eid
  {
    vc<int> done(N);
    FOR(v, N) {
      if (done[v]) continue;
      int cnt = 0;
      auto dfs = [&](auto& dfs, int v, int p) -> void {
        V.eb(v);
        par[v] = p;
        done[v] = 1;
        for (auto&& e: G[v]) {
          ++cnt;
          if (done[e.to]) continue;
          dfs(dfs, e.to, v);
        }
      };
      dfs(dfs, v, -1);
    }
  }
  vc<int> ord(N);
  FOR(i, N) ord[V[i]] = i;
  vc<int> done(M);
  FOR_R(i, N) {
    int v = V[i];
    vc<int> down;
    int up = -1;
    for (auto&& e: G[v]) {
      if (done[e.id]) continue;
      if (up == -1 && e.to == par[v]) up = e.id;
      if (ord[e.to] > ord[v]) down.eb(e.id);
    }
    while (len(down) >= 2) {
      auto i = POP(down);
      auto j = POP(down);
      ANS.eb(i, j);
      done[i] = done[j] = 1;
    }
    if (len(down) == 0) continue;
    if (up != -1) {
      int x = up;
      int y = down[0];
      done[x] = done[y] = 1;
      ANS.eb(x, y);
    }
  }
  return ANS;
}
