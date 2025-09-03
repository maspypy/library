#define PROBLEM "https://yukicoder.me/problems/no/1069"
#define ERROR 0.001
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/shortest_path/K_shortest_path.hpp"

void solve() {
  using Re = double;
  LL(N, M, K);
  LL(s, t);
  --s, --t;
  VEC(pi, P, N);
  Graph<double, 1> G(N);
  FOR(M) {
    LL(i, j);
    --i, --j;
    auto [xi, yi] = P[i];
    auto [xj, yj] = P[j];
    Re dx = xi - xj, dy = yi - yj;
    Re d = sqrt(dx * dx + dy * dy);
    G.add(i, j, d);
    G.add(j, i, d);
  }
  G.build();
  auto res = K_shortest_path<double>(G, s, t, K);
  for (auto&& [x, vs, es]: res) print(x);
  FOR(K - len(res)) print(-1);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
