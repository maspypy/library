#include "ds/bit_vector.hpp"
#include "ds/index_compression.hpp"
#include "alg/monoid/add.hpp"

// 静的メソッドinverseの存在をチェックするテンプレート
template <typename, typename = std::void_t<>>
struct has_inverse : std::false_type {};

template <typename T>
struct has_inverse<T, std::void_t<decltype(
                          T::inverse(std::declval<typename T::value_type>()))>>
    : std::true_type {};

struct Dummy_Data_Structure {
  using MX = Monoid_Add<bool>;
  void build(const vc<bool>& A) {}
};

template <typename Y, bool SMALL_Y, typename SEGTREE = Dummy_Data_Structure>
struct Wavelet_Matrix {
  using Mono = typename SEGTREE::MX;
  using T = typename Mono::value_type;
  static_assert(Mono::commute);

  int n, log, K;
  Index_Compression<Y, true, SMALL_Y> IDX;
  vc<int> mid;
  vc<Bit_Vector> bv;
  vc<SEGTREE> seg;

  Wavelet_Matrix() {}
  Wavelet_Matrix(const vc<Y>& A) { build(A); }
  Wavelet_Matrix(const vc<Y>& A, vc<T>& SUM_Data) { build(A, SUM_Data); }
  template <typename F>
  Wavelet_Matrix(int n, F f) {
    build(n, f);
  }

  template <typename F>
  void build(int m, F f) {
    vc<Y> A(m);
    vc<T> S(m);
    for (int i = 0; i < m; ++i) tie(A[i], S[i]) = f(i);
  }

  void build(const vc<Y>& A) { build(A, vc<T>(len(A), Mono::unit())); }
  void build(const vc<Y>& A, vc<T> S) {
    n = len(A);
    vc<int> B = IDX.build(A);
    K = 1;
    for (auto& x: B) chmax(K, x + 1);
    log = 0;
    while ((1 << log) < K) ++log;
    mid.resize(log), bv.assign(log, Bit_Vector(n));
    vc<int> B0(n), B1(n);
    vc<T> S0(n), S1(n);
    seg.resize(log + 1);
    seg[log].build(S);
    for (int d = log - 1; d >= 0; --d) {
      int p0 = 0, p1 = 0;
      for (int i = 0; i < n; ++i) {
        bool f = (B[i] >> d & 1);
        if (!f) { B0[p0] = B[i], S0[p0] = S[i], p0++; }
        if (f) { bv[d].set(i), B1[p1] = B[i], S1[p1] = S[i], p1++; }
      }
      swap(B, B0), swap(S, S0);
      move(B1.begin(), B1.begin() + p1, B.begin() + p0);
      move(S1.begin(), S1.begin() + p1, S.begin() + p0);
      mid[d] = p0, bv[d].build(), seg[d].build(S);
    }
  }

  // [L,R) x [0,y)
  int prefix_count(int L, int R, Y y) {
    int k = IDX(y);
    if (k == 0) return 0;
    if (k == K) return R - L;
    int cnt = 0;
    for (int d = log - 1; d >= 0; --d) {
      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);
      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;
      if (k >> d & 1) cnt += r0 - l0, L = l1, R = r1;
      if (!(k >> d & 1)) L = l0, R = r0;
    }
    return cnt;
  }

  // [L,R) x [y1,y2)
  int count(int L, int R, Y y1, Y y2) {
    return prefix_count(L, R, y2) - prefix_count(L, R, y1);
  }

  // [L,R) x [0,y)
  pair<int, T> prefix_count_and_prod(int L, int R, Y y) {
    int k = IDX(y);
    if (k == 0) return {0, Mono::unit()};
    if (k == K) return {R - L, seg[log].prod(L, R)};
    int cnt = 0;
    T ans = Mono::unit();
    for (int d = log - 1; d >= 0; --d) {
      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);
      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;
      if (k >> d & 1) {
        cnt += r0 - l0;
        ans = Mono::op(ans, seg[d].prod(l0, r0)), L = l1, R = r1;
      }
      if (!(k >> d & 1)) L = l0, R = r0;
    }
    return {cnt, ans};
  }

  // [L,R) x [y1,y2)
  pair<int, T> count_and_prod(int L, int R, Y y1, Y y2) {
    if constexpr (has_inverse<Mono>::value) {
      auto [c1, t1] = prefix_count_and_prod(L, R, y1);
      auto [c2, t2] = prefix_count_and_prod(L, R, y2);
      return {c2 - c1, Mono::op(Mono::inverse(t1), t2)};
    }
    int lo = IDX(y1), hi = IDX(y2), cnt = 0;
    T ans = Mono::unit();
    auto dfs = [&](auto& dfs, int d, int L, int R, int a, int b) -> void {
      assert(b - a == (1 << d));
      if (hi <= a || b <= lo) return;
      if (lo <= a && b <= hi) {
        cnt += R - L, ans = Mono::op(ans, seg[d].prod(L, R));
        return;
      }
      --d;
      int c = (a + b) / 2;
      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);
      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;
      dfs(dfs, d, l0, r0, a, c), dfs(dfs, d, l1, r1, c, b);
    };
    dfs(dfs, log, L, R, 0, 1 << log);
    return {cnt, ans};
  }

  // [L,R) x [y1,y2)
  T prefix_prod(int L, int R, Y y) { return prefix_count_and_prod(L, R, y).se; }
  // [L,R) x [y1,y2)
  T prod(int L, int R, Y y1, Y y2) { return count_and_prod(L, R, y1, y2).se; }
};

/*
// 座圧するかどうかを COMPRESS で指定する
// xor 的な使い方をする場合には、コンストラクタで log を渡すこと
template <typename T, bool COMPRESS, bool USE_SUM>
struct Wavelet_Matrix_Old {
  static_assert(is_same_v<T, int> || is_same_v<T, ll>);
  int N, lg;
  vector<int> mid;
  vector<Bit_Vector> bv;
  vc<T> key;
  bool set_log;
  vvc<T> cumsum;

  Wavelet_Matrix_Old() {}

  // 和を使わないなら、SUM_data は空でよい
  Wavelet_Matrix_Old(vc<T> A, vc<T> SUM_data = {}, int log = -1) {
    build(A, SUM_data, log);
  }

  void build(vc<T> A, vc<T> SUM_data = {}, int log = -1) {
    if constexpr (USE_SUM) { assert(len(SUM_data) == len(A)); }
    N = len(A), lg = log, set_log = (log != -1);
    if (N == 0) {
      lg = 0;
      cumsum.resize(1);
      cumsum[0] = {0};
      return;
    }
    vc<T>& S = SUM_data;
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
    mid.resize(lg), bv.assign(lg, Bit_Vector(N));
    if constexpr (USE_SUM) cumsum.assign(1 + lg, vc<T>(N + 1, 0));
    S.resize(N);
    vc<T> A0(N), A1(N);
    vc<T> S0(N), S1(N);
    FOR_R(d, -1, lg) {
      int p0 = 0, p1 = 0;
      if constexpr (USE_SUM) {
        FOR(i, N) { cumsum[d + 1][i + 1] = cumsum[d + 1][i] + S[i]; }
      }
      if (d == -1) break;
      FOR(i, N) {
        bool f = (A[i] >> d & 1);
        if (!f) {
          if constexpr (USE_SUM) S0[p0] = S[i];
          A0[p0++] = A[i];
        } else {
          if constexpr (USE_SUM) S1[p1] = S[i];
          bv[d].set(i), A1[p1++] = A[i];
        }
      }
      mid[d] = p0;
      bv[d].build();
      swap(A, A0), swap(S, S0);
      FOR(i, p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];
    }
  }

  // [L,R) x [a,b), (cnt, monoid value)
  pair<int, T> range_cnt_sum(int L, int R, T a, T b, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    if (a == b) return {0, 0};
    if (COMPRESS) a = LB(key, a), b = LB(key, b);
    int cnt = 0;
    T sm = 0;
    auto dfs = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void {
      if (rx <= a || b <= lx) return;
      if (a <= lx && rx <= b) {
        cnt += R - L, sm += get(d, L, R);
        return;
      }
      --d;
      T mx = (lx + rx) / 2;
      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);
      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;
      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);
      dfs(dfs, d, l0, r0, lx, mx), dfs(dfs, d, l1, r1, mx, rx);
    };
    dfs(dfs, lg, L, R, 0, T(1) << lg);
    return {cnt, sm};
  }

  // smallest k, sum of [0,k)
  pair<T, T> kth_value_sum(int L, int R, int k, T xor_val = 0) {
    assert(0 <= k && k <= R - L);
    if (k == R - L) { return {infty<T>, sum_all(L, R)}; }
    if (L == R) return {infty<T>, 0};
    if (xor_val != 0) assert(set_log);
    T sm = 0, val = 0;
    for (int d = lg - 1; d >= 0; --d) {
      // いま幅 d+1 の trie node に居て, 幅 d のところに行く
      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);
      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;
      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);
      if (k < r0 - l0) {
        L = l0, R = r0;
      } else {
        k -= r0 - l0, val |= T(1) << d, L = l1, R = r1;
        if constexpr (USE_SUM) sm += get(d, l0, r0);
      }
    }
    if constexpr (USE_SUM) sm += get(0, L, L + k);
    if (COMPRESS) val = key[val];

    return {val, sm};
  }

  int count(int L, int R, T a, T b, T xor_val = 0) {
    return range_cnt_sum(L, R, a, b, xor_val).fi;
  }
  T sum(int L, int R, T a, T b, T xor_val = 0) {
    static_assert(USE_SUM);
    return range_cnt_sum(L, R, a, b, xor_val).se;
  }

  T sum_index_range(int L, int R, int k1, int k2, T xor_val = 0) {
    static_assert(USE_SUM);
    return kth_value_sum(L, R, k2, xor_val).se
           - kth_value_sum(L, R, k1, xor_val).se;
  }
  T kth(int L, int R, int k, T xor_val = 0) {
    assert(0 <= k && k < R - L);
    return kth_value_sum(L, R, k, xor_val).fi;
  }

  // x 以上最小 OR infty<T>
  T next(int L, int R, T x, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    if (L == R) return infty<T>;
    if (COMPRESS) x = LB(key, x);
    T ans = infty<T>;

    auto dfs = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void {
      if (ans <= lx || L == R || rx <= x) return;
      if (d == 0) {
        chmin(ans, lx);
        return;
      }
      --d;
      T mx = (lx + rx) / 2;
      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);
      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;
      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);
      dfs(dfs, d, l0, r0, lx, mx), dfs(dfs, d, l1, r1, mx, rx);
    };
    dfs(dfs, lg, L, R, 0, T(1) << lg);
    if (COMPRESS && ans < infty<T>) ans = key[ans];
    return ans;
  }

  // x 以下最大 OR -infty<T>
  T prev(int L, int R, T x, T xor_val = 0) {
    if (xor_val != 0) assert(set_log);
    if (L == R) return -infty<T>;
    T ans = -infty<int>;
    ++x;
    if (COMPRESS) x = LB(key, x);

    auto dfs = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void {
      if ((rx - 1) <= ans || L == R || x <= lx) return;
      if (d == 0) {
        chmax(ans, lx);
        return;
      }
      --d;
      T mx = (lx + rx) / 2;
      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);
      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;
      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);
      dfs(dfs, d, l1, r1, mx, rx), dfs(dfs, d, l0, r0, lx, mx);
    };
    dfs(dfs, lg, L, R, 0, T(1) << lg);
    if (COMPRESS && ans != -infty<T>) ans = key[ans];
    return ans;
  }

  // xor した結果で、[L, R) の中で中央値。
  // LOWER = true：下側中央値、false：上側中央値
  T median(bool UPPER, int L, int R, T xor_val = 0) {
    int n = R - L;
    int k = (UPPER ? n / 2 : (n - 1) / 2);
    return kth(L, R, k, xor_val);
  }

  T sum_all(int L, int R) { return get(lg, L, R); }

  // check(cnt, prefix sum) が true となるような最大の (cnt, sum)
  template <typename F>
  pair<int, T> max_right(F check, int L, int R, T xor_val = 0) {
    assert(check(0, 0));
    if (xor_val != 0) assert(set_log);
    if (L == R) return {0, 0};
    if (check(R - L, get(lg, L, R))) return {R - L, get(lg, L, R)};
    int cnt = 0;
    T sm = 0;
    for (int d = lg - 1; d >= 0; --d) {
      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);
      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;
      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);
      if (check(cnt + r0 - l0, sm + get(d, l0, r0))) {
        cnt += r0 - l0, sm += get(d, l0, r0);
        L = l1, R = r1;
      } else {
        L = l0, R = r0;
      }
    }
    int k = binary_search(
        [&](int k) -> bool { return check(cnt + k, sm + get(0, L, L + k)); }, 0,
        R - L);
    cnt += k, sm += get(0, L, L + k);
    return {cnt, sm};
  }

private:
  inline T get(int d, int L, int R) {
    if constexpr (USE_SUM) return cumsum[d][R] - cumsum[d][L];
    return 0;
  }
};
*/
