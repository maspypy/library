---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/rational_approximation.test.cpp
    title: test/2_library_checker/number_theory/rational_approximation.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc333g.test.cpp
    title: test/5_atcoder/abc333g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/rational_binary_search.hpp\"\n\n// 0/1 OK, 1/0 NG. 3N\
    \ \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044. unsigned\
    \ OK.\n// return : (a,b,c,d) such that a/b OK, c/d NG.\ntemplate <typename T,\
    \ typename F>\ntuple<T, T, T, T> rational_binary_search(F check, T N) {\n  assert(check(0,\
    \ 1) && !check(1, 0));\n  auto dfs = [&](auto& dfs, bool side, T& a, T& b, T c,\
    \ T d) -> void {\n    if (a + c > N || b + d > N) return;\n    if (check(a + c,\
    \ b + d) == side) {\n      a += c, b += d;\n      dfs(dfs, side, a, b, c + c,\
    \ d + d);\n    }\n    if (a + c <= N && b + d <= N && check(a + c, b + d) == side)\
    \ a += c, b += d;\n  };\n\n  T a = 0, b = 1, c = 1, d = 0;\n  while (a + c <=\
    \ N && b + d <= N) { dfs(dfs, true, a, b, c, d), dfs(dfs, false, c, d, a, b);\
    \ }\n  return {a, b, c, d};\n}\n"
  code: "\n// 0/1 OK, 1/0 NG. 3N \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\
    \u306A\u3044. unsigned OK.\n// return : (a,b,c,d) such that a/b OK, c/d NG.\n\
    template <typename T, typename F>\ntuple<T, T, T, T> rational_binary_search(F\
    \ check, T N) {\n  assert(check(0, 1) && !check(1, 0));\n  auto dfs = [&](auto&\
    \ dfs, bool side, T& a, T& b, T c, T d) -> void {\n    if (a + c > N || b + d\
    \ > N) return;\n    if (check(a + c, b + d) == side) {\n      a += c, b += d;\n\
    \      dfs(dfs, side, a, b, c + c, d + d);\n    }\n    if (a + c <= N && b + d\
    \ <= N && check(a + c, b + d) == side) a += c, b += d;\n  };\n\n  T a = 0, b =\
    \ 1, c = 1, d = 0;\n  while (a + c <= N && b + d <= N) { dfs(dfs, true, a, b,\
    \ c, d), dfs(dfs, false, c, d, a, b); }\n  return {a, b, c, d};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/rational_binary_search.hpp
  requiredBy: []
  timestamp: '2024-08-27 20:48:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/number_theory/rational_approximation.test.cpp
  - test/5_atcoder/abc333g.test.cpp
documentation_of: nt/rational_binary_search.hpp
layout: document
redirect_from:
- /library/nt/rational_binary_search.hpp
- /library/nt/rational_binary_search.hpp.html
title: nt/rational_binary_search.hpp
---
