#include "graph/bipartite_vertex_coloring.hpp"
#include "flow/maxflow.hpp"
#include "graph/reverse_graph.hpp"

// グラフがある. 頂点 v は A[v] 回まで使える（多重頂点）
// winning position の列をかえす. それを含まない最大マッチングがああるということ
// https://qoj.ac/contest/1576/problem/8507
vc<int> graph_path_game(Graph<int, 0> G, vc<int> A) {
  // 二部だけ
  auto color = bipartite_vertex_coloring(G);
  assert(!color.empty());
  int N = G.N;
  int s = N, t = N + 1;
  MaxFlow<int> F(N + 2, s, t);
  FOR(v, N) {
    if (color[v] == 0) F.add(s, v, A[v]);
    if (color[v] == 1) F.add(v, t, A[v]);
  }
  for (auto& e: G.edges) {
    int a = e.frm, b = e.to;
    if (color[a] == 1) swap(a, b);
    F.add(a, b, infty<int>);
  }
  F.flow();
  // 残余グラフで s から到達可能な左側の点
  // t へ到達可能な右側の点
  Graph<int, 1> H(N + 2);
  FOR(v, N + 2) {
    for (auto& e: F.edges[v]) {
      if (e.cap > 0) H.add(v, e.to);
    }
  }
  H.build();
  auto reach = [&](int v) -> vc<int> {
    vc<bool> vis(N + 2);
    vc<int> que;
    que.eb(v), vis[v] = 1;
    FOR(i, len(que)) {
      int v = que[i];
      for (auto& e: H[v]) {
        if (!vis[e.to]) vis[e.to] = 1, que.eb(e.to);
      }
    }
    return que;
  };
  vc<int> ANS;
  for (auto& v: reach(s)) {
    if (v < N && color[v] == 0) ANS.eb(v);
  }
  H = reverse_graph(H);
  for (auto& v: reach(t)) {
    if (v < N && color[v] == 1) ANS.eb(v);
  }
  return ANS;
}