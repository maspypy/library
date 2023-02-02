#define PROBLEM "https://atcoder.jp/contests/arc151/tasks/arc151_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/longest_common_substring.hpp"
#include "graph/shortest_path/dijkstra.hpp"

void solve() {
  INT(N);
  VEC(int, A, N);
  INT(P);
  VEC(int, B, P);
  INT(Q);
  VEC(int, C, Q);

  int lcp = [&]() -> int {
    auto [l1, r1, l2, r2] = longest_common_substring(B, C);
    return r1 - l1;
  }();

  if (lcp >= 1) { return print(P + Q - 2 * lcp); }

  // あとは、1 文字を経由してうろうろする場合
  for (auto&& x: A) --x;
  for (auto&& x: B) --x;
  for (auto&& x: C) --x;
  int S = N;
  int T = N + 1;
  Graph<int, 0> G(N + 2);
  for (auto&& x: B) { G.add(S, x, P - 1); }
  for (auto&& x: C) { G.add(x, T, Q - 1); }
  FOR(i, N - 1) {
    G.add(A[i], A[i + 1], 2);
    G.add(A[i + 1], A[i], 2);
  }
  G.build();

  auto [dist, par] = dijkstra(G, S);
  print(dist[T]);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
