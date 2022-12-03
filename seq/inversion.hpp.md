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
  code: "#include \"ds/fenwick/fenwick.hpp\"\n\ntemplate <typename T>\nll inversion(vc<T>\
    \ A, bool SMALL = false) {\n  if (!SMALL) {\n    auto key = A;\n    UNIQUE(key);\n\
    \    for (auto&& x: A) x = LB(key, x);\n  }\n  ll ANS = 0;\n  ll K = MAX(A) +\
    \ 1;\n  FenwickTree<Monoid_Add<int>> bit(K);\n  for (auto&& x: A) {\n    ANS +=\
    \ bit.sum(x + 1, K);\n    bit.add(x, 1);\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/inversion.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/inversion.hpp
layout: document
redirect_from:
- /library/seq/inversion.hpp
- /library/seq/inversion.hpp.html
title: seq/inversion.hpp
---
