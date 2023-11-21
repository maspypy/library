#define PROBLEM "https://yukicoder.me/problems/no/1615"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/rank_maximal_bipartite_matching.hpp"

void solve() {
  LL(N1, N2, K, M);
  Graph<int, 0> G(N1 + N2);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    G.add(a, N1 + b, c);
  }
  G.build();

  Rank_Maximal_Bipartite_Matching<decltype(G)> BM(G);
  ll ANS = 0;
  for (auto& i: BM.get_matching_edges()) {
    // print(i);
    ANS += 1 << (G.edges[i].cost);
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
