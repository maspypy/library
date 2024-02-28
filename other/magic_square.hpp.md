---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/magic_square.test.cpp
    title: test/mytest/magic_square.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/magic_square.hpp\"\n// \u3068\u308A\u3042\u3048\u305A\
    \u5947\u6570\u306E\u307F\u5BFE\u5FDC\u3059\u308B\nvvc<int> magic_square(int N)\
    \ {\n  assert(N % 2 == 1);\n  vv(int, A, N, N);\n  int x = 0, y = N / 2;\n  FOR(i,\
    \ N * N) {\n    A[x][y] = i + 1;\n    int nx = (x == 0 ? N - 1 : x - 1);\n   \
    \ int ny = (y == N - 1 ? 0 : y + 1);\n    if (A[nx][ny] != 0) { nx = (x == N -\
    \ 1 ? 0 : x + 1), ny = y; }\n    tie(x, y) = mp(nx, ny);\n  }\n  return A;\n}\n"
  code: "// \u3068\u308A\u3042\u3048\u305A\u5947\u6570\u306E\u307F\u5BFE\u5FDC\u3059\
    \u308B\nvvc<int> magic_square(int N) {\n  assert(N % 2 == 1);\n  vv(int, A, N,\
    \ N);\n  int x = 0, y = N / 2;\n  FOR(i, N * N) {\n    A[x][y] = i + 1;\n    int\
    \ nx = (x == 0 ? N - 1 : x - 1);\n    int ny = (y == N - 1 ? 0 : y + 1);\n   \
    \ if (A[nx][ny] != 0) { nx = (x == N - 1 ? 0 : x + 1), ny = y; }\n    tie(x, y)\
    \ = mp(nx, ny);\n  }\n  return A;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/magic_square.hpp
  requiredBy: []
  timestamp: '2022-11-27 18:59:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/magic_square.test.cpp
documentation_of: other/magic_square.hpp
layout: document
redirect_from:
- /library/other/magic_square.hpp
- /library/other/magic_square.hpp.html
title: other/magic_square.hpp
---
