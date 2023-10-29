---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: seq/domino_standard_tableaux.hpp
    title: seq/domino_standard_tableaux.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2149.test.cpp
    title: test/yukicoder/2149.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"seq/hook_length_formula.hpp\"\n\ntemplate <typename mint>\n\
    mint hook_length_formula(vc<int> A) {\n  if (len(A) == 0) return 1;\n  int H =\
    \ len(A), W = A[0];\n  FOR(i, H - 1) assert(A[i] >= A[i + 1]);\n  vc<int> B(W);\n\
    \  reverse(all(A));\n  mint ANS = fact<mint>(SUM<int>(A));\n  for (auto&& a: A)\
    \ {\n    FOR(j, a) { ANS *= inv<mint>(B[j] + a - j), ++B[j]; }\n  }\n  return\
    \ ANS;\n}\n"
  code: "#pragma once\n\ntemplate <typename mint>\nmint hook_length_formula(vc<int>\
    \ A) {\n  if (len(A) == 0) return 1;\n  int H = len(A), W = A[0];\n  FOR(i, H\
    \ - 1) assert(A[i] >= A[i + 1]);\n  vc<int> B(W);\n  reverse(all(A));\n  mint\
    \ ANS = fact<mint>(SUM<int>(A));\n  for (auto&& a: A) {\n    FOR(j, a) { ANS *=\
    \ inv<mint>(B[j] + a - j), ++B[j]; }\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/hook_length_formula.hpp
  requiredBy:
  - seq/domino_standard_tableaux.hpp
  timestamp: '2022-12-07 02:54:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2149.test.cpp
documentation_of: seq/hook_length_formula.hpp
layout: document
redirect_from:
- /library/seq/hook_length_formula.hpp
- /library/seq/hook_length_formula.hpp.html
title: seq/hook_length_formula.hpp
---
