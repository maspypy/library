#if defined(USE_PCH)
#include <my_template_compiled.hpp>
#else
#if defined(__GNUC__)
#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
// 環境によってはコンパイル成功かつ実行時エラー
#pragma GCC target("avx2,popcnt")
#endif
#include <bits/stdc++.h>
#include <cassert>

using namespace std;

using ll = long long;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class>
constexpr bool dependent_false = false;

template <class T>
constexpr T infty = [] {
  static_assert(dependent_false<T>, "infty<T> is not defined");
  return T{};
}();
template <>
constexpr int infty<int> = 1'010'000'000;
template <>
constexpr ll infty<ll> = 2'020'000'000'000'000'000;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;
template <>
constexpr double infty<double> = infty<i128>;
template <>
constexpr long double infty<long double> = infty<i128>;

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
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

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
#define FOR1_R(a) for (ll i = ll(a) - 1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = ll(a) - 1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define all(x) (x).begin(), (x).end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

// require y > 0
template <typename T>
T floor(T x, T y) {
  return x / y - (x % y < 0);
}

// require y > 0
template <typename T>
T ceil(T x, T y) {
  return (x / y) + (x % y > 0);
}

// require y > 0
template <typename T>
T bmod(T x, T y) {
  T r = x % y;
  return (r < 0 ? r + y : r);
}

// require y > 0
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = x / y, r = x % y;
  if (r < 0) --q, r += y;
  return {q, r};
}

constexpr auto TEN = [] {
  array<u64, 20> A{};
  A[0] = 1;
  for (int i = 1; i < 20; ++i) A[i] = 10 * A[i - 1];
  return A;
}();

template <typename T, typename U>
T SUM(const U &A) {
  return std::accumulate(A.begin(), A.end(), T{});
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
template <class C, class T>
inline long long LB(const C &c, const T &x) {
  return lower_bound(c.begin(), c.end(), x) - c.begin();
}
template <class C, class T>
inline long long UB(const C &c, const T &x) {
  return upper_bound(c.begin(), c.end(), x) - c.begin();
}
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <class T, class Container, class Compare>
T POP(priority_queue<T, Container, Compare> &que) {
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
  while (1) {
    ll x = (ok + ng) / 2;
    if (x == ok || x == ng) break;
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
  T c = max<T>(a, b);
  bool changed = (c != a);
  a = c;
  return changed;
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  T c = min<T>(a, b);
  bool changed = (c != a);
  a = c;
  return changed;
}

// ? は -1
vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vc<T> cumsum(const vc<U> &A, int off = 1) {
  int N = A.size();
  vc<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

// stable sort
template <typename T>
vc<int> argsort(const vc<T> &A) {
  vc<int> ids(len(A));
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

template <typename T, typename... Vectors>
void concat(vc<T> &first, const Vectors &...others) {
  first.reserve(first.size() + (others.size() + ... + 0));
  (first.insert(first.end(), others.begin(), others.end()), ...);
}

// i128
template <class T, enable_if_t<is_same_v<T, i128>, int> = 0>
constexpr i128 abs(T x) {
  return x < 0 ? -x : x;
}

constexpr i128 gcd(i128 a, i128 b) {
  while (b != 0) {
    i128 c = a % b;
    a = b, b = c;
  }
  return abs(a);
}
#endif
