#define PROBLEM "https://yukicoder.me/problems/no/1324"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N, K);
  VEC(ll, A, N);
  VEC(ll, B, N);
  auto left = [&](int i) -> int { return 1 + i; };
  auto right = [&](int i) -> int { return 1 + N + i; };
  int source = 0;
  int sink = 1 + N + N;
  Min_Cost_Flow<int, int, true> G(N + N + 2, source, sink);

  VV(ll, P, N, N);
  FOR(i, N) G.add(source, left(i), A[i], 0);
  FOR(i, N) G.add(right(i), sink, B[i], 0);

  ll base = 0;
  FOR(i, N) FOR(j, N) {
    ll y = P[i][j];
    base += y * y;
    FOR(k, min(A[i], B[j]) + 1) {
      ll a = (y - k) * (y - k);
      ll b = (y - k - 1) * (y - k - 1);
      G.add(left(i), right(j), 1, b - a);
    }
  }
  auto [flow, cost] = G.flow();
  print(base + cost);
}

signed main() {
  solve();
  return 0;
}