#define PROBLEM "https://yukicoder.me/problems/no/1077"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/slope_trick/slope_trick_1.hpp"

void solve() {
  LL(N);
  Slope_Trick_1 X;
  using F = decltype(X)::FUNC;
  F f = X.segment_func(-infty<int>, infty<int>, 0, 0);

  FOR(N) {
    LL(x);
    f = X.add_abs(f, x);
    f = X.clear_inc(f);
  }

  auto [fx, lx, rx] = X.get_min(f);
  print(fx);
}

signed main() {
  solve();
  return 0;
}
