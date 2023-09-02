#include "graph/base.hpp"

// 無向グラフから C4 をひとつ見つける
// https://codeforces.com/problemset/problem/1468/M
template <typename GT>
tuple<int, int, int, int> find_C4(GT& G) {
  assert(!G.is_directed());
  int N = G.N;
  auto deg = G.deg_array();
  auto I = argsort(deg);
  reverse(all(I));
  vc<int> rk(N);
  FOR(i, N) rk[I[i]] = i;

  // 遷移先を降順に並べる
  vvc<int> TO(N);
  for (auto&& e: G.edges) {
    int a = rk[e.frm], b = rk[e.to];
    TO[a].eb(b);
    TO[b].eb(a);
  }
  FOR(v, N) {
    sort(all(TO[v]));
    reverse(all(TO[v]));
  }
  vc<int> par(N, -1);
  FOR(a, N) {
    for (auto&& b: TO[a]) TO[b].pop_back();
    for (auto&& b: TO[a]) {
      for (auto&& c: TO[b]) {
        if (par[c] != -1) { return {I[a], I[b], I[c], I[par[c]]}; }
        par[c] = b;
      }
    }
    for (auto&& b: TO[a]) {
      for (auto&& c: TO[b]) { par[c] = -1; }
    }
  }
  return {-1, -1, -1, -1};
}
