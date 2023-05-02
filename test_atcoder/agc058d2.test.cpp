#define PROBLEM "https://atcoder.jp/contests/agc058/tasks/agc058_d"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution.hpp"
#include "poly/multipoint.hpp"
#include "mod/primitive_root.hpp"
#include "poly/fps_div.hpp"
#include "poly/coef_of_rational_fps.hpp"
#include "poly/poly_divmod.hpp"

using mint = modint998;

void solve() {
  LL(A, B, C);
  ll N = A + B + C;

  ll LIM = (A + B + C) / 3 + 5;

  mint r = primitive_root(mint::get_mod());
  mint pow = 1;
  vc<mint> Y(LIM);
  FOR(i, LIM) {
    vc<mint> num = {mint(3), mint(-1), mint(0)};
    vc<mint> den = {mint(1), mint(-1), mint(0), mint(2) * pow};
    Y[i] = inv<mint>(2) * coef_of_rational_fps(num, den, N);
    pow *= r;
  }

  auto f = multipoint_interpolate_on_geom_seq(Y, mint(1), r);
  f[0] = mint(1);

  mint ANS = 0;

  FOR(t, len(f)) {
    ll a = A - t, b = B - t, c = C - t;
    if (min({a, b, c}) < 0) break;
    mint cf = fact<mint>(a + b + c) * fact_inv<mint>(a) * fact_inv<mint>(b)
              * fact_inv<mint>(c);
    ANS += f[t] * cf;
  }
  print(ANS);
}

signed main() {
  solve();

  return 0;
}