#include "graph/ds/static_toptree.hpp"

// https://codeforces.com/contest/1172/problem/E
// https://codeforces.com/contest/1942/problem/H
// single(v) : v とその親辺を合わせたクラスタ
// rake(x, y, u, v) uv(top down) が boundary になるように rake (maybe v=-1)
// compress(x,y,a,b,c)  (top-down) 順に (a,b] + (b,c]
template <typename TREE, typename Data>
struct Dynamic_Tree_Dp {
  Static_TopTree<TREE> STT;
  vc<Data> dp;

  Dynamic_Tree_Dp(TREE& tree) : STT(tree) {}

  template <typename F1, typename F2, typename F3>
  Data init_dp(F1 single, F2 rake, F3 compress) {
    int n = len(STT.par);
    dp.resize(n);
    FOR(i, n) { upd(i, single, rake, compress); }
    return dp.back();
  }

  template <typename F1, typename F2, typename F3>
  Data recalc(int v, F1 single, F2 rake, F3 compress) {
    assert(!dp.empty());
    for (int k = v; k != -1; k = STT.par[k]) { upd(k, single, rake, compress); }
    return dp.back();
  }

  Data get() { return dp.back(); }

private:
  template <typename F1, typename F2, typename F3>
  void upd(int k, F1 single, F2 rake, F3 compress) {
    if (0 <= k && k < STT.N) {
      dp[k] = single(k);
      return;
    }
    int l = STT.lch[k], r = STT.rch[k];
    if (STT.is_compress[k]) {
      int a = STT.A[l], b = STT.B[l];
      int c = STT.A[r], d = STT.B[r];
      assert(b == c);
      dp[k] = compress(dp[l], dp[r], a, b, d);
    } else {
      dp[k] = rake(dp[l], dp[r], STT.A[k], STT.B[k]);
    }
  }
};