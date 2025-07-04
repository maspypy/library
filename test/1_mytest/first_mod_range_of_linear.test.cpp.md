---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/first_mod_range_of_linear.hpp
    title: mod/first_mod_range_of_linear.hpp
  - icon: ':heavy_check_mark:'
    path: mod/min_of_linear_segments.hpp
    title: mod/min_of_linear_segments.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/first_mod_range_of_linear.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\"\
    )\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq_max = priority_queue<T>;\ntemplate <class T>\nusing pq_min = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\
    \n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq_min<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pq_max<T> &que) {\n\
    \  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
    \ &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate\
    \ <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true)\
    \ {\n  if (check_ok) assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate\
    \ <typename F>\ndouble binary_search_real(F check, double ok, double ng, int iter\
    \ = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok :\
    \ ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline\
    \ bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char)\
    \ {\n  vc<int> A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] -\
    \ first_char : -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T>\
    \ cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N +\
    \ 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n\
    \  return B;\n}\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/first_mod_range_of_linear.test.cpp\"\
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
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/first_mod_range_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/first_mod_range_of_linear.test.cpp
- /verify/test/1_mytest/first_mod_range_of_linear.test.cpp.html
title: test/1_mytest/first_mod_range_of_linear.test.cpp
---
