#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/reflection.hpp"

void solve() {
  using Re = double;
  LL(a, b, c, d);
  Line<ll> L(a, b, c, d);
  LL(Q);
  FOR(Q) {
    LL(x, y);
    Point<Re> p = reflection<Re, ll, ll>(Point<ll>(x, y), L);
    print(p.x, p.y);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
