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
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/convolution.hpp\"\r\n\r\ntemplate <typename mint>\r\nmint\
    \ coef_of_rational_fps(vector<mint> A, vector<mint> B, ll N) {\r\n  if (len(A)\
    \ == 0) return 0;\r\n  assert(len(A) < len(B));\r\n  while (len(A) + 1 < len(B))\
    \ A.eb(0);\r\n  assert(B[0] == mint(1));\r\n  assert(len(B) == len(A) + 1);\r\n\
    \  while (N) {\r\n    vc<mint> B1 = B;\r\n    FOR(i, len(B1)) if (i & 1) B1[i]\
    \ = -B1[i];\r\n    A = convolution(A, B1);\r\n    B = convolution(B, B1);\r\n\
    \    FOR(i, len(B1)) B[i] = B[2 * i];\r\n    if (N & 1) {\r\n      FOR(i, len(B1)\
    \ - 1) A[i] = A[2 * i | 1];\r\n    } else {\r\n      FOR(i, len(B1) - 1) A[i]\
    \ = A[2 * i];\r\n    }\r\n    A.resize(len(B1) - 1);\r\n    B.resize(len(B1));\r\
    \n    N /= 2;\r\n  }\r\n  return A[0];\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/coef_of_rational_fps.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/coef_of_rational_fps.hpp
layout: document
redirect_from:
- /library/poly/coef_of_rational_fps.hpp
- /library/poly/coef_of_rational_fps.hpp.html
title: poly/coef_of_rational_fps.hpp
---
