#include "graph/base.hpp"
#include "ds/unionfind/unionfind.hpp"

template <typename T>
Graph<T, 0> Manhattan_MST(vc<pair<T, T>>& XY) {
  int N = XY.size();
  vc<tuple<T, int, int>> dat;
  dat.reserve(4 * N);
  vc<int> idx(N);
  iota(all(idx), 0);

  FOR(a, 2) {
    for (auto&& [x, y]: XY) x = -x;
    FOR(b, 2) {
      for (auto&& [x, y]: XY) swap(x, y);
      sort(all(idx), [&](const int& i, const int& j) -> bool {
        return XY[i].fi + XY[i].se < XY[j].fi + XY[j].se;
      });

      map<T, int> MP;
      for (const int i: idx) {
        auto& [x, y] = XY[i];
        for (auto it = MP.lower_bound(-y); it != MP.end(); it = MP.erase(it)) {
          const int j = it->se;
          auto& [xj, yj] = XY[j];
          const int dx = x - xj;
          const int dy = y - yj;
          if (dy > dx) break;
          dat.eb(dx + dy, i, j);
        }
        MP[-y] = i;
      }
    }
  }

  sort(all(dat));
  Graph<T, 0> G(N);
  UnionFind uf(N);
  for (auto&& [cost, i, j]: dat) {
    if (uf.merge(i, j)) G.add(i, j, cost);
  }
  G.build();
  return G;
}
