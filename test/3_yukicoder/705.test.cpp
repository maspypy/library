#define PROBLEM "https://yukicoder.me/problems/no/705"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/monge.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  VEC(ll, X, N);
  VEC(ll, Y, N);
  auto f = [&](ll i, ll j) -> ll {
    ll a = A[j - 1];
    ll x = X[i], y = Y[i];
    ll dx = abs(a - x);
    ll dy = abs(y);
    return dx * dx * dx + dy * dy * dy;
  };
  print(monge_shortest_path<ll>(N, f).back());
}

signed main() {
  solve();
  return 0;
}
