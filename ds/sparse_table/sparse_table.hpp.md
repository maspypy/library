---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: ds/static_range_product.hpp
    title: ds/static_range_product.hpp
  - icon: ':heavy_check_mark:'
    path: ds/static_rmq.hpp
    title: ds/static_rmq.hpp
  - icon: ':heavy_check_mark:'
    path: graph/fast_lca.hpp
    title: graph/fast_lca.hpp
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
  - icon: ':question:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2361.test.cpp
    title: test/3_yukicoder/2361.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/866.test.cpp
    title: test/3_yukicoder/866.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/sparse_table/sparse_table.hpp\"\n\n// \u51AA\u7B49\u306A\
    \u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3002\
    disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\ntemplate <class Monoid>\n\
    struct Sparse_Table {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) {\
    \ build(n); }\n  template <typename F>\n  Sparse_Table(int n, F f) {\n    build(n,\
    \ f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v); }\n\n  void build(int m)\
    \ {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n    FOR(i,\
    \ n) dat[0][i] = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i])\
    \ - (1 << i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j]\
    \ = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) {\n    if (L == R) return MX::unit();\n    if (R == L + 1) return\
    \ dat[0][L];\n    int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R\
    \ - (1 << k)]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n    if (L == n) return\
    \ n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int k = (ok\
    \ + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n    \
    \  if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(0 <= R && R <= n && check(MX::unit()));\n\
    \    if (R == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n"
  code: "#pragma once\n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x\
    \ \u500D\u9AD8\u901F\ntemplate <class Monoid>\nstruct Sparse_Table {\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n  int n, log;\n  vvc<X>\
    \ dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) { build(n); }\n  template\
    \ <typename F>\n  Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].resize(n);\n    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1)\
    \ {\n      dat[i + 1].resize(len(dat[i]) - (1 << i));\n      FOR(j, len(dat[i])\
    \ - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n\n  X prod(int L, int R) {\n    if (L == R) return MX::unit();\n\
    \    if (R == L + 1) return dat[0][L];\n    int k = topbit(R - L - 1);\n    return\
    \ MX::op(dat[k][L], dat[k][R - (1 << k)]);\n  }\n\n  template <class F>\n  int\
    \ max_right(const F check, int L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n\
    \    if (L == n) return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template\
    \ <class F>\n  int min_left(const F check, int R) {\n    assert(0 <= R && R <=\
    \ n && check(MX::unit()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n\
    \    while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparse_table/sparse_table.hpp
  requiredBy:
  - graph/fast_lca.hpp
  - ds/static_rmq.hpp
  - ds/static_range_product.hpp
  - string/suffix_array.hpp
  - string/longest_common_substring.hpp
  - string/suffix_tree.hpp
  - string/sort_substrings.hpp
  - string/many_string_compare.hpp
  - string/lex_max_suffix_for_all_prefix.hpp
  timestamp: '2024-02-11 04:08:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/866.test.cpp
  - test/3_yukicoder/2361.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
  - test/3_yukicoder/1036_4.test.cpp
  - test/2_library_checker/data_structure/staticrmq_sparse.test.cpp
  - test/2_library_checker/data_structure/staticrmq.test.cpp
  - test/2_library_checker/data_structure/staticrmq_x.test.cpp
  - test/2_library_checker/tree/lca_fast.test.cpp
  - test/2_library_checker/string/number_of_substrings.test.cpp
  - test/2_library_checker/string/suffix_array_vec.test.cpp
  - test/2_library_checker/string/suffix_array.test.cpp
  - test/2_library_checker/string/longest_common_substring.test.cpp
  - test/1_mytest/lex_minmax_suffix.test.cpp
  - test/1_mytest/longest_common_substr.test.cpp
documentation_of: ds/sparse_table/sparse_table.hpp
layout: document
redirect_from:
- /library/ds/sparse_table/sparse_table.hpp
- /library/ds/sparse_table/sparse_table.hpp.html
title: ds/sparse_table/sparse_table.hpp
---
