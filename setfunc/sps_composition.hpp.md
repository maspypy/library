---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  - icon: ':x:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
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
    path: graph/tutte_polynomial.hpp
    title: graph/tutte_polynomial.hpp
  - icon: ':warning:'
    path: setfunc/sps_log.hpp
    title: setfunc/sps_log.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/composition_sps.test.cpp
    title: test/2_library_checker/set_power_series/composition_sps.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/ranked_zeta.hpp\"\n\r\n#line 2 \"setfunc/bitwise_transform.hpp\"\
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
    \ bitwise\n#line 4 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate <typename T, int\
    \ LIM>\r\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\r\n  int n = topbit(len(f));\r\
    \n  assert(n <= LIM);\r\n  assert(len(f) == 1 << n);\r\n  vc<array<T, LIM + 1>>\
    \ Rf(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\
    \n  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);\r\n  return\
    \ Rf;\r\n}\r\n\r\ntemplate <typename T, int LIM>\r\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\r\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_mobius>(Rf);\r\
    \n  vc<T> f(len(Rf));\r\n  for (int s = 0; s < len(f); ++s) f[s] = Rf[s][popcnt(s)];\r\
    \n  return f;\r\n}\n#line 3 \"setfunc/sps_composition.hpp\"\n\n// sum_i f_i/i!\
    \ s^i, s^i is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ sps_composition_egf(vc<mint>& f, vc<mint>& s) {\n  const int N = topbit(len(s));\n\
    \  assert(len(s) == (1 << N) && s[0] == mint(0));\n  if (len(f) > N) f.resize(N\
    \ + 1);\n  int D = len(f) - 1;\n  using ARR = array<mint, LIM + 1>;\n  vvc<ARR>\
    \ zs(N);\n  FOR(i, N) { zs[i] = ranked_zeta<mint, LIM>({s.begin() + (1 << i),\
    \ s.begin() + (2 << i)}); }\n\n  // dp : (d/dt)^df(s) (d=D,D-1,...)\n  vc<mint>\
    \ dp(1 << (N - D));\n  dp[0] = f[D];\n  FOR_R(d, D) {\n    vc<mint> newdp(1 <<\
    \ (N - d));\n    newdp[0] = f[d];\n    vc<ARR> zdp = ranked_zeta<mint, LIM>(dp);\n\
    \    FOR(i, N - d) {\n      // zs[1<<i:2<<i], zdp[0:1<<i]\n      vc<ARR> znewdp(1\
    \ << i);\n      FOR(k, 1 << i) {\n        FOR(p, i + 1) FOR(q, i - p + 1) { znewdp[k][p\
    \ + q] += zdp[k][p] * zs[i][k][q]; }\n      }\n      auto x = ranked_mobius<mint,\
    \ LIM>(znewdp);\n      copy(all(x), newdp.begin() + (1 << i));\n    }\n    swap(dp,\
    \ newdp);\n  }\n  return dp;\n}\n\n// sum_i f_i s^i, s^i is subset-convolution\n\
    template <typename mint, int LIM>\nvc<mint> sps_composition_poly(vc<mint> f, vc<mint>\
    \ s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 << N));\n  if (f.empty())\
    \ return vc<mint>(1 << N, mint(0));\n  // convert to egf problem\n  int D = min<int>(len(f)\
    \ - 1, N);\n  vc<mint> g(D + 1);\n  mint c = s[0];\n  s[0] = 0;\n  // (x+c)^i\n\
    \  vc<mint> pow(D + 1);\n  pow[0] = 1;\n  FOR(i, len(f)) {\n    FOR(j, D + 1)\
    \ g[j] += f[i] * pow[j];\n    FOR_R(j, D + 1) pow[j] = pow[j] * c + (j == 0 ?\
    \ mint(0) : pow[j - 1]);\n  }\n  // to egf\n  mint factorial = 1;\n  FOR(j, D\
    \ + 1) g[j] *= factorial, factorial *= mint(j + 1);\n  return sps_composition_egf<mint,\
    \ LIM>(g, s);\n}\n"
  code: "#pragma once\n#include \"setfunc/ranked_zeta.hpp\"\n\n// sum_i f_i/i! s^i,\
    \ s^i is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint> sps_composition_egf(vc<mint>&\
    \ f, vc<mint>& s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 <<\
    \ N) && s[0] == mint(0));\n  if (len(f) > N) f.resize(N + 1);\n  int D = len(f)\
    \ - 1;\n  using ARR = array<mint, LIM + 1>;\n  vvc<ARR> zs(N);\n  FOR(i, N) {\
    \ zs[i] = ranked_zeta<mint, LIM>({s.begin() + (1 << i), s.begin() + (2 << i)});\
    \ }\n\n  // dp : (d/dt)^df(s) (d=D,D-1,...)\n  vc<mint> dp(1 << (N - D));\n  dp[0]\
    \ = f[D];\n  FOR_R(d, D) {\n    vc<mint> newdp(1 << (N - d));\n    newdp[0] =\
    \ f[d];\n    vc<ARR> zdp = ranked_zeta<mint, LIM>(dp);\n    FOR(i, N - d) {\n\
    \      // zs[1<<i:2<<i], zdp[0:1<<i]\n      vc<ARR> znewdp(1 << i);\n      FOR(k,\
    \ 1 << i) {\n        FOR(p, i + 1) FOR(q, i - p + 1) { znewdp[k][p + q] += zdp[k][p]\
    \ * zs[i][k][q]; }\n      }\n      auto x = ranked_mobius<mint, LIM>(znewdp);\n\
    \      copy(all(x), newdp.begin() + (1 << i));\n    }\n    swap(dp, newdp);\n\
    \  }\n  return dp;\n}\n\n// sum_i f_i s^i, s^i is subset-convolution\ntemplate\
    \ <typename mint, int LIM>\nvc<mint> sps_composition_poly(vc<mint> f, vc<mint>\
    \ s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 << N));\n  if (f.empty())\
    \ return vc<mint>(1 << N, mint(0));\n  // convert to egf problem\n  int D = min<int>(len(f)\
    \ - 1, N);\n  vc<mint> g(D + 1);\n  mint c = s[0];\n  s[0] = 0;\n  // (x+c)^i\n\
    \  vc<mint> pow(D + 1);\n  pow[0] = 1;\n  FOR(i, len(f)) {\n    FOR(j, D + 1)\
    \ g[j] += f[i] * pow[j];\n    FOR_R(j, D + 1) pow[j] = pow[j] * c + (j == 0 ?\
    \ mint(0) : pow[j - 1]);\n  }\n  // to egf\n  mint factorial = 1;\n  FOR(j, D\
    \ + 1) g[j] *= factorial, factorial *= mint(j + 1);\n  return sps_composition_egf<mint,\
    \ LIM>(g, s);\n}\n"
  dependsOn:
  - setfunc/ranked_zeta.hpp
  - setfunc/bitwise_transform.hpp
  isVerificationFile: false
  path: setfunc/sps_composition.hpp
  requiredBy:
  - graph/count/count_bridgeless_subgraph.hpp
  - graph/count/count_biconnected_subgraph.hpp
  - graph/count/count_connected_subgraph.hpp
  - graph/tutte_polynomial.hpp
  - setfunc/sps_log.hpp
  timestamp: '2026-07-26 16:27:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/set_power_series/composition_sps.test.cpp
documentation_of: setfunc/sps_composition.hpp
layout: document
redirect_from:
- /library/setfunc/sps_composition.hpp
- /library/setfunc/sps_composition.hpp.html
title: setfunc/sps_composition.hpp
---
