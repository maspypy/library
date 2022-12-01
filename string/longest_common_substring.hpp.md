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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/disjointsparse.hpp:\
    \ line -1: no such header\n"
  code: "#include \"string/suffixarray.hpp\"\n\ntemplate <typename STRING>\ntuple<int,\
    \ int, int, int> longest_common_substring(STRING& S, STRING& T) {\n  int dummy\
    \ = max<int>(*max_element(all(S)), *max_element(all(T))) + 1;\n  STRING ST;\n\
    \  for (auto&& x: S) ST.push_back(x);\n  ST.push_back(dummy);\n  for (auto&& x:\
    \ T) ST.push_back(x);\n  SuffixArray X(ST);\n  auto& SA = X.SA;\n  auto& LCP =\
    \ X.LCP;\n\n  tuple<int, int, int, int> res = {0, 0, 0, 0};\n  int n = 0;\n  FOR(i,\
    \ len(ST) - 1) {\n    if ((SA[i] < len(S)) != (SA[i + 1] < len(S))) {\n      if\
    \ (chmax(n, LCP[i])) {\n        int a = SA[i];\n        int b = SA[i + 1] - len(S)\
    \ - 1;\n        res = {a, a + n, b, b + n};\n      }\n    }\n  }\n  return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: string/longest_common_substring.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/longest_common_substring.hpp
layout: document
redirect_from:
- /library/string/longest_common_substring.hpp
- /library/string/longest_common_substring.hpp.html
title: string/longest_common_substring.hpp
---
