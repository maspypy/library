#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "mod/dynamic_modint.hpp"
#include "random/base.hpp"
#include "mod/O1_inverse.hpp"

template <typename mint>
void test() {
  FOR(10000000) {
    int x = RNG(1, mint::get_mod());
    mint v = O1_inverse<mint>(x);
    mint prd = v * mint::raw(x);
    assert(prd == mint(1));
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test<modint998>();
  test<modint107>();
  dmint::set_mod(998244353);
  test<dmint>();
  dmint::set_mod(2);
  test<dmint>();
  dmint::set_mod(3);
  test<dmint>();
  dmint::set_mod(5);
  test<dmint>();
  dmint::set_mod(1'000'003);
  test<dmint>();
  dmint::set_mod(1'048'573);
  test<dmint>();
  dmint::set_mod(1'048'583);
  test<dmint>();
  dmint::set_mod(2097143);
  test<dmint>();
  dmint::set_mod(2097169);
  test<dmint>();
  solve();
}
