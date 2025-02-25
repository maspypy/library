#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modfast.hpp"
#include "random/base.hpp"
#include "mod/modint.hpp"

using mint = modint998;

template <typename mint>
void test() {
  constexpr u32 mod = mint::get_mod();
  ModFast<mod> fast;

  FOR(1 << 20) {
    mint x = RNG(1, mod);
    mint y = fast.inverse(x.val);
    assert(x * y == 1);
  }

  FOR(1 << 20) {
    mint x = RNG(1, mod);
    int exp = RNG(0, mod);
    mint y = fast.pow(x.val, exp);
    assert(x.pow(exp) == y);
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
  solve();
}