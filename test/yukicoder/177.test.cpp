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
  MaxFlowGraph<ll> G(N + M + 2);
  ll source = N + M;
  ll sink = N + M + 1;
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
  ll f = G.flow(source, sink);
  if (f < W)
    print("BANSAKUTSUKITA");
  else
    print("SHIROBAKO");
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
