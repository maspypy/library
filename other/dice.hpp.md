---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ITP1_11_A.test.cpp
    title: test/aoj/ITP1_11_A.test.cpp
  - icon: ':x:'
    path: test/aoj/ITP1_11_B.test.cpp
    title: test/aoj/ITP1_11_B.test.cpp
  - icon: ':x:'
    path: test/aoj/ITP1_11_C.test.cpp
    title: test/aoj/ITP1_11_C.test.cpp
  - icon: ':x:'
    path: test/aoj/ITP1_11_D.test.cpp
    title: test/aoj/ITP1_11_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A
  bundledCode: "#line 1 \"other/dice.hpp\"\n// \u6B21\u306E\u756A\u53F7\u4ED8\u3051\
    \u308B\u306B\u5F93\u3046\uFF1AUFRLBD\n// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A\n\
    // i, 5-i \u304C\u53CD\u5BFE\u306E\u9762\u306B\u306A\u3063\u3066\u3044\u308B\n\
    template <typename X>\nstruct Dice {\n  using ARR = array<X, 6>;\n  ARR A;\n\n\
    \  Dice(ARR A) : A(A) {}\n\n  X U() { return A[0]; }\n  X F() { return A[1]; }\n\
    \  X R() { return A[2]; }\n  X L() { return A[3]; }\n  X B() { return A[4]; }\n\
    \  X D() { return A[5]; }\n\n  // U \u306E\u3046\u3064\u308B\u5148\u3068\u306A\
    \u308B FRLB \u3092\u6307\u5B9A\u3059\u308B or \u65B9\u89D2 NWES \u3092\u6307\u5B9A\
    \u3059\u308B\n  void rotate(char c) {\n    if (c == 'F' || c == 'S') A = {A[4],\
    \ A[0], A[2], A[3], A[5], A[1]};\n    elif (c == 'R' || c == 'E') A = {A[3], A[1],\
    \ A[0], A[5], A[4], A[2]};\n    elif (c == 'L' || c == 'W') A = {A[2], A[1], A[5],\
    \ A[0], A[4], A[3]};\n    elif (c == 'B' || c == 'N') A = {A[1], A[5], A[2], A[3],\
    \ A[0], A[4]};\n    else {\n      assert(false);\n    }\n  }\n\n  vc<ARR> gen_all()\
    \ {\n    vc<ARR> res(24);\n    vc<tuple<int, int, int>> tmp(24);\n    tmp[0] =\
    \ {0, 1, 2};\n    tmp[1] = {0, 4, 3};\n    tmp[2] = {5, 1, 3};\n    tmp[3] = {5,\
    \ 4, 2};\n\n    FOR(i, 4) {\n      auto [a, b, c] = tmp[i];\n      tmp[4 + i]\
    \ = {b, c, a};\n      tmp[8 + i] = {c, a, b};\n    }\n\n    FOR(i, 12) {\n   \
    \   auto [a, b, c] = tmp[i];\n      tmp[12 + i] = {5 - b, a, c};\n    }\n\n  \
    \  FOR(i, 24) {\n      auto [a, b, c] = tmp[i];\n      res[i] = {A[a], A[b], A[c],\
    \ A[5 - c], A[5 - b], A[5 - a]};\n    }\n    return res;\n  }\n};\n"
  code: "// \u6B21\u306E\u756A\u53F7\u4ED8\u3051\u308B\u306B\u5F93\u3046\uFF1AUFRLBD\n\
    // https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A\n// i,\
    \ 5-i \u304C\u53CD\u5BFE\u306E\u9762\u306B\u306A\u3063\u3066\u3044\u308B\ntemplate\
    \ <typename X>\nstruct Dice {\n  using ARR = array<X, 6>;\n  ARR A;\n\n  Dice(ARR\
    \ A) : A(A) {}\n\n  X U() { return A[0]; }\n  X F() { return A[1]; }\n  X R()\
    \ { return A[2]; }\n  X L() { return A[3]; }\n  X B() { return A[4]; }\n  X D()\
    \ { return A[5]; }\n\n  // U \u306E\u3046\u3064\u308B\u5148\u3068\u306A\u308B\
    \ FRLB \u3092\u6307\u5B9A\u3059\u308B or \u65B9\u89D2 NWES \u3092\u6307\u5B9A\u3059\
    \u308B\n  void rotate(char c) {\n    if (c == 'F' || c == 'S') A = {A[4], A[0],\
    \ A[2], A[3], A[5], A[1]};\n    elif (c == 'R' || c == 'E') A = {A[3], A[1], A[0],\
    \ A[5], A[4], A[2]};\n    elif (c == 'L' || c == 'W') A = {A[2], A[1], A[5], A[0],\
    \ A[4], A[3]};\n    elif (c == 'B' || c == 'N') A = {A[1], A[5], A[2], A[3], A[0],\
    \ A[4]};\n    else {\n      assert(false);\n    }\n  }\n\n  vc<ARR> gen_all()\
    \ {\n    vc<ARR> res(24);\n    vc<tuple<int, int, int>> tmp(24);\n    tmp[0] =\
    \ {0, 1, 2};\n    tmp[1] = {0, 4, 3};\n    tmp[2] = {5, 1, 3};\n    tmp[3] = {5,\
    \ 4, 2};\n\n    FOR(i, 4) {\n      auto [a, b, c] = tmp[i];\n      tmp[4 + i]\
    \ = {b, c, a};\n      tmp[8 + i] = {c, a, b};\n    }\n\n    FOR(i, 12) {\n   \
    \   auto [a, b, c] = tmp[i];\n      tmp[12 + i] = {5 - b, a, c};\n    }\n\n  \
    \  FOR(i, 24) {\n      auto [a, b, c] = tmp[i];\n      res[i] = {A[a], A[b], A[c],\
    \ A[5 - c], A[5 - b], A[5 - a]};\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: other/dice.hpp
  requiredBy: []
  timestamp: '2022-08-20 02:40:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ITP1_11_C.test.cpp
  - test/aoj/ITP1_11_B.test.cpp
  - test/aoj/ITP1_11_A.test.cpp
  - test/aoj/ITP1_11_D.test.cpp
documentation_of: other/dice.hpp
layout: document
redirect_from:
- /library/other/dice.hpp
- /library/other/dice.hpp.html
title: other/dice.hpp
---
