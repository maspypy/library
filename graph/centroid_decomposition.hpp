#include "graph/base.hpp"
#include "graph/to_directed_tree.hpp"
#include "graph/toposort.hpp"

/*
https://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d
1/3 CD のみ扱う
centroid_decomposition_1：長さ 2 以上のパス全体
centroid_decomposition_2：real, virtual フラグを持って長さ 1 以上のパス
*/

template <typename GT, typename F>
void centroid_decomposition_1_dfs(GT& G, vc<int> vs, F f) {
  const int N = G.N;
  assert(N > 1);
  if (N == 2) return;
  vc<int> sz(N, 1), par(N, -1);
  FOR_R(i, N) {
    for (auto& e: G[i]) sz[i] += sz[e.to], par[e.to] = i;
  }
  int c = -1;
  FOR_R(i, N) {
    if (sz[i] >= ceil<int>(N, 2)) {
      c = i;
      break;
    }
  }
  vc<int> color(N, -1);
  int take = 0;
  vc<int> ord(N, -1);
  ord[c] = 0;
  int p = 1;
  for (auto& e: G[c]) {
    if (take + sz[e.to] <= floor<int>(N - 1, 2)) {
      color[e.to] = 0, ord[e.to] = p++, take += sz[e.to];
    }
  }
  FOR(i, N) {
    if (color[i] == 0) {
      for (auto& e: G[i]) { color[e.to] = 0, ord[e.to] = p++; }
    }
  }
  int n1 = p - 1;
  int a = c;
  while (1) {
    a = par[a];
    if (a == -1) break;
    color[a] = 1, ord[a] = p++;
  }
  FOR(i, N) {
    if (i != c && color[i] == -1) color[i] = 1, ord[i] = p++;
  }
  assert(p == N);
  int n2 = N - 1 - n1;
  using WT = typename GT::cost_type;
  Graph<WT, true> H1(n1 + 1), H2(n2 + 1), H(N);
  vc<int> V1(n1 + 1), V2(n2 + 1), V(N);
  V1[0] = V2[0] = V[0] = c;
  FOR(v, N) {
    int i = ord[v];
    V[i] = vs[v];
    (i <= n1 ? V1[i] : V2[i - n1]) = vs[v];
  }
  for (auto& e: G.edges) {
    int a = ord[e.frm], b = ord[e.to];
    if (a > b) swap(a, b);
    H.add(a, b, e.cost, e.id);
    if (b <= n1) {
      H1.add(a, b, e.cost, e.id);
    } else {
      H2.add(max(a - n1, 0), b - n1, e.cost, e.id);
    }
  }
  H.build(), H1.build(), H2.build();
  f(H, V, n1, n2);
  centroid_decomposition_1_dfs(H1, V1, f);
  centroid_decomposition_1_dfs(H2, V2, f);
}

// 長さ 1 のパスは別処理することに注意
// 長さ 2 以上のパスすべてに対する計算をしたい
// f(G, V, n1, n2)
// G: oriented
// V: label in original tree, dfs order
// color=1: V[1:1+n1]
// color=2: V[1+n1:1+n1+n2]
template <typename GT, typename F>
void centroid_decomposition_1(GT& G, F f) {
  if (G.N == 1) return;
  if constexpr (GT::is_directed) {
    vc<int> V = toposort(G);
    G = G.rearrange(V, true);
    centroid_decomposition_1_dfs(G, V, f);
  } else {
    Graph<typename GT::cost_type, true> H = to_directed_tree(G);
    vc<int> V = toposort(H);
    H = H.rearrange(V, true);
    centroid_decomposition_1_dfs(H, V, f);
  }
}
