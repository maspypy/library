#define PROBLEM "https://atcoder.jp/contests/abc318/tasks/abc318_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/maxflow.hpp"

void solve() {
  LL(N, M);
  MaxFlowGraph<int> G(2 * N + 2);
  int s = 2 * N, t = 2 * N + 1;
  LL(a, b, c);
  --a, --b, --c;

  FOR(v, N) G.add(2 * v + 0, 2 * v + 1, 1);
  G.add(2 * b + 0, 2 * b + 1, 1);
  G.add(s, 2 * b + 0, 2);
  G.add(2 * a + 1, t, 1);
  G.add(2 * c + 1, t, 1);

  FOR(M) {
    LL(a, b);
    --a, --b;
    G.add(2 * a + 1, 2 * b + 0, 2);
    G.add(2 * b + 1, 2 * a + 0, 2);
  }

  G.build();

  Yes(G.flow(s, t) == 2);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
