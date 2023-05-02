#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/fps_pow.hpp"

using mint = modint998;

void test() {
  vv(mint, f, 9, 9);
  f[0][0] = f[0][1] = f[1][0] = mint(1);
  f[1][2] = f[2][1] = f[2][2] = mint(1);
  f = fps_pow_1_sparse_2d<mint>(f, 4);
  assert(f[0] == vc<mint>({1, 4, 6, 4, 1, 0, 0, 0, 0}));
  assert(f[1] == vc<mint>({4, 12, 16, 16, 12, 4, 0, 0, 0}));
  assert(f[2] == vc<mint>({6, 16, 34, 48, 34, 16, 6, 0, 0}));
  assert(f[3] == vc<mint>({4, 16, 48, 60, 60, 48, 16, 4, 0}));
  assert(f[4] == vc<mint>({1, 12, 34, 60, 90, 60, 34, 12, 1}));
  assert(f[5] == vc<mint>({0, 4, 16, 48, 60, 60, 48, 16, 4}));
  assert(f[6] == vc<mint>({0, 0, 6, 16, 34, 48, 34, 16, 6}));
  assert(f[7] == vc<mint>({0, 0, 0, 4, 12, 16, 16, 12, 4}));
  assert(f[8] == vc<mint>({0, 0, 0, 0, 1, 4, 6, 4, 1}));
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}
