#define PROBLEM "https://judge.yosupo.jp/problem/factorial"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/prefix_product_of_poly.hpp"

using mint = modint998;

void solve() {
  INT(N);
  vc<mint> f = {1, 1};
  mint ans = prefix_product_of_poly(f, N);
  print(ans);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
