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
  auto f = [&](vc<int>& par, vc<int>& V, vc<int>& indptr) -> void {
    int N = len(par);
    vc<int> dist(N);
    FOR(i, 1, N) { dist[i] = dist[par[i]] + 1; }
    auto calc = [&](int L, int R, int sgn) -> void {
      int mx = *max_element(dist.begin() + L, dist.begin() + R);
      vi f(mx + 1);
      FOR(i, L, R) f[dist[i]]++;
      f = convolution(f, f);
      FOR(i, len(f)) ANS[i] += sgn * f[i];
    };
    calc(0, N, +1);
    FOR(k, 1, len(indptr) - 1) { calc(indptr[k], indptr[k + 1], -1); }
  };
  centroid_decomposition<0>(G, f);
  for (auto& x: ANS) x /= 2;
  ANS.erase(ANS.begin());
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
