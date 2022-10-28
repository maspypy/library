---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/slope.hpp
    title: ds/slope.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/min_cost_matching_on_line.test.cpp
    title: test/mytest/min_cost_matching_on_line.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/slope.hpp\"\n\r\ntemplate <typename T>\r\nstruct Slope_Trick_1\
    \ {\r\n  static constexpr T LMIN = numeric_limits<T>::lowest();\r\n  static constexpr\
    \ T RMAX = numeric_limits<T>::max();\r\n  pq<T> que_l;\r\n  pqg<T> que_r;\r\n\
    \  T add_l, add_r;\r\n  T min_f;\r\n\r\n  Slope_Trick_1() : add_l(0), add_r(0),\
    \ min_f(0) {}\r\n  Slope_Trick_1(vc<T> left, vc<T> right)\r\n      : que_l(all(left)),\
    \ que_r(all(right)), add_l(0), add_r(0), min_f(0) {}\r\n\r\n  int size() { return\
    \ len(que_l) + len(que_r); }\r\n  tuple<T, T, T> get_min() { return {top_L(),\
    \ top_R(), min_f}; }\r\n\r\n  void add_const(T a) { min_f += a; }\r\n\r\n  //\
    \ (a-x)+\r\n  void add_a_minus_x(T a) {\r\n    min_f += max(T(0), a - top_R());\r\
    \n    push_R(a), push_L(pop_R());\r\n  }\r\n  // (x-a)+\r\n  void add_x_minus_a(T\
    \ a) {\r\n    min_f += max(T(0), top_L() - a);\r\n    push_L(a), push_R(pop_L());\r\
    \n  }\r\n  // |x-a|\r\n  void add_abs(T a) {\r\n    add_a_minus_x(a);\r\n    add_x_minus_a(a);\r\
    \n  }\r\n\r\n  // \u5897\u52A0\u5074\u3092\u6D88\u3057\u3066\u3001\u6E1B\u5C11\
    \u5074\u306E\u307F\u306B\u3059\u308B\r\n  void clear_inc() { que_r = pqg<T>();\
    \ }\r\n  // \u6E1B\u5C11\u5074\u3092\u6D88\u3057\u3066\u3001\u5897\u52A0\u5074\
    \u306E\u307F\u306B\u3059\u308B\r\n  void clear_dec() { que_l = pq<T>(); }\r\n\
    \  void shift(const T &a) { add_l += a, add_r += a; }\r\n\r\n  // g(x) = min_{x-b\
    \ <= y <= x-a} f(y)\r\n  void sliding_window_minimum(const T &a, const T &b) {\r\
    \n    add_l += a, add_r += b;\r\n  }\r\n\r\n  // O(size)\r\n  T eval(T x) {\r\n\
    \    T y = min_f;\r\n    pq<T> que_l_copy = que_l;\r\n    pqg<T> que_r_copy =\
    \ que_r;\r\n    while (len(que_l_copy)) { y += max<T>(0, (pick(que_l_copy) + add_l)\
    \ - x); }\r\n    while (len(que_r_copy)) { y += max<T>(0, x - (pick(que_r_copy)\
    \ + add_r)); }\r\n    return y;\r\n  }\r\n\r\n  void push_R(const T &x) {\r\n\
    \    if (x != RMAX) que_r.emplace(x - add_r);\r\n  }\r\n  void push_L(const T\
    \ &x) {\r\n    if (x != LMIN) que_l.emplace(x - add_l);\r\n  }\r\n  T top_R()\
    \ { return (len(que_r) ? que_r.top() + add_r : RMAX); }\r\n  T top_L() { return\
    \ (len(que_l) ? que_l.top() + add_l : LMIN); }\r\n  T pop_R() {\r\n    T res =\
    \ top_R();\r\n    if (len(que_r)) que_r.pop();\r\n    return res;\r\n  }\r\n \
    \ T pop_L() {\r\n    T res = top_L();\r\n    if (len(que_l)) que_l.pop();\r\n\
    \    return res;\r\n  }\r\n};\n#line 2 \"flow/min_cost_matching_on_line.hpp\"\n\
    \n// \u5EA7\u6A19 0, ..., N-1 \u306B A_i \u500B\u3042\u308B\n// \u5EA7\u6A19 0,\
    \ ..., N-1 \u3067 B_i \u500B\u307E\u3067\u53D7\u3051\u5165\u308C\u3089\u308C\u308B\
    \nll min_cost_matching_on_line_1(vi A, vi B) {\n  assert(SUM<ll>(A) <= SUM<ll>(B));\n\
    \  const int N = len(A);\n  Slope_Trick_1<ll> f(vi(N + N + 1, 0), vi());\n  FOR(i,\
    \ N) {\n    ll c = A[i] - B[i];\n    f.shift(c);\n    f.clear_inc();\n    f.add_abs(0);\n\
    \  }\n  return f.eval(0);\n}\n"
  code: "#include \"ds/slope.hpp\"\n\n// \u5EA7\u6A19 0, ..., N-1 \u306B A_i \u500B\
    \u3042\u308B\n// \u5EA7\u6A19 0, ..., N-1 \u3067 B_i \u500B\u307E\u3067\u53D7\u3051\
    \u5165\u308C\u3089\u308C\u308B\nll min_cost_matching_on_line_1(vi A, vi B) {\n\
    \  assert(SUM<ll>(A) <= SUM<ll>(B));\n  const int N = len(A);\n  Slope_Trick_1<ll>\
    \ f(vi(N + N + 1, 0), vi());\n  FOR(i, N) {\n    ll c = A[i] - B[i];\n    f.shift(c);\n\
    \    f.clear_inc();\n    f.add_abs(0);\n  }\n  return f.eval(0);\n}"
  dependsOn:
  - ds/slope.hpp
  isVerificationFile: false
  path: flow/min_cost_matching_on_line.hpp
  requiredBy: []
  timestamp: '2022-10-29 03:23:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/min_cost_matching_on_line.test.cpp
documentation_of: flow/min_cost_matching_on_line.hpp
layout: document
redirect_from:
- /library/flow/min_cost_matching_on_line.hpp
- /library/flow/min_cost_matching_on_line.hpp.html
title: flow/min_cost_matching_on_line.hpp
---
