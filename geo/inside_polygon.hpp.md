---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/qoj5443.test.cpp
    title: test/mytest/qoj5443.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qoj.ac/problem/5443
  bundledCode: "#line 1 \"geo/inside_polygon.hpp\"\n// https://qoj.ac/problem/5443\n\
    // \u7DDA\u5206\u4E0A\u306B\u9802\u70B9\u3084\u8FBA\u304C\u6765\u308B\u3053\u3068\
    \u306F\u8A31\u5BB9\ntemplate <typename T>\nbool inside_polygon(Segment<T> S, vc<Point<T>>&\
    \ dat) {\n  using P = Point<T>;\n  int N = len(dat);\n  int cnt = 0;\n  P A =\
    \ S.A, B = S.B;\n  auto PREV = [&](int i) -> int { return (i == 0 ? N : i) - 1;\
    \ };\n  auto NEXT = [&](int i) -> int { return (i == N - 1 ? 0 : i + 1); };\n\
    \  FOR(i, N) {\n    P p = dat[i], q = dat[NEXT(i)], r = dat[PREV(i)];\n    int\
    \ a = ccw(A, B, p);\n    int b = ccw(A, B, q);\n    int c = ccw(A, B, r);\n  \
    \  if (a * b == -1) {\n      Segment pq(p, q);\n      auto L = pq.to_Line();\n\
    \      T x = L.eval(A), y = L.eval(B);\n      if (x < y) { x = -x, y = -y; }\n\
    \      if (x <= 0) ++cnt;\n      if (0 < x && x < x - y) return 0;\n    }\n  \
    \  if (a == 0) {\n      if (b != c && (b * c < 0 || ccw(p, q, r) > 0)) {\n   \
    \     T t = (p - A).dot(B - A), x = (B - A).dot(B - A);\n        if (t <= 0) ++cnt;\n\
    \        if (0 < t && t < x) return 0;\n      }\n    }\n  }\n  return cnt % 2\
    \ == 1;\n}\n"
  code: "// https://qoj.ac/problem/5443\n// \u7DDA\u5206\u4E0A\u306B\u9802\u70B9\u3084\
    \u8FBA\u304C\u6765\u308B\u3053\u3068\u306F\u8A31\u5BB9\ntemplate <typename T>\n\
    bool inside_polygon(Segment<T> S, vc<Point<T>>& dat) {\n  using P = Point<T>;\n\
    \  int N = len(dat);\n  int cnt = 0;\n  P A = S.A, B = S.B;\n  auto PREV = [&](int\
    \ i) -> int { return (i == 0 ? N : i) - 1; };\n  auto NEXT = [&](int i) -> int\
    \ { return (i == N - 1 ? 0 : i + 1); };\n  FOR(i, N) {\n    P p = dat[i], q =\
    \ dat[NEXT(i)], r = dat[PREV(i)];\n    int a = ccw(A, B, p);\n    int b = ccw(A,\
    \ B, q);\n    int c = ccw(A, B, r);\n    if (a * b == -1) {\n      Segment pq(p,\
    \ q);\n      auto L = pq.to_Line();\n      T x = L.eval(A), y = L.eval(B);\n \
    \     if (x < y) { x = -x, y = -y; }\n      if (x <= 0) ++cnt;\n      if (0 <\
    \ x && x < x - y) return 0;\n    }\n    if (a == 0) {\n      if (b != c && (b\
    \ * c < 0 || ccw(p, q, r) > 0)) {\n        T t = (p - A).dot(B - A), x = (B -\
    \ A).dot(B - A);\n        if (t <= 0) ++cnt;\n        if (0 < t && t < x) return\
    \ 0;\n      }\n    }\n  }\n  return cnt % 2 == 1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geo/inside_polygon.hpp
  requiredBy: []
  timestamp: '2023-01-31 20:02:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/qoj5443.test.cpp
documentation_of: geo/inside_polygon.hpp
layout: document
redirect_from:
- /library/geo/inside_polygon.hpp
- /library/geo/inside_polygon.hpp.html
title: geo/inside_polygon.hpp
---
