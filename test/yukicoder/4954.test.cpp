#define PROBLEM "https://yukicoder.me/problems/4954"
#include "my_template.hpp"
#include "other/io.hpp"
#include "enumerate/floor_range.hpp"

void solve() {
  LL(N);
  ll ANS = 0;
  auto f = [&](ll q, ll l, ll r) -> void { ++ANS; };
  floor_range<int>(N, f);
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
