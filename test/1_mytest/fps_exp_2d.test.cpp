#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "mod/modint.hpp"
#include "poly/2d/fps_exp_2d.hpp"
#include "poly/2d/fps_log_2d.hpp"
#include "poly/2d/convolution2d.hpp"

using mint = modint998;

void test() {
  auto gen = [&](ll H, ll W) -> vvc<mint> {
    vv(mint, F, H, W);
    FOR(i, H) FOR(j, W) F[i][j] = RNG(mint::get_mod());
    F[0][0] = mint(0);
    return F;
  };

  auto check = [&](ll H, ll W) -> void {
    {
      auto F = gen(H, W);
      auto G = fps_exp_2d<mint>(F);
      auto L = fps_log_2d<mint>(G);
      assert(L == F);
    }
    {
      auto F = gen(H, W);
      auto G = fps_exp_2d<mint>(F);

      vv(mint, DF, H - 1, W);
      vv(mint, DG, H - 1, W);
      FOR(i, H - 1) FOR(j, W) {
        DF[i][j] = F[i + 1][j] * mint(i + 1);
        DG[i][j] = G[i + 1][j] * mint(i + 1);
      }
      G.resize(H - 1);
      auto RHS = convolution2d<mint>(G, DF, true);
      assert(DG == RHS);
    }
  };

  FOR(H, 1, 20) FOR(W, 1, 20) { FOR(10) check(H, W); }

  FOR(10) {
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