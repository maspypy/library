#define PROBLEM \
  "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/centroid_decomposition.hpp"
#include "poly/convolution.hpp"

void solve() {
  LL(N);
  Graph<int> G(N);
  G.read_tree(0, 0);
  vi ANS(N);
  auto f = [&](vc<int>& par, vc<int>& V, vc<int>& color) -> void {
    int N = len(par);
    vc<int> dist(N);
    FOR(i, 1, N) { dist[i] = dist[par[i]] + 1; }
    FOR(p, 3) {
      vi f(N), g(N);
      FOR(i, N) {
        if (color[i] == p) f[dist[i]]++;
        if (color[i] > p) g[dist[i]]++;
      }
      while (len(f) && f.back() == 0) POP(f);
      while (len(g) && g.back() == 0) POP(g);
      f = convolution(f, g);
      FOR(i, len(f)) ANS[i] += f[i];
    }
  };
  centroid_decomposition<2>(G, f);
  ANS.erase(ANS.begin());
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
