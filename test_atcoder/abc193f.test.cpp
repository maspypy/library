#define PROBLEM "https://atcoder.jp/contests/abc193/tasks/abc193_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/binary_optimization.hpp"

void solve() {
  LL(N);
  VEC(string, G, N);
  const int INF = infty<int>;
  Binary_Optimization<ll, 0> X(N * N);
  auto idx = [&](int i, int j) -> int { return N * i + j; };

  FOR(i, N) FOR(j, N) {
    int sgn = (i + j) % 2;
    if (G[i][j] == 'B' && sgn == 0) X.add_1(idx(i, j), -INF, 0);
    if (G[i][j] == 'W' && sgn == 1) X.add_1(idx(i, j), -INF, 0);
    if (G[i][j] == 'B' && sgn == 1) X.add_1(idx(i, j), 0, -INF);
    if (G[i][j] == 'W' && sgn == 0) X.add_1(idx(i, j), 0, -INF);
  }

  int dx[] = {0, 1};
  int dy[] = {1, 0};

  FOR(x, N) FOR(y, N) {
    FOR(d, 2) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx >= N || ny >= N) continue;
      int a = idx(x, y), b = idx(nx, ny);
      X.add_2(a, b, 1, 0, 0, 1);
    }
  }

  ll ANS = X.calc().fi;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}