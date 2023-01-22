#define PROBLEM "https://atcoder.jp/contests/abc256/tasks/abc256_d"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/intervals.hpp"

void solve() {
  Intervals<ll, int> I(0);
  LL(N);
  FOR(N) {
    LL(l, r);
    I.set(l, r, 1);
  }
  for (auto [l, r, x]: I.get_all()) {
    if (x) print(l, r);
  };
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
