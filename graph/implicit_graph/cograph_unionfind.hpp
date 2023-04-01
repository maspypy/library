#include "ds/unionfind/unionfind.hpp"
#include "ds/fastset.hpp"

template <typename GT>
UnionFind cograph_unionfind(GT& G) {
  const int N = G.N;
  UnionFind uf(N);
  FastSet ss(N);
  FOR(v, N) ss.insert(v);

  vc<int> que;
  FOR(v, N) {
    if (!ss[v]) continue;
    que.eb(v);
    while (len(que)) {
      int a = POP(que);
      vc<int> tmp;
      for (auto&& e: G[a]) {
        if (ss[e.to]) tmp.eb(e.to);
      }
      for (auto&& x: tmp) ss.erase(x);
      ss.enumerate(0, N, [&](int to) -> void {
        ss.erase(to);
        que.eb(to);
        uf.merge(a, to);
      });
      for (auto&& x: tmp) ss.insert(x);
    }
  }
  return uf;
}