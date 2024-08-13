#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR 0.00000001
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/distance.hpp"

using Re = double;

void solve() {
  LL(Q);
  FOR(Q) {
    LL(a, b, c, d, e, f, g, h);
    Segment<ll> S1(a, b, c, d);
    Segment<ll> S2(e, f, g, h);
    Re x = distance<Re, ll>(S1, S2);
    print(x);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
