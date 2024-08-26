#define PROBLEM "https://atcoder.jp/contests/abc285/tasks/abc285_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/maxflow_with_lowerbound.hpp"

void solve() {
  INT(H, W);
  auto idx = [&](int x, int y) -> int { return W * x + y; };
  int s = idx(H, 0);
  int t = s + 1;
  MaxFlow_With_LowerBound<int> G(t + 1, s, t);
  VEC(string, A, H);
  auto isin = [&](int x, int y) -> bool { return (0 <= x && x < H && 0 <= y && y < W); };
  int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
  int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
  FOR(i, H) FOR(j, W) {
    if (A[i][j] == '2') {
      if ((i + j) % 2 == 0) G.add(s, idx(i, j), 1, 1);
      if ((i + j) % 2 == 1) G.add(idx(i, j), t, 1, 1);
    }
    elif (A[i][j] == '?') {
      if ((i + j) % 2 == 0) G.add(s, idx(i, j), 0, 1);
      if ((i + j) % 2 == 1) G.add(idx(i, j), t, 0, 1);
    }
    if ((i + j) % 2 == 0) {
      FOR(d, 4) {
        int ni = i + dx[d], nj = j + dy[d];
        if (!isin(ni, nj)) continue;
        G.add(idx(i, j), idx(ni, nj), 0, 1);
      }
    }
  }
  int F = G.flow();
  Yes(F != -1);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
