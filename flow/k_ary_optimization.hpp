
#include "flow/maxflow.hpp"

// ABC347G
template <typename T, bool MINIMIZE>
struct K_ary_Optimization {
  int n;
  vc<int> ks;
  vvc<int> idx;
  map<pair<int, int>, T> edges;
  int source, sink, nxt;
  T base_cost;

  // idx[i][j] が cut の source 側：val[i]>=j
  K_ary_Optimization(vc<int> ks) : n(len(ks)), ks(ks), base_cost(0) {
    source = 0, sink = 1, nxt = 2;
    for (auto& k: ks) {
      assert(k >= 1);
      vc<int> I(k + 1);
      I[0] = source, I[k] = sink;
      FOR(i, 1, k) { I[i] = nxt++; }
      idx.eb(I);
      if (k >= 3) { FOR(j, 1, k - 1) add_edge(I[j + 1], I[j], infty<T>); }
    }
  }

  // xi を 0, 1, ..., k-1 にするときにかかるコストを追加する。
  void add_1(int i, vc<T> cost) {
    assert(0 <= i && i < n && len(cost) == ks[i]);
    if (!MINIMIZE) {
      for (auto& x: cost) x = -x;
    }
    _add_1(i, cost);
  }

  void add_2(int i, int j, vvc<T> cost) {
    assert(0 <= i && i < n && 0 <= j && j < n && i != j);
    int H = ks[i], W = ks[j];
    assert(len(cost) == H);
    FOR(a, H) assert(len(cost[a]) == W);
    if (!MINIMIZE) { FOR(a, H) FOR(b, W) cost[a][b] = -cost[a][b]; }
    _add_2(i, j, cost);
  }

  // 最小値および、[0,k) 列を返す
  pair<T, vc<int>> calc() {
    MaxFlow<T> G(nxt, source, sink);
    for (auto&& [key, cap]: edges) {
      auto [frm, to] = key;
      G.add(frm, to, cap);
    }

    auto [val, cut] = G.cut();
    val += base_cost;
    vc<int> ANS(n);
    FOR(i, n) {
      FOR(j, 1, ks[i]) { ANS[i] += 1 - cut[idx[i][j]]; }
    }
    if (!MINIMIZE) val = -val;
    return {val, ANS};
  }

private:
  void add_base(T x) {
    base_cost += x;
    assert(-infty<T> < base_cost && base_cost < infty<T>);
  }

  void add_edge(int i, int j, T t) {
    assert(t >= 0);
    if (t == 0) return;
    pair<int, int> key = mp(i, j);
    edges[key] += t;
    assert(edges[key] <= infty<T>);
  }

  void _add_1(int i, vc<T> cost) {
    add_base(cost[0]);
    FOR_R(j, ks[i]) cost[j] -= cost[0];
    FOR(j, 1, ks[i]) {
      T x = cost[j] - cost[j - 1];
      // j 以上にすると x
      if (x > 0) add_edge(idx[i][j], sink, x);
      if (x < 0) add_base(x), add_edge(source, idx[i][j], -x);
    }
  }
  void _add_2(int i, int j, vvc<T> cost) {
    int H = ks[i], W = ks[j];
    _add_1(j, cost[0]);
    FOR_R(a, H) FOR(b, W) cost[a][b] -= cost[0][b];
    vc<T> tmp(H);
    FOR(a, H) tmp[a] = cost[a][W - 1];
    _add_1(i, tmp);
    FOR(a, H) FOR(b, W) cost[a][b] -= tmp[a];
    FOR(a, 1, H) FOR(b, W - 1) {
      T x = cost[a][b] + cost[a - 1][b + 1] - cost[a - 1][b] - cost[a][b + 1];
      assert(x >= 0); // monge
      add_edge(idx[i][a], idx[j][b + 1], x);
    }
  }
};