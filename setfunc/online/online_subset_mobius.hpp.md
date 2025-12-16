---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
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
  bundledCode: "#line 1 \"enumerate/bits.hpp\"\ntemplate <typename BS, typename F>\n\
    void enumerate_bits_bitset(BS& b, int L, int R, F&& f) {\n  if (L >= len(b)) return;\n\
    \  int p = (b[L] ? L : b._Find_next(L));\n  while (p < R) {\n    f(p);\n    p\
    \ = b._Find_next(p);\n  }\n}\n\ntemplate <typename UINT, typename F>\ninline void\
    \ enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n#line 2 \"setfunc/online/online_subset_mobius.hpp\"\
    \n\ntemplate <typename T>\nstruct Online_Subset_Mobius {\n  int n;\n  int p =\
    \ 0;\n  vc<T> A;\n  Online_Subset_Mobius(int LOG) : n(LOG), A(1 << n) {}\n\n \
    \ // set a[i], return zeta(a)[i]\n  T set(int i, T a) {\n    assert(p == i);\n\
    \    T ans = assume(i, 0) + a;\n    A[p++] = a;\n    int K = lowbit(p);\n    for\
    \ (int k = 0; k < K; ++k)\n      for (int j = p - (1 << k); j < p; ++j) A[j] -=\
    \ A[j - (1 << k)];\n    return ans;\n  }\n\n  // assume a[i], return zeta(a)[i].\
    \ not increment the pointer.\n  T assume(int i, T ai) {\n    assert(p == i);\n\
    \    T ans = ai;\n    enumerate_all_bit<u32>(i, [&](int j) -> vood { ans -= A[i\
    \ - (1 << j)]; });\n    return ans;\n  }\n};\n"
  code: "#include \"enumerate/bits.hpp\"\n\ntemplate <typename T>\nstruct Online_Subset_Mobius\
    \ {\n  int n;\n  int p = 0;\n  vc<T> A;\n  Online_Subset_Mobius(int LOG) : n(LOG),\
    \ A(1 << n) {}\n\n  // set a[i], return zeta(a)[i]\n  T set(int i, T a) {\n  \
    \  assert(p == i);\n    T ans = assume(i, 0) + a;\n    A[p++] = a;\n    int K\
    \ = lowbit(p);\n    for (int k = 0; k < K; ++k)\n      for (int j = p - (1 <<\
    \ k); j < p; ++j) A[j] -= A[j - (1 << k)];\n    return ans;\n  }\n\n  // assume\
    \ a[i], return zeta(a)[i]. not increment the pointer.\n  T assume(int i, T ai)\
    \ {\n    assert(p == i);\n    T ans = ai;\n    enumerate_all_bit<u32>(i, [&](int\
    \ j) -> vood { ans -= A[i - (1 << j)]; });\n    return ans;\n  }\n};\n"
  dependsOn:
  - enumerate/bits.hpp
  isVerificationFile: false
  path: setfunc/online/online_subset_mobius.hpp
  requiredBy:
  - setfunc/online/online_or_convolution.hpp
  timestamp: '2025-12-16 20:51:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/online/online_subset_mobius.hpp
layout: document
redirect_from:
- /library/setfunc/online/online_subset_mobius.hpp
- /library/setfunc/online/online_subset_mobius.hpp.html
title: setfunc/online/online_subset_mobius.hpp
---
