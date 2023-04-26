#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/dynamic_modint.hpp"
#include "poly/convolution.hpp"

using mint = dmint;

void solve() {
  mint::set_mod(998244353);
  // mint::set_ntt_info();

  LL(N, M);
  VEC(mint, A, N);
  VEC(mint, B, M);
  auto ANS = convolution(A, B);
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
