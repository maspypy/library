#include "graph/base.hpp"

// 非連結でも動作する，BCT は森．
// block とは辺の同値類のこととする. したがって
// - loop は 1 辺からなる block
// - 孤立点は block に接続しない
struct Block_Cut {
  int N, M, NB;
  Graph<int, 0> BCT;
  vc<int> comp_e;
  vc<bool> art;

  template <typename GT>
  Block_Cut(const GT& G) {
    N = G.N, M = G.M;
    vc<int> low(N), ord(N), st;
    vc<bool> used(N), used_e(M);
    st.reserve(M);
    art.assign(N, false);
    int k = 0;
    vvc<int> es;
    FOR(r, N) if (!used[r]) {
      auto dfs = [&](auto& dfs, int v) -> void {
        used[v] = 1;
        low[v] = ord[v] = k++;
        int n_ch = 0;
        for (auto&& e : G[v]) {
          if (used_e[e.id]) continue;
          used_e[e.id] = 1;
          if (e.to == v) {
            es.eb(vc<int>({e.id}));
            continue;
          }
          if (!used[e.to]) {
            ++n_ch;
            int s = len(st);
            st.eb(e.id);
            dfs(dfs, e.to);
            chmin(low[v], low[e.to]);
            if (low[e.to] >= ord[v]) {
              if (v != r) art[v] = 1;
              vc<int> E;
              while (len(st) > s) E.eb(POP(st));
              es.eb(E);
            }
          } else {
            // back edge
            st.eb(e.id);
            chmin(low[v], ord[e.to]);
          }
        }
        if (v == r) art[v] = (n_ch >= 2);
      };
      dfs(dfs, r);
      assert(st.empty());
    }

    comp_e.resize(M);
    FOR(v, N) used[v] = 0;
    NB = len(es);
    BCT.build(N + NB);
    vc<int> V;
    FOR(k, NB) {
      V.clear();
      for (int e : es[k]) {
        comp_e[e] = N + k;
        V.eb(G.edges[e].frm);
        V.eb(G.edges[e].to);
      }
      for (int v : V) {
        if (used[v]) continue;
        used[v] = 1;
        BCT.add(N + k, v);
      }
      for (int v : V) used[v] = 0;
    }
    BCT.build();
  }

  int edge_to_block(int eid) const {
    assert(0 <= eid && eid < M);
    return comp_e[eid];
  }

  bool is_art(int v) const {
    assert(0 <= v && v < N);
    return art[v];
  }
};
