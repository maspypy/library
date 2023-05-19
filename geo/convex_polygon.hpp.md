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
  bundledCode: "#line 1 \"geo/convex_polygon.hpp\"\n\ntemplate <typename T>\nstruct\
    \ ConvexPolygon {\n  using P = Point<T>;\n  int n;\n  vc<P> point;\n\n  ConvexPolygon(vc<P>\
    \ point) : n(len(point)), point(point) { assert(n >= 2); }\n\n  // \u6BD4\u8F03\
    \u95A2\u6570 comp(i,j)\n  template <typename F>\n  int periodic_min_comp(F comp)\
    \ {\n    int L = 0, M = n, R = n + n;\n    while (1) {\n      if (R - L == 2)\
    \ break;\n      int L1 = (L + M) / 2, R1 = (M + R + 1) / 2;\n      if (comp(L1,\
    \ M)) { R = M, M = L1; }\n      elif (comp(R1, M)) { L = M, M = R1; }\n      else\
    \ {\n        L = L1, R = R1;\n      }\n    }\n    return M;\n  }\n\n  int nxt_idx(int\
    \ i) { return (i + 1 == n ? 0 : i + 1); }\n  int perv_idx(int i) { return (i ==\
    \ 0 ? n - 1 : i - 1); }\n\n  // \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A\
    -1\n  int side(P p) {}\n\n  pair<int, T> min_dot(P p) {}\n  pair<int, T> max_dot(P\
    \ p) {}\n  pair<int, int> visible_range(P p) {}\n};\n"
  code: "\ntemplate <typename T>\nstruct ConvexPolygon {\n  using P = Point<T>;\n\
    \  int n;\n  vc<P> point;\n\n  ConvexPolygon(vc<P> point) : n(len(point)), point(point)\
    \ { assert(n >= 2); }\n\n  // \u6BD4\u8F03\u95A2\u6570 comp(i,j)\n  template <typename\
    \ F>\n  int periodic_min_comp(F comp) {\n    int L = 0, M = n, R = n + n;\n  \
    \  while (1) {\n      if (R - L == 2) break;\n      int L1 = (L + M) / 2, R1 =\
    \ (M + R + 1) / 2;\n      if (comp(L1, M)) { R = M, M = L1; }\n      elif (comp(R1,\
    \ M)) { L = M, M = R1; }\n      else {\n        L = L1, R = R1;\n      }\n   \
    \ }\n    return M;\n  }\n\n  int nxt_idx(int i) { return (i + 1 == n ? 0 : i +\
    \ 1); }\n  int perv_idx(int i) { return (i == 0 ? n - 1 : i - 1); }\n\n  // \u4E2D\
    \uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1\n  int side(P p) {}\n\n  pair<int,\
    \ T> min_dot(P p) {}\n  pair<int, T> max_dot(P p) {}\n  pair<int, int> visible_range(P\
    \ p) {}\n};"
  dependsOn: []
  isVerificationFile: false
  path: geo/convex_polygon.hpp
  requiredBy: []
  timestamp: '2023-05-19 13:21:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/convex_polygon.hpp
layout: document
redirect_from:
- /library/geo/convex_polygon.hpp
- /library/geo/convex_polygon.hpp.html
title: geo/convex_polygon.hpp
---
