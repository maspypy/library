---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/check_monge.test.cpp
    title: test/1_mytest/check_monge.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/monge/check_monge.hpp\"\n\n// check Monge property\
    \ on [0, N]:\n// f(a,d) + f(b,c) >= f(a,c) + f(b,d) for a < b < c < d\ntemplate\
    \ <typename T, typename F>\nbool check_monge(int N, F f) {\n  FOR(d, N + 1) FOR(c,\
    \ d) FOR(b, c) FOR(a, b) {\n    T lhs = f(a, d) + f(b, c);\n    T rhs = f(a, c)\
    \ + f(b, d);\n    if (lhs < rhs) {\n      print(\"monge ng\");\n      print(\"\
    a,b,c,d = \", a, b, c, d);\n      print(\"f(a, d)=\", f(a, d));\n      print(\"\
    f(b, c)=\", f(b, c));\n      print(\"f(a, c)=\", f(a, c));\n      print(\"f(b,\
    \ d)=\", f(b, d));\n      return false;\n    }\n  }\n  return true;\n}\n"
  code: "\n// check Monge property on [0, N]:\n// f(a,d) + f(b,c) >= f(a,c) + f(b,d)\
    \ for a < b < c < d\ntemplate <typename T, typename F>\nbool check_monge(int N,\
    \ F f) {\n  FOR(d, N + 1) FOR(c, d) FOR(b, c) FOR(a, b) {\n    T lhs = f(a, d)\
    \ + f(b, c);\n    T rhs = f(a, c) + f(b, d);\n    if (lhs < rhs) {\n      print(\"\
    monge ng\");\n      print(\"a,b,c,d = \", a, b, c, d);\n      print(\"f(a, d)=\"\
    , f(a, d));\n      print(\"f(b, c)=\", f(b, c));\n      print(\"f(a, c)=\", f(a,\
    \ c));\n      print(\"f(b, d)=\", f(b, d));\n      return false;\n    }\n  }\n\
    \  return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/monge/check_monge.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/check_monge.test.cpp
documentation_of: convex/monge/check_monge.hpp
layout: document
redirect_from:
- /library/convex/monge/check_monge.hpp
- /library/convex/monge/check_monge.hpp.html
title: convex/monge/check_monge.hpp
---
