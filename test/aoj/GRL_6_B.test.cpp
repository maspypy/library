#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N, M, F);
  Min_Cost_Flow<int, ll, 0> G(N, 0, N - 1);
  FOR(M) {
    LL(a, b, c, d);
    G.add(a, b, c, d);
  }

  auto [f, x] = G.flow(F);
  if (f < F)
    print(-1);
  else
    print(x);
}

signed main() {
  solve();
  return 0;
}