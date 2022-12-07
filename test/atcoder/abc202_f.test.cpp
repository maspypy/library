#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/count_points_in_triangles.hpp"
#include "geo/angle_sort.hpp"
#include "mod/modint.hpp"
#include "mod/powertable.hpp"

using mint = modint107;

void solve() {
  LL(N);
  using P = Point<ll>;
  VEC(P, A, N);
  Count_Points_In_Triangles X(A, A);

  vc<P> vecs;
  FOR(i, N) FOR(j, N) vecs.eb(A[j] - A[i]);
  auto I = angle_argsort(vecs);

  vc<pair<int, int>> IJ;
  for (auto&& k: I) {
    auto [i, j] = divmod(k, N);
    if (i != j) IJ.eb(i, j);
  }
  vc<mint> POW = powertable_1<mint>(2, N);

  mint ANS = 0;
  FOR(s, N) {
    vv(mint, dp, 2, N);
    dp[0][s] = 1;
    for (auto&& [i, j]: IJ) {
      ll area = (A[i] - A[s]).det(A[j] - A[s]);
      FOR(sgn, 2) {
        ll t = (sgn + area) & 1;
        int cnt = X.query(s, i, j);
        dp[t][j] += POW[cnt] * dp[sgn][i];
      }
    }
    ANS += dp[0][s];
  }
  // 1 角形
  ANS -= mint(N);
  // 2 角形
  ANS -= mint(N * (N - 1) / 2);
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
