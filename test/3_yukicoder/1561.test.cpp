#define PROBLEM "https://yukicoder.me/problems/no/1561"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/hashmap.hpp"
#include "random/hash_vector.hpp"
#include "mod/modint.hpp"
#include "other/connected_dp.hpp"
#include "seq/interpolate_linear_rec.hpp"

using mint = modint107;

void solve() {
  LL(H, W);
  auto [states, edges] = connected_dp_squares::connedted_dp_graph(H, true);
  int S = len(states);
  int LIM = 2 * S + 10;
  vc<mint> f(LIM);
  vc<mint> dp(S);
  dp[0] = mint(1);
  FOR(i, LIM) {
    vc<mint> newdp(S);
    for (auto&& [a, b]: edges) newdp[b] += dp[a];
    swap(dp, newdp);
    f[i] = dp[1];
  }
  mint ANS = interpolate_linear_rec(f, W, 0);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  solve();

  return 0;
}