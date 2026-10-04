---
data:
  _extendedDependsOn: []
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
    path: string/substring_shortest_border.hpp
    title: string/substring_shortest_border.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_lcp_change.hpp
    title: string/suffix_lcp_change.hpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/sparse_table/disjoint_sparse_table.hpp\"\n\ntemplate\
    \ <class Monoid>\nstruct Disjoint_Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Disjoint_Sparse_Table()\
    \ {}\n  Disjoint_Sparse_Table(int n) { build(n); }\n  template <typename F>\n\
    \  Disjoint_Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n  Disjoint_Sparse_Table(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::id(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].reserve(n);\n    FOR(i, n) dat[0].eb(f(i));\n    FOR(i, 1, log) {\n\
    \      auto& v = dat[i];\n      v = dat[0];\n      int b = 1 << i;\n      for\
    \ (int m = b; m <= n; m += 2 * b) {\n        int L = m - b, R = min(n, m + b);\n\
    \        FOR_R(j, L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\n        FOR(j,\
    \ m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) const {\n    if (L == R) return MX::id();\n    --R;\n    if (L ==\
    \ R) return dat[0][L];\n    int k = topbit(L ^ R);\n    return MX::op(dat[k][L],\
    \ dat[k][R]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) const {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n)\
    \ return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int\
    \ k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n\
    \      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n\
    \  int min_left(const F check, int R) const {\n    assert(0 <= R && R <= n &&\
    \ check(MX::id()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n   \
    \ while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n"
  code: "\ntemplate <class Monoid>\nstruct Disjoint_Sparse_Table {\n  using MX = Monoid;\n\
    \  using X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Disjoint_Sparse_Table()\
    \ {}\n  Disjoint_Sparse_Table(int n) { build(n); }\n  template <typename F>\n\
    \  Disjoint_Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n  Disjoint_Sparse_Table(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::id(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].reserve(n);\n    FOR(i, n) dat[0].eb(f(i));\n    FOR(i, 1, log) {\n\
    \      auto& v = dat[i];\n      v = dat[0];\n      int b = 1 << i;\n      for\
    \ (int m = b; m <= n; m += 2 * b) {\n        int L = m - b, R = min(n, m + b);\n\
    \        FOR_R(j, L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\n        FOR(j,\
    \ m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) const {\n    if (L == R) return MX::id();\n    --R;\n    if (L ==\
    \ R) return dat[0][L];\n    int k = topbit(L ^ R);\n    return MX::op(dat[k][L],\
    \ dat[k][R]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) const {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n)\
    \ return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int\
    \ k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n\
    \      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n\
    \  int min_left(const F check, int R) const {\n    assert(0 <= R && R <= n &&\
    \ check(MX::id()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n   \
    \ while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparse_table/disjoint_sparse_table.hpp
  requiredBy:
  - graph/ds/static_tree_monoid.hpp
  - ds/static_range_product.hpp
  - string/longest_common_substring.hpp
  - string/suffix_array.hpp
  - string/basic_substring_structure.hpp
  - string/sort_substrings.hpp
  - string/many_string_compare.hpp
  - string/lex_max_suffix_for_all_prefix.hpp
  - string/substring_shortest_border.hpp
  - string/suffix_lcp_change.hpp
  timestamp: '2026-09-28 10:13:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/longest_common_substr.test.cpp
  - test/1_mytest/suffix_lcp_change.test.cpp
  - test/1_mytest/lex_minmax_suffix.test.cpp
  - test/3_yukicoder/1216_2.test.cpp
  - test/3_yukicoder/2005.test.cpp
  - test/3_yukicoder/1216.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
  - test/2_library_checker/data_structure/staticrmq.test.cpp
  - test/2_library_checker/data_structure/staticrmq_dst.test.cpp
  - test/2_library_checker/string/longest_common_substring.test.cpp
  - test/2_library_checker/string/suffix_array_vec.test.cpp
  - test/2_library_checker/string/suffix_array.test.cpp
  - test/2_library_checker/string/number_of_substrings.test.cpp
  - test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
documentation_of: ds/sparse_table/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/ds/sparse_table/disjoint_sparse_table.hpp
- /library/ds/sparse_table/disjoint_sparse_table.hpp.html
title: ds/sparse_table/disjoint_sparse_table.hpp
---
