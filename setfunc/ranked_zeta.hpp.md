---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/chromatic.hpp
    title: graph/chromatic.hpp
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
  - icon: ':x:'
    path: linalg/hafnian.hpp
    title: linalg/hafnian.hpp
  - icon: ':x:'
    path: setfunc/power_projection_of_sps.hpp
    title: setfunc/power_projection_of_sps.hpp
  - icon: ':x:'
    path: setfunc/sps_composition.hpp
    title: setfunc/sps_composition.hpp
  - icon: ':x:'
    path: setfunc/sps_exp.hpp
    title: setfunc/sps_exp.hpp
  - icon: ':warning:'
    path: setfunc/sps_inv.hpp
    title: setfunc/sps_inv.hpp
  - icon: ':warning:'
    path: setfunc/sps_log.hpp
    title: setfunc/sps_log.hpp
  - icon: ':x:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/graph/chromatic_number.test.cpp
    title: test/2_library_checker/graph/chromatic_number.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/chromatic_polynomial.test.cpp
    title: test/2_library_checker/graph/chromatic_polynomial.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/composition_sps.test.cpp
    title: test/2_library_checker/set_power_series/composition_sps.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
    title: test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/powproj_sps.test.cpp
    title: test/2_library_checker/set_power_series/powproj_sps.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/sps_exp.test.cpp
    title: test/2_library_checker/set_power_series/sps_exp.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/subset_convolution.test.cpp
    title: test/2_library_checker/set_power_series/subset_convolution.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2507.test.cpp
    title: test/3_yukicoder/2507.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/ranked_zeta.hpp\"\n\n#line 1 \"setfunc/bitwise_transform.hpp\"\
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
    \ bitwise\n#line 3 \"setfunc/ranked_zeta.hpp\"\n\ntemplate <typename T, int LIM>\n\
    vc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\n  int n = topbit(len(f));\n\
    \  assert(n <= LIM);\n  assert(len(f) == 1 << n);\n  vc<array<T, LIM + 1>> Rf(1\
    \ << n);\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);\n\
    \  return Rf;\n}\n\ntemplate <typename T, int LIM>\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_mobius>(Rf);\n\
    \  vc<T> f(len(Rf));\n  for (int s = 0; s < len(f); ++s) f[s] = Rf[s][popcnt(s)];\n\
    \  return f;\n}\n"
  code: "\n#include \"setfunc/bitwise_transform.hpp\"\n\ntemplate <typename T, int\
    \ LIM>\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\n  int n = topbit(len(f));\n\
    \  assert(n <= LIM);\n  assert(len(f) == 1 << n);\n  vc<array<T, LIM + 1>> Rf(1\
    \ << n);\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);\n\
    \  return Rf;\n}\n\ntemplate <typename T, int LIM>\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_mobius>(Rf);\n\
    \  vc<T> f(len(Rf));\n  for (int s = 0; s < len(f); ++s) f[s] = Rf[s][popcnt(s)];\n\
    \  return f;\n}"
  dependsOn:
  - setfunc/bitwise_transform.hpp
  isVerificationFile: false
  path: setfunc/ranked_zeta.hpp
  requiredBy:
  - linalg/hafnian.hpp
  - graph/count/count_bridgeless_subgraph.hpp
  - graph/count/count_biconnected_subgraph.hpp
  - graph/count/count_connected_subgraph.hpp
  - graph/count/count_tree_subgraph.hpp
  - graph/chromatic.hpp
  - graph/tutte_polynomial.hpp
  - setfunc/power_projection_of_sps.hpp
  - setfunc/sps_composition.hpp
  - setfunc/subset_convolution.hpp
  - setfunc/sps_exp.hpp
  - setfunc/sps_log.hpp
  - setfunc/sps_inv.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/graph/chromatic_polynomial.test.cpp
  - test/2_library_checker/graph/chromatic_number.test.cpp
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - test/2_library_checker/set_power_series/composition_sps.test.cpp
  - test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
  - test/2_library_checker/set_power_series/powproj_sps.test.cpp
  - test/2_library_checker/set_power_series/sps_exp.test.cpp
  - test/2_library_checker/set_power_series/subset_convolution.test.cpp
  - test/3_yukicoder/2507.test.cpp
documentation_of: setfunc/ranked_zeta.hpp
layout: document
redirect_from:
- /library/setfunc/ranked_zeta.hpp
- /library/setfunc/ranked_zeta.hpp.html
title: setfunc/ranked_zeta.hpp
---
