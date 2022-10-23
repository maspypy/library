#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
using mint = modint998;

void test() {
  assert(fact_invs<mint>() == mint(1));
  assert(fact_invs<mint>(3) == mint(6).inverse());
  assert(fact_invs<mint>(3, 4, 5) == mint(6 * 24 * 120).inverse());

  assert(multinomial<mint>(10, 10) == mint(1));
  assert(multinomial<mint>(10, 2, 8) == mint(45));
  assert(multinomial<mint>(10, 2, 3, 5) == mint(2520));
  assert(multinomial<mint>(10, 1, 2, 3, 4) == mint(12600));
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
