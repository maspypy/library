#define PROBLEM "https://judge.yosupo.jp/problem/incremental_scc"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/incremental_scc.hpp"
#include "ds/unionfind/unionfind.hpp"

using mint = modint998;

void solve() {
  INT(N, M);
  VEC(mint, X, N);

  Graph<int, 1> G(N);
  G.read_graph(M, 0, 0);

  auto time = incremental_scc(G);
  vc<vc<int>> IDS(M + 1);
  FOR(i, M) {
    if (time[i] != infty<int>) IDS[time[i]].eb(i);
  }

  UnionFind uf(N);
  mint ANS = 0;
  FOR(t, 1, M + 1) {
    for (auto &i: IDS[t]) {
      int a = G.edges[i].frm;
      int b = G.edges[i].to;
      a = uf[a], b = uf[b];
      if (a == b) continue;
      ANS += X[a] * X[b];
      uf.merge(a, b);
      X[uf[a]] = X[a] + X[b];
    }
    print(ANS);
  }
}

signed main() { solve(); }
