#include "graph/ds/static_toptree.hpp"

// reroot できない簡易版
// https://codeforces.com/contest/1172/problem/E
// https://codeforces.com/contest/1942/problem/H
// single(v) : v とその親辺を合わせたクラスタ
// rake(L,R) : L の boundary を維持
// compress(L,R)  (top-down) 順に L,R
template <typename TREE, typename TREE_DP>
struct Dynamic_Tree_Dp {
  using X = typename TREE_DP::value_type;
  Static_TopTree<TREE> STT;
  vc<X> dp;

  template <typename F>
  Dynamic_Tree_Dp(TREE& tree, F single) : STT(tree) {
    int N = tree.N;
    dp.resize(2 * N - 1);
    FOR(i, N) dp[i] = single(i);
    FOR(i, N, 2 * N - 1) update(i);
  }

  void set(int v, X x) {
    dp[v] = x;
    for (int i = STT.par[v]; i != -1; i = STT.par[i]) update(i);
  }

  X prod_all() { return dp.back(); }

private:
  inline void update(int i) {
    X &L = dp[STT.lch[i]], &R = dp[STT.rch[i]];
    dp[i] = (STT.is_compress[i] ? TREE_DP::compress(L, R) : TREE_DP::rake(L, R));
  }
};