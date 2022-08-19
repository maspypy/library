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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geo/convexhull.hpp:\
    \ line -1: no such header\n"
  code: "#include \"geo/convexhull.hpp\"\n#include \"geo/base.hpp\"\n\n// \u6700\u9060\
    \u70B9\u5BFE\u3068\u306A\u308B 2 \u70B9\u306E index \u3092\u304B\u3048\u3059\u3002\
    \u7A7A\u96C6\u5408\u306F\u30A8\u30E9\u30FC\u3002\ntemplate <typename T>\npair<int,\
    \ int> points_diameter(vc<Point<T>>& XY) {\n  ll N = len(XY);\n  assert(N >= 1);\n\
    \  if (N == 1) return {0, 0};\n  auto I = ConvexHull(XY, \"full\");\n  pi res\
    \ = {0, 0};\n  ll best = 0;\n  ll s = 0;\n  FOR(k, len(I)) {\n    ll i = (k ==\
    \ 0 ? I.back() : I[k - 1]), j = I[k];\n    Point<T> A = XY[i], B = XY[j];\n  \
    \  ll dx = B.x - A.x, dy = B.y - A.y;\n    Point<T> vec = {-dy, dx};\n    while\
    \ (1) {\n      Point<T> p = XY[I[s]], q = XY[I[(s + 1) % len(I)]];\n      if (vec.dot(p\
    \ - q) < 0)\n        s = (s + 1) % len(I);\n      else\n        break;\n    }\n\
    \    Point<T> C = XY[I[s]];\n    if (chmax(best, (A - C).dot(A - C))) res = {i,\
    \ I[s]};\n    if (chmax(best, (B - C).dot(B - C))) res = {j, I[s]};\n  }\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geo_old/points_diameter.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo_old/points_diameter.hpp
layout: document
redirect_from:
- /library/geo_old/points_diameter.hpp
- /library/geo_old/points_diameter.hpp.html
title: geo_old/points_diameter.hpp
---
