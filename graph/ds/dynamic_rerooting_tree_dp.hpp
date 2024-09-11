#include "graph/ds/static_toptree.hpp"

/*
https://github.com/maspypy/library/blob/main/graph/ds/stt_dp_memo.png
rake: (a<-b], (a<-c] -> (a<-b].
rake2: (a->b], (a<-c] -> (a->b].
rake3: [a<-b), (a<-c] -> [a<-b). typically rake3==rake.
compress: (a<-b], (b<-c] -> (a<-c].
compress2: [a<-b), [b<-c) -> [a<-c). typically compress2(L,R) == compress(R,L).
*/
template <typename TREE, typename TREE_DP>
struct Dynamic_Rerooting_Tree_Dp {
  using X = typename TREE_DP::value_type;
  Static_TopTree<TREE> STT;
  vc<pair<X, X>> dp;

  template <typename F>
  Dynamic_Rerooting_Tree_Dp(TREE& tree, F f) : STT(tree) {
    assert(tree.V[0] == 0); // さぼり
    int N = tree.N;
    dp.resize(2 * N - 1);
    dp[0].fi = dp[0].se = TREE_DP::unit();
    FOR(i, 1, N) dp[i] = f(i);
    FOR(i, N, 2 * N - 1) update(i);
  }

  // v と親を結ぶ辺. 親が virtual / 子が virtual
  void set(int v, pair<X, X> x) {
    assert(v > 0);
    dp[v] = x;
    for (int i = STT.par[v]; i != -1; i = STT.par[i]) update(i);
  }

  X prod_all(int v) {
    int i = v;
    X a = dp[i].se, b = TREE_DP::unit(), c = TREE_DP::unit();
    while (1) {
      int p = STT.par[i];
      if (p == -1) break;
      int l = STT.lch[p], r = STT.rch[p];
      if (STT.is_compress[p]) {
        if (l == i) {
          b = TREE_DP::compress(b, dp[r].fi);
        } else {
          a = TREE_DP::compress2(dp[l].se, a);
        }
      } else {
        if (STT.lch[p] == i) {
          a = TREE_DP::rake2(a, dp[r].fi);
        } else {
          a = TREE_DP::rake3(a, b);
          c = TREE_DP::compress2(a, c);
          a = TREE_DP::unit(), b = dp[l].fi;
        }
      }
      i = p;
    }
    a = TREE_DP::rake3(a, b);
    return TREE_DP::compress2(a, c);
  }

private:
  inline void update(int i) {
    auto& [L1, L2] = dp[STT.lch[i]];
    auto& [R1, R2] = dp[STT.rch[i]];
    if (STT.is_compress[i]) {
      dp[i] = {TREE_DP::compress(L1, R1), TREE_DP::compress2(L2, R2)};
    } else {
      dp[i] = {TREE_DP::rake(L1, R1), TREE_DP::rake2(L2, R1)};
    }
  }
};
