---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/factorial_digit.test.cpp
    title: test/mytest/factorial_digit.test.cpp
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
    \ }\n  E prefix_prod(int k) {\n    chmin(k, n);\n    E ret = G::unit();\n    for\
    \ (; k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n\
    \  E sum(int L, int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L,\
    \ 0), chmin(R, n);\n    if (L == 0) return prefix_prod(R);\n    assert(0 <= L\
    \ && L <= R && R <= n);\n    E pos = G::unit(), neg = G::unit();\n    while (L\
    \ < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg\
    \ = G::op(neg, dat[L - 1]), L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check) {\n    assert(check(G::unit()));\n    int\
    \ i = 0;\n    E s = G::unit();\n    int k = 1;\n    while (2 * k <= n) k *= 2;\n\
    \    while (k) {\n      if (i + k - 1 < len(dat)) {\n        E t = G::op(s, dat[i\
    \ + k - 1]);\n        if (check(t)) { i += k, s = t; }\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int kth(E k) {\n    return max_right([&k](E x)\
    \ -> bool { return x <= k; });\n  }\n};\n#line 2 \"seq/factorial_digit_system.hpp\"\
    \n\n// \u53F3\u306B\u3042\u308B\u5C0F\u3055\u3044\u3084\u3064\u306E\u500B\u6570\
    \ [2,0,3,1] \u2192 [2,0,1,0]\nvc<int> to_factorial_digit_system(vc<int>& A) {\n\
    \  int N = len(A);\n  for (auto&& x: A) assert(0 <= x && x < N);\n  FenwickTree<Monoid_Add<int>>\
    \ bit(N);\n  vc<int> B(N);\n  FOR_R(i, N) B[i] = bit.sum(0, A[i]), bit.add(A[i],\
    \ 1);\n  return B;\n}\n\n// \u53F3\u306B\u3042\u308B\u5C0F\u3055\u3044\u3084\u3064\
    \u306E\u500B\u6570 [2,0,1,0] \u2192 [2,0,3,1]\nvc<int> from_factorial_digit_system(vc<int>&\
    \ A) {\n  int N = len(A);\n  for (auto&& x: A) assert(0 <= x && x < N);\n  vc<int>\
    \ ANS(N);\n  FenwickTree<Monoid_Add<int>> bit(N, [&](int i) -> int { return 1;\
    \ });\n  FOR(i, N) {\n    ANS[i] = bit.kth(A[i]);\n    bit.add(ANS[i], -1);\n\
    \  }\n  return ANS;\n}\n"
  code: "#include \"ds/fenwicktree/fenwicktree.hpp\"\n\n// \u53F3\u306B\u3042\u308B\
    \u5C0F\u3055\u3044\u3084\u3064\u306E\u500B\u6570 [2,0,3,1] \u2192 [2,0,1,0]\n\
    vc<int> to_factorial_digit_system(vc<int>& A) {\n  int N = len(A);\n  for (auto&&\
    \ x: A) assert(0 <= x && x < N);\n  FenwickTree<Monoid_Add<int>> bit(N);\n  vc<int>\
    \ B(N);\n  FOR_R(i, N) B[i] = bit.sum(0, A[i]), bit.add(A[i], 1);\n  return B;\n\
    }\n\n// \u53F3\u306B\u3042\u308B\u5C0F\u3055\u3044\u3084\u3064\u306E\u500B\u6570\
    \ [2,0,1,0] \u2192 [2,0,3,1]\nvc<int> from_factorial_digit_system(vc<int>& A)\
    \ {\n  int N = len(A);\n  for (auto&& x: A) assert(0 <= x && x < N);\n  vc<int>\
    \ ANS(N);\n  FenwickTree<Monoid_Add<int>> bit(N, [&](int i) -> int { return 1;\
    \ });\n  FOR(i, N) {\n    ANS[i] = bit.kth(A[i]);\n    bit.add(ANS[i], -1);\n\
    \  }\n  return ANS;\n}"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: seq/factorial_digit_system.hpp
  requiredBy: []
  timestamp: '2023-03-05 17:53:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/factorial_digit.test.cpp
documentation_of: seq/factorial_digit_system.hpp
layout: document
redirect_from:
- /library/seq/factorial_digit_system.hpp
- /library/seq/factorial_digit_system.hpp.html
title: seq/factorial_digit_system.hpp
---
