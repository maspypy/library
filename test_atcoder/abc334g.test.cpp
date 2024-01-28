#define PROBLEM "https://atcoder.jp/contests/abc334/tasks/abc334_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/ds/remove_one_vertex_connectivity.hpp"

using mint = modint998;

void solve() {
  LL(H, W);
  VEC(string, S, H);
  vv(int, IDX, H, W, -1);
  int p = 0;
  FOR(x, H) FOR(y, W) {
    if (S[x][y] == '#') { IDX[x][y] = p++; }
  }

  auto isin = [&](int x, int y) -> bool {
    return (0 <= x && x < H && 0 <= y && y < W && S[x][y] == '#');
  };
  int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
  int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

  Graph<int, 0> G(p);
  FOR(x, H) FOR(y, W) {
    FOR(d, 2) {
      int nx = x + dx[d], ny = y + dy[d];
      if (!isin(x, y)) continue;
      if (!isin(nx, ny)) continue;
      G.add(IDX[x][y], IDX[nx][ny]);
    }
  }
  G.build();

  Remove_One_Vertex_Connectivity X(G);
  mint ans = 0;
  FOR(v, p) { ans += X.n_comp(v); }
  ans /= mint(p);
  print(ans);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
