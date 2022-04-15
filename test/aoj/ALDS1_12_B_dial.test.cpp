#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/dial.hpp"

void solve() {
  LL(N);
  Graph<int, 1> G(N);
  FOR(v, N) {
    LL(u);
    assert(u == v);
    LL(k);
    FOR_(k) {
      LL(a, b);
      G.add(v, a, b);
    }
  }
  G.build();
  auto [dist, par] = dial(G, 0);
  FOR(v, N) print(v, dist[v]);
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
