#define PROBLEM "https://yukicoder.me/problems/no/1573"
#include "my_template.hpp"
#include "other/io.hpp"
#include "enumerate/floor_range.hpp"

void solve() {
  LL(N, M);
  i128 ANS = 0;
  auto f = [&](ll q, ll l, ll r) -> void {
    ll lo = max(l, 1LL);
    ll hi = min(r - 1, M);
    if (lo > hi) return;
    i128 x = (q * (q + 1) / 2 + q);
    i128 y = (lo + hi) * (hi - lo + 1) / 2;
    ANS += x * y;
  };
  floor_range(N, f);
  print(ANS % 998244353);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
