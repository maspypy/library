---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
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
    links: []
  bundledCode: "#line 2 \"setfunc/sps_exp.hpp\"\n\n#line 2 \"other/bit.hpp\"\n\nint\
    \ popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return\
    \ __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(u64 x) { return __builtin_popcountll(x); }\nint popcnt_sgn(int\
    \ x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }\nint popcnt_sgn(u32\
    \ x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\nint popcnt_sgn(ll x) { return\
    \ (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x)\
    \ & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x)\
    \ { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return\
    \ (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0\
    \ ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x == 0 ? -1\
    \ : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32 x) { return\
    \ (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x));\
    \ }\n\ntemplate <typename T>\nT kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate\
    \ <typename T>\nbool has_kth_bit(T x, int k) {\n  return x >> k & 1;\n}\n\ntemplate\
    \ <typename UINT>\nstruct all_bit {\n  UINT s;\n  struct iter {\n    UINT s;\n\
    \    int operator*() const { return lowbit(s); }\n    void operator++() { s &=\
    \ s - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  struct iter {\n    UINT s,\
    \ t;\n    bool done = false;\n    UINT operator*() const { return t; }\n    void\
    \ operator++() {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool\
    \ operator!=(nullptr_t) const { return !done; }\n  };\n  iter begin() const {\
    \ return {s, s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\nconstexpr\
    \ u64 full_mask(int n) { return n == 64 ? -1ULL : (1ULL << n) - 1; }\n#line 2\
    \ \"setfunc/ranked_zeta.hpp\"\n\r\n#line 2 \"setfunc/bitwise_transform.hpp\"\n\
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
    \ bitwise\n#line 4 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate <typename T, int\
    \ LIM>\r\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\r\n  int n = topbit(len(f));\r\
    \n  assert(n <= LIM);\r\n  assert(len(f) == 1 << n);\r\n  vc<array<T, LIM + 1>>\
    \ Rf(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\
    \n  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);\r\n  return\
    \ Rf;\r\n}\r\n\r\ntemplate <typename T, int LIM>\r\nvc<T> ranked_mobius(vc<array<T,\
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
    \ dp.begin() + (1 << i));\n  }\n  return dp;\n}\n#line 2 \"enumerate/bits.hpp\"\
    \ntemplate <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L,\
    \ int R, F&& f) {\n  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n\
    \  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename\
    \ UINT, typename F>\ninline void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n#line 3 \"linalg/hafnian.hpp\"\
    \n\r\n// \u96A3\u63A5\u884C\u5217\u306B\u5BFE\u3057\u3066\u5B8C\u5168\u30DE\u30C3\
    \u30C1\u30F3\u30B0\u3092\u6570\u3048\u308B\u3002\r\ntemplate <typename mint, int\
    \ LIM = 20>\r\nmint Hufnian(vc<vc<mint>>& mat) {\r\n  int N = len(mat);\r\n  int\
    \ n = N / 2;\r\n  assert(n <= LIM);\r\n  vc<mint> cyc(1 << n);\r\n\r\n  FOR(i,\
    \ N / 2) {\r\n    int A = 2 * i + 0, B = 2 * i + 1;\r\n    int K = 2 * i;\r\n\
    \    cyc[1 << i] += mat[A][B];\r\n    vc<mint> dp(K << i);\r\n    for (int j =\
    \ 0; j < i; ++j) {\r\n      int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\n      dp[(K\
    \ << j) + j0] += mat[A][j1], dp[(K << j) + j1] += mat[A][j0];\r\n    }\r\n   \
    \ for (int s = 0; s < (1 << i); ++s) {\r\n      for (int j = 0; j < i; ++j) {\r\
    \n        int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\n        cyc[s | 1 << i] += dp[K\
    \ * s + j0] * mat[B][j0];\r\n        cyc[s | 1 << i] += dp[K * s + j1] * mat[B][j1];\r\
    \n        enumerate_all_bit<u32>((1 << i) - 1 - s, [&](int k) -> void {\r\n  \
    \        int k0 = 2 * k + 0, k1 = 2 * k + 1;\r\n          int t = s | 1 << k;\r\
    \n          dp[K * t + k0] += dp[K * s + j0] * mat[j0][k1];\r\n          dp[K\
    \ * t + k0] += dp[K * s + j1] * mat[j1][k1];\r\n          dp[K * t + k1] += dp[K\
    \ * s + j0] * mat[j0][k0];\r\n          dp[K * t + k1] += dp[K * s + j1] * mat[j1][k0];\r\
    \n        });\r\n      }\r\n    }\r\n  }\r\n  return sps_exp<mint, LIM>(cyc).back();\r\
    \n}\r\n"
  code: "#include \"setfunc/sps_exp.hpp\"\r\n#include \"enumerate/bits.hpp\"\r\n\r\
    \n// \u96A3\u63A5\u884C\u5217\u306B\u5BFE\u3057\u3066\u5B8C\u5168\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u3092\u6570\u3048\u308B\u3002\r\ntemplate <typename mint, int LIM\
    \ = 20>\r\nmint Hufnian(vc<vc<mint>>& mat) {\r\n  int N = len(mat);\r\n  int n\
    \ = N / 2;\r\n  assert(n <= LIM);\r\n  vc<mint> cyc(1 << n);\r\n\r\n  FOR(i, N\
    \ / 2) {\r\n    int A = 2 * i + 0, B = 2 * i + 1;\r\n    int K = 2 * i;\r\n  \
    \  cyc[1 << i] += mat[A][B];\r\n    vc<mint> dp(K << i);\r\n    for (int j = 0;\
    \ j < i; ++j) {\r\n      int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\n      dp[(K <<\
    \ j) + j0] += mat[A][j1], dp[(K << j) + j1] += mat[A][j0];\r\n    }\r\n    for\
    \ (int s = 0; s < (1 << i); ++s) {\r\n      for (int j = 0; j < i; ++j) {\r\n\
    \        int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\n        cyc[s | 1 << i] += dp[K\
    \ * s + j0] * mat[B][j0];\r\n        cyc[s | 1 << i] += dp[K * s + j1] * mat[B][j1];\r\
    \n        enumerate_all_bit<u32>((1 << i) - 1 - s, [&](int k) -> void {\r\n  \
    \        int k0 = 2 * k + 0, k1 = 2 * k + 1;\r\n          int t = s | 1 << k;\r\
    \n          dp[K * t + k0] += dp[K * s + j0] * mat[j0][k1];\r\n          dp[K\
    \ * t + k0] += dp[K * s + j1] * mat[j1][k1];\r\n          dp[K * t + k1] += dp[K\
    \ * s + j0] * mat[j0][k0];\r\n          dp[K * t + k1] += dp[K * s + j1] * mat[j1][k0];\r\
    \n        });\r\n      }\r\n    }\r\n  }\r\n  return sps_exp<mint, LIM>(cyc).back();\r\
    \n}\r\n"
  dependsOn:
  - setfunc/sps_exp.hpp
  - setfunc/subset_convolution.hpp
  - other/bit.hpp
  - setfunc/ranked_zeta.hpp
  - setfunc/bitwise_transform.hpp
  - enumerate/bits.hpp
  isVerificationFile: false
  path: linalg/hafnian.hpp
  requiredBy: []
  timestamp: '2026-07-26 21:01:29+09:00'
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
