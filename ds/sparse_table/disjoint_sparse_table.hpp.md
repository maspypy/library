---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/static_range_product.hpp
    title: ds/static_range_product.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/static_tree_monoid.hpp
    title: graph/ds/static_tree_monoid.hpp
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
    path: string/substring_count_in_substring.hpp
    title: string/substring_count_in_substring.hpp
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
    path: test/2_library_checker/data_structure/staticrmq_dst.test.cpp
    title: test/2_library_checker/data_structure/staticrmq_dst.test.cpp
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
    path: test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
    title: test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1216.test.cpp
    title: test/3_yukicoder/1216.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1216_2.test.cpp
    title: test/3_yukicoder/1216_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2005.test.cpp
    title: test/3_yukicoder/2005.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2361.test.cpp
    title: test/3_yukicoder/2361.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 3 \"ds/sparse_table/disjoint_sparse_table.hpp\"\n\
    \r\ntemplate <class Monoid>\r\nstruct Disjoint_Sparse_Table {\r\n  using MX =\
    \ Monoid;\r\n  using X = typename MX::value_type;\r\n  int n, log;\r\n  vvc<X>\
    \ dat;\r\n\r\n  Disjoint_Sparse_Table() {}\r\n  Disjoint_Sparse_Table(int n) {\
    \ build(n); }\r\n  template <typename F>\r\n  Disjoint_Sparse_Table(int n, F f)\
    \ {\r\n    build(n, f);\r\n  }\r\n  Disjoint_Sparse_Table(const vc<X>& v) { build(v);\
    \ }\r\n\r\n  void build(int m) {\r\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\r\n  }\r\n  void build(const vc<X>& v) {\r\n    build(len(v), [&](int i)\
    \ -> X { return v[i]; });\r\n  }\r\n  template <typename F>\r\n  void build(int\
    \ m, F f) {\r\n    n = m, log = 1;\r\n    while ((1 << log) < n) ++log;\r\n  \
    \  dat.resize(log);\r\n    dat[0].reserve(n);\r\n    FOR(i, n) dat[0].eb(f(i));\r\
    \n    FOR(i, 1, log) {\r\n      auto& v = dat[i];\r\n      v = dat[0];\r\n   \
    \   int b = 1 << i;\r\n      for (int m = b; m <= n; m += 2 * b) {\r\n       \
    \ int L = m - b, R = min(n, m + b);\r\n        FOR_R(j, L + 1, m) v[j - 1] = MX::op(v[j\
    \ - 1], v[j]);\r\n        FOR(j, m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  X prod(int L, int R) const {\r\n    if (L ==\
    \ R) return MX::unit();\r\n    --R;\r\n    if (L == R) return dat[0][L];\r\n \
    \   int k = topbit(L ^ R);\r\n    return MX::op(dat[k][L], dat[k][R]);\r\n  }\r\
    \n\r\n  template <class F>\r\n  int max_right(const F check, int L) const {\r\n\
    \    assert(0 <= L && L <= n && check(MX::unit()));\r\n    if (L == n) return\
    \ n;\r\n    int ok = L, ng = n + 1;\r\n    while (ok + 1 < ng) {\r\n      int\
    \ k = (ok + ng) / 2;\r\n      bool bl = check(prod(L, k));\r\n      if (bl) ok\
    \ = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  template\
    \ <class F>\r\n  int min_left(const F check, int R) const {\r\n    assert(0 <=\
    \ R && R <= n && check(MX::unit()));\r\n    if (R == 0) return 0;\r\n    int ok\
    \ = R, ng = -1;\r\n    while (ng + 1 < ok) {\r\n      int k = (ok + ng) / 2;\r\
    \n      bool bl = check(prod(k, R));\r\n      if (bl) ok = k;\r\n      if (!bl)\
    \ ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n};\n"
  code: "#pragma once\r\n#include \"other/bit.hpp\"\r\n\r\ntemplate <class Monoid>\r\
    \nstruct Disjoint_Sparse_Table {\r\n  using MX = Monoid;\r\n  using X = typename\
    \ MX::value_type;\r\n  int n, log;\r\n  vvc<X> dat;\r\n\r\n  Disjoint_Sparse_Table()\
    \ {}\r\n  Disjoint_Sparse_Table(int n) { build(n); }\r\n  template <typename F>\r\
    \n  Disjoint_Sparse_Table(int n, F f) {\r\n    build(n, f);\r\n  }\r\n  Disjoint_Sparse_Table(const\
    \ vc<X>& v) { build(v); }\r\n\r\n  void build(int m) {\r\n    build(m, [](int\
    \ i) -> X { return MX::unit(); });\r\n  }\r\n  void build(const vc<X>& v) {\r\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\r\n  }\r\n  template <typename\
    \ F>\r\n  void build(int m, F f) {\r\n    n = m, log = 1;\r\n    while ((1 <<\
    \ log) < n) ++log;\r\n    dat.resize(log);\r\n    dat[0].reserve(n);\r\n    FOR(i,\
    \ n) dat[0].eb(f(i));\r\n    FOR(i, 1, log) {\r\n      auto& v = dat[i];\r\n \
    \     v = dat[0];\r\n      int b = 1 << i;\r\n      for (int m = b; m <= n; m\
    \ += 2 * b) {\r\n        int L = m - b, R = min(n, m + b);\r\n        FOR_R(j,\
    \ L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\r\n        FOR(j, m, R - 1) v[j\
    \ + 1] = MX::op(v[j], v[j + 1]);\r\n      }\r\n    }\r\n  }\r\n\r\n  X prod(int\
    \ L, int R) const {\r\n    if (L == R) return MX::unit();\r\n    --R;\r\n    if\
    \ (L == R) return dat[0][L];\r\n    int k = topbit(L ^ R);\r\n    return MX::op(dat[k][L],\
    \ dat[k][R]);\r\n  }\r\n\r\n  template <class F>\r\n  int max_right(const F check,\
    \ int L) const {\r\n    assert(0 <= L && L <= n && check(MX::unit()));\r\n   \
    \ if (L == n) return n;\r\n    int ok = L, ng = n + 1;\r\n    while (ok + 1 <\
    \ ng) {\r\n      int k = (ok + ng) / 2;\r\n      bool bl = check(prod(L, k));\r\
    \n      if (bl) ok = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\
    \n  }\r\n\r\n  template <class F>\r\n  int min_left(const F check, int R) const\
    \ {\r\n    assert(0 <= R && R <= n && check(MX::unit()));\r\n    if (R == 0) return\
    \ 0;\r\n    int ok = R, ng = -1;\r\n    while (ng + 1 < ok) {\r\n      int k =\
    \ (ok + ng) / 2;\r\n      bool bl = check(prod(k, R));\r\n      if (bl) ok = k;\r\
    \n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n};"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: ds/sparse_table/disjoint_sparse_table.hpp
  requiredBy:
  - graph/ds/static_tree_monoid.hpp
  - ds/static_range_product.hpp
  - string/suffix_array.hpp
  - string/many_string_compare.hpp
  - string/longest_common_substring.hpp
  - string/suffix_lcp_change.hpp
  - string/substring_count_in_substring.hpp
  - string/suffix_tree.hpp
  - string/basic_substring_structure.hpp
  - string/lex_max_suffix_for_all_prefix.hpp
  - string/substring_shortest_border.hpp
  - string/sort_substrings.hpp
  timestamp: '2026-07-28 12:25:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1216_2.test.cpp
  - test/3_yukicoder/2005.test.cpp
  - test/3_yukicoder/1216.test.cpp
  - test/3_yukicoder/2361.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
  - test/1_mytest/longest_common_substr.test.cpp
  - test/1_mytest/lex_minmax_suffix.test.cpp
  - test/1_mytest/suffix_lcp_change.test.cpp
  - test/2_library_checker/string/suffix_array_vec.test.cpp
  - test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - test/2_library_checker/string/suffix_array.test.cpp
  - test/2_library_checker/string/number_of_substrings.test.cpp
  - test/2_library_checker/string/longest_common_substring.test.cpp
  - test/2_library_checker/data_structure/staticrmq.test.cpp
  - test/2_library_checker/data_structure/staticrmq_dst.test.cpp
documentation_of: ds/sparse_table/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/ds/sparse_table/disjoint_sparse_table.hpp
- /library/ds/sparse_table/disjoint_sparse_table.hpp.html
title: ds/sparse_table/disjoint_sparse_table.hpp
---
