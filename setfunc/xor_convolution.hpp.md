---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/hadamard.hpp
    title: setfunc/hadamard.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/2_library_checker/convolution/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1142.test.cpp
    title: test/3_yukicoder/1142.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/hadamard.hpp\"\n\r\n#line 2 \"setfunc/bitwise_transform.hpp\"\
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
    \ bitwise\n#line 4 \"setfunc/hadamard.hpp\"\n\r\n// B[j] = sum_i (-1)^{popcnt(i&j)}\
    \ A[i]\r\n// len(A) \u306F 2^25 \u4EE5\u4E0B\u306E 2 \u51AA\u3092\u4EEE\u5B9A\u3002\
    2^k \u3067\u5272\u308B\u3053\u3068\u306F\u3057\u3066\u3044\u306A\u3044\u3002\r\
    \ntemplate <typename T>\r\nvoid hadamard(vc<T>& A) {\r\n  bitwise::bitwise_transform<bitwise::trans_type::hadamard>(A);\r\
    \n}\r\n#line 2 \"setfunc/xor_convolution.hpp\"\n\r\ntemplate <typename T>\r\n\
    vc<T> xor_convolution(vc<T> A, vc<T> B) {\r\n  hadamard(A);\r\n  hadamard(B);\r\
    \n  FOR(i, len(A)) A[i] *= B[i];\r\n  hadamard(A);\r\n\r\n  T c = T(1) / T(len(A));\r\
    \n  if (c != T(0)) {\r\n    FOR(i, len(A)) A[i] *= c;\r\n  } else {\r\n    FOR(i,\
    \ len(A)) A[i] /= len(A);\r\n  }\r\n  return A;\r\n}\r\n"
  code: "#include \"setfunc/hadamard.hpp\"\r\n\r\ntemplate <typename T>\r\nvc<T> xor_convolution(vc<T>\
    \ A, vc<T> B) {\r\n  hadamard(A);\r\n  hadamard(B);\r\n  FOR(i, len(A)) A[i] *=\
    \ B[i];\r\n  hadamard(A);\r\n\r\n  T c = T(1) / T(len(A));\r\n  if (c != T(0))\
    \ {\r\n    FOR(i, len(A)) A[i] *= c;\r\n  } else {\r\n    FOR(i, len(A)) A[i]\
    \ /= len(A);\r\n  }\r\n  return A;\r\n}\r\n"
  dependsOn:
  - setfunc/hadamard.hpp
  - setfunc/bitwise_transform.hpp
  isVerificationFile: false
  path: setfunc/xor_convolution.hpp
  requiredBy: []
  timestamp: '2026-07-26 16:27:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1142.test.cpp
  - test/2_library_checker/convolution/bitwise_xor_convolution.test.cpp
documentation_of: setfunc/xor_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/xor_convolution.hpp
- /library/setfunc/xor_convolution.hpp.html
title: setfunc/xor_convolution.hpp
---
