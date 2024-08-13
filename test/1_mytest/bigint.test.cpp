#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "bigint/base.hpp"
#include "bigint/binary.hpp"
#include "random/base.hpp"

template <typename B>
void test() {
  int x = 0, y = 0;
  B X(x), Y(y);
  FOR(100) {
    FOR(1000) {
      int a = RNG(-3, 4);
      int b = RNG(-3, 4);
      if (RNG(0, 2)) {
        x += a, y += b;
        X += a, Y += b;
      } else {
        x -= a, y -= b;
        X -= a, Y -= b;
      }
      assert(X == B(x) && Y == B(y));
      assert((x == y) == (X == Y));
      assert((x != y) == (X != Y));
      assert((x < y) == (X < Y));
      assert((x <= y) == (X <= Y));
      assert((x > y) == (X > Y));
      assert((x >= y) == (X >= Y));
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}

signed main() {
  test<BigInteger>();
  test<BigInteger_Binary>();
  solve();
  return 0;
}