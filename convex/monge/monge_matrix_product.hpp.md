---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html
  bundledCode: "#line 1 \"convex/monge/monge_matrix_product.hpp\"\n\n// https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html\n\
    // Prop 1\n// \u4E0A\u4E09\u89D2 monge A, B\n// C[i][j] = min_k (A[i][k] + B[k][j])\n\
    template <typename T, typename F1, typename F2>\nvvc<T> monge_matrix_product(int\
    \ N, F1 A, F2 B) {\n  vv(T, C, N + 1, N + 1, infty<T>);\n  vc<int> K(N + 1);\n\
    \  FOR(i, N + 1) C[i][i] = A(i, i) + B(i, i), K[i] = i;\n  FOR(s, 1, N + 1) {\n\
    \    vc<int> newK(N + 1 - s);\n    FOR(i, N + 1 - s) {\n      int j = i + s;\n\
    \      int p = K[i], q = K[i + 1];\n      FOR(k, p, q + 1) if (chmin(C[i][j],\
    \ A(i, k) + B(k, j))) newK[i] = k;\n    }\n    swap(K, newK);\n  }\n  return C;\n\
    }\n"
  code: "\n// https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html\n\
    // Prop 1\n// \u4E0A\u4E09\u89D2 monge A, B\n// C[i][j] = min_k (A[i][k] + B[k][j])\n\
    template <typename T, typename F1, typename F2>\nvvc<T> monge_matrix_product(int\
    \ N, F1 A, F2 B) {\n  vv(T, C, N + 1, N + 1, infty<T>);\n  vc<int> K(N + 1);\n\
    \  FOR(i, N + 1) C[i][i] = A(i, i) + B(i, i), K[i] = i;\n  FOR(s, 1, N + 1) {\n\
    \    vc<int> newK(N + 1 - s);\n    FOR(i, N + 1 - s) {\n      int j = i + s;\n\
    \      int p = K[i], q = K[i + 1];\n      FOR(k, p, q + 1) if (chmin(C[i][j],\
    \ A(i, k) + B(k, j))) newK[i] = k;\n    }\n    swap(K, newK);\n  }\n  return C;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/monge/monge_matrix_product.hpp
  requiredBy: []
  timestamp: '2026-05-31 16:57:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/monge/monge_matrix_product.hpp
layout: document
redirect_from:
- /library/convex/monge/monge_matrix_product.hpp
- /library/convex/monge/monge_matrix_product.hpp.html
title: convex/monge/monge_matrix_product.hpp
---
