#include "ds/bit_vector.hpp"
#include "alg/monoid/add.hpp"

// 座圧するかどうかを COMPRESS で指定する
// xor 的な使い方をする場合には、コンストラクタで log を渡すこと
template <typename T, bool COMPRESS, typename Monoid = Monoid_Add<T>>
struct Wavelet_Matrix {
  using MX = Monoid;
  using X = typename MX::value_type;
  static_assert(MX::commute);
  int N, lg;
  vector<int> mid;
  vector<Bit_Vector> bv;
  vc<T> key;
  const bool set_log;
  vvc<X> cumsum;

  // 和を使わないなら、SUM_data は空でよい
  Wavelet_Matrix(vc<T> A, vc<X> SUM_data = {}, int log = -1)
      : N(len(A)), lg(log), set_log(log != -1) {
    bool MAKE_SUM = !(SUM_data.empty());
    vc<X>& S = SUM_data;
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
    if (MAKE_SUM) cumsum.assign(1 + lg, vc<X>(N + 1, MX::unit()));
    S.resize(N);
    vc<T> A0(N), A1(N);
    vc<X> S0(N), S1(N);
    FOR_R(d, -1, lg) {
      int p0 = 0, p1 = 0;
      if (MAKE_SUM) {
        FOR(i, N) { cumsum[d + 1][i + 1] = MX::op(cumsum[d + 1][i], S[i]); }
      }
      if (d == -1) break;
      FOR(i, N) {
        bool f = (A[i] >> d & 1);
        if (!f) {
          if (MAKE_SUM) S0[p0] = S[i];
          A0[p0++] = A[i];
        }
        if (f) {
          if (MAKE_SUM) S1[p1] = S[i];
          bv[d].set(i), A1[p1++] = A[i];
        }
      }
      mid[d] = p0;
      bv[d].build();
      swap(A, A0), swap(S, S0);
      FOR(i, p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];
    }
  }

  // xor した結果で [a, b) に収まるものを数える
  int count(int L, int R, T a, T b, T xor_val = 0) {
    return prefix_count(L, R, b, xor_val) - prefix_count(L, R, a, xor_val);
  }

  // xor した結果で、[L, R) の中で k>=0 番目
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
    if (COMPRESS) ret = key[ret];
    return ret;
  }

  // xor した結果で、[L, R) の中で k>=0 番目と prefix sum
  pair<int, T> kth_value_and_sum(int L, int R, int k, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    assert(0 <= k && k <= R - L);
    if (k == R - L) { return {infty<T>, sum_all(L, R)}; }
    T ret = 0;
    X sm = MX::unit();
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      if (k < kf) {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      } else {
        X s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
        k -= kf, ret |= T(1) << d, sm = MX::op(sm, s);
        if (!f) L += mid[d] - l0, R += mid[d] - r0;
        if (f) L = l0, R = r0;
      }
    }
    if (k) sm = MX::op(sm, get(0, L, L + k));
    if (COMPRESS) ret = key[ret];
    return {ret, sm};
  }

  // xor した結果で、[L, R) の中で中央値。
  // LOWER = true：下側中央値、false：上側中央値
  T median(bool UPPER, int L, int R, T xor_val = 0) {
    int n = R - L;
    int k = (UPPER ? n / 2 : (n - 1) / 2);
    return kth(L, R, k, xor_val);
  }

  // xor した結果で [k1, k2) 番目であるところの SUM_data の和
  X sum(int L, int R, int k1, int k2, T xor_val = 0) {
    return prefix_sum(L, R, k2, xor_val) - prefix_sum(L, R, k1, xor_val);
  }

  X sum_all(int L, int R) {
    return MX::op(MX::inverse(cumsum[lg][L]), cumsum[lg][R]);
  }

  // check(cnt, prefix sum) が true となるような最大の (cnt, sum)
  template <typename F>
  pair<int, X> max_right(F check, int L, int R, T xor_val = 0) {
    assert(check(0, MX::unit()));
    if (xor_val != 0) assert(set_log);
    if (check(R - L, get(lg, L, R))) return R - L;
    int cnt = 0;
    X sm = MX::unit();
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      X s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
      if (check(cnt + c, MX::op(sm, s))) {
        cnt += c, sm = MX::op(sm, s);
        if (f) L = l0, R = r0;
        if (!f) L += mid[d] - l0, R += mid[d] - r0;
      } else {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      }
    }
    int k = binary_search(
        [&](int k) -> bool {
          return check(cnt + k, MX::op(sm, get(0, L, L + k)));
        },
        0, R - L);
    cnt += k;
    sm = MX::op(sm, get(0, L, L + k));
    return {cnt, sm};
  }

private:
  inline X get(int d, int L, int R) {
    return MX::op(MX::inverse(cumsum[d][L]), cumsum[d][R]);
  }

  // xor した結果で [0, x) に収まるものを数える
  int prefix_count(int L, int R, T x, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    x = (COMPRESS ? LB(key, x) : x);
    if (x == 0) return 0;
    if (x >= (1 << lg)) return R - L;
    int cnt = 0;
    FOR_R(d, lg) {
      bool add = (x >> d) & 1;
      bool f = ((xor_val) >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      if (add) {
        cnt += kf;
        if (f) { L = l0, R = r0; }
        if (!f) { L += mid[d] - l0, R += mid[d] - r0; }
      } else {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      }
    }
    return cnt;
  }

  // xor した結果で [0, k) 番目のものの和
  X prefix_sum(int L, int R, int k, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    assert(0 <= k && k <= R - L);
    if (k == 0) return MX::unit();
    if (k == R - L) return sum_all(L, R);
    assert(!cumsum.empty());

    X sm = MX::unit();
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      X s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
      if (k < c) {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      } else {
        k -= c, sm = MX::op(sm, s);
        if (f) { L = l0, R = r0; }
        if (!f) { L += mid[d] - l0, R += mid[d] - r0; }
      }
    }
    if (k) sm = MX::op(sm, get(0, L, L + k));
    return sm;
  }
};