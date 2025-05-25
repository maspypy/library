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
  bundledCode: "#line 1 \"setfunc/online/online_subset_zeta.hpp\"\n/*\nsegtree \u3092\
    \u8003\u3048\u308B\n\u73FE\u5728\u306E\u30DD\u30A4\u30F3\u30BF\u306E\u4F4D\u7F6E\
    \u304C\u3042\u308B\n\u3082\u3046\u5168\u90E8\u306E\u5024\u304C\u8AAD\u307E\u308C\
    \u305F subtree \u3067\u306F\u30BC\u30FC\u30BF\u3055\u308C\u305F\u72B6\u614B\u306B\
    \u3057\u3066\u304A\u304F\n*/\ntemplate <typename T>\nstruct Online_Subset_Zeta\
    \ {\n  int n;\n  int p = 0;\n  vc<T> A;\n  Online_Subset_Zeta(int LOG) : n(LOG),\
    \ A(1 << n) {}\n\n  // set a[i], return zeta(a)[i]\n  T set(int i, T a) {\n  \
    \  assert(p == i);\n    T ans = assume(i, 0) + a;\n    A[p++] = a;\n    int K\
    \ = lowbit(p);\n    for (int k = 0; k < K; ++k)\n      for (int j = p - (1 <<\
    \ k); j < p; ++j) A[j] += A[j - (1 << k)];\n    return ans;\n  }\n\n  // assume\
    \ a[i], return zeta(a)[i]. not increment the pointer.\n  T assume(int i, T ai)\
    \ {\n    assert(p == i);\n    T ans = ai;\n    // \u306A\u3093\u3068\u3053\u308C\
    \u3060\u3051\uFF1F\n    for (int j: all_bit<u32>(i)) ans += A[i - (1 << j)];\n\
    \    return ans;\n  }\n};\n"
  code: "/*\nsegtree \u3092\u8003\u3048\u308B\n\u73FE\u5728\u306E\u30DD\u30A4\u30F3\
    \u30BF\u306E\u4F4D\u7F6E\u304C\u3042\u308B\n\u3082\u3046\u5168\u90E8\u306E\u5024\
    \u304C\u8AAD\u307E\u308C\u305F subtree \u3067\u306F\u30BC\u30FC\u30BF\u3055\u308C\
    \u305F\u72B6\u614B\u306B\u3057\u3066\u304A\u304F\n*/\ntemplate <typename T>\n\
    struct Online_Subset_Zeta {\n  int n;\n  int p = 0;\n  vc<T> A;\n  Online_Subset_Zeta(int\
    \ LOG) : n(LOG), A(1 << n) {}\n\n  // set a[i], return zeta(a)[i]\n  T set(int\
    \ i, T a) {\n    assert(p == i);\n    T ans = assume(i, 0) + a;\n    A[p++] =\
    \ a;\n    int K = lowbit(p);\n    for (int k = 0; k < K; ++k)\n      for (int\
    \ j = p - (1 << k); j < p; ++j) A[j] += A[j - (1 << k)];\n    return ans;\n  }\n\
    \n  // assume a[i], return zeta(a)[i]. not increment the pointer.\n  T assume(int\
    \ i, T ai) {\n    assert(p == i);\n    T ans = ai;\n    // \u306A\u3093\u3068\u3053\
    \u308C\u3060\u3051\uFF1F\n    for (int j: all_bit<u32>(i)) ans += A[i - (1 <<\
    \ j)];\n    return ans;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/online/online_subset_zeta.hpp
  requiredBy: []
  timestamp: '2025-05-25 23:45:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/online/online_subset_zeta.hpp
layout: document
redirect_from:
- /library/setfunc/online/online_subset_zeta.hpp
- /library/setfunc/online/online_subset_zeta.hpp.html
title: setfunc/online/online_subset_zeta.hpp
---
