---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convex/slope_trick/slope_trick_0.hpp
    title: convex/slope_trick/slope_trick_0.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/min_cost_matching_on_line.test.cpp
    title: test/1_mytest/min_cost_matching_on_line.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/slope_trick/slope_trick_0.hpp\"\n// \u6700\u521D\u306B\
    \u4F5C\u3063\u305F\u6700\u3082\u30B7\u30F3\u30D7\u30EB\u306A\u3084\u3064\u3092\
    \u4E00\u5FDC\u6B8B\u3057\u3066\u304A\u304F\r\nstruct Slope_Trick_0 {\r\n  static\
    \ constexpr ll LMIN = -infty<ll>;\r\n  static constexpr ll RMAX = infty<ll>;\r\
    \n  pq_max<ll> que_l;\r\n  pq_min<ll> que_r;\r\n\r\n  ll add_l, add_r;\r\n  i128\
    \ min_f;  // infty \u3092\u8DB3\u3057\u5F15\u304D\u3057\u3066\u3082\u58CA\u308C\
    \u306A\u3044\u3088\u3046\u306B i128 \u306B\u3059\u308B\r\n\r\n  Slope_Trick_0()\
    \ : add_l(0), add_r(0), min_f(0) {}\r\n\r\n  int size() { return len(que_l) +\
    \ len(que_r); }\r\n  tuple<ll, ll, i128> get_min() { return {top_L(), top_R(),\
    \ min_f}; }\r\n\r\n  void add_const(ll a) { min_f += a; }\r\n\r\n  // O(|a| log\
    \ N)\r\n  void add_linear(ll a, ll b) {\r\n    min_f += b;\r\n    FOR(max<int>(a,\
    \ 0)) {\r\n      ll x = pop_L();\r\n      min_f += x;\r\n      push_R(x);\r\n\
    \    }\r\n    FOR(max<int>(-a, 0)) {\r\n      ll x = pop_R();\r\n      min_f -=\
    \ x;\r\n      push_L(x);\r\n    }\r\n  }\r\n\r\n  // (a-x)+\r\n  void add_a_minus_x(ll\
    \ a) {\r\n    min_f += max<ll>(0, a - top_R());\r\n    push_R(a), push_L(pop_R());\r\
    \n  }\r\n  // (x-a)+\r\n  void add_x_minus_a(ll a) {\r\n    min_f += max<ll>(0,\
    \ top_L() - a);\r\n    push_L(a), push_R(pop_L());\r\n  }\r\n\r\n  // |x-a|\r\n\
    \  void add_abs(ll a) { add_a_minus_x(a), add_x_minus_a(a); }\r\n\r\n  // \u5897\
    \u52A0\u5074\u3092\u6D88\u3057\u3066\u3001\u6E1B\u5C11\u5074\u306E\u307F\u306B\
    \u3059\u308B\r\n  void clear_right() { que_r = pq_min<ll>(); }\r\n  // \u6E1B\u5C11\
    \u5074\u3092\u6D88\u3057\u3066\u3001\u5897\u52A0\u5074\u306E\u307F\u306B\u3059\
    \u308B\r\n  void clear_left() { que_l = pq_max<ll>(); }\r\n  void shift(const\
    \ ll &a) { add_l += a, add_r += a; }\r\n\r\n  // g(x) = min_{x-b <= y <= x-a}\
    \ f(y)\r\n  void sliding_window_minimum(const ll &a, const ll &b) {\r\n    assert(a\
    \ <= b);\r\n    add_l += a, add_r += b;\r\n  }\r\n\r\n  // O(size log(size))\r\
    \n  i128 eval(ll x) {\r\n    i128 y = min_f;\r\n    pq_max<ll> que_l_copy = que_l;\r\
    \n    pq_min<ll> que_r_copy = que_r;\r\n    while (len(que_l_copy)) {\r\n    \
    \  y += max<ll>(0, (POP(que_l_copy) + add_l) - x);\r\n    }\r\n    while (len(que_r_copy))\
    \ {\r\n      y += max<ll>(0, x - (POP(que_r_copy) + add_r));\r\n    }\r\n    return\
    \ y;\r\n  }\r\n\r\n  void push_R(const ll &x) { que_r.emplace(x - add_r); }\r\n\
    \  void push_L(const ll &x) { que_l.emplace(x - add_l); }\r\n  ll top_R() {\r\n\
    \    if (que_r.empty()) que_r.emplace(RMAX);\r\n    return que_r.top() + add_r;\r\
    \n  }\r\n  ll top_L() {\r\n    if (que_l.empty()) que_l.emplace(LMIN);\r\n   \
    \ return que_l.top() + add_l;\r\n  }\r\n  ll pop_R() {\r\n    ll res = top_R();\r\
    \n    que_r.pop();\r\n    return res;\r\n  }\r\n  ll pop_L() {\r\n    ll res =\
    \ top_L();\r\n    que_l.pop();\r\n    return res;\r\n  }\r\n\r\n#ifdef FASTIO\r\
    \n  void debug() {\r\n    vi left, right;\r\n    pq_max<ll> que_l_copy = que_l;\r\
    \n    pq_min<ll> que_r_copy = que_r;\r\n    while (len(que_l_copy)) {\r\n    \
    \  left.eb(POP(que_l_copy) + add_l);\r\n    }\r\n    while (len(que_r_copy)) {\r\
    \n      right.eb(POP(que_r_copy) + add_r);\r\n    }\r\n    sort(all(left));\r\n\
    \    sort(all(right));\r\n    print(\"min_f\", min_f, \"left\", left, \"right\"\
    , right);\r\n  }\r\n#endif\r\n};\n#line 2 \"flow/min_cost_matching_on_line.hpp\"\
    \n\n// \u5EA7\u6A19 0, ..., N-1 \u306B A_i \u500B\u3042\u308B\n// \u5EA7\u6A19\
    \ 0, ..., N-1 \u3067 B_i \u500B\u307E\u3067\u53D7\u3051\u5165\u308C\u3089\u308C\
    \u308B\nll min_cost_matching_on_line_1(vi A, vi B) {\n  assert(SUM<ll>(A) <= SUM<ll>(B));\n\
    \  const int N = len(A);\n  Slope_Trick_0 f;\n  FOR(N + 1) f.add_a_minus_x(0);\n\
    \  FOR(i, N) {\n    ll c = A[i] - B[i];\n    f.shift(c);\n    f.clear_right();\n\
    \    f.add_abs(0);\n  }\n  return f.eval(0);\n}\n"
  code: "#include \"convex/slope_trick/slope_trick_0.hpp\"\n\n// \u5EA7\u6A19 0, ...,\
    \ N-1 \u306B A_i \u500B\u3042\u308B\n// \u5EA7\u6A19 0, ..., N-1 \u3067 B_i \u500B\
    \u307E\u3067\u53D7\u3051\u5165\u308C\u3089\u308C\u308B\nll min_cost_matching_on_line_1(vi\
    \ A, vi B) {\n  assert(SUM<ll>(A) <= SUM<ll>(B));\n  const int N = len(A);\n \
    \ Slope_Trick_0 f;\n  FOR(N + 1) f.add_a_minus_x(0);\n  FOR(i, N) {\n    ll c\
    \ = A[i] - B[i];\n    f.shift(c);\n    f.clear_right();\n    f.add_abs(0);\n \
    \ }\n  return f.eval(0);\n}\n"
  dependsOn:
  - convex/slope_trick/slope_trick_0.hpp
  isVerificationFile: false
  path: flow/min_cost_matching_on_line.hpp
  requiredBy: []
  timestamp: '2025-07-04 07:28:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/min_cost_matching_on_line.test.cpp
documentation_of: flow/min_cost_matching_on_line.hpp
layout: document
redirect_from:
- /library/flow/min_cost_matching_on_line.hpp
- /library/flow/min_cost_matching_on_line.hpp.html
title: flow/min_cost_matching_on_line.hpp
---
