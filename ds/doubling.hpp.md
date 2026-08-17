---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1097.test.cpp
    title: test/3_yukicoder/1097.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1977.test.cpp
    title: test/3_yukicoder/1977.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2242.test.cpp
    title: test/3_yukicoder/2242.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\n\
    struct Monoid_Add {\n  using X = E;\n  using value_type = X;\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\n  static constexpr X unit() { return\
    \ X(0); }\n  static constexpr bool commute = true;\n};\n#line 3 \"ds/doubling.hpp\"\
    \n\r\n// \u72B6\u614B a \u304B\u3089 1 \u56DE\u64CD\u4F5C\u3059\u308B\u3068\u3001\
    \u72B6\u614B b \u306B\u9077\u79FB\u3057\u3001\u30E2\u30CE\u30A4\u30C9\u306E\u5143\
    \ x \u3092\u52A0\u3048\u308B\u3002\r\n// \u884C\u304D\u5148\u304C\u306A\u3044\u5834\
    \u5408\uFF1A-1 \uFF08add \u4E0D\u8981\uFF09\r\ntemplate <typename Monoid, int\
    \ LOG>\r\nstruct Doubling {\r\n  using X = typename Monoid::value_type;\r\n  int\
    \ N;\r\n  bool is_prepared;\r\n  vvc<int> TO;\r\n  vvc<X> DP;\r\n\r\n  Doubling(int\
    \ N) : N(N), is_prepared(0) {\r\n    TO.assign(LOG, vc<int>(N, -1));\r\n    DP.assign(LOG,\
    \ vc<X>(N, Monoid::unit()));\r\n  }\r\n\r\n  void add(int i, int to, X x) {\r\n\
    \    assert(!is_prepared);\r\n    assert(-1 <= to && to < N);\r\n    TO[0][i]\
    \ = to;\r\n    DP[0][i] = x;\r\n  }\r\n\r\n  void build() {\r\n    assert(!is_prepared);\r\
    \n    is_prepared = 1;\r\n    FOR(k, LOG - 1) {\r\n      FOR(v, N) {\r\n     \
    \   int w = TO[k][v];\r\n        if (w == -1) {\r\n          TO[k + 1][v] = -1;\r\
    \n          DP[k + 1][v] = DP[k][v];\r\n          continue;\r\n        }\r\n \
    \       TO[k + 1][v] = TO[k][w];\r\n        DP[k + 1][v] = Monoid::op(DP[k][v],\
    \ DP[k][w]);\r\n      }\r\n    }\r\n  }\r\n\r\n  // (to, val)\r\n  pair<int, X>\
    \ calc(int i, ll step) {\r\n    assert(is_prepared);\r\n    assert(0 <= step &&\
    \ step < (1LL << LOG));\r\n    X x = Monoid::unit();\r\n    while (step && i !=\
    \ -1) {\r\n      int k = topbit(step);\r\n      step ^= 1LL << k;\r\n      x =\
    \ Monoid::op(x, DP[k][i]);\r\n      i = TO[k][i];\r\n    }\r\n    return {i, x};\r\
    \n  }\r\n\r\n  // check(to, monoid_sum)\r\n  template <typename F>\r\n  ll max_step(F\
    \ check, int i) {\r\n    assert(is_prepared);\r\n    X x = Monoid::unit();\r\n\
    \    ll step = 0;\r\n    assert(check(i, x));\r\n    FOR_R(k, LOG) {\r\n     \
    \ int j = TO[k][i];\r\n      if (j == -1) continue;\r\n      X y = Monoid::op(x,\
    \ DP[k][i]);\r\n      if (check(j, y)) {\r\n        step |= 1LL << k;\r\n    \
    \    i = j;\r\n        x = y;\r\n        assert(i != -1);\r\n      }\r\n    }\r\
    \n    return step;\r\n  }\r\n\r\n  void debug() {\r\n    print(\"TO\");\r\n  \
    \  FOR(k, LOG) print(TO[k]);\r\n    print(\"DP\");\r\n    FOR(k, LOG) print(DP[k]);\r\
    \n  }\r\n};\r\n"
  code: "#include \"other/bit.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\n\r\n// \u72B6\
    \u614B a \u304B\u3089 1 \u56DE\u64CD\u4F5C\u3059\u308B\u3068\u3001\u72B6\u614B\
    \ b \u306B\u9077\u79FB\u3057\u3001\u30E2\u30CE\u30A4\u30C9\u306E\u5143 x \u3092\
    \u52A0\u3048\u308B\u3002\r\n// \u884C\u304D\u5148\u304C\u306A\u3044\u5834\u5408\
    \uFF1A-1 \uFF08add \u4E0D\u8981\uFF09\r\ntemplate <typename Monoid, int LOG>\r\
    \nstruct Doubling {\r\n  using X = typename Monoid::value_type;\r\n  int N;\r\n\
    \  bool is_prepared;\r\n  vvc<int> TO;\r\n  vvc<X> DP;\r\n\r\n  Doubling(int N)\
    \ : N(N), is_prepared(0) {\r\n    TO.assign(LOG, vc<int>(N, -1));\r\n    DP.assign(LOG,\
    \ vc<X>(N, Monoid::unit()));\r\n  }\r\n\r\n  void add(int i, int to, X x) {\r\n\
    \    assert(!is_prepared);\r\n    assert(-1 <= to && to < N);\r\n    TO[0][i]\
    \ = to;\r\n    DP[0][i] = x;\r\n  }\r\n\r\n  void build() {\r\n    assert(!is_prepared);\r\
    \n    is_prepared = 1;\r\n    FOR(k, LOG - 1) {\r\n      FOR(v, N) {\r\n     \
    \   int w = TO[k][v];\r\n        if (w == -1) {\r\n          TO[k + 1][v] = -1;\r\
    \n          DP[k + 1][v] = DP[k][v];\r\n          continue;\r\n        }\r\n \
    \       TO[k + 1][v] = TO[k][w];\r\n        DP[k + 1][v] = Monoid::op(DP[k][v],\
    \ DP[k][w]);\r\n      }\r\n    }\r\n  }\r\n\r\n  // (to, val)\r\n  pair<int, X>\
    \ calc(int i, ll step) {\r\n    assert(is_prepared);\r\n    assert(0 <= step &&\
    \ step < (1LL << LOG));\r\n    X x = Monoid::unit();\r\n    while (step && i !=\
    \ -1) {\r\n      int k = topbit(step);\r\n      step ^= 1LL << k;\r\n      x =\
    \ Monoid::op(x, DP[k][i]);\r\n      i = TO[k][i];\r\n    }\r\n    return {i, x};\r\
    \n  }\r\n\r\n  // check(to, monoid_sum)\r\n  template <typename F>\r\n  ll max_step(F\
    \ check, int i) {\r\n    assert(is_prepared);\r\n    X x = Monoid::unit();\r\n\
    \    ll step = 0;\r\n    assert(check(i, x));\r\n    FOR_R(k, LOG) {\r\n     \
    \ int j = TO[k][i];\r\n      if (j == -1) continue;\r\n      X y = Monoid::op(x,\
    \ DP[k][i]);\r\n      if (check(j, y)) {\r\n        step |= 1LL << k;\r\n    \
    \    i = j;\r\n        x = y;\r\n        assert(i != -1);\r\n      }\r\n    }\r\
    \n    return step;\r\n  }\r\n\r\n  void debug() {\r\n    print(\"TO\");\r\n  \
    \  FOR(k, LOG) print(TO[k]);\r\n    print(\"DP\");\r\n    FOR(k, LOG) print(DP[k]);\r\
    \n  }\r\n};\r\n"
  dependsOn:
  - other/bit.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/doubling.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2242.test.cpp
  - test/3_yukicoder/1097.test.cpp
  - test/3_yukicoder/1977.test.cpp
documentation_of: ds/doubling.hpp
layout: document
redirect_from:
- /library/ds/doubling.hpp
- /library/ds/doubling.hpp.html
title: ds/doubling.hpp
---
