#include "graph/ds/static_toptree.hpp"

// 木の頂点の重み付き集合を管理.
// 全対の距離の和, v からの距離の和がとれる.
// O(logN). 自分の実装だと雑な重心分解より速かった.
// https://codeforces.com/contest/1458/problem/F
template <typename TREE, typename T>
struct Distance_Sum {
  struct Data {
    T ans, cnt, a, b, c;
  };
  static Data rake(Data& L, Data& R) { return {L.ans + R.ans + L.cnt * R.a + R.cnt * L.a, L.cnt + R.cnt, L.a + R.a, L.b + R.a + L.c * R.cnt, L.c}; }
  static Data compress(Data& L, Data& R) {
    return {L.ans + R.ans + L.cnt * R.a + R.cnt * L.b, L.cnt + R.cnt, L.a + R.a + R.cnt * L.c, L.b + R.b + L.cnt * R.c, L.c + R.c};
  }
  static Data single(T d, T cnt) { return {0, cnt, d * cnt, 0, d}; }

  int N;
  Static_TopTree<TREE> STT;
  T ALL_PAIR_SUM = 0;
  vc<Data> dp;
  Distance_Sum(TREE& tree) : N(tree.N), STT(tree) {
    dp.assign(2 * N - 1, {0, 0, 0, 0, 0});
    FOR(v, N) dp[v] = {0, 0, 0, 0, edge_len(v)};
    FOR(i, N, 2 * N - 2) {
      Data &L = dp[STT.lch[i]], &R = dp[STT.rch[i]];
      dp[i] = (STT.is_compress[i] ? compress(L, R) : rake(L, R));
    }
  }
  T edge_len(int v) {
    if (v == 0) return 0;
    int p = STT.tree.parent[v];
    return STT.tree.depth_weighted[v] - STT.tree.depth_weighted[p];
  }
  void set(int v, T x) {
    dp[v] = single(edge_len(v), x);
    for (int i = STT.par[v]; i != -1; i = STT.par[i]) {
      Data &L = dp[STT.lch[i]], &R = dp[STT.rch[i]];
      dp[i] = (STT.is_compress[i] ? compress(L, R) : rake(L, R));
    }
  }

  T all_pair_sum() { return dp[2 * N - 2].ans; }

  void add(int v, T x) { set(v, dp[v].cnt + x); }
  T query(int v) {
    T now = dp[2 * N - 2].ans;
    Data x = single(edge_len(v), dp[v].cnt + 1);
    while (v != 2 * N - 2) {
      int p = STT.par[v];
      Data& L = (STT.lch[p] == v ? x : dp[STT.lch[p]]);
      Data& R = (STT.rch[p] == v ? x : dp[STT.rch[p]]);
      x = (STT.is_compress[p] ? compress(L, R) : rake(L, R)), v = p;
    }
    return x.ans - now;
  }
};