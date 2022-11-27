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
  bundledCode: "#line 2 \"alg/monoid/gl2.hpp\"\n\ntemplate <typename T, bool reversed>\n\
    struct Group_GL2 {\n  using X = array<array<T, 2>, 2>;\n  using value_type = X;\n\
    \  static X op(const X &x, const X &y) {\n    X z{};\n    if (!reversed) {\n \
    \     FOR(i, 2) FOR(j, 2) FOR(k, 2) z[i][k] += x[i][j] * y[j][k];\n    }\n   \
    \ if (reversed) {\n      FOR(i, 2) FOR(j, 2) FOR(k, 2) z[i][k] += y[i][j] * x[j][k];\n\
    \    }\n    return z;\n  }\n  static X inverse(const X &x) {\n    T det = x[0][0]\
    \ * x[1][1] - x[0][1] * x[1][0];\n    T cf = T(1) / det;\n    X y;\n    y[0] =\
    \ {x[1][1] * cf, -x[0][1] * cf};\n    y[1] = {-x[1][0] * cf, x[0][0] * cf};\n\
    \    return y;\n  }\n  // static X power(const X &x, ll n) { return n * x; }\n\
    \  static constexpr X unit() {\n    X x;\n    x[0] = {T(1), T(0)};\n    x[1] =\
    \ {T(0), T(1)};\n    return x;\n  }\n  static constexpr bool commute = 0;\n};\n"
  code: "#pragma once\n\ntemplate <typename T, bool reversed>\nstruct Group_GL2 {\n\
    \  using X = array<array<T, 2>, 2>;\n  using value_type = X;\n  static X op(const\
    \ X &x, const X &y) {\n    X z{};\n    if (!reversed) {\n      FOR(i, 2) FOR(j,\
    \ 2) FOR(k, 2) z[i][k] += x[i][j] * y[j][k];\n    }\n    if (reversed) {\n   \
    \   FOR(i, 2) FOR(j, 2) FOR(k, 2) z[i][k] += y[i][j] * x[j][k];\n    }\n    return\
    \ z;\n  }\n  static X inverse(const X &x) {\n    T det = x[0][0] * x[1][1] - x[0][1]\
    \ * x[1][0];\n    T cf = T(1) / det;\n    X y;\n    y[0] = {x[1][1] * cf, -x[0][1]\
    \ * cf};\n    y[1] = {-x[1][0] * cf, x[0][0] * cf};\n    return y;\n  }\n  //\
    \ static X power(const X &x, ll n) { return n * x; }\n  static constexpr X unit()\
    \ {\n    X x;\n    x[0] = {T(1), T(0)};\n    x[1] = {T(0), T(1)};\n    return\
    \ x;\n  }\n  static constexpr bool commute = 0;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/gl2.hpp
  requiredBy: []
  timestamp: '2022-11-27 13:06:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/gl2.hpp
layout: document
redirect_from:
- /library/alg/monoid/gl2.hpp
- /library/alg/monoid/gl2.hpp.html
title: alg/monoid/gl2.hpp
---
