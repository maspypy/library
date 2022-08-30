#define PROBLEM "https://yukicoder.me/problems/no/1490"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/rectangle_add_ractangle_sum.hpp"

void solve() {
  LL(H, W, N, M);

  using T = tuple<ll, ll, ll, ll, ll>;
  vc<T> dat;
  FOR(i, N) {
    LL(xl, xr, yl, yr, a);
    --xl, --yl;
    dat.eb(xl, yl, xr, yr, a);
  }

  Rectangle_Add_Rectangle_Sum<Group_Add<ll>, 1> X;
  FOR(M) {
    LL(x, y, b, c);
    --x, --y;
    ll xl = x - b, xr = x + b + 1;
    ll yl = y - b, yr = y + b + 1;
    X.add_query(xl, yl, xr, yr, c);
  }
  FOR(i, N) {
    auto [xl, yl, xr, yr, a] = dat[i];
    X.sum_query(xl, yl, xr, yr);
  }
  auto res = X.calc();
  ll ANS = 0;
  FOR(i, N) {
    auto [xl, yl, xr, yr, a] = dat[i];
    ll x = res[i];
    if (a > x) ++ANS;
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
