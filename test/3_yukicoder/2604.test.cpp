#define PROBLEM "https://yukicoder.me/problems/no/2604"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/mincostflow.hpp"

void solve() {
  LL(K, N, M);
  VEC(int, A, K);
  for (auto& a: A) --a;
  VEC(int, B, N);

  int s = N, t = N + 1;
  Min_Cost_Flow<ll, ll, false> G(N + 2, s, t);

  for (auto& a: A) G.add(s, a, 1, 0);
  FOR(i, N) G.add(i, t, B[i], 0);

  FOR(M) {
    LL(a, b, c);
    --a, --b;
    G.add(a, b, K, c);
    G.add(b, a, K, c);
  }
  auto [a, b] = G.flow();
  print(b);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
