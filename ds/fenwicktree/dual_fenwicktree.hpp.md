---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/dual_fenwick.test.cpp
    title: test/mytest/dual_fenwick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fenwicktree/dual_fenwicktree.hpp\"\n\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/dual_fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Dual_FenwickTree {\n  using G = Monoid;\n\
    \  using E = typename G::value_type;\n  int n;\n  vector<E> dat;\n\n  Dual_FenwickTree()\
    \ {}\n  Dual_FenwickTree(int n) { build(n); }\n\n  void build(int m) {\n    n\
    \ = m;\n    dat.assign(m, G::unit());\n  }\n\n  E get(int k) {\n    E x = G::unit();\n\
    \    for (++k; k <= n; k += k & -k) x = G::op(x, dat[k - 1]);\n    return x;\n\
    \  }\n  vc<E> get_all() {\n    vc<E> A = dat;\n    FOR_R(i, 1, len(A) + 1) {\n\
    \      int j = i + (i & -i);\n      if (j <= len(A)) A[i - 1] += A[j - 1];\n \
    \   }\n    return A;\n  }\n\n  void apply(int L, int R, E x) {\n    assert(0 <=\
    \ L && L <= R && R <= n);\n    E neg_x = G::inverse(x);\n    while (L < R) { dat[R\
    \ - 1] = G::op(x, dat[R - 1]), R -= R & -R; };\n    while (R < L) { dat[L - 1]\
    \ = G::op(neg_x, dat[L - 1]), L -= L & -L; };\n  }\n};\n"
  code: "\n#include \"alg/monoid/add.hpp\"\n\ntemplate <typename Monoid>\nstruct Dual_FenwickTree\
    \ {\n  using G = Monoid;\n  using E = typename G::value_type;\n  int n;\n  vector<E>\
    \ dat;\n\n  Dual_FenwickTree() {}\n  Dual_FenwickTree(int n) { build(n); }\n\n\
    \  void build(int m) {\n    n = m;\n    dat.assign(m, G::unit());\n  }\n\n  E\
    \ get(int k) {\n    E x = G::unit();\n    for (++k; k <= n; k += k & -k) x = G::op(x,\
    \ dat[k - 1]);\n    return x;\n  }\n  vc<E> get_all() {\n    vc<E> A = dat;\n\
    \    FOR_R(i, 1, len(A) + 1) {\n      int j = i + (i & -i);\n      if (j <= len(A))\
    \ A[i - 1] += A[j - 1];\n    }\n    return A;\n  }\n\n  void apply(int L, int\
    \ R, E x) {\n    assert(0 <= L && L <= R && R <= n);\n    E neg_x = G::inverse(x);\n\
    \    while (L < R) { dat[R - 1] = G::op(x, dat[R - 1]), R -= R & -R; };\n    while\
    \ (R < L) { dat[L - 1] = G::op(neg_x, dat[L - 1]), L -= L & -L; };\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/dual_fenwicktree.hpp
  requiredBy: []
  timestamp: '2024-01-23 05:58:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/dual_fenwick.test.cpp
documentation_of: ds/fenwicktree/dual_fenwicktree.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/dual_fenwicktree.hpp
- /library/ds/fenwicktree/dual_fenwicktree.hpp.html
title: ds/fenwicktree/dual_fenwicktree.hpp
---
