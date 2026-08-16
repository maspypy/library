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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/zalgorithm.hpp:\
    \ line -1: no such header\n"
  code: "#include \"string/zalgorithm.hpp\"\n\n// \u9023\u7D9A\u90E8\u5206\u5217\u306B\
    \u542B\u3080\u304B\u3069\u3046\u304B\u3002z-algo \u3067\u7DDA\u5F62\u6642\u9593\
    \ntemplate <typename STRING>\nbool is_substring(STRING S, STRING T) {\n  int n\
    \ = int(S.size()), m = int(T.size());\n  STRING ST;\n  for (auto&& x: S) ST.push_back(x);\n\
    \  for (auto&& x: T) ST.push_back(x);\n  auto Z = zalgorithm(ST);\n  for (int\
    \ i = n; i < n + m; ++i) {\n    if (Z[i] >= n) return true;\n  }\n  return false;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: string/is_substring.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/is_substring.hpp
layout: document
redirect_from:
- /library/string/is_substring.hpp
- /library/string/is_substring.hpp.html
title: string/is_substring.hpp
---
