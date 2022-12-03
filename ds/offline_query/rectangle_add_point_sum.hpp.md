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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/fenwick/fenwick.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/fenwick/fenwick.hpp\"\n\ntemplate <typename AbelGroup, bool\
    \ SMALL>\nstruct Rectangle_Add_Point_Sum {\n  using G = typename AbelGroup::value_type;\n\
    \  vc<tuple<ll, ll, ll, ll>> rect;\n  vc<G> WT;\n  vc<pi> point;\n\n  Rectangle_Add_Point_Sum()\
    \ {}\n\n  void add_query(ll xl, ll xr, ll yl, ll yr, G g) {\n    rect.eb(xl, xr,\
    \ yl, yr);\n    WT.eb(g);\n  }\n\n  void sum_query(ll x, ll y) { point.eb(x, y);\
    \ }\n\n  vc<G> calc() {\n    int N = len(rect), Q = len(point);\n    if (N ==\
    \ 0) return vc<G>(Q, AbelGroup::unit());\n    vi keyX, keyY;\n    keyX.reserve(2\
    \ * N + Q);\n    keyY.reserve(2 * N + Q);\n    for (auto&& [xl, xr, yl, yr]: rect)\
    \ {\n      keyX.eb(xl), keyX.eb(xr), keyY.eb(yl), keyY.eb(yr);\n    }\n    for\
    \ (auto&& [x, y]: point) { keyX.eb(x), keyY.eb(y); }\n    int NX = 0, NY = 0;\n\
    \    if (!SMALL) {\n      UNIQUE(keyX), UNIQUE(keyY);\n      NX = len(keyX), NY\
    \ = len(keyY);\n      for (auto&& [xl, xr, yl, yr]: rect) {\n        xl = LB(keyX,\
    \ xl), xr = LB(keyX, xr);\n        yl = LB(keyY, yl), yr = LB(keyY, yr);\n   \
    \   }\n      for (auto&& [x, y]: point) {\n        x = LB(keyX, x);\n        y\
    \ = LB(keyY, y);\n      }\n    } else {\n      ll mx = MIN(keyX), my = MIN(keyY);\n\
    \      NX = MAX(keyX) - mx + 1, NY = MAX(keyY) - my + 1;\n      for (auto&& [xl,\
    \ xr, yl, yr]: rect) {\n        xl = xl - mx, xr = xr - mx;\n        yl = yl -\
    \ my, yr = yr - my;\n      }\n      for (auto&& [x, y]: point) { x = x - mx, y\
    \ = y - my; }\n    }\n    vvc<tuple<int, int, G>> ADD(NY);\n    vvc<int> CALC(NY);\n\
    \    FOR(i, N) {\n      auto [xl, xr, yl, yr] = rect[i];\n      ADD[yl].eb(xl,\
    \ xr, WT[i]);\n      ADD[yr].eb(xl, xr, AbelGroup::inverse(WT[i]));\n    }\n \
    \   FOR(q, Q) {\n      auto [x, y] = point[q];\n      CALC[y].eb(q);\n    }\n\
    \    vc<G> res(Q);\n    FenwickTree<AbelGroup> bit(NX);\n    FOR(y, NY) {\n  \
    \    for (auto&& [xl, xr, g]: ADD[y]) {\n        bit.add(xl, g);\n        bit.add(xr,\
    \ AbelGroup::inverse(g));\n      }\n      for (auto&& q: CALC[y]) {\n        auto\
    \ [x, y] = point[q];\n        res[q] = bit.prod(x + 1);\n      }\n    }\n    return\
    \ res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/rectangle_add_point_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offline_query/rectangle_add_point_sum.hpp
layout: document
redirect_from:
- /library/ds/offline_query/rectangle_add_point_sum.hpp
- /library/ds/offline_query/rectangle_add_point_sum.hpp.html
title: ds/offline_query/rectangle_add_point_sum.hpp
---
