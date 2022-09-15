#define PROBLEM "https://yukicoder.me/problems/no/1242"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/functional.hpp"

void solve() {
  LL(N, K);
  VEC(ll, A, K);

  FunctionalGraph<int> G(64);
  FOR(s, 64) {
    int t = (2 * s) & 63;
    bool ok = 1;
    if (!(s & 1) && !(s & 32)) ok = 0;
    if (!(s & 2) && !(s & 16)) ok = 0;
    if (!(s & 4) && !(s & 8)) ok = 0;
    if (ok) t |= 1;
    G.add(s, t);
  }
  auto tree = G.build();
  ll x = N;
  ll s = 63;
  FOR_R(k, K) {
    ll y = A[k];
    s = G.jump(tree, s, x - y);
    s &= 62;
    x = y;
  }
  s = G.jump(tree, s, x - 1);
  Yes(s & 1);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
