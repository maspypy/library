#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/blackbox/complement_graph_bfs.hpp"

/*
対象: complement_graph_bfs(G,s) が返す補グラフ内の距離と親。
既存の問題別テストにはこの関数への直接の検証が見当たらないため追加。
独立 oracle: 隣接行列を反転した単純な BFS。補グラフに自己ループは含めない。
元グラフは無向で、平行辺を許し、合法な始点を与える。
小さい無向グラフ（n<=5）を全列挙、さらに n=63/64/65/129 等を乱択。
関数内の static バッファが前回実行の情報を引きずらないよう、n・始点を毎回変える。
乱数seed: 0xC0B17E2026ULL。
*/
namespace {
void fail(int n, int s, int v, const string& why) {
  cerr << "complement_graph_bfs n=" << n << " source=" << s
       << " vertex=" << v << " : " << why << '\n';
  abort();
}
void check(const vector<vector<unsigned char>>& adj, int s,
           const vector<pair<int, int>>& edges) {
  int n = int(adj.size());
  Graph<int, 0> G(n);
  for (auto [u, v] : edges) G.add(u, v);
  G.build();
  const auto [dist, par] = complement_graph_bfs(G, s);
  vector<int> expected(n, infty<int>);
  queue<int> q;
  expected[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int w = 0; w < n; ++w) {
      if (w == v || adj[v][w] || expected[w] != infty<int>) continue;
      expected[w] = expected[v] + 1;
      q.push(w);
    }
  }
  if (dist.size() != size_t(n) || par.size() != size_t(n))
    fail(n, s, -1, "output sizes");
  for (int v = 0; v < n; ++v) {
    if (dist[v] != expected[v])
      fail(n, s, v, "dist got=" + to_string(dist[v]) +
                     " expected=" + to_string(expected[v]));
    if (v == s || expected[v] == infty<int>) {
      if (par[v] != -1) fail(n, s, v, "parent should be -1");
    } else {
      int p = par[v];
      if (p < 0 || p >= n || p == v || adj[p][v] ||
          dist[p] + 1 != dist[v])
        fail(n, s, v, "parent is not a valid shortest-path predecessor");
    }
  }
}
void test_mask(int n, uint64_t mask) {
  vector<vector<unsigned char>> adj(n, vector<unsigned char>(n));
  vector<pair<int, int>> edges;
  int k = 0;
  for (int u = 0; u < n; ++u) for (int v = u + 1; v < n; ++v) {
    if (mask >> k & 1ULL) adj[u][v] = adj[v][u] = 1, edges.emplace_back(u, v);
    ++k;
  }
  for (int s = 0; s < n; ++s) check(adj, s, edges);
}
void random_case(int n, mt19937_64& rng) {
  vector<vector<unsigned char>> adj(n, vector<unsigned char>(n));
  vector<pair<int, int>> edges;
  int p = int(rng() % 101);
  for (int u = 0; u < n; ++u) for (int v = u + 1; v < n; ++v) {
    if (rng() % 100 < uint64_t(p)) {
      adj[u][v] = adj[v][u] = 1;
      edges.emplace_back(u, v);
      if (rng() % 31 == 0) edges.emplace_back(u, v); // 元グラフの平行辺
    }
  }
  for (int repeat = 0; repeat < min(n, 5); ++repeat) {
    int s = int(rng() % n);
    check(adj, s, edges);
  }
}
} // namespace

int main() {
  for (int n = 1; n <= 5; ++n) {
    int m = n * (n - 1) / 2;
    for (uint64_t mask = 0; mask < (1ULL << m); ++mask) test_mask(n, mask);
  }
  mt19937_64 rng(0xC0B17E2026ULL);
  for (int n : {1, 2, 3, 6, 7, 8, 31, 32, 63, 64, 65, 66, 127, 128, 129}) {
    for (int rep = 0; rep < 28; ++rep) random_case(n, rng);
  }
  return 0;
}
