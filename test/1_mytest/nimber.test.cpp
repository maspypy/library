#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "nt/nimber/base.hpp"
#include "nt/nimber/solve_quadratic.hpp"

template <typename U>
void test() {
  using F = Nimber<U>;
  auto test = [&](F x) -> void {
    assert(x * x == x.square());
    assert(x.sqrt().square() == x);
    if (x != F(0)) assert(x * x.inverse() == F(1));
  };
  FOR(i, 1 << 20) { test(i); }
  FOR(10000) { test(F(RNG_64())); }

  auto test_q = [&](F a, F x) -> void {
    F b = x * x + a * x;
    vc<F> ANS = solve_quadratic(a, b);
    for (auto& z: ANS) { assert(z * z + a * z == b); }
    FOR(j, len(ANS)) FOR(i, j) { assert(ANS[i] != ANS[j]); }
    int exist = 0;
    FOR(i, len(ANS)) exist += (ANS[i] == x);
    assert(exist == 1);
  };
  // quadratic
  FOR(a, 100) {
    FOR(x, 100) { test_q(a, x); }
  }
  FOR(10000) { test_q(F(RNG_64()), F(RNG_64())); }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test<u16>();
  test<u32>();
  test<u64>();
  solve();
}