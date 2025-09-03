#define PROBLEM "https://yukicoder.me/problems/no/1678"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N, K);
  vi A(N);
  vvc<int> B(N);
  FOR(i, N) {
    LL(a, m);
    A[i] = a;
    FOR(m) {
      LL(b);
      B[i].eb(--b);
    }
  }

  int source = 0;
  int sink = N + 1;
  auto idx = [&](int v) -> int { return 1 + v; };

  Min_Cost_Flow<int, ll, 1> G(N + 2, source, sink);
  FOR(i, N + 1) G.add(i, i + 1, K, 0);
  FOR(to, N) {
    for (auto&& frm: B[to]) {
      ll cost = A[frm] - A[to];
      G.add(idx(frm), idx(to), 1, cost);
    }
  }
  auto XY = G.slope();
  ll ANS = -XY.back().se;
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}