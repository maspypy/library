---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mod/first_mod_range_of_linear.hpp
    title: mod/first_mod_range_of_linear.hpp
  - icon: ':x:'
    path: mod/min_of_linear_segments.hpp
    title: mod/min_of_linear_segments.hpp
  - icon: ':x:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/first_mod_range_of_linear.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n//\
    \ \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6210\
    \u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\n#pragma GCC target(\"\
    avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include <cassert>\n\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class>\nconstexpr\
    \ bool dependent_false = false;\n\ntemplate <class T>\nconstexpr T infty = []\
    \ {\n  static_assert(dependent_false<T>, \"infty<T> is not defined\");\n  return\
    \ T{};\n}();\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
    \ <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = numeric_limits<double>::infinity();\n\
    template <>\nconstexpr long double infty<long double> =\n    numeric_limits<long\
    \ double>::infinity();\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing pq_max = priority_queue<T>;\n\
    template <class T>\nusing pq_min = priority_queue<T, vector<T>, greater<T>>;\n\
    \n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a) - 1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)\n\
    #define overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n\
    #define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\n// require y > 0\n\
    template <typename T>\nT floor(T x, T y) {\n  return x / y - (x % y < 0);\n}\n\
    \n// require y > 0\ntemplate <typename T>\nT ceil(T x, T y) {\n  return (x / y)\
    \ + (x % y > 0);\n}\n\n// require y > 0\ntemplate <typename T>\nT bmod(T x, T\
    \ y) {\n  T r = x % y;\n  return (r < 0 ? r + y : r);\n}\n\n// require y > 0\n\
    template <typename T>\npair<T, T> divmod(T x, T y) {\n  T q = x / y, r = x % y;\n\
    \  if (r < 0) --q, r += y;\n  return {q, r};\n}\n\nconstexpr auto TEN = [] {\n\
    \  array<u64, 20> A{};\n  A[0] = 1;\n  for (int i = 1; i < 20; ++i) A[i] = 10\
    \ * A[i - 1];\n  return A;\n}();\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll\
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (1)\
    \ {\n    ll x = midpoint(ok, ng);\n    if (x == ok || x == ng) break;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = midpoint(ok, ng);\n    (check(x) ? ok : ng) = x;\n  }\n  return midpoint(ok,\
    \ ng);\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b)\
    \ {\n  T c = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n\
    }\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c =\
    \ min<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n\
    // ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const\
    \ vc<U> &A, int off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n\
    \  vc<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  first.reserve(first.size() + (others.size()\
    \ + ... + 0));\n  (first.insert(first.end(), others.begin(), others.end()), ...);\n\
    }\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr\
    \ i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128\
    \ b) {\n  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return\
    \ abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/first_mod_range_of_linear.test.cpp\"\
    \n\n#line 2 \"mod/min_of_linear_segments.hpp\"\n\n/*\nax + b (x>=0) \u304C\u6700\
    \u5C0F\u3068\u306A\u308B\u3068\u3053\u308D\u306E\u60C5\u5831\u3092\u8FD4\u3059\
    \u3002\nprefix min \u3092\u66F4\u65B0\u3059\u308B x \u5168\u4F53\u304C\u3001\u7B49\
    \u5DEE\u6570\u5217\u306E\u548C\u96C6\u5408\u3002\u6B21\u3092\u8FD4\u3059\u3002\
    \n\u30FB\u7B49\u5DEE\u6570\u5217\u306E\u5883\u754C\u3068\u306A\u308B x_0, x_1,\
    \ ..., x_n\n\u30FB\u5404\u5883\u754C\u306E\u9593\u3067\u306E\u4EA4\u5DEE dx_0,\
    \ ..., dx_{n-1}\n*/\npair<vc<int>, vc<int>> min_of_linear_segments(int a, int\
    \ b, int mod) {\n  assert(0 <= a && a < mod);\n  assert(0 <= b && b < mod);\n\
    \  vc<int> X = {0};\n  vc<int> DX;\n  int g = gcd(a, mod);\n  a /= g, b /= g,\
    \ mod /= g;\n  // p/q <= (mod-a)/mod <= r/s\n  int p = 0, q = 1, r = 1, s = 1;\n\
    \  int det_l = mod - a, det_r = a;\n  int x = 0, y = b;\n\n  while (y) {\n   \
    \ // upd r/s\n    int k = det_r / det_l;\n    det_r %= det_l;\n    if (det_r ==\
    \ 0) {\n      --k;\n      det_r = det_l;\n    }\n    r += k * p;\n    s += k *\
    \ q;\n    while (1) {\n      int k = max(0, ceil(det_l - y, det_r));\n      if\
    \ (det_l - k * det_r <= 0) break;\n      det_l -= k * det_r;\n      p += k * r;\n\
    \      q += k * s;\n      // p/q <= a/mod\n      // (aq - pmod) = det_l \u3092\
    \ y \u304B\u3089\u5F15\u304F\n      k = y / det_l;\n      y -= k * det_l;\n  \
    \    x += q * k;\n      X.eb(x);\n      DX.eb(q);\n    }\n    k = det_l / det_r;\n\
    \    det_l -= k * det_r;\n    p += k * r;\n    q += k * s;\n    assert(min({p,\
    \ q, r, s}) >= 0);\n  }\n  return {X, DX};\n}\n#line 2 \"mod/first_mod_range_of_linear.hpp\"\
    \n\n// ax+b in {L, ..., R-1} mod \u3068\u306A\u308B\u6700\u5C0F\u306E x>=0 \u3092\
    \u8FD4\u3059\n// \u4F8B\u3048\u3070 ax+b=1 \u306A\u3089 ax+b in {-1} mod 2 \u306E\
    \u3088\u3046\u306B\u3059\u308B\n// \u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    \ -1\n// L<0 \u3084 mod<=R \u3082 ok\nint first_mod_range_of_linear(ll L, ll R,\
    \ ll a, ll b, int mod) {\n  assert(L <= R);\n  b -= L, R -= L;\n  if (R >= mod)\
    \ return 0;\n  a = bmod<ll>(a, mod), b = bmod<ll>(b, mod);\n  // ax+b<R\n  if\
    \ (b < R) return 0;\n  auto [X, DX] = min_of_linear_segments(a, b, mod);\n  FOR(i,\
    \ len(DX)) {\n    ll x1 = X[i], x2 = X[i + 1];\n    ll y2 = (a * x2 + b) % mod;\n\
    \    if (y2 >= R) continue;\n    ll y1 = (a * x1 + b) % mod;\n    ll d = (y1 -\
    \ y2) * DX[i] / (x2 - x1);\n    ll k = floor(y1 - R, d) + 1;\n    return x1 +\
    \ k * DX[i];\n  }\n  return -1;\n}\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 6 \"test/1_mytest/first_mod_range_of_linear.test.cpp\"\
    \n\nll naive(ll L, ll R, ll a, ll b, ll mod) {\n  FOR(x, mod) {\n    FOR(y, L,\
    \ R) {\n      if (((a * x + b) - y) % mod == 0) return x;\n    }\n  }\n  return\
    \ -1;\n}\n\nvoid test() {\n  ll K = 15;\n  FOR(L, -K, K) {\n    FOR(R, L, K) {\n\
    \      FOR(mod, 1, K) {\n        FOR(a, -K, K) {\n          FOR(b, -K, K) {\n\
    \            ll X = naive(L, R, a, b, mod);\n            ll Y = first_mod_range_of_linear(L,\
    \ R, a, b, mod);\n            assert(X == Y);\n          }\n        }\n      }\n\
    \    }\n  }\n\n  K = 10000;\n  FOR(100) {\n    ll L = RNG(-K, K);\n    ll R =\
    \ RNG(-K, K);\n    if (L > R) swap(L, R);\n    ll mod = RNG(1, K);\n    ll a =\
    \ RNG(-K, K);\n    ll b = RNG(-K, K);\n    ll X = naive(L, R, a, b, mod);\n  \
    \  ll Y = first_mod_range_of_linear(L, R, a, b, mod);\n    assert(X == Y);\n \
    \ }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\
    \\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"mod/first_mod_range_of_linear.hpp\"\n#include \"random/base.hpp\"\
    \n\nll naive(ll L, ll R, ll a, ll b, ll mod) {\n  FOR(x, mod) {\n    FOR(y, L,\
    \ R) {\n      if (((a * x + b) - y) % mod == 0) return x;\n    }\n  }\n  return\
    \ -1;\n}\n\nvoid test() {\n  ll K = 15;\n  FOR(L, -K, K) {\n    FOR(R, L, K) {\n\
    \      FOR(mod, 1, K) {\n        FOR(a, -K, K) {\n          FOR(b, -K, K) {\n\
    \            ll X = naive(L, R, a, b, mod);\n            ll Y = first_mod_range_of_linear(L,\
    \ R, a, b, mod);\n            assert(X == Y);\n          }\n        }\n      }\n\
    \    }\n  }\n\n  K = 10000;\n  FOR(100) {\n    ll L = RNG(-K, K);\n    ll R =\
    \ RNG(-K, K);\n    if (L > R) swap(L, R);\n    ll mod = RNG(1, K);\n    ll a =\
    \ RNG(-K, K);\n    ll b = RNG(-K, K);\n    ll X = naive(L, R, a, b, mod);\n  \
    \  ll Y = first_mod_range_of_linear(L, R, a, b, mod);\n    assert(X == Y);\n \
    \ }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\
    \\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - mod/first_mod_range_of_linear.hpp
  - mod/min_of_linear_segments.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/first_mod_range_of_linear.test.cpp
  requiredBy: []
  timestamp: '2026-08-10 06:35:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/first_mod_range_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/first_mod_range_of_linear.test.cpp
- /verify/test/1_mytest/first_mod_range_of_linear.test.cpp.html
title: test/1_mytest/first_mod_range_of_linear.test.cpp
---
