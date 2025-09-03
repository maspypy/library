#define PROBLEM "https://yukicoder.me/problems/no/177"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/maxflow.hpp"

void solve() {
  LL(W);
  LL(N);
  VEC(ll, A, N);
  LL(M);
  VEC(ll, C, M);
  ll source = N + M;
  ll sink = N + M + 1;
  MaxFlow<ll> G(N + M + 2, source, sink);
  auto left = [&](int i) -> int { return i; };
  auto right = [&](int i) -> int { return N + i; };
  FOR(i, N) G.add(source, left(i), A[i]);
  FOR(i, M) G.add(right(i), sink, C[i]);
  FOR(j, M) {
    LL(n);
    vi ok(N, 1);
    FOR(n) {
      LL(x);
      ok[--x] = 0;
    }
    FOR(i, N) if (ok[i]) { G.add(left(i), right(j), infty<ll>); }
  }
  ll f = G.flow();
  if (f < W)
    print("BANSAKUTSUKITA");
  else
    print("SHIROBAKO");
}

signed main() {
  solve();
  return 0;
}
