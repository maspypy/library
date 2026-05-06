#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "mod/modint.hpp"
#include "poly/2d/fps_inv_2d.hpp"
#include "poly/2d/convolution2d.hpp"

using mint = modint998;

void test() {
  auto gen = [&](ll H, ll W) -> vvc<mint> {
    vv(mint, F, H, W);
    FOR(i, H) FOR(j, W) F[i][j] = RNG(mint::get_mod());
    if (F[0][0] == mint(0)) F[0][0] = mint(1);
    return F;
  };

  auto check = [&](ll H, ll W) -> void {
    auto F = gen(H, W);
    auto G = fps_inv_2d<mint>(F);
    auto C = convolution2d<mint>(F, G, true);

    FOR(i, H) FOR(j, W) {
      mint expected = (i == 0 && j == 0 ? mint(1) : mint(0));
      assert(C[i][j] == expected);
    }
  };

  FOR(H, 1, 20) FOR(W, 1, 20) { FOR(100) check(H, W); }

  FOR(100) {
    ll H = RNG(1, 500);
    ll W = RNG(1, 500);
    check(H, W);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}