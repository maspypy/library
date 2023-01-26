#include "graph/bipartite_vertex_coloring.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "flow/bipartite.hpp"

struct RegularBipartiteColoring {
  using P = pair<int, int>;
  int N, M;
  vc<P> edges;

  vvc<int> solve(int n, int k, vc<P> G) {
    N = n;
    M = len(G);
    edges = G;
    vc<int> A(M);
    iota(all(A), 0);
    return solve_inner(M / N, A);
  }

  vvc<int> solve_inner(int k, vc<int> A) {
    return (k % 2 == 0 ? solve_even(k, A) : solve_odd(k, A));
  }

  vvc<int> solve_even(int k, vc<int> A) {
    assert(k % 2 == 0);
    if (k == 0) return {};
    // 2^m <= k < 2^{m+1}
    int m = 0;
    while (1 << (m + 1) <= k) ++m;
    vvc<int> res;
    if (k != 1 << m) {
      auto [B, C] = split(k, A);
      auto dat = solve_inner(k / 2, C);
      FOR(j, k - (1 << m)) { res.eb(dat[j]); }
      FOR(j, k - (1 << m), len(dat)) {
        for (auto&& idx: dat[j]) B.eb(idx);
      }
      k = 1 << m;
      swap(A, B);
    }
    auto dfs = [&](auto& dfs, int K, vc<int> A) -> void {
      if (K == 1) {
        res.eb(A);
        return;
      }
      auto [B, C] = split(k, A);
      dfs(dfs, K / 2, B);
      dfs(dfs, K / 2, C);
    };
    dfs(dfs, k, A);
    return res;
  }

  vvc<int> solve_odd(int k, vc<int> A) {
    assert(k % 2 == 1);
    if (k == 1) { return {A}; }
    vc<bool> match = matching(k, A);
    vc<int> B;
    B.reserve(len(A) - N);
    vc<int> es;
    FOR(i, len(A)) {
      if (match[i]) es.eb(A[i]);
      if (!match[i]) B.eb(A[i]);
    }
    vvc<int> res = solve_inner(k - 1, B);
    res.eb(es);
    return res;
  }

  vc<bool> matching(int k, vc<int> A) {
    Graph<bool, 0> G(N + N);
    vc<int> color(N + N);
    FOR(v, N) color[v] = 0;
    for (auto&& eid: A) {
      auto [a, b] = edges[eid];
      G.add(a, b);
    }
    G.build();
    BipartiteMatching<decltype(G)> BM(G);
    auto& match = BM.match;
    vc<bool> res(len(A));
    FOR(i, len(A)) {
      auto idx = A[i];
      auto [a, b] = edges[idx];
      if (match[a] == b) {
        match[a] = -1;
        res[i] = 1;
      }
    }
    return res;
  }

  pair<vc<int>, vc<int>> split(int k, vc<int> A) {
    assert(k % 2 == 0);
    // 2 つの k/2 - regular に分割する。
    int n = len(A);
    vc<bool> rest(n);
    vc<int> A0, A1;
    A0.reserve(n / 2), A1.reserve(n / 2);
    vvc<P> G(N + N);
    FOR(i, n) {
      rest[i] = 1;
      auto [a, b] = edges[A[i]];
      G[a].eb(i, b);
      G[b].eb(i, a);
    }
    auto dfs = [&](auto& dfs, int v, int color) -> void {
      while (len(G[v])) {
        auto [i, to] = POP(G[v]);
        if (!rest[i]) continue;
        rest[i] = 0;
        if (color == 0) A0.eb(A[i]);
        if (color == 1) A1.eb(A[i]);
        dfs(dfs, to, 1 ^ color);
      }
    };
    FOR(v, N) dfs(dfs, v, 0);
    return {A0, A1};
  }
};

template <typename GT>
pair<int, vc<int>> bipartite_edge_coloring(GT& G) {
  auto vcolor = bipartite_vertex_coloring<decltype(G)>(G);
  auto deg = G.deg_array();
  int D = MAX(deg);

  UnionFind uf(G.N);
  FOR(c, 2) {
    pqg<pair<int, int>> que;
    FOR(v, G.N) {
      if (vcolor[v] == c) que.emplace(deg[v], v);
    }
    while (len(que) > 1) {
      auto [d1, v1] = POP(que);
      auto [d2, v2] = POP(que);
      if (d1 + d2 > D) break;
      uf.merge(v1, v2);
      int r = uf[v1];
      que.emplace(d1 + d2, r);
    }
  }

  vc<int> LV, RV;
  FOR(v, G.N) if (uf[v] == v) {
    if (vcolor[v] == 0) LV.eb(v);
    if (vcolor[v] == 1) RV.eb(v);
  }
  int X = max(len(LV), len(RV));
  vc<int> degL(X), degR(X);

  vc<pair<int, int>> edges;
  for (auto&& e: G.edges) {
    int a = e.frm, b = e.to;
    a = uf[a], b = uf[b];
    a = LB(LV, a);
    b = LB(RV, b);
    degL[a]++, degR[b]++;
    edges.eb(a, X + b);
  }
  int p = 0, q = 0;
  while (p < X && q < X) {
    if (degL[p] == D) {
      ++p;
      continue;
    }
    if (degR[q] == D) {
      ++q;
      continue;
    }
    edges.eb(p, X + q);
    degL[p]++, degR[q]++;
  }
  RegularBipartiteColoring RBC;
  vvc<int> res = RBC.solve(X, D, edges);
  vc<int> ecolor(len(edges));
  FOR(i, len(res)) {
    for (auto&& j: res[i]) ecolor[j] = i;
  }
  ecolor.resize(G.M);
  return {D, ecolor};
}