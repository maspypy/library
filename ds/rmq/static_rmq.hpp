#include "ds/sparse_table/sparse_table.hpp"

// 構築 O(N), クエリ O(1)
// static_range_product より遅いっぽいので使うことはなさそうだ
template <typename Monoid>
struct Static_RMQ {
  using MX = Monoid;
  using X = typename MX::value_type;
  static constexpr int LOG = 4;
  int N, b_num;
  vc<X> A, pre, suf; // inclusive
  Sparse_Table<Monoid> ST;

  using u16 = unsigned short;
  vc<u16> dat;

  Static_RMQ() {}
  template <typename F>
  Static_RMQ(int n, F f) {
    build(n, f);
  }
  Static_RMQ(const vc<X>& v) { build(v); }

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
    FOR(i, 1, N) {
      if (i & 15) pre[i] = MX::op(pre[i - 1], A[i]);
    }
    FOR_R(i, 1, N) {
      if (i & 15) suf[i - 1] = MX::op(A[i - 1], suf[i]);
    }
    ST.build(b_num, [&](int i) -> X { return suf[i << LOG]; });
    // 長さ 16 以下のクエリに対応するための前計算
    // [i,i+16) 内で i+j が [i,i+j] での最小値となる場合に j-th bit を立てる
    dat.resize(N);
    u32 stack = 0;
    FOR_R(i, N) {
      stack = (stack << 1) & 65535;
      while (stack) {
        int k = lowbit(stack);
        if (MX::op(A[i], A[i + k]) != A[i]) break;
        stack &= ~(u32(1) << k);
      }
      stack |= u32(1);
      dat[i] = stack;
    }
  }

  X prod(int L, int R) {
    assert(0 <= L && L <= R && R <= N);
    if (L == R) return MX::unit();
    if (R - L <= 16) {
      u32 d = dat[L] & ((u32(1) << (R - L)) - 1);
      return A[L + topbit(d)];
    }
    --R;
    int a = L >> LOG, b = R >> LOG;
    X x = ST.prod(a + 1, b);
    x = MX::op(suf[L], x);
    x = MX::op(x, pre[R]);
    return x;
  }
};
