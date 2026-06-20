---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/alien.test.cpp
    title: test/1_mytest/alien.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/alien.hpp\"\n\n// T \u306F\u6574\u6570\u578B\u3092\
    \u4EEE\u5B9A\n// solve(penalty) -> {val, cnt}\n// lo: cnt > K, hi: cnt <= K\n\
    // return: ans, pena\ntemplate <typename T, typename F>\npair<T, T> alien_trick(int\
    \ N, int K, T lo, T hi, F solve) {\n  while (lo + 1 < hi) {\n    T mid = lo +\
    \ (hi - lo) / 2;\n    auto [val, cnt] = solve(mid);\n    (cnt <= K ? hi : lo)\
    \ = mid;\n  }\n  auto [val, cnt] = solve(hi);\n  return {val - hi * K, hi};\n\
    }\n\ntemplate <typename T, typename F>\npair<T, T> alien_trick_auto_search_range(int\
    \ N, int K, F solve) {\n  T lo = 0, hi = 0;\n  int c0 = solve(0).se;\n  if (c0\
    \ <= K) {\n    lo = -1, hi = 0;\n    while (solve(lo).se < K) {\n      T d = hi\
    \ - lo;\n      lo -= 2 * d, hi -= d;\n    }\n  } else {\n    lo = 0, hi = 1;\n\
    \    while (solve(hi).se > K) {\n      T d = hi - lo;\n      lo += d, hi += 2\
    \ * d;\n    }\n  }\n  return alien_trick(N, K, lo, hi, solve);\n}\n"
  code: "#pragma once\n\n// T \u306F\u6574\u6570\u578B\u3092\u4EEE\u5B9A\n// solve(penalty)\
    \ -> {val, cnt}\n// lo: cnt > K, hi: cnt <= K\n// return: ans, pena\ntemplate\
    \ <typename T, typename F>\npair<T, T> alien_trick(int N, int K, T lo, T hi, F\
    \ solve) {\n  while (lo + 1 < hi) {\n    T mid = lo + (hi - lo) / 2;\n    auto\
    \ [val, cnt] = solve(mid);\n    (cnt <= K ? hi : lo) = mid;\n  }\n  auto [val,\
    \ cnt] = solve(hi);\n  return {val - hi * K, hi};\n}\n\ntemplate <typename T,\
    \ typename F>\npair<T, T> alien_trick_auto_search_range(int N, int K, F solve)\
    \ {\n  T lo = 0, hi = 0;\n  int c0 = solve(0).se;\n  if (c0 <= K) {\n    lo =\
    \ -1, hi = 0;\n    while (solve(lo).se < K) {\n      T d = hi - lo;\n      lo\
    \ -= 2 * d, hi -= d;\n    }\n  } else {\n    lo = 0, hi = 1;\n    while (solve(hi).se\
    \ > K) {\n      T d = hi - lo;\n      lo += d, hi += 2 * d;\n    }\n  }\n  return\
    \ alien_trick(N, K, lo, hi, solve);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/alien.hpp
  requiredBy: []
  timestamp: '2026-06-20 11:11:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/alien.test.cpp
documentation_of: convex/alien.hpp
layout: document
redirect_from:
- /library/convex/alien.hpp
- /library/convex/alien.hpp.html
title: convex/alien.hpp
---
