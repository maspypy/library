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
  const ll INF = 1LL << 60;
  print(monge_shortest_path<INF>(N, f).back());
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
