#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/directed_mst.hpp"

struct TestEdge { int u, v; long long w; };
static mt19937_64 gen(0xD1EC7ED5ULL);
static int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }

static pair<bool, long long> brute_arborescence(int n, int root, const vector<TestEdge>& es) {
  vector<vector<int>> incoming(n);
  for (int i = 0; i < (int)es.size(); ++i) {
    if (es[i].u != es[i].v && es[i].v != root) incoming[es[i].v].push_back(i);
  }
  vector<int> vertices;
  for (int v = 0; v < n; ++v) if (v != root) {
    if (incoming[v].empty()) return {false, 0};
    vertices.push_back(v);
  }
  vector<int> chosen(n, -1);
  long long best = LLONG_MAX;
  auto dfs = [&](auto&& self, int i) -> void {
    if (i == (int)vertices.size()) {
      vector<vector<int>> g(n);
      long long cost = 0;
      for (int v : vertices) {
        auto e = es[chosen[v]];
        g[e.u].push_back(e.v);
        cost += e.w;
      }
      vector<int> vis(n);
      vector<int> st = {root};
      vis[root] = 1;
      for (int k = 0; k < (int)st.size(); ++k)
        for (int w : g[st[k]]) if (!vis[w]) vis[w] = 1, st.push_back(w);
      if ((int)st.size() == n) best = min(best, cost);
      return;
    }
    int v = vertices[i];
    for (int id : incoming[v]) chosen[v] = id, self(self, i + 1);
  };
  dfs(dfs, 0);
  return {best != LLONG_MAX, best != LLONG_MAX ? best : 0};
}

static void check_case(int n, int root, const vector<TestEdge>& es, int case_id) {
  Graph<long long, true> g(n);
  for (auto e : es) g.add(e.u, e.v, e.w);
  g.build();
  auto got = directed_mst(g, root);
  auto want = brute_arborescence(n, root, es);
  auto fail = [&](const string& reason) -> void {
    cerr << "directed_mst mismatch case=" << case_id << " n=" << n
         << " root=" << root << " reason=" << reason << "\n";
    for (int i = 0; i < (int)es.size(); ++i)
      cerr << "  edge[" << i << "]=" << es[i].u << ',' << es[i].v << ',' << es[i].w << '\n';
    cerr << "got.cost=" << got.first << " got.edges=";
    for (int id : got.second) cerr << id << ',';
    cerr << " expected.exists=" << want.first << " expected.cost=" << want.second << '\n';
    abort();
  };
  if (!want.first) {
    if (!got.second.empty()) fail("unreachable: nonempty arborescence");
    return;
  }
  if (got.first != want.second) fail("cost");
  if ((int)got.second.size() != n - 1) fail("edge count");
  vector<int> seen(es.size());
  vector<int> indeg(n);
  vector<vector<int>> adj(n);
  long long total = 0;
  for (int id : got.second) {
    if (id < 0 || id >= (int)es.size() || seen[id]++) fail("invalid/repeated edge id");
    auto e = es[id];
    if (e.v == root || ++indeg[e.v] != 1) fail("wrong incoming edges");
    total += e.w;
    adj[e.u].push_back(e.v);
  }
  for (int v = 0; v < n; ++v) if (v != root && indeg[v] != 1) fail("missing incoming edge");
  vector<int> vis(n);
  vector<int> q = {root};
  vis[root] = 1;
  for (int i = 0; i < (int)q.size(); ++i)
    for (int v : adj[q[i]]) if (!vis[v]) vis[v] = 1, q.push_back(v);
  if ((int)q.size() != n) fail("not rooted spanning arborescence");
  if (total != got.first) fail("reported cost differs from chosen edge costs");
}

int main() {
  int case_id = 0;
  for (int n = 1; n <= 6; ++n) {
    for (int trial = 0; trial < 2200; ++trial) {
      int root = randint(0, n - 1);
      int m = randint(0, 12);
      vector<TestEdge> es;
      for (int j = 0; j < m; ++j) {
        int u = randint(0, n - 1), v = randint(0, n - 1);
        long long w = randint(-13, 13);
        es.push_back({u, v, w});
      }
      check_case(n, root, es, ++case_id);
    }
  }
  check_case(3, 0, {{0,1,9},{0,2,9},{1,2,-10},{2,1,-10}}, ++case_id);
  check_case(4, 3, {{0,1,-3},{1,0,-4},{2,3,-8},{3,2,0},{1,2,7},{3,0,10}}, ++case_id);
  check_case(2, 1, {{0,0,-100},{1,1,-100},{1,0,3},{1,0,-5}}, ++case_id);
  cout << "PASS directed_mst cases=" << case_id << '\n';
}
