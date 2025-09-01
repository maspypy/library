#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "mod/modint.hpp"
#include "mod/dynamic_modint.hpp"
#include "poly/convolution.hpp"

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

template <typename mint>
void test_conv() {
  int N = RNG(1000, 10000);
  int M = RNG(1000, 10000);
  vc<mint> A(N), B(M);
  FOR(i, N) A[i] = RNG(0, u32(-1));
  FOR(i, M) B[i] = RNG(0, u32(-1));
  vc<mint> S(N + M - 1);
  FOR(i, N) FOR(j, M) { S[i + j] += A[i] * B[j]; }
  auto f = convolution_ntt(A, B);
  assert(S == f);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  {
    constexpr u32 mod = (u32(1) << 31) - 19;
    dmint::set_mod(mod);
    test<modint<mod>>();
    test<dmint>();
  }

  const u32 mod = 2013265921;
  dmint::set_mod(mod);
  dmint::set_ntt_info();
  FOR(10) test_conv<modint<2013265921>>();
  FOR(10) test_conv<dmint>();

  solve();
  return 0;
}