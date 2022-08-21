#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/incremental_convexhull.hpp"

// geocon2013 c sample より
void test() {
  {
    Incremental_ConvexHull<ll> X;
    assert(X.area_2() == 0);
    assert(X.side(Point<ll>(2, 2)) == -1);
    assert(X.side(Point<ll>(1, 2)) == -1);
    assert(X.side(Point<ll>(1, 1)) == -1);
    assert(X.side(Point<ll>(2, 1)) == -1);
    X.add(Point<ll>(1, 1));
    assert(X.side(Point<ll>(2, 2)) == -1);
    assert(X.side(Point<ll>(1, 2)) == -1);
    assert(X.side(Point<ll>(1, 1)) == 0);
    assert(X.side(Point<ll>(2, 1)) == -1);
    X.add(Point<ll>(5, 1));
    assert(X.area_2() == 0);
    assert(X.side(Point<ll>(2, 2)) == -1);
    assert(X.side(Point<ll>(1, 2)) == -1);
    assert(X.side(Point<ll>(1, 1)) == 0);
    assert(X.side(Point<ll>(2, 1)) == 0);
    X.add(Point<ll>(1, 5));
    assert(X.area_2() == 16);
    assert(X.side(Point<ll>(2, 2)) == 1);
    assert(X.side(Point<ll>(1, 2)) == 0);
    assert(X.side(Point<ll>(1, 1)) == 0);
    assert(X.side(Point<ll>(2, 1)) == 0);
  }
  {
    Incremental_ConvexHull<ll> X;
    X.add(Point<ll>(2, 1));
    X.add(Point<ll>(4, 1));
    X.add(Point<ll>(6, 1));
    assert(X.side(Point<ll>(1, 1)) == -1);
    assert(X.side(Point<ll>(3, 1)) == 0);
    assert(X.side(Point<ll>(5, 1)) == 0);
    assert(X.side(Point<ll>(7, 1)) == -1);
  }
}

void solve() {
  LL(A, B);
  print(A + B);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
