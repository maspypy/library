---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/convex_hull.hpp\"\n\ntemplate <typename T>\nvector<int>\
    \ ConvexHull(vector<pair<T, T>>& XY, string mode = \"full\",\n               \
    \        bool inclusive = false, bool sorted = false) {\n  assert(mode == \"full\"\
    \ || mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N ==\
    \ 1) return {0};\n  if (N == 2) return {0, 1};\n  vc<int> I = argsort(XY);\n\n\
    \  auto check = [&](ll i, ll j, ll k) -> bool {\n    auto xi = XY[i].fi, yi =\
    \ XY[i].se;\n    auto xj = XY[j].fi, yj = XY[j].se;\n    auto xk = XY[k].fi, yk\
    \ = XY[k].se;\n    auto dx1 = xj - xi, dy1 = yj - yi;\n    auto dx2 = xk - xj,\
    \ dy2 = yk - yj;\n    ll det = dx1 * dy2 - dy1 * dx2;\n    return (inclusive ?\
    \ det >= 0 : det > 0);\n  };\n\n  auto calc = [&]() {\n    vector<int> P;\n  \
    \  for (auto&& k: I) {\n      while (P.size() > 1) {\n        auto i = P[P.size()\
    \ - 2];\n        auto j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n\
    \        P.pop_back();\n      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n\
    \  vc<int> P;\n  if (mode == \"full\" || mode == \"lower\") {\n    vc<int> Q =\
    \ calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"full\" || mode\
    \ == \"upper\") {\n    if (!P.empty()) P.pop_back();\n    reverse(all(I));\n \
    \   vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"\
    upper\") reverse(all(P));\n  if (len(P) >= 2 && P[0] == P.back()) P.pop_back();\n\
    \  return P;\n}\n"
  code: "\ntemplate <typename T>\nvector<int> ConvexHull(vector<pair<T, T>>& XY, string\
    \ mode = \"full\",\n                       bool inclusive = false, bool sorted\
    \ = false) {\n  assert(mode == \"full\" || mode == \"lower\" || mode == \"upper\"\
    );\n  ll N = XY.size();\n  if (N == 1) return {0};\n  if (N == 2) return {0, 1};\n\
    \  vc<int> I = argsort(XY);\n\n  auto check = [&](ll i, ll j, ll k) -> bool {\n\
    \    auto xi = XY[i].fi, yi = XY[i].se;\n    auto xj = XY[j].fi, yj = XY[j].se;\n\
    \    auto xk = XY[k].fi, yk = XY[k].se;\n    auto dx1 = xj - xi, dy1 = yj - yi;\n\
    \    auto dx2 = xk - xj, dy2 = yk - yj;\n    ll det = dx1 * dy2 - dy1 * dx2;\n\
    \    return (inclusive ? det >= 0 : det > 0);\n  };\n\n  auto calc = [&]() {\n\
    \    vector<int> P;\n    for (auto&& k: I) {\n      while (P.size() > 1) {\n \
    \       auto i = P[P.size() - 2];\n        auto j = P[P.size() - 1];\n       \
    \ if (check(i, j, k)) break;\n        P.pop_back();\n      }\n      P.eb(k);\n\
    \    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode == \"full\" || mode ==\
    \ \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n\
    \  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty()) P.pop_back();\n\
    \    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n\
    \  }\n  if (mode == \"upper\") reverse(all(P));\n  if (len(P) >= 2 && P[0] ==\
    \ P.back()) P.pop_back();\n  return P;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geo/convex_hull.hpp
  requiredBy: []
  timestamp: '2023-05-12 16:35:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/convex_hull.hpp
layout: document
redirect_from:
- /library/geo/convex_hull.hpp
- /library/geo/convex_hull.hpp.html
title: geo/convex_hull.hpp
---
