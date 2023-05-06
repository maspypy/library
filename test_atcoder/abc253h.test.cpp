#define PROBLEM "https://atcoder.jp/contests/abc253/tasks/abc253_Ex"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/sps_exp.hpp"
#include "setfunc/transposed_sps_composition.hpp"

const int LIM = 14;
using mint = modint998;

void solve() {
  LL(N, M);

  vv(int, mat, N, N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    mat[a][b]++, mat[b][a]++;
  }

  // count tree
  vc<mint> dp(1 << N);
  dp[0] = 0;
  FOR(i, N) {
    vc<mint> a = {dp.begin(), dp.begin() + (1 << i)};
    FOR(s, 1 << i) {
      int k = 0;
      FOR(j, i) if (s >> j & 1) k += mat[i][j];
      a[s] *= mint(k);
    }
    a = sps_exp<mint, LIM>(i, a);
    copy(all(a), dp.begin() + (1 << i));
  }

  vc<mint> x(1 << N);
  x.back() = mint(1);
  auto y = transposed_sps_composition_egf<mint, LIM>(N, dp, x);

  FOR(k, 1, N) {
    // k edges = N-k component
    mint ans = y[N - k];
    ans *= inv<mint>(M).pow(k) * fact<mint>(k);
    print(ans);
  }
}

signed main() {
  solve();
  return 0;
}