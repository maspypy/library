#include "graph/base.hpp"

// (vs, es), size=(n+1,n)
// [R] https://scoreboard.icpc.global/46/finals46.pdf
template <typename GT>
pair<vc<int>, vc<int>> find_even_cycle(GT &G) {
  /*
  参考：https://chaoxu.prof/posts/2014-03-08-even-cycle-in-a-simple-graph.html
  DFS木を作る, 後退辺ごとにサイクルを作る
  偶サイクルができれば OK
  共通辺を持つ奇サイクルがある → それらの XOR が満たす
  どちらもない → 奇サイクルからなるカクタス → むり
  */
  static_assert(!GT::is_directed);
  const int N = G.N, M = G.M;
  if (N == 1) return {{}, {}};
  bool FOUND = 0;
  vvc<int> cyc; // edge index
  vc<int> in_cycle(M, -1);
  vc<int> path_v;
  vc<int> path_e;
  vc<bool> used(M);
  vc<bool> vis(N);
  pair<int, int> cid = {-1, -1};
  auto dfs = [&](auto &dfs, int v) -> void {
    for (auto &e: G[v]) {
      if (FOUND) return;
      if (used[e.id]) continue;
      used[e.id] = 1;

      if (!vis[e.to]) {
        vis[e.to] = 1, used[e.id] = 1;
        path_v.eb(e.to), path_e.eb(e.id);
        dfs(dfs, e.to);
        if (FOUND) return;
        POP(path_v), POP(path_e);
        continue;
      }
      // cycle 発見
      vc<int> EID = {e.id};
      int p = len(path_v) - 1;
      while (path_v[p] != e.to) { EID.eb(path_e[--p]); }
      int k = len(cyc);
      cyc.eb(EID);
      if (len(EID) % 2 == 0) {
        cid = {k, k}, FOUND = 1;
        return;
      }
      for (auto &i: EID) {
        if (in_cycle[i] != -1) {
          cid = {k, in_cycle[i]}, FOUND = 1;
          return;
        }
        in_cycle[i] = k;
      }
    }
  };
  FOR(v, N) {
    if (vis[v]) continue;
    path_v = {int(v)};
    vis[v] = 1;
    dfs(dfs, v);
  }
  if (!FOUND) return {{}, {}};
  vc<int> es = [&]() {
    if (cid.fi == cid.se) { return cyc[cid.fi]; }
    auto [a, b] = cid;
    vc<int> use(M);
    for (auto &e: cyc[a]) use[e] ^= 1;
    for (auto &e: cyc[b]) use[e] ^= 1;
    vc<int> es;
    FOR(i, M) if (use[i]) es.eb(i);
    return es;
  }();

  vc<pair<int, int>> v_to_e(N, {-1, -1});
  auto add = [&](int v, int e) -> void {
    if (v_to_e[v].fi == -1) {
      v_to_e[v].fi = e;
    } else {
      v_to_e[v].se = e;
    }
  };
  for (auto &e: es) { add(G.edges[e].frm, e), add(G.edges[e].to, e); }

  int v0 = G.edges[es[0]].frm;
  vc<int> vs = {v0};
  es.clear(), es.shrink_to_fit();
  es = {v_to_e[v0].fi};
  while (1) {
    int e = es.back();
    int a = G.edges[e].frm, b = G.edges[e].to;
    assert(vs.back() == a || vs.back() == b);
    if (vs.back() != a) swap(a, b);
    vs.eb(b);
    if (b == v0) break;
    es.eb(v_to_e[b].fi + v_to_e[b].se - e);
  }
  return {vs, es};
}