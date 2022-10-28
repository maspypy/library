---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: flow/min_cost_matching_on_line.hpp
    title: flow/min_cost_matching_on_line.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc127f.test.cpp
    title: test/atcoder/abc127f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc217h.test.cpp
    title: test/atcoder/abc217h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc123d.test.cpp
    title: test/atcoder/arc123d.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1077.test.cpp
    title: test/yukicoder/1077.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \    return res;\r\n  }\r\n};\n"
  code: "\r\ntemplate <typename T>\r\nstruct Slope_Trick_1 {\r\n  static constexpr\
    \ T LMIN = numeric_limits<T>::lowest();\r\n  static constexpr T RMAX = numeric_limits<T>::max();\r\
    \n  pq<T> que_l;\r\n  pqg<T> que_r;\r\n  T add_l, add_r;\r\n  T min_f;\r\n\r\n\
    \  Slope_Trick_1() : add_l(0), add_r(0), min_f(0) {}\r\n  Slope_Trick_1(vc<T>\
    \ left, vc<T> right)\r\n      : que_l(all(left)), que_r(all(right)), add_l(0),\
    \ add_r(0), min_f(0) {}\r\n\r\n  int size() { return len(que_l) + len(que_r);\
    \ }\r\n  tuple<T, T, T> get_min() { return {top_L(), top_R(), min_f}; }\r\n\r\n\
    \  void add_const(T a) { min_f += a; }\r\n\r\n  // (a-x)+\r\n  void add_a_minus_x(T\
    \ a) {\r\n    min_f += max(T(0), a - top_R());\r\n    push_R(a), push_L(pop_R());\r\
    \n  }\r\n  // (x-a)+\r\n  void add_x_minus_a(T a) {\r\n    min_f += max(T(0),\
    \ top_L() - a);\r\n    push_L(a), push_R(pop_L());\r\n  }\r\n  // |x-a|\r\n  void\
    \ add_abs(T a) {\r\n    add_a_minus_x(a);\r\n    add_x_minus_a(a);\r\n  }\r\n\r\
    \n  // \u5897\u52A0\u5074\u3092\u6D88\u3057\u3066\u3001\u6E1B\u5C11\u5074\u306E\
    \u307F\u306B\u3059\u308B\r\n  void clear_inc() { que_r = pqg<T>(); }\r\n  // \u6E1B\
    \u5C11\u5074\u3092\u6D88\u3057\u3066\u3001\u5897\u52A0\u5074\u306E\u307F\u306B\
    \u3059\u308B\r\n  void clear_dec() { que_l = pq<T>(); }\r\n  void shift(const\
    \ T &a) { add_l += a, add_r += a; }\r\n\r\n  // g(x) = min_{x-b <= y <= x-a} f(y)\r\
    \n  void sliding_window_minimum(const T &a, const T &b) {\r\n    add_l += a, add_r\
    \ += b;\r\n  }\r\n\r\n  // O(size)\r\n  T eval(T x) {\r\n    T y = min_f;\r\n\
    \    pq<T> que_l_copy = que_l;\r\n    pqg<T> que_r_copy = que_r;\r\n    while\
    \ (len(que_l_copy)) { y += max<T>(0, (pick(que_l_copy) + add_l) - x); }\r\n  \
    \  while (len(que_r_copy)) { y += max<T>(0, x - (pick(que_r_copy) + add_r)); }\r\
    \n    return y;\r\n  }\r\n\r\n  void push_R(const T &x) {\r\n    if (x != RMAX)\
    \ que_r.emplace(x - add_r);\r\n  }\r\n  void push_L(const T &x) {\r\n    if (x\
    \ != LMIN) que_l.emplace(x - add_l);\r\n  }\r\n  T top_R() { return (len(que_r)\
    \ ? que_r.top() + add_r : RMAX); }\r\n  T top_L() { return (len(que_l) ? que_l.top()\
    \ + add_l : LMIN); }\r\n  T pop_R() {\r\n    T res = top_R();\r\n    if (len(que_r))\
    \ que_r.pop();\r\n    return res;\r\n  }\r\n  T pop_L() {\r\n    T res = top_L();\r\
    \n    if (len(que_l)) que_l.pop();\r\n    return res;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/slope.hpp
  requiredBy:
  - flow/min_cost_matching_on_line.hpp
  timestamp: '2022-10-29 03:23:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1077.test.cpp
  - test/atcoder/abc217h.test.cpp
  - test/atcoder/abc127f.test.cpp
  - test/atcoder/arc123d.test.cpp
documentation_of: ds/slope.hpp
layout: document
redirect_from:
- /library/ds/slope.hpp
- /library/ds/slope.hpp.html
title: ds/slope.hpp
---
