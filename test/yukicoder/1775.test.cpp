#define PROBLEM "https://yukicoder.me/problems/no/1775"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/minimum_cycle_length_through_specified.hpp"

void solve() {
  LL(N, M);
  vv(bool, can, N, N, 1);
  INT(X, Y, Z);
  --X, --Y, --Z;
  FOR(M) {
    LL(a, b);
    --a, --b;
    can[a][b] = can[b][a] = 0;
  }

  Graph<bool, 0> G(N);
  FOR(i, N) FOR(j, i) if (can[i][j]) G.add(i, j);
  G.build();

  vc<int> use = {X, Y, Z};
  int ANS = minimum_cycle_length_through_specified(G, use);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
