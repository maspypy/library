#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "mod/modint.hpp"
#include "mod/dynamic_modint.hpp"

template <typename mint>
void test() {
  const u32 mod = mint::get_mod();
  auto check = [&](ll x, ll y) -> void {
    mint mx = x, my = y;
    assert((x + y) % mod == (mx + my).val);
    assert((x + mod - y) % mod == (mx - my).val);
    assert((x * y) % mod == (mx * my).val);
    mint mz = mx / my;
    ll z = mz.val;
    assert(y * z % mod == x);
  };
  FOR(10000) {
    ll x = RNG(0, mint::get_mod());
    ll y = RNG(0, mint::get_mod());
    check(x, y);
  }
  FOR(i, 1, 100) FOR(j, 1, 100) { check(mod - i, mod - j); }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  constexpr u32 mod = (u32(1) << 31) - 19;
  using dmint = Dynamic_Modint;
  dmint::set_mod(mod);
  test<modint<mod>>();
  test<dmint>();

  solve();
  return 0;
}