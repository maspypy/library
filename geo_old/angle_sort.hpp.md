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
  code: "#include \"geo/base.hpp\"\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\
    \u3059\u308B argsort\r\ntemplate<typename Point>\r\nvector<int> angle_argsort(vector<Point>&\
    \ P) {\r\n  auto is_lower = [](Point P) { return (P.y < 0) || (P.y == 0 && P.x\
    \ > 0); };\r\n  vector<int> lower, origin, upper;\r\n  Point O = {0, 0};\r\n \
    \ FOR(i, len(P)) {\r\n    if (P[i] == O) origin.eb(i);\r\n    elif (is_lower(P[i]))\
    \ lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n  sort(all(lower), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  sort(all(upper), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  auto& I = lower;\r\n  I.insert(I.end(),\
    \ all(origin));\r\n  I.insert(I.end(), all(upper));\r\n  return I;\r\n}\r\n\r\n\
    // inplace \u306B\u504F\u89D2\u30BD\u30FC\u30C8\u3059\u308B\r\n// index \u304C\
    \u6B32\u3057\u3044\u5834\u5408\u306F angle_argsort\r\ntemplate<typename Point>\r\
    \nvoid angle_sort(vector<Point>& P) {\r\n  auto I = angle_argsort(P);\r\n  vc<Point>\
    \ Q(len(P));\r\n  FOR(i, len(P)) Q[i] = P[I[i]];\r\n  P = Q;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geo_old/angle_sort.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo_old/angle_sort.hpp
layout: document
redirect_from:
- /library/geo_old/angle_sort.hpp
- /library/geo_old/angle_sort.hpp.html
title: geo_old/angle_sort.hpp
---
