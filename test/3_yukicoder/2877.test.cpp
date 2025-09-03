#define PROBLEM "https://yukicoder.me/problems/no/2877"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/multipoint.hpp"
#include "mod/primitive_root.hpp"
#include "mod/modint.hpp"
#include "seq/interpolate_linear_rec.hpp"

using mint = modint998;

void solve() {
  LL(N, H);
  mint r = primitive_root(mint::get_mod());
  mint x = 1;
  vc<mint> Y(N + 1);

  FOR(p, N + 1) {
    vc<mint> dp = {mint(2) * inv<mint>(5), mint(2) * inv<mint>(5) * x, inv<mint>(5) * x};
    vc<mint> A;
    vc<tuple<int, int, mint>> tr;
    tr.eb(0, 0, inv<mint>(2));
    tr.eb(0, 1, inv<mint>(2) * x);

    tr.eb(1, 0, inv<mint>(3));
    tr.eb(1, 1, inv<mint>(3) * x);
    tr.eb(1, 2, inv<mint>(3) * x);

    tr.eb(2, 1, inv<mint>(3) * mint(2) * x);
    tr.eb(2, 2, inv<mint>(3) * x);
    FOR(7) {
      A.eb(SUM<mint>(dp));
      vc<mint> newdp(3);
      for (auto& [a, b, c]: tr) newdp[b] += dp[a] * c;
      swap(dp, newdp);
    }
    Y[p] = interpolate_linear_rec<mint>(A, N - 1, 0);
    x *= r;
  }

  vc<mint> F = multipoint_interpolate_on_geom_seq<mint>(Y, 1, r);

  mint ANS = 0;
  FOR(i, H, N + 1) ANS += F[i];
  // print(F);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
