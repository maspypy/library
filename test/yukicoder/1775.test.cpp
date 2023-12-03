#define PROBLEM "https://yukicoder.me/problems/no/1775"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/find_path_through_specified.hpp"

void solve() {
  LL(N, M);
  INT(X, Y, Z);
  --X, --Y, --Z;
  vv(bool, can, N, N, 1);
  FOR(M) {
    LL(a, b);
    --a, --b;
    can[a][b] = can[b][a] = 0;
  }

  Graph<int, 0> G(N);
  FOR(a, N) FOR(b, a) if (can[a][b]) G.add(a, b);
  G.build();
  vc<int> need = {Y, Z};
  auto [L, nxt] = find_path_through_specified(G, X, X, need);
  print(L);
}

signed main() {
  solve();
  return 0;
}
