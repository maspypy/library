#line 1 "main.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#line 1 "library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else

// https://codeforces.com/blog/entry/96344
#pragma GCC optimize("Ofast,unroll-loops")
// いまの CF だとこれ入れると動かない？
// #pragma GCC target("avx2,popcnt")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000;
template <>
constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) \
  for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_mod_2(int x) { return __builtin_parity(x); }
int popcnt_mod_2(u32 x) { return __builtin_parity(x); }
int popcnt_mod_2(ll x) { return __builtin_parityll(x); }
int popcnt_mod_2(u64 x) { return __builtin_parityll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return floor(x + y - 1, y);
}
template <typename T>
T bmod(T x, T y) {
  return x - y * floor(x, y);
}
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

template <typename T, typename U>
T SUM(const vector<U> &A) {
  T sm = 0;
  for (auto &&a: A) sm += a;
  return sm;
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <typename T>
T POP(pq<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(pqg<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
  if (check_ok) assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    (check(x) ? ok : ng) = x;
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    (check(x) ? ok : ng) = x;
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

// ? は -1
vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vector<T> cumsum(vector<U> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

// stable sort
template <typename T>
vector<int> argsort(const vector<T> &A) {
  vector<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  vc<T> B(len(I));
  FOR(i, len(I)) B[i] = A[I[i]];
  return B;
}
#endif
#line 3 "main.cpp"

#line 1 "library/ds/bit_vector.hpp"
struct Bit_Vector {
  vc<pair<u32, u32>> dat;
  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }

  void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }

  void build() {
    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);
  }

  // [0, k) 内の 1 の個数
  int rank(int k, bool f = 1) {
    auto [a, b] = dat[k >> 5];
    int ret = b + popcnt(a & ((u32(1) << (k & 31)) - 1));
    return (f ? ret : k - ret);
  }
};
#line 2 "library/ds/wavelet_matrix/wavelet_matrix.hpp"

// 座圧するかどうかを COMPRESS で指定する
// xor 的な使い方をする場合には、コンストラクタで log を渡すこと
template <typename T, bool COMPRESS, bool USE_SUM>
struct Wavelet_Matrix {
  static_assert(is_same_v<T, int> || is_same_v<T, ll>);
  int N, lg;
  vector<int> mid;
  vector<Bit_Vector> bv;
  vc<T> key;
  bool set_log;
  vvc<T> cumsum;

  Wavelet_Matrix() {}

  // 和を使わないなら、SUM_data は空でよい
  Wavelet_Matrix(vc<T> A, vc<T> SUM_data = {}, int log = -1) {
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
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
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
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
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
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
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
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
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
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
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
#line 2 "library/random/base.hpp"

u64 RNG_64() {
  static uint64_t x_
      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(
                     chrono::high_resolution_clock::now().time_since_epoch())
                     .count())
        * 10150724397891781847ULL;
  x_ ^= x_ << 7;
  return x_ ^= x_ >> 9;
}

u64 RNG(u64 lim) { return RNG_64() % lim; }

ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }
#line 6 "main.cpp"

void test_compress(int N) {
  int MAX = RNG(2, 1 << 10);
  vc<int> A(N);
  vc<int> X(N);
  FOR(i, N) X[i] = RNG(MAX);
  FOR(i, N) A[i] = RNG(MAX);

  Wavelet_Matrix<int, true, true> WM(A, X);

  int Q = 100;
  FOR(Q) {
    int L = RNG(0, max(1, N));
    int R = RNG(0, max(1, N + 1));
    if (L > R) swap(L, R);
    int lo = RNG(0, MAX);
    int hi = RNG(0, MAX);
    if (lo > hi) swap(lo, hi);
    ++hi;
    vc<int> B = {A.begin() + L, A.begin() + R};
    vc<int> Y = {X.begin() + L, X.begin() + R};

    int t = RNG(0, 7);
    if (t == 0) { // count
      int cnt = 0;
      for (auto&& x: B)
        if (lo <= x && x < hi) cnt += 1;
      assert(WM.count(L, R, lo, hi) == cnt);
    }
    if (t == 1) { // sm
      int sm = 0;
      FOR(i, L, R) if (lo <= A[i] && A[i] < hi) sm += X[i];
      assert(WM.sum(L, R, lo, hi) == sm);
    }
    if (t == 2) { // kth
      if (L == R) continue;
      int k = RNG(R - L);
      sort(all(B));
      assert(WM.kth(L, R, k) == B[k]);
    }
    if (t == 3) { // max_right
      int a = RNG(0, 10);
      int b = RNG(0, 10);
      int c = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);
      auto check
          = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };
      auto p = WM.max_right(check, L, R);
      int k = binary_search(
          [&](int k) -> bool {
            int sm = WM.sum_index_range(L, R, 0, k);
            return check(k, sm);
          },
          0, R - L + 1);
      int sm = WM.sum_index_range(L, R, 0, k);
      assert(p.fi == k && p.se == sm);
    }
    if (t == 4) { // k-th value and sum
      int k = RNG(0, R - L + 1);
      B.eb(infty<int>);
      auto I = argsort(B);
      int val = B[I[k]];
      int sm = 0;
      FOR(i, k) sm += Y[I[i]];
      auto p = WM.kth_value_sum(L, R, k);
      assert(p.fi == val && p.se == sm);
    }
    if (t == 5) { // next
      int x = RNG(-1, MAX + 2);
      int ans = infty<int>;
      for (auto& b: B) {
        if (x <= b) chmin(ans, b);
      }
      assert(ans == WM.next(L, R, x));
    }
    if (t == 6) { // prev
      int x = RNG(-1, MAX + 1);
      int ans = -infty<int>;
      for (auto& b: B) {
        if (b <= x) chmax(ans, b);
      }
      assert(ans == WM.prev(L, R, x));
    }
  }
}

void test_not_compress(int N) {
  int log = RNG(1, 7);
  int MAX = 1 << log;
  vc<int> A(N);
  vc<int> X(N);
  FOR(i, N) X[i] = RNG(0, MAX);
  FOR(i, N) A[i] = RNG(MAX);
  Wavelet_Matrix<int, false, true> WM(A, X, log);

  int Q = 100;
  FOR(Q) {
    int L = RNG(0, max(1, N));
    int R = RNG(0, max(1, N + 1));
    if (L > R) swap(L, R);
    int lo = RNG(0, MAX);
    int hi = RNG(0, MAX);
    int xor_val = RNG(0, MAX);
    if (lo > hi) swap(lo, hi);
    ++hi;
    vc<int> B = {A.begin() + L, A.begin() + R};
    vc<int> Y = {X.begin() + L, X.begin() + R};
    for (auto&& x: B) x ^= xor_val;

    int t = RNG(0, 7);
    if (t == 0) { // count
      int cnt = 0;
      for (auto&& x: B) {
        if (lo <= x && x < hi) cnt += 1;
      }
      assert(WM.count(L, R, lo, hi, xor_val) == cnt);
    }
    if (t == 1) { // sm
      int sm = 0;
      FOR(i, len(B)) if (lo <= B[i] && B[i] < hi) sm += Y[i];
      assert(WM.sum(L, R, lo, hi, xor_val) == sm);
    }
    if (t == 2) { // kth
      if (L == R) continue;
      int k = RNG(R - L);
      sort(all(B));
      assert(WM.kth(L, R, k, xor_val) == B[k]);
    }
    if (t == 3) { // max_right
      int a = RNG(0, 10);
      int b = RNG(0, 10);
      int c = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);
      auto check
          = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };
      auto p = WM.max_right(check, L, R, xor_val);
      int k = binary_search(
          [&](int k) -> bool {
            int sm = WM.sum_index_range(L, R, 0, k, xor_val);
            return check(k, sm);
          },
          0, R - L + 1);
      int sm = WM.sum_index_range(L, R, 0, k, xor_val);
      assert(k == p.fi && sm == p.se);
    }
    if (t == 4) { // k-th value and sum
      int k = RNG(0, R - L + 1);
      B.eb(infty<int>);
      auto I = argsort(B);
      int val = B[I[k]];
      int sm = 0;
      FOR(i, k) sm += Y[I[i]];
      auto p = WM.kth_value_sum(L, R, k, xor_val);
      assert(p.fi == val && p.se == sm);
    }
    if (t == 5) { // next
      int x = RNG(-1, MAX + 2);
      int ans = infty<int>;
      for (auto& b: B) {
        if (x <= b) chmin(ans, b);
      }
      assert(ans == WM.next(L, R, x, xor_val));
    }
    if (t == 6) { // prev
      int x = RNG(-1, MAX + 1);
      int ans = -infty<int>;
      for (auto& b: B) {
        if (b <= x) chmax(ans, b);
      }
      assert(ans == WM.prev(L, R, x, xor_val));
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(N, 64) { FOR(50) test_compress(N); }
  FOR(N, 64) { FOR(50) test_not_compress(N); }
  solve();

  return 0;
}
