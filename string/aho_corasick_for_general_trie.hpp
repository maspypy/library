#include "ds/dynamic_array.hpp"
#include "ds/to_small_key.hpp"
#include "graph/base.hpp"

// 入力: 0 を根とする木で辺には int ラベルがついている
// return: suffix link
// https://qoj.ac/contest/1435/problem/7742
vc<int> aho_corasick_for_general_trie(Graph<int, 1> G) {
  const int N = G.N;
  To_Small_Key MP(N);
  assert(N < (1 << 20));
  Dynamic_Array<int, true> X(6 * N, 0);
  vc<int> BFS(N), link(N, -1);
  using np = decltype(X)::np;
  vc<np> S(N);
  int p = 0, q = 0;
  BFS[q++] = 0;
  S[0] = X.new_root();
  while (p < q) {
    int v = BFS[p++];
    if (v) S[v] = S[link[v]];
    for (auto& e: G[v]) {
      int s = MP.query(e.cost, 1), w = e.to;
      link[w] = X.get(S[v], s);
      S[v] = X.set(S[v], s, w);
      BFS[q++] = w;
    }
  }
  return link;
}