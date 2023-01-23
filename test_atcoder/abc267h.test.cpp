#define PROBLEM "https://atcoder.jp/contests/abc267/tasks/abc267_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/product_of_one_minus_xn.hpp"
#include "poly/product_of_one_plus_xn.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(int, A, N);

  auto f = product_of_one_plus_xn<mint>(A, M);
  auto g = product_of_one_minus_xn<mint>(A, M);
  print((f[M] - g[M]) / mint(2));
}

signed main() {
  solve();
  return 0;
}
