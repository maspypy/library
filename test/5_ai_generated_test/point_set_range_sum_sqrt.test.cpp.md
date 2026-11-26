---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/xor.hpp
    title: alg/monoid/xor.hpp
  - icon: ':heavy_check_mark:'
    path: ds/point_set_range_sum_sqrt.hpp
    title: ds/point_set_range_sum_sqrt.hpp
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
    #line 1 \"ds/point_set_range_sum_sqrt.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/point_set_range_sum_sqrt.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/point_set_range_sum_sqrt.hpp\"\n\n// update O(1) / query O(sqrt\
    \ N)\n// b_sz \u306F sqrt(N/2) \u304C\u76EE\u5B89\ntemplate <typename AbelGroup,\
    \ int b_sz = 256>\nstruct Point_Set_Range_Sum_Sqrt {\n  using G = AbelGroup;\n\
    \  static_assert(G::commute);\n  using MX = AbelGroup;\n  using E = typename G::value_type;\n\
    \  int n, b_num;\n  vc<E> A, B;\n  E total;\n\n  Point_Set_Range_Sum_Sqrt(int\
    \ N = 0) { build(N); }\n  template <typename F>\n  Point_Set_Range_Sum_Sqrt(int\
    \ N, F f) {\n    build(N, f);\n  }\n\n  void build(int N) {\n    build(N, [&](int\
    \ i) -> E { return G::id(); });\n  }\n  void build(const vc<E> &v) {\n    build(len(v),\
    \ [&](int i) -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m;\n    b_num = ceil<int>(n, b_sz);\n    A.assign(b_sz *\
    \ b_num, G::id()), B.assign(b_num, G::id());\n    FOR(i, n) A[i] = f(i);\n   \
    \ for (int l = 0, b = 0; b < b_num; ++b, l += b_sz) {\n      E x = G::id();\n\
    \      FOR(i, l, l + b_sz) x = G::op(x, A[i]);\n      B[b] = x;\n    }\n    total\
    \ = G::id();\n    for (E x : B) total = G::op(total, x);\n  }\n\n  E prod_all()\
    \ const { return total; }\n  E sum_all() const { return total; }\n  E sum(int\
    \ k) const { return sum(0, k); }\n  E prod(int k) const { return sum(0, k); }\n\
    \  E sum(int L, int R) const { return prod(L, R); }\n  E prod(int L, int R) const\
    \ {\n    assert(0 <= L && L <= R && R <= n);\n    auto [b1, k1] = divmod<int>(L,\
    \ b_sz);\n    E add = G::id(), sub = G::id();\n    if (k1 <= b_sz / 2) {\n   \
    \   FOR(i, b1 * b_sz, L) sub = G::op(sub, A[i]);\n    } else {\n      ++b1;\n\
    \      FOR(i, L, b1 * b_sz) add = G::op(add, A[i]);\n    }\n    auto [b2, k2]\
    \ = divmod<int>(R, b_sz);\n    if (k2 <= b_sz / 2) {\n      FOR(i, b2 * b_sz,\
    \ R) add = G::op(add, A[i]);\n    } else {\n      ++b2;\n      FOR(i, R, b2 *\
    \ b_sz) sub = G::op(sub, A[i]);\n    }\n    // [b1,b2) \u3092\u8DB3\u3059\n  \
    \  if (b2 - b1 <= b_num / 2) {\n      FOR(b, b1, b2) add = G::op(add, B[b]);\n\
    \    } else {\n      add = G::op(add, total);\n      FOR(b, b1) sub = G::op(sub,\
    \ B[b]);\n      FOR(b, b2, b_num) sub = G::op(sub, B[b]);\n    }\n    return G::op(add,\
    \ G::inverse(sub));\n  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void\
    \ multiply(int k, E x) {\n    assert(0 <= k && k < n);\n    total = G::op(total,\
    \ x);\n    A[k] = G::op(A[k], x), B[k / b_sz] = G::op(B[k / b_sz], x);\n  }\n\
    \  void set(int k, E x) {\n    assert(0 <= k && k < n);\n    x = G::op(x, G::inverse(A[k]));\n\
    \    add(k, x);\n  }\n};\n#line 1 \"alg/monoid/xor.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/xor.hpp\n\
    \ntemplate <typename X>\nstruct Monoid_Xor {\n  using value_type = X;\n  static\
    \ X op(X x, X y) { return x ^ y; }\n  static constexpr X inverse(const X &x) noexcept\
    \ { return x; }\n  static constexpr X power(const X &x, ll n) noexcept {\n   \
    \ return (n & 1 ? x : 0);\n  }\n  static constexpr X id(){return X(0);};\n  static\
    \ constexpr bool commute = true;\n};\n#line 4 \"test/5_ai_generated_test/point_set_range_sum_sqrt.test.cpp\"\
    \n\n/*\n\u5BFE\u8C61: ds/point_set_range_sum_sqrt.hpp\n  Point_Set_Range_Sum_Sqrt::build\
    \ / set / add / multiply / prod / sum /\n  prod_all / sum_all \u3092\u691C\u8A3C\
    \u3059\u308B\u3002\n\n\u72EC\u7ACB\u30AA\u30E9\u30AF\u30EB: \u5404\u8981\u7D20\
    \u3092 std::vector \u306B\u4FDD\u6301\u3057\u3001[l,r) \u3092\u76F4\u63A5\u7573\
    \u307F\u8FBC\u3080\u3002\n  \u5B9F\u88C5\u306E\u30D6\u30ED\u30C3\u30AF\u5206\u5272\
    \u30FB\u88DC\u96C6\u5408\u3092\u5229\u7528\u3057\u305F\u5DEE\u5206\u8A08\u7B97\
    \u306F\u6A21\u5023\u3057\u306A\u3044\u3002\n  \u52A0\u7B97\u7FA4\u3068 XOR \u7FA4\
    \u306E\u4E21\u65B9\u3067\u3001\u9006\u5143\u306E\u4F7F\u3044\u65B9\u3084\u7B26\
    \u53F7\u306E\u53D6\u308A\u9055\u3048\u3092\u691C\u67FB\u3059\u308B\u3002\n\n\u72D9\
    \u3046\u4E0D\u5177\u5408: \u30D6\u30ED\u30C3\u30AF\u5883\u754C\u306E off-by-one\u3001\
    \u90E8\u5206\u30D6\u30ED\u30C3\u30AF\u3068\u5168\u4F53\u96C6\u7D04\u306E\n  \u4E8C\
    \u91CD\u8A08\u4E0A\u3001set \u306E\u65E7\u5024\u9664\u53BB\u5FD8\u308C\u3001build\
    \ \u306E\u518D\u5229\u7528\u6642\u306E\u53E4\u3044\u5024\u306E\u6B8B\u7559\u3002\
    \n  \u7A7A\u914D\u5217\u30FB\u7A7A\u533A\u9593\u30FB\u3061\u3087\u3046\u3069\u30D6\
    \u30ED\u30C3\u30AF\u9577\u30FB\u524D\u5F8C 1 \u8981\u7D20\u3092\u660E\u793A\u7684\
    \u306B\u542B\u3080\u3002\n\n\u6761\u4EF6: b_sz > 0\u3001\u554F\u3044\u5408\u308F\
    \u305B\u306F 0 <= l <= r <= n\u3001\u66F4\u65B0\u5148\u306F 0 <= i < n\u3002\n\
    \  \u52A0\u7B97\u5024\u306F\u5C0F\u3055\u3044\u6574\u6570\u306B\u9650\u5B9A\u3057\
    \u3001\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u306E\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3092\u907F\u3051\u308B\u3002\n  \u4E71\u6570\u306F mt19937_64 \u306E\
    \u56FA\u5B9A seed 0x21a9b17\uFF08\u578B\u30FB\u30D6\u30ED\u30C3\u30AF\u9577\u3067\
    \u5206\u96E2\uFF09\u3002\n*/\n\ntemplate <class Group, int B>\nvoid run_group(const\
    \ char* group_name, uint64_t seed) {\n  using E = typename Group::value_type;\n\
    \  using DS = Point_Set_Range_Sum_Sqrt<Group, B>;\n  mt19937_64 rng(seed ^ (uint64_t(B)\
    \ * 0x9e3779b97f4a7c15ULL));\n  auto rand_value = [&]() -> E {\n    if constexpr\
    \ (std::is_signed<E>::value) {\n      return E(int(rng() % 20001) - 10000);\n\
    \    } else {\n      return E(rng());\n    }\n  };\n\n  set<int> sizes{0, 1, 2,\
    \ 3, 4, 7, 8, 9, 15, 16, 17,\n                 31, 32, 33, 63, 64, 65, 127, 128,\
    \ 129, 255, 256, 257,\n                 B - 1, B, B + 1, 2 * B - 1, 2 * B, 2 *\
    \ B + 1};\n  for (int n : sizes) {\n    DS ds(n);\n    vector<E> ref(n, Group::id());\n\
    \    auto brute = [&](int l, int r) -> E {\n      E ans = Group::id();\n     \
    \ for (int i = l; i < r; ++i) ans = Group::op(ans, ref[i]);\n      return ans;\n\
    \    };\n    auto fail = [&](int step, int l, int r, E got, E expected) {\n  \
    \    cerr << \"Point_Set_Range_Sum_Sqrt mismatch: \" << group_name\n         \
    \  << \" B=\" << B << \" n=\" << n << \" step=\" << step\n           << \" range=[\"\
    \ << l << ',' << r << \") got=\" << got\n           << \" expected=\" << expected\
    \ << '\\n';\n      abort();\n    };\n    auto check = [&](int step, int l, int\
    \ r) {\n      E expected = brute(l, r);\n      E got = ds.prod(l, r);\n      if\
    \ (got != expected) fail(step, l, r, got, expected);\n      got = ds.sum(l, r);\n\
    \      if (got != expected) fail(step, l, r, got, expected);\n    };\n    auto\
    \ check_all = [&](int step) {\n      E expected = brute(0, n);\n      if (ds.prod_all()\
    \ != expected)\n        fail(step, 0, n, ds.prod_all(), expected);\n      if (ds.sum_all()\
    \ != expected)\n        fail(step, 0, n, ds.sum_all(), expected);\n      int k\
    \ = int(rng() % uint64_t(n + 1));\n      E prefix = brute(0, k);\n      if (ds.sum(k)\
    \ != prefix) fail(step, 0, k, ds.sum(k), prefix);\n      if (ds.prod(k) != prefix)\
    \ fail(step, 0, k, ds.prod(k), prefix);\n      check(step, 0, 0);\n      check(step,\
    \ n, n);\n      check(step, 0, n);\n    };\n\n    // \u5024\u3092\u8FD4\u3059\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3068\u518D build \u3092\u3001\u540C\u3058\
    \u914D\u5217\u306B\u5BFE\u3057\u3066\u7167\u5408\u3059\u308B\u3002\n    for (auto&\
    \ x : ref) x = rand_value();\n    DS constructed(n, [&](int i) -> E { return ref[i];\
    \ });\n    if (constructed.prod_all() != brute(0, n)) abort();\n    ds.build(ref);\n\
    \    check_all(-1);\n\n    for (int step = 0; step < 520; ++step) {\n      int\
    \ action = int(rng() % 10);\n      if (n && action < 5) {\n        int i = int(rng()\
    \ % uint64_t(n));\n        E x = rand_value();\n        if (action == 0 || action\
    \ == 1) {\n          ds.set(i, x);\n          ref[i] = x;\n        } else if (action\
    \ == 2 || action == 3) {\n          ds.add(i, x);\n          ref[i] = Group::op(ref[i],\
    \ x);\n        } else {\n          ds.multiply(i, x);\n          ref[i] = Group::op(ref[i],\
    \ x);\n        }\n      } else if (action == 5) {\n        ds.build(ref);\n  \
    \    } else if (action == 6) {\n        ds.build(n, [&](int i) -> E { return ref[i];\
    \ });\n      } else if (action == 7) {\n        ds.build(n);\n        fill(ref.begin(),\
    \ ref.end(), Group::id());\n      }\n\n      // \u6BCE\u56DE\u30E9\u30F3\u30C0\
    \u30E0\u533A\u9593\u3092\u8907\u6570\u30C1\u30A7\u30C3\u30AF\u3002\u7A7A\u533A\
    \u9593\u3082\u81EA\u7136\u306B\u51FA\u73FE\u3059\u308B\u3002\n      for (int j\
    \ = 0; j < 3; ++j) {\n        int l = int(rng() % uint64_t(n + 1));\n        int\
    \ r = int(rng() % uint64_t(n + 1));\n        if (l > r) swap(l, r);\n        check(step,\
    \ l, r);\n      }\n      check_all(step);\n      // \u5883\u754C\u3092\u56FA\u5B9A\
    \u3057\u3066\u7167\u5408\u3057\u3001\u4E71\u629E\u3060\u3051\u3067\u306F\u6F0F\
    \u308C\u3084\u3059\u3044\u7A7A\u7AEF\u3068\u5168\u533A\u9593\u3092\u8986\u3046\
    \u3002\n      if (step % 73 == 0) {\n        for (int l : {0, n / 2, n})\n   \
    \       for (int r : {l, n}) check(step, l, r);\n      }\n    }\n    ds.build(n);\n\
    \    fill(ref.begin(), ref.end(), Group::id());\n    check_all(521);\n  }\n  cerr\
    \ << \"PASS \" << group_name << \" block=\" << B << '\\n';\n}\n\nint main() {\n\
    \  run_group<Monoid_Add<ll>, 1>(\"add_ll\", 0x21a9b17ULL);\n  run_group<Monoid_Add<ll>,\
    \ 3>(\"add_ll\", 0x21a9b17ULL);\n  run_group<Monoid_Add<ll>, 7>(\"add_ll\", 0x21a9b17ULL);\n\
    \  run_group<Monoid_Add<ll>, 16>(\"add_ll\", 0x21a9b17ULL);\n  run_group<Monoid_Add<ll>,\
    \ 64>(\"add_ll\", 0x21a9b17ULL);\n  run_group<Monoid_Xor<u64>, 1>(\"xor_u64\"\
    , 0x21a9b17ULL);\n  run_group<Monoid_Xor<u64>, 3>(\"xor_u64\", 0x21a9b17ULL);\n\
    \  run_group<Monoid_Xor<u64>, 7>(\"xor_u64\", 0x21a9b17ULL);\n  run_group<Monoid_Xor<u64>,\
    \ 16>(\"xor_u64\", 0x21a9b17ULL);\n  run_group<Monoid_Xor<u64>, 64>(\"xor_u64\"\
    , 0x21a9b17ULL);\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"ds/point_set_range_sum_sqrt.hpp\"\
    \n#include \"alg/monoid/xor.hpp\"\n\n/*\n\u5BFE\u8C61: ds/point_set_range_sum_sqrt.hpp\n\
    \  Point_Set_Range_Sum_Sqrt::build / set / add / multiply / prod / sum /\n  prod_all\
    \ / sum_all \u3092\u691C\u8A3C\u3059\u308B\u3002\n\n\u72EC\u7ACB\u30AA\u30E9\u30AF\
    \u30EB: \u5404\u8981\u7D20\u3092 std::vector \u306B\u4FDD\u6301\u3057\u3001[l,r)\
    \ \u3092\u76F4\u63A5\u7573\u307F\u8FBC\u3080\u3002\n  \u5B9F\u88C5\u306E\u30D6\
    \u30ED\u30C3\u30AF\u5206\u5272\u30FB\u88DC\u96C6\u5408\u3092\u5229\u7528\u3057\
    \u305F\u5DEE\u5206\u8A08\u7B97\u306F\u6A21\u5023\u3057\u306A\u3044\u3002\n  \u52A0\
    \u7B97\u7FA4\u3068 XOR \u7FA4\u306E\u4E21\u65B9\u3067\u3001\u9006\u5143\u306E\u4F7F\
    \u3044\u65B9\u3084\u7B26\u53F7\u306E\u53D6\u308A\u9055\u3048\u3092\u691C\u67FB\
    \u3059\u308B\u3002\n\n\u72D9\u3046\u4E0D\u5177\u5408: \u30D6\u30ED\u30C3\u30AF\
    \u5883\u754C\u306E off-by-one\u3001\u90E8\u5206\u30D6\u30ED\u30C3\u30AF\u3068\u5168\
    \u4F53\u96C6\u7D04\u306E\n  \u4E8C\u91CD\u8A08\u4E0A\u3001set \u306E\u65E7\u5024\
    \u9664\u53BB\u5FD8\u308C\u3001build \u306E\u518D\u5229\u7528\u6642\u306E\u53E4\
    \u3044\u5024\u306E\u6B8B\u7559\u3002\n  \u7A7A\u914D\u5217\u30FB\u7A7A\u533A\u9593\
    \u30FB\u3061\u3087\u3046\u3069\u30D6\u30ED\u30C3\u30AF\u9577\u30FB\u524D\u5F8C\
    \ 1 \u8981\u7D20\u3092\u660E\u793A\u7684\u306B\u542B\u3080\u3002\n\n\u6761\u4EF6\
    : b_sz > 0\u3001\u554F\u3044\u5408\u308F\u305B\u306F 0 <= l <= r <= n\u3001\u66F4\
    \u65B0\u5148\u306F 0 <= i < n\u3002\n  \u52A0\u7B97\u5024\u306F\u5C0F\u3055\u3044\
    \u6574\u6570\u306B\u9650\u5B9A\u3057\u3001\u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u306E\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3092\u907F\u3051\u308B\u3002\
    \n  \u4E71\u6570\u306F mt19937_64 \u306E\u56FA\u5B9A seed 0x21a9b17\uFF08\u578B\
    \u30FB\u30D6\u30ED\u30C3\u30AF\u9577\u3067\u5206\u96E2\uFF09\u3002\n*/\n\ntemplate\
    \ <class Group, int B>\nvoid run_group(const char* group_name, uint64_t seed)\
    \ {\n  using E = typename Group::value_type;\n  using DS = Point_Set_Range_Sum_Sqrt<Group,\
    \ B>;\n  mt19937_64 rng(seed ^ (uint64_t(B) * 0x9e3779b97f4a7c15ULL));\n  auto\
    \ rand_value = [&]() -> E {\n    if constexpr (std::is_signed<E>::value) {\n \
    \     return E(int(rng() % 20001) - 10000);\n    } else {\n      return E(rng());\n\
    \    }\n  };\n\n  set<int> sizes{0, 1, 2, 3, 4, 7, 8, 9, 15, 16, 17,\n       \
    \          31, 32, 33, 63, 64, 65, 127, 128, 129, 255, 256, 257,\n           \
    \      B - 1, B, B + 1, 2 * B - 1, 2 * B, 2 * B + 1};\n  for (int n : sizes) {\n\
    \    DS ds(n);\n    vector<E> ref(n, Group::id());\n    auto brute = [&](int l,\
    \ int r) -> E {\n      E ans = Group::id();\n      for (int i = l; i < r; ++i)\
    \ ans = Group::op(ans, ref[i]);\n      return ans;\n    };\n    auto fail = [&](int\
    \ step, int l, int r, E got, E expected) {\n      cerr << \"Point_Set_Range_Sum_Sqrt\
    \ mismatch: \" << group_name\n           << \" B=\" << B << \" n=\" << n << \"\
    \ step=\" << step\n           << \" range=[\" << l << ',' << r << \") got=\" <<\
    \ got\n           << \" expected=\" << expected << '\\n';\n      abort();\n  \
    \  };\n    auto check = [&](int step, int l, int r) {\n      E expected = brute(l,\
    \ r);\n      E got = ds.prod(l, r);\n      if (got != expected) fail(step, l,\
    \ r, got, expected);\n      got = ds.sum(l, r);\n      if (got != expected) fail(step,\
    \ l, r, got, expected);\n    };\n    auto check_all = [&](int step) {\n      E\
    \ expected = brute(0, n);\n      if (ds.prod_all() != expected)\n        fail(step,\
    \ 0, n, ds.prod_all(), expected);\n      if (ds.sum_all() != expected)\n     \
    \   fail(step, 0, n, ds.sum_all(), expected);\n      int k = int(rng() % uint64_t(n\
    \ + 1));\n      E prefix = brute(0, k);\n      if (ds.sum(k) != prefix) fail(step,\
    \ 0, k, ds.sum(k), prefix);\n      if (ds.prod(k) != prefix) fail(step, 0, k,\
    \ ds.prod(k), prefix);\n      check(step, 0, 0);\n      check(step, n, n);\n \
    \     check(step, 0, n);\n    };\n\n    // \u5024\u3092\u8FD4\u3059\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u3068\u518D build \u3092\u3001\u540C\u3058\u914D\
    \u5217\u306B\u5BFE\u3057\u3066\u7167\u5408\u3059\u308B\u3002\n    for (auto& x\
    \ : ref) x = rand_value();\n    DS constructed(n, [&](int i) -> E { return ref[i];\
    \ });\n    if (constructed.prod_all() != brute(0, n)) abort();\n    ds.build(ref);\n\
    \    check_all(-1);\n\n    for (int step = 0; step < 520; ++step) {\n      int\
    \ action = int(rng() % 10);\n      if (n && action < 5) {\n        int i = int(rng()\
    \ % uint64_t(n));\n        E x = rand_value();\n        if (action == 0 || action\
    \ == 1) {\n          ds.set(i, x);\n          ref[i] = x;\n        } else if (action\
    \ == 2 || action == 3) {\n          ds.add(i, x);\n          ref[i] = Group::op(ref[i],\
    \ x);\n        } else {\n          ds.multiply(i, x);\n          ref[i] = Group::op(ref[i],\
    \ x);\n        }\n      } else if (action == 5) {\n        ds.build(ref);\n  \
    \    } else if (action == 6) {\n        ds.build(n, [&](int i) -> E { return ref[i];\
    \ });\n      } else if (action == 7) {\n        ds.build(n);\n        fill(ref.begin(),\
    \ ref.end(), Group::id());\n      }\n\n      // \u6BCE\u56DE\u30E9\u30F3\u30C0\
    \u30E0\u533A\u9593\u3092\u8907\u6570\u30C1\u30A7\u30C3\u30AF\u3002\u7A7A\u533A\
    \u9593\u3082\u81EA\u7136\u306B\u51FA\u73FE\u3059\u308B\u3002\n      for (int j\
    \ = 0; j < 3; ++j) {\n        int l = int(rng() % uint64_t(n + 1));\n        int\
    \ r = int(rng() % uint64_t(n + 1));\n        if (l > r) swap(l, r);\n        check(step,\
    \ l, r);\n      }\n      check_all(step);\n      // \u5883\u754C\u3092\u56FA\u5B9A\
    \u3057\u3066\u7167\u5408\u3057\u3001\u4E71\u629E\u3060\u3051\u3067\u306F\u6F0F\
    \u308C\u3084\u3059\u3044\u7A7A\u7AEF\u3068\u5168\u533A\u9593\u3092\u8986\u3046\
    \u3002\n      if (step % 73 == 0) {\n        for (int l : {0, n / 2, n})\n   \
    \       for (int r : {l, n}) check(step, l, r);\n      }\n    }\n    ds.build(n);\n\
    \    fill(ref.begin(), ref.end(), Group::id());\n    check_all(521);\n  }\n  cerr\
    \ << \"PASS \" << group_name << \" block=\" << B << '\\n';\n}\n\nint main() {\n\
    \  run_group<Monoid_Add<ll>, 1>(\"add_ll\", 0x21a9b17ULL);\n  run_group<Monoid_Add<ll>,\
    \ 3>(\"add_ll\", 0x21a9b17ULL);\n  run_group<Monoid_Add<ll>, 7>(\"add_ll\", 0x21a9b17ULL);\n\
    \  run_group<Monoid_Add<ll>, 16>(\"add_ll\", 0x21a9b17ULL);\n  run_group<Monoid_Add<ll>,\
    \ 64>(\"add_ll\", 0x21a9b17ULL);\n  run_group<Monoid_Xor<u64>, 1>(\"xor_u64\"\
    , 0x21a9b17ULL);\n  run_group<Monoid_Xor<u64>, 3>(\"xor_u64\", 0x21a9b17ULL);\n\
    \  run_group<Monoid_Xor<u64>, 7>(\"xor_u64\", 0x21a9b17ULL);\n  run_group<Monoid_Xor<u64>,\
    \ 16>(\"xor_u64\", 0x21a9b17ULL);\n  run_group<Monoid_Xor<u64>, 64>(\"xor_u64\"\
    , 0x21a9b17ULL);\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/point_set_range_sum_sqrt.hpp
  - alg/monoid/add.hpp
  - alg/monoid/xor.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/point_set_range_sum_sqrt.test.cpp
  requiredBy: []
  timestamp: '2026-11-18 16:13:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/point_set_range_sum_sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/point_set_range_sum_sqrt.test.cpp
- /verify/test/5_ai_generated_test/point_set_range_sum_sqrt.test.cpp.html
title: test/5_ai_generated_test/point_set_range_sum_sqrt.test.cpp
---
