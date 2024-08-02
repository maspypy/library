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
  bundledCode: "#line 1 \"seq/rsk_correspondence.hpp\"\n\npair<vvc<int>, vvc<int>>\
    \ RSK_correspondence_prefix(vc<int> A, int nrow = -1) {\n  int N = len(A);\n \
    \ if (nrow == -1) nrow = N;\n  vvc<int> X(nrow), Y(nrow);\n  FOR(i, len(A)) {\n\
    \    int a = A[i];\n    int col = i;\n    FOR(row, nrow) {\n      // \u6307\u6570\
    \u63A2\u7D22\n      int r = min<int>(col + 1, len(X[row]));\n      // [r] > a\n\
    \      int l = r - 1;\n      while (0 <= l && X[row][l] > a) { tie(l, r) = mp(3\
    \ * l - 2 * r, l); }\n      // [l] < a, [r] > a\n      while (l + 1 < r) {\n \
    \       int m = (l + r) / 2;\n        (m < 0 || X[row][m] < a ? l : r) = m;\n\
    \      }\n      col = r;\n      if (col == len(X[row])) {\n        X[row].eb(a),\
    \ Y[row].eb(i);\n        break;\n      } else {\n        swap(X[row][col], a);\n\
    \      }\n    }\n  }\n  while (len(X) && X.back().empty()) POP(X);\n  return {X,\
    \ Y};\n}\n\n// \u6307\u6570\u63A2\u7D22\u3068\u8EE2\u7F6E\u306E\u5229\u7528\u306B\
    \u3088\u308A worst(N^1.5) \u306B\u306A\u3063\u3066\u3044\u308B.\n// \u30E9\u30F3\
    \u30C0\u30E0\u30B1\u30FC\u30B9\u3060\u3068\u666E\u901A\u306B\u3084\u308B\u65B9\
    \u304C\u901F\u3044.\npair<vvc<int>, vvc<int>> RSK_correspondence(vc<int> A) {\n\
    \  int N = len(A);\n  int M = 1;\n  while (M * M < N) ++M;\n  auto [X1, Y1] =\
    \ RSK_correspondence_prefix(A, M);\n  reverse(all(A));\n  int m = len(X1);\n \
    \ auto [X2, Y2] = RSK_correspondence_prefix(A, m);\n  reverse(all(A));\n  for\
    \ (auto& x: A) x = N - 1 - x;\n  auto [X3, Y3] = RSK_correspondence_prefix(A,\
    \ m);\n  X1.resize(len(X2[0]));\n  Y1.resize(len(X2[0]));\n  FOR(i, len(X2)) {\n\
    \    FOR(j, M, len(X2[i])) {\n      X1[j].eb(X2[i][j]);\n      Y1[j].eb(Y3[i][j]);\n\
    \    }\n  }\n  return {X1, Y1};\n}\n"
  code: "\npair<vvc<int>, vvc<int>> RSK_correspondence_prefix(vc<int> A, int nrow\
    \ = -1) {\n  int N = len(A);\n  if (nrow == -1) nrow = N;\n  vvc<int> X(nrow),\
    \ Y(nrow);\n  FOR(i, len(A)) {\n    int a = A[i];\n    int col = i;\n    FOR(row,\
    \ nrow) {\n      // \u6307\u6570\u63A2\u7D22\n      int r = min<int>(col + 1,\
    \ len(X[row]));\n      // [r] > a\n      int l = r - 1;\n      while (0 <= l &&\
    \ X[row][l] > a) { tie(l, r) = mp(3 * l - 2 * r, l); }\n      // [l] < a, [r]\
    \ > a\n      while (l + 1 < r) {\n        int m = (l + r) / 2;\n        (m < 0\
    \ || X[row][m] < a ? l : r) = m;\n      }\n      col = r;\n      if (col == len(X[row]))\
    \ {\n        X[row].eb(a), Y[row].eb(i);\n        break;\n      } else {\n   \
    \     swap(X[row][col], a);\n      }\n    }\n  }\n  while (len(X) && X.back().empty())\
    \ POP(X);\n  return {X, Y};\n}\n\n// \u6307\u6570\u63A2\u7D22\u3068\u8EE2\u7F6E\
    \u306E\u5229\u7528\u306B\u3088\u308A worst(N^1.5) \u306B\u306A\u3063\u3066\u3044\
    \u308B.\n// \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u3060\u3068\u666E\u901A\
    \u306B\u3084\u308B\u65B9\u304C\u901F\u3044.\npair<vvc<int>, vvc<int>> RSK_correspondence(vc<int>\
    \ A) {\n  int N = len(A);\n  int M = 1;\n  while (M * M < N) ++M;\n  auto [X1,\
    \ Y1] = RSK_correspondence_prefix(A, M);\n  reverse(all(A));\n  int m = len(X1);\n\
    \  auto [X2, Y2] = RSK_correspondence_prefix(A, m);\n  reverse(all(A));\n  for\
    \ (auto& x: A) x = N - 1 - x;\n  auto [X3, Y3] = RSK_correspondence_prefix(A,\
    \ m);\n  X1.resize(len(X2[0]));\n  Y1.resize(len(X2[0]));\n  FOR(i, len(X2)) {\n\
    \    FOR(j, M, len(X2[i])) {\n      X1[j].eb(X2[i][j]);\n      Y1[j].eb(Y3[i][j]);\n\
    \    }\n  }\n  return {X1, Y1};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/rsk_correspondence.hpp
  requiredBy: []
  timestamp: '2024-08-03 00:17:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/rsk_correspondence.hpp
layout: document
redirect_from:
- /library/seq/rsk_correspondence.hpp
- /library/seq/rsk_correspondence.hpp.html
title: seq/rsk_correspondence.hpp
---
