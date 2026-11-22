#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/shortest_path/bellman_ford.hpp"

// 対象: bellman_ford<ll, END>(G, source), END=true/false。
// 独立オラクル: 全点対距離を Floyd-Warshall で計算し、
// D[s][k]有限・D[k][k]<0・D[k][v]有限なら v=-infty と判定する。
// 到達不能な負閉路は無視し、到達可能な負閉路だけを END=true の
// 空配列条件と END=false の -infty 伝播条件に使う。
// 経路復元の親配列についても有限距離の辺緩和等式を確認する。
// n=1・自己ループ・平行辺・負辺・負閉路・到達不能を含める。
// 固定seed 0xB311A0F7。重みは[-8,9]・n<=8 で数値のoverflowなし。
struct Arc {
  int a, b;
  ll w;
};

[[noreturn]] void fail(int n, int trial, int root, int vertex,
                       const vector<Arc>& arcs, const string& what,
                       ll got, ll expected) {
  cerr << "bellman_ford: n=" << n << " trial=" << trial
       << " source=" << root << " v=" << vertex << " " << what
       << " got=" << got << " expected=" << expected << "\n";
  for (auto e : arcs) cerr << e.a << " -> " << e.b << " : " << e.w << '\n';
  abort();
}

void check(int n, const vector<Arc>& arcs, int root, int trial) {
  Graph<ll, true> G(n);
  for (auto [a, b, w] : arcs) G.add(a, b, w);
  G.build();
  constexpr ll INF = (1LL << 50);
  vector<vector<ll>> fw(n, vector<ll>(n, INF));
  for (int i = 0; i < n; ++i) fw[i][i] = 0;
  for (auto [a, b, w] : arcs) fw[a][b] = min(fw[a][b], w);
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) if (fw[i][k] < INF) {
      for (int j = 0; j < n; ++j) if (fw[k][j] < INF)
        fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
    }
  }
  vector<ll> expect(n, infty<ll>);
  bool has_negative = false;
  for (int v = 0; v < n; ++v) {
    if (fw[root][v] < INF) expect[v] = fw[root][v];
    for (int k = 0; k < n; ++k) {
      if (fw[root][k] < INF && fw[k][k] < 0 && fw[k][v] < INF) {
        expect[v] = -infty<ll>;
        has_negative = true;
        break;
      }
    }
  }
  auto [dist_all, parent_all] = bellman_ford<ll, false>(G, root);
  if ((int)dist_all.size() != n || (int)parent_all.size() != n)
    fail(n, trial, root, -1, arcs, "END=false size", dist_all.size(), n);
  for (int v = 0; v < n; ++v) {
    if (dist_all[v] != expect[v])
      fail(n, trial, root, v, arcs, "END=false distance", dist_all[v], expect[v]);
    if (v == root || expect[v] == infty<ll> || expect[v] == -infty<ll>) continue;
    int p = parent_all[v];
    if (p < 0 || p >= n)
      fail(n, trial, root, v, arcs, "missing predecessor", p, -2);
    bool valid = false;
    for (auto [a, b, w] : arcs)
      if (a == p && b == v && dist_all[p] != infty<ll> &&
          dist_all[p] != -infty<ll> && dist_all[p] + w == dist_all[v])
        valid = true;
    if (!valid)
      fail(n, trial, root, v, arcs, "predecessor relaxation", p, -2);
  }
  auto [dist_end, parent_end] = bellman_ford<ll, true>(G, root);
  if (has_negative) {
    if (!dist_end.empty() || !parent_end.empty())
      fail(n, trial, root, -1, arcs, "END=true should reject reachable negative cycle", dist_end.size(), 0);
  } else {
    if (dist_end != expect || parent_end.size() != expect.size())
      fail(n, trial, root, -1, arcs, "END=true finite result", dist_end.size(), expect.size());
  }
}

int main() {
  mt19937 rng(0xB311A0F7);
  check(1, {{0,0,-1}}, 0, -1);
  check(5, {{0,1,2},{2,3,-4},{3,2,2},{3,4,5}}, 0, -2);
  check(5, {{0,1,2},{1,2,1},{2,1,-4},{2,3,6},{4,4,-3}}, 0, -3);
  check(4, {{0,1,0},{1,2,0},{2,0,0},{2,3,4}}, 0, -4);
  for (int n = 1; n <= 8; ++n) {
    for (int trial = 0; trial < 1300; ++trial) {
      vector<Arc> arcs;
      int m = int(rng() % (3 * n + 5));
      for (int i = 0; i < m; ++i) {
        int a = int(rng() % n), b = int(rng() % n);
        ll w = ll(int(rng() % 18) - 8);
        arcs.push_back({a, b, w});
      }
      int source = int(rng() % n);
      check(n, arcs, source, trial);
    }
  }
  return 0;
}
