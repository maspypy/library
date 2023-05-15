#define PROBLEM "https://yukicoder.me/problems/no/1242"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/functional.hpp"

void solve() {
  LL(N, K);
  VEC(ll, A, K);

  FunctionalGraph<int> FG(64);
  FOR(s, 64) {
    int t = (2 * s) & 63;
    bool ok = 1;
    if (!(s & 1) && !(s & 32)) ok = 0;
    if (!(s & 2) && !(s & 16)) ok = 0;
    if (!(s & 4) && !(s & 8)) ok = 0;
    if (ok) t |= 1;
    FG.add(s, t);
  }
  auto [G, tree] = FG.build();
  ll x = N;
  ll s = 63;
  FOR_R(k, K) {
    ll y = A[k];
    s = FG.jump(tree, s, x - y);
    s &= 62;
    x = y;
  }
  s = FG.jump(tree, s, x - 1);
  Yes(s & 1);
}

signed main() {
  solve();
  return 0;
}