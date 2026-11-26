---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/sliding_window_aggregation.hpp
    title: ds/sliding_window_aggregation.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"my_template.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n\
    #if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\n#if defined(__GNUC__)\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#if !defined(MASPY_NON_AVX2)\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#endif\n\n#else  // MASPY_TEMPLATE_BODY\n\
    #include <bits/stdc++.h>\n#include <cassert>\n\n#if defined(__GNUC__)\n#pragma\
    \ GCC optimize(\"Ofast,unroll-loops\")\n#endif\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false =\
    \ false;\n\ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 4'040'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 4'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<i128>;\ntemplate <>\nconstexpr long double infty<long double> = infty<i128>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing pq_max = priority_queue<T>;\ntemplate <class T>\nusing\
    \ pq_min = priority_queue<T, vector<T>, greater<T>>;\n\n#define vv(type, name,\
    \ h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define\
    \ vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name( \\\n \
    \     h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR1_R(a)\
    \ for (ll i = ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a)\
    \ - 1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload3(__VA_ARGS__,\
    \ FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R,\
    \ FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define all(x) (x).begin(), (x).end()\n#define\
    \ len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\n\
    #define stoi stoll\n\n// require y > 0\ntemplate <typename T>\nT floor(T x, T\
    \ y) {\n  return x / y - (x % y < 0);\n}\n\n// require y > 0\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return (x / y) + (x % y > 0);\n}\n\n// require y >\
    \ 0\ntemplate <typename T>\nT bmod(T x, T y) {\n  T r = x % y;\n  return (r <\
    \ 0 ? r + y : r);\n}\n\n// require y > 0\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = x / y, r = x % y;\n  if (r < 0) --q, r += y;\n  return {q,\
    \ r};\n}\n\nconstexpr auto TEN = [] {\n  array<u64, 20> A{};\n  A[0] = 1;\n  for\
    \ (int i = 1; i < 20; ++i) A[i] = 10 * A[i - 1];\n  return A;\n}();\n\ntemplate\
    \ <typename T, typename U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(),\
    \ A.end(), T{});\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    template <class C, class T>\ninline long long LB(const C &c, const T &x) {\n \
    \ return lower_bound(c.begin(), c.end(), x) - c.begin();\n}\ntemplate <class C,\
    \ class T>\ninline long long UB(const C &c, const T &x) {\n  return upper_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end())\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n\
    \  que.pop_front();\n  return a;\n}\ntemplate <class T, class Container, class\
    \ Compare>\nT POP(priority_queue<T, Container, Compare> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T\
    \ a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\n\
    i128 binary_search(F check, i128 ok, i128 ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (1) {\n    i128 x = (ok + ng) / 2;\n    if (x ==\
    \ ok || x == ng) break;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\
    \ntemplate <typename F>\ndouble binary_search_real(F check, double ok, double\
    \ ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class\
    \ S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a, b);\n  bool changed\
    \ = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class T, class S>\ninline\
    \ bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n  bool changed = (c !=\
    \ a);\n  a = c;\n  return changed;\n}\n\n// bit operations\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ T>\nstruct all_bit {\n  static_assert(is_integral<T>::value);\n  T s;\n  all_bit(T\
    \ s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ T>\nstruct all_subset {\n  static_assert(is_integral<T>::value);\n  T s;\n \
    \ all_subset(T s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s, t;\n \
    \   bool done = false;\n    T operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n\
    \  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n      [&](int i, int j) { return (A[i] == A[j] ? i <\
    \ j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n\
    \  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\ntemplate <typename T, typename...\
    \ Vectors>\nvoid concat(vc<T> &first, const Vectors &...others) {\n  first.reserve(first.size()\
    \ + (others.size() + ... + 0));\n  (first.insert(first.end(), others.begin(),\
    \ others.end()), ...);\n}\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T,\
    \ i128>, int> = 0>\nconstexpr i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\n\
    constexpr i128 gcd(i128 a, i128 b) {\n  while (b != 0) {\n    i128 c = a % b;\n\
    \    a = b, b = c;\n  }\n  return abs(a);\n}\n#endif  // MASPY_TEMPLATE_BODY\n\
    #line 1 \"ds/sliding_window_aggregation.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/sliding_window_aggregation.hpp\n\
    template <class Monoid>\nstruct Sliding_Window_Aggregation {\n  using X = typename\
    \ Monoid::value_type;\n  using value_type = X;\n  int sz = 0;\n  vc<X> dat;\n\
    \  vc<X> cum_l;\n  X cum_r;\n\n  Sliding_Window_Aggregation()\n      : cum_l({Monoid::id()}),\
    \ cum_r(Monoid::id()) {}\n\n  int size() { return sz; }\n\n  void push(X x) {\n\
    \    ++sz;\n    cum_r = Monoid::op(cum_r, x);\n    dat.eb(x);\n  }\n\n  void pop()\
    \ {\n    --sz;\n    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n      cum_l\
    \ = {Monoid::id()};\n      cum_r = Monoid::id();\n      while (len(dat) > 1) {\n\
    \        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n        dat.pop_back();\n\
    \      }\n      dat.pop_back();\n    }\n  }\n\n  X lprod() { return cum_l.back();\
    \ }\n  X rprod() { return cum_r; }\n\n  X prod() { return Monoid::op(cum_l.back(),\
    \ cum_r); }\n};\n\n// \u5B9A\u6570\u500D\u306F\u76EE\u306B\u898B\u3048\u3066\u9045\
    \u304F\u306A\u308B\u306E\u3067\u3001queue \u3067\u3088\u3044\u3068\u304D\u306F\
    \u4F7F\u308F\u306A\u3044\ntemplate <class Monoid>\nstruct Sliding_Window_Aggregation_Deque\
    \ {\n  using X = typename Monoid::value_type;\n  using value_type = X;\n  int\
    \ sz;\n  vc<X> dat_l, dat_r;\n  vc<X> cum_l, cum_r;\n\n  Sliding_Window_Aggregation_Deque()\n\
    \      : sz(0), cum_l({Monoid::id()}), cum_r({Monoid::id()}) {}\n\n  int size()\
    \ { return sz; }\n\n  void push_back(X x) {\n    ++sz;\n    dat_r.eb(x);\n   \
    \ cum_r.eb(Monoid::op(cum_r.back(), x));\n  }\n\n  void push_front(X x) {\n  \
    \  ++sz;\n    dat_l.eb(x);\n    cum_l.eb(Monoid::op(x, cum_l.back()));\n  }\n\n\
    \  void push(X x) { push_back(x); }\n\n  void clear() {\n    sz = 0;\n    dat_l.clear(),\
    \ dat_r.clear();\n    cum_l = {Monoid::id()}, cum_r = {Monoid::id()};\n  }\n\n\
    \  void pop_front() {\n    if (sz == 1) return clear();\n    if (dat_l.empty())\
    \ rebuild();\n    --sz;\n    dat_l.pop_back();\n    cum_l.pop_back();\n  }\n\n\
    \  void pop_back() {\n    if (sz == 1) return clear();\n    if (dat_r.empty())\
    \ rebuild();\n    --sz;\n    dat_r.pop_back();\n    cum_r.pop_back();\n  }\n\n\
    \  void pop() { pop_front(); }\n\n  X front() {\n    if (len(dat_l)) return dat_l.back();\n\
    \    return dat_r[0];\n  }\n\n  X lprod() { return cum_l.back(); }\n  X rprod()\
    \ { return cum_r.back(); }\n  X prod() { return Monoid::op(cum_l.back(), cum_r.back());\
    \ }\n  X prod_all() { return prod(); }\n\n private:\n  void rebuild() {\n    vc<X>\
    \ X;\n    reverse(all(dat_l));\n    concat(X, dat_l, dat_r);\n    clear();\n \
    \   int m = len(X) / 2;\n    FOR_R(i, m) push_front(X[i]);\n    FOR(i, m, len(X))\
    \ push_back(X[i]);\n    assert(sz == len(X));\n  }\n};\n#line 3 \"test/5_ai_generated_test/sliding_window_aggregation.test.cpp\"\
    \n\n/*\n\u5BFE\u8C61: ds/sliding_window_aggregation.hpp\n  Sliding_Window_Aggregation\
    \ (queue) \u3068 Sliding_Window_Aggregation_Deque\u3002\n\n\u72EC\u7ACB\u30AA\u30E9\
    \u30AF\u30EB: std::deque<string> \u306B\u540C\u3058 push/pop \u3092\u9069\u7528\
    \u3057\u3001\u5148\u982D\u304B\u3089\n  \u6587\u5B57\u5217\u9023\u7D50\u3057\u305F\
    \u7D50\u679C\u3092\u6BD4\u8F03\u3059\u308B\u3002\u975E\u53EF\u63DB\u306A\u9023\
    \u7D50\u30E2\u30CE\u30A4\u30C9\u3092\u4F7F\u7528\u3059\u308B\u305F\u3081\u3001\
    \n  \u7D2F\u7A4D\u306E\u7D50\u5408\u9806\u5E8F\u3084\u5DE6\u53F3\u30B9\u30BF\u30C3\
    \u30AF\u518D\u69CB\u7BC9\u6642\u306E\u9806\u5E8F\u9006\u8EE2\u3092\u767A\u898B\
    \u3067\u304D\u308B\u3002\n\n\u72D9\u3046\u4E0D\u5177\u5408: \u6700\u5F8C\u306E\
    \u8981\u7D20\u3092 pop \u3059\u308B\u3068\u304D\u306E\u7A7A\u72B6\u614B\u3001\u53F3\
    /\u5DE6\u7247\u5074\u304C\u7A7A\u306E\u3068\u304D\u306E\n  \u518D\u69CB\u7BC9\u3001\
    push_front \u3068 push_back \u306E\u6DF7\u5728\u3001clear \u5F8C\u306E\u7D2F\u7A4D\
    \u5024\u6B8B\u7559\u3001\n  size/front \u306E\u540C\u671F\u305A\u308C\u3001\u7E70\
    \u308A\u8FD4\u3057 pop/\u518D push \u3057\u305F\u3068\u304D\u306E\u53E4\u3044\u30C7\
    \u30FC\u30BF\u3002\n\n\u6761\u4EF6: \u7A7A\u306E\u69CB\u9020\u304B\u3089 pop/front\
    \ \u306F\u884C\u308F\u306A\u3044\u3002\u30C8\u30FC\u30AF\u30F3\u9577 1\u301C3\u3001\
    \u9577\u3055\u6700\u5927\n  80 \u7A0B\u5EA6\u3068\u3057\u3066 oracle \u306E\u9023\
    \u7D50\u30B3\u30B9\u30C8\u3092\u5236\u5FA1\u3059\u308B\u3002\u4E71\u6570 seed\
    \ \u306F\u56FA\u5B9A\u3002\n*/\n\nstruct String_Concat_For_Test {\n  using value_type\
    \ = string;\n  static string id() { return \"\"; }\n  static string op(const string&\
    \ a, const string& b) { return a + b; }\n};\nusing M = String_Concat_For_Test;\n\
    using Queue = Sliding_Window_Aggregation<M>;\nusing Deque = Sliding_Window_Aggregation_Deque<M>;\n\
    \nstring token(mt19937_64& rng) {\n  int k = 1 + int(rng() % 3);\n  string s;\n\
    \  for (int i = 0; i < k; ++i) s += char('a' + rng() % 5);\n  return s;\n}\n\n\
    string brute_concat(const deque<string>& ref) {\n  string s;\n  for (const string&\
    \ t : ref) s += t;\n  return s;\n}\n\nvoid check_queue(Queue& ds, const deque<string>&\
    \ ref, int step) {\n  string expected = brute_concat(ref);\n  if (ds.size() !=\
    \ int(ref.size()) || ds.prod() != expected ||\n      M::op(ds.lprod(), ds.rprod())\
    \ != expected) {\n    cerr << \"SWAG queue mismatch at step=\" << step\n     \
    \    << \" size=\" << ds.size() << \" expected_size=\" << ref.size()\n       \
    \  << \" got=\" << ds.prod() << \" expected=\" << expected << '\\n';\n    abort();\n\
    \  }\n}\n\nvoid check_deque(Deque& ds, const deque<string>& ref, int step) {\n\
    \  string expected = brute_concat(ref);\n  if (ds.size() != int(ref.size()) ||\
    \ ds.prod() != expected ||\n      ds.prod_all() != expected ||\n      M::op(ds.lprod(),\
    \ ds.rprod()) != expected ||\n      (!ref.empty() && ds.front() != ref.front()))\
    \ {\n    cerr << \"SWAG deque mismatch at step=\" << step\n         << \" size=\"\
    \ << ds.size() << \" expected_size=\" << ref.size()\n         << \" got=\" <<\
    \ ds.prod() << \" expected=\" << expected << '\\n';\n    abort();\n  }\n}\n\n\
    void test_queue() {\n  mt19937_64 rng(0x5a691e123ULL);\n  Queue ds;\n  deque<string>\
    \ ref;\n  check_queue(ds, ref, -1);\n\n  // \u7247\u5074\u306B\u591A\u6570 push\
    \ \u3057\u3066\u304B\u3089\u5168 pop \u3059\u308B\u64CD\u4F5C\u3092\u7E70\u308A\
    \u8FD4\u3059\u3002\n  for (int rep = 0; rep < 12; ++rep) {\n    for (int i = 0;\
    \ i < 73; ++i) {\n      string s = token(rng);\n      ds.push(s), ref.push_back(s);\n\
    \      check_queue(ds, ref, rep * 200 + i);\n    }\n    for (int i = 0; i < 73;\
    \ ++i) {\n      ds.pop(), ref.pop_front();\n      check_queue(ds, ref, rep * 200\
    \ + 73 + i);\n    }\n  }\n  for (int step = 0; step < 25000; ++step) {\n    if\
    \ (ref.empty() || (ref.size() < 80 && rng() % 10 < 6)) {\n      string s = token(rng);\n\
    \      ds.push(s), ref.push_back(s);\n    } else {\n      ds.pop(), ref.pop_front();\n\
    \    }\n    check_queue(ds, ref, 100000 + step);\n  }\n}\n\nvoid test_deque()\
    \ {\n  mt19937_64 rng(0xdedea091ULL);\n  Deque ds;\n  deque<string> ref;\n  check_deque(ds,\
    \ ref, -1);\n\n  // \u6700\u521D\u306F\u53F3\u5074\u3060\u3051\u306B\u7A4D\u307F\
    \u3001\u5DE6\u304B\u3089\u53D6\u308A\u7D9A\u3051\u3066 rebuild \u3092\u767A\u751F\
    \u3055\u305B\u308B\u3002\n  // \u6B21\u306B\u5DE6\u5074\u3060\u3051\u306B\u7A4D\
    \u307F\u3001\u53F3\u304B\u3089\u53D6\u3063\u3066\u9006\u65B9\u5411\u306E rebuild\
    \ \u3092\u767A\u751F\u3055\u305B\u308B\u3002\n  for (int rep = 0; rep < 8; ++rep)\
    \ {\n    for (int i = 0; i < 79; ++i) {\n      string s = token(rng);\n      ds.push_back(s),\
    \ ref.push_back(s);\n      check_deque(ds, ref, rep * 400 + i);\n    }\n    for\
    \ (int i = 0; i < 79; ++i) {\n      ds.pop_front(), ref.pop_front();\n      check_deque(ds,\
    \ ref, rep * 400 + 80 + i);\n    }\n    for (int i = 0; i < 79; ++i) {\n     \
    \ string s = token(rng);\n      ds.push_front(s), ref.push_front(s);\n      check_deque(ds,\
    \ ref, rep * 400 + 160 + i);\n    }\n    for (int i = 0; i < 79; ++i) {\n    \
    \  ds.pop_back(), ref.pop_back();\n      check_deque(ds, ref, rep * 400 + 240\
    \ + i);\n    }\n    ds.clear(), ref.clear();\n    check_deque(ds, ref, rep * 400\
    \ + 320);\n  }\n\n  for (int step = 0; step < 35000; ++step) {\n    int op = int(rng()\
    \ % 12);\n    if (ref.empty() || (ref.size() < 80 && op <= 4)) {\n      string\
    \ s = token(rng);\n      if (op % 2 == 0) ds.push_front(s), ref.push_front(s);\n\
    \      else if (op == 3) ds.push(s), ref.push_back(s);\n      else ds.push_back(s),\
    \ ref.push_back(s);\n    } else if (op == 11) {\n      ds.clear(), ref.clear();\n\
    \    } else if (op % 2 == 0) {\n      ds.pop_front(), ref.pop_front();\n    }\
    \ else if (op == 7) {\n      ds.pop(), ref.pop_front();\n    } else {\n      ds.pop_back(),\
    \ ref.pop_back();\n    }\n    check_deque(ds, ref, 100000 + step);\n  }\n  ds.clear(),\
    \ ref.clear();\n  check_deque(ds, ref, 200000);\n}\n\nint main() {\n  test_queue();\n\
    \  test_deque();\n  cerr << \"PASS sliding_window_aggregation queue+deque\\n\"\
    ;\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"ds/sliding_window_aggregation.hpp\"\
    \n\n/*\n\u5BFE\u8C61: ds/sliding_window_aggregation.hpp\n  Sliding_Window_Aggregation\
    \ (queue) \u3068 Sliding_Window_Aggregation_Deque\u3002\n\n\u72EC\u7ACB\u30AA\u30E9\
    \u30AF\u30EB: std::deque<string> \u306B\u540C\u3058 push/pop \u3092\u9069\u7528\
    \u3057\u3001\u5148\u982D\u304B\u3089\n  \u6587\u5B57\u5217\u9023\u7D50\u3057\u305F\
    \u7D50\u679C\u3092\u6BD4\u8F03\u3059\u308B\u3002\u975E\u53EF\u63DB\u306A\u9023\
    \u7D50\u30E2\u30CE\u30A4\u30C9\u3092\u4F7F\u7528\u3059\u308B\u305F\u3081\u3001\
    \n  \u7D2F\u7A4D\u306E\u7D50\u5408\u9806\u5E8F\u3084\u5DE6\u53F3\u30B9\u30BF\u30C3\
    \u30AF\u518D\u69CB\u7BC9\u6642\u306E\u9806\u5E8F\u9006\u8EE2\u3092\u767A\u898B\
    \u3067\u304D\u308B\u3002\n\n\u72D9\u3046\u4E0D\u5177\u5408: \u6700\u5F8C\u306E\
    \u8981\u7D20\u3092 pop \u3059\u308B\u3068\u304D\u306E\u7A7A\u72B6\u614B\u3001\u53F3\
    /\u5DE6\u7247\u5074\u304C\u7A7A\u306E\u3068\u304D\u306E\n  \u518D\u69CB\u7BC9\u3001\
    push_front \u3068 push_back \u306E\u6DF7\u5728\u3001clear \u5F8C\u306E\u7D2F\u7A4D\
    \u5024\u6B8B\u7559\u3001\n  size/front \u306E\u540C\u671F\u305A\u308C\u3001\u7E70\
    \u308A\u8FD4\u3057 pop/\u518D push \u3057\u305F\u3068\u304D\u306E\u53E4\u3044\u30C7\
    \u30FC\u30BF\u3002\n\n\u6761\u4EF6: \u7A7A\u306E\u69CB\u9020\u304B\u3089 pop/front\
    \ \u306F\u884C\u308F\u306A\u3044\u3002\u30C8\u30FC\u30AF\u30F3\u9577 1\u301C3\u3001\
    \u9577\u3055\u6700\u5927\n  80 \u7A0B\u5EA6\u3068\u3057\u3066 oracle \u306E\u9023\
    \u7D50\u30B3\u30B9\u30C8\u3092\u5236\u5FA1\u3059\u308B\u3002\u4E71\u6570 seed\
    \ \u306F\u56FA\u5B9A\u3002\n*/\n\nstruct String_Concat_For_Test {\n  using value_type\
    \ = string;\n  static string id() { return \"\"; }\n  static string op(const string&\
    \ a, const string& b) { return a + b; }\n};\nusing M = String_Concat_For_Test;\n\
    using Queue = Sliding_Window_Aggregation<M>;\nusing Deque = Sliding_Window_Aggregation_Deque<M>;\n\
    \nstring token(mt19937_64& rng) {\n  int k = 1 + int(rng() % 3);\n  string s;\n\
    \  for (int i = 0; i < k; ++i) s += char('a' + rng() % 5);\n  return s;\n}\n\n\
    string brute_concat(const deque<string>& ref) {\n  string s;\n  for (const string&\
    \ t : ref) s += t;\n  return s;\n}\n\nvoid check_queue(Queue& ds, const deque<string>&\
    \ ref, int step) {\n  string expected = brute_concat(ref);\n  if (ds.size() !=\
    \ int(ref.size()) || ds.prod() != expected ||\n      M::op(ds.lprod(), ds.rprod())\
    \ != expected) {\n    cerr << \"SWAG queue mismatch at step=\" << step\n     \
    \    << \" size=\" << ds.size() << \" expected_size=\" << ref.size()\n       \
    \  << \" got=\" << ds.prod() << \" expected=\" << expected << '\\n';\n    abort();\n\
    \  }\n}\n\nvoid check_deque(Deque& ds, const deque<string>& ref, int step) {\n\
    \  string expected = brute_concat(ref);\n  if (ds.size() != int(ref.size()) ||\
    \ ds.prod() != expected ||\n      ds.prod_all() != expected ||\n      M::op(ds.lprod(),\
    \ ds.rprod()) != expected ||\n      (!ref.empty() && ds.front() != ref.front()))\
    \ {\n    cerr << \"SWAG deque mismatch at step=\" << step\n         << \" size=\"\
    \ << ds.size() << \" expected_size=\" << ref.size()\n         << \" got=\" <<\
    \ ds.prod() << \" expected=\" << expected << '\\n';\n    abort();\n  }\n}\n\n\
    void test_queue() {\n  mt19937_64 rng(0x5a691e123ULL);\n  Queue ds;\n  deque<string>\
    \ ref;\n  check_queue(ds, ref, -1);\n\n  // \u7247\u5074\u306B\u591A\u6570 push\
    \ \u3057\u3066\u304B\u3089\u5168 pop \u3059\u308B\u64CD\u4F5C\u3092\u7E70\u308A\
    \u8FD4\u3059\u3002\n  for (int rep = 0; rep < 12; ++rep) {\n    for (int i = 0;\
    \ i < 73; ++i) {\n      string s = token(rng);\n      ds.push(s), ref.push_back(s);\n\
    \      check_queue(ds, ref, rep * 200 + i);\n    }\n    for (int i = 0; i < 73;\
    \ ++i) {\n      ds.pop(), ref.pop_front();\n      check_queue(ds, ref, rep * 200\
    \ + 73 + i);\n    }\n  }\n  for (int step = 0; step < 25000; ++step) {\n    if\
    \ (ref.empty() || (ref.size() < 80 && rng() % 10 < 6)) {\n      string s = token(rng);\n\
    \      ds.push(s), ref.push_back(s);\n    } else {\n      ds.pop(), ref.pop_front();\n\
    \    }\n    check_queue(ds, ref, 100000 + step);\n  }\n}\n\nvoid test_deque()\
    \ {\n  mt19937_64 rng(0xdedea091ULL);\n  Deque ds;\n  deque<string> ref;\n  check_deque(ds,\
    \ ref, -1);\n\n  // \u6700\u521D\u306F\u53F3\u5074\u3060\u3051\u306B\u7A4D\u307F\
    \u3001\u5DE6\u304B\u3089\u53D6\u308A\u7D9A\u3051\u3066 rebuild \u3092\u767A\u751F\
    \u3055\u305B\u308B\u3002\n  // \u6B21\u306B\u5DE6\u5074\u3060\u3051\u306B\u7A4D\
    \u307F\u3001\u53F3\u304B\u3089\u53D6\u3063\u3066\u9006\u65B9\u5411\u306E rebuild\
    \ \u3092\u767A\u751F\u3055\u305B\u308B\u3002\n  for (int rep = 0; rep < 8; ++rep)\
    \ {\n    for (int i = 0; i < 79; ++i) {\n      string s = token(rng);\n      ds.push_back(s),\
    \ ref.push_back(s);\n      check_deque(ds, ref, rep * 400 + i);\n    }\n    for\
    \ (int i = 0; i < 79; ++i) {\n      ds.pop_front(), ref.pop_front();\n      check_deque(ds,\
    \ ref, rep * 400 + 80 + i);\n    }\n    for (int i = 0; i < 79; ++i) {\n     \
    \ string s = token(rng);\n      ds.push_front(s), ref.push_front(s);\n      check_deque(ds,\
    \ ref, rep * 400 + 160 + i);\n    }\n    for (int i = 0; i < 79; ++i) {\n    \
    \  ds.pop_back(), ref.pop_back();\n      check_deque(ds, ref, rep * 400 + 240\
    \ + i);\n    }\n    ds.clear(), ref.clear();\n    check_deque(ds, ref, rep * 400\
    \ + 320);\n  }\n\n  for (int step = 0; step < 35000; ++step) {\n    int op = int(rng()\
    \ % 12);\n    if (ref.empty() || (ref.size() < 80 && op <= 4)) {\n      string\
    \ s = token(rng);\n      if (op % 2 == 0) ds.push_front(s), ref.push_front(s);\n\
    \      else if (op == 3) ds.push(s), ref.push_back(s);\n      else ds.push_back(s),\
    \ ref.push_back(s);\n    } else if (op == 11) {\n      ds.clear(), ref.clear();\n\
    \    } else if (op % 2 == 0) {\n      ds.pop_front(), ref.pop_front();\n    }\
    \ else if (op == 7) {\n      ds.pop(), ref.pop_front();\n    } else {\n      ds.pop_back(),\
    \ ref.pop_back();\n    }\n    check_deque(ds, ref, 100000 + step);\n  }\n  ds.clear(),\
    \ ref.clear();\n  check_deque(ds, ref, 200000);\n}\n\nint main() {\n  test_queue();\n\
    \  test_deque();\n  cerr << \"PASS sliding_window_aggregation queue+deque\\n\"\
    ;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/sliding_window_aggregation.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/sliding_window_aggregation.test.cpp
  requiredBy: []
  timestamp: '2026-11-18 16:13:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/sliding_window_aggregation.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/sliding_window_aggregation.test.cpp
- /verify/test/5_ai_generated_test/sliding_window_aggregation.test.cpp.html
title: test/5_ai_generated_test/sliding_window_aggregation.test.cpp
---
