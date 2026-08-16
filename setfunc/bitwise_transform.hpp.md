---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/count/count_biconnected_subgraph.hpp
    title: graph/count/count_biconnected_subgraph.hpp
  - icon: ':warning:'
    path: graph/count/count_bridgeless_subgraph.hpp
    title: graph/count/count_bridgeless_subgraph.hpp
  - icon: ':warning:'
    path: graph/count/count_connected_subgraph.hpp
    title: graph/count/count_connected_subgraph.hpp
  - icon: ':warning:'
    path: graph/count/count_tree_subgraph.hpp
    title: graph/count/count_tree_subgraph.hpp
  - icon: ':warning:'
    path: graph/tutte_polynomial.hpp
    title: graph/tutte_polynomial.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/hafnian.hpp
    title: linalg/hafnian.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/and_convolution.hpp
    title: setfunc/and_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/hadamard.hpp
    title: setfunc/hadamard.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/or_convolution.hpp
    title: setfunc/or_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/power_projection_of_sps.hpp
    title: setfunc/power_projection_of_sps.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/sps_composition.hpp
    title: setfunc/sps_composition.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/sps_exp.hpp
    title: setfunc/sps_exp.hpp
  - icon: ':warning:'
    path: setfunc/sps_inv.hpp
    title: setfunc/sps_inv.hpp
  - icon: ':warning:'
    path: setfunc/sps_log.hpp
    title: setfunc/sps_log.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/xor_convolution.hpp
    title: setfunc/xor_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/zeta.hpp
    title: setfunc/zeta.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/bitwise_or_convolution.test.cpp
    title: test/2_library_checker/convolution/bitwise_or_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/2_library_checker/convolution/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/set_power_series/composition_sps.test.cpp
    title: test/2_library_checker/set_power_series/composition_sps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
    title: test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/set_power_series/powproj_sps.test.cpp
    title: test/2_library_checker/set_power_series/powproj_sps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/set_power_series/sps_exp.test.cpp
    title: test/2_library_checker/set_power_series/sps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/set_power_series/subset_convolution.test.cpp
    title: test/2_library_checker/set_power_series/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1142.test.cpp
    title: test/3_yukicoder/1142.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1753.test.cpp
    title: test/3_yukicoder/1753.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2507.test.cpp
    title: test/3_yukicoder/2507.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/bitwise_transform.hpp\"\n\nnamespace bitwise {\n\
    \nenum class trans_type {\n  hadamard,\n  superset_zeta,\n  superset_mobius,\n\
    \  subset_zeta,\n  subset_mobius,\n  ranked_zeta,\n  ranked_mobius,\n  superset_zeta_or\n\
    };\n\ntemplate <typename ARR>\ninline void ranked_add(ARR& a, const ARR& b) {\n\
    \  for (int d = 0; d < int(a.size()); ++d) a[d] += b[d];\n}\n\ntemplate <typename\
    \ ARR>\ninline void ranked_sub(ARR& a, const ARR& b) {\n  for (int d = 0; d <\
    \ int(a.size()); ++d) a[d] -= b[d];\n}\n\ntemplate <trans_type type, int N, typename\
    \ T>\ninline void bitwise_transform_fixed(T* a) {\n  static_assert(N >= 1 && (N\
    \ & (N - 1)) == 0);\n  if constexpr (N == 1) {\n    return;\n  } else {\n    constexpr\
    \ int H = N / 2;\n    bitwise_transform_fixed<type, H>(a);\n    bitwise_transform_fixed<type,\
    \ H>(a + H);\n    if constexpr (type == trans_type::hadamard) {\n      for (int\
    \ i = 0; i < H; ++i) {\n        auto x = a[i], y = a[H + i];\n        a[i] = x\
    \ + y, a[H + i] = x - y;\n      }\n    }\n    if constexpr (type == trans_type::superset_zeta)\
    \ {\n      for (int i = 0; i < H; ++i) a[i] += a[H + i];\n    }\n    if constexpr\
    \ (type == trans_type::superset_mobius) {\n      for (int i = 0; i < H; ++i) a[i]\
    \ -= a[H + i];\n    }\n    if constexpr (type == trans_type::subset_zeta) {\n\
    \      for (int i = 0; i < H; ++i) a[H + i] += a[i];\n    }\n    if constexpr\
    \ (type == trans_type::subset_mobius) {\n      for (int i = 0; i < H; ++i) a[H\
    \ + i] -= a[i];\n    }\n    if constexpr (type == trans_type::ranked_zeta) {\n\
    \      for (int i = 0; i < H; ++i) ranked_add(a[H + i], a[i]);\n    }\n    if\
    \ constexpr (type == trans_type::ranked_mobius) {\n      for (int i = 0; i < H;\
    \ ++i) ranked_sub(a[H + i], a[i]);\n    }\n    if constexpr (type == trans_type::superset_zeta_or)\
    \ {\n      for (int i = 0; i < H; ++i) a[i] |= a[H + i];\n    }\n  }\n}\n\ntemplate\
    \ <trans_type type, int N, typename T>\ninline void bitwise_transform_dispatch(vc<T>&\
    \ a) {\n  if (len(a) == N) {\n    return bitwise_transform_fixed<type, N>(a.data());\n\
    \  }\n  if constexpr (N > 1) {\n    return bitwise_transform_dispatch<type, N\
    \ / 2>(a);\n  }\n}\n\ntemplate <trans_type type, typename T>\ninline void bitwise_transform(vc<T>&\
    \ a) {\n  int n = len(a);\n  assert(n >= 1);\n  assert((n & (n - 1)) == 0);\n\
    \  assert(n <= (1 << 25));\n  bitwise_transform_dispatch<type, 1 << 25>(a);\n\
    }\n}  // namespace bitwise\n"
  code: "\nnamespace bitwise {\n\nenum class trans_type {\n  hadamard,\n  superset_zeta,\n\
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
    \ bitwise\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/bitwise_transform.hpp
  requiredBy:
  - linalg/hafnian.hpp
  - graph/count/count_bridgeless_subgraph.hpp
  - graph/count/count_biconnected_subgraph.hpp
  - graph/count/count_connected_subgraph.hpp
  - graph/count/count_tree_subgraph.hpp
  - graph/tutte_polynomial.hpp
  - setfunc/power_projection_of_sps.hpp
  - setfunc/zeta.hpp
  - setfunc/or_convolution.hpp
  - setfunc/hadamard.hpp
  - setfunc/sps_composition.hpp
  - setfunc/xor_convolution.hpp
  - setfunc/ranked_zeta.hpp
  - setfunc/and_convolution.hpp
  - setfunc/subset_convolution.hpp
  - setfunc/sps_exp.hpp
  - setfunc/sps_log.hpp
  - setfunc/sps_inv.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/convolution/bitwise_or_convolution.test.cpp
  - test/2_library_checker/convolution/bitwise_xor_convolution.test.cpp
  - test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - test/2_library_checker/set_power_series/composition_sps.test.cpp
  - test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
  - test/2_library_checker/set_power_series/powproj_sps.test.cpp
  - test/2_library_checker/set_power_series/sps_exp.test.cpp
  - test/2_library_checker/set_power_series/subset_convolution.test.cpp
  - test/3_yukicoder/1753.test.cpp
  - test/3_yukicoder/1142.test.cpp
  - test/3_yukicoder/2507.test.cpp
documentation_of: setfunc/bitwise_transform.hpp
layout: document
redirect_from:
- /library/setfunc/bitwise_transform.hpp
- /library/setfunc/bitwise_transform.hpp.html
title: setfunc/bitwise_transform.hpp
---
