---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: setfunc/online/online_or_convolution.hpp
    title: setfunc/online/online_or_convolution.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/online/online_subset_mobius.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Online_Subset_Mobius {\n  int n;\n  int p = 0;\n  vc<T> A;\n  Online_Subset_Mobius(int\
    \ LOG) : n(LOG), A(1 << n) {}\n\n  // set a[i], return zeta(a)[i]\n  T set(int\
    \ i, T a) {\n    assert(p == i);\n    T ans = assume(i, 0) + a;\n    A[p++] =\
    \ a;\n    int K = lowbit(p);\n    for (int k = 0; k < K; ++k)\n      for (int\
    \ j = p - (1 << k); j < p; ++j) A[j] -= A[j - (1 << k)];\n    return ans;\n  }\n\
    \n  // assume a[i], return zeta(a)[i]. not increment the pointer.\n  T assume(int\
    \ i, T ai) {\n    assert(p == i);\n    T ans = ai;\n    for (int j: all_bit<u32>(i))\
    \ ans -= A[i - (1 << j)];\n    return ans;\n  }\n};\n"
  code: "\ntemplate <typename T>\nstruct Online_Subset_Mobius {\n  int n;\n  int p\
    \ = 0;\n  vc<T> A;\n  Online_Subset_Mobius(int LOG) : n(LOG), A(1 << n) {}\n\n\
    \  // set a[i], return zeta(a)[i]\n  T set(int i, T a) {\n    assert(p == i);\n\
    \    T ans = assume(i, 0) + a;\n    A[p++] = a;\n    int K = lowbit(p);\n    for\
    \ (int k = 0; k < K; ++k)\n      for (int j = p - (1 << k); j < p; ++j) A[j] -=\
    \ A[j - (1 << k)];\n    return ans;\n  }\n\n  // assume a[i], return zeta(a)[i].\
    \ not increment the pointer.\n  T assume(int i, T ai) {\n    assert(p == i);\n\
    \    T ans = ai;\n    for (int j: all_bit<u32>(i)) ans -= A[i - (1 << j)];\n \
    \   return ans;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/online/online_subset_mobius.hpp
  requiredBy:
  - setfunc/online/online_or_convolution.hpp
  timestamp: '2025-05-25 23:45:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/online/online_subset_mobius.hpp
layout: document
redirect_from:
- /library/setfunc/online/online_subset_mobius.hpp
- /library/setfunc/online/online_subset_mobius.hpp.html
title: setfunc/online/online_subset_mobius.hpp
---
