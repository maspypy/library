---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/check_monge.test.cpp
    title: test/1_mytest/check_monge.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/monge/check_monge.hpp\"\n\n// check Monge property\
    \ on [0, N]:\n// f(a,d) + f(b,c) >= f(a,c) + f(b,d) for a < b < c < d\ntemplate\
    \ <typename T, typename F>\nbool check_monge(int N, F f) {\n  FOR(d, N + 1) FOR(c,\
    \ d) FOR(b, c) FOR(a, b) {\n    T lhs = f(a, d) + f(b, c);\n    T rhs = f(a, c)\
    \ + f(b, d);\n    if (lhs < rhs) {\n      print(\"monge ng\");\n      print(\"\
    a,b,c,d = \", a, b, c, d);\n      print(\"f(a, d)=\", f(a, d));\n      print(\"\
    f(b, c)=\", f(b, c));\n      print(\"f(a, c)=\", f(a, c));\n      print(\"f(b,\
    \ d)=\", f(b, d));\n      return false;\n    }\n  }\n  return true;\n}\n"
  code: "#pragma once\n\n// check Monge property on [0, N]:\n// f(a,d) + f(b,c) >=\
    \ f(a,c) + f(b,d) for a < b < c < d\ntemplate <typename T, typename F>\nbool check_monge(int\
    \ N, F f) {\n  FOR(d, N + 1) FOR(c, d) FOR(b, c) FOR(a, b) {\n    T lhs = f(a,\
    \ d) + f(b, c);\n    T rhs = f(a, c) + f(b, d);\n    if (lhs < rhs) {\n      print(\"\
    monge ng\");\n      print(\"a,b,c,d = \", a, b, c, d);\n      print(\"f(a, d)=\"\
    , f(a, d));\n      print(\"f(b, c)=\", f(b, c));\n      print(\"f(a, c)=\", f(a,\
    \ c));\n      print(\"f(b, d)=\", f(b, d));\n      return false;\n    }\n  }\n\
    \  return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/monge/check_monge.hpp
  requiredBy: []
  timestamp: '2026-05-31 17:32:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/check_monge.test.cpp
documentation_of: convex/monge/check_monge.hpp
layout: document
redirect_from:
- /library/convex/monge/check_monge.hpp
- /library/convex/monge/check_monge.hpp.html
title: convex/monge/check_monge.hpp
---
