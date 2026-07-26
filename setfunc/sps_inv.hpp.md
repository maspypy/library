---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  - icon: ':x:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \n  return f;\r\n}\n#line 2 \"setfunc/sps_inv.hpp\"\n\ntemplate <typename mint,\
    \ int LIM>\nvc<mint> sps_inv(vc<mint>& dp) {\n  const int N = topbit(len(dp));\n\
    \  assert(len(dp) == (1 << N) && dp[0] == mint(1));\n  auto RA = ranked_zeta<mint,\
    \ LIM>(dp);\n  array<mint, LIM + 1> g;\n  FOR(s, 1 << N) {\n    auto& f = RA[s];\n\
    \    g[0] = 1;\n    FOR(k, 1, N + 1) {\n      g[k] = 0;\n      FOR(i, k) g[k]\
    \ -= g[i] * f[k - i];\n    }\n    RA[s] = g;\n  }\n  return ranked_mobius<mint,\
    \ LIM>(RA);\n}\n"
  code: "#include \"setfunc/ranked_zeta.hpp\"\n\ntemplate <typename mint, int LIM>\n\
    vc<mint> sps_inv(vc<mint>& dp) {\n  const int N = topbit(len(dp));\n  assert(len(dp)\
    \ == (1 << N) && dp[0] == mint(1));\n  auto RA = ranked_zeta<mint, LIM>(dp);\n\
    \  array<mint, LIM + 1> g;\n  FOR(s, 1 << N) {\n    auto& f = RA[s];\n    g[0]\
    \ = 1;\n    FOR(k, 1, N + 1) {\n      g[k] = 0;\n      FOR(i, k) g[k] -= g[i]\
    \ * f[k - i];\n    }\n    RA[s] = g;\n  }\n  return ranked_mobius<mint, LIM>(RA);\n\
    }\n"
  dependsOn:
  - setfunc/ranked_zeta.hpp
  - setfunc/bitwise_transform.hpp
  isVerificationFile: false
  path: setfunc/sps_inv.hpp
  requiredBy: []
  timestamp: '2026-07-26 16:27:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/sps_inv.hpp
layout: document
redirect_from:
- /library/setfunc/sps_inv.hpp
- /library/setfunc/sps_inv.hpp.html
title: setfunc/sps_inv.hpp
---
