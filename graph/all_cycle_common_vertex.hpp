#include "graph/strongly_connected_component.hpp"
#include "graph/toposort.hpp"
#include "graph/find_cycle.hpp"

// v を通るサイクルが存在し, v を消すと DAG になるような v を昇順全列挙する
// v を消すと 非DAG -> DAG
// loop はないものとしたかも
// https://codeforces.com/contest/982/problem/F
template <typename GT>
vc<int> all_cycle_common_vertex(GT& G, bool strongly_connected) {
  static_assert(G.is_directed());
  int N = G.N;
  if (!strongly_connected) {
    auto [nc, comp] = strongly_connected_component(G);
    vc<int> sz(nc);
    FOR(v, N) sz[comp[v]]++;
    int k = -1;
    FOR(i, nc) {
      if (sz[i] >= 2) {
        if (k != -1) return {};
        k = i;
      }
    }
    if (k == -1) return {};  // DAG
    vc<int> V;
    FOR(v, N) if (comp[v] == k) V.eb(v);
    Graph<int, 1> H = G.rearrange(V);
    vc<int> ANS = all_cycle_common_vertex(H, true);
    for (int& x : ANS) x = V[x];
    return ANS;
  }

  assert(strongly_connected);
  if (N == 1) return {};  // DAG

  // main cycle
  vc<int> C = find_cycle_directed(G).fi;

  int n = len(C);
  vc<int> idx(N, -1);
  FOR(i, n) idx[C[i]] = i;

  vc<int> other;
  FOR(i, N) if (idx[i] == -1) other.eb(i);
  if (len(other)) {
    Graph<int, 1> H = G.rearrange(other);
    if (toposort(H).empty()) return {};  // two vertex disjoint cycle
  }

  vc<int> F(N + 1);
  auto arc = [&](int s, int t) -> void {
    if (s < t) {
      F[s + 1]++, F[t]--;
    } else {
      F[s + 1]++, F[n]--;
      F[0]++, F[t]--;
    }
  };

  vc<int> dp(N, -2);

  FOR(s, n) {
    auto eval = [&](int i) -> int {
      if (i < 0) return i;
      return (s < i ? i - s : i + n - s);
    };

    auto dfs = [&](auto& dfs, int v) -> int {
      if (idx[v] != -1) return idx[v];
      if (dp[v] != -2) return dp[v];
      int ans = -1;
      for (auto& e : G[v]) {
        int i = dfs(dfs, e.to);
        if (eval(ans) < eval(i)) ans = i;
      }
      return dp[v] = ans;
    };
    int i = -1;
    for (auto& e : G[C[s]]) {
      int j = dfs(dfs, e.to);
      if (eval(i) < eval(j)) i = j;
    }
    if (i != -1) arc(s, i);
  }
  FOR(i, n) F[i + 1] += F[i];
  F.pop_back();

  vc<int> ANS;
  FOR(i, n) if (F[i] == 0) ANS.eb(C[i]);

  if (ANS.empty()) return {};
  vc<int> V;
  FOR(v, N) if (v != ANS[0]) V.eb(v);
  {
    Graph<int, 1> H = G.rearrange(V);
    if (toposort(H).empty()) return {};
  }
  return ANS;
}
