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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bit.hpp: line\
    \ -1: no such header\n"
  code: "#include \"string/suffix_array.hpp\"\n\ntemplate <typename STRING>\ntuple<int,\
    \ int, int, int> longest_common_substring(STRING& S, STRING& T) {\n  int dummy\
    \ = max<int>(*max_element(all(S)), *max_element(all(T))) + 1;\n  STRING ST;\n\
    \  for (auto&& x: S) ST.push_back(x);\n  ST.push_back(dummy);\n  for (auto&& x:\
    \ T) ST.push_back(x);\n  Suffix_Array X(ST);\n  auto& SA = X.SA;\n  auto& LCP\
    \ = X.LCP;\n\n  tuple<int, int, int, int> res = {0, 0, 0, 0};\n  int n = 0;\n\
    \  FOR(i, len(ST) - 1) {\n    int i1 = SA[i], i2 = SA[i + 1];\n    if (i1 > i2)\
    \ swap(i1, i2);\n    if (i1 < len(S) && len(S) < i2 && chmax(n, LCP[i])) {\n \
    \     int a = i1, b = i2 - len(S) - 1;\n      res = {a, a + n, b, b + n};\n  \
    \  }\n  }\n  return res;\n}"
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
