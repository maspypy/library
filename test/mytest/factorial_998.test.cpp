#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"

#include "mod/factorial998.hpp"
#include "poly/prefix_product_of_poly.hpp"

using mint = modint998;

void test() {
  FOR(10) {
    int x = RNG(0, mint::get_mod());
    // int x = t;
    int a = factorial998(x);
    vc<mint> f = {1, 1};
    int b = prefix_product_of_poly(f, x).val;
    assert(a == b);
  }
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
