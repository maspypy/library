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
    - https://codeforces.com/contest/267/problem/C
  bundledCode: "#line 1 \"linalg/solve_linear_real.hpp\"\n\n// \u6B63\u65B9\u884C\u5217\
    \ full rank \u524D\u63D0\n// \u8AA4\u5DEE\u3067\u6B7B\u306C\u30D1\u30BF\u30FC\u30F3\
    \u304C\u306A\u3044\u304B\u306F\u77E5\u3089\u306A\u3044\n// https://codeforces.com/contest/267/problem/C\n\
    template <typename T>\nvc<T> solve_linear_real(vc<vc<T>> a, vc<T> b, int n = -1,\
    \ int m = -1) {\n  if (n == -1) { n = len(a); }\n  assert(n == len(a) && n ==\
    \ len(b));\n  FOR(i, n) assert(len(a[i]) == n);\n  FOR(i, n) {\n    T mx = abs(a[i][i]);\n\
    \    int k = i;\n    FOR(j, i + 1, n) if (chmax(mx, abs(a[j][i]))) k = j;\n  \
    \  if (k != i) { swap(a[i], a[k]), swap(b[i], b[k]); }\n    T c = T(1) / a[i][i];\n\
    \    for (auto&& x: a[i]) x *= c;\n    b[i] *= c;\n    FOR(k, n) {\n      if (i\
    \ != k) {\n        T c = a[k][i];\n        FOR(j, i, n) a[k][j] -= c * a[i][j];\n\
    \        b[k] -= c * b[i];\n      }\n    }\n  }\n  return b;\n}\n"
  code: "\n// \u6B63\u65B9\u884C\u5217 full rank \u524D\u63D0\n// \u8AA4\u5DEE\u3067\
    \u6B7B\u306C\u30D1\u30BF\u30FC\u30F3\u304C\u306A\u3044\u304B\u306F\u77E5\u3089\
    \u306A\u3044\n// https://codeforces.com/contest/267/problem/C\ntemplate <typename\
    \ T>\nvc<T> solve_linear_real(vc<vc<T>> a, vc<T> b, int n = -1, int m = -1) {\n\
    \  if (n == -1) { n = len(a); }\n  assert(n == len(a) && n == len(b));\n  FOR(i,\
    \ n) assert(len(a[i]) == n);\n  FOR(i, n) {\n    T mx = abs(a[i][i]);\n    int\
    \ k = i;\n    FOR(j, i + 1, n) if (chmax(mx, abs(a[j][i]))) k = j;\n    if (k\
    \ != i) { swap(a[i], a[k]), swap(b[i], b[k]); }\n    T c = T(1) / a[i][i];\n \
    \   for (auto&& x: a[i]) x *= c;\n    b[i] *= c;\n    FOR(k, n) {\n      if (i\
    \ != k) {\n        T c = a[k][i];\n        FOR(j, i, n) a[k][j] -= c * a[i][j];\n\
    \        b[k] -= c * b[i];\n      }\n    }\n  }\n  return b;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/solve_linear_real.hpp
  requiredBy: []
  timestamp: '2024-08-20 10:42:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/solve_linear_real.hpp
layout: document
redirect_from:
- /library/linalg/solve_linear_real.hpp
- /library/linalg/solve_linear_real.hpp.html
title: linalg/solve_linear_real.hpp
---
