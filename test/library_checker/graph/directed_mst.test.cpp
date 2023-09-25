#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/directed_mst.hpp"

void solve() {
  INT(N, M, s);
  Graph<ll, 1> G(N);
  G.read_graph(M, 1, 0);
  auto [cost, I] = directed_mst<decltype(G), 200'000>(G, s);
  vc<int> par(N, -1);
  par[s] = s;
  for (auto &idx: I) {
    auto &e = G.edges[idx];
    par[e.to] = e.frm;
  }
  print(cost);
  print(par);
}

signed main() {
  solve();
  return 0;
}
