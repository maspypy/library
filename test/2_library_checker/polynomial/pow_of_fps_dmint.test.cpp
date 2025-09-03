#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/dynamic_modint.hpp"
#include "poly/fps_pow.hpp"

using mint = modint998;

void solve() {
  using mint = dmint;
  mint::set_mod(998244353);
  LL(N, M);
  VEC(mint, A, N);
  print(fps_pow(A, M));
}

signed main() {
  solve();
  return 0;
}
