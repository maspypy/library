---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/min_cost_matching_on_line.hpp
    title: flow/min_cost_matching_on_line.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc127f.test.cpp
    title: test/atcoder/abc127f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc217h.test.cpp
    title: test/atcoder/abc217h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc123d.test.cpp
    title: test/atcoder/arc123d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/min_cost_matching_on_line.test.cpp
    title: test/mytest/min_cost_matching_on_line.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1077.test.cpp
    title: test/yukicoder/1077.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/slope.hpp\"\nstruct Slope_Trick {\r\n  static constexpr\
    \ ll LMIN = numeric_limits<ll>::lowest() / 2;\r\n  static constexpr ll RMAX =\
    \ numeric_limits<ll>::max() / 2;\r\n  pq<ll> que_l;\r\n  pqg<ll> que_r;\r\n\r\n\
    \  ll add_l, add_r;\r\n  i128 min_f; // INF \u3092\u8DB3\u3057\u5F15\u304D\u3057\
    \u3066\u3082\u58CA\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\r\n\r\n  Slope_Trick()\
    \ : add_l(0), add_r(0), min_f(0) {}\r\n  Slope_Trick(vc<ll> left, vc<ll> right)\r\
    \n      : que_l(all(left)), que_r(all(right)), add_l(0), add_r(0), min_f(0) {}\r\
    \n\r\n  int size() { return len(que_l) + len(que_r); }\r\n  tuple<ll, ll, i128>\
    \ get_min() { return {top_L(), top_R(), min_f}; }\r\n\r\n  void add_const(ll a)\
    \ { min_f += a; }\r\n\r\n  // O(|a| log N)\r\n  void add_linear(ll a, ll b) {\r\
    \n    min_f += b;\r\n    FOR(max<int>(a, 0)) {\r\n      ll x = pop_L();\r\n  \
    \    min_f += x;\r\n      push_R(x);\r\n    }\r\n    FOR(max<int>(-a, 0)) {\r\n\
    \      ll x = pop_R();\r\n      min_f -= x;\r\n      push_L(x);\r\n    }\r\n \
    \ }\r\n\r\n  // (a-x)+\r\n  void add_a_minus_x(ll a) {\r\n    min_f += max<ll>(0,\
    \ a - top_R());\r\n    push_R(a), push_L(pop_R());\r\n  }\r\n  // (x-a)+\r\n \
    \ void add_x_minus_a(ll a) {\r\n    min_f += max<ll>(0, top_L() - a);\r\n    push_L(a),\
    \ push_R(pop_L());\r\n  }\r\n\r\n  // |x-a|\r\n  void add_abs(ll a) {\r\n    add_a_minus_x(a);\r\
    \n    add_x_minus_a(a);\r\n  }\r\n\r\n  // \u5897\u52A0\u5074\u3092\u6D88\u3057\
    \u3066\u3001\u6E1B\u5C11\u5074\u306E\u307F\u306B\u3059\u308B\r\n  void clear_right()\
    \ { que_r = pqg<ll>(); }\r\n  // \u6E1B\u5C11\u5074\u3092\u6D88\u3057\u3066\u3001\
    \u5897\u52A0\u5074\u306E\u307F\u306B\u3059\u308B\r\n  void clear_left() { que_l\
    \ = pq<ll>(); }\r\n  void shift(const ll &a) { add_l += a, add_r += a; }\r\n\r\
    \n  // g(x) = min_{x-b <= y <= x-a} f(y)\r\n  void sliding_window_minimum(const\
    \ ll &a, const ll &b) {\r\n    add_l += a, add_r += b;\r\n  }\r\n\r\n  // O(size\
    \ log(size))\r\n  i128 eval(ll x) {\r\n    i128 y = min_f;\r\n    pq<ll> que_l_copy\
    \ = que_l;\r\n    pqg<ll> que_r_copy = que_r;\r\n    while (len(que_l_copy)) {\
    \ y += max<ll>(0, (pick(que_l_copy) + add_l) - x); }\r\n    while (len(que_r_copy))\
    \ { y += max<ll>(0, x - (pick(que_r_copy) + add_r)); }\r\n    return y;\r\n  }\r\
    \n\r\n  void push_R(const ll &x) { que_r.emplace(x - add_r); }\r\n  void push_L(const\
    \ ll &x) { que_l.emplace(x - add_l); }\r\n  ll top_R() {\r\n    if (que_r.empty())\
    \ que_r.emplace(RMAX);\r\n    return que_r.top() + add_r;\r\n  }\r\n  ll top_L()\
    \ {\r\n    if (que_l.empty()) que_l.emplace(LMIN);\r\n    return que_l.top() +\
    \ add_l;\r\n  }\r\n  ll pop_R() {\r\n    ll res = top_R();\r\n    que_r.pop();\r\
    \n    return res;\r\n  }\r\n  ll pop_L() {\r\n    ll res = top_L();\r\n    que_l.pop();\r\
    \n    return res;\r\n  }\r\n\r\n  void debug() {\r\n    vi left, right;\r\n  \
    \  pq<ll> que_l_copy = que_l;\r\n    pqg<ll> que_r_copy = que_r;\r\n    while\
    \ (len(que_l_copy)) { left.eb(pick(que_l_copy) + add_l); }\r\n    while (len(que_r_copy))\
    \ { right.eb(pick(que_r_copy) + add_r); }\r\n    sort(all(left));\r\n    sort(all(right));\r\
    \n    print(\"min_f\", min_f, \"left\", left, \"right\", right);\r\n  }\r\n};\n"
  code: "struct Slope_Trick {\r\n  static constexpr ll LMIN = numeric_limits<ll>::lowest()\
    \ / 2;\r\n  static constexpr ll RMAX = numeric_limits<ll>::max() / 2;\r\n  pq<ll>\
    \ que_l;\r\n  pqg<ll> que_r;\r\n\r\n  ll add_l, add_r;\r\n  i128 min_f; // INF\
    \ \u3092\u8DB3\u3057\u5F15\u304D\u3057\u3066\u3082\u58CA\u308C\u306A\u3044\u3088\
    \u3046\u306B\u3059\u308B\r\n\r\n  Slope_Trick() : add_l(0), add_r(0), min_f(0)\
    \ {}\r\n  Slope_Trick(vc<ll> left, vc<ll> right)\r\n      : que_l(all(left)),\
    \ que_r(all(right)), add_l(0), add_r(0), min_f(0) {}\r\n\r\n  int size() { return\
    \ len(que_l) + len(que_r); }\r\n  tuple<ll, ll, i128> get_min() { return {top_L(),\
    \ top_R(), min_f}; }\r\n\r\n  void add_const(ll a) { min_f += a; }\r\n\r\n  //\
    \ O(|a| log N)\r\n  void add_linear(ll a, ll b) {\r\n    min_f += b;\r\n    FOR(max<int>(a,\
    \ 0)) {\r\n      ll x = pop_L();\r\n      min_f += x;\r\n      push_R(x);\r\n\
    \    }\r\n    FOR(max<int>(-a, 0)) {\r\n      ll x = pop_R();\r\n      min_f -=\
    \ x;\r\n      push_L(x);\r\n    }\r\n  }\r\n\r\n  // (a-x)+\r\n  void add_a_minus_x(ll\
    \ a) {\r\n    min_f += max<ll>(0, a - top_R());\r\n    push_R(a), push_L(pop_R());\r\
    \n  }\r\n  // (x-a)+\r\n  void add_x_minus_a(ll a) {\r\n    min_f += max<ll>(0,\
    \ top_L() - a);\r\n    push_L(a), push_R(pop_L());\r\n  }\r\n\r\n  // |x-a|\r\n\
    \  void add_abs(ll a) {\r\n    add_a_minus_x(a);\r\n    add_x_minus_a(a);\r\n\
    \  }\r\n\r\n  // \u5897\u52A0\u5074\u3092\u6D88\u3057\u3066\u3001\u6E1B\u5C11\u5074\
    \u306E\u307F\u306B\u3059\u308B\r\n  void clear_right() { que_r = pqg<ll>(); }\r\
    \n  // \u6E1B\u5C11\u5074\u3092\u6D88\u3057\u3066\u3001\u5897\u52A0\u5074\u306E\
    \u307F\u306B\u3059\u308B\r\n  void clear_left() { que_l = pq<ll>(); }\r\n  void\
    \ shift(const ll &a) { add_l += a, add_r += a; }\r\n\r\n  // g(x) = min_{x-b <=\
    \ y <= x-a} f(y)\r\n  void sliding_window_minimum(const ll &a, const ll &b) {\r\
    \n    add_l += a, add_r += b;\r\n  }\r\n\r\n  // O(size log(size))\r\n  i128 eval(ll\
    \ x) {\r\n    i128 y = min_f;\r\n    pq<ll> que_l_copy = que_l;\r\n    pqg<ll>\
    \ que_r_copy = que_r;\r\n    while (len(que_l_copy)) { y += max<ll>(0, (pick(que_l_copy)\
    \ + add_l) - x); }\r\n    while (len(que_r_copy)) { y += max<ll>(0, x - (pick(que_r_copy)\
    \ + add_r)); }\r\n    return y;\r\n  }\r\n\r\n  void push_R(const ll &x) { que_r.emplace(x\
    \ - add_r); }\r\n  void push_L(const ll &x) { que_l.emplace(x - add_l); }\r\n\
    \  ll top_R() {\r\n    if (que_r.empty()) que_r.emplace(RMAX);\r\n    return que_r.top()\
    \ + add_r;\r\n  }\r\n  ll top_L() {\r\n    if (que_l.empty()) que_l.emplace(LMIN);\r\
    \n    return que_l.top() + add_l;\r\n  }\r\n  ll pop_R() {\r\n    ll res = top_R();\r\
    \n    que_r.pop();\r\n    return res;\r\n  }\r\n  ll pop_L() {\r\n    ll res =\
    \ top_L();\r\n    que_l.pop();\r\n    return res;\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    vi left, right;\r\n    pq<ll> que_l_copy = que_l;\r\n    pqg<ll> que_r_copy\
    \ = que_r;\r\n    while (len(que_l_copy)) { left.eb(pick(que_l_copy) + add_l);\
    \ }\r\n    while (len(que_r_copy)) { right.eb(pick(que_r_copy) + add_r); }\r\n\
    \    sort(all(left));\r\n    sort(all(right));\r\n    print(\"min_f\", min_f,\
    \ \"left\", left, \"right\", right);\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: convex/slope.hpp
  requiredBy:
  - flow/min_cost_matching_on_line.hpp
  timestamp: '2022-12-03 09:41:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1077.test.cpp
  - test/mytest/min_cost_matching_on_line.test.cpp
  - test/atcoder/abc217h.test.cpp
  - test/atcoder/arc123d.test.cpp
  - test/atcoder/abc127f.test.cpp
documentation_of: convex/slope.hpp
layout: document
redirect_from:
- /library/convex/slope.hpp
- /library/convex/slope.hpp.html
title: convex/slope.hpp
---
