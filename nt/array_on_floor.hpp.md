---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/array_on_floor.hpp\"\n// N=10 \u3060\u3068 dat = {dp[1],\
    \ dp[2], dp[3], dp[5], dp[10]} \u307F\u305F\u3044\u306B\u306A\u308B\n// hashmap\
    \ \u3088\u308A\u6570\u500D\u9AD8\u901F\ntemplate <typename T>\nstruct Array_On_Floor\
    \ {\n  ll N;\n  int n, sq;\n  vc<T> dat;\n  Array_On_Floor(ll N, T default_value\
    \ = T{}) : N(N) {\n    assert(N <= (1LL << 50));\n    sq = sqrtl(N);\n    n =\
    \ (ll(sq) * sq + sq <= N ? sq : sq - 1);\n    dat.resize(n + sq, default_value);\n\
    \  }\n\n  T& operator[](ll d) {\n    int i = get_index(d);\n    return dat[i];\n\
    \  }\n\n  inline int get_index(ll d) {\n    assert(d > 0);\n    if (d <= n) return\
    \ d - 1;\n    return len(dat) - int(double(N) / d);\n  }\n\n  // dat[i] \u306B\
    \u5BFE\u5FDC\u3059\u308B floor\n  ll get_floor(int i) { return (i < n ? 1 + i\
    \ : double(N) / (n + sq - i)); }\n\n  template <typename F>\n  void enumerate_all(F\
    \ f) {\n    FOR(i, len(dat)) { f(get_floor(i), dat[i]); }\n  }\n};\n"
  code: "// N=10 \u3060\u3068 dat = {dp[1], dp[2], dp[3], dp[5], dp[10]} \u307F\u305F\
    \u3044\u306B\u306A\u308B\n// hashmap \u3088\u308A\u6570\u500D\u9AD8\u901F\ntemplate\
    \ <typename T>\nstruct Array_On_Floor {\n  ll N;\n  int n, sq;\n  vc<T> dat;\n\
    \  Array_On_Floor(ll N, T default_value = T{}) : N(N) {\n    assert(N <= (1LL\
    \ << 50));\n    sq = sqrtl(N);\n    n = (ll(sq) * sq + sq <= N ? sq : sq - 1);\n\
    \    dat.resize(n + sq, default_value);\n  }\n\n  T& operator[](ll d) {\n    int\
    \ i = get_index(d);\n    return dat[i];\n  }\n\n  inline int get_index(ll d) {\n\
    \    assert(d > 0);\n    if (d <= n) return d - 1;\n    return len(dat) - int(double(N)\
    \ / d);\n  }\n\n  // dat[i] \u306B\u5BFE\u5FDC\u3059\u308B floor\n  ll get_floor(int\
    \ i) { return (i < n ? 1 + i : double(N) / (n + sq - i)); }\n\n  template <typename\
    \ F>\n  void enumerate_all(F f) {\n    FOR(i, len(dat)) { f(get_floor(i), dat[i]);\
    \ }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: nt/array_on_floor.hpp
  requiredBy: []
  timestamp: '2023-10-14 01:49:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/array_on_floor.hpp
layout: document
redirect_from:
- /library/nt/array_on_floor.hpp
- /library/nt/array_on_floor.hpp.html
title: nt/array_on_floor.hpp
---
