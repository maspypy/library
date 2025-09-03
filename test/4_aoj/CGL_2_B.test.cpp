#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/cross_point.hpp"

void solve() {
  LL(Q);
  FOR(Q) {
    LL(a, b, c, d, e, f, g, h);
    Segment<ll> S1(a, b, c, d);
    Segment<ll> S2(e, f, g, h);
    int n = count_cross<ll>(S1, S2, true);
    print(n ? 1 : 0);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
