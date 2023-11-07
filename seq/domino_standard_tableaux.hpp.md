---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: seq/hook_length_formula.hpp
    title: seq/hook_length_formula.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2149.test.cpp
    title: test/yukicoder/2149.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"seq/hook_length_formula.hpp\"\n\ntemplate <typename mint>\n\
    mint hook_length_formula(vc<int> A) {\n  if (len(A) == 0) return 1;\n  int H =\
    \ len(A), W = A[0];\n  FOR(i, H - 1) assert(A[i] >= A[i + 1]);\n  vc<int> B(W);\n\
    \  reverse(all(A));\n  mint ANS = fact<mint>(SUM<int>(A));\n  for (auto&& a: A)\
    \ {\n    FOR(j, a) { ANS *= inv<mint>(B[j] + a - j), ++B[j]; }\n  }\n  return\
    \ ANS;\n}\n#line 2 \"seq/domino_standard_tableaux.hpp\"\n\ntemplate <typename\
    \ mint>\nmint domino_standard_tableaux(vc<int> A) {\n  int N = len(A);\n  if (N\
    \ == 0) return mint(1);\n  FOR(i, N - 1) assert(A[i] >= A[i + 1]);\n  int x =\
    \ 0;\n  FOR(i, N) {\n    if (A[i] % 2 == 1) { x += (i % 2 == 0 ? 1 : -1); }\n\
    \  }\n  if (x != 0) return 0;\n  FOR(i, N) A[i] += N - 1 - i;\n  int ev = 0, od\
    \ = 0;\n  vc<int> P, Q;\n  FOR_R(i, N) {\n    if (A[i] % 2 == 0) { P.eb(A[i] /\
    \ 2 - ev), ++ev; }\n    if (A[i] % 2 == 1) { Q.eb(A[i] / 2 - od), ++od; }\n  }\n\
    \  reverse(all(P)), reverse(all(Q));\n  int b = SUM<int>(P), c = SUM<int>(Q);\n\
    \  return C<mint>(b + c, b) * hook_length_formula<mint>(P)\n         * hook_length_formula<mint>(Q);\n\
    }\n"
  code: "#include \"seq/hook_length_formula.hpp\"\n\ntemplate <typename mint>\nmint\
    \ domino_standard_tableaux(vc<int> A) {\n  int N = len(A);\n  if (N == 0) return\
    \ mint(1);\n  FOR(i, N - 1) assert(A[i] >= A[i + 1]);\n  int x = 0;\n  FOR(i,\
    \ N) {\n    if (A[i] % 2 == 1) { x += (i % 2 == 0 ? 1 : -1); }\n  }\n  if (x !=\
    \ 0) return 0;\n  FOR(i, N) A[i] += N - 1 - i;\n  int ev = 0, od = 0;\n  vc<int>\
    \ P, Q;\n  FOR_R(i, N) {\n    if (A[i] % 2 == 0) { P.eb(A[i] / 2 - ev), ++ev;\
    \ }\n    if (A[i] % 2 == 1) { Q.eb(A[i] / 2 - od), ++od; }\n  }\n  reverse(all(P)),\
    \ reverse(all(Q));\n  int b = SUM<int>(P), c = SUM<int>(Q);\n  return C<mint>(b\
    \ + c, b) * hook_length_formula<mint>(P)\n         * hook_length_formula<mint>(Q);\n\
    }\n"
  dependsOn:
  - seq/hook_length_formula.hpp
  isVerificationFile: false
  path: seq/domino_standard_tableaux.hpp
  requiredBy: []
  timestamp: '2022-12-07 02:54:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2149.test.cpp
documentation_of: seq/domino_standard_tableaux.hpp
layout: document
redirect_from:
- /library/seq/domino_standard_tableaux.hpp
- /library/seq/domino_standard_tableaux.hpp.html
title: seq/domino_standard_tableaux.hpp
---
