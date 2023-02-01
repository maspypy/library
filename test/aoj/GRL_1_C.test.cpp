#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/warshall_floyd.hpp"

void solve() {
  LL(N, M);
  Graph<ll, 1> G(N);
  G.read_graph(M, 1, 0);
  auto dist = warshall_floyd<ll>(G);
  FOR(v, N) if (dist[v][v] < 0) return print("NEGATIVE CYCLE");
  FOR(a, N) {
    string S;
    FOR(b, N) {
      if (b) S += " ";
      ll x = dist[a][b];
      if (x == infty<ll>)
        S += "INF";
      else
        S += to_string(x);
    }
    print(S);
  }
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
