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
  I.enumerate_all([&](ll l, ll r, int x) -> void {
    if (x) print(l, r);
  });
}

signed main() {
  solve();

  return 0;
}
