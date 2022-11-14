#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1566"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/bipartite.hpp"

void solve() {
  LL(N);
  VEC(pi, AB, N);
  ll K = 31;
  for (auto&& [a, b]: AB) { --a; }
  Graph<bool, 0> G(K + N);
  vi isin(K);
  FOR(i, N) {
    auto [a, b] = AB[i];
    FOR(k, a, b) {
      G.add(k, K + i);
      isin[k] = 1;
    }
  }
  G.build();

  BipartiteMatching<decltype(G)> X(G);
  ll a = len(X.matching());
  ll b = SUM<int>(isin);
  print((a + b) * 50);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
