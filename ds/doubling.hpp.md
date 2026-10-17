---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
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
    links:
    - https://github.com/maspypy/library/blob/main/ds/doubling.hpp
  bundledCode: "#line 1 \"ds/doubling.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/doubling.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/doubling.hpp\"\n\n// \u72B6\u614B a \u304B\u3089 1 \u56DE\u64CD\
    \u4F5C\u3059\u308B\u3068\u3001\u72B6\u614B b \u306B\u9077\u79FB\u3057\u3001\u30E2\
    \u30CE\u30A4\u30C9\u306E\u5143 x \u3092\u52A0\u3048\u308B\u3002\n// \u884C\u304D\
    \u5148\u304C\u306A\u3044\u5834\u5408\uFF1A-1 \uFF08add \u4E0D\u8981\uFF09\ntemplate\
    \ <typename Monoid, int LOG>\nstruct Doubling {\n  using X = typename Monoid::value_type;\n\
    \  int N;\n  bool is_prepared;\n  vvc<int> TO;\n  vvc<X> DP;\n\n  Doubling(int\
    \ N) : N(N), is_prepared(0) {\n    TO.assign(LOG, vc<int>(N, -1));\n    DP.assign(LOG,\
    \ vc<X>(N, Monoid::id()));\n  }\n\n  void add(int i, int to, X x) {\n    assert(!is_prepared);\n\
    \    assert(-1 <= to && to < N);\n    TO[0][i] = to;\n    DP[0][i] = x;\n  }\n\
    \n  void build() {\n    assert(!is_prepared);\n    is_prepared = 1;\n    FOR(k,\
    \ LOG - 1) {\n      FOR(v, N) {\n        int w = TO[k][v];\n        if (w == -1)\
    \ {\n          TO[k + 1][v] = -1;\n          DP[k + 1][v] = DP[k][v];\n      \
    \    continue;\n        }\n        TO[k + 1][v] = TO[k][w];\n        DP[k + 1][v]\
    \ = Monoid::op(DP[k][v], DP[k][w]);\n      }\n    }\n  }\n\n  // (to, val)\n \
    \ pair<int, X> calc(int i, ll step) {\n    assert(is_prepared);\n    assert(0\
    \ <= step && step < (1LL << LOG));\n    X x = Monoid::id();\n    while (step &&\
    \ i != -1) {\n      int k = topbit(step);\n      step ^= 1LL << k;\n      x =\
    \ Monoid::op(x, DP[k][i]);\n      i = TO[k][i];\n    }\n    return {i, x};\n \
    \ }\n\n  // check(to, monoid_sum)\n  template <typename F>\n  ll max_step(F check,\
    \ int i) {\n    assert(is_prepared);\n    X x = Monoid::id();\n    ll step = 0;\n\
    \    assert(check(i, x));\n    FOR_R(k, LOG) {\n      int j = TO[k][i];\n    \
    \  if (j == -1) continue;\n      X y = Monoid::op(x, DP[k][i]);\n      if (check(j,\
    \ y)) {\n        step |= 1LL << k;\n        i = j;\n        x = y;\n        assert(i\
    \ != -1);\n      }\n    }\n    return step;\n  }\n\n  void debug() {\n    print(\"\
    TO\");\n    FOR(k, LOG) print(TO[k]);\n    print(\"DP\");\n    FOR(k, LOG) print(DP[k]);\n\
    \  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/doubling.hpp\n\
    #include \"alg/monoid/add.hpp\"\n\n// \u72B6\u614B a \u304B\u3089 1 \u56DE\u64CD\
    \u4F5C\u3059\u308B\u3068\u3001\u72B6\u614B b \u306B\u9077\u79FB\u3057\u3001\u30E2\
    \u30CE\u30A4\u30C9\u306E\u5143 x \u3092\u52A0\u3048\u308B\u3002\n// \u884C\u304D\
    \u5148\u304C\u306A\u3044\u5834\u5408\uFF1A-1 \uFF08add \u4E0D\u8981\uFF09\ntemplate\
    \ <typename Monoid, int LOG>\nstruct Doubling {\n  using X = typename Monoid::value_type;\n\
    \  int N;\n  bool is_prepared;\n  vvc<int> TO;\n  vvc<X> DP;\n\n  Doubling(int\
    \ N) : N(N), is_prepared(0) {\n    TO.assign(LOG, vc<int>(N, -1));\n    DP.assign(LOG,\
    \ vc<X>(N, Monoid::id()));\n  }\n\n  void add(int i, int to, X x) {\n    assert(!is_prepared);\n\
    \    assert(-1 <= to && to < N);\n    TO[0][i] = to;\n    DP[0][i] = x;\n  }\n\
    \n  void build() {\n    assert(!is_prepared);\n    is_prepared = 1;\n    FOR(k,\
    \ LOG - 1) {\n      FOR(v, N) {\n        int w = TO[k][v];\n        if (w == -1)\
    \ {\n          TO[k + 1][v] = -1;\n          DP[k + 1][v] = DP[k][v];\n      \
    \    continue;\n        }\n        TO[k + 1][v] = TO[k][w];\n        DP[k + 1][v]\
    \ = Monoid::op(DP[k][v], DP[k][w]);\n      }\n    }\n  }\n\n  // (to, val)\n \
    \ pair<int, X> calc(int i, ll step) {\n    assert(is_prepared);\n    assert(0\
    \ <= step && step < (1LL << LOG));\n    X x = Monoid::id();\n    while (step &&\
    \ i != -1) {\n      int k = topbit(step);\n      step ^= 1LL << k;\n      x =\
    \ Monoid::op(x, DP[k][i]);\n      i = TO[k][i];\n    }\n    return {i, x};\n \
    \ }\n\n  // check(to, monoid_sum)\n  template <typename F>\n  ll max_step(F check,\
    \ int i) {\n    assert(is_prepared);\n    X x = Monoid::id();\n    ll step = 0;\n\
    \    assert(check(i, x));\n    FOR_R(k, LOG) {\n      int j = TO[k][i];\n    \
    \  if (j == -1) continue;\n      X y = Monoid::op(x, DP[k][i]);\n      if (check(j,\
    \ y)) {\n        step |= 1LL << k;\n        i = j;\n        x = y;\n        assert(i\
    \ != -1);\n      }\n    }\n    return step;\n  }\n\n  void debug() {\n    print(\"\
    TO\");\n    FOR(k, LOG) print(TO[k]);\n    print(\"DP\");\n    FOR(k, LOG) print(DP[k]);\n\
    \  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/doubling.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1977.test.cpp
  - test/3_yukicoder/1097.test.cpp
  - test/3_yukicoder/2242.test.cpp
documentation_of: ds/doubling.hpp
layout: document
redirect_from:
- /library/ds/doubling.hpp
- /library/ds/doubling.hpp.html
title: ds/doubling.hpp
---
