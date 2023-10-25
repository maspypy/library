#define PROBLEM "https://atcoder.jp/contests/abc319/tasks/abc319_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/implicit_graph/cograph_bfs.hpp"
#include "mod/modint.hpp"
using mint = modint998;

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M);

  auto dist = cograph_bfs(G, 0).fi;

  ll d = dist[N - 1];
  if (d == infty<int>) return print(-1);

  vvc<int> V(d + 1);
  FOR(v, N) {
    if (dist[v] <= d) V[dist[v]].eb(v);
  }

  vc<mint> dp(N);
  dp[0] = 1;
  vc<int> pre(N);
  FOR(i, 1, d + 1) {
    mint base = 0;
    for (auto&& v: V[i - 1]) pre[v] = 1, base += dp[v];
    for (auto&& v: V[i]) {
      dp[v] += base;
      for (auto& e: G[v]) {
        if (pre[e.to]) dp[v] -= dp[e.to];
      }
    }
    for (auto&& v: V[i - 1]) pre[v] = 0;
  }
  // print(dp);
  print(dp[N - 1]);
}

signed main() {
  solve();
  return 0;
}
