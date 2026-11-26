---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/rollback_unionfind.hpp
    title: ds/unionfind/rollback_unionfind.hpp
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
    #line 1 \"ds/unionfind/rollback_unionfind.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/unionfind/rollback_unionfind.hpp\n\
    #line 1 \"ds/rollback_array.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/rollback_array.hpp\n\
    \ntemplate <typename T>\nstruct Rollback_Array {\n  int N;\n  vc<T> dat;\n  vc<pair<int,\
    \ T>> history;\n\n  Rollback_Array() {}\n  Rollback_Array(vc<T> x) : N(len(x)),\
    \ dat(x) {}\n  Rollback_Array(int N) : N(N), dat(N) {}\n  template <typename F>\n\
    \  Rollback_Array(int N, F f) : N(N) {\n    dat.reserve(N);\n    FOR(i, N) dat.eb(f(i));\n\
    \  }\n\n  int time() { return len(history); }\n  void rollback(int t) {\n    while\
    \ (t < time()) {\n      auto [idx, v] = POP(history);\n      dat[idx] = v;\n \
    \   }\n  }\n  T get(int idx) { return dat[idx]; }\n  void set(int idx, T x) {\n\
    \    history.eb(idx, dat[idx]);\n    dat[idx] = x;\n  }\n\n  vc<T> get_all() {\
    \ return dat; }\n};\n#line 3 \"ds/unionfind/rollback_unionfind.hpp\"\n\nstruct\
    \ Rollback_UnionFind {\n  int n;\n  Rollback_Array<int> dat; // parent or size\n\
    \n  Rollback_UnionFind(int n) : n(n), dat(vc<int>(n, -1)) {}\n\n  int operator[](int\
    \ v) {\n    while (dat.get(v) >= 0) v = dat.get(v);\n    return v;\n  }\n\n  ll\
    \ size(int v) { return -dat.get((*this)[v]); }\n  int time() { return dat.time();\
    \ }\n  void rollback(int t) { dat.rollback(t); }\n  void reset() { rollback(0);\
    \ }\n\n  bool merge(int a, int b) {\n    a = (*this)[a], b = (*this)[b];\n   \
    \ if (a == b) return false;\n    if (dat.get(a) > dat.get(b)) swap(a, b);\n  \
    \  dat.set(a, dat.get(a) + dat.get(b));\n    dat.set(b, a);\n    return true;\n\
    \  }\n  vc<int> get_all() {\n    vc<int> ANS(n);\n    FOR(i, n) ANS[i] = (*this)[i];\n\
    \    return ANS;\n  }\n};\n#line 3 \"test/5_ai_generated_test/rollback_unionfind.test.cpp\"\
    \n\n/*\n\u5BFE\u8C61: ds/unionfind/rollback_unionfind.hpp \u3068\u4F9D\u5B58\u5148\
    \ ds/rollback_array.hpp\u3002\n  merge\u3001operator[]\u3001size\u3001time\u3001\
    rollback\u3001reset\u3001get_all \u3092\u691C\u8A3C\u3059\u308B\u3002\n\n\u72EC\
    \u7ACB\u30AA\u30E9\u30AF\u30EB: \u5404\u9802\u70B9\u306E\u9023\u7D50\u6210\u5206\
    \u30E9\u30D9\u30EB\u3092 vector<int> \u3068\u3057\u3066\u76F4\u63A5\u7BA1\u7406\
    \u3059\u308B\u3002\n  \u30DE\u30FC\u30B8\u306F\u7247\u65B9\u306E\u30E9\u30D9\u30EB\
    \u3092\u5168\u9802\u70B9\u306B\u3064\u3044\u3066\u7F6E\u63DB\u3057\u3001\u30B9\
    \u30CA\u30C3\u30D7\u30B7\u30E7\u30C3\u30C8\u306F\n  \u30E9\u30D9\u30EB\u914D\u5217\
    \u305D\u306E\u3082\u306E\u3092\u30B3\u30D4\u30FC\u3059\u308B\u3002UF \u6728\u3084\
    \ rollback \u5C65\u6B74\u306F\u6A21\u5023\u3057\u306A\u3044\u3002\n  \u30E9\u30D9\
    \u30EB\u306E\u6570\u5024\u305D\u306E\u3082\u306E\u306F\u4EFB\u610F\u306A\u306E\
    \u3067\u3001\u5168\u9802\u70B9\u5BFE\u306E\u540C\u5024\u95A2\u4FC2\u3067\u6BD4\
    \u8F03\u3059\u308B\u3002\n\n\u72D9\u3046\u4E0D\u5177\u5408: \u30DE\u30FC\u30B8\
    \u6210\u529F/\u5931\u6557\u6642\u306E\u6642\u523B\u66F4\u65B0\u3001\u9023\u7D50\
    \u6210\u5206\u30B5\u30A4\u30BA\u3001\u540C\u3058\u6210\u5206\u306E\n  \u518D\u30DE\
    \u30FC\u30B8\u3001rollback \u6642\u306B\u5B50\u3060\u3051/\u89AA\u3060\u3051\u304C\
    \u5FA9\u5143\u3055\u308C\u308B\u4E0D\u6574\u5408\u3001\u7570\u306A\u308B\n  \u30B9\
    \u30CA\u30C3\u30D7\u30B7\u30E7\u30C3\u30C8\u3078\u623B\u3063\u3066\u679D\u5206\
    \u304B\u308C\u3057\u305F\u5F8C\u306E\u53E4\u3044\u72B6\u614B\u3001reset \u5F8C\
    \u306E\u6B8B\u7559\u3002\n\n\u6761\u4EF6: \u9802\u70B9\u306F 0 <= v < n\u3001\
    rollback \u306F\u73FE\u5728\u306E\u6642\u523B\u4EE5\u4E0B\u306B\u53D6\u5F97\u3057\
    \u305F\n  \u30B9\u30CA\u30C3\u30D7\u30B7\u30E7\u30C3\u30C8\u306B\u5BFE\u3057\u3066\
    \u306E\u307F\u884C\u3046\u3002n=0 \u3067\u306F\u9802\u70B9\u64CD\u4F5C\u3092\u884C\
    \u308F\u306A\u3044\u3002\n  n<=32\u3001\u56FA\u5B9A seed 0x6117dabc \u306B\u3088\
    \u308B\u518D\u73FE\u53EF\u80FD\u306A\u4E71\u629E\u64CD\u4F5C\u3092\u7528\u3044\
    \u308B\u3002\n*/\n\nstruct Reference_Partition {\n  vector<int> label;\n  explicit\
    \ Reference_Partition(int n) : label(n) {\n    iota(label.begin(), label.end(),\
    \ 0);\n  }\n  bool merge(int a, int b) {\n    int x = label[a], y = label[b];\n\
    \    if (x == y) return false;\n    for (int& z : label) if (z == y) z = x;\n\
    \    return true;\n  }\n  int size(int v) const {\n    return int(count(label.begin(),\
    \ label.end(), label[v]));\n  }\n};\n\nstruct Snapshot {\n  int t;\n  vector<int>\
    \ label;\n};\n\nvoid check(Rollback_UnionFind& uf, const Reference_Partition&\
    \ ref,\n           int n, int step) {\n  if (uf.time() < 0) abort();\n  vector<int>\
    \ roots = uf.get_all();\n  if (int(roots.size()) != n) abort();\n  for (int i\
    \ = 0; i < n; ++i) {\n    int root = uf[i];\n    if (root != roots[i] || root\
    \ < 0 || root >= n ||\n        uf[root] != root || uf.size(i) != ref.size(i))\
    \ {\n      cerr << \"Rollback_UnionFind root/size mismatch n=\" << n\n       \
    \    << \" step=\" << step << \" v=\" << i << '\\n';\n      abort();\n    }\n\
    \    for (int j = 0; j < n; ++j) {\n      bool got = (roots[i] == roots[j]);\n\
    \      bool expected = (ref.label[i] == ref.label[j]);\n      if (got != expected)\
    \ {\n        cerr << \"Rollback_UnionFind connectivity mismatch n=\" << n\n  \
    \           << \" step=\" << step << \" pair=(\" << i << ',' << j << \")\\n\"\
    ;\n        abort();\n      }\n    }\n  }\n}\n\nvoid run(int n, uint64_t seed)\
    \ {\n  Rollback_UnionFind uf(n);\n  Reference_Partition ref(n);\n  vector<Snapshot>\
    \ snapshots{{uf.time(), ref.label}};\n  mt19937_64 rng(seed ^ (uint64_t(n) * 0x9e3779b97f4a7c15ULL));\n\
    \  if (uf.time() != 0) abort();\n  check(uf, ref, n, -1);\n\n  for (int step =\
    \ 0; step < 4400; ++step) {\n    int op = int(rng() % 16);\n    if (n && op <\
    \ 10) {\n      int a = int(rng() % uint64_t(n));\n      int b = (op == 0 ? a :\
    \ int(rng() % uint64_t(n)));\n      int before = uf.time();\n      bool expected\
    \ = ref.merge(a, b);\n      bool got = uf.merge(a, b);\n      if (got != expected\
    \ || (got && uf.time() <= before) ||\n          (!got && uf.time() != before))\
    \ {\n        cerr << \"Rollback_UnionFind merge/time mismatch n=\" << n\n    \
    \         << \" step=\" << step << \" a=\" << a << \" b=\" << b << '\\n';\n  \
    \      abort();\n      }\n    } else if (op < 12 && !snapshots.empty()) {\n  \
    \    // \u904E\u53BB\u306E\u4EFB\u610F\u306E\u7956\u5148\u3078\u623B\u308A\u3001\
    \u4EE5\u5F8C\u305D\u306E\u6642\u523B\u3088\u308A\u672A\u6765\u306E\u5C65\u6B74\
    \u306F\u7834\u68C4\u3059\u308B\u3002\n      int k = int(rng() % uint64_t(snapshots.size()));\n\
    \      Snapshot s = snapshots[k];\n      uf.rollback(s.t);\n      ref.label =\
    \ s.label;\n      if (uf.time() != s.t) abort();\n      snapshots.erase(remove_if(snapshots.begin(),\
    \ snapshots.end(),\n                                [&](const Snapshot& x) { return\
    \ x.t > s.t; }),\n                      snapshots.end());\n    } else if (op ==\
    \ 12) {\n      uf.reset();\n      ref = Reference_Partition(n);\n      snapshots\
    \ = {{0, ref.label}};\n      if (uf.time() != 0) abort();\n    } else {\n    \
    \  snapshots.push_back({uf.time(), ref.label});\n    }\n    check(uf, ref, n,\
    \ step);\n  }\n\n  // \u4EFB\u610F\u306E\u5206\u5C90\u306E\u6700\u7D42\u72B6\u614B\
    \u304B\u3089\u521D\u671F\u72B6\u614B\u307E\u3067\u623B\u3059\u3002\n  uf.reset();\n\
    \  ref = Reference_Partition(n);\n  if (uf.time() != 0) abort();\n  check(uf,\
    \ ref, n, 5000);\n  if (n >= 2) {\n    int t = uf.time();\n    uf.merge(0, 1);\n\
    \    ref.merge(0, 1);\n    check(uf, ref, n, 5001);\n    uf.rollback(t);\n   \
    \ ref = Reference_Partition(n);\n    check(uf, ref, n, 5002);\n    // \u540C\u3058\
    \u6642\u523B\u304B\u3089\u3001\u5225\u306E\u30DE\u30FC\u30B8\u3092\u7E70\u308A\
    \u8FD4\u3057\u3066\u5C65\u6B74\u306E\u4F7F\u3044\u56DE\u3057\u3092\u78BA\u8A8D\
    \u3059\u308B\u3002\n    uf.merge(n - 1, 0);\n    ref.merge(n - 1, 0);\n    check(uf,\
    \ ref, n, 5003);\n    uf.rollback(t);\n    ref = Reference_Partition(n);\n   \
    \ check(uf, ref, n, 5004);\n  }\n  cerr << \"PASS rollback_unionfind n=\" << n\
    \ << '\\n';\n}\n\nint main() {\n  for (int n : {0, 1, 2, 3, 4, 7, 8, 16, 24, 32})\n\
    \    run(n, 0x6117dabcULL);\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"ds/unionfind/rollback_unionfind.hpp\"\
    \n\n/*\n\u5BFE\u8C61: ds/unionfind/rollback_unionfind.hpp \u3068\u4F9D\u5B58\u5148\
    \ ds/rollback_array.hpp\u3002\n  merge\u3001operator[]\u3001size\u3001time\u3001\
    rollback\u3001reset\u3001get_all \u3092\u691C\u8A3C\u3059\u308B\u3002\n\n\u72EC\
    \u7ACB\u30AA\u30E9\u30AF\u30EB: \u5404\u9802\u70B9\u306E\u9023\u7D50\u6210\u5206\
    \u30E9\u30D9\u30EB\u3092 vector<int> \u3068\u3057\u3066\u76F4\u63A5\u7BA1\u7406\
    \u3059\u308B\u3002\n  \u30DE\u30FC\u30B8\u306F\u7247\u65B9\u306E\u30E9\u30D9\u30EB\
    \u3092\u5168\u9802\u70B9\u306B\u3064\u3044\u3066\u7F6E\u63DB\u3057\u3001\u30B9\
    \u30CA\u30C3\u30D7\u30B7\u30E7\u30C3\u30C8\u306F\n  \u30E9\u30D9\u30EB\u914D\u5217\
    \u305D\u306E\u3082\u306E\u3092\u30B3\u30D4\u30FC\u3059\u308B\u3002UF \u6728\u3084\
    \ rollback \u5C65\u6B74\u306F\u6A21\u5023\u3057\u306A\u3044\u3002\n  \u30E9\u30D9\
    \u30EB\u306E\u6570\u5024\u305D\u306E\u3082\u306E\u306F\u4EFB\u610F\u306A\u306E\
    \u3067\u3001\u5168\u9802\u70B9\u5BFE\u306E\u540C\u5024\u95A2\u4FC2\u3067\u6BD4\
    \u8F03\u3059\u308B\u3002\n\n\u72D9\u3046\u4E0D\u5177\u5408: \u30DE\u30FC\u30B8\
    \u6210\u529F/\u5931\u6557\u6642\u306E\u6642\u523B\u66F4\u65B0\u3001\u9023\u7D50\
    \u6210\u5206\u30B5\u30A4\u30BA\u3001\u540C\u3058\u6210\u5206\u306E\n  \u518D\u30DE\
    \u30FC\u30B8\u3001rollback \u6642\u306B\u5B50\u3060\u3051/\u89AA\u3060\u3051\u304C\
    \u5FA9\u5143\u3055\u308C\u308B\u4E0D\u6574\u5408\u3001\u7570\u306A\u308B\n  \u30B9\
    \u30CA\u30C3\u30D7\u30B7\u30E7\u30C3\u30C8\u3078\u623B\u3063\u3066\u679D\u5206\
    \u304B\u308C\u3057\u305F\u5F8C\u306E\u53E4\u3044\u72B6\u614B\u3001reset \u5F8C\
    \u306E\u6B8B\u7559\u3002\n\n\u6761\u4EF6: \u9802\u70B9\u306F 0 <= v < n\u3001\
    rollback \u306F\u73FE\u5728\u306E\u6642\u523B\u4EE5\u4E0B\u306B\u53D6\u5F97\u3057\
    \u305F\n  \u30B9\u30CA\u30C3\u30D7\u30B7\u30E7\u30C3\u30C8\u306B\u5BFE\u3057\u3066\
    \u306E\u307F\u884C\u3046\u3002n=0 \u3067\u306F\u9802\u70B9\u64CD\u4F5C\u3092\u884C\
    \u308F\u306A\u3044\u3002\n  n<=32\u3001\u56FA\u5B9A seed 0x6117dabc \u306B\u3088\
    \u308B\u518D\u73FE\u53EF\u80FD\u306A\u4E71\u629E\u64CD\u4F5C\u3092\u7528\u3044\
    \u308B\u3002\n*/\n\nstruct Reference_Partition {\n  vector<int> label;\n  explicit\
    \ Reference_Partition(int n) : label(n) {\n    iota(label.begin(), label.end(),\
    \ 0);\n  }\n  bool merge(int a, int b) {\n    int x = label[a], y = label[b];\n\
    \    if (x == y) return false;\n    for (int& z : label) if (z == y) z = x;\n\
    \    return true;\n  }\n  int size(int v) const {\n    return int(count(label.begin(),\
    \ label.end(), label[v]));\n  }\n};\n\nstruct Snapshot {\n  int t;\n  vector<int>\
    \ label;\n};\n\nvoid check(Rollback_UnionFind& uf, const Reference_Partition&\
    \ ref,\n           int n, int step) {\n  if (uf.time() < 0) abort();\n  vector<int>\
    \ roots = uf.get_all();\n  if (int(roots.size()) != n) abort();\n  for (int i\
    \ = 0; i < n; ++i) {\n    int root = uf[i];\n    if (root != roots[i] || root\
    \ < 0 || root >= n ||\n        uf[root] != root || uf.size(i) != ref.size(i))\
    \ {\n      cerr << \"Rollback_UnionFind root/size mismatch n=\" << n\n       \
    \    << \" step=\" << step << \" v=\" << i << '\\n';\n      abort();\n    }\n\
    \    for (int j = 0; j < n; ++j) {\n      bool got = (roots[i] == roots[j]);\n\
    \      bool expected = (ref.label[i] == ref.label[j]);\n      if (got != expected)\
    \ {\n        cerr << \"Rollback_UnionFind connectivity mismatch n=\" << n\n  \
    \           << \" step=\" << step << \" pair=(\" << i << ',' << j << \")\\n\"\
    ;\n        abort();\n      }\n    }\n  }\n}\n\nvoid run(int n, uint64_t seed)\
    \ {\n  Rollback_UnionFind uf(n);\n  Reference_Partition ref(n);\n  vector<Snapshot>\
    \ snapshots{{uf.time(), ref.label}};\n  mt19937_64 rng(seed ^ (uint64_t(n) * 0x9e3779b97f4a7c15ULL));\n\
    \  if (uf.time() != 0) abort();\n  check(uf, ref, n, -1);\n\n  for (int step =\
    \ 0; step < 4400; ++step) {\n    int op = int(rng() % 16);\n    if (n && op <\
    \ 10) {\n      int a = int(rng() % uint64_t(n));\n      int b = (op == 0 ? a :\
    \ int(rng() % uint64_t(n)));\n      int before = uf.time();\n      bool expected\
    \ = ref.merge(a, b);\n      bool got = uf.merge(a, b);\n      if (got != expected\
    \ || (got && uf.time() <= before) ||\n          (!got && uf.time() != before))\
    \ {\n        cerr << \"Rollback_UnionFind merge/time mismatch n=\" << n\n    \
    \         << \" step=\" << step << \" a=\" << a << \" b=\" << b << '\\n';\n  \
    \      abort();\n      }\n    } else if (op < 12 && !snapshots.empty()) {\n  \
    \    // \u904E\u53BB\u306E\u4EFB\u610F\u306E\u7956\u5148\u3078\u623B\u308A\u3001\
    \u4EE5\u5F8C\u305D\u306E\u6642\u523B\u3088\u308A\u672A\u6765\u306E\u5C65\u6B74\
    \u306F\u7834\u68C4\u3059\u308B\u3002\n      int k = int(rng() % uint64_t(snapshots.size()));\n\
    \      Snapshot s = snapshots[k];\n      uf.rollback(s.t);\n      ref.label =\
    \ s.label;\n      if (uf.time() != s.t) abort();\n      snapshots.erase(remove_if(snapshots.begin(),\
    \ snapshots.end(),\n                                [&](const Snapshot& x) { return\
    \ x.t > s.t; }),\n                      snapshots.end());\n    } else if (op ==\
    \ 12) {\n      uf.reset();\n      ref = Reference_Partition(n);\n      snapshots\
    \ = {{0, ref.label}};\n      if (uf.time() != 0) abort();\n    } else {\n    \
    \  snapshots.push_back({uf.time(), ref.label});\n    }\n    check(uf, ref, n,\
    \ step);\n  }\n\n  // \u4EFB\u610F\u306E\u5206\u5C90\u306E\u6700\u7D42\u72B6\u614B\
    \u304B\u3089\u521D\u671F\u72B6\u614B\u307E\u3067\u623B\u3059\u3002\n  uf.reset();\n\
    \  ref = Reference_Partition(n);\n  if (uf.time() != 0) abort();\n  check(uf,\
    \ ref, n, 5000);\n  if (n >= 2) {\n    int t = uf.time();\n    uf.merge(0, 1);\n\
    \    ref.merge(0, 1);\n    check(uf, ref, n, 5001);\n    uf.rollback(t);\n   \
    \ ref = Reference_Partition(n);\n    check(uf, ref, n, 5002);\n    // \u540C\u3058\
    \u6642\u523B\u304B\u3089\u3001\u5225\u306E\u30DE\u30FC\u30B8\u3092\u7E70\u308A\
    \u8FD4\u3057\u3066\u5C65\u6B74\u306E\u4F7F\u3044\u56DE\u3057\u3092\u78BA\u8A8D\
    \u3059\u308B\u3002\n    uf.merge(n - 1, 0);\n    ref.merge(n - 1, 0);\n    check(uf,\
    \ ref, n, 5003);\n    uf.rollback(t);\n    ref = Reference_Partition(n);\n   \
    \ check(uf, ref, n, 5004);\n  }\n  cerr << \"PASS rollback_unionfind n=\" << n\
    \ << '\\n';\n}\n\nint main() {\n  for (int n : {0, 1, 2, 3, 4, 7, 8, 16, 24, 32})\n\
    \    run(n, 0x6117dabcULL);\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/unionfind/rollback_unionfind.hpp
  - ds/rollback_array.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/rollback_unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-11-18 16:13:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/rollback_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/rollback_unionfind.test.cpp
- /verify/test/5_ai_generated_test/rollback_unionfind.test.cpp.html
title: test/5_ai_generated_test/rollback_unionfind.test.cpp
---
