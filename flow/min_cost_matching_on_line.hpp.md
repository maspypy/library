---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    links:
    - https://github.com/maspypy/library/blob/main/flow/min_cost_matching_on_line.hpp
  bundledCode: "#line 1 \"flow/min_cost_matching_on_line.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/flow/min_cost_matching_on_line.hpp\n\
    #line 1 \"convex/slope_trick/slope_trick_0.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/convex/slope_trick/slope_trick_0.hpp\n\
    // \u6700\u521D\u306B\u4F5C\u3063\u305F\u6700\u3082\u30B7\u30F3\u30D7\u30EB\u306A\
    \u3084\u3064\u3092\u4E00\u5FDC\u6B8B\u3057\u3066\u304A\u304F\nstruct Slope_Trick_0\
    \ {\n  static constexpr ll LMIN = -infty<ll>;\n  static constexpr ll RMAX = infty<ll>;\n\
    \  pq_max<ll> que_l;\n  pq_min<ll> que_r;\n\n  ll add_l, add_r;\n  i128 min_f;\
    \  // infty \u3092\u8DB3\u3057\u5F15\u304D\u3057\u3066\u3082\u58CA\u308C\u306A\
    \u3044\u3088\u3046\u306B i128 \u306B\u3059\u308B\n\n  Slope_Trick_0() : add_l(0),\
    \ add_r(0), min_f(0) {}\n\n  int size() { return len(que_l) + len(que_r); }\n\
    \  tuple<ll, ll, i128> get_min() { return {top_L(), top_R(), min_f}; }\n\n  void\
    \ add_const(ll a) { min_f += a; }\n\n  // O(|a| log N)\n  void add_linear(ll a,\
    \ ll b) {\n    min_f += b;\n    FOR(max<int>(a, 0)) {\n      ll x = pop_L();\n\
    \      min_f += x;\n      push_R(x);\n    }\n    FOR(max<int>(-a, 0)) {\n    \
    \  ll x = pop_R();\n      min_f -= x;\n      push_L(x);\n    }\n  }\n\n  // (a-x)+\n\
    \  void add_a_minus_x(ll a) {\n    min_f += max<ll>(0, a - top_R());\n    push_R(a),\
    \ push_L(pop_R());\n  }\n  // (x-a)+\n  void add_x_minus_a(ll a) {\n    min_f\
    \ += max<ll>(0, top_L() - a);\n    push_L(a), push_R(pop_L());\n  }\n\n  // |x-a|\n\
    \  void add_abs(ll a) { add_a_minus_x(a), add_x_minus_a(a); }\n\n  // \u5897\u52A0\
    \u5074\u3092\u6D88\u3057\u3066\u3001\u6E1B\u5C11\u5074\u306E\u307F\u306B\u3059\
    \u308B\n  void clear_right() { que_r = pq_min<ll>(); }\n  // \u6E1B\u5C11\u5074\
    \u3092\u6D88\u3057\u3066\u3001\u5897\u52A0\u5074\u306E\u307F\u306B\u3059\u308B\
    \n  void clear_left() { que_l = pq_max<ll>(); }\n  void shift(const ll &a) { add_l\
    \ += a, add_r += a; }\n\n  // g(x) = min_{x-b <= y <= x-a} f(y)\n  void sliding_window_minimum(const\
    \ ll &a, const ll &b) {\n    assert(a <= b);\n    add_l += a, add_r += b;\n  }\n\
    \n  // O(size log(size))\n  i128 eval(ll x) {\n    i128 y = min_f;\n    pq_max<ll>\
    \ que_l_copy = que_l;\n    pq_min<ll> que_r_copy = que_r;\n    while (len(que_l_copy))\
    \ {\n      y += max<ll>(0, (POP(que_l_copy) + add_l) - x);\n    }\n    while (len(que_r_copy))\
    \ {\n      y += max<ll>(0, x - (POP(que_r_copy) + add_r));\n    }\n    return\
    \ y;\n  }\n\n  void push_R(const ll &x) { que_r.emplace(x - add_r); }\n  void\
    \ push_L(const ll &x) { que_l.emplace(x - add_l); }\n  ll top_R() {\n    if (que_r.empty())\
    \ que_r.emplace(RMAX);\n    return que_r.top() + add_r;\n  }\n  ll top_L() {\n\
    \    if (que_l.empty()) que_l.emplace(LMIN);\n    return que_l.top() + add_l;\n\
    \  }\n  ll pop_R() {\n    ll res = top_R();\n    que_r.pop();\n    return res;\n\
    \  }\n  ll pop_L() {\n    ll res = top_L();\n    que_l.pop();\n    return res;\n\
    \  }\n\n#ifdef FASTIO\n  void debug() {\n    vi left, right;\n    pq_max<ll> que_l_copy\
    \ = que_l;\n    pq_min<ll> que_r_copy = que_r;\n    while (len(que_l_copy)) {\n\
    \      left.eb(POP(que_l_copy) + add_l);\n    }\n    while (len(que_r_copy)) {\n\
    \      right.eb(POP(que_r_copy) + add_r);\n    }\n    sort(all(left));\n    sort(all(right));\n\
    \    print(\"min_f\", min_f, \"left\", left, \"right\", right);\n  }\n#endif\n\
    };\n#line 3 \"flow/min_cost_matching_on_line.hpp\"\n\n// \u5EA7\u6A19 0, ...,\
    \ N-1 \u306B A_i \u500B\u3042\u308B\n// \u5EA7\u6A19 0, ..., N-1 \u3067 B_i \u500B\
    \u307E\u3067\u53D7\u3051\u5165\u308C\u3089\u308C\u308B\nll min_cost_matching_on_line(vi\
    \ A, vi B) {\n  assert(SUM<ll>(A) <= SUM<ll>(B));\n  const int N = len(A);\n \
    \ Slope_Trick_0 f;\n  FOR(N + 1) f.add_a_minus_x(0);\n  FOR(i, N) {\n    ll c\
    \ = A[i] - B[i];\n    f.shift(c);\n    f.clear_right();\n    f.add_abs(0);\n \
    \ }\n  return f.eval(0);\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/flow/min_cost_matching_on_line.hpp\n\
    #include \"convex/slope_trick/slope_trick_0.hpp\"\n\n// \u5EA7\u6A19 0, ..., N-1\
    \ \u306B A_i \u500B\u3042\u308B\n// \u5EA7\u6A19 0, ..., N-1 \u3067 B_i \u500B\
    \u307E\u3067\u53D7\u3051\u5165\u308C\u3089\u308C\u308B\nll min_cost_matching_on_line(vi\
    \ A, vi B) {\n  assert(SUM<ll>(A) <= SUM<ll>(B));\n  const int N = len(A);\n \
    \ Slope_Trick_0 f;\n  FOR(N + 1) f.add_a_minus_x(0);\n  FOR(i, N) {\n    ll c\
    \ = A[i] - B[i];\n    f.shift(c);\n    f.clear_right();\n    f.add_abs(0);\n \
    \ }\n  return f.eval(0);\n}\n"
  dependsOn:
  - convex/slope_trick/slope_trick_0.hpp
  isVerificationFile: false
  path: flow/min_cost_matching_on_line.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
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
