#include "ds/sparse_table/sparse_table.hpp"
#include "ds/sparse_table/disjoint_sparse_table.hpp"

/*
参考：https://judge.yosupo.jp/submission/106668
長さ 2^LOG のブロックに分ける．ブロック内の prefix, suffix を持つ．
ブロック積の列を ST(DST) で持つ．ブロックをまたぐ積は O(1).
短いものは O(1) を諦めて愚直ということにする．
前計算：O(Nlog(N)/2^LOG)
クエリ：O(1) / worst O(2^LOG)
*/
template <typename Monoid, typename SPARSE_TABLE, int LOG = 4>
struct Static_Range_Product {
  using MX = Monoid;
  using X = typename MX::value_type;
  int N, b_num;
  vc<X> A, pre, suf; // inclusive
  SPARSE_TABLE ST;

  Static_Range_Product() {}
  template <typename F>
  Static_Range_Product(int n, F f) {
    build(n, f);
  }
  Static_Range_Product(const vc<X>& v) { build(v); }

  void build(const vc<X>& v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    N = m;
    b_num = N >> LOG;
    A.resize(N);
    FOR(i, N) A[i] = f(i);
    pre = A, suf = A;
    constexpr int mask = (1 << LOG) - 1;
    FOR(i, 1, N) {
      if (i & mask) pre[i] = MX::op(pre[i - 1], A[i]);
    }
    FOR_R(i, 1, N) {
      if (i & mask) suf[i - 1] = MX::op(A[i - 1], suf[i]);
    }
    ST.build(b_num, [&](int i) -> X { return suf[i << LOG]; });
  }

  // O(1) or O(R-L)
  X prod(int L, int R) {
    if (L == R) return MX::unit();
    R -= 1;
    int a = L >> LOG, b = R >> LOG;
    if (a < b) {
      X x = ST.prod(a + 1, b);
      x = MX::op(suf[L], x);
      x = MX::op(x, pre[R]);
      return x;
    }
    X x = A[L];
    FOR(i, L + 1, R + 1) x = MX::op(x, A[i]);
    return x;
  }

  template <class F>
  int max_right(const F check, int L) {
    assert(0 <= L && L <= N && check(MX::unit()));
    if (L == N) return N;
    int ok = L, ng = N + 1;
    while (ok + 1 < ng) {
      int k = (ok + ng) / 2;
      bool bl = check(prod(L, k));
      if (bl) ok = k;
      if (!bl) ng = k;
    }
    return ok;
  }

  template <class F>
  int min_left(const F check, int R) {
    assert(0 <= R && R <= N && check(MX::unit()));
    if (R == 0) return 0;
    int ok = R, ng = -1;
    while (ng + 1 < ok) {
      int k = (ok + ng) / 2;
      bool bl = check(prod(k, R));
      if (bl) ok = k;
      if (!bl) ng = k;
    }
    return ok;
  }
};