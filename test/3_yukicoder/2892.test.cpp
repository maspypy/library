#define PROBLEM "https://yukicoder.me/problems/no/2892"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/centroid_decomposition.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree();
  STR(S);

  ll ANS = 0;

  auto f = [&](vc<int> par, vc<int> V, int n1, int n2) -> void {
    ll n = len(V);
    vc<int> A(n);
    FOR(i, n) { A[i] = (S[V[i]] == '1' ? 1 : -1); }
    // 根を含まない場合の値
    vc<int> dp(n);
    FOR(i, 1, n) {
      int p = par[i];
      dp[i] = dp[p] + A[i];
    }

    vc<int> L, R;
    FOR(i, 1, 1 + n1) L.eb(dp[i] + A[0] + n);
    vc<int> F(2 * n + 3);
    FOR(j, 1 + n1, 1 + n1 + n2) F[n - dp[j]]++;
    F = cumsum<int>(F);
    FOR(i, 1, 1 + n1) ANS += F[dp[i] + A[0] + n];
  };

  centroid_decomposition<1, decltype(G)>(G, f);
  FOR(v, N) if (S[v] == '1')++ ANS;
  for (auto& e: G.edges) {
    if (S[e.frm] == '1' && S[e.to] == '1') ++ANS;
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
