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
  bundledCode: "#line 1 \"enumerate/permutation.hpp\"\n// f(A, end)\ntemplate <typename\
    \ F>\nvoid enumerate_partition(int N, F f) {\n  bool end = false;\n  vc<int> A(N);\n\
    \  FOR(i, N) A[i] = i;\n  do {\n    f(A, end);\n    if (end) break;\n  } while\
    \ (next_permutation(all(A)));\n}\n"
  code: "// f(A, end)\ntemplate <typename F>\nvoid enumerate_partition(int N, F f)\
    \ {\n  bool end = false;\n  vc<int> A(N);\n  FOR(i, N) A[i] = i;\n  do {\n   \
    \ f(A, end);\n    if (end) break;\n  } while (next_permutation(all(A)));\n}"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/permutation.hpp
  requiredBy: []
  timestamp: '2026-11-24 17:55:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/permutation.hpp
layout: document
redirect_from:
- /library/enumerate/permutation.hpp
- /library/enumerate/permutation.hpp.html
title: enumerate/permutation.hpp
---
