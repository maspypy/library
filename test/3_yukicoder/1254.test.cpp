#define PROBLEM "https://yukicoder.me/problems/no/1254"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/unicyclic.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_graph(N);
  UnicyclicGraph X(G);
  vc<int> ANS;
  FOR(i, N) {
    auto& e = G.edges[i];
    if (X.in_cycle[e.frm] && X.in_cycle[e.to]) ANS.eb(i + 1);
  }
  print(len(ANS));
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
