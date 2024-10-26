#define PROBLEM "https://atcoder.jp/contests/abc217/tasks/abc217_h"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/slope_trick/slope_trick_0.hpp"

void solve() {
  LL(N);
  Slope_Trick_0 f;
  FOR(N) f.add_abs(0);

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
  solve();
  return 0;
}
