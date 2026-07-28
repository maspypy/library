---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convex/monge/monge_shortest_path_d_edge.hpp
    title: convex/monge/monge_shortest_path_d_edge.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  requiredBy:
  - convex/monge/monge_shortest_path_d_edge.hpp
  timestamp: '2026-06-20 11:11:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/alien.hpp
layout: document
redirect_from:
- /library/convex/alien.hpp
- /library/convex/alien.hpp.html
title: convex/alien.hpp
---
