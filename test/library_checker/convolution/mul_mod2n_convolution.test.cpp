#define PROBLEM "https://judge.yosupo.jp/problem/mul_mod2n_convolution"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "nt/multiplicative_convolution_mod2n.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, A, 1 << N);
  VEC(mint, B, 1 << N);
  auto C = multiplicative_convolution_mod2n(A, B);
  print(C);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
