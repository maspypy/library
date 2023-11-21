#define PROBLEM "https://yukicoder.me/problems/no/1777"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/planar_graph.hpp"

/*
・答は 4 or 5 である
・4 で塗ろうとする
・ある面とその頂点が確定する、隣接する面も確定するはず
・結局、陽にグラフを作ってひとつの面を塗ったあと、確定するはずのところを決めていく
*/

using Re = double;
const Re PI = acos(-1);
void solve() {
  INT(N, M);
  vc<Point<Re>> point(N);
  FOR(i, N) point[i] = {cos(2 * PI / N * i), sin(2 * PI / N * i)};
  Planar_Graph<double> PG(N, point);
  FOR(i, N) { PG.add(i, (i + 1) % N); }
  FOR(M) {
    INT(a, b);
    --a, --b;
    PG.add(a, b);
  }
  PG.build();

  int NF = PG.NF;
  Graph<int, 0> G(N + NF);
  vc<pi> edges;
  // v-v
  for (auto& e: PG.G.edges) { edges.eb(e.frm, e.to); }
  // v-f
  FOR(f, NF) {
    auto [vs, es] = PG.get_face_data(f);
    for (auto& v: vs) edges.eb(v, N + f);
  }
  // f-f
  FOR(i, PG.NE) {
    int a = PG.left_face[2 * i + 0];
    int b = PG.left_face[2 * i + 1];
    edges.eb(N + a, N + b);
  }
  for (auto& [a, b]: edges) {
    if (a > b) swap(a, b);
  }
  UNIQUE(edges);

  for (auto& [a, b]: edges) { G.add(a, b); }
  G.build();

  N = G.N;
  vc<int> cand(N, 15);
  vc<int> color(N, -1);

  pqg<pi> que;
  FOR(v, N) que.emplace(popcnt(cand[v]), v);

  auto set_color = [&](int v, int k) -> void {
    assert(color[v] == -1);
    color[v] = k;
    for (auto& e: G[v]) {
      int w = e.to;
      cand[w] &= ~(1 << k);
      if (color[w] == -1) que.emplace(popcnt(cand[w]), w);
    }
  };

  set_color(PG.NV, 0); // outer
  set_color(0, 1);
  set_color(1, 2);

  // 決まらない場合もあるらしいがやってみる
  while (len(que)) {
    int v = POP(que).se;
    if (color[v] != -1) continue;
    if (cand[v] == 0) return print(5);
    int k = topbit(cand[v]);
    set_color(v, k);
  }
  for (auto& c: color)
    if (c == -1) return print(5);
  for (auto& e: G.edges)
    if (color[e.frm] == color[e.to]) return print(5);
  print(4);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
