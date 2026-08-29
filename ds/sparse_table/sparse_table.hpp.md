---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/rmq/static_rmq.hpp
    title: ds/rmq/static_rmq.hpp
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table/sparse_table_on_segtree.hpp
    title: ds/sparse_table/sparse_table_on_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/static_range_product.hpp
    title: ds/static_range_product.hpp
  - icon: ':warning:'
    path: graph/compress_tree.hpp
    title: graph/compress_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/fast_lca.hpp
    title: graph/fast_lca.hpp
  - icon: ':warning:'
    path: string/basic_substring_structure.hpp
    title: string/basic_substring_structure.hpp
  - icon: ':heavy_check_mark:'
    path: string/lex_max_suffix_for_all_prefix.hpp
    title: string/lex_max_suffix_for_all_prefix.hpp
  - icon: ':heavy_check_mark:'
    path: string/longest_common_substring.hpp
    title: string/longest_common_substring.hpp
  - icon: ':warning:'
    path: string/many_string_compare.hpp
    title: string/many_string_compare.hpp
  - icon: ':warning:'
    path: string/sort_substrings.hpp
    title: string/sort_substrings.hpp
  - icon: ':warning:'
    path: string/substring_shortest_border.hpp
    title: string/substring_shortest_border.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_lcp_change.hpp
    title: string/suffix_lcp_change.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/lex_minmax_suffix.test.cpp
    title: test/1_mytest/lex_minmax_suffix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/longest_common_substr.test.cpp
    title: test/1_mytest/longest_common_substr.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/suffix_lcp_change.test.cpp
    title: test/1_mytest/suffix_lcp_change.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/staticrmq.test.cpp
    title: test/2_library_checker/data_structure/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/staticrmq_sparse.test.cpp
    title: test/2_library_checker/data_structure/staticrmq_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/staticrmq_x.test.cpp
    title: test/2_library_checker/data_structure/staticrmq_x.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/longest_common_substring.test.cpp
    title: test/2_library_checker/string/longest_common_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/number_of_substrings.test.cpp
    title: test/2_library_checker/string/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/suffix_array.test.cpp
    title: test/2_library_checker/string/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/suffix_array_vec.test.cpp
    title: test/2_library_checker/string/suffix_array_vec.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/lca_fast.test.cpp
    title: test/2_library_checker/tree/lca_fast.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1036_4.test.cpp
    title: test/3_yukicoder/1036_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2361.test.cpp
    title: test/3_yukicoder/2361.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/866.test.cpp
    title: test/3_yukicoder/866.test.cpp
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].resize(n);\n    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1)\
    \ {\n      dat[i + 1].resize(len(dat[i]) - (1 << i));\n      FOR(j, len(dat[i])\
    \ - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n\n  X prod(int L, int R) const {\n    if (L == R) return\
    \ MX::unit();\n    if (R == L + 1) return dat[0][L];\n    int k = topbit(R - L\
    \ - 1);\n    return MX::op(dat[k][L], dat[k][R - (1 << k)]);\n  }\n\n  template\
    \ <class F>\n  int max_right(const F check, int L) const {\n    assert(0 <= L\
    \ && L <= n && check(MX::unit()));\n    if (L == n) return n;\n    int ok = L,\
    \ ng = n + 1;\n    while (ok + 1 < ng) {\n      int k = (ok + ng) / 2;\n     \
    \ bool bl = check(prod(L, k));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n\
    \    }\n    return ok;\n  }\n\n  template <class F>\n  int min_left(const F check,\
    \ int R) const {\n    assert(0 <= R && R <= n && check(MX::unit()));\n    if (R\
    \ == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok) {\n     \
    \ int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if (bl) ok\
    \ = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n"
  code: "#include \"other/bit.hpp\"\n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\
    \u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\
    \u308A x \u500D\u9AD8\u901F\ntemplate <class Monoid>\nstruct Sparse_Table {\n\
    \  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n, log;\n \
    \ vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) { build(n); }\n  template\
    \ <typename F>\n  Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].resize(n);\n    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1)\
    \ {\n      dat[i + 1].resize(len(dat[i]) - (1 << i));\n      FOR(j, len(dat[i])\
    \ - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n\n  X prod(int L, int R) const {\n    if (L == R) return\
    \ MX::unit();\n    if (R == L + 1) return dat[0][L];\n    int k = topbit(R - L\
    \ - 1);\n    return MX::op(dat[k][L], dat[k][R - (1 << k)]);\n  }\n\n  template\
    \ <class F>\n  int max_right(const F check, int L) const {\n    assert(0 <= L\
    \ && L <= n && check(MX::unit()));\n    if (L == n) return n;\n    int ok = L,\
    \ ng = n + 1;\n    while (ok + 1 < ng) {\n      int k = (ok + ng) / 2;\n     \
    \ bool bl = check(prod(L, k));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n\
    \    }\n    return ok;\n  }\n\n  template <class F>\n  int min_left(const F check,\
    \ int R) const {\n    assert(0 <= R && R <= n && check(MX::unit()));\n    if (R\
    \ == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok) {\n     \
    \ int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if (bl) ok\
    \ = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: ds/sparse_table/sparse_table.hpp
  requiredBy:
  - graph/fast_lca.hpp
  - graph/compress_tree.hpp
  - ds/rmq/static_rmq.hpp
  - ds/static_range_product.hpp
  - ds/sparse_table/sparse_table_on_segtree.hpp
  - string/suffix_lcp_change.hpp
  - string/many_string_compare.hpp
  - string/lex_max_suffix_for_all_prefix.hpp
  - string/basic_substring_structure.hpp
  - string/suffix_tree.hpp
  - string/sort_substrings.hpp
  - string/suffix_array.hpp
  - string/longest_common_substring.hpp
  - string/substring_shortest_border.hpp
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/lex_minmax_suffix.test.cpp
  - test/1_mytest/suffix_lcp_change.test.cpp
  - test/1_mytest/longest_common_substr.test.cpp
  - test/2_library_checker/data_structure/staticrmq_sparse.test.cpp
  - test/2_library_checker/data_structure/staticrmq.test.cpp
  - test/2_library_checker/data_structure/staticrmq_x.test.cpp
  - test/2_library_checker/string/suffix_array.test.cpp
  - test/2_library_checker/string/longest_common_substring.test.cpp
  - test/2_library_checker/string/suffix_array_vec.test.cpp
  - test/2_library_checker/string/number_of_substrings.test.cpp
  - test/2_library_checker/tree/lca_fast.test.cpp
  - test/3_yukicoder/2361.test.cpp
  - test/3_yukicoder/1036_4.test.cpp
  - test/3_yukicoder/866.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
documentation_of: ds/sparse_table/sparse_table.hpp
layout: document
redirect_from:
- /library/ds/sparse_table/sparse_table.hpp
- /library/ds/sparse_table/sparse_table.hpp.html
title: ds/sparse_table/sparse_table.hpp
---
