#define PROBLEM "https://atcoder.jp/contests/abc314/tasks/abc314_Ex"
#define ERROR 1e-5

#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/base.hpp"
#include "geo/distance.hpp"
#include "geo/cross_point.hpp"
#include "other/golden_search.hpp"

using Re = double;
using P = Point<Re>;
using S = Segment<Re>;

void solve() {
  LL(N);
  vc<P> A(N), B(N);
  FOR(i, N) read(A[i], B[i]);
  vc<S> seg;
  FOR(i, N) seg.eb(Segment<Re>(A[i], B[i]));

  auto F = [&](Re x, Re y) -> Re {
    P p = {x, y};
    Re ma = 0.0;
    FOR(i, N) chmax(ma, distance<Re, Re, Re>(seg[i], p));
    return ma;
  };

  Re INF = 1e6;
  auto f = [&](Re y) -> Re {
    return golden_search<Re, true>([&](Re x) -> Re { return F(x, y); }, -INF,
                                   INF)
        .fi;
  };

  Re ANS
      = golden_search<Re, true>([&](Re y) -> Re { return f(y); }, -INF, INF).fi;
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
