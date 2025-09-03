#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/base.hpp"

void solve() {
  LL(Q);
  FOR(Q) {
    LL(a, b, c, d);
    Line<ll> A(a, b, c, d);
    LL(e, f, g, h);
    Line<ll> B(e, f, g, h);
    bool p = A.is_parallel(B);
    bool o = A.is_orthogonal(B);
    if (p) print(2);
    elif (o) print(1);
    else print(0);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
