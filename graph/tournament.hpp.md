---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://official.contest.yandex.ru/opencupXXII/contest/30766/problems/K
  bundledCode: "#line 1 \"graph/tournament.hpp\"\n// https://official.contest.yandex.ru/opencupXXII/contest/30766/problems/K\n\
    // a \u2192 b \u8FBA\u304C\u3042\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\
    \u3059\u308B bool check(int, int) \u3092\u6E21\u3059\u3002\ntemplate <typename\
    \ F>\nvc<int> hamiltonian_path_in_tournament(int n, F check) {\n  vc<int> P(n);\n\
    \  iota(all(P), 0);\n  sort(all(P), [&](auto& x, auto& y) { return check(x, y);\
    \ });\n  return P;\n}\n"
  code: "// https://official.contest.yandex.ru/opencupXXII/contest/30766/problems/K\n\
    // a \u2192 b \u8FBA\u304C\u3042\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\
    \u3059\u308B bool check(int, int) \u3092\u6E21\u3059\u3002\ntemplate <typename\
    \ F>\nvc<int> hamiltonian_path_in_tournament(int n, F check) {\n  vc<int> P(n);\n\
    \  iota(all(P), 0);\n  sort(all(P), [&](auto& x, auto& y) { return check(x, y);\
    \ });\n  return P;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tournament.hpp
  requiredBy: []
  timestamp: '2022-04-22 16:56:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tournament.hpp
layout: document
redirect_from:
- /library/graph/tournament.hpp
- /library/graph/tournament.hpp.html
title: graph/tournament.hpp
---
