#define PROBLEM "https://atcoder.jp/contests/arc123/tasks/arc123_d"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/func/slope.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  Slope_Trick X;
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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
