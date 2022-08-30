#define PROBLEM "https://yukicoder.me/problems/no/1301"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N, M);
  mcf_graph<int, ll> G(N + M + M);
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
  print(G.slope(0, N - 1, 2).back().se);
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
