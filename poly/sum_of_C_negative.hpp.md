---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  - icon: ':question:'
    path: ds/sliding_window_aggregation.hpp
    title: ds/sliding_window_aggregation.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/arc144d.test.cpp
    title: test_atcoder/arc144d.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc160d.test.cpp
    title: test_atcoder/arc160d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/sliding_window_aggregation.hpp\"\ntemplate <class Monoid>\n\
    struct Sliding_Window_Aggregation {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  int sz = 0;\n  vc<X> dat;\n  vc<X> cum_l;\n  X cum_r;\n\
    \n  Sliding_Window_Aggregation()\n      : cum_l({Monoid::unit()}), cum_r(Monoid::unit())\
    \ {}\n\n  int size() { return sz; }\n\n  void push(X x) {\n    ++sz;\n    cum_r\
    \ = Monoid::op(cum_r, x);\n    dat.eb(x);\n  }\n\n  void pop() {\n    --sz;\n\
    \    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n      cum_l = {Monoid::unit()};\n\
    \      cum_r = Monoid::unit();\n      while (len(dat) > 1) {\n        cum_l.eb(Monoid::op(dat.back(),\
    \ cum_l.back()));\n        dat.pop_back();\n      }\n      dat.pop_back();\n \
    \   }\n  }\n\n  X lprod() { return cum_l.back(); }\n  X rprod() { return cum_r;\
    \ }\n\n  X prod() { return Monoid::op(cum_l.back(), cum_r); }\n\n  void debug()\
    \ {\n    print(\"swag\");\n    print(\"dat\", dat);\n    print(\"cum_l\", cum_l);\n\
    \    print(\"cum_r\", cum_r);\n  }\n};\n\n// \u5B9A\u6570\u500D\u306F\u76EE\u306B\
    \u898B\u3048\u3066\u9045\u304F\u306A\u308B\u306E\u3067\u3001queue \u3067\u3088\
    \u3044\u3068\u304D\u306F\u4F7F\u308F\u306A\u3044\ntemplate <class Monoid>\nstruct\
    \ SWAG_deque {\n  using X = typename Monoid::value_type;\n  using value_type =\
    \ X;\n  int sz;\n  vc<X> dat_l, dat_r;\n  vc<X> cum_l, cum_r;\n\n  SWAG_deque()\
    \ : sz(0), cum_l({Monoid::unit()}), cum_r({Monoid::unit()}) {}\n\n  int size()\
    \ { return sz; }\n\n  void push_back(X x) {\n    ++sz;\n    dat_r.eb(x);\n   \
    \ cum_r.eb(Monoid::op(cum_r.back(), x));\n  }\n\n  void push_front(X x) {\n  \
    \  ++sz;\n    dat_l.eb(x);\n    cum_l.eb(Monoid::op(x, cum_l.back()));\n  }\n\n\
    \  void push(X x) { push_back(x); }\n\n  void clear() {\n    sz = 0;\n    dat_l.clear(),\
    \ dat_r.clear();\n    cum_l = {Monoid::unit()}, cum_r = {Monoid::unit()};\n  }\n\
    \n  void pop_front() {\n    if (sz == 1) return clear();\n    if (dat_l.empty())\
    \ rebuild();\n    --sz;\n    dat_l.pop_back();\n    cum_l.pop_back();\n  }\n\n\
    \  void pop_back() {\n    if (sz == 1) return clear();\n    if (dat_r.empty())\
    \ rebuild();\n    --sz;\n    dat_r.pop_back();\n    cum_r.pop_back();\n  }\n\n\
    \  void pop() { pop_front(); }\n\n  X lprod() { return cum_l.back(); }\n  X rprod()\
    \ { return cum_r.back(); }\n  X prod() { return Monoid::op(cum_l.back(), cum_r.back());\
    \ }\n  X prod_all() { return prod(); }\n\n  void debug() {\n    print(\"swag\"\
    );\n    print(\"dat_l\", dat_l);\n    print(\"dat_r\", dat_r);\n    print(\"cum_l\"\
    , cum_l);\n    print(\"cum_r\", cum_r);\n  }\n\nprivate:\n  void rebuild() {\n\
    \    vc<X> X;\n    FOR_R(i, len(dat_l)) X.eb(dat_l[i]);\n    X.insert(X.end(),\
    \ all(dat_r));\n    clear();\n    int m = len(X) / 2;\n    FOR_R(i, m) push_front(X[i]);\n\
    \    FOR(i, m, len(X)) push_back(X[i]);\n    assert(sz == len(X));\n  }\n};\n\
    #line 2 \"alg/monoid/mul.hpp\"\n\r\ntemplate <class T>\r\nstruct Monoid_Mul {\r\
    \n  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"poly/sum_of_C_negative.hpp\"\
    \n\n// calculate [x^N] f(x)(1-x)^{-K} in O(deg(f)+K).\ntemplate <typename mint>\n\
    mint sum_of_C_negative(ll N, ll K, vc<mint>& f) {\n  assert(K >= 0);\n  if (N\
    \ < 0) return mint(1);\n  if (K == 0) { return (N < len(f) ? f[N] : mint(0));\
    \ }\n  K -= 1;\n  Sliding_Window_Aggregation<Monoid_Mul<mint>> seg;\n  FOR(i,\
    \ K) seg.push(N + K - i);\n  mint ANS = 0;\n  FOR(i, len(f)) {\n    ANS += f[i]\
    \ * seg.prod();\n    seg.push(N - i);\n    seg.pop();\n  }\n  return ANS * fact_inv<mint>(K);\n\
    }\n"
  code: "#include \"ds/sliding_window_aggregation.hpp\"\n#include \"alg/monoid/mul.hpp\"\
    \n\n// calculate [x^N] f(x)(1-x)^{-K} in O(deg(f)+K).\ntemplate <typename mint>\n\
    mint sum_of_C_negative(ll N, ll K, vc<mint>& f) {\n  assert(K >= 0);\n  if (N\
    \ < 0) return mint(1);\n  if (K == 0) { return (N < len(f) ? f[N] : mint(0));\
    \ }\n  K -= 1;\n  Sliding_Window_Aggregation<Monoid_Mul<mint>> seg;\n  FOR(i,\
    \ K) seg.push(N + K - i);\n  mint ANS = 0;\n  FOR(i, len(f)) {\n    ANS += f[i]\
    \ * seg.prod();\n    seg.push(N - i);\n    seg.pop();\n  }\n  return ANS * fact_inv<mint>(K);\n\
    }\n"
  dependsOn:
  - ds/sliding_window_aggregation.hpp
  - alg/monoid/mul.hpp
  isVerificationFile: false
  path: poly/sum_of_C_negative.hpp
  requiredBy: []
  timestamp: '2023-05-26 18:53:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc144d.test.cpp
  - test_atcoder/arc160d.test.cpp
documentation_of: poly/sum_of_C_negative.hpp
layout: document
redirect_from:
- /library/poly/sum_of_C_negative.hpp
- /library/poly/sum_of_C_negative.hpp.html
title: poly/sum_of_C_negative.hpp
---
