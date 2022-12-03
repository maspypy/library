#define PROBLEM "https://atcoder.jp/contests/abc217/tasks/abc217_h"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/slope.hpp"

void solve() {
  LL(N);
  Slope_Trick f(vi(N, 0), vi(N, 0));

  ll pt = 0;
  FOR(N) {
    LL(t, d, x);
    ll dt = t - pt;
    pt = t;
    f.sliding_window_minimum(-dt, dt);
    if (d == 0) f.add_a_minus_x(x);
    if (d == 1) f.add_x_minus_a(x);
  }
  auto [xl, xr, min_f] = f.get_min();
  print(min_f);
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
