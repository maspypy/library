#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/minimum_hamiltonian_cycle.hpp"

void solve() {
  LL(N, M);
  Graph<int, 1> G(N);
  G.read_graph(M, 1, 0);
  print(minimum_hamiltonian_cycle<int>(G).fi);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
