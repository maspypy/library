#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"

#include "game/dyadic_rational.hpp"

void test() {
  using X = Dyadic_Rational<ll>;
  // 足し
  assert(X(1) + X(2) == X(3));
  assert(X(-3) + X(2) == X(-1));
  assert(X(-3) + X(3) == X(0));
  assert(X(3, 8) + X(1, 2) == X(7, 8));
  assert(X(3, 8) + X(3, 8) == X(3, 4));
  assert(X(3, 8) + X(-3, 8) == X(0));
  assert(X(2, 8) + X(-1, 4) == X(0));
  // 引き
  assert(X(1) - X(2) == X(-1));
  assert(X(-3) - X(2) == X(-5));
  assert(X(-3) - X(3) == X(-6));
  assert(X(3, 8) - X(1, 2) == X(-1, 8));
  assert(X(3, 8) - X(3, 8) == X(0, 1));
  assert(X(3, 8) - X(-3, 8) == X(3, 4));
  assert(X(2, 8) - X(-1, 4) == X(1, 2));
  // 不等号
  assert(X(1) < X(2));
  assert(X(-3) < X(2));
  assert(X(-3) < X(3));
  assert(X(3, 8) < X(1, 2));
  assert(X(3, 8) == X(3, 8));
  assert(X(3, 8) > X(-3, 8));
  assert(X(2, 8) > X(-1, 4));
  // {x|y}
  assert(X::simplest(X(1), X(2)) == X(3, 2));
  assert(X::simplest(X(-3), X(0)) == X(-1));
  assert(X::simplest(X(1), X(5)) == X(2));
  assert(X::simplest(X(-3), X(1)) == X(0));
  assert(X::simplest(X(9, 16), X(5, 8)) == X(19, 32));
  assert(X::simplest(X(1, 2), X(2, 1)) == X(1));
  assert(X::simplest(X(1, 8), X(5, 8)) == X(1, 2));
  assert(X::simplest(X(-91, 64), X(-41, 32)) == X(-11, 8));
  assert(X::simplest(X(-3, 2), X(-1, 1)) == X(-5, 4));
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  test();

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}