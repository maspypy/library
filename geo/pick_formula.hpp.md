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
  bundledCode: "#line 1 \"geo/pick_formula.hpp\"\n\n// input: simple polygon\n// return:\
    \ area2, inner, boundary\ntemplate <typename T>\ntuple<i128, i128, i128> pick_formula(vc<Point<T>>&\
    \ A) {\n  using P = Point<T>;\n  int N = len(A);\n  i128 area2 = 0;\n  i128 bd\
    \ = 0;\n  FOR(i, N) {\n    P a = A[i], b = A[(i + 1) % N];\n    area2 += i128(a.x)\
    \ * b.y - i128(a.y) * b.x;\n    P d = b - a;\n    bd += gcd(d.x, d.y);\n  }\n\
    \  i128 in = (area2 + 2 - bd) / 2;\n  return {area2, in, bd};\n}\n"
  code: "\n// input: simple polygon\n// return: area2, inner, boundary\ntemplate <typename\
    \ T>\ntuple<i128, i128, i128> pick_formula(vc<Point<T>>& A) {\n  using P = Point<T>;\n\
    \  int N = len(A);\n  i128 area2 = 0;\n  i128 bd = 0;\n  FOR(i, N) {\n    P a\
    \ = A[i], b = A[(i + 1) % N];\n    area2 += i128(a.x) * b.y - i128(a.y) * b.x;\n\
    \    P d = b - a;\n    bd += gcd(d.x, d.y);\n  }\n  i128 in = (area2 + 2 - bd)\
    \ / 2;\n  return {area2, in, bd};\n}"
  dependsOn: []
  isVerificationFile: false
  path: geo/pick_formula.hpp
  requiredBy: []
  timestamp: '2026-08-01 03:11:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/pick_formula.hpp
layout: document
redirect_from:
- /library/geo/pick_formula.hpp
- /library/geo/pick_formula.hpp.html
title: geo/pick_formula.hpp
---
