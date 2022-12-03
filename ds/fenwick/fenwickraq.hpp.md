---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: ds/fenwick/fenwick.hpp
    title: ds/fenwick/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick/fenwick.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Fenwick_Tree {\n  static_assert(G::commute);\n\
    \  using G = Monoid;\n  using E = typename G::value_type;\n  int n;\n  vector<E>\
    \ dat;\n  E total;\n\n  Fenwick_Tree() {}\n  Fenwick_Tree(int n) { build(n); }\n\
    \  template <typename F>\n  Fenwick_Tree(int n, F f) {\n    build(n, f);\n  }\n\
    \  Fenwick_Tree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n    dat.assign(m,\
    \ G::unit());\n    total = G::unit();\n  }\n  void build(const vc<X>& v) {\n \
    \   build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n\
    \    total = G::unit();\n    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1;\
    \ i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j - 1] =\
    \ G::op(dat[i - 1], dat[j - 1]);\n    }\n    total = sum(m);\n  }\n\n  E prod_all()\
    \ { return total; }\n  E sum_all() { return total; }\n  E prefix_sum(int k) {\
    \ return prefix_prod(k); }\n  E prefix_prod(int k) {\n    E ret = G::unit();\n\
    \    for (; k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n\
    \  }\n  E sum(int L, int R) { return prod(L, R); }\n  E prod(int L, int R) {\n\
    \    if (L == 0) return prod(R);\n    E pos = G::unit(), neg = G::unit();\n  \
    \  while (L < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }\n    while (R\
    \ < L) { neg = G::op(neg, dat[L - 1]), L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    total = G::op(total, x);\n    for (++k; k <= n; k += k & -k) dat[k -\
    \ 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class F>\n  int max_right(const\
    \ F check) {\n    assert(check(G::unit()));\n    int i = 0;\n    E s = G::unit();\n\
    \    int k = 1;\n    while (2 * k <= n) k *= 2;\n    while (k) {\n      E t =\
    \ G::op(s, dat[i + k - 1]);\n      if (check(t)) { i += k, s = t; }\n      k >>=\
    \ 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n    return max_right([](E\
    \ x) -> bool { return x <= k; });\n  }\n};\n#line 2 \"ds/fenwick/fenwickraq.hpp\"\
    \ntemplate <typename AbelGroup>\r\nstruct FenwickRAQ {\r\n  using E = typename\
    \ AbelGroup::value_type;\r\n  int n;\r\n  FenwickTree<AbelGroup> bit0;\r\n  FenwickTree<AbelGroup>\
    \ bit1;\r\n\r\n  FenwickRAQ() : FenwickRAQ(0) {}\r\n  FenwickRAQ(int n) : n(n),\
    \ bit0(n), bit1(n) {}\r\n  FenwickRAQ(vc<E> v) : n(len(v)), bit0(v), bit1(len(v))\
    \ {}\r\n\r\n  void add(ll i, E val) { bit0.add(i, val); }\r\n\r\n  void add(ll\
    \ L, ll R, E val) {\r\n    bit0.add(L, AbelGroup::power(val, -L));\r\n    bit0.add(R,\
    \ AbelGroup::power(val, R));\r\n    bit1.add(L, val);\r\n    bit1.add(R, AbelGroup::inverse(val));\r\
    \n  }\r\n\r\n  E prod(ll L, ll R) {\r\n    E prod_R = AbelGroup::op(AbelGroup::power(bit1.prod(R),\
    \ R), bit0.prod(R));\r\n    E prod_L = AbelGroup::op(AbelGroup::power(bit1.prod(L),\
    \ L), bit0.prod(L));\r\n    return AbelGroup::op(AbelGroup::inverse(prod_L), prod_R);\r\
    \n  }\r\n};\r\n"
  code: "#include \"ds/fenwick/fenwick.hpp\"\r\ntemplate <typename AbelGroup>\r\n\
    struct FenwickRAQ {\r\n  using E = typename AbelGroup::value_type;\r\n  int n;\r\
    \n  FenwickTree<AbelGroup> bit0;\r\n  FenwickTree<AbelGroup> bit1;\r\n\r\n  FenwickRAQ()\
    \ : FenwickRAQ(0) {}\r\n  FenwickRAQ(int n) : n(n), bit0(n), bit1(n) {}\r\n  FenwickRAQ(vc<E>\
    \ v) : n(len(v)), bit0(v), bit1(len(v)) {}\r\n\r\n  void add(ll i, E val) { bit0.add(i,\
    \ val); }\r\n\r\n  void add(ll L, ll R, E val) {\r\n    bit0.add(L, AbelGroup::power(val,\
    \ -L));\r\n    bit0.add(R, AbelGroup::power(val, R));\r\n    bit1.add(L, val);\r\
    \n    bit1.add(R, AbelGroup::inverse(val));\r\n  }\r\n\r\n  E prod(ll L, ll R)\
    \ {\r\n    E prod_R = AbelGroup::op(AbelGroup::power(bit1.prod(R), R), bit0.prod(R));\r\
    \n    E prod_L = AbelGroup::op(AbelGroup::power(bit1.prod(L), L), bit0.prod(L));\r\
    \n    return AbelGroup::op(AbelGroup::inverse(prod_L), prod_R);\r\n  }\r\n};\r\
    \n"
  dependsOn:
  - ds/fenwick/fenwick.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwick/fenwickraq.hpp
  requiredBy: []
  timestamp: '2022-12-03 09:00:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/DSL_2_G.test.cpp
documentation_of: ds/fenwick/fenwickraq.hpp
layout: document
redirect_from:
- /library/ds/fenwick/fenwickraq.hpp
- /library/ds/fenwick/fenwickraq.hpp.html
title: ds/fenwick/fenwickraq.hpp
---
