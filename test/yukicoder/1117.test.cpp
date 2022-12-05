#define PROBLEM "https://yukicoder.me/problems/no/1117"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/sliding_window_aggregation.hpp"
#include "alg/monoid/max.hpp"

void solve() {
  LL(N, K, M);
  VEC(ll, A, N);
  auto Ac = cumsum<ll>(A);
  const ll INF = 1LL << 60;
  vi DP(N + 1, -INF);
  DP[0] = 0;
  FOR(K) {
    Slinding_Window_Aggregation<Monoid_Max<ll>> swag1, swag2;
    vi newDP(N + 1, -INF);
    FOR(i, N + 1) {
      chmax(newDP[i], swag1.prod() - Ac[i]);
      chmax(newDP[i], swag2.prod() + Ac[i]);
      swag1.push(DP[i] + Ac[i]);
      swag2.push(DP[i] - Ac[i]);
      if (len(swag1) > M) swag1.pop();
      if (len(swag2) > M) swag2.pop();
    }
    swap(DP, newDP);
  }
  print(DP.back());
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
