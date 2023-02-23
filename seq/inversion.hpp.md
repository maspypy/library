---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_2_A.test.cpp
    title: test/aoj/ALDS1_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_5.test.cpp
    title: test/aoj/ALDS1_5.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1838.test.cpp
    title: test/yukicoder/1838.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc190f.test.cpp
    title: test_atcoder/abc190f.test.cpp
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
    \ -> bool { return x <= k; });\n  }\n};\n#line 3 \"seq/inversion.hpp\"\n\ntemplate\
    \ <typename T, bool SMALL>\nll inversion(vc<T> A) {\n  if (A.empty()) return 0;\n\
    \  if (!SMALL) {\n    auto key = A;\n    UNIQUE(key);\n    for (auto&& x: A) x\
    \ = LB(key, x);\n  }\n  ll ANS = 0;\n  ll K = MAX(A) + 1;\n  FenwickTree<Monoid_Add<int>>\
    \ bit(K);\n  for (auto&& x: A) {\n    ANS += bit.sum(x + 1, K);\n    bit.add(x,\
    \ 1);\n  }\n  return ANS;\n}\n\n// i \u756A\u76EE\uFF1AA_i \u304C\u5148\u982D\u306B\
    \u306A\u308B\u3088\u3046\u306B rotate \u3057\u305F\u3068\u304D\u306E\u8EE2\u5012\
    \u6570\ntemplate <typename T, bool SMALL>\nvi inversion_rotate(vc<T>& A) {\n \
    \ const int N = len(A);\n  if (!SMALL) {\n    auto key = A;\n    UNIQUE(key);\n\
    \    for (auto&& x: A) x = LB(key, x);\n  }\n  ll K = MAX(A) + 1;\n  ll ANS =\
    \ 0;\n  FenwickTree<Monoid_Add<int>> bit(K);\n  for (auto&& x: A) {\n    ANS +=\
    \ bit.sum(x + 1, K);\n    bit.add(x, 1);\n  }\n  vi res(N);\n  FOR(i, N) {\n \
    \   res[i] = ANS;\n    ll x = A[i];\n    ANS = ANS + bit.sum(x + 1, K) - bit.prefix_sum(x);\n\
    \  }\n  return res;\n}\n\n// inv[i][j] = inversion A[i:j) \u3067\u3042\u308B\u3088\
    \u3046\u306A (N+1, N+1) \u30C6\u30FC\u30D6\u30EB\ntemplate <typename T>\nvvc<int>\
    \ all_range_inversion(vc<T>& A) {\n  int N = len(A);\n  vv(int, dp, N + 1, N +\
    \ 1);\n  FOR_R(L, N + 1) FOR(R, L + 2, N + 1) {\n    dp[L][R] = dp[L][R - 1] +\
    \ dp[L + 1][R] - dp[L + 1][R - 1];\n    if (A[L] > A[R - 1]) ++dp[L][R];\n  }\n\
    \  return dp;\n}\n"
  code: "#pragma once\n#include \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename\
    \ T, bool SMALL>\nll inversion(vc<T> A) {\n  if (A.empty()) return 0;\n  if (!SMALL)\
    \ {\n    auto key = A;\n    UNIQUE(key);\n    for (auto&& x: A) x = LB(key, x);\n\
    \  }\n  ll ANS = 0;\n  ll K = MAX(A) + 1;\n  FenwickTree<Monoid_Add<int>> bit(K);\n\
    \  for (auto&& x: A) {\n    ANS += bit.sum(x + 1, K);\n    bit.add(x, 1);\n  }\n\
    \  return ANS;\n}\n\n// i \u756A\u76EE\uFF1AA_i \u304C\u5148\u982D\u306B\u306A\
    \u308B\u3088\u3046\u306B rotate \u3057\u305F\u3068\u304D\u306E\u8EE2\u5012\u6570\
    \ntemplate <typename T, bool SMALL>\nvi inversion_rotate(vc<T>& A) {\n  const\
    \ int N = len(A);\n  if (!SMALL) {\n    auto key = A;\n    UNIQUE(key);\n    for\
    \ (auto&& x: A) x = LB(key, x);\n  }\n  ll K = MAX(A) + 1;\n  ll ANS = 0;\n  FenwickTree<Monoid_Add<int>>\
    \ bit(K);\n  for (auto&& x: A) {\n    ANS += bit.sum(x + 1, K);\n    bit.add(x,\
    \ 1);\n  }\n  vi res(N);\n  FOR(i, N) {\n    res[i] = ANS;\n    ll x = A[i];\n\
    \    ANS = ANS + bit.sum(x + 1, K) - bit.prefix_sum(x);\n  }\n  return res;\n\
    }\n\n// inv[i][j] = inversion A[i:j) \u3067\u3042\u308B\u3088\u3046\u306A (N+1,\
    \ N+1) \u30C6\u30FC\u30D6\u30EB\ntemplate <typename T>\nvvc<int> all_range_inversion(vc<T>&\
    \ A) {\n  int N = len(A);\n  vv(int, dp, N + 1, N + 1);\n  FOR_R(L, N + 1) FOR(R,\
    \ L + 2, N + 1) {\n    dp[L][R] = dp[L][R - 1] + dp[L + 1][R] - dp[L + 1][R -\
    \ 1];\n    if (A[L] > A[R - 1]) ++dp[L][R];\n  }\n  return dp;\n}"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: seq/inversion.hpp
  requiredBy: []
  timestamp: '2023-02-12 02:06:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc190f.test.cpp
  - test/yukicoder/1838.test.cpp
  - test/aoj/ALDS1_5.test.cpp
  - test/aoj/ALDS1_2_A.test.cpp
documentation_of: seq/inversion.hpp
layout: document
redirect_from:
- /library/seq/inversion.hpp
- /library/seq/inversion.hpp.html
title: seq/inversion.hpp
---
