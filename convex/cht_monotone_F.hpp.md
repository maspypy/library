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
    - https://contest.ucup.ac/contest/1893/problem/9737
  bundledCode: "#line 1 \"convex/cht_monotone_F.hpp\"\n// x=INF \u3067\u5C0F\u3055\
    \u304F\u306A\u308B\uFF08\u50BE\u304D\u304C\u5C0F\u3055\u3044\uFF09\u3082\u306E\
    \u304C back\n// O(QlogQ) func call or O(Q) func call + O(Q) find\n// https://contest.ucup.ac/contest/1893/problem/9737\n\
    // push front \u4F7F\u3063\u305F\u3053\u3068\u306A\u3057\ntemplate <typename F,\
    \ bool MINIMIZE>\nstruct CHT_monotone_F {\n  using T = typename F::value_type;\n\
    \  ll L, R;\n\n  // func, L, R\n  vc<tuple<F, ll, ll>> dat;\n  CHT_monotone_F(ll\
    \ L, ll R) : L(L), R(R) {}\n\n  void push_back(F f) {\n    auto find = [&](F f,\
    \ F g, ll a, ll b) -> ll { return binary_search([&](ll x) -> bool { return select_right(f,\
    \ g, x); }, b, a, 0); };\n    push_back_with_find(f, find);\n  }\n\n  void push_front(F\
    \ f) {\n    auto find = [&](F f, F g, ll a, ll b) -> ll { return binary_search([&](ll\
    \ x) -> bool { return select_right(f, g, x); }, b, a, 0); };\n    push_front_with_find(f,\
    \ find);\n  }\n\n  // find(f,g,a,b): f(a)<=g(a), g(b)<f(b) \u306E\u3068\u304D\
    \ g(x)<f(x) \u3068\u306A\u308B\u6700\u5C0F\u306E x\n  template <typename FIND>\n\
    \  void push_back_with_find(F g, FIND find) {\n    while (1) {\n      if (dat.empty())\
    \ {\n        dat.eb(g, L, R);\n        break;\n      }\n      auto [f, a, b] =\
    \ dat.back();\n      if (select_right(f, g, a)) {\n        dat.pop_back();\n \
    \       if (len(dat)) get<2>(dat.back()) = b;\n        continue;\n      }\n  \
    \    if (!select_right(f, g, b - 1)) { break; }\n      ll x = find(f, g, a, b\
    \ - 1);\n      get<2>(dat.back()) = x;\n      dat.emplace_back(g, x, b);\n   \
    \   break;\n    }\n  }\n\n  // find(f,g,a,b): f(a)<=g(a), g(b)<f(b) \u306E\u3068\
    \u304D g(x)<f(x) \u3068\u306A\u308B\u6700\u5C0F\u306E x\n  template <typename\
    \ FIND>\n  void push_front_with_find(F f, FIND find) {\n    while (1) {\n    \
    \  if (dat.empty()) {\n        dat.eb(f, L, R);\n        break;\n      }\n   \
    \   auto [g, a, b] = dat.front();\n      if (!select_right(f, g, b - 1)) {\n \
    \       dat.pop_front();\n        if (len(dat)) get<1>(dat.front()) = L;\n   \
    \     continue;\n      }\n      if (select_right(f, g, a)) break;\n      ll x\
    \ = find(f, g, a, b - 1);\n      get<1>(dat.front()) = x;\n      dat.emplace_front(f,\
    \ a, x);\n      break;\n    }\n  }\n\n  T query(ll x) {\n    assert(!dat.empty());\n\
    \    int k = binary_search([&](int i) -> bool { return get<1>(dat[i]) <= x; },\
    \ 0, len(dat));\n    auto [f, a, b] = dat[k];\n    assert(a <= x && x < b);\n\
    \    return f(x);\n  }\n\n  int last = 0;\n  T query_monotone(ll x) {\n    assert(!dat.empty());\n\
    \    chmin(last, len(dat) - 1);\n    while (1) {\n      auto [f, l, r] = dat[last];\n\
    \      if (x < l) --last;\n      elif (r <= x)++ last;\n      else break;\n  \
    \  }\n    auto [f, l, r] = dat[last];\n    return f(x);\n  }\n\nprivate:\n  bool\
    \ select_right(F L, F R, ll x) { return (MINIMIZE ? !(L(x) < R(x)) : (L(x) < R(x)));\
    \ }\n};\n"
  code: "// x=INF \u3067\u5C0F\u3055\u304F\u306A\u308B\uFF08\u50BE\u304D\u304C\u5C0F\
    \u3055\u3044\uFF09\u3082\u306E\u304C back\n// O(QlogQ) func call or O(Q) func\
    \ call + O(Q) find\n// https://contest.ucup.ac/contest/1893/problem/9737\n// push\
    \ front \u4F7F\u3063\u305F\u3053\u3068\u306A\u3057\ntemplate <typename F, bool\
    \ MINIMIZE>\nstruct CHT_monotone_F {\n  using T = typename F::value_type;\n  ll\
    \ L, R;\n\n  // func, L, R\n  vc<tuple<F, ll, ll>> dat;\n  CHT_monotone_F(ll L,\
    \ ll R) : L(L), R(R) {}\n\n  void push_back(F f) {\n    auto find = [&](F f, F\
    \ g, ll a, ll b) -> ll { return binary_search([&](ll x) -> bool { return select_right(f,\
    \ g, x); }, b, a, 0); };\n    push_back_with_find(f, find);\n  }\n\n  void push_front(F\
    \ f) {\n    auto find = [&](F f, F g, ll a, ll b) -> ll { return binary_search([&](ll\
    \ x) -> bool { return select_right(f, g, x); }, b, a, 0); };\n    push_front_with_find(f,\
    \ find);\n  }\n\n  // find(f,g,a,b): f(a)<=g(a), g(b)<f(b) \u306E\u3068\u304D\
    \ g(x)<f(x) \u3068\u306A\u308B\u6700\u5C0F\u306E x\n  template <typename FIND>\n\
    \  void push_back_with_find(F g, FIND find) {\n    while (1) {\n      if (dat.empty())\
    \ {\n        dat.eb(g, L, R);\n        break;\n      }\n      auto [f, a, b] =\
    \ dat.back();\n      if (select_right(f, g, a)) {\n        dat.pop_back();\n \
    \       if (len(dat)) get<2>(dat.back()) = b;\n        continue;\n      }\n  \
    \    if (!select_right(f, g, b - 1)) { break; }\n      ll x = find(f, g, a, b\
    \ - 1);\n      get<2>(dat.back()) = x;\n      dat.emplace_back(g, x, b);\n   \
    \   break;\n    }\n  }\n\n  // find(f,g,a,b): f(a)<=g(a), g(b)<f(b) \u306E\u3068\
    \u304D g(x)<f(x) \u3068\u306A\u308B\u6700\u5C0F\u306E x\n  template <typename\
    \ FIND>\n  void push_front_with_find(F f, FIND find) {\n    while (1) {\n    \
    \  if (dat.empty()) {\n        dat.eb(f, L, R);\n        break;\n      }\n   \
    \   auto [g, a, b] = dat.front();\n      if (!select_right(f, g, b - 1)) {\n \
    \       dat.pop_front();\n        if (len(dat)) get<1>(dat.front()) = L;\n   \
    \     continue;\n      }\n      if (select_right(f, g, a)) break;\n      ll x\
    \ = find(f, g, a, b - 1);\n      get<1>(dat.front()) = x;\n      dat.emplace_front(f,\
    \ a, x);\n      break;\n    }\n  }\n\n  T query(ll x) {\n    assert(!dat.empty());\n\
    \    int k = binary_search([&](int i) -> bool { return get<1>(dat[i]) <= x; },\
    \ 0, len(dat));\n    auto [f, a, b] = dat[k];\n    assert(a <= x && x < b);\n\
    \    return f(x);\n  }\n\n  int last = 0;\n  T query_monotone(ll x) {\n    assert(!dat.empty());\n\
    \    chmin(last, len(dat) - 1);\n    while (1) {\n      auto [f, l, r] = dat[last];\n\
    \      if (x < l) --last;\n      elif (r <= x)++ last;\n      else break;\n  \
    \  }\n    auto [f, l, r] = dat[last];\n    return f(x);\n  }\n\nprivate:\n  bool\
    \ select_right(F L, F R, ll x) { return (MINIMIZE ? !(L(x) < R(x)) : (L(x) < R(x)));\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/cht_monotone_F.hpp
  requiredBy: []
  timestamp: '2025-01-16 21:29:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/cht_monotone_F.hpp
layout: document
redirect_from:
- /library/convex/cht_monotone_F.hpp
- /library/convex/cht_monotone_F.hpp.html
title: convex/cht_monotone_F.hpp
---
