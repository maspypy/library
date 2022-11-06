#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/convolution_all.hpp"

using mint = modint998;

void solve() {
  LL(N);
  vvc<mint> polys;
  FOR(N) {
    LL(d);
    VEC(mint, f, d + 1);
    polys.eb(f);
  }
  auto f = convolution_all(polys);
  print(f);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
