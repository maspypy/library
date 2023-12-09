#include "graph/ds/static_toptree.hpp"

// https://codeforces.com/contest/1172/problem/E
// function を持たせると 1.5 倍遅いんだがどうしよう
template <typename TREE, typename Data>
struct Dynamic_Tree_Dp {
  Static_TopTree<TREE> STT;
  int n;
  vc<Data> dp;
  vc<int> v_to_k;

  template <typename F1, typename F2, typename F3, typename F4, typename F5>
  Dynamic_Tree_Dp(TREE& tree, F1 from_vertex, F2 add_vertex, F3 add_edge,
                  F4 merge_light, F5 merge_heavy)
      : STT(tree) {
    n = len(STT.par);
    dp.resize(n);
    FOR_R(i, n) {
      upd(i, from_vertex, add_vertex, add_edge, merge_light, merge_heavy);
    }
    int N = tree.N;
    v_to_k.assign(N, -1);
    FOR(k, n) {
      if (STT.lch[k] == -1 && STT.rch[k] == -1) { v_to_k[STT.A[k]] = k; }
      elif (STT.rch[k] == -1 && STT.heavy[k]) { v_to_k[STT.A[k]] = k; }
    }
  }

  template <typename F1, typename F2, typename F3, typename F4, typename F5>
  void upd(int k, F1 from_vertex, F2 add_vertex, F3 add_edge, F4 merge_light,
           F5 merge_heavy) {
    int l = STT.lch[k], r = STT.rch[k], a = STT.A[k];
    if (l == -1 && r == -1) { dp[k] = from_vertex(a); }
    elif (r == -1) {
      if (STT.heavy[k]) {
        dp[k] = add_vertex(dp[l], a);
      } else {
        dp[k] = add_edge(dp[l], a, STT.B[l]);
      }
    }
    else {
      if (STT.heavy[k]) {
        dp[k]
            = merge_heavy(dp[l], dp[r], STT.A[l], STT.B[l], STT.A[r], STT.B[r]);
      } else {
        dp[k] = merge_light(dp[l], dp[r]);
      }
    }
  }

  template <typename F1, typename F2, typename F3, typename F4, typename F5>
  void recalc_vertex(int v, F1 from_vertex, F2 add_vertex, F3 add_edge,
                     F4 merge_light, F5 merge_heavy) {
    int k = v_to_k[v];
    while (k != -1) {
      upd(k, from_vertex, add_vertex, add_edge, merge_light, merge_heavy),
          k = STT.par[k];
    }
  }

  Data get() { return dp[0]; }
};