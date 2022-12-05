#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/sliding_window_aggregation.hpp"
#include "alg/monoid/gcd.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  Slinding_Window_Aggregation<Monoid_Gcd<ll>> swag;
  ll R = 0;
  ll ANS = 0;
  FOR(L, N) {
    chmax(R, L);
    while (R < N && gcd(swag.prod(), A[R]) != 1) swag.push(A[R++]);
    ANS += N - R;
    if (len(swag)) swag.pop();
  }
  print(ANS);
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
