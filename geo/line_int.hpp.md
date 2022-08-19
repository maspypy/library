---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geo/point_int.hpp
    title: geo/point_int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/point_int.hpp\"\ntemplate <typenamt INT>\nstruct Point\
    \ {\n  INT x, y;\n  template <typename S, typename T>\n  Point_int(S x, T y) :\
    \ x(x), y(y) {}\n\n  template <typename S, typename T>\n  Point_int(pair<S, T>\
    \ p) : x(p.fi), y(p.se) {}\n};\n#line 2 \"geo/line_int.hpp\"\n\ntemplate <typenamt\
    \ INT>\nstruct Line_int {\n  INT x, y;\n  template <typename S, typename T>\n\
    \  Point_int(S x, T y) : x(x), y(y) {}\n\n  template <typename S, typename T>\n\
    \  Point_int(pair<S, T> p) : x(p.fi), y(p.se) {}\n};\n"
  code: "#include \"geo/point_int.hpp\"\n\ntemplate <typenamt INT>\nstruct Line_int\
    \ {\n  INT x, y;\n  template <typename S, typename T>\n  Point_int(S x, T y) :\
    \ x(x), y(y) {}\n\n  template <typename S, typename T>\n  Point_int(pair<S, T>\
    \ p) : x(p.fi), y(p.se) {}\n};\n"
  dependsOn:
  - geo/point_int.hpp
  isVerificationFile: false
  path: geo/line_int.hpp
  requiredBy: []
  timestamp: '2022-08-20 05:23:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/line_int.hpp
layout: document
redirect_from:
- /library/geo/line_int.hpp
- /library/geo/line_int.hpp.html
title: geo/line_int.hpp
---
