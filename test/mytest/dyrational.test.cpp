#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"

#include "game/dyrational.hpp"

void test() {
  using X = DyRational<ll>;
  // 足し
  assert(X(1) + X(2) == X(3));
  assert(X(-3) + X(2) == X(-1));
  assert(X(-3) + X(3) == X(0));
  assert(X(3, 3) + X(1, 1) == X(7, 3));
  assert(X(3, 3) + X(3, 3) == X(3, 2));
  assert(X(3, 3) + X(-3, 3) == X(0, 0));
  assert(X(2, 3) + X(-1, 2) == X(0, 0));
  // 引き
  assert(X(1) - X(2) == X(-1));
  assert(X(-3) - X(2) == X(-5));
  assert(X(-3) - X(3) == X(-6));
  assert(X(3, 3) - X(1, 1) == X(-1, 3));
  assert(X(3, 3) - X(3, 3) == X(0, 0));
  assert(X(3, 3) - X(-3, 3) == X(3, 2));
  assert(X(2, 3) - X(-1, 2) == X(1, 1));
  // 不等号
  assert(X(1) < X(2));
  assert(X(-3) < X(2));
  assert(X(-3) < X(3));
  assert(X(3, 3) < X(1, 1));
  assert(X(3, 3) == X(3, 3));
  assert(X(3, 3) > X(-3, 3));
  assert(X(2, 3) > X(-1, 2));
  // {x|y}
  assert(X::find(X(1), X(2)) == X(3, 1));
  assert(X::find(X(-3), X(0)) == X(-1));
  assert(X::find(X(1), X(5)) == X(2));
  assert(X::find(X(-3), X(1)) == X(0));
  assert(X::find(X(9, 4), X(5, 3)) == X(19, 5));
  assert(X::find(X(1, 1), X(2, 0)) == X(1));
  assert(X::find(X(1, 3), X(5, 3)) == X(1, 1));
  assert(X::find(X(-91, 6), X(-41, 5)) == X(-11, 3));
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