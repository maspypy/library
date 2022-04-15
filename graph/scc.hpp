#pragma once
#include "graph/base.hpp"

template <typename Graph>
struct SCC {
  Graph &G;
  int N;
  int cnt;
  vc<int> comp;
  vc<int> low;
  vc<int> ord;
  vc<int> visited;
  int now = 0;

  SCC(Graph &G)
      : G(G), N(G.N), cnt(0), comp(G.N, 0), low(G.N, 0), ord(G.N, -1) {
    assert(G.is_directed());
    assert(G.is_prepared());
    build();
  }

  int operator[](int v) { return comp[v]; }

  void dfs(int v) {
    low[v] = now;
    ord[v] = now;
    ++now;
    visited.eb(v);
    for (auto &&[frm, to, cost, id]: G[v]) {
      if (ord[to] == -1) {
        dfs(to);
        chmin(low[v], low[to]);
      } else {
        chmin(low[v], ord[to]);
      }
    }
    if (low[v] == ord[v]) {
      while (1) {
        int u = visited.back();
        visited.pop_back();
        ord[u] = N;
        comp[u] = cnt;
        if (u == v) break;
      }
      ++cnt;
    }
  }

  void build() {
    FOR(v, N) {
      if (ord[v] == -1) dfs(v);
    }
    FOR(v, N) comp[v] = cnt - 1 - comp[v];
  }
};
