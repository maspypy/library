#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N, M, F);
  mcf_graph<int, ll, 0> G(N);
  FOR(M) {
    LL(a, b, c, d);
    G.add(a, b, c, d);
  }

  auto [f, x] = G.flow(0, N - 1, F);
  if (f < F)
    print(-1);
  else
    print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
