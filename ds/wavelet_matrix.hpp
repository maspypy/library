#include "ds/bit_vector.hpp"

// 座圧するかどうかを COMPRESS で指定する
// xor 的な使い方をする場合には、コンストラクタで log を渡すこと
template <typename T, bool COMPRESS>
struct Wavelet_Matrix {
  int N, lg;
  vector<int> mid;
  vector<Bit_Vector> bv;
  vc<T> key;
  const bool set_log;

  Wavelet_Matrix(vector<T> A, int log = -1)
      : N(len(A)), lg(log), set_log(log != -1) {
    if (COMPRESS) {
      assert(!set_log);
      key.reserve(N);
      vc<int> I = argsort(A);
      for (auto&& i: I) {
        if (key.empty() || key.back() != A[i]) key.eb(A[i]);
        A[i] = len(key) - 1;
      }
      key.shrink_to_fit();
    }
    if (lg == -1) lg = __lg(max<ll>(MAX(A), 1)) + 1;
    mid.resize(lg);
    bv.assign(lg, Bit_Vector(N));
    vc<T> A0(N), A1(N);
    FOR_R(d, lg) {
      int p0 = 0, p1 = 0;
      FOR(i, N) {
        bool f = (A[i] >> d & 1);
        if (!f) A0[p0++] = A[i];
        if (f) bv[d].set(i), A1[p1++] = A[i];
      }
      mid[d] = p0;
      bv[d].build();
      swap(A, A0);
      FOR(i, p1) A[p0 + i] = A1[i];
    }
  }

  // xor した結果で [a, b) に収まるものを数える
  int count(int L, int R, T a, T b, T xor_val = 0) {
    return prefix_count(L, R, b, xor_val) - prefix_count(L, R, a, xor_val);
  }

  // xor した結果で [0, x) に収まるものを数える
  int prefix_count(int L, int R, T x, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    x = (COMPRESS ? LB(key, x) : x);
    if (x >= (1 << lg)) return R - L;
    int ret = 0;
    FOR_R(d, lg) {
      bool add = (x >> d) & 1;
      bool f = ((x ^ xor_val) >> d) & 1;
      if (add) ret += bv[d].rank(R, !f) - bv[d].rank(L, !f);
      L = bv[d].rank(L, f) + (f ? mid[d] : 0);
      R = bv[d].rank(R, f) + (f ? mid[d] : 0);
    }
    return ret;
  }

  // [L, R) の中で k>=0 番目
  T kth(int L, int R, int k, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    assert(0 <= k && k < R - L);
    T ret = 0;
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      if (k < kf) {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      } else {
        k -= kf, ret |= T(1) << d;
        if (!f) L += mid[d] - l0, R += mid[d] - r0;
        if (f) L = l0, R = r0;
      }
    }
    return (COMPRESS ? key[ret] : ret);
  }
};
