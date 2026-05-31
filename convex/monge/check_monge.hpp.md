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
  bundledCode: "#line 1 \"convex/monge/check_monge.hpp\"\n// \u5B9A\u7FA9\u57DF [0,\
    \ N] \u306E\u7BC4\u56F2\u3067 f \u306E monge \u6027\u3092\u78BA\u8A8D\ntemplate\
    \ <typename T, typename F>\nbool check_monge(int N, F f) {\n  FOR(l, N + 1) FOR(k,\
    \ l) FOR(j, k) FOR(i, j) {\n    T lhs = f(i, l) + f(j, k);\n    T rhs = f(i, k)\
    \ + f(j, l);\n    if (lhs < rhs) {\n      print(\"monge ng\");\n      print(i,\
    \ j, k, l, f(i, k), f(i, l), f(j, k), f(j, l), lhs, rhs);\n      return false;\n\
    \    }\n  }\n  print(\"monge ok\");\n  return true;\n}\n"
  code: "// \u5B9A\u7FA9\u57DF [0, N] \u306E\u7BC4\u56F2\u3067 f \u306E monge \u6027\
    \u3092\u78BA\u8A8D\ntemplate <typename T, typename F>\nbool check_monge(int N,\
    \ F f) {\n  FOR(l, N + 1) FOR(k, l) FOR(j, k) FOR(i, j) {\n    T lhs = f(i, l)\
    \ + f(j, k);\n    T rhs = f(i, k) + f(j, l);\n    if (lhs < rhs) {\n      print(\"\
    monge ng\");\n      print(i, j, k, l, f(i, k), f(i, l), f(j, k), f(j, l), lhs,\
    \ rhs);\n      return false;\n    }\n  }\n  print(\"monge ok\");\n  return true;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/monge/check_monge.hpp
  requiredBy: []
  timestamp: '2026-05-31 16:46:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/monge/check_monge.hpp
layout: document
redirect_from:
- /library/convex/monge/check_monge.hpp
- /library/convex/monge/check_monge.hpp.html
title: convex/monge/check_monge.hpp
---
