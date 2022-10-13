#define PROBLEM "https://yukicoder.me/problems/no/1962"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/sum_of_rationals.hpp"
#include "poly/coef_of_rational_fps.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  using poly = vc<mint>;
  vc<pair<poly, poly>> dat;
  FOR(X, 1, M + 1) {
    poly num(X), den(X + 1);
    FOR(i, 1, X) num[i] = mint(1);
    FOR(i, X) den[i] = mint(1);
    den[X] = mint(-1);
    dat.eb(num, den);
  }
  auto [f, g] = sum_of_rationals(dat);
  poly num = f;
  poly den = g;
  FOR(i, len(f)) den[i] -= f[i];
  mint ANS = coef_of_rational_fps<mint>(num, den, N);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
