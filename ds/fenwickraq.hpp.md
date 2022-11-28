---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\
    \n\ntemplate <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename\
    \ AbelGroup::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree(int\
    \ n = 0) : n(n) {\n    assert(AbelGroup::commute);\n    reset(n);\n  }\n  FenwickTree(const\
    \ vector<E>& v) {\n    assert(AbelGroup::commute);\n    build(v);\n  }\n\n  void\
    \ build(const vc<E>& v) {\n    n = len(v);\n    total = AbelGroup::unit();\n \
    \   for (int i = 0; i < n; ++i) total = AbelGroup::op(total, v[i]);\n    dat =\
    \ v;\n    for (int i = 1; i <= n; ++i) {\n      int j = i + (i & -i);\n      if\
    \ (j <= n) dat[j - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n\
    \  void reset(int sz = 0) {\n    if (sz) n = sz;\n    total = AbelGroup::unit();\n\
    \    dat.assign(n, AbelGroup::unit());\n  }\n\n  E prod(int k) {\n    E ret =\
    \ AbelGroup::unit();\n    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret,\
    \ dat[k - 1]);\n    return ret;\n  }\n\n  E prod(int L, int R) {\n    E pos =\
    \ AbelGroup::unit();\n    while (L < R) {\n      pos = AbelGroup::op(pos, dat[R\
    \ - 1]);\n      R -= R & -R;\n    }\n    E neg = AbelGroup::unit();\n    while\
    \ (R < L) {\n      neg = AbelGroup::op(neg, dat[L - 1]);\n      L -= L & -L;\n\
    \    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n  }\n\n  E prod_all()\
    \ { return total; }\n\n  E sum(int k) { return prod(k); }\n\n  E sum(int L, int\
    \ R) { return prod(L, R); }\n\n  E sum_all() { return total; }\n\n  void multiply(int\
    \ k, E x) {\n    total = AbelGroup::op(total, x);\n    for (++k; k <= n; k +=\
    \ k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n  }\n\n  void add(int k,\
    \ E x) { multiply(k, x); }\n\n  template <class F>\n  int max_right(F& check)\
    \ {\n    assert(check(E(0)));\n    ll i = 0;\n    E s = AbelGroup::unit();\n \
    \   int k = 1;\n    int N = dat.size() + 1;\n    while (2 * k < N) k *= 2;\n \
    \   while (k) {\n      if (i + k < N && check(AbelGroup::op(s, dat[i + k - 1])))\
    \ {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n      }\n   \
    \   k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n    auto check\
    \ = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n  }\n\n\
    \  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"ds/fenwickraq.hpp\"\
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
  code: "#include \"ds/fenwick.hpp\"\r\ntemplate <typename AbelGroup>\r\nstruct FenwickRAQ\
    \ {\r\n  using E = typename AbelGroup::value_type;\r\n  int n;\r\n  FenwickTree<AbelGroup>\
    \ bit0;\r\n  FenwickTree<AbelGroup> bit1;\r\n\r\n  FenwickRAQ() : FenwickRAQ(0)\
    \ {}\r\n  FenwickRAQ(int n) : n(n), bit0(n), bit1(n) {}\r\n  FenwickRAQ(vc<E>\
    \ v) : n(len(v)), bit0(v), bit1(len(v)) {}\r\n\r\n  void add(ll i, E val) { bit0.add(i,\
    \ val); }\r\n\r\n  void add(ll L, ll R, E val) {\r\n    bit0.add(L, AbelGroup::power(val,\
    \ -L));\r\n    bit0.add(R, AbelGroup::power(val, R));\r\n    bit1.add(L, val);\r\
    \n    bit1.add(R, AbelGroup::inverse(val));\r\n  }\r\n\r\n  E prod(ll L, ll R)\
    \ {\r\n    E prod_R = AbelGroup::op(AbelGroup::power(bit1.prod(R), R), bit0.prod(R));\r\
    \n    E prod_L = AbelGroup::op(AbelGroup::power(bit1.prod(L), L), bit0.prod(L));\r\
    \n    return AbelGroup::op(AbelGroup::inverse(prod_L), prod_R);\r\n  }\r\n};\r\
    \n"
  dependsOn:
  - ds/fenwick.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwickraq.hpp
  requiredBy: []
  timestamp: '2022-11-28 14:51:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/DSL_2_G.test.cpp
documentation_of: ds/fenwickraq.hpp
layout: document
redirect_from:
- /library/ds/fenwickraq.hpp
- /library/ds/fenwickraq.hpp.html
title: ds/fenwickraq.hpp
---
