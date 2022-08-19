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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geo/base.hpp:\
    \ line -1: no such header\n"
  code: "#include \"geo/base.hpp\"\r\n\r\ntemplate<typename T>\r\nvector<int> ConvexHull(vector<pair<T,\
    \ T>>& XY, string mode = \"full\",\r\n                      bool inclusive = false,\
    \ bool sorted = false) {\r\n  assert(mode == \"full\" || mode == \"lower\" ||\
    \ mode == \"upper\");\r\n  ll N = XY.size();\r\n  if (N == 1) return {0};\r\n\
    \  if (N == 2) return {0, 1};\r\n  vc<int> I = argsort(XY);\r\n\r\n  auto check\
    \ = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].fi, yi = XY[i].se;\r\
    \n    auto xj = XY[j].fi, yj = XY[j].se;\r\n    auto xk = XY[k].fi, yk = XY[k].se;\r\
    \n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk - xj, dy2 = yk -\
    \ yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive ? det >=\
    \ 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vector<int> P;\r\n\
    \    for (auto&& k: I) {\r\n      while (P.size() > 1) {\r\n        auto i = P[P.size()\
    \ - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i, j, k)) break;\r\
    \n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\n    return P;\r\
    \n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode == \"lower\") {\r\
    \n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\n  }\r\n  if (mode\
    \ == \"full\" || mode == \"upper\") {\r\n    if (!P.empty()) P.pop_back();\r\n\
    \    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P) >= 2 && P[0]\
    \ == P.back()) P.pop_back();\r\n  return P;\r\n}\r\n\r\ntemplate<typename X>\r\
    \nvc<int> ConvexHull(vector<Point<X>>& XY, string mode = \"full\",\r\n       \
    \               bool inclusive = false, bool sorted = false) {\r\n  assert(mode\
    \ == \"full\" || mode == \"lower\" || mode == \"upper\");\r\n  ll N = XY.size();\r\
    \n  if (N == 1) return {0};\r\n  if (N == 2) return {0, 1};\r\n  vc<int> I = argsort(XY);\r\
    \n\r\n  auto check = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].x,\
    \ yi = XY[i].y;\r\n    auto xj = XY[j].x, yj = XY[j].y;\r\n    auto xk = XY[k].x,\
    \ yk = XY[k].y;\r\n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk\
    \ - xj, dy2 = yk - yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive\
    \ ? det >= 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vc<int> P;\r\
    \n    for (auto&& k: I) {\r\n      while (P.size() > 1) {\r\n        auto i =\
    \ P[P.size() - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i,\
    \ j, k)) break;\r\n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\
    \n    return P;\r\n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode\
    \ == \"lower\") {\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"full\" || mode == \"upper\") {\r\n    if (!P.empty())\
    \ P.pop_back();\r\n    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(),\
    \ all(Q));\r\n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P)\
    \ >= 2 && P[0] == P.back()) P.pop_back();\r\n  return P;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: geo_old/convexhull.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo_old/convexhull.hpp
layout: document
redirect_from:
- /library/geo_old/convexhull.hpp
- /library/geo_old/convexhull.hpp.html
title: geo_old/convexhull.hpp
---
