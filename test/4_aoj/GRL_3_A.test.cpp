#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/block_cut.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);
  auto BCT = block_cut(G);
  FOR(v, N) {
    if (BCT.deg(v) != 1) print(v);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}