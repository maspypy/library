#define PROBLEM "https://yukicoder.me/problems/no/2097"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/product_of_f_rk_x.hpp"

using mint = modint998;
using poly = vc<mint>;

void solve() {
  LL(N, M, L);
  mint p = inv<mint>(2).pow(N);
  poly f(L + 1);
  f[0] = mint(1);
  FOR(i, 1, L + 1) f[i] = fact_inv<mint>(i) * p;
  f = product_of_f_rk_x(f, mint(2), M);
  FOR(i, L + 1) f[i] *= fact<mint>(i);

  mint cf = mint(2).pow(N * M);
  for (auto&& x: f) x *= cf;
  FOR(i, 1, L + 1) print(f[i]);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
