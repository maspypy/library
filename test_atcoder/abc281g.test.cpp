#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/dynamic_modint.hpp"
#include "mod/powertable.hpp"
#include "poly/sum_of_rationals.hpp"
#include "poly/fps_div.hpp"

using mint = dmint;
 
void solve() {
  LL(N, mod);
  mint::set_mod(mod);
  auto POW = powertable_1<mint>(mint(2), N * N + 10);
 
  // 一応 o(N^3) を実装するか
 
  vv(mint, dp, N, N);
  FOR(i, N) dp[i][i] += POW[i * (i - 1) / 2];
 
  FOR(n, N) {
    vc<mint> f = dp[n];
    f.resize(n + 1);
    vc<mint> g(N - n);
    /*
    FOR(i, n + 1) {
      FOR(j, 1, N - n) { g[j] += f[i] * (POW[i] - mint(1)).pow(j); }
    }
    */
    // 結局、sum f[i]/1-ax の形
    using poly = vc<mint>;
    vc<pair<poly, poly>> rationals;
    FOR(i, n + 1) {
      if (f[i] == mint(0)) continue;
      poly F = {f[i]};
      poly G = {mint(1), mint(1) - POW[i]};
      rationals.eb(F, G);
    }
    auto [F, G] = sum_of_rationals<mint>(rationals);
    F.resize(N - n), G.resize(N - n);
    g = fps_div(F, G);
 
    FOR(j, 1, N - n) {
      dp[n + j][j] += g[j] * C<mint, 0, true>(n + j, j) * POW[j * (j - 1) / 2];
    }
  }
  mint ANS = 0;
  FOR(i, 1, N) ANS += dp[N - 2][i] * (POW[i] - mint(1));
  print(ANS);
}
 
signed main() {
  solve();
  return 0;
}
