---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1638/problem/E
    - https://codeforces.com/contest/897/problem/E
  bundledCode: "#line 1 \"ds/intervals.hpp\"\n// https://codeforces.com/contest/1638/problem/E\n\
    // https://codeforces.com/contest/897/problem/E\n// \u6301\u3064\u5024\u306E\u30BF\
    \u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7 X\n// \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\u6307\u5B9A\u3059\u308B\ntemplate\
    \ <typename T = ll, typename X = ll>\nstruct Intervals {\n  static constexpr X\
    \ LLIM = numeric_limits<X>::lowest();\n  static constexpr X RLIM = numeric_limits<X>::max();\n\
    \  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\u500B\
    \u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  X total_len;\n  map<X,\
    \ T> dat;\n\n  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0)\
    \ {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n  }\n\n  tuple<X, X,\
    \ T> get(X x) {\n    auto it = dat.upper_bound(x);\n    X r = (*it).fi;\n    auto\
    \ [l, t] = *prev(it);\n    return {l, r, t};\n  }\n\n  template <typename ADD,\
    \ typename RM>\n  void set(X L, X R, T t, ADD& add_f, RM& rm_f) {\n    if (L ==\
    \ R) return;\n    assert(L < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\
    \u66F4\u3059\u308B\n    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\
    \u308A\u5408\u3046\u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<X, X, T>>\
    \ tmp;\n    auto it = prev(dat.lower_bound(L));\n    while (1) {\n      auto [l,\
    \ t] = *it;\n      if (R < l) break;\n      it = next(it);\n      X r = (*it).fi;\n\
    \      tmp.eb(l, r, t);\n    }\n    auto [lx, _, lt] = tmp[0];\n    auto [__,\
    \ rx, rt] = tmp.back();\n    // \u3068\u308A\u3042\u3048\u305A\u5168\u90E8\u524A\
    \u9664\n    for (auto&& [l, r, t]: tmp) {\n      dat.erase(l);\n      if (t ==\
    \ none_val) continue;\n      total_num--;\n      total_len -= r - l;\n      rm_f(l,\
    \ r, t);\n    }\n    if (lt == t) chmin(L, lx);\n    if (rt == t) chmax(R, rx);\n\
    \    if (lx < L) {\n      // [lx, L)\n      dat[lx] = lt;\n      if (lt != none_val)\
    \ {\n        total_num++;\n        total_len += L - lx;\n        add_f(lx, L,\
    \ lt);\n      }\n    }\n    if (R < rx) {\n      // [R, rx)\n      dat[R] = rt;\n\
    \      if (rt != none_val) {\n        total_num++;\n        total_len += rx -\
    \ R;\n        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    dat[L] = t;\n\
    \    if (t != none_val) {\n      total_num++;\n      total_len += R - L;\n   \
    \   add_f(L, R, t);\n    }\n  }\n\n  void set(X L, X R, T t = 1) {\n    auto f\
    \ = [&](X L, X R, T t) -> void {};\n    set(L, R, t, f, f);\n  }\n\n  void erase(X\
    \ L, X R) {\n    auto f = [&](X L, X R, T t) -> void {};\n    set(L, R, none_val,\
    \ f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\u30BF (l, r, t) \u3092\u5168\
    \u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<X, X, T>> get(X L, X R) {\n    vc<tuple<X,\
    \ X, T>> res;\n    auto it = prev(dat.lower_bound(L));\n    while (1) {\n    \
    \  auto [l, t] = *it;\n      if (R <= l) break;\n      it = next(it);\n      X\
    \ r = (*it).fi;\n      X l0 = max(l, L);\n      X r0 = min(r, R);\n      if (l0\
    \ < r0) res.eb(l0, r0, t);\n    }\n    return res;\n  }\n\n  vc<tuple<X, X, T>>\
    \ get_all() {\n    return get(LLIM + 1, RLIM);\n  }\n\n  void debug() {\n    auto\
    \ it = dat.begin();\n    print(\"Intervals\");\n    print(\"total_num\", total_num);\n\
    \    print(\"total_len\", total_len);\n    while (1) {\n      auto [l, t] = *it;\n\
    \      ++it;\n      if (it == dat.end()) break;\n      X r = (*it).fi;\n     \
    \ print(\"l, r, t\", l, r, t);\n    }\n  }\n};\n"
  code: "// https://codeforces.com/contest/1638/problem/E\n// https://codeforces.com/contest/897/problem/E\n\
    // \u6301\u3064\u5024\u306E\u30BF\u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7\
    \ X\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\
    \u6307\u5B9A\u3059\u308B\ntemplate <typename T = ll, typename X = ll>\nstruct\
    \ Intervals {\n  static constexpr X LLIM = numeric_limits<X>::lowest();\n  static\
    \ constexpr X RLIM = numeric_limits<X>::max();\n  const T none_val;\n  // none_val\
    \ \u3067\u306A\u3044\u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\
    \n  int total_num;\n  X total_len;\n  map<X, T> dat;\n\n  Intervals(T none_val)\
    \ : none_val(none_val), total_num(0), total_len(0) {\n    dat[LLIM] = none_val;\n\
    \    dat[RLIM] = none_val;\n  }\n\n  tuple<X, X, T> get(X x) {\n    auto it =\
    \ dat.upper_bound(x);\n    X r = (*it).fi;\n    auto [l, t] = *prev(it);\n   \
    \ return {l, r, t};\n  }\n\n  template <typename ADD, typename RM>\n  void set(X\
    \ L, X R, T t, ADD& add_f, RM& rm_f) {\n    if (L == R) return;\n    assert(L\
    \ < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\u66F4\u3059\u308B\n\
    \    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\u308A\u5408\u3046\
    \u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<X, X, T>> tmp;\n    auto it\
    \ = prev(dat.lower_bound(L));\n    while (1) {\n      auto [l, t] = *it;\n   \
    \   if (R < l) break;\n      it = next(it);\n      X r = (*it).fi;\n      tmp.eb(l,\
    \ r, t);\n    }\n    auto [lx, _, lt] = tmp[0];\n    auto [__, rx, rt] = tmp.back();\n\
    \    // \u3068\u308A\u3042\u3048\u305A\u5168\u90E8\u524A\u9664\n    for (auto&&\
    \ [l, r, t]: tmp) {\n      dat.erase(l);\n      if (t == none_val) continue;\n\
    \      total_num--;\n      total_len -= r - l;\n      rm_f(l, r, t);\n    }\n\
    \    if (lt == t) chmin(L, lx);\n    if (rt == t) chmax(R, rx);\n    if (lx <\
    \ L) {\n      // [lx, L)\n      dat[lx] = lt;\n      if (lt != none_val) {\n \
    \       total_num++;\n        total_len += L - lx;\n        add_f(lx, L, lt);\n\
    \      }\n    }\n    if (R < rx) {\n      // [R, rx)\n      dat[R] = rt;\n   \
    \   if (rt != none_val) {\n        total_num++;\n        total_len += rx - R;\n\
    \        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    dat[L] = t;\n \
    \   if (t != none_val) {\n      total_num++;\n      total_len += R - L;\n    \
    \  add_f(L, R, t);\n    }\n  }\n\n  void set(X L, X R, T t = 1) {\n    auto f\
    \ = [&](X L, X R, T t) -> void {};\n    set(L, R, t, f, f);\n  }\n\n  void erase(X\
    \ L, X R) {\n    auto f = [&](X L, X R, T t) -> void {};\n    set(L, R, none_val,\
    \ f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\u30BF (l, r, t) \u3092\u5168\
    \u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<X, X, T>> get(X L, X R) {\n    vc<tuple<X,\
    \ X, T>> res;\n    auto it = prev(dat.lower_bound(L));\n    while (1) {\n    \
    \  auto [l, t] = *it;\n      if (R <= l) break;\n      it = next(it);\n      X\
    \ r = (*it).fi;\n      X l0 = max(l, L);\n      X r0 = min(r, R);\n      if (l0\
    \ < r0) res.eb(l0, r0, t);\n    }\n    return res;\n  }\n\n  vc<tuple<X, X, T>>\
    \ get_all() {\n    return get(LLIM + 1, RLIM);\n  }\n\n  void debug() {\n    auto\
    \ it = dat.begin();\n    print(\"Intervals\");\n    print(\"total_num\", total_num);\n\
    \    print(\"total_len\", total_len);\n    while (1) {\n      auto [l, t] = *it;\n\
    \      ++it;\n      if (it == dat.end()) break;\n      X r = (*it).fi;\n     \
    \ print(\"l, r, t\", l, r, t);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/intervals.hpp
  requiredBy: []
  timestamp: '2022-05-29 02:01:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/intervals.hpp
layout: document
redirect_from:
- /library/ds/intervals.hpp
- /library/ds/intervals.hpp.html
title: ds/intervals.hpp
---
