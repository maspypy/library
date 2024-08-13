#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
#define ERROR 0.00000001

#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/cross_point.hpp"

void solve() {
  LL(Q);
  FOR(Q) {
    LL(a, b, c, d, e, f, g, h);
    Segment<ll> S1(a, b, c, d);
    Segment<ll> S2(e, f, g, h);
    Point<double> pt = cross_point<double>(S1.to_Line(), S2.to_Line());
    print(pt.x, pt.y);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
