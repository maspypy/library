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
  code: "#include \"ds/fenwick/fenwick.hpp\"\n\n// i \u756A\u76EE\uFF1AA_i \u304C\u5148\
    \u982D\u306B\u306A\u308B\u3088\u3046\u306B rotate \u3057\u305F\u3068\u304D\u306E\
    \u8EE2\u5012\u6570\ntemplate <typename T>\nvi inversion_rotate(vc<T>& A, bool\
    \ SMALL = false) {\n  const int N = len(A);\n  if (!SMALL) {\n    auto key = A;\n\
    \    UNIQUE(key);\n    for (auto&& x: A) x = LB(key, x);\n  }\n  ll K = MAX(A)\
    \ + 1;\n  ll ANS = 0;\n  FenwickTree<Monoid_Add<int>> bit(K);\n  for (auto&& x:\
    \ A) {\n    ANS += bit.sum(x + 1, K);\n    bit.add(x, 1);\n  }\n  vi res(N);\n\
    \  FOR(i, N) {\n    res[i] = ANS;\n    ll x = A[i];\n    ANS = ANS + bit.prod(x\
    \ + 1, K) - bit.sum(x);\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/inversion_rotate.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/inversion_rotate.hpp
layout: document
redirect_from:
- /library/seq/inversion_rotate.hpp
- /library/seq/inversion_rotate.hpp.html
title: seq/inversion_rotate.hpp
---
