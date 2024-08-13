#define PROBLEM "https://yukicoder.me/problems/no/1301"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N, M);
  Min_Cost_Flow<int, ll> G(N + M + M, 0, N - 1);
  FOR(i, M) {
    LL(a, b, c, d);
    --a, --b;
    int ein = N + 2 * i;
    int eout = N + 2 * i + 1;
    G.add(a, ein, 2, 0);
    G.add(eout, a, 2, 0);
    G.add(b, ein, 2, 0);
    G.add(eout, b, 2, 0);
    G.add(ein, eout, 1, c);
    G.add(ein, eout, 1, d);
  }
  print(G.slope(2).back().se);
}

signed main() {
  solve();
  return 0;
}