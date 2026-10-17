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
  bundledCode: "#line 1 \"alg/monoid/maxplus_matrix.hpp\"\ntemplate <typename T, int\
    \ K, bool upper = false>\nstruct Monoid_MinPlus_Matrix {\n  using X = array<array<T,\
    \ K>, K>;\n  using value_type = X;\n\n  static X op(const X& x, const X& y) {\n\
    \    X z;\n    if constexpr (upper) {\n      FOR(a, K) {\n        FOR(c, a) z[a][c]\
    \ = -infty<T>;\n        FOR(c, a, K) {\n          T v = -infty<T>;\n         \
    \ FOR(b, a, c + 1) v = max(v, x[a][b] + y[b][c]);\n          z[a][c] = v;\n  \
    \      }\n      }\n    } else {\n      FOR(a, K) FOR(c, K) {\n        T v = -infty<T>;\n\
    \        FOR(b, K) v = max(v, x[a][b] + y[b][c]);\n        z[a][c] = v;\n    \
    \  }\n    }\n    return z;\n  }\n\n  static constexpr X id() {\n    X x{};\n \
    \   FOR(i, K) FOR(j, K) x[i][j] = (i == j ? T(0) : -infty<T>);\n    return x;\n\
    \  }\n\n  static constexpr bool commute = false;\n};\n"
  code: "template <typename T, int K, bool upper = false>\nstruct Monoid_MinPlus_Matrix\
    \ {\n  using X = array<array<T, K>, K>;\n  using value_type = X;\n\n  static X\
    \ op(const X& x, const X& y) {\n    X z;\n    if constexpr (upper) {\n      FOR(a,\
    \ K) {\n        FOR(c, a) z[a][c] = -infty<T>;\n        FOR(c, a, K) {\n     \
    \     T v = -infty<T>;\n          FOR(b, a, c + 1) v = max(v, x[a][b] + y[b][c]);\n\
    \          z[a][c] = v;\n        }\n      }\n    } else {\n      FOR(a, K) FOR(c,\
    \ K) {\n        T v = -infty<T>;\n        FOR(b, K) v = max(v, x[a][b] + y[b][c]);\n\
    \        z[a][c] = v;\n      }\n    }\n    return z;\n  }\n\n  static constexpr\
    \ X id() {\n    X x{};\n    FOR(i, K) FOR(j, K) x[i][j] = (i == j ? T(0) : -infty<T>);\n\
    \    return x;\n  }\n\n  static constexpr bool commute = false;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/maxplus_matrix.hpp
  requiredBy: []
  timestamp: '2026-10-17 17:23:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/maxplus_matrix.hpp
layout: document
redirect_from:
- /library/alg/monoid/maxplus_matrix.hpp
- /library/alg/monoid/maxplus_matrix.hpp.html
title: alg/monoid/maxplus_matrix.hpp
---
