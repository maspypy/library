---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  - icon: ':question:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':question:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/count/count_bridgeless_subgraph.hpp
    title: graph/count/count_bridgeless_subgraph.hpp
  - icon: ':warning:'
    path: graph/count/count_tree_subgraph.hpp
    title: graph/count/count_tree_subgraph.hpp
  - icon: ':warning:'
    path: graph/tutte_polynomial.hpp
    title: graph/tutte_polynomial.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/hafnian.hpp
    title: linalg/hafnian.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/set_power_series/sps_exp.test.cpp
    title: test/2_library_checker/set_power_series/sps_exp.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2507.test.cpp
    title: test/3_yukicoder/2507.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/sps_exp.hpp\"\n\n#line 2 \"setfunc/subset_convolution.hpp\"\
    \n\r\n#line 2 \"setfunc/ranked_zeta.hpp\"\n\r\n#line 2 \"setfunc/bitwise_transform.hpp\"\
    \n\nnamespace bitwise {\n\nenum class trans_type {\n  hadamard,\n  superset_zeta,\n\
    \  superset_mobius,\n  subset_zeta,\n  subset_mobius,\n  ranked_zeta,\n  ranked_mobius\n\
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
    \ ++i) ranked_sub(a[H + i], a[i]);\n    }\n  }\n}\n\ntemplate <trans_type type,\
    \ int N, typename T>\ninline void bitwise_transform_dispatch(vc<T>& a) {\n  if\
    \ (len(a) == N) {\n    return bitwise_transform_fixed<type, N>(a.data());\n  }\n\
    \  if constexpr (N > 1) {\n    return bitwise_transform_dispatch<type, N / 2>(a);\n\
    \  }\n}\n\ntemplate <trans_type type, typename T>\ninline void bitwise_transform(vc<T>&\
    \ a) {\n  int n = len(a);\n  assert(n >= 1);\n  assert((n & (n - 1)) == 0);\n\
    \  assert(n <= (1 << 25));\n  bitwise_transform_dispatch<type, 1 << 25>(a);\n\
    }\n}  // namespace bitwise\n#line 4 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate\
    \ <typename T, int LIM>\r\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\r\
    \n  int n = topbit(len(f));\r\n  assert(n <= LIM);\r\n  assert(len(f) == 1 <<\
    \ n);\r\n  vc<array<T, LIM + 1>> Rf(1 << n);\r\n  for (int s = 0; s < (1 << n);\
    \ ++s) Rf[s][popcnt(s)] = f[s];\r\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);\r\
    \n  return Rf;\r\n}\r\n\r\ntemplate <typename T, int LIM>\r\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\r\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_mobius>(Rf);\r\
    \n  vc<T> f(len(Rf));\r\n  for (int s = 0; s < len(f); ++s) f[s] = Rf[s][popcnt(s)];\r\
    \n  return f;\r\n}\n#line 4 \"setfunc/subset_convolution.hpp\"\n\r\ntemplate <typename\
    \ T, int LIM = 20>\r\nvc<T> subset_convolution_square(const vc<T>& A) {\r\n  auto\
    \ RA = ranked_zeta<T, LIM>(A);\r\n  int n = topbit(len(RA));\r\n  FOR(s, len(RA))\
    \ {\r\n    auto& f = RA[s];\r\n    FOR_R(d, n + 1) {\r\n      T x = 0;\r\n   \
    \   FOR(i, d + 1) x += f[i] * f[d - i];\r\n      f[d] = x;\r\n    }\r\n  }\r\n\
    \  return ranked_mobius<T, LIM>(RA);\r\n}\r\n\r\ntemplate <typename T, int LIM\
    \ = 20>\r\nvc<T> subset_convolution(const vc<T>& A, const vc<T>& B) {\r\n  if\
    \ (A == B) return subset_convolution_square(A);\r\n  auto RA = ranked_zeta<T,\
    \ LIM>(A);\r\n  auto RB = ranked_zeta<T, LIM>(B);\r\n  int n = topbit(len(RA));\r\
    \n  FOR(s, len(RA)) {\r\n    auto &f = RA[s], &g = RB[s];\r\n    FOR_R(d, n +\
    \ 1) {\r\n      T x = 0;\r\n      FOR(i, d + 1) x += f[i] * g[d - i];\r\n    \
    \  f[d] = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T, LIM>(RA);\r\n}\r\n#line\
    \ 4 \"setfunc/sps_exp.hpp\"\n\n// sum_i 1/i! s^i, s^i is subset-convolution\n\
    template <typename mint, int LIM>\nvc<mint> sps_exp(vc<mint>& s) {\n  const int\
    \ N = topbit(len(s));\n  assert(len(s) == (1 << N) && s[0] == mint(0));\n  vc<mint>\
    \ dp(1 << N);\n  dp[0] = mint(1);\n  FOR(i, N) {\n    vc<mint> a = {s.begin()\
    \ + (1 << i), s.begin() + (2 << i)};\n    vc<mint> b = {dp.begin(), dp.begin()\
    \ + (1 << i)};\n    a = subset_convolution<mint, LIM>(a, b);\n    copy(all(a),\
    \ dp.begin() + (1 << i));\n  }\n  return dp;\n}\n"
  code: "#pragma once\n\n#include \"setfunc/subset_convolution.hpp\"\n\n// sum_i 1/i!\
    \ s^i, s^i is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ sps_exp(vc<mint>& s) {\n  const int N = topbit(len(s));\n  assert(len(s) ==\
    \ (1 << N) && s[0] == mint(0));\n  vc<mint> dp(1 << N);\n  dp[0] = mint(1);\n\
    \  FOR(i, N) {\n    vc<mint> a = {s.begin() + (1 << i), s.begin() + (2 << i)};\n\
    \    vc<mint> b = {dp.begin(), dp.begin() + (1 << i)};\n    a = subset_convolution<mint,\
    \ LIM>(a, b);\n    copy(all(a), dp.begin() + (1 << i));\n  }\n  return dp;\n}\n"
  dependsOn:
  - setfunc/subset_convolution.hpp
  - setfunc/ranked_zeta.hpp
  - setfunc/bitwise_transform.hpp
  isVerificationFile: false
  path: setfunc/sps_exp.hpp
  requiredBy:
  - linalg/hafnian.hpp
  - graph/count/count_bridgeless_subgraph.hpp
  - graph/count/count_tree_subgraph.hpp
  - graph/tutte_polynomial.hpp
  timestamp: '2026-06-15 22:08:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2507.test.cpp
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - test/2_library_checker/set_power_series/sps_exp.test.cpp
documentation_of: setfunc/sps_exp.hpp
layout: document
redirect_from:
- /library/setfunc/sps_exp.hpp
- /library/setfunc/sps_exp.hpp.html
title: setfunc/sps_exp.hpp
---
