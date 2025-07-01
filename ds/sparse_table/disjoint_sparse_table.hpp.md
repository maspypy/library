---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/static_range_product.hpp
    title: ds/static_range_product.hpp
  - icon: ':x:'
    path: graph/ds/static_tree_monoid.hpp
    title: graph/ds/static_tree_monoid.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/staticrmq.test.cpp
    title: test/2_library_checker/data_structure/staticrmq.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/staticrmq_dst.test.cpp
    title: test/2_library_checker/data_structure/staticrmq_dst.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
    title: test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1216.test.cpp
    title: test/3_yukicoder/1216.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1216_2.test.cpp
    title: test/3_yukicoder/1216_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2005.test.cpp
    title: test/3_yukicoder/2005.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/sparse_table/disjoint_sparse_table.hpp\"\n\r\ntemplate\
    \ <class Monoid>\r\nstruct Disjoint_Sparse_Table {\r\n  using MX = Monoid;\r\n\
    \  using X = typename MX::value_type;\r\n  int n, log;\r\n  vvc<X> dat;\r\n\r\n\
    \  Disjoint_Sparse_Table() {}\r\n  Disjoint_Sparse_Table(int n) { build(n); }\r\
    \n  template <typename F>\r\n  Disjoint_Sparse_Table(int n, F f) {\r\n    build(n,\
    \ f);\r\n  }\r\n  Disjoint_Sparse_Table(const vc<X>& v) { build(v); }\r\n\r\n\
    \  void build(int m) {\r\n    build(m, [](int i) -> X { return MX::unit(); });\r\
    \n  }\r\n  void build(const vc<X>& v) {\r\n    build(len(v), [&](int i) -> X {\
    \ return v[i]; });\r\n  }\r\n  template <typename F>\r\n  void build(int m, F\
    \ f) {\r\n    n = m, log = 1;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(log);\r\
    \n    dat[0].reserve(n);\r\n    FOR(i, n) dat[0].eb(f(i));\r\n    FOR(i, 1, log)\
    \ {\r\n      auto& v = dat[i];\r\n      v = dat[0];\r\n      int b = 1 << i;\r\
    \n      for (int m = b; m <= n; m += 2 * b) {\r\n        int L = m - b, R = min(n,\
    \ m + b);\r\n        FOR_R(j, L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\r\n\
    \        FOR(j, m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);\r\n      }\r\n  \
    \  }\r\n  }\r\n\r\n  X prod(int L, int R) {\r\n    if (L == R) return MX::unit();\r\
    \n    --R;\r\n    if (L == R) return dat[0][L];\r\n    int k = topbit(L ^ R);\r\
    \n    return MX::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  template <class F>\r\
    \n  int max_right(const F check, int L) {\r\n    assert(0 <= L && L <= n && check(MX::unit()));\r\
    \n    if (L == n) return n;\r\n    int ok = L, ng = n + 1;\r\n    while (ok +\
    \ 1 < ng) {\r\n      int k = (ok + ng) / 2;\r\n      bool bl = check(prod(L, k));\r\
    \n      if (bl) ok = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\
    \n  }\r\n\r\n  template <class F>\r\n  int min_left(const F check, int R) {\r\n\
    \    assert(0 <= R && R <= n && check(MX::unit()));\r\n    if (R == 0) return\
    \ 0;\r\n    int ok = R, ng = -1;\r\n    while (ng + 1 < ok) {\r\n      int k =\
    \ (ok + ng) / 2;\r\n      bool bl = check(prod(k, R));\r\n      if (bl) ok = k;\r\
    \n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class Monoid>\r\nstruct Disjoint_Sparse_Table\
    \ {\r\n  using MX = Monoid;\r\n  using X = typename MX::value_type;\r\n  int n,\
    \ log;\r\n  vvc<X> dat;\r\n\r\n  Disjoint_Sparse_Table() {}\r\n  Disjoint_Sparse_Table(int\
    \ n) { build(n); }\r\n  template <typename F>\r\n  Disjoint_Sparse_Table(int n,\
    \ F f) {\r\n    build(n, f);\r\n  }\r\n  Disjoint_Sparse_Table(const vc<X>& v)\
    \ { build(v); }\r\n\r\n  void build(int m) {\r\n    build(m, [](int i) -> X {\
    \ return MX::unit(); });\r\n  }\r\n  void build(const vc<X>& v) {\r\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\r\n  }\r\n  template <typename F>\r\n  void\
    \ build(int m, F f) {\r\n    n = m, log = 1;\r\n    while ((1 << log) < n) ++log;\r\
    \n    dat.resize(log);\r\n    dat[0].reserve(n);\r\n    FOR(i, n) dat[0].eb(f(i));\r\
    \n    FOR(i, 1, log) {\r\n      auto& v = dat[i];\r\n      v = dat[0];\r\n   \
    \   int b = 1 << i;\r\n      for (int m = b; m <= n; m += 2 * b) {\r\n       \
    \ int L = m - b, R = min(n, m + b);\r\n        FOR_R(j, L + 1, m) v[j - 1] = MX::op(v[j\
    \ - 1], v[j]);\r\n        FOR(j, m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  X prod(int L, int R) {\r\n    if (L == R) return\
    \ MX::unit();\r\n    --R;\r\n    if (L == R) return dat[0][L];\r\n    int k =\
    \ topbit(L ^ R);\r\n    return MX::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  template\
    \ <class F>\r\n  int max_right(const F check, int L) {\r\n    assert(0 <= L &&\
    \ L <= n && check(MX::unit()));\r\n    if (L == n) return n;\r\n    int ok = L,\
    \ ng = n + 1;\r\n    while (ok + 1 < ng) {\r\n      int k = (ok + ng) / 2;\r\n\
    \      bool bl = check(prod(L, k));\r\n      if (bl) ok = k;\r\n      if (!bl)\
    \ ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  template <class F>\r\n  int\
    \ min_left(const F check, int R) {\r\n    assert(0 <= R && R <= n && check(MX::unit()));\r\
    \n    if (R == 0) return 0;\r\n    int ok = R, ng = -1;\r\n    while (ng + 1 <\
    \ ok) {\r\n      int k = (ok + ng) / 2;\r\n      bool bl = check(prod(k, R));\r\
    \n      if (bl) ok = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\
    \n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparse_table/disjoint_sparse_table.hpp
  requiredBy:
  - ds/static_range_product.hpp
  - graph/ds/static_tree_monoid.hpp
  timestamp: '2024-02-06 01:35:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - test/2_library_checker/data_structure/staticrmq_dst.test.cpp
  - test/2_library_checker/data_structure/staticrmq.test.cpp
  - test/3_yukicoder/2005.test.cpp
  - test/3_yukicoder/1216_2.test.cpp
  - test/3_yukicoder/1216.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
documentation_of: ds/sparse_table/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/ds/sparse_table/disjoint_sparse_table.hpp
- /library/ds/sparse_table/disjoint_sparse_table.hpp.html
title: ds/sparse_table/disjoint_sparse_table.hpp
---
