
#include "graph/reverse_graph.hpp"

// 有向グラフ、動けない人が負け
// 各ノードに対して手番のプレイヤが決まっていて、交互
// 勝者は最短、敗者は最長手数を目指す
struct Graph_Game {
  vc<bool> win;
  vc<bool> lose;
  vc<int> end_turn;
  vc<int> best_strategy;

  template <typename GT>
  Graph_Game(GT& G) {
    auto RG = reverse_graph(G);
    auto [indeg, outdeg] = G.deg_array_inout();
    int N = G.N;
    win.resize(N);
    lose.resize(N);
    end_turn.resize(N, 1 << 30);
    best_strategy.resize(N, -1);
    deque<int> que;
    FOR(v, N) {
      if (outdeg[v] == 0) que.eb(v);
    }

    while (!que.empty()) {
      auto v = POP(que);
      if (win[v] || lose[v]) continue;
      lose[v] = 1;
      for (auto&& e: G[v]) {
        if (lose[e.to]) win[v] = 1;
        if (!win[e.to]) lose[v] = 0;
      }
      assert(win[v] ^ lose[v]);
      if (win[v]) {
        for (auto&& e: G[v]) {
          if (chmin(end_turn[v], end_turn[e.to] + 1)) {
            best_strategy[v] = e.to;
          }
        }
      }
      if (lose[v]) {
        end_turn[v] = 0;
        for (auto&& e: G[v]) {
          if (chmax(end_turn[v], end_turn[e.to] + 1)) {
            best_strategy[v] = e.to;
          }
        }
      }
      for (auto&& e: RG[v]) {
        outdeg[e.to]--;
        if (lose[v] || outdeg[e.to] == 0) que.eb(e.to);
      }
    }
  }
};