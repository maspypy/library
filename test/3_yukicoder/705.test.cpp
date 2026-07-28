#define PROBLEM "https://yukicoder.me/problems/no/705"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/monge/monge_shortest_path.hpp"

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
  Monge_Shortest_Path<ll> solver;
  ll ANS = solver.solve(N, f);

  {
    vc<int> path = solver.restore_path();
    int n = len(path) - 1;
    assert(path[0] == 0 && path[n] == N);
    ll check = 0;
    FOR(i, n) check += f(path[i], path[i + 1]);
    assert(ANS == check);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}