#define PROBLEM "https://yukicoder.me/problems/no/1297"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/cht_monotone.hpp"
#include "convex/cht.hpp"

void solve() {
  LL(N, C);
  CHT_monotone<ll, true> X2;
  CHT_min<ll> X1;

  FOR(i, N + 1) {
    ll dp = 0;
    if (i) dp = X1.query(i) + (i * i - i) * C;
    if (i == N) return print(dp / 2);
    {
      ll a = i;
      ll b = dp + (i * i - i) * C;
      X2.add(a, b);
    }
    LL(A, B);
    A *= 2, B *= 2;
    ll x = -2 * C * i - A;
    ll y = X2.query(x);
    y += 2 * (i * i + i) * C + B;
    {
      ll a = A - 2 * C * i;
      ll b = y;
      X1.add(a, b);
    }
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
