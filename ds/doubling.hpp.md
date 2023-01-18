---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1097.test.cpp
    title: test/yukicoder/1097.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1977.test.cpp
    title: test/yukicoder/1977.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/doubling.hpp\"\
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
    \ DP[k][w]);\r\n      }\r\n    }\r\n  }\r\n\r\n  pair<int, X> calc(int i, ll step)\
    \ {\r\n    assert(is_prepared);\r\n    assert(step < (1LL << LOG));\r\n    X x\
    \ = Monoid::unit();\r\n    FOR(k, LOG) {\r\n      if (i == -1) break;\r\n    \
    \  if (step & 1LL << k) {\r\n        x = Monoid::op(x, DP[k][i]);\r\n        i\
    \ = TO[k][i];\r\n      }\r\n    }\r\n    return {i, x};\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  ll max_step(F check, int i) {\r\n    assert(is_prepared);\r\
    \n    X x = Monoid::unit();\r\n    ll step = 0;\r\n    assert(check(x));\r\n \
    \   FOR_R(k, LOG) {\r\n      int j = TO[k][i];\r\n      X y = Monoid::op(x, DP[k][i]);\r\
    \n      if (check(y)) {\r\n        step |= 1LL << k;\r\n        i = j;\r\n   \
    \     x = y;\r\n        assert(i != -1);\r\n      }\r\n    }\r\n    return step;\r\
    \n  }\r\n\r\n  void debug() {\r\n    print(\"TO\");\r\n    FOR(k, LOG) print(TO[k]);\r\
    \n    print(\"DP\");\r\n    FOR(k, LOG) print(DP[k]);\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n\r\n// \u72B6\u614B a \u304B\u3089 1 \u56DE\
    \u64CD\u4F5C\u3059\u308B\u3068\u3001\u72B6\u614B b \u306B\u9077\u79FB\u3057\u3001\
    \u30E2\u30CE\u30A4\u30C9\u306E\u5143 x \u3092\u52A0\u3048\u308B\u3002\r\n// \u884C\
    \u304D\u5148\u304C\u306A\u3044\u5834\u5408\uFF1A-1 \uFF08add \u4E0D\u8981\uFF09\
    \r\ntemplate <typename Monoid, int LOG>\r\nstruct Doubling {\r\n  using X = typename\
    \ Monoid::value_type;\r\n  int N;\r\n  bool is_prepared;\r\n  vvc<int> TO;\r\n\
    \  vvc<X> DP;\r\n\r\n  Doubling(int N) : N(N), is_prepared(0) {\r\n    TO.assign(LOG,\
    \ vc<int>(N, -1));\r\n    DP.assign(LOG, vc<X>(N, Monoid::unit()));\r\n  }\r\n\
    \r\n  void add(int i, int to, X x) {\r\n    assert(!is_prepared);\r\n    assert(-1\
    \ <= to && to < N);\r\n    TO[0][i] = to;\r\n    DP[0][i] = x;\r\n  }\r\n\r\n\
    \  void build() {\r\n    assert(!is_prepared);\r\n    is_prepared = 1;\r\n   \
    \ FOR(k, LOG - 1) {\r\n      FOR(v, N) {\r\n        int w = TO[k][v];\r\n    \
    \    if (w == -1) {\r\n          TO[k + 1][v] = -1;\r\n          DP[k + 1][v]\
    \ = DP[k][v];\r\n          continue;\r\n        }\r\n        TO[k + 1][v] = TO[k][w];\r\
    \n        DP[k + 1][v] = Monoid::op(DP[k][v], DP[k][w]);\r\n      }\r\n    }\r\
    \n  }\r\n\r\n  pair<int, X> calc(int i, ll step) {\r\n    assert(is_prepared);\r\
    \n    assert(step < (1LL << LOG));\r\n    X x = Monoid::unit();\r\n    FOR(k,\
    \ LOG) {\r\n      if (i == -1) break;\r\n      if (step & 1LL << k) {\r\n    \
    \    x = Monoid::op(x, DP[k][i]);\r\n        i = TO[k][i];\r\n      }\r\n    }\r\
    \n    return {i, x};\r\n  }\r\n\r\n  template <typename F>\r\n  ll max_step(F\
    \ check, int i) {\r\n    assert(is_prepared);\r\n    X x = Monoid::unit();\r\n\
    \    ll step = 0;\r\n    assert(check(x));\r\n    FOR_R(k, LOG) {\r\n      int\
    \ j = TO[k][i];\r\n      X y = Monoid::op(x, DP[k][i]);\r\n      if (check(y))\
    \ {\r\n        step |= 1LL << k;\r\n        i = j;\r\n        x = y;\r\n     \
    \   assert(i != -1);\r\n      }\r\n    }\r\n    return step;\r\n  }\r\n\r\n  void\
    \ debug() {\r\n    print(\"TO\");\r\n    FOR(k, LOG) print(TO[k]);\r\n    print(\"\
    DP\");\r\n    FOR(k, LOG) print(DP[k]);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/doubling.hpp
  requiredBy: []
  timestamp: '2023-01-02 17:13:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1977.test.cpp
  - test/yukicoder/1097.test.cpp
documentation_of: ds/doubling.hpp
layout: document
redirect_from:
- /library/ds/doubling.hpp
- /library/ds/doubling.hpp.html
title: ds/doubling.hpp
---
