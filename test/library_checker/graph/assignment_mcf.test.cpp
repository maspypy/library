#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N);
  mcf_graph<int, ll, true> G(N + N + 2);
  int source = 0;
  auto left = [&](int i) -> int { return 1 + i; };
  auto right = [&](int i) -> int { return 1 + N + i; };
  int sink = right(N);
  FOR(i, N) FOR(j, N) {
    LL(x);
    G.add(left(i), right(j), 1, x);
  }
  FOR(i, N) {
    G.add(source, left(i), 1, 0);
    G.add(right(i), sink, 1, 0);
  }
  auto xy = G.slope(source, sink);
  auto edges = G.edges();
  vi ANS(N);
  for (auto&& e: edges) {
    if (e.flow && 1 <= e.frm && e.frm <= N) {
      ANS[e.frm - 1] = e.to - right(0);
    }
  }
  print(xy.back().se);
  print(ANS);
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
