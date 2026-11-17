---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/minmax.hpp
    title: alg/monoid/minmax.hpp
  - icon: ':x:'
    path: ds/segtree/range_minmax.hpp
    title: ds/segtree/range_minmax.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
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
    #line 1 \"ds/segtree/range_minmax.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/range_minmax.hpp\n\
    \n#line 1 \"alg/monoid/minmax.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/minmax.hpp\n\
    \ntemplate <class X>\nstruct Monoid_MinMax {\n  using P = pair<X, X>;\n  using\
    \ value_type = P;\n  static constexpr P op(const P x, const P y) noexcept {\n\
    \    return {min(x.fi, y.fi), max(x.se, y.se)};\n  }\n  static constexpr P from_element(const\
    \ X x) { return {x, x}; }\n  static constexpr P id() { return {infty<X>, -infty<X>};\
    \ }\n  static constexpr bool commute = true;\n};\n#line 4 \"ds/segtree/range_minmax.hpp\"\
    \n\n// 2026/11/17 AI generated.\n\n// Range_Min / Range_Max \u3068\u540C\u3058\
    \ B \u5206\u6728\u3002\u5404\u30D6\u30ED\u30C3\u30AF\u306F min 64B + max 64B\u3002\
    \n// \u4F4D\u7F6E i \u306F Monoid_MinMax<T>::value_type (= pair<T,T>) \u3092\u6301\
    \u3064\u3002\n// \u521D\u671F\u5024\u306F monoid \u306E\u5358\u4F4D\u5143 {INF,\
    \ -INF}\u3002\u30B9\u30AB\u30E9\u30FC x \u306F {x,x} \u3068\u3057\u3066\u6271\u3046\
    \u3002\n// \u6709\u52B9\u306A\u5024\u57DF\u306F Monoid_MinMax<T>::id() \u306E\u756A\
    \u5175\u306B\u53CE\u307E\u308B\u7BC4\u56F2\u3068\u3059\u308B\u3002\n#if defined(__x86_64__)\
    \ && (defined(__GNUC__) || defined(__clang__)) && \\\n    !defined(RANGE_MINMAX_NO_AVX2)\n\
    #include <immintrin.h>\n#define RANGE_MINMAX_AVX2 1\n#else\n#define RANGE_MINMAX_AVX2\
    \ 0\n#endif\n\ntemplate <typename T>\nstruct Range_MinMax {\n  static_assert(is_same_v<T,\
    \ int> || is_same_v<T, ll>);\n  using MX = Monoid_MinMax<T>;\n  using value_type\
    \ = typename MX::value_type;\n  using X = value_type;\n\n  static constexpr T\
    \ INF = infty<T>;\n  static constexpr int B = 64 / sizeof(T);\n\n  struct alignas(64)\
    \ Block {\n    T mn[B], mx[B];\n  };\n  static_assert(sizeof(Block) == 128);\n\
    \n  int n = 0;\n\n private:\n  vc<vc<Block>> dat;\n  bool use_avx2 = false;\n\n\
    \  static X as_pair(T x) { return {x, x}; }\n  static X as_pair(X x) { return\
    \ x; }\n\n  static X op(X a, X b) {\n    return {min(a.first, b.first), max(a.second,\
    \ b.second)};\n  }\n\n  static T reduce_min_scalar(const T* p) {\n    T x = INF;\n\
    \    for (int j = 0; j < B; ++j) x = min(x, p[j]);\n    return x;\n  }\n\n  static\
    \ T reduce_max_scalar(const T* p) {\n    T x = -INF;\n    for (int j = 0; j <\
    \ B; ++j) x = max(x, p[j]);\n    return x;\n  }\n\n  static X range_scalar(const\
    \ Block& p, int l, int r) {\n    X x = MX::id();\n    for (int j = l; j < r; ++j)\
    \ {\n      x.first = min(x.first, p.mn[j]);\n      x.second = max(x.second, p.mx[j]);\n\
    \    }\n    return x;\n  }\n\n#if RANGE_MINMAX_AVX2\n  __attribute__((target(\"\
    avx2\"))) static __m256i min64(__m256i a, __m256i b) {\n    return _mm256_blendv_epi8(a,\
    \ b, _mm256_cmpgt_epi64(a, b));\n  }\n\n  __attribute__((target(\"avx2\"))) static\
    \ __m256i max64(__m256i a, __m256i b) {\n    return _mm256_blendv_epi8(a, b, _mm256_cmpgt_epi64(b,\
    \ a));\n  }\n\n  __attribute__((target(\"avx2\"))) static T reduce_min_avx2(const\
    \ T* p) {\n    if constexpr (is_same_v<T, int>) {\n      __m256i a = _mm256_loadu_si256((const\
    \ __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 8));\n\
    \      a = _mm256_min_epi32(a, b);\n      a = _mm256_min_epi32(a, _mm256_permute2x128_si256(a,\
    \ a, 1));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0x4e));\n   \
    \   a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n      return _mm256_extract_epi32(a,\
    \ 0);\n    } else {\n      __m256i a = _mm256_loadu_si256((const __m256i*)p);\n\
    \      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));\n      a = min64(a,\
    \ b);\n      a = min64(a, _mm256_permute4x64_epi64(a, 0x4e));\n      a = min64(a,\
    \ _mm256_permute4x64_epi64(a, 0xb1));\n      return (T)_mm256_extract_epi64(a,\
    \ 0);\n    }\n  }\n\n  __attribute__((target(\"avx2\"))) static T reduce_max_avx2(const\
    \ T* p) {\n    if constexpr (is_same_v<T, int>) {\n      __m256i a = _mm256_loadu_si256((const\
    \ __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 8));\n\
    \      a = _mm256_max_epi32(a, b);\n      a = _mm256_max_epi32(a, _mm256_permute2x128_si256(a,\
    \ a, 1));\n      a = _mm256_max_epi32(a, _mm256_shuffle_epi32(a, 0x4e));\n   \
    \   a = _mm256_max_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n      return _mm256_extract_epi32(a,\
    \ 0);\n    } else {\n      __m256i a = _mm256_loadu_si256((const __m256i*)p);\n\
    \      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));\n      a = max64(a,\
    \ b);\n      a = max64(a, _mm256_permute4x64_epi64(a, 0x4e));\n      a = max64(a,\
    \ _mm256_permute4x64_epi64(a, 0xb1));\n      return (T)_mm256_extract_epi64(a,\
    \ 0);\n    }\n  }\n\n  // min/max \u4E21\u65B9\u306E\u90E8\u5206\u30D6\u30ED\u30C3\
    \u30AF\u3092\u30DE\u30B9\u30AF\u4ED8\u304D\u3067\u96C6\u7D04\u3059\u308B\u3002\
    \n  __attribute__((target(\"avx2\"))) static X range_avx2(\n      const Block&\
    \ p, int l, int r) {\n    if (l == 0 && r == B) {\n      return {reduce_min_avx2(p.mn),\
    \ reduce_max_avx2(p.mx)};\n    }\n    if constexpr (is_same_v<T, int>) {\n   \
    \   __m256i lo = _mm256_set1_epi32(l - 1);\n      __m256i hi = _mm256_set1_epi32(r);\n\
    \      __m256i ix = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);\n      __m256i\
    \ iy = _mm256_setr_epi32(8, 9, 10, 11, 12, 13, 14, 15);\n      __m256i mask0 =\
    \ _mm256_and_si256(\n          _mm256_cmpgt_epi32(ix, lo), _mm256_cmpgt_epi32(hi,\
    \ ix));\n      __m256i mask1 = _mm256_and_si256(\n          _mm256_cmpgt_epi32(iy,\
    \ lo), _mm256_cmpgt_epi32(hi, iy));\n      __m256i pos = _mm256_set1_epi32(INF);\n\
    \      __m256i neg = _mm256_set1_epi32(-INF);\n      __m256i a = _mm256_blendv_epi8(\n\
    \          pos, _mm256_loadu_si256((const __m256i*)p.mn), mask0);\n      __m256i\
    \ b = _mm256_blendv_epi8(\n          pos, _mm256_loadu_si256((const __m256i*)(p.mn\
    \ + 8)), mask1);\n      __m256i c = _mm256_blendv_epi8(\n          neg, _mm256_loadu_si256((const\
    \ __m256i*)p.mx), mask0);\n      __m256i d = _mm256_blendv_epi8(\n          neg,\
    \ _mm256_loadu_si256((const __m256i*)(p.mx + 8)), mask1);\n      a = _mm256_min_epi32(a,\
    \ b);\n      c = _mm256_max_epi32(c, d);\n      a = _mm256_min_epi32(a, _mm256_permute2x128_si256(a,\
    \ a, 1));\n      c = _mm256_max_epi32(c, _mm256_permute2x128_si256(c, c, 1));\n\
    \      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0x4e));\n      c = _mm256_max_epi32(c,\
    \ _mm256_shuffle_epi32(c, 0x4e));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a,\
    \ 0xb1));\n      c = _mm256_max_epi32(c, _mm256_shuffle_epi32(c, 0xb1));\n   \
    \   return {_mm256_extract_epi32(a, 0), _mm256_extract_epi32(c, 0)};\n    } else\
    \ {\n      __m256i lo = _mm256_set1_epi64x(l - 1);\n      __m256i hi = _mm256_set1_epi64x(r);\n\
    \      __m256i ix = _mm256_setr_epi64x(0, 1, 2, 3);\n      __m256i iy = _mm256_setr_epi64x(4,\
    \ 5, 6, 7);\n      __m256i mask0 = _mm256_and_si256(\n          _mm256_cmpgt_epi64(ix,\
    \ lo), _mm256_cmpgt_epi64(hi, ix));\n      __m256i mask1 = _mm256_and_si256(\n\
    \          _mm256_cmpgt_epi64(iy, lo), _mm256_cmpgt_epi64(hi, iy));\n      __m256i\
    \ pos = _mm256_set1_epi64x(INF);\n      __m256i neg = _mm256_set1_epi64x(-INF);\n\
    \      __m256i a = _mm256_blendv_epi8(\n          pos, _mm256_loadu_si256((const\
    \ __m256i*)p.mn), mask0);\n      __m256i b = _mm256_blendv_epi8(\n          pos,\
    \ _mm256_loadu_si256((const __m256i*)(p.mn + 4)), mask1);\n      __m256i c = _mm256_blendv_epi8(\n\
    \          neg, _mm256_loadu_si256((const __m256i*)p.mx), mask0);\n      __m256i\
    \ d = _mm256_blendv_epi8(\n          neg, _mm256_loadu_si256((const __m256i*)(p.mx\
    \ + 4)), mask1);\n      a = min64(a, b);\n      c = max64(c, d);\n      a = min64(a,\
    \ _mm256_permute4x64_epi64(a, 0x4e));\n      c = max64(c, _mm256_permute4x64_epi64(c,\
    \ 0x4e));\n      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));\n      c = max64(c,\
    \ _mm256_permute4x64_epi64(c, 0xb1));\n      return {(T)_mm256_extract_epi64(a,\
    \ 0), (T)_mm256_extract_epi64(c, 0)};\n    }\n  }\n#endif\n\n  // 1 \u500B\u306E\
    \u5B50\u306E\u96C6\u7D04\u5024\u306E\u5909\u5316\u3092\u89AA\u3078\u53CD\u6620\
    \u3002\u7247\u5074\u3060\u3051\u304C\u5F71\u97FF\u3092\u53D7\u3051\u308B\u5834\
    \u5408\u306F\n  // min/max \u306E\u5FC5\u8981\u306A\u5074\u3060\u3051\u518D\u8A08\
    \u7B97\u3059\u308B\u3002\n  template <typename FMIN, typename FMAX>\n  void set_by(int\
    \ i, X x, FMIN reduce_min, FMAX reduce_max) {\n    Block& leaf = dat[0][i / B];\n\
    \    const int j = i % B;\n    X old = {leaf.mn[j], leaf.mx[j]};\n    if (old\
    \ == x) return;\n    leaf.mn[j] = x.first;\n    leaf.mx[j] = x.second;\n\n   \
    \ for (int k = 0; k + 1 < (int)dat.size(); ++k) {\n      int b = i / B;\n    \
    \  Block& parent = dat[k + 1][b / B];\n      T& pmin = parent.mn[b % B];\n   \
    \   T& pmax = parent.mx[b % B];\n      X old_p = {pmin, pmax};\n      X new_p\
    \ = old_p;\n\n      if (x.first < old.first) {\n        new_p.first = min(old_p.first,\
    \ x.first);\n      } else if (x.first > old.first && old.first <= old_p.first)\
    \ {\n        new_p.first = reduce_min(dat[k][b].mn);\n      }\n      if (x.second\
    \ > old.second) {\n        new_p.second = max(old_p.second, x.second);\n     \
    \ } else if (x.second < old.second && old.second >= old_p.second) {\n        new_p.second\
    \ = reduce_max(dat[k][b].mx);\n      }\n\n      if (new_p == old_p) break;\n \
    \     pmin = new_p.first;\n      pmax = new_p.second;\n      old = old_p;\n  \
    \    x = new_p;\n      i = b;\n    }\n  }\n\n  template <typename F>\n  X prod_by(int\
    \ l, int r, F reduce) const {\n    X ans = MX::id();\n    for (const auto& level\
    \ : dat) {\n      if (l >= r) break;\n      int a = l / B, b = (r - 1) / B;\n\
    \      if (a == b) {\n        return op(ans, reduce(level[a], l % B, (r - 1) %\
    \ B + 1));\n      }\n      if (l % B) {\n        ans = op(ans, reduce(level[a],\
    \ l % B, B));\n        l = (a + 1) * B;\n      }\n      if (r % B) {\n       \
    \ ans = op(ans, reduce(level[b], 0, r % B));\n        r = b * B;\n      }\n  \
    \    l /= B;\n      r /= B;\n    }\n    return ans;\n  }\n\n#if RANGE_MINMAX_AVX2\n\
    \  __attribute__((target(\"avx2\"))) void set_avx2(int i, X x) {\n    set_by(i,\
    \ x, reduce_min_avx2, reduce_max_avx2);\n  }\n\n  __attribute__((target(\"avx2\"\
    ))) X prod_avx2(int l, int r) const {\n    return prod_by(l, r, range_avx2);\n\
    \  }\n#endif\n\n  template <typename F>\n  int descend_right(int k, int i, X sm,\
    \ F& check) const {\n    for (--k; k >= 0; --k) {\n      const auto& p = dat[k][i];\n\
    \      for (int j = 0; j < B; ++j) {\n        X y = op(sm, {p.mn[j], p.mx[j]});\n\
    \        if (!check(y)) {\n          i = B * i + j;\n          break;\n      \
    \  }\n        sm = y;\n      }\n    }\n    return min(i, n);\n  }\n\n  template\
    \ <typename F>\n  int descend_left(int k, int i, X sm, F& check) const {\n   \
    \ for (--k; k >= 0; --k) {\n      const auto& p = dat[k][i];\n      for (int j\
    \ = B - 1; j >= 0; --j) {\n        X y = op({p.mn[j], p.mx[j]}, sm);\n       \
    \ if (!check(y)) {\n          i = B * i + j;\n          break;\n        }\n  \
    \      sm = y;\n      }\n    }\n    return min(i + 1, n);\n  }\n\n public:\n \
    \ Range_MinMax() { build(0); }\n  Range_MinMax(int m) { build(m); }\n  Range_MinMax(const\
    \ vc<T>& a) { build(a); }\n  Range_MinMax(const vc<X>& a) { build(a); }\n\n  template\
    \ <typename F>\n  Range_MinMax(int m, F f) {\n    build(m, f);\n  }\n\n  void\
    \ build(int m) {\n    build(m, [](int) -> X { return MX::id(); });\n  }\n\n  void\
    \ build(const vc<T>& a) {\n    build((int)a.size(), [&](int i) -> T { return a[i];\
    \ });\n  }\n\n  void build(const vc<X>& a) {\n    build((int)a.size(), [&](int\
    \ i) -> X { return a[i]; });\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    assert(m >= 0);\n    n = m;\n    vc<X> cur(max(m, 1), MX::id());\n\
    \    for (int i = 0; i < m; ++i) cur[i] = as_pair(f(i));\n\n    dat.clear();\n\
    \    while (true) {\n      int sz = ((int)cur.size() + B - 1) / B;\n      dat.emplace_back(sz);\n\
    \      vc<X> nxt(sz, MX::id());\n      for (int b = 0; b < sz; ++b) {\n      \
    \  Block& p = dat.back()[b];\n        fill(p.mn, p.mn + B, INF);\n        fill(p.mx,\
    \ p.mx + B, -INF);\n        for (int j = 0; j < B && b * B + j < (int)cur.size();\
    \ ++j) {\n          p.mn[j] = cur[b * B + j].first;\n          p.mx[j] = cur[b\
    \ * B + j].second;\n        }\n        nxt[b] = {reduce_min_scalar(p.mn), reduce_max_scalar(p.mx)};\n\
    \      }\n      if (cur.size() == 1) break;\n      cur.swap(nxt);\n    }\n\n \
    \   use_avx2 = false;\n#if RANGE_MINMAX_AVX2\n    __builtin_cpu_init();\n    use_avx2\
    \ = __builtin_cpu_supports(\"avx2\");\n#endif\n  }\n\n  X get(int i) const {\n\
    \    assert(0 <= i && i < n);\n    const auto& p = dat[0][i / B];\n    return\
    \ {p.mn[i % B], p.mx[i % B]};\n  }\n\n  vc<X> get_all() const {\n    vc<X> a(n);\n\
    \    for (int i = 0; i < n; ++i) a[i] = get(i);\n    return a;\n  }\n\n  void\
    \ set(int i, const X& x) {\n    assert(0 <= i && i < n);\n#if RANGE_MINMAX_AVX2\n\
    \    if (use_avx2) return set_avx2(i, x);\n#endif\n    set_by(i, x, reduce_min_scalar,\
    \ reduce_max_scalar);\n  }\n\n  void set(int i, T x) { set(i, X{x, x}); }\n\n\
    \  void multiply(int i, const X& x) { set(i, op(get(i), x)); }\n  void multiply(int\
    \ i, T x) { multiply(i, X{x, x}); }\n\n  X prod(int l, int r) const {\n    assert(0\
    \ <= l && l <= r && r <= n);\n#if RANGE_MINMAX_AVX2\n    if (use_avx2) return\
    \ prod_avx2(l, r);\n#endif\n    return prod_by(l, r, range_scalar);\n  }\n\n \
    \ X prod_all() const {\n    const auto& p = dat.back()[0];\n    return {p.mn[0],\
    \ p.mx[0]};\n  }\n\n  template <typename F>\n  int max_right(F check, int L) const\
    \ {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n) return\
    \ n;\n    X sm = MX::id();\n    int i = L;\n    for (int k = 0; k < (int)dat.size();\
    \ ++k) {\n      if (i % B || k + 1 == (int)dat.size()) {\n        int b = i /\
    \ B;\n        for (int j = i % B; j < B; ++j) {\n          const auto& p = dat[k][b];\n\
    \          X y = op(sm, {p.mn[j], p.mx[j]});\n          if (!check(y)) {\n   \
    \         return descend_right(k, b * B + j, sm, check);\n          }\n      \
    \    sm = y;\n        }\n        i = b + 1;\n      } else {\n        i /= B;\n\
    \      }\n    }\n    return n;\n  }\n\n  template <typename F>\n  int min_left(F\
    \ check, int R) const {\n    assert(0 <= R && R <= n && check(MX::id()));\n  \
    \  if (R == 0) return 0;\n    X sm = MX::id();\n    int i = R;\n    for (int k\
    \ = 0; k < (int)dat.size(); ++k) {\n      if (i % B || k + 1 == (int)dat.size())\
    \ {\n        if (i == 0) return 0;\n        int b = (i - 1) / B;\n        for\
    \ (int j = (i - 1) % B; j >= 0; --j) {\n          const auto& p = dat[k][b];\n\
    \          X y = op({p.mn[j], p.mx[j]}, sm);\n          if (!check(y)) {\n   \
    \         return descend_left(k, b * B + j, sm, check);\n          }\n       \
    \   sm = y;\n        }\n        i = b;\n      } else {\n        i /= B;\n    \
    \  }\n    }\n    return 0;\n  }\n};\n\n#undef RANGE_MINMAX_AVX2\n#line 3 \"test/5_ai_generated_test/range_minmax.test.cpp\"\
    \n\n\ntemplate<class T>void check_all() {\n  mt19937_64 mt(70042+sizeof(T));\n\
    \  using P=pair<T,T>;\n  using D=Range_MinMax<T>;\n  constexpr T INF=infty<T>;\n\
    \  const P ID={INF,-INF};\n  auto oper=[&](P a,P b){return P{min(a.first,b.first),max(a.second,b.second)};};\n\
    \  int checks=0;\n  for(int n:{0,1,2,3,4,7,8,9,15,16,17,31,32,33,63,64,65,127,128,129,255,256,257,511,512,513,1000,4096})\
    \ {\n    vector<P> v(n,ID);\n    D d(n);\n    assert(d.n==n);\n    assert(d.prod(0,n)==ID);\n\
    \    for(int i=0;i<n;i++)assert(d.get(i)==ID);\n    for(int it=0;it<(n<=513?850:250);it++){\n\
    \      int mode=mt()%9;\n      auto scalar=[&]()->T {return (T)((int)(mt()%1000001)-500000);};\n\
    \      int i=(n?mt()%n:0);\n      if(n && mode<=3){\n        if(mode==0){T x=scalar();d.set(i,x);v[i]={x,x};}\n\
    \        if(mode==1){T a=scalar(),b=scalar();if(a>b)swap(a,b);d.set(i,P{a,b});v[i]={a,b};}\n\
    \        if(mode==2){T x=scalar();d.multiply(i,x);v[i]=oper(v[i],P{x,x});}\n \
    \       if(mode==3){T a=scalar(),b=scalar();if(a>b)swap(a,b);d.multiply(i,P{a,b});v[i]=oper(v[i],P{a,b});}\n\
    \        assert(d.get(i)==v[i]);\n      } else if(mode==4) {\n        if(n &&\
    \ mt()%5==0){d.set(i,ID);v[i]=ID;}\n        assert(d.get_all()==v);\n      } else\
    \ if(mode==5) {\n        if(n && mt()%20==0){\n          if(mt()%2){d.build(n,[&](int\
    \ j){return v[j];});}\n          else {d.build(v);}\n        }\n      }\n    \
    \  int l=mt()%(n+1),r=mt()%(n+1);if(l>r)swap(l,r);\n      P ans=ID;\n      for(int\
    \ j=l;j<r;j++)ans=oper(ans,v[j]);\n      P got=d.prod(l,r);\n      if(got!=ans){cerr<<\"\
    PROD FAIL type=\"<<sizeof(T)<<\" n=\"<<n<<\" it=\"<<it<<\" l=\"<<l<<\" r=\"<<r<<\"\
    \ got=\"<<got.first<<\",\"<<got.second<<\" exp=\"<<ans.first<<\",\"<<ans.second<<\"\
    \\n\";abort();}\n      P all=ID;for(auto x:v)all=oper(all,x);\n      assert(d.prod_all()==all);\n\
    \      checks++;\n      if(it%3==0){\n        int L=mt()%(n+1),R=mt()%(n+1);\n\
    \        T bound=(T)(mt()%500001);\n        auto pred=[&](P p) {return p.first>=-bound&&p.second<=bound;};\n\
    \        int expR=L;\n        P cur=ID;\n        for(;expR<n;expR++){P nxt=oper(cur,v[expR]);if(!pred(nxt))break;cur=nxt;}\n\
    \        int expL=R;\n        cur=ID;\n        for(;expL>0;){P nxt=oper(v[expL-1],cur);if(!pred(nxt))break;cur=nxt;--expL;}\n\
    \        int gotR=d.max_right(pred,L),gotL=d.min_left(pred,R);\n        if(gotR!=expR||gotL!=expL){cerr<<\"\
    BOUNDARY FAIL type=\"<<sizeof(T)<<\" n=\"<<n<<\" it=\"<<it<<\" L=\"<<L<<\" R=\"\
    <<R<<\" bound=\"<<bound<<\" gotR=\"<<gotR<<\" expR=\"<<expR<<\" gotL=\"<<gotL<<\"\
    \ expL=\"<<expL<<\"\\n\";abort();}\n      }\n    }\n    // Rebuild from scalar\
    \ values and from pair-producing lambda.\n    vector<T> values(n);\n    for(auto&\
    \ x:values)x=(T)((int)(mt()%1000001)-500000);\n    d.build(values);\n    for(int\
    \ i=0;i<n;i++)assert(d.get(i)==P(values[i],values[i]));\n    d.build(n,[&](int\
    \ i){return values[i];});\n    for(int i=0;i<n;i++)assert(d.get(i)==P(values[i],values[i]));\n\
    \    d.build(n,[&](int i)->P{return {values[i],values[i]};});\n    for(int i=0;i<n;i++)assert(d.get(i)==P(values[i],values[i]));\n\
    \    d.build(n);assert(d.prod_all()==ID);\n  }\n  D empty;assert(empty.prod(0,0)==ID);assert(empty.prod_all()==ID);\n\
    \  cerr<<\"PASS \"<<sizeof(T)*8<<\"-bit \"<<checks<<\" operations\\n\";\n}\nint\
    \ main(){check_all<int>();check_all<ll>();}\n"
  code: "#include \"my_template.hpp\"\n#include \"ds/segtree/range_minmax.hpp\"\n\n\
    \ntemplate<class T>void check_all() {\n  mt19937_64 mt(70042+sizeof(T));\n  using\
    \ P=pair<T,T>;\n  using D=Range_MinMax<T>;\n  constexpr T INF=infty<T>;\n  const\
    \ P ID={INF,-INF};\n  auto oper=[&](P a,P b){return P{min(a.first,b.first),max(a.second,b.second)};};\n\
    \  int checks=0;\n  for(int n:{0,1,2,3,4,7,8,9,15,16,17,31,32,33,63,64,65,127,128,129,255,256,257,511,512,513,1000,4096})\
    \ {\n    vector<P> v(n,ID);\n    D d(n);\n    assert(d.n==n);\n    assert(d.prod(0,n)==ID);\n\
    \    for(int i=0;i<n;i++)assert(d.get(i)==ID);\n    for(int it=0;it<(n<=513?850:250);it++){\n\
    \      int mode=mt()%9;\n      auto scalar=[&]()->T {return (T)((int)(mt()%1000001)-500000);};\n\
    \      int i=(n?mt()%n:0);\n      if(n && mode<=3){\n        if(mode==0){T x=scalar();d.set(i,x);v[i]={x,x};}\n\
    \        if(mode==1){T a=scalar(),b=scalar();if(a>b)swap(a,b);d.set(i,P{a,b});v[i]={a,b};}\n\
    \        if(mode==2){T x=scalar();d.multiply(i,x);v[i]=oper(v[i],P{x,x});}\n \
    \       if(mode==3){T a=scalar(),b=scalar();if(a>b)swap(a,b);d.multiply(i,P{a,b});v[i]=oper(v[i],P{a,b});}\n\
    \        assert(d.get(i)==v[i]);\n      } else if(mode==4) {\n        if(n &&\
    \ mt()%5==0){d.set(i,ID);v[i]=ID;}\n        assert(d.get_all()==v);\n      } else\
    \ if(mode==5) {\n        if(n && mt()%20==0){\n          if(mt()%2){d.build(n,[&](int\
    \ j){return v[j];});}\n          else {d.build(v);}\n        }\n      }\n    \
    \  int l=mt()%(n+1),r=mt()%(n+1);if(l>r)swap(l,r);\n      P ans=ID;\n      for(int\
    \ j=l;j<r;j++)ans=oper(ans,v[j]);\n      P got=d.prod(l,r);\n      if(got!=ans){cerr<<\"\
    PROD FAIL type=\"<<sizeof(T)<<\" n=\"<<n<<\" it=\"<<it<<\" l=\"<<l<<\" r=\"<<r<<\"\
    \ got=\"<<got.first<<\",\"<<got.second<<\" exp=\"<<ans.first<<\",\"<<ans.second<<\"\
    \\n\";abort();}\n      P all=ID;for(auto x:v)all=oper(all,x);\n      assert(d.prod_all()==all);\n\
    \      checks++;\n      if(it%3==0){\n        int L=mt()%(n+1),R=mt()%(n+1);\n\
    \        T bound=(T)(mt()%500001);\n        auto pred=[&](P p) {return p.first>=-bound&&p.second<=bound;};\n\
    \        int expR=L;\n        P cur=ID;\n        for(;expR<n;expR++){P nxt=oper(cur,v[expR]);if(!pred(nxt))break;cur=nxt;}\n\
    \        int expL=R;\n        cur=ID;\n        for(;expL>0;){P nxt=oper(v[expL-1],cur);if(!pred(nxt))break;cur=nxt;--expL;}\n\
    \        int gotR=d.max_right(pred,L),gotL=d.min_left(pred,R);\n        if(gotR!=expR||gotL!=expL){cerr<<\"\
    BOUNDARY FAIL type=\"<<sizeof(T)<<\" n=\"<<n<<\" it=\"<<it<<\" L=\"<<L<<\" R=\"\
    <<R<<\" bound=\"<<bound<<\" gotR=\"<<gotR<<\" expR=\"<<expR<<\" gotL=\"<<gotL<<\"\
    \ expL=\"<<expL<<\"\\n\";abort();}\n      }\n    }\n    // Rebuild from scalar\
    \ values and from pair-producing lambda.\n    vector<T> values(n);\n    for(auto&\
    \ x:values)x=(T)((int)(mt()%1000001)-500000);\n    d.build(values);\n    for(int\
    \ i=0;i<n;i++)assert(d.get(i)==P(values[i],values[i]));\n    d.build(n,[&](int\
    \ i){return values[i];});\n    for(int i=0;i<n;i++)assert(d.get(i)==P(values[i],values[i]));\n\
    \    d.build(n,[&](int i)->P{return {values[i],values[i]};});\n    for(int i=0;i<n;i++)assert(d.get(i)==P(values[i],values[i]));\n\
    \    d.build(n);assert(d.prod_all()==ID);\n  }\n  D empty;assert(empty.prod(0,0)==ID);assert(empty.prod_all()==ID);\n\
    \  cerr<<\"PASS \"<<sizeof(T)*8<<\"-bit \"<<checks<<\" operations\\n\";\n}\nint\
    \ main(){check_all<int>();check_all<ll>();}\n"
  dependsOn:
  - my_template.hpp
  - ds/segtree/range_minmax.hpp
  - alg/monoid/minmax.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/range_minmax.test.cpp
  requiredBy: []
  timestamp: '2026-11-17 17:35:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/5_ai_generated_test/range_minmax.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/range_minmax.test.cpp
- /verify/test/5_ai_generated_test/range_minmax.test.cpp.html
title: test/5_ai_generated_test/range_minmax.test.cpp
---
