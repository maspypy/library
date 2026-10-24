// Source: https://github.com/maspypy/library/blob/main/other/todd_coxeter.hpp
#include "ds/unionfind/unionfind.hpp"

// 有限モノイドであることを前提として，遷移表を返す
template <int K>
vc<array<int, K>> todd_coxeter(const vc<pair<vc<int>, vc<int>>> &R) {
  int N = 0;

  vector<array<int, K>> T;
  UnionFind uf;
  vc<bool> done;

  auto add_vertex = [&]() -> int {
    int v = N++;
    T.emplace_back().fill(-1);
    uf.add_vertex();
    done.eb(false);
    return v;
  };

  auto step = [&](int v, int x) -> int {
    v = uf[v];
    if (T[v][x] == -1) return T[v][x] = add_vertex();
    return uf[T[v][x]];
  };

  auto walk = [&](int v, const vc<int> &s) -> int {
    for (int x : s) v = step(v, x);
    return v;
  };

  auto merge = [&](int p, int q) -> void {
    vc<pair<int, int>> que;
    que.eb(p, q);
    while (len(que)) {
      auto [p, q] = POP(que);
      p = uf[p], q = uf[q];
      if (p == q) continue;
      uf.merge(p, q);
      int r = uf[p];
      done[r] = done[p] | done[q];
      FOR(x, K) {
        int a = T[p][x], b = T[q][x];
        T[r][x] = max(a, b);
        if (a != -1 && b != -1) que.eb(a, b);
      }
    }
  };

  add_vertex();
  for (int p = 0; p < len(T); ++p) {
    for (auto &[u, v] : R) merge(walk(p, u), walk(p, v));
    FOR(x, K) step(p, x);
    done[uf[p]] = true;
  }

  // 代表元だけを残してインデックスをつけなおし，遷移表を返す
  vc<int> root;
  FOR(v, N) if (uf[v] == v) root.emplace_back(v);
  int n = len(root);
  vc<int> new_idx(N);
  FOR(i, n) new_idx[root[i]] = i;
  for (int v : root) {
    FOR(x, K) T[v][x] = new_idx[uf[T[v][x]]];
  }
  FOR(i, n) T[i] = T[root[i]];
  T.resize(n);
  return T;
}