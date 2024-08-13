#define PROBLEM "https://atcoder.jp/contests/arc133/tasks/arc133_f"

#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/composition_f_a_plus_bx_div_c_plus_dx.hpp"
#include "poly/composition_f_a_plus_bx.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  vc<mint> f(N + 1);
  FOR(i, N + 1) {
    U32(x);
    f[i] = x;
  }

  f = composition_f_a_plus_bx_div_c_plus_dx<mint, true>(f, 1, -1, 1, 1);
  FOR(i, N + 1) f[i] *= mint(N - i - i).pow(K);
  f = composition_f_a_plus_bx_div_c_plus_dx<mint, true>(f, 0, 1, 2, -1);
  f = composition_f_a_plus_bx<mint>(f, 1, -1);
  mint sm = SUM<mint>(f);
  mint cf = mint(1) / sm;
  for (auto&& x: f) x *= cf;
  print(f);
}

signed main() {
  solve();
  return 0;
}
