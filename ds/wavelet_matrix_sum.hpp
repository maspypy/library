#include "ds/bit_vector.hpp"
#include "alg/monoid/add.hpp"

// 座圧するかどうかを COMPRESS で指定する
// xor 的な使い方をする場合には、コンストラクタで log を渡すこと
template <typename T, bool COMPRESS, typename Monoid = Monoid_Add<T>>
struct Wavelet_Matrix_Sum {
  using MX = Monoid;
  using X = typename MX::value_type;
  int N, lg;
  vector<int> mid;
  vector<Bit_Vector> bv;
  vc<T> key;
  const T INF;
  const bool set_log;
  vvc<X> cumsum;

  Wavelet_Matrix_Sum(vc<T> A, int log = -1)
      : Wavelet_Matrix_Sum([](int a) -> X { return a; }, A, log) {}

  template <typename FUNC>
  Wavelet_Matrix_Sum(FUNC F, vector<T> A, int log = -1)
      : N(len(A)), lg(log), INF(numeric_limits<T>::max()), set_log(log != -1) {
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
    cumsum.assign(1 + lg, vc<X>(N + 1, MX::unit()));
    vc<T> A0(N), A1(N);
    FOR_R(d, -1, lg) {
      int p0 = 0, p1 = 0;
      FOR(i, N) {
        X x = F(COMPRESS ? key[A[i]] : A[i]);
        cumsum[d + 1][i + 1] = MX::op(cumsum[d + 1][i], x);
      }
      if (d == -1) break;
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

  // xor した結果が [a, b) に収まるものを数える
  // 個数および和を返す
  pair<int, X> count(int L, int R, T a, T b, T xor_val = 0) {
    auto [c1, s1] = prefix_count(L, R, a, xor_val);
    auto [c2, s2] = prefix_count(L, R, b, xor_val);
    return {c2 - c1, MX::op(MX::inverse(s1), s2)};
  }

  // xor した結果が [0, x) に収まるものを数える
  // 個数および和を返す
  pair<int, X> prefix_count(int L, int R, T x, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    x = (COMPRESS ? LB(key, x) : x);
    if (x >= (1 << lg)) return {R - L, get(lg, L, R)};
    int cnt = 0;
    X sm = MX::unit();
    FOR_R(d, lg) {
      bool add = (x >> d) & 1;
      bool f = ((xor_val) >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      if (add) {
        cnt += kf;
        if (f) {
          sm = MX::op(sm, get(d, L + mid[d] - l0, R + mid[d] - r0));
          L = l0, R = r0;
        } else {
          sm = MX::op(sm, get(d, l0, r0));
          L = L + mid[d] - l0, R = R + mid[d] - r0;
        }
      } else {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      }
    }
    return {cnt, sm};
  }

  // [L, R) の中で k 番目、および、下位 k 個の和
  // k = R-L のときの first は、INF を返す
  pair<T, X> kth(int L, int R, int k, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    if (k == R - L) return {INF, get(lg, L, R)};
    assert(0 <= k && k < R - L);
    T ret = 0;
    X sm = 0;
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      if (k < kf) {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      } else {
        k -= kf, ret |= T(1) << d;
        if (f) {
          sm = MX::op(sm, get(d, L + mid[d] - l0, R + mid[d] - r0));
          L = l0, R = r0;
        } else {
          sm = MX::op(sm, get(d, l0, r0));
          L = L + mid[d] - l0, R = R + mid[d] - r0;
        }
      }
    }
    if (k) sm = MX::op(sm, get(0, L, L + k));
    return {(COMPRESS ? key[ret] : ret), sm};
  }

  // check(prefix sum) が true となる上限の最大値
  template <typename F>
  T max_right_value(F check, int L, int R, T xor_val = 0) {
    assert(check(MX::unit()));
    if (xor_val != 0) assert(set_log);
    if (check(get(lg, L, R))) return INF;
    T ret = 0;
    X sm = MX::unit();
    for (int d = lg - 1; d >= 0; --d) {
      bool f = ((xor_val) >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      X lo_sm = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
      if (check(MX::op(sm, lo_sm))) {
        sm = MX::op(sm, lo_sm);
        ret |= 1 << d;
        if (f) L = l0, R = r0;
        if (!f) L = L + mid[d] - l0, R = R + mid[d] - r0;
      } else {
        if (!f) L = l0, R = r0;
        if (f) L = L + mid[d] - l0, R = R + mid[d] - r0;
      }
    }
    return (COMPRESS ? key[ret] : ret);
  }

  // check(prefix sum) が true となる加算個数の最大値
  template <typename F>
  int max_right_count(F check, int L, int R, T xor_val = 0) {
    assert(check(MX::unit()));
    if (xor_val != 0) assert(set_log);
    if (check(get(lg, L, R))) return R - L;
    int ret = 0;
    X sm = MX::unit();
    for (int d = lg - 1; d >= 0; --d) {
      bool f = (xor_val >> d) & 1;
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
      X lo_sm = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
      if (check(MX::op(sm, lo_sm))) {
        sm = MX::op(sm, lo_sm), ret += kf;
        if (f) L = l0, R = r0;
        if (!f) L += mid[d] - l0, R += mid[d] - r0;
      } else {
        if (!f) L = l0, R = r0;
        if (f) L += mid[d] - l0, R += mid[d] - r0;
      }
    }
    ret += binary_search(
        [&](int k) -> bool { return check(MX::op(sm, get(0, L, L + k))); }, 0,
        R - L);
    return ret;
  }

private:
  inline X get(int d, int L, int R) {
    return MX::op(MX::inverse(cumsum[d][L]), cumsum[d][R]);
  }
};
