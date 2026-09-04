---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/chromatic.hpp
    title: graph/chromatic.hpp
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
  - icon: ':heavy_check_mark:'
    path: setfunc/power_projection_of_sps.hpp
    title: setfunc/power_projection_of_sps.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/sps_exp.hpp
    title: setfunc/sps_exp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/chromatic_number.test.cpp
    title: test/2_library_checker/graph/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/chromatic_polynomial.test.cpp
    title: test/2_library_checker/graph/chromatic_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
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
    path: test/3_yukicoder/2507.test.cpp
    title: test/3_yukicoder/2507.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"setfunc/ranked_zeta.hpp\"\
    \n\n#line 1 \"setfunc/bitwise_transform.hpp\"\n\nnamespace bitwise {\n\nenum class\
    \ trans_type {\n  hadamard,\n  superset_zeta,\n  superset_mobius,\n  subset_zeta,\n\
    \  subset_mobius,\n  ranked_zeta,\n  ranked_mobius,\n  superset_zeta_or\n};\n\n\
    template <typename ARR>\ninline void ranked_add(ARR& a, const ARR& b) {\n  for\
    \ (int d = 0; d < int(a.size()); ++d) a[d] += b[d];\n}\n\ntemplate <typename ARR>\n\
    inline void ranked_sub(ARR& a, const ARR& b) {\n  for (int d = 0; d < int(a.size());\
    \ ++d) a[d] -= b[d];\n}\n\ntemplate <trans_type type, int N, typename T>\ninline\
    \ void bitwise_transform_fixed(T* a) {\n  static_assert(N >= 1 && (N & (N - 1))\
    \ == 0);\n  if constexpr (N == 1) {\n    return;\n  } else {\n    constexpr int\
    \ H = N / 2;\n    bitwise_transform_fixed<type, H>(a);\n    bitwise_transform_fixed<type,\
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
    }\n}  // namespace bitwise\n#line 3 \"setfunc/ranked_zeta.hpp\"\n\ntemplate <typename\
    \ T, int LIM>\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\n  int n =\
    \ topbit(len(f));\n  assert(n <= LIM);\n  assert(len(f) == 1 << n);\n  vc<array<T,\
    \ LIM + 1>> Rf(1 << n);\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)]\
    \ = f[s];\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);\n\
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
    \ i];\n      f[d] = x;\n    }\n  }\n  return ranked_mobius<T, LIM>(RA);\n}\n"
  code: "#include \"other/bit.hpp\"\n#include \"setfunc/ranked_zeta.hpp\"\n\ntemplate\
    \ <typename T, int LIM = 20>\nvc<T> subset_convolution_square(const vc<T>& A)\
    \ {\n  auto RA = ranked_zeta<T, LIM>(A);\n  int n = topbit(len(RA));\n  FOR(s,\
    \ len(RA)) {\n    auto& f = RA[s];\n    FOR_R(d, n + 1) {\n      T x = 0;\n  \
    \    FOR(i, d + 1) x += f[i] * f[d - i];\n      f[d] = x;\n    }\n  }\n  return\
    \ ranked_mobius<T, LIM>(RA);\n}\n\ntemplate <typename T, int LIM = 20>\nvc<T>\
    \ subset_convolution(const vc<T>& A, const vc<T>& B) {\n  if (A == B) return subset_convolution_square(A);\n\
    \  auto RA = ranked_zeta<T, LIM>(A);\n  auto RB = ranked_zeta<T, LIM>(B);\n  int\
    \ n = topbit(len(RA));\n  FOR(s, len(RA)) {\n    auto &f = RA[s], &g = RB[s];\n\
    \    FOR_R(d, n + 1) {\n      T x = 0;\n      FOR(i, d + 1) x += f[i] * g[d -\
    \ i];\n      f[d] = x;\n    }\n  }\n  return ranked_mobius<T, LIM>(RA);\n}\n"
  dependsOn:
  - other/bit.hpp
  - setfunc/ranked_zeta.hpp
  - setfunc/bitwise_transform.hpp
  isVerificationFile: false
  path: setfunc/subset_convolution.hpp
  requiredBy:
  - linalg/hafnian.hpp
  - setfunc/power_projection_of_sps.hpp
  - setfunc/sps_exp.hpp
  - graph/chromatic.hpp
  - graph/count/count_tree_subgraph.hpp
  - graph/count/count_bridgeless_subgraph.hpp
  - graph/tutte_polynomial.hpp
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/set_power_series/subset_convolution.test.cpp
  - test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
  - test/2_library_checker/set_power_series/powproj_sps.test.cpp
  - test/2_library_checker/set_power_series/sps_exp.test.cpp
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - test/2_library_checker/graph/chromatic_polynomial.test.cpp
  - test/2_library_checker/graph/chromatic_number.test.cpp
  - test/3_yukicoder/2507.test.cpp
documentation_of: setfunc/subset_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/subset_convolution.hpp
- /library/setfunc/subset_convolution.hpp.html
title: setfunc/subset_convolution.hpp
---
