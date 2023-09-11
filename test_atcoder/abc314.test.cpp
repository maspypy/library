#define PROBLEM "https://atcoder.jp/contests/abc314/tasks/abc314_Ex"
#define ERROR 1e-5

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/base.hpp"
#include "geo/distance.hpp"
#include "geo/cross_point.hpp"

using Re = double;
using P = Point<Re>;
using S = Segment<Re>;

void solve() {
  LL(N);
  vc<P> A(N), B(N);
  FOR(i, N) read(A[i], B[i]);
  vc<S> seg;
  FOR(i, N) seg.eb(Segment<Re>(A[i], B[i]));

  auto ternary_search = [&](auto f, Re x1, Re x2) -> pair<Re, Re> {
    // 凸関数の最小化。pair (x, f(x)) を返す
    FOR(80) {
      Re xl = x1 * 0.55 + x2 * 0.45;
      Re xr = xl * 0.45 + x2 * 0.55;
      if (f(xl) < f(xr))
        x2 = xr;
      else
        x1 = xl;
    }
    return mp(x1, f(x1));
  };

  auto F = [&](Re x, Re y) -> Re {
    P p = {x, y};
    Re ma = 0.0;
    FOR(i, N) chmax(ma, distance<Re, Re, Re>(seg[i], p));
    return ma;
  };

  Re INF = 1e6;
  auto f = [&](Re y) -> Re {
    return ternary_search([&](Re x) -> Re { return F(x, y); }, -INF, INF).se;
  };

  Re ANS = ternary_search([&](Re y) -> Re { return f(y); }, -INF, INF).se;
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
