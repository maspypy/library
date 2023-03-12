#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution.hpp"
#include "mod/dynamic_modint.hpp"
using mint = dmint;

void solve() {
  LL(N, M);
  mint::set_mod(1'000'000'007);
  VEC(mint, A, N);
  VEC(mint, B, M);
  auto ANS = convolution(A, B);
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
