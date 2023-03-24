---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convex/monge.hpp
    title: convex/monge.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/fibonacci_search.test.cpp
    title: test/mytest/fibonacci_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/705.test.cpp
    title: test/yukicoder/705.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/fibonacci_search.hpp\"\n// [L, R) \u3067\u306E\u6975\
    \u5C0F\u5024\u3092\u3072\u3068\u3064\u6C42\u3081\u308B\u3001\u5358\u5CF0\u306F\
    \u4E0D\u8981\ntemplate <typename T, bool MINIMIZE, typename F>\npair<ll, T> fibonacci_search(F\
    \ f, ll L, ll R) {\n  assert(L < R);\n  --R;\n  ll a = L, b = L + 1, c = L + 2,\
    \ d = L + 3;\n  int n = 0;\n  while (d < R) { b = c, c = d, d = b + c - a, ++n;\
    \ }\n  auto get = [&](ll x) -> T {\n    if (R < x) return infty<T>;\n    return\
    \ (MINIMIZE ? f(x) : -f(x));\n  };\n  T ya = get(a), yb = get(b), yc = get(c),\
    \ yd = get(d);\n  // \u3053\u306E\u4E2D\u3067\u6975\u5C0F\u306A\u3089\u3070\u5168\
    \u4F53\u3067\u3082\u6975\u5C0F\u3001\u3092\u7DAD\u6301\u3059\u308B\n  FOR(n) {\n\
    \    if (yb <= yc) {\n      d = c, c = b, b = a + d - c;\n      yd = yc, yc =\
    \ yb, yb = get(b);\n    } else {\n      a = b, b = c, c = a + d - b;\n      ya\
    \ = yb, yb = yc, yc = get(c);\n    }\n  }\n  ll x = a;\n  T y = ya;\n  if (chmin(y,\
    \ yb)) x = b;\n  if (chmin(y, yc)) x = c;\n  if (chmin(y, yd)) x = d;\n  if (MINIMIZE)\
    \ return {x, y};\n  return {x, -y};\n}\n"
  code: "// [L, R) \u3067\u306E\u6975\u5C0F\u5024\u3092\u3072\u3068\u3064\u6C42\u3081\
    \u308B\u3001\u5358\u5CF0\u306F\u4E0D\u8981\ntemplate <typename T, bool MINIMIZE,\
    \ typename F>\npair<ll, T> fibonacci_search(F f, ll L, ll R) {\n  assert(L < R);\n\
    \  --R;\n  ll a = L, b = L + 1, c = L + 2, d = L + 3;\n  int n = 0;\n  while (d\
    \ < R) { b = c, c = d, d = b + c - a, ++n; }\n  auto get = [&](ll x) -> T {\n\
    \    if (R < x) return infty<T>;\n    return (MINIMIZE ? f(x) : -f(x));\n  };\n\
    \  T ya = get(a), yb = get(b), yc = get(c), yd = get(d);\n  // \u3053\u306E\u4E2D\
    \u3067\u6975\u5C0F\u306A\u3089\u3070\u5168\u4F53\u3067\u3082\u6975\u5C0F\u3001\
    \u3092\u7DAD\u6301\u3059\u308B\n  FOR(n) {\n    if (yb <= yc) {\n      d = c,\
    \ c = b, b = a + d - c;\n      yd = yc, yc = yb, yb = get(b);\n    } else {\n\
    \      a = b, b = c, c = a + d - b;\n      ya = yb, yb = yc, yc = get(c);\n  \
    \  }\n  }\n  ll x = a;\n  T y = ya;\n  if (chmin(y, yb)) x = b;\n  if (chmin(y,\
    \ yc)) x = c;\n  if (chmin(y, yd)) x = d;\n  if (MINIMIZE) return {x, y};\n  return\
    \ {x, -y};\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/fibonacci_search.hpp
  requiredBy:
  - convex/monge.hpp
  timestamp: '2023-03-24 19:14:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/fibonacci_search.test.cpp
  - test/yukicoder/705.test.cpp
documentation_of: other/fibonacci_search.hpp
layout: document
redirect_from:
- /library/other/fibonacci_search.hpp
- /library/other/fibonacci_search.hpp.html
title: other/fibonacci_search.hpp
---
