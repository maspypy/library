#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/block_cut.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);

  Block_Cut X(G);
  auto T = X.BCT;

  int single = 0;
  FOR(v, N) if (G.deg(v) == 0)++ single;

  print(T.N - N + single);
  FOR(k, N, T.N) {
    vc<int> ANS;
    for (auto&& e : T[k]) ANS.eb(e.to);
    print(len(ANS), ANS);
  }
  FOR(v, N) if (G.deg(v) == 0) print(1, v);
}

signed main() {
  solve();

  return 0;
}