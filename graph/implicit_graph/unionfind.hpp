#include "ds/unionfind/unionfind.hpp"

// 頂点を削除しながら、適当なデータ構造により次の辺を探す。
// 中身はただの bfs しているので、01 最短路にも流用可能
template <typename F1, typename F2>
UnionFind implicit_graph_unionfind(int N, F1 set_used, F2 find_unused) {
  UnionFind uf(N);
  vc<bool> done(N);
  deque<int> que;
  FOR(v, N) if (!done[v]) {
    que.eb(v);
    done[v] = 1;
    set_used(v);
    while (!que.empty()) {
      int x = que.front();
      que.pop_front();
      set_used(x);
      done[x] = 1;
      while (1) {
        int to = find_unused(x);
        if (to == -1) break;
        uf.merge(v, to);
        que.eb(to);
        done[to] = 1;
        set_used(to);
      }
    }
  }
  return uf;
}