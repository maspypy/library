#pragma once
#include "graph/base.hpp"

// ab, bc 辺はあるが ac 辺はないような 3 つ組 (a,b,c) を探す。
// なければ {-1,-1,-1}
// example: https://codeforces.com/contest/967/problem/F
template <typename Graph>
tuple<int, int, int> find_nontransitive_triple(Graph& G) {
  int N = G.N;
  assert(G.is_prepared());
  assert(!G.is_directed());
  vc<int> done(N);
  vc<int> que;
  FOR(root, N) {
    if (done[root]) continue;
    que = {root};
    int p = 0;
    while (p < len(que)) {
      int v = que[p++];
      done[v] = 2;
      ll s = 0;
      for (auto&& e: G[v]) {
        int to = e.to;
        if (done[to] == 0) {
          done[to] = 1;
          que.eb(to);
        }
        elif (done[to] == 2) { ++s; }
      }
      if (s == p - 1) continue;
      assert(p >= 3);
      int c = v;
      int a = -1;
      int b = -1;
      for (auto&& e: G[v]) done[e.to] = 0;
      FOR(i, p - 1) {
        int x = que[i];
        if (done[x] == 2) a = x;
        if (done[x] == 0) b = x;
      }
      assert(a != -1);
      assert(b != -1);
      return {a, b, c};
    }
  }
  return {-1, -1, -1};
}
