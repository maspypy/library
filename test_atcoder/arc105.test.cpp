#define PROBLEM "https://atcoder.jp/contests/arc105/tasks/arc105_f"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/zeta.hpp"
#include "setfunc/subset_convolution.hpp"
#include "setfunc/sps_log.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  vv(bool, mat, N, N);
  vc<int> f(1 << N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    f[(1 << a) | (1 << b)]++;
  }
  subset_zeta(f);

  vc<mint> F(1 << N);
  FOR(s, 1 << N) F[s] = inv<mint>(2).pow(f[s]);
  F = subset_convolution_square<mint, 17>(F);
  FOR(s, 1 << N) F[s] *= mint(2).pow(f[s]);
  F = sps_log<mint, 17>(N, F);
  print(F.back() * inv<mint>(2));
}

signed main() {
  solve();
  return 0;
}