#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/block_cut.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);
  Block_Cut X(G);
  FOR(v, N) if (X.is_art(v)) print(v);
}

signed main() {
  solve();
  return 0;
}