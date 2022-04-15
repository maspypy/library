#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_large"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/convolution_huge.hpp"
using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, A, N);
  VEC(mint, B, M);
  print(convolution_huge(A, B));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
