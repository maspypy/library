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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"seq/famous/stirling_number_2.hpp\"\r\n\r\n// n \u5143\u96C6\u5408\
    \u304B\u3089\u306E\u5168\u5C04\u306E\u6570\u3048\u4E0A\u3052\r\n// O(klogk)\r\n\
    template <typename mint>\r\nvc<mint> surjection_n(int n, int k_max) {\r\n  auto\
    \ f = stirling_number_2_n<mint>(n, k_max);\r\n  mint fc = 1;\r\n  FOR(i, k_max\
    \ + 1) { f[i] *= fc, fc *= mint(1 + i); }\r\n  return f;\r\n}\r\n\r\n// k \u5143\
    \u96C6\u5408\u3078\u306E\u306E\u5168\u5C04\u306E\u6570\u3048\u4E0A\u3052\r\n//\
    \ O(nlogn)\r\ntemplate <typename mint>\r\nvc<mint> surjection_k(int k, int n_max)\
    \ {\r\n  auto f = stirling_number_2_k<mint>(k, n_max);\r\n  mint fc = 1;\r\n \
    \ FOR(i, 1, k + 1) fc *= i;\r\n  FOR(i, n_max + 1) f[i] *= fc;\r\n  return f;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvvc<mint> surjection_2d(int nmax, int kmax)\
    \ {\r\n  auto A = stirling_number_2_2d<mint>(nmax, kmax);\r\n  mint fc = 1;\r\n\
    \  FOR(k, kmax + 1) {\r\n    FOR(n, nmax + 1) { A[n][k] *= fc; }\r\n    fc *=\
    \ 1 + k;\r\n  }\r\n  return A;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/surjection.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/surjection.hpp
layout: document
redirect_from:
- /library/seq/famous/surjection.hpp
- /library/seq/famous/surjection.hpp.html
title: seq/famous/surjection.hpp
---
