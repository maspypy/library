#define PROBLEM "https://atcoder.jp/contests/arc123/tasks/arc123_d"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/slope_trick/slope_trick_0.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  Slope_Trick_0 X;
  FOR(i, N) {
    if (i > 0) {
      ll c = max<ll>(0, A[i] - A[i - 1]);
      X.shift(c);
      X.clear_right();
    }
    X.add_abs(0);
    X.add_abs(A[i]);
  }
  auto [xl, xr, min_f] = X.get_min();
  print(min_f);
}

signed main() {
  solve();
  return 0;
}
