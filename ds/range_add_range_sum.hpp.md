---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
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
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ E = typename G::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree()\
    \ {}\n  FenwickTree(int n) { build(n); }\n  template <typename F>\n  FenwickTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m, G::unit());\n    total\
    \ = G::unit();\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int\
    \ i) -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n    total = G::unit();\n\
    \    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int\
    \ j = i + (i & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n  E prod_all() { return total;\
    \ }\n  E sum_all() { return total; }\n  E sum(int k) { return prefix_sum(k); }\n\
    \  E prod(int k) { return prefix_prod(k); }\n  E prefix_sum(int k) { return prefix_prod(k);\
    \ }\n  E prefix_prod(int k) {\n    E ret = G::unit();\n    for (; k > 0; k -=\
    \ k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L,\
    \ int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    if (L == 0) return\
    \ prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n    E pos = G::unit(),\
    \ neg = G::unit();\n    while (L < R) { pos = G::op(pos, dat[R - 1]), R -= R &\
    \ -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]), L -= L & -L; }\n  \
    \  return G::op(pos, G::inverse(neg));\n  }\n\n  void add(int k, E x) { multiply(k,\
    \ x); }\n  void multiply(int k, E x) {\n    static_assert(G::commute);\n    total\
    \ = G::op(total, x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k\
    \ - 1], x);\n  }\n\n  template <class F>\n  int max_right(const F check) {\n \
    \   assert(check(G::unit()));\n    int i = 0;\n    E s = G::unit();\n    int k\
    \ = 1;\n    while (2 * k <= n) k *= 2;\n    while (k) {\n      E t = G::op(s,\
    \ dat[i + k - 1]);\n      if (check(t)) { i += k, s = t; }\n      k >>= 1;\n \
    \   }\n    return i;\n  }\n\n  int find_kth(E k) {\n    return max_right([&k](E\
    \ x) -> bool { return x <= k; });\n  }\n};\n#line 2 \"ds/range_add_range_sum.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Range_Add_Range_Sum {\n  using MX = Monoid;\n\
    \  using E = typename MX::value_type;\n\n  struct Mono {\n    using value_type\
    \ = pair<E, E>;\n    using X = value_type;\n    static X op(X x, X y) { return\
    \ {MX::op(x.fi, y.fi), MX::op(x.se, y.se)}; }\n    static constexpr X unit() {\
    \ return {MX::unit(), MX::unit()}; }\n    static constexpr bool commute = 1;\n\
    \  };\n  FenwickTree<Mono> bit;\n\n  Range_Add_Range_Sum() {}\n  Range_Add_Range_Sum(int\
    \ n) { build(n); }\n  template <typename F>\n  Range_Add_Range_Sum(int n, F f)\
    \ {\n    build(n, f);\n  }\n  Range_Add_Range_Sum(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> E { return MX::unit();\
    \ });\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i) -> E\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    bit.build(m, [&](int i) -> pair<E, E> { return {f(i), MX::unit()}; });\n\
    \  }\n\n  void add(int L, int R, E a) {\n    E b = MX::inverse(a);\n    bit.add(L,\
    \ {MX::power(b, L), a});\n    bit.add(R, {MX::power(a, R), b});\n  }\n\n  E sum(int\
    \ L, int R) {\n    auto [x0, x1] = bit.sum(L);\n    auto [y0, y1] = bit.sum(R);\n\
    \    E x = MX::op(MX::power(x1, L), x0);\n    E y = MX::op(MX::power(y1, R), y0);\n\
    \    return MX::op(MX::inverse(x), y);\n  }\n};\n"
  code: "#include \"fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename Monoid>\n\
    struct Range_Add_Range_Sum {\n  using MX = Monoid;\n  using E = typename MX::value_type;\n\
    \n  struct Mono {\n    using value_type = pair<E, E>;\n    using X = value_type;\n\
    \    static X op(X x, X y) { return {MX::op(x.fi, y.fi), MX::op(x.se, y.se)};\
    \ }\n    static constexpr X unit() { return {MX::unit(), MX::unit()}; }\n    static\
    \ constexpr bool commute = 1;\n  };\n  FenwickTree<Mono> bit;\n\n  Range_Add_Range_Sum()\
    \ {}\n  Range_Add_Range_Sum(int n) { build(n); }\n  template <typename F>\n  Range_Add_Range_Sum(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Range_Add_Range_Sum(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> E { return MX::unit();\
    \ });\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i) -> E\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    bit.build(m, [&](int i) -> pair<E, E> { return {f(i), MX::unit()}; });\n\
    \  }\n\n  void add(int L, int R, E a) {\n    E b = MX::inverse(a);\n    bit.add(L,\
    \ {MX::power(b, L), a});\n    bit.add(R, {MX::power(a, R), b});\n  }\n\n  E sum(int\
    \ L, int R) {\n    auto [x0, x1] = bit.sum(L);\n    auto [y0, y1] = bit.sum(R);\n\
    \    E x = MX::op(MX::power(x1, L), x0);\n    E y = MX::op(MX::power(y1, R), y0);\n\
    \    return MX::op(MX::inverse(x), y);\n  }\n};\n"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/range_add_range_sum.hpp
  requiredBy: []
  timestamp: '2022-12-04 19:59:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/DSL_2_G.test.cpp
documentation_of: ds/range_add_range_sum.hpp
layout: document
redirect_from:
- /library/ds/range_add_range_sum.hpp
- /library/ds/range_add_range_sum.hpp.html
title: ds/range_add_range_sum.hpp
---
