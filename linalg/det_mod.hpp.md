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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/fast_div.hpp:\
    \ line -1: no such header\n"
  code: "#include \"mod/fast_div.hpp\"\n\nint det_mod(vvc<int> A, int m) {\n  fast_div\
    \ mod(m);\n  const int n = len(A);\n  ll det = 1;\n  FOR(i, n) {\n    FOR(j, i,\
    \ n) {\n      if (A[j][i] == 0) continue;\n      if (i != j) { swap(A[i], A[j]),\
    \ det = m - det; }\n      break;\n    }\n    FOR(j, i + 1, n) {\n      while (A[i][i]\
    \ != 0) {\n        ll c = m - A[j][i] / A[i][i];\n        FOR_R(k, i, n) { A[j][k]\
    \ = (A[j][k] + A[i][k] * c) % mod; }\n        swap(A[i], A[j]), det = m - det;\n\
    \      }\n      swap(A[i], A[j]), det = m - det;\n    }\n  }\n  FOR(i, n) det\
    \ = det * A[i][i] % mod;\n  return det;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/det_mod.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/det_mod.hpp
layout: document
redirect_from:
- /library/linalg/det_mod.hpp
- /library/linalg/det_mod.hpp.html
title: linalg/det_mod.hpp
---
