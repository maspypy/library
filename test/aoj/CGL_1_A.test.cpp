#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"
#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/projection.hpp"

void solve() {
  using Re = long double;
  LL(a, b, c, d);
  Line<ll> L(a, b, c, d);
  LL(Q);
  FOR(Q) {
    LL(x, y);
    Point<ll> P(x, y);
    Point<Re> Q = projection<Re, ll, ll>(P, L);
    print(Q.x, Q.y);
  }
}

signed main() {
  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
