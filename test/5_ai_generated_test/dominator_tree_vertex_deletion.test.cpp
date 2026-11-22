#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/dominator_tree.hpp"

static mt19937_64 gen(0xD0A11A70ULL);
static int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }

static vector<int> reach_without(int n, int root, const vector<pair<int,int>>& es, int banned) {
  vector<vector<int>> adj(n);
  for (auto [u, v] : es) if (u != banned && v != banned) adj[u].push_back(v);
  vector<int> vis(n);
  if (root == banned) return vis;
  vector<int> q = {root};
  vis[root] = 1;
  for (int i = 0; i < (int)q.size(); ++i) {
    for (int v : adj[q[i]]) if (!vis[v]) vis[v] = 1, q.push_back(v);
  }
  return vis;
}

static vector<int> brute_idom(int n, int root, const vector<pair<int,int>>& es) {
  vector<vector<char>> dominates(n, vector<char>(n));
  auto original = reach_without(n, root, es, -1);
  for (int d = 0; d < n; ++d) {
    auto reachable = reach_without(n, root, es, d);
    for (int v = 0; v < n; ++v) {
      dominates[d][v] = (original[v] && !reachable[v]);
    }
  }
  vector<int> ans(n, -1);
  for (int v = 0; v < n; ++v) if (original[v] && v != root) {
    vector<int> strict;
    for (int d = 0; d < n; ++d) if (d != v && dominates[d][v]) strict.push_back(d);
    int candidate = -1;
    // idom(v) is the deepest strict dominator: every other strict dominator
    // must itself dominate that candidate.
    for (int d : strict) {
      bool ok = true;
      for (int e : strict) if (e != d && !dominates[e][d]) ok = false;
      if (ok) {
        if (candidate != -1) { cerr << "Non-unique brute idom\n"; abort(); }
        candidate = d;
      }
    }
    if (candidate == -1) { cerr << "Missing brute idom\n"; abort(); }
    ans[v] = candidate;
  }
  return ans;
}

static void check(int n, int root, const vector<pair<int,int>>& es, int trial) {
  Graph<int, true> g(n);
  for (auto [u,v] : es) g.add(u,v);
  g.build();
  vector<int> got = dominator_tree(g, root);
  vector<int> want = brute_idom(n, root, es);
  if (got == want) return;
  cerr << "dominator mismatch trial=" << trial << " n=" << n << " root=" << root << '\n';
  for (auto [u,v] : es) cerr << u << " -> " << v << '\n';
  for (int i = 0; i < n; ++i)
    cerr << "  v=" << i << " expected=" << want[i] << " actual=" << got[i] << '\n';
  abort();
}

int main() {
  int case_id = 0;
  for (int n = 1; n <= 4; ++n) {
    const int bits = n * n;
    for (int mask = 0; mask < (1 << bits); ++mask) {
      vector<pair<int,int>> es;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (mask & (1 << (i*n+j))) es.push_back({i,j});
      if (n == 4 && mask % 17 != 0) continue;
      for (int root = 0; root < n; ++root) check(n,root,es,++case_id);
    }
  }
  for (int n = 1; n <= 10; ++n) {
    for (int trial = 0; trial < 2400; ++trial) {
      int root = randint(0,n-1), m = randint(0,n*n+5);
      vector<pair<int,int>> es;
      for (int i = 0; i < m; ++i) es.push_back({randint(0,n-1),randint(0,n-1)});
      check(n,root,es,++case_id);
    }
  }
  cout << "PASS dominator_tree cases=" << case_id << '\n';
}
