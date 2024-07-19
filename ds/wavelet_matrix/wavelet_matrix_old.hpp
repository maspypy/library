#include "ds/bit_vector.hpp"

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