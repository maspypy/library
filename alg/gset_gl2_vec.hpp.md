---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/group_gl2.hpp
    title: alg/group_gl2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1648_discretelog_gset.test.cpp
    title: test/yukicoder/1648_discretelog_gset.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_gl2.hpp\"\n\ntemplate <typename T>\nstruct Group_GL2\
    \ {\n  using X = array<array<T, 2>, 2>;\n  using value_type = X;\n  static X op(const\
    \ X &x, const X &y) {\n    X z{};\n    FOR(i, 2) FOR(j, 2) FOR(k, 2) z[i][k] +=\
    \ x[i][j] * y[j][k];\n    return z;\n  }\n  static X inverse(const X &x) {\n \
    \   T det = x[0][0] * x[1][1] - x[0][1] * x[1][0];\n    T cf = T(1) / det;\n \
    \   X y;\n    y[0] = {x[1][1] * cf, -x[0][1] * cf};\n    y[1] = {-x[1][0] * cf,\
    \ x[0][0] * cf};\n    return y;\n  }\n  // static X power(const X &x, ll n) {\
    \ return n * x; }\n  static constexpr X unit() {\n    X x;\n    x[0] = {T(1),\
    \ T(0)};\n    x[1] = {T(0), T(1)};\n    return x;\n  }\n  static constexpr bool\
    \ commute = 1;\n};\n#line 3 \"alg/gset_gl2_vec.hpp\"\n\ntemplate <typename T>\n\
    struct GSet_GL2_Vec {\n  using Group = Group_GL2<T>;\n  using G = typename Group::value_type;\n\
    \  using X = pair<T, T>;\n  static X act(const G &g, const X &x) {\n    return\
    \ {g[0][0] * x.fi + g[0][1] * x.se, g[1][0] * x.fi + g[1][1] * x.se};\n  }\n};\n"
  code: "#pragma once\n#include \"alg/group_gl2.hpp\"\n\ntemplate <typename T>\nstruct\
    \ GSet_GL2_Vec {\n  using Group = Group_GL2<T>;\n  using G = typename Group::value_type;\n\
    \  using X = pair<T, T>;\n  static X act(const G &g, const X &x) {\n    return\
    \ {g[0][0] * x.fi + g[0][1] * x.se, g[1][0] * x.fi + g[1][1] * x.se};\n  }\n};"
  dependsOn:
  - alg/group_gl2.hpp
  isVerificationFile: false
  path: alg/gset_gl2_vec.hpp
  requiredBy: []
  timestamp: '2022-06-05 16:18:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1648_discretelog_gset.test.cpp
documentation_of: alg/gset_gl2_vec.hpp
layout: document
redirect_from:
- /library/alg/gset_gl2_vec.hpp
- /library/alg/gset_gl2_vec.hpp.html
title: alg/gset_gl2_vec.hpp
---
