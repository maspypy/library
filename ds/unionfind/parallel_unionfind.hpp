#include "ds/unionfind/unionfind.hpp"

// same(L1,R1,L2,R2) みたいなことは出来ないと思う(必要なら rolling hash かな)
struct Range_Parallel_UnionFind {
  int N;
  int log;
  int n_comp;
  // ufs[i][a]==ufs[i][b] iff [a,...,a+2^i) == [b,...,b+2^i)
  vc<UnionFind> ufs;
  Range_Parallel_UnionFind(int n) : N(n), n_comp(n) {
    log = 1;
    while ((1 << log) < n) ++log;
    ufs.resize(log);
    FOR(i, log) {
      ll n = 1 << i;
      ufs[i].build(N - n + 1);
    }
  }

  int operator[](int i) { return ufs[0][i]; }

  // f(r1,r2) : 成分 r2 を r1 にマージ
  template <typename F>
  void merge(int L1, int R1, int L2, int R2, F f) {
    assert(R1 - L1 == R2 - L2);
    int n = R1 - L1;
    if (n == 0) return;
    if (n == 1) return merge_inner(0, L1, L2, f);
    int k = topbit(n - 1);
    merge_inner(k, L1, L2, f);
    merge_inner(k, R1 - (1 << k), R2 - (1 << k), f);
  }

  // f(r1,r2) : 成分 r2 を r1 にマージ
  template <typename F>
  void merge(int i, int j, F f) {
    merge_inner(0, i, j, f);
  }

  void merge(int L1, int R1, int L2, int R2) {
    merge(L1, R1, L2, R2, [&](int i, int j) -> void {});
  }
  void merge(int i, int j) {
    merge(i, j, [&](int i, int j) -> void {});
  }

  template <typename F>
  void merge_inner(int k, int L1, int L2, const F& f) {
    if (k == 0) {
      int a = ufs[0][L1], b = ufs[0][L2];
      if (a == b) return;
      ufs[0].merge(a, b);
      int c = ufs[0][a];
      --n_comp;
      return f(c, a ^ b ^ c);
    }
    if (!ufs[k].merge(L1, L2)) return;
    merge_inner(k - 1, L1, L2, f);
    merge_inner(k - 1, L1 + (1 << (k - 1)), L2 + (1 << (k - 1)), f);
  }
};
