#define PROBLEM "https://yukicoder.me/problems/no/1776"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/find_path_through_specified.hpp"

void solve() {
  LL(N, M);
  INT(X, Y, Z);
  --X, --Y, --Z;
  vv(bool, can, N, N, 1);
  FOR(M) {
    LL(a, b);
    --a, --b;
    can[a][b] = can[b][a] = 0;
  }

  vc<int> path = {X};
  while (1) {
    vc<int> done(N);
    FOR(i, 1, len(path) - 1) { done[path[i]] = 1; }
    Graph<int, 0> G(N);
    FOR(b, N) FOR(a, b) {
      if (!can[a][b] || done[a] || done[b]) continue;
      G.add(a, b);
    }
    int s = path.back(), t = X;
    vc<int> need;
    for (auto& y: {Y, Z}) {
      if (y == s || y == t || done[y]) continue;
      need.eb(y);
    }
    auto [L, nxt] = find_path_through_specified(G, s, t, need);
    if (L == -1) return print(-1);
    path.eb(nxt);
    if (nxt == X) break;
  }

  for (auto& x: path) ++x;
  print(len(path) - 1);
  print(path);
}

signed main() {
  solve();
  return 0;
}
