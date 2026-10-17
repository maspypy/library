---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  - icon: ':x:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  - icon: ':x:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':x:'
    path: setfunc/sps_exp.hpp
    title: setfunc/sps_exp.hpp
  - icon: ':x:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/linalg/hafnian.hpp
  bundledCode: "#line 1 \"linalg/hafnian.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/linalg/hafnian.hpp\n\
    #line 1 \"setfunc/sps_exp.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/setfunc/sps_exp.hpp\n\
    \n#line 1 \"setfunc/subset_convolution.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/setfunc/subset_convolution.hpp\n\
    #line 1 \"setfunc/ranked_zeta.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/setfunc/ranked_zeta.hpp\n\
    \n#line 1 \"setfunc/bitwise_transform.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/setfunc/bitwise_transform.hpp\n\
    \nnamespace bitwise {\n\nenum class trans_type {\n  hadamard,\n  superset_zeta,\n\
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
    \ bitwise\n#line 4 \"setfunc/ranked_zeta.hpp\"\n\ntemplate <typename T, int LIM>\n\
    vc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\n  int n = topbit(len(f));\n\
    \  assert(n <= LIM);\n  assert(len(f) == 1 << n);\n  vc<array<T, LIM + 1>> Rf(1\
    \ << n);\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);\n\
    \  return Rf;\n}\n\ntemplate <typename T, int LIM>\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_mobius>(Rf);\n\
    \  vc<T> f(len(Rf));\n  for (int s = 0; s < len(f); ++s) f[s] = Rf[s][popcnt(s)];\n\
    \  return f;\n}\n#line 3 \"setfunc/subset_convolution.hpp\"\n\ntemplate <typename\
    \ T, int LIM = 20>\nvc<T> subset_convolution_square(const vc<T>& A) {\n  auto\
    \ RA = ranked_zeta<T, LIM>(A);\n  int n = topbit(len(RA));\n  FOR(s, len(RA))\
    \ {\n    auto& f = RA[s];\n    FOR_R(d, n + 1) {\n      T x = 0;\n      FOR(i,\
    \ d + 1) x += f[i] * f[d - i];\n      f[d] = x;\n    }\n  }\n  return ranked_mobius<T,\
    \ LIM>(RA);\n}\n\ntemplate <typename T, int LIM = 20>\nvc<T> subset_convolution(const\
    \ vc<T>& A, const vc<T>& B) {\n  if (A == B) return subset_convolution_square(A);\n\
    \  auto RA = ranked_zeta<T, LIM>(A);\n  auto RB = ranked_zeta<T, LIM>(B);\n  int\
    \ n = topbit(len(RA));\n  FOR(s, len(RA)) {\n    auto &f = RA[s], &g = RB[s];\n\
    \    FOR_R(d, n + 1) {\n      T x = 0;\n      FOR(i, d + 1) x += f[i] * g[d -\
    \ i];\n      f[d] = x;\n    }\n  }\n  return ranked_mobius<T, LIM>(RA);\n}\n#line\
    \ 4 \"setfunc/sps_exp.hpp\"\n\n// sum_i 1/i! s^i, s^i is subset-convolution\n\
    template <typename mint, int LIM>\nvc<mint> sps_exp(vc<mint>& s) {\n  const int\
    \ N = topbit(len(s));\n  assert(len(s) == (1 << N) && s[0] == mint(0));\n  vc<mint>\
    \ dp(1 << N);\n  dp[0] = mint(1);\n  FOR(i, N) {\n    vc<mint> a = {s.begin()\
    \ + (1 << i), s.begin() + (2 << i)};\n    vc<mint> b = {dp.begin(), dp.begin()\
    \ + (1 << i)};\n    a = subset_convolution<mint, LIM>(a, b);\n    copy(all(a),\
    \ dp.begin() + (1 << i));\n  }\n  return dp;\n}\n#line 1 \"enumerate/bits.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/enumerate/bits.hpp\n\
    template <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int\
    \ R, F&& f) {\n  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n\
    \  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename\
    \ UINT, typename F>\ninline void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n#line 4 \"linalg/hafnian.hpp\"\
    \n\n// \u96A3\u63A5\u884C\u5217\u306B\u5BFE\u3057\u3066\u5B8C\u5168\u30DE\u30C3\
    \u30C1\u30F3\u30B0\u3092\u6570\u3048\u308B\u3002\ntemplate <typename mint, int\
    \ LIM = 20>\nmint hafnian(const vvc<mint>& mat) {\n  int N = len(mat);\n  int\
    \ n = N / 2;\n  assert(n <= LIM);\n  vc<mint> cyc(1 << n);\n\n  FOR(i, N / 2)\
    \ {\n    int A = 2 * i + 0, B = 2 * i + 1;\n    int K = 2 * i;\n    cyc[1 << i]\
    \ += mat[A][B];\n    vc<mint> dp(K << i);\n    for (int j = 0; j < i; ++j) {\n\
    \      int j0 = 2 * j + 0, j1 = 2 * j + 1;\n      dp[(K << j) + j0] += mat[A][j1],\
    \ dp[(K << j) + j1] += mat[A][j0];\n    }\n    for (int s = 0; s < (1 << i); ++s)\
    \ {\n      for (int j = 0; j < i; ++j) {\n        int j0 = 2 * j + 0, j1 = 2 *\
    \ j + 1;\n        cyc[s | 1 << i] += dp[K * s + j0] * mat[B][j0];\n        cyc[s\
    \ | 1 << i] += dp[K * s + j1] * mat[B][j1];\n        enumerate_all_bit<u32>((1\
    \ << i) - 1 - s, [&](int k) -> void {\n          int k0 = 2 * k + 0, k1 = 2 *\
    \ k + 1;\n          int t = s | 1 << k;\n          dp[K * t + k0] += dp[K * s\
    \ + j0] * mat[j0][k1];\n          dp[K * t + k0] += dp[K * s + j1] * mat[j1][k1];\n\
    \          dp[K * t + k1] += dp[K * s + j0] * mat[j0][k0];\n          dp[K * t\
    \ + k1] += dp[K * s + j1] * mat[j1][k0];\n        });\n      }\n    }\n  }\n \
    \ return sps_exp<mint, LIM>(cyc).back();\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/linalg/hafnian.hpp\n\
    #include \"setfunc/sps_exp.hpp\"\n#include \"enumerate/bits.hpp\"\n\n// \u96A3\
    \u63A5\u884C\u5217\u306B\u5BFE\u3057\u3066\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u3092\u6570\u3048\u308B\u3002\ntemplate <typename mint, int LIM = 20>\n\
    mint hafnian(const vvc<mint>& mat) {\n  int N = len(mat);\n  int n = N / 2;\n\
    \  assert(n <= LIM);\n  vc<mint> cyc(1 << n);\n\n  FOR(i, N / 2) {\n    int A\
    \ = 2 * i + 0, B = 2 * i + 1;\n    int K = 2 * i;\n    cyc[1 << i] += mat[A][B];\n\
    \    vc<mint> dp(K << i);\n    for (int j = 0; j < i; ++j) {\n      int j0 = 2\
    \ * j + 0, j1 = 2 * j + 1;\n      dp[(K << j) + j0] += mat[A][j1], dp[(K << j)\
    \ + j1] += mat[A][j0];\n    }\n    for (int s = 0; s < (1 << i); ++s) {\n    \
    \  for (int j = 0; j < i; ++j) {\n        int j0 = 2 * j + 0, j1 = 2 * j + 1;\n\
    \        cyc[s | 1 << i] += dp[K * s + j0] * mat[B][j0];\n        cyc[s | 1 <<\
    \ i] += dp[K * s + j1] * mat[B][j1];\n        enumerate_all_bit<u32>((1 << i)\
    \ - 1 - s, [&](int k) -> void {\n          int k0 = 2 * k + 0, k1 = 2 * k + 1;\n\
    \          int t = s | 1 << k;\n          dp[K * t + k0] += dp[K * s + j0] * mat[j0][k1];\n\
    \          dp[K * t + k0] += dp[K * s + j1] * mat[j1][k1];\n          dp[K * t\
    \ + k1] += dp[K * s + j0] * mat[j0][k0];\n          dp[K * t + k1] += dp[K * s\
    \ + j1] * mat[j1][k0];\n        });\n      }\n    }\n  }\n  return sps_exp<mint,\
    \ LIM>(cyc).back();\n}\n"
  dependsOn:
  - setfunc/sps_exp.hpp
  - setfunc/subset_convolution.hpp
  - setfunc/ranked_zeta.hpp
  - setfunc/bitwise_transform.hpp
  - enumerate/bits.hpp
  isVerificationFile: false
  path: linalg/hafnian.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
documentation_of: linalg/hafnian.hpp
layout: document
redirect_from:
- /library/linalg/hafnian.hpp
- /library/linalg/hafnian.hpp.html
title: linalg/hafnian.hpp
---
