---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: nt/convex_floor_sum.hpp
    title: nt/convex_floor_sum.hpp
  - icon: ':x:'
    path: nt/sigma_0_sum.hpp
    title: nt/sigma_0_sum.hpp
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
    - https://oeis.org/A057494
  bundledCode: "#line 1 \"test/1_mytest/sigma_0_sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr\
    \ T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
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
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
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
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    UINT operator*() const { return s ^ t; }\n    iter &operator++() {\n    \
    \  (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool\
    \ operator!=(const iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  iter begin() const { return iter(s); }\n  iter end() const {\
    \ return iter(0); }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return\
    \ a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y)\
    \ {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y)\
    \ {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nconstexpr ll\
    \ TEN[] = {\n    1LL,\n    10LL,\n    100LL,\n    1000LL,\n    10000LL,\n    100000LL,\n\
    \    1000000LL,\n    10000000LL,\n    100000000LL,\n    1000000000LL,\n    10000000000LL,\n\
    \    100000000000LL,\n    1000000000000LL,\n    10000000000000LL,\n    100000000000000LL,\n\
    \    1000000000000000LL,\n    10000000000000000LL,\n    100000000000000000LL,\n\
    \    1000000000000000000LL,\n};\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ ll(distance((c).begin(), lower_bound(all(c), (x))))\n#define UB(c, x) ll(distance((c).begin(),\
    \ upper_bound(all(c), (x))))\n#define UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <class T,\
    \ class Container, class Compare>\nT POP(priority_queue<T, Container, Compare>\
    \ &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n\
    }\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok\
    \ = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok - ng) > 1)\
    \ {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check, double ok,\
    \ double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n\
    \    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class\
    \ T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b,\
    \ 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n\
    \  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i] == A[j] ? i <\
    \ j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n\
    \  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\ntemplate <typename T, typename...\
    \ Vectors>\nvoid concat(vc<T> &first, const Vectors &...others) {\n  vc<T> &res\
    \ = first;\n  (res.insert(res.end(), others.begin(), others.end()), ...);\n}\n\
    #endif\n#line 3 \"test/1_mytest/sigma_0_sum.test.cpp\"\n\n#line 1 \"nt/convex_floor_sum.hpp\"\
    \n\n// f: \u51F8, \u975E\u8CA0, \u5358\u8ABF\u5897\u52A0\u3092\u4EEE\u5B9A\n//\
    \ above(x,y) : y > f(x)\n// slope(x,a,b) : f'(x) >= a/b\n// return : sum_[0,N)\
    \ floor(f(x))\n// https://qoj.ac/contest/1195/problem/6188\ntemplate <typename\
    \ U, typename ANS_TYPE, typename F1, typename F2>\nANS_TYPE convex_floor_sum(U\
    \ N, F1 above, F2 slope) {\n  if (N == 0) return 0;\n  auto check = [&](U x, U\
    \ y) -> bool { return x < N && above(x, y); };\n\n  using T = ANS_TYPE;\n  auto\
    \ max_add = [&](auto f, U& a, U& b, U c, U d) -> void {\n    auto dfs = [&](auto&\
    \ dfs, U c, U d) -> void {\n      if (!f(a + c, b + d)) return;\n      a += c,\
    \ b += d, dfs(dfs, c + c, d + d);\n      if (f(a + c, b + d)) a += c, b += d;\n\
    \    };\n    dfs(dfs, c, d);\n  };\n\n  assert(!above(0, 0));\n  U x = 0, y =\
    \ 0;\n  max_add([&](U x, U y) -> bool { return !above(x, y); }, x, y, 0, 1);\n\
    \  ++y;\n  T ANS = 2 * (y - 1); //  [0,1) x [1,y)\n\n  auto add_ANS = [&](U& x,\
    \ U& y, U a, U b) -> void {\n    U x0 = x, y0 = y;\n    max_add(check, x, y, a,\
    \ b);\n    U n = (x - x0) / a;\n    //  (x0,y0) to (x,y)\n    ANS += 2 * (y0 -\
    \ 1) * (x - x0);\n    ANS += (x - x0 + 1) * (y - y0 + 1) - (n + 1);\n  };\n\n\
    \  add_ANS(x, y, 1, 0);\n  vc<tuple<U, U, U, U>> SBT;\n  SBT.eb(1, 0, 0, 1);\n\
    \  while (x < N - 1) {\n    U a, b, c, d;\n    tie(a, b, c, d) = SBT.back();\n\
    \    if (!check(x + c, y + d)) {\n      POP(SBT);\n      continue;\n    }\n  \
    \  auto f = [&](u64 a, u64 b) -> bool {\n      if (x + a >= N) return 0;\n   \
    \   if (above(x + a, y + b)) return 0;\n      if (slope(x + a, d, c)) return 0;\n\
    \      return 1;\n    };\n    max_add(f, a, b, c, d);\n    if (check(x + a + c,\
    \ y + b + d)) {\n      max_add([&](U a, U b) -> bool { return check(x + a, y +\
    \ b); }, c, d, a, b);\n      SBT.eb(a, b, c, d);\n      continue;\n    }\n   \
    \ add_ANS(x, y, c, d);\n  }\n  ANS /= T(2);\n  return ANS;\n}\n#line 2 \"nt/sigma_0_sum.hpp\"\
    \n\n// sum_[1,N] sigma_0(n)\ntemplate <typename T = u64>\nT sigma_0_sum_small(u64\
    \ N) {\n  u32 sq = sqrtl(N);\n  T ANS = 0;\n  for (u32 d = 1; d <= sq; ++d) {\
    \ ANS += N / d; }\n  return 2 * ANS - u64(sq) * sq;\n}\n\n// https://oeis.org/A006218\n\
    // sigma0(1)+...+sigma0(N) = sum floor(N/i)\ntemplate <typename T = u64>\nT sigma_0_sum_large(u64\
    \ N) {\n  u32 sq = sqrtl(N);\n  auto above = [&](u128 x, u128 y) -> bool { return\
    \ y * (sq - x) > N; };\n  auto slope = [&](u128 x, u128 a, u128 b) -> bool {\n\
    \    x = sq - x;\n    return a * x * x <= N * b;\n  };\n  T ANS = convex_floor_sum<u64,\
    \ T>(sq, above, slope);\n  return 2 * ANS - u64(sq) * sq;\n}\n\ntemplate <typename\
    \ T = u64>\nT sigma_0_sum(u64 N) {\n  return (N < (1e14) ? sigma_0_sum_small<T>(N)\
    \ : sigma_0_sum_large<T>(N));\n}\n#line 5 \"test/1_mytest/sigma_0_sum.test.cpp\"\
    \n\nvoid test() {\n  FOR(N, 1, 10000) {\n    u64 ans = 0;\n    FOR(x, 1, N + 1)\
    \ ans += N / x;\n    assert(ans == sigma_0_sum_small(N));\n    assert(ans == sigma_0_sum_large(N));\n\
    \  }\n  u64 N = 1'000'000'000'000'000;\n  u64 ANS = 34'693'207'724'724'246; //\
    \ https://oeis.org/A057494\n  u64 a = sigma_0_sum_small(N);\n  u64 b = sigma_0_sum_small(N);\n\
    \  assert(a == ANS && b == ANS);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a\
    \ >> b;\n  cout << a + b << \"\\n\";\n}\n\nint main() {\n  test();\n  solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"nt/sigma_0_sum.hpp\"\n\nvoid test() {\n  FOR(N, 1, 10000) {\n \
    \   u64 ans = 0;\n    FOR(x, 1, N + 1) ans += N / x;\n    assert(ans == sigma_0_sum_small(N));\n\
    \    assert(ans == sigma_0_sum_large(N));\n  }\n  u64 N = 1'000'000'000'000'000;\n\
    \  u64 ANS = 34'693'207'724'724'246; // https://oeis.org/A057494\n  u64 a = sigma_0_sum_small(N);\n\
    \  u64 b = sigma_0_sum_small(N);\n  assert(a == ANS && b == ANS);\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nint main()\
    \ {\n  test();\n  solve();\n}\n"
  dependsOn:
  - my_template.hpp
  - nt/sigma_0_sum.hpp
  - nt/convex_floor_sum.hpp
  isVerificationFile: true
  path: test/1_mytest/sigma_0_sum.test.cpp
  requiredBy: []
  timestamp: '2025-09-03 05:45:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/sigma_0_sum.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/sigma_0_sum.test.cpp
- /verify/test/1_mytest/sigma_0_sum.test.cpp.html
title: test/1_mytest/sigma_0_sum.test.cpp
---
