#define PROBLEM "https://yukicoder.me/problems/no/2907"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "nt/nimber/base.hpp"
#include "linalg/rank_for_all_column_subset.hpp"

using F = Nimber64;
using mint = modint998;

void solve() {
  LL(W, H);
  vv(F, A, H, W, F(0));
  FOR(x, H) FOR(y, W) {
    U64(w);
    A[x][y] = F(w - 1);
  }

  vc<int> R = rank_for_all_column_subset(A, H, W);
  ll N = W;
  mint ANS = 0;
  vc<mint> POW(N + 1);
  FOR(n, N + 1) POW[n] = mint(2).pow(64 * n);
  FOR(s, 1 << N) {
    ll r = R[s];
    ll n = popcnt(s) - r;
    mint x = POW[n];
    if ((N - popcnt(s)) % 2 == 0) {
      ANS += x;
    } else {
      ANS -= x;
    }
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}