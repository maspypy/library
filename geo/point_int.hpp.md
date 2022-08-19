---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geo/line_int.hpp
    title: geo/line_int.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/point_int.hpp\"\ntemplate <typenamt INT>\nstruct Point\
    \ {\n  INT x, y;\n  template <typename S, typename T>\n  Point_int(S x, T y) :\
    \ x(x), y(y) {}\n\n  template <typename S, typename T>\n  Point_int(pair<S, T>\
    \ p) : x(p.fi), y(p.se) {}\n};\n"
  code: "template <typenamt INT>\nstruct Point {\n  INT x, y;\n  template <typename\
    \ S, typename T>\n  Point_int(S x, T y) : x(x), y(y) {}\n\n  template <typename\
    \ S, typename T>\n  Point_int(pair<S, T> p) : x(p.fi), y(p.se) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/point_int.hpp
  requiredBy:
  - geo/line_int.hpp
  timestamp: '2022-08-20 05:23:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/point_int.hpp
layout: document
redirect_from:
- /library/geo/point_int.hpp
- /library/geo/point_int.hpp.html
title: geo/point_int.hpp
---
