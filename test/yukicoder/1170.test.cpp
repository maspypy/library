#define PROBLEM "https://yukicoder.me/problems/no/1170"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/range_to_range_graph.hpp"
#include "graph/strongly_connected_component.hpp"

void solve() {
  LL(N, A, B);
  VEC(ll, X, N);
  Range_to_Range_Graph<int> RRG(N);
  FOR(i, N) {
    {
      ll l = LB(X, X[i] - B);
      ll r = UB(X, X[i] - A);
      RRG.add_to_range(i, l, r, 1);
    }
    {
      ll l = LB(X, X[i] + A);
      ll r = UB(X, X[i] + B);
      RRG.add_to_range(i, l, r, 1);
    }
  }
  auto G = RRG.build();
  auto [C, comp] = strongly_connected_component(G);
  vi sz(C);
  FOR(v, N) sz[comp[v]]++;
  FOR(v, N) print(sz[comp[v]]);
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
