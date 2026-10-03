---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/zeta.hpp
    title: setfunc/zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/zeta.hpp\"\n\n#line 1 \"setfunc/bitwise_transform.hpp\"\
    \n\nnamespace bitwise {\n\nenum class trans_type {\n  hadamard,\n  superset_zeta,\n\
    \  superset_mobius,\n  subset_zeta,\n  subset_mobius,\n  ranked_zeta,\n  ranked_mobius,\n\
    \  superset_zeta_or\n};\n\ntemplate <typename ARR>\ninline void ranked_add(ARR&\
    \ a, const ARR& b) {\n  for (int d = 0; d < int(a.size()); ++d) a[d] += b[d];\n\
    }\n\ntemplate <typename ARR>\ninline void ranked_sub(ARR& a, const ARR& b) {\n\
    \  for (int d = 0; d < int(a.size()); ++d) a[d] -= b[d];\n}\n\ntemplate <trans_type\
    \ type, int N, typename T>\ninline void bitwise_transform_fixed(T* a) {\n  static_assert(N\
    \ >= 1 && (N & (N - 1)) == 0);\n  if constexpr (N == 1) {\n    return;\n  } else\
    \ {\n    constexpr int H = N / 2;\n    bitwise_transform_fixed<type, H>(a);\n\
    \    bitwise_transform_fixed<type, H>(a + H);\n    if constexpr (type == trans_type::hadamard)\
    \ {\n      for (int i = 0; i < H; ++i) {\n        auto x = a[i], y = a[H + i];\n\
    \        a[i] = x + y, a[H + i] = x - y;\n      }\n    }\n    if constexpr (type\
    \ == trans_type::superset_zeta) {\n      for (int i = 0; i < H; ++i) a[i] += a[H\
    \ + i];\n    }\n    if constexpr (type == trans_type::superset_mobius) {\n   \
    \   for (int i = 0; i < H; ++i) a[i] -= a[H + i];\n    }\n    if constexpr (type\
    \ == trans_type::subset_zeta) {\n      for (int i = 0; i < H; ++i) a[H + i] +=\
    \ a[i];\n    }\n    if constexpr (type == trans_type::subset_mobius) {\n     \
    \ for (int i = 0; i < H; ++i) a[H + i] -= a[i];\n    }\n    if constexpr (type\
    \ == trans_type::ranked_zeta) {\n      for (int i = 0; i < H; ++i) ranked_add(a[H\
    \ + i], a[i]);\n    }\n    if constexpr (type == trans_type::ranked_mobius) {\n\
    \      for (int i = 0; i < H; ++i) ranked_sub(a[H + i], a[i]);\n    }\n    if\
    \ constexpr (type == trans_type::superset_zeta_or) {\n      for (int i = 0; i\
    \ < H; ++i) a[i] |= a[H + i];\n    }\n  }\n}\n\ntemplate <trans_type type, int\
    \ N, typename T>\ninline void bitwise_transform_dispatch(vc<T>& a) {\n  if (len(a)\
    \ == N) {\n    return bitwise_transform_fixed<type, N>(a.data());\n  }\n  if constexpr\
    \ (N > 1) {\n    return bitwise_transform_dispatch<type, N / 2>(a);\n  }\n}\n\n\
    template <trans_type type, typename T>\ninline void bitwise_transform(vc<T>& a)\
    \ {\n  int n = len(a);\n  assert(n >= 1);\n  assert((n & (n - 1)) == 0);\n  assert(n\
    \ <= (1 << 25));\n  bitwise_transform_dispatch<type, 1 << 25>(a);\n}\n}  // namespace\
    \ bitwise\n#line 3 \"setfunc/zeta.hpp\"\n\ntemplate <typename T>\nvoid superset_zeta(vc<T>&\
    \ a) {\n  bitwise::bitwise_transform<bitwise::trans_type::superset_zeta>(a);\n\
    }\n\ntemplate <typename T>\nvoid superset_mobius(vc<T>& a) {\n  bitwise::bitwise_transform<bitwise::trans_type::superset_mobius>(a);\n\
    }\n\ntemplate <typename T>\nvoid subset_zeta(vc<T>& a) {\n  bitwise::bitwise_transform<bitwise::trans_type::subset_zeta>(a);\n\
    }\n\ntemplate <typename T>\nvoid subset_mobius(vc<T>& a) {\n  bitwise::bitwise_transform<bitwise::trans_type::subset_mobius>(a);\n\
    }\n#line 2 \"setfunc/and_convolution.hpp\"\ntemplate <typename T>\r\nvc<T> and_convolution(vc<T>\
    \ A, vc<T> B) {\r\n  superset_zeta(A);\r\n  superset_zeta(B);\r\n  FOR(i, len(A))\
    \ A[i] *= B[i];\r\n  superset_mobius(A);\r\n  return A;\r\n}\r\n"
  code: "#include \"setfunc/zeta.hpp\"\r\ntemplate <typename T>\r\nvc<T> and_convolution(vc<T>\
    \ A, vc<T> B) {\r\n  superset_zeta(A);\r\n  superset_zeta(B);\r\n  FOR(i, len(A))\
    \ A[i] *= B[i];\r\n  superset_mobius(A);\r\n  return A;\r\n}\r\n"
  dependsOn:
  - setfunc/zeta.hpp
  - setfunc/bitwise_transform.hpp
  isVerificationFile: false
  path: setfunc/and_convolution.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
documentation_of: setfunc/and_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/and_convolution.hpp
- /library/setfunc/and_convolution.hpp.html
title: setfunc/and_convolution.hpp
---
