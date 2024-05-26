
#include "graph/base.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "graph/block_cut.hpp"
#include "graph/shortest_path/bfs01.hpp"
#include "graph/shortest_path/restore_path.hpp"

// https://en.wikipedia.org/wiki/Bipolar_orientation
// 順列 p を求める. p[s]=0,p[t]=n-1.
// p[u]<p[v] となる向きに辺を向き付けると任意の v に対して svt パスが存在.
// 存在条件：BCT で全部の成分を通る st パスがある 不可能ならば empty をかえす.
template <typename GT>
vc<int> st_numbering(GT &G, int s, int t) {
  static_assert(!GT::is_directed);
  assert(G.is_prepared());
  int N = G.N;
  if (N == 1) return {0};
  if (s == t) return {};
  vc<int> par(N, -1), pre(N, -1), low(N, -1);
  vc<int> V;

  auto dfs = [&](auto &dfs, int v) -> void {
    pre[v] = len(V), V.eb(v);
    low[v] = v;
    for (auto &e: G[v]) {
      int w = e.to;
      if (v == w) continue;
      if (pre[w] == -1) {
        dfs(dfs, w);
        par[w] = v;
        if (pre[low[w]] < pre[low[v]]) { low[v] = low[w]; }
      }
      elif (pre[w] < pre[low[v]]) { low[v] = w; }
    }
  };

  pre[s] = 0, V.eb(s);
  dfs(dfs, t);
  if (len(V) != N) return {};
  vc<int> nxt(N, -1), prev(N);
  nxt[s] = t, prev[t] = s;

  vc<int> sgn(N);
  sgn[s] = -1;
  FOR(i, 2, len(V)) {
    int v = V[i];
    int p = par[v];
    if (sgn[low[v]] == -1) {
      int q = prev[p];
      if (q == -1) return {};
      nxt[q] = v, nxt[v] = p;
      prev[v] = q, prev[p] = v;
      sgn[p] = 1;
    } else {
      int q = nxt[p];
      if (q == -1) return {};
      nxt[p] = v, nxt[v] = q;
      prev[v] = p, prev[q] = v;
      sgn[p] = -1;
    }
  }
  vc<int> A = {s};
  while (A.back() != t) { A.eb(nxt[A.back()]); }
  // 作れているか判定
  if (len(A) < N) return {};
  assert(A[0] == s && A.back() == t);
  vc<int> rk(N, -1);
  FOR(i, N) rk[A[i]] = i;
  assert(MIN(rk) != -1);
  FOR(i, N) {
    bool l = 0, r = 0;
    int v = A[i];
    for (auto &e: G[v]) {
      if (rk[e.to] < rk[v]) l = 1;
      if (rk[v] < rk[e.to]) r = 1;
    }
    if (i > 0 && !l) return {};
    if (i < N - 1 && !r) return {};
  }
  vc<int> res(N);
  FOR(i, N) res[A[i]] = i;
  return res;
}

bool check_st_numbering(Graph<int, 0> G, int s, int t) {
  int N = G.N;
  assert(N >= 2);
  if (s == t) return 0;

  UnionFind uf(N);
  for (auto &e: G.edges) uf.merge(e.frm, e.to);
  if (uf.n_comp >= 2) return 0; // disconnected

  // BCT において st パスがすべての block を通ることが必要
  auto BCT = block_cut(G);
  auto [dist, par] = bfs01<int>(BCT, s);
  vc<int> path = restore_path(par, t);

  vc<int> vis(BCT.N);
  for (auto &x: path) vis[x] = 1;

  FOR(i, N, BCT.N) {
    if (!vis[i]) return 0;
  }
  return 1;
}
