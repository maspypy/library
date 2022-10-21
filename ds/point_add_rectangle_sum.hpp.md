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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group_add.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include \"ds/fenwick.hpp\"\r\n\r\n\r\ntemplate <typename\
    \ AbelGroup, bool SMALL = false>\r\nstruct Point_Add_Rectangle_Sum {\r\n  using\
    \ G = typename AbelGroup::value_type;\r\n  int Q;\r\n  vector<ll> X, Y;\r\n  vector<G>\
    \ WT;\r\n  vector<tuple<ll, ll, ll, ll>> rect;\r\n\r\n  Point_Add_Rectangle_Sum()\
    \ {}\r\n\r\n  void add_query(ll x, ll y, G w) {\r\n    X.emplace_back(x), Y.emplace_back(y),\
    \ WT.emplace_back(w);\r\n  }\r\n\r\n  void sum_query(ll xl, ll yl, ll xr, ll yr)\
    \ {\r\n    rect.emplace_back(xl, yl, xr, yr);\r\n  }\r\n\r\n  vector<G> calc()\
    \ {\r\n    int N = X.size(), Q = rect.size();\r\n    if (N == 0) return vector<G>(Q,\
    \ AbelGroup::unit());\r\n    int NX = 0, NY = 0;\r\n    if (!SMALL) {\r\n    \
    \  vector<ll> keyX = X, keyY = Y;\r\n      sort(all(keyX));\r\n      keyX.erase(unique(all(keyX)),\
    \ keyX.end());\r\n      sort(all(keyY));\r\n      keyY.erase(unique(all(keyY)),\
    \ keyY.end());\r\n      NX = keyX.size(), NY = keyY.size();\r\n      for (auto\
    \ &&x: X) x = lower_bound(all(keyX), x) - keyX.begin();\r\n      for (auto &&y:\
    \ Y) y = lower_bound(all(keyY), y) - keyY.begin();\r\n      for (auto &&[xl, yl,\
    \ xr, yr]: rect) {\r\n        xl = lower_bound(all(keyX), xl) - keyX.begin();\r\
    \n        xr = lower_bound(all(keyX), xr) - keyX.begin();\r\n        yl = lower_bound(all(keyY),\
    \ yl) - keyY.begin();\r\n        yr = lower_bound(all(keyY), yr) - keyY.begin();\r\
    \n      }\r\n    }\r\n    if (SMALL) {\r\n      ll mx = *(min_element(X.begin(),\
    \ X.end()));\r\n      ll my = *(min_element(Y.begin(), Y.end()));\r\n      for\
    \ (auto &&x: X) x -= mx;\r\n      for (auto &&y: Y) y -= my;\r\n      NX = *(max_element(X.begin(),\
    \ X.end())) + 1;\r\n      NY = *(max_element(Y.begin(), Y.end())) + 1;\r\n   \
    \   for (auto &&[xl, yl, xr, yr]: rect) {\r\n        xl -= mx, xr -= mx;\r\n \
    \       yl -= my, yr -= my;\r\n        xl = max(0, min<int>(xl, NX));\r\n    \
    \    xr = max(0, min<int>(xr, NX));\r\n        yl = max(0, min<int>(yl, NY));\r\
    \n        yr = max(0, min<int>(yr, NY));\r\n      }\r\n    }\r\n    vector<vector<pair<int,\
    \ G>>> ADD(NY + 1);\r\n    vector<vector<tuple<int, int, int>>> CALC_1(NY + 1);\r\
    \n    vector<vector<tuple<int, int, int>>> CALC_2(NY + 1);\r\n    for (int n =\
    \ 0; n < N; ++n) { ADD[Y[n]].emplace_back(X[n], WT[n]); }\r\n    for (int q =\
    \ 0; q < Q; ++q) {\r\n      auto &[xl, yl, xr, yr] = rect[q];\r\n      CALC_1[yr].emplace_back(xl,\
    \ xr, q);\r\n      CALC_2[yl].emplace_back(xl, xr, q);\r\n    };\r\n\r\n    vector<G>\
    \ res(Q, AbelGroup::unit());\r\n    FenwickTree<AbelGroup> bit(NX);\r\n\r\n  \
    \  for (int y = 0; y <= NY; ++y) {\r\n      for (auto &&[xl, xr, q]: CALC_1[y])\
    \ {\r\n        auto x = bit.prod(xl, xr);\r\n        res[q] = AbelGroup::op(res[q],\
    \ x);\r\n      }\r\n      for (auto &&[xl, xr, q]: CALC_2[y]) {\r\n        auto\
    \ x = AbelGroup::inverse(bit.prod(xl, xr));\r\n        res[q] = AbelGroup::op(res[q],\
    \ x);\r\n      }\r\n      for (auto &&[x, g]: ADD[y]) { bit.add(x, g); }\r\n \
    \   }\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/point_add_rectangle_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/point_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/ds/point_add_rectangle_sum.hpp
- /library/ds/point_add_rectangle_sum.hpp.html
title: ds/point_add_rectangle_sum.hpp
---
