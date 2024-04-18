#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "random/random_graph.hpp"
#include "graph/find_even_cycle.hpp"

vc<int> find_even_cycle_naive(Graph<int, 0> G) {
  int N = G.N;
  vc<int> used_v(N);
  vc<int> path;
  vc<int> ANS;
  auto dfs = [&](auto& dfs, int v, int p) -> void {
    if (!ANS.empty()) return;
    for (auto& e: G[v]) {
      if (e.id == p) continue;
      if (e.to == path[0] && len(path) % 2 == 0) {
        ANS = path;
        return;
      }
      if (!used_v[e.to]) {
        used_v[e.to] = 1;
        path.eb(e.to);
        dfs(dfs, e.to, e.id);
        POP(path);
        used_v[e.to] = 0;
      }
    }
  };
  FOR(v, N) {
    used_v[v] = 1;
    path.eb(v);
    dfs(dfs, v, -1);
    used_v[v] = 0;
    path.pop_back();
  }
  return ANS;
}

void test() {
  FOR(N, 1, 15) {
    FOR(1000) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<0>(N, false)) G.add(a, b);
      G.build();
      auto [vs, es] = find_even_cycle(G);
      vc<int> ans = find_even_cycle_naive(G);
      if (vs.empty()) {
        assert(ans.empty());
        continue;
      }
      assert(!ans.empty());
      int n = len(es);

      assert(n % 2 == 0);
      assert(len(vs) == 1 + n);
      assert(vs[0] == vs[n]);
      FOR(i, n) {
        int a = vs[i], b = vs[i + 1];
        auto& e = G.edges[es[i]];
        assert((e.frm == a && e.to == b) || (e.frm == b && e.to == a));
      }
      UNIQUE(vs);
      assert(len(vs) == n);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}
