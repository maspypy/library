#include "graph/base.hpp"

// {G, LR}.
// regular bracket sequence をグラフにする。各頂点の範囲を表す配列 LR も作る。
// 全体を表す根ノードも作って、N/2+1頂点。
// ()() → [0,4), [0,2), [2,4)
// regular bracket sequence 以外が入力に来るときは、前後に()を補えば使える。
pair<Graph<int, 1>, vc<pair<int, int>>> bracket_graph(string& S) {
  int N = len(S) / 2;
  Graph<int, 1> G(N + 1);
  vc<pair<int, int>> LR(N + 1);
  int now = 0;
  int nxt = 1;
  LR[0] = {0, len(S)};
  vc<int> par(N + 1, -1);
  FOR(i, len(S)) {
    assert(S[i] == '(' || S[i] == ')');
    if (S[i] == '(') {
      G.add(now, nxt);
      par[nxt] = now;
      LR[nxt].fi = i;
      now = nxt;
      nxt++;
    }
    if (S[i] == ')') {
      LR[now].se = i + 1;
      now = par[now];
    }
  }
  assert(now == 0);
  G.build();
  return {G, LR};
}