// BEGIN: main.cpp
#line 1 "main.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1036"
// BEGIN: my_template.hpp
#line 1 "my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else

// https://codeforces.com/blog/entry/96344
// https://codeforces.com/blog/entry/126772?#comment-1154880
#if defined(__GNUC__)
#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class T>
constexpr T infty = 0;
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
constexpr double infty<double> = numeric_limits<double>::infinity();
template <>
constexpr long double infty<long double> =
    numeric_limits<long double>::infinity();

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
#define FOR1_R(a) for (ll i = (a) - 1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

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
int popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }
int popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
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
T kth_bit(int k) {
  return T(1) << k;
}
template <typename T>
bool has_kth_bit(T x, int k) {
  return x >> k & 1;
}

template <typename UINT>
struct all_bit {
  struct iter {
    UINT s;
    iter(UINT s) : s(s) {}
    int operator*() const { return lowbit(s); }
    iter &operator++() {
      s &= s - 1;
      return *this;
    }
    bool operator!=(const iter) const { return s != 0; }
  };
  UINT s;
  all_bit(UINT s) : s(s) {}
  iter begin() const { return iter(s); }
  iter end() const { return iter(0); }
};

template <typename UINT>
struct all_subset {
  static_assert(is_unsigned<UINT>::value);
  struct iter {
    UINT s, t;
    bool ed;
    iter(UINT s) : s(s), t(s), ed(0) {}
    UINT operator*() const { return s ^ t; }
    iter &operator++() {
      (t == 0 ? ed = 1 : t = (t - 1) & s);
      return *this;
    }
    bool operator!=(const iter) const { return !ed; }
  };
  UINT s;
  all_subset(UINT s) : s(s) {}
  iter begin() const { return iter(s); }
  iter end() const { return iter(0); }
};

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

inline constexpr std::array<u64, 20> TEN_TAB = [] {
  std::array<u64, 20> a{};
  u64 x = 1;
  for (int i = 0; i <= 19; ++i) {
    a[i] = x, x *= 10;
  }
  return a;
}();

inline constexpr u64 TEN(int n) {
  assert(0 <= n && n <= 19);
  return TEN_TAB[n];
}

template <int N>
inline constexpr u64 TEN_v = [] {
  static_assert(0 <= N && N <= 19);
  return TEN_TAB[N];
}();

template <typename T, typename U>
T SUM(const U &A) {
  return std::accumulate(A.begin(), A.end(), T{});
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
  while (llabs(ok - ng) > 1) {
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
  vc<T> &res = first;
  (res.insert(res.end(), others.begin(), others.end()), ...);
}
#endif
// END: my_template.hpp
#line 3 "main.cpp"
// BEGIN: other/io.hpp
#line 1 "other/io.hpp"
#define FASTIO

// https://judge.yosupo.jp/submission/21623
namespace fastio {
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
char out[100];
// pointer of ibuf, obuf
uint32_t pil = 0, pir = 0, por = 0;

struct Pre {
  char num[10000][4];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i][j] = n % 10 | '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  memmove(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
  if (pir < SZ) ibuf[pir++] = '\n';
}

inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}

void rd(char &c) {
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
}

void rd(string &x) {
  x.clear();
  char c;
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
  do {
    x += c;
    if (pil == pir) load();
    c = ibuf[pil++];
  } while (!isspace(c));
}

template <typename T>
void rd_real(T &x) {
  string s;
  rd(s);
  x = stod(s);
}

template <typename T>
void rd_integer(T &x) {
  if (pil + 100 > pir) load();
  char c;
  do c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (c == '-') {
      minus = 1, c = ibuf[pil++];
    }
  }
  x = 0;
  while ('0' <= c) {
    x = x * 10 + (c & 15), c = ibuf[pil++];
  }
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (minus) x = -x;
  }
}

template <class T>
enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>> rd(
    T &x) {
  rd_integer(x);
}

template <class T>
enable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> rd(T &x) {
  rd_real(x);
}

template <class T, class U>
void rd(pair<T, U> &p) {
  rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T>
void rd_tuple(T &t) {
  if constexpr (N < tuple_size<T>::value) {
    auto &x = get<N>(t);
    rd(x);
    rd_tuple<N + 1>(t);
  }
}
template <class... T>
void rd(tuple<T...> &tpl) {
  rd_tuple(tpl);
}

template <size_t N = 0, typename T>
void rd(array<T, N> &x) {
  for (auto &d : x) rd(d);
}
template <class T>
void rd(vc<T> &x) {
  for (auto &d : x) rd(d);
}

void read() {}
template <class H, class... T>
void read(H &h, T &...t) {
  rd(h), read(t...);
}

// 先に用意（既出なら不要）
inline void wt_range(const char *s, size_t n) {
  size_t i = 0;
  while (i < n) {
    if (por == SZ) flush();
    size_t chunk = min(n - i, (size_t)(SZ - por));
    memcpy(obuf + por, s + i, chunk);
    por += chunk;
    i += chunk;
  }
}

void wt(const char c) {
  if (por == SZ) flush();
  obuf[por++] = c;
}
void wt(const char *s) { wt_range(s, strlen(s)); }
void wt(const string &s) { wt_range(s.data(), s.size()); }

template <typename T>
void wt_integer(T x) {
  if (por > SZ - 100) flush();
  if (x < 0) {
    obuf[por++] = '-', x = -x;
  }
  int outi;
  for (outi = 96; x >= 10000; outi -= 4) {
    memcpy(out + outi, pre.num[x % 10000], 4);
    x /= 10000;
  }
  if (x >= 1000) {
    memcpy(obuf + por, pre.num[x], 4);
    por += 4;
  } else if (x >= 100) {
    memcpy(obuf + por, pre.num[x] + 1, 3);
    por += 3;
  } else if (x >= 10) {
    int q = (x * 103) >> 10;
    obuf[por] = q | '0';
    obuf[por + 1] = (x - q * 10) | '0';
    por += 2;
  } else
    obuf[por++] = x | '0';
  memcpy(obuf + por, out + outi + 4, 96 - outi);
  por += 96 - outi;
}

template <typename T>
inline void wt_real(T x) {
  char buf[64];
  // 有効数字 15 桁、通常/指数を自動選択（printf("%.15g") 相当）
  int n = std::snprintf(buf, sizeof(buf), "%.15g", (double)x);

  // （任意）-0 を 0 に正規化
  if (n == 2 && buf[0] == '-' && buf[1] == '0') {
    buf[0] = '0';
    n = 1;
  }
  wt_range(buf, (size_t)n);
}

template <class T>
enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>> wt(
    T x) {
  wt_integer(x);
}

template <class T>
enable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> wt(T x) {
  wt_real(x);
}

inline void wt(bool b) { wt(static_cast<char>('0' + (b ? 1 : 0))); }

template <class T, class U>
void wt(const pair<T, U> &val) {
  wt(val.first);
  wt(' ');
  wt(val.second);
}
template <size_t N = 0, typename T>
void wt_tuple(const T &t) {
  if constexpr (N < tuple_size<T>::value) {
    if constexpr (N > 0) wt(' ');
    wt(get<N>(t));
    wt_tuple<N + 1>(t);
  }
}
template <class... T>
void wt(const tuple<T...> &tpl) {
  wt_tuple(tpl);
}
template <class T, size_t S>
void wt(const array<T, S> &val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}
template <class T>
void wt(const vector<T> &val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}

void print() { wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail) {
  wt(head);
  if (sizeof...(Tail)) wt(' ');
  print(forward<Tail>(tail)...);
}

// gcc expansion. called automaticall after main.
void __attribute__((destructor)) _d() { flush(); }
}  // namespace fastio
using fastio::flush;
using fastio::print;
using fastio::read;

#if defined(LOCAL)
using fastio::wt;
#define P1(x)                                                                \
  wt("[DEBUG "), wt(__func__), wt(":"), wt((int)__LINE__), wt("] "), wt(#x), \
      wt(" = "), wt(x)
#define P_(x) wt(", "), wt(#x), wt(" = "), wt(x)

#define SHOW1(a) P1(a), wt("\n")
#define SHOW2(a, b) P1(a), P_(b), wt("\n")
#define SHOW3(a, b, c) P1(a), P_(b), P_(c), wt("\n")
#define SHOW4(a, b, c, d) P1(a), P_(b), P_(c), P_(d), wt("\n")
#define SHOW5(a, b, c, d, e) P1(a), P_(b), P_(c), P_(d), P_(e), wt("\n")
#define SHOW6(a, b, c, d, e, f) \
  P1(a), P_(b), P_(c), P_(d), P_(e), P_(f), wt("\n")
#define SHOW7(a, b, c, d, e, f, g) \
  P1(a), P_(b), P_(c), P_(d), P_(e), P_(f), P_(g), wt("\n")
#define SHOW8(a, b, c, d, e, f, g, h) \
  P1(a), P_(b), P_(c), P_(d), P_(e), P_(f), P_(g), P_(h), wt("\n")

#define SHOW_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define SHOW(...)                                                         \
  SHOW_IMPL(__VA_ARGS__, SHOW8, SHOW7, SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, \
            SHOW1)                                                        \
  (__VA_ARGS__)
#else
#define SHOW(...)
#endif

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define U32(...)   \
  u32 __VA_ARGS__; \
  read(__VA_ARGS__)
#define U64(...)   \
  u64 __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
void YA(bool t = 1) { print(t ? "YA" : "TIDAK"); }
void TIDAK(bool t = 1) { YA(!t); }
// END: other/io.hpp
#line 4 "main.cpp"
// BEGIN: ds/segtree/dynamic_segtree.hpp
#line 1 "ds/segtree/dynamic_segtree.hpp"
// BEGIN: alg/default_prod.hpp
#line 1 "alg/default_prod.hpp"
template <class Monoid>
struct DefaultUnitProd {
  using X = typename Monoid::value_type;
  static constexpr bool unit_only = true;
  X operator()(long long, long long) const { return Monoid::unit(); }
};
// END: alg/default_prod.hpp
#line 2 "ds/segtree/dynamic_segtree.hpp"

/*
要素数の管理が面倒なので, vector<int> を使うようにした.
参照を持っているときに eb が入ると破壊されることに気を付ける必要がある！
*/
template <typename Monoid, bool PERSISTENT,
          class DefaultProd = DefaultUnitProd<Monoid>>
struct Dynamic_SegTree {
  using MX = Monoid;
  using X = typename MX::value_type;
  struct Node {
    int ch[2];
    X x;
  };

  const ll L0, R0;
  DefaultProd default_prod;
  vc<Node> node;
  static constexpr int NIL = 0;

  Dynamic_SegTree(ll L0_, ll R0_, DefaultProd func = DefaultProd{})
      : L0(L0_), R0(L0_ == R0_ ? R0_ + 1 : R0_), default_prod(std::move(func)) {
    reset();
  }

  void reserve(int n) { node.reserve(n + 1); }
  void reset() { node.clear(), node.eb(Node{NIL, NIL, MX::unit()}); }

  inline X get_prod(int i, ll l, ll r) {
    if constexpr (kUnitOnly) {
      return node[i].x;
    } else {
      return (i == NIL ? default_prod(l, r) : node[i].x);
    }
  }
  void update(int i, ll l, ll r) {
    assert(l + 1 < r);
    ll m = (l + r) / 2;
    int L = node[i].ch[0], R = node[i].ch[1];
    node[i].x = MX::op(get_prod(L, l, m), get_prod(R, m, r));
  }

  inline int new_root() { return new_node(L0, R0); }

  inline int new_node(const X &x) {
    node.emplace_back(Node{NIL, NIL, x});
    return int(node.size()) - 1;
  }

  inline int new_node(ll l, ll r) { return new_node(default_prod(l, r)); }
  inline int new_node() { return new_node(L0, R0); }
  inline Node operator[](int i) const { return node[i]; }

  int new_node_from_vector(const vc<X> &dat) {
    assert(L0 == 0 && R0 == len(dat));
    auto dfs = [&](auto &dfs, ll l, ll r) -> int {
      if (r == l + 1) return new_node(dat[l]);
      ll m = (l + r) / 2;
      int l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);
      X x = MX::op(node[l_root].x, node[r_root].x);
      node.eb(Node{l_root, r_root, x});
      return int(node.size()) - 1;
    };
    return dfs(dfs, 0, len(dat));
  }

  X prod(int root, ll l, ll r) {
    assert(root != NIL && L0 <= l && l <= r && r <= R0);
    if (l == r) return MX::unit();
    X x = MX::unit();
    prod_rec(root, L0, R0, l, r, x);
    return x;
  }

  X prod_all(int root) { return node[root].x; }

  int set(int root, ll i, const X &x) {
    assert(root != NIL && L0 <= i && i < R0);
    root = copy_node(root);
    set_rec(root, L0, R0, i, x);
    return root;
  }

  int multiply(int root, ll i, const X &x) {
    assert(root != NIL && L0 <= i && i < R0);
    root = copy_node(root);
    multiply_rec(root, L0, R0, i, x);
    return root;
  }

  template <typename F>
  ll max_right(int root, F check, ll L) {
    assert(root != NIL && L0 <= L && L <= R0 && check(MX::unit()));
    X x = MX::unit();
    return max_right_rec(root, check, L0, R0, L, x);
  }

  template <typename F>
  ll min_left(int root, F check, ll R) {
    assert(root != NIL && L0 <= R && R <= R0 && check(MX::unit()));
    X x = MX::unit();
    return min_left_rec(root, check, L0, R0, R, x);
  }

  // (idx, val)
  template <typename F>
  void enumerate(int root, F f) {
    assert(root != NIL);
    auto dfs = [&](auto &dfs, int c, ll l, ll r) -> void {
      if (c == NIL) return;
      if (r - l == 1) {
        f(l, node[c].x);
        return;
      }
      ll m = (l + r) / 2;
      dfs(dfs, node[c].ch[0], l, m), dfs(dfs, node[c].ch[1], m, r);
    };
    dfs(dfs, root, L0, R0);
  }

 private:
  static constexpr bool kUnitOnly =
      std::is_same_v<DefaultProd, DefaultUnitProd<Monoid>>;
  int copy_node(int c) {
    if constexpr (!PERSISTENT) return c;
    if (c == NIL) return c;
    node.eb(node[c]);
    return int(node.size()) - 1;
  }

  int touch_child(int c, ll l, ll r) {
    if constexpr (!PERSISTENT) {
      return (c == NIL ? new_node(l, r) : c);
    } else {
      return (c == NIL ? new_node(l, r) : copy_node(c));
    }
  }

  void set_rec(int c, ll l, ll r, ll i, const X &x) {
    assert(c != NIL);
    // もう c は新しくしてある
    if (r == l + 1) {
      node[c].x = x;
      return;
    }
    ll m = (l + r) / 2;
    int b = (m <= i);
    ll nl = (b ? m : l), nr = (b ? r : m);
    node[c].ch[b] = touch_child(node[c].ch[b], nl, nr);
    set_rec(node[c].ch[b], nl, nr, i, x);
    update(c, l, r);
  }

  void multiply_rec(int c, ll l, ll r, ll i, const X &x) {
    assert(c != NIL);
    // もう c は新しくしてある
    if (r == l + 1) {
      node[c].x = MX::op(node[c].x, x);
      return;
    }
    ll m = (l + r) / 2;
    int b = (m <= i);
    ll nl = (b ? m : l), nr = (b ? r : m);
    node[c].ch[b] = touch_child(node[c].ch[b], nl, nr);
    multiply_rec(node[c].ch[b], nl, nr, i, x);
    update(c, l, r);
  }

  void prod_rec(int c, ll l, ll r, ll ql, ll qr, X &x) {
    chmax(ql, l), chmin(qr, r);
    if (ql >= qr) return;
    if (c == NIL || (l == ql && r == qr)) {
      x = MX::op(x, get_prod(c, ql, qr));
      return;
    }
    ll m = (l + r) / 2;
    prod_rec(node[c].ch[0], l, m, ql, qr, x);
    prod_rec(node[c].ch[1], m, r, ql, qr, x);
  }

  template <typename F>
  ll max_right_rec(int c, const F &check, ll l, ll r, ll ql, X &x) {
    if (r <= ql) return R0;
    X myprod = get_prod(c, l, r);
    if (ql <= l && check(MX::op(x, myprod))) {
      x = MX::op(x, myprod);
      return R0;
    }
    if (r == l + 1) return l;
    ll m = (l + r) / 2;
    ll k = max_right_rec(node[c].ch[0], check, l, m, ql, x);
    if (k != R0) return k;
    return max_right_rec(node[c].ch[1], check, m, r, ql, x);
  }

  // これ new node 作ってるのはさぼり
  template <typename F>
  ll min_left_rec(int c, const F &check, ll l, ll r, ll qr, X &x) {
    if (qr <= l) return L0;
    X myprod = get_prod(c, l, r);
    if (r <= qr && check(MX::op(myprod, x))) {
      x = MX::op(x, myprod);
      return L0;
    }
    if (r == l + 1) return r;
    ll m = (l + r) / 2;
    ll k = min_left_rec(node[c].ch[1], check, m, r, qr, x);
    if (k != L0) return k;
    return min_left_rec(node[c].ch[0], check, l, m, qr, x);
  }
};
// END: ds/segtree/dynamic_segtree.hpp
#line 5 "main.cpp"
// BEGIN: alg/monoid/gcd.hpp
#line 1 "alg/monoid/gcd.hpp"

template <typename X>
struct Monoid_Gcd {
  using value_type = X;
  static X op(X x, X y) { return gcd(x, y); }
  static constexpr X unit() { return 0; }
  static constexpr bool commute = true;
};
// END: alg/monoid/gcd.hpp
#line 6 "main.cpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  auto f = [&](ll L, ll R) -> ll { return 0; };
  Dynamic_SegTree<Monoid_Gcd<ll>, false> seg(0, N, f);
  seg.reserve(2 * N);
  int root = seg.new_node_from_vector(A);

  ll ANS1 = 0;
  FOR(L, N) {
    auto check = [&](auto e) -> bool { return e != 1; };
    auto R = seg.max_right(root, check, L);
    ANS1 += N - R;
  }
  ll ANS2 = 0;
  FOR(R, 1, N + 1) {
    auto check = [&](auto e) -> bool { return e != 1; };
    auto L = seg.min_left(root, check, R);
    ANS2 += L;
  }
  assert(ANS1 == ANS2);
  print(ANS1);
}

signed main() {
  solve();
  return 0;
}
// END: main.cpp
