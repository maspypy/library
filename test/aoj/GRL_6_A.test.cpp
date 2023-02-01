#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/maxflow.hpp"

void solve() {
  LL(N, M);
  MaxFlowGraph<int> G(N);
  FOR(M) {
    LL(a, b, c);
    G.add(a, b, c);
  }
  print(G.flow(0, N - 1));
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
