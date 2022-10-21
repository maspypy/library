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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/monoid_min.hpp:\
    \ line -1: no such header\n"
  code: "#include \"string/suffixarray.hpp\"\n\n/*\ndp[l][r] := S[l:r] \u304C\u6607\
    \u9806\u3067\u4F55\u756A\u76EE\u304B\uFF1F\u3068\u3044\u3046\u30C6\u30FC\u30D6\
    \u30EB\u3092\u8FD4\u3059\u3002\nO(N^2)\n*/\ntemplate <typename STRING>\nvc<vc<int>>\
    \ sort_all_substring(STRING S) {\n  int n = len(S);\n  SuffixArray sa(S);\n  auto&\
    \ SA = sa.SA;\n  auto& LCP = sa.LCP;\n  int nxt = 0;\n  vv(int, DP, n, n + 1,\
    \ -1);\n  FOR(i, len(SA)) {\n    auto L = SA[i];\n    FOR3(k, 1, n - L + 1) {\n\
    \      int R = L + k;\n      if (i > 0 && LCP[i - 1] >= k)\n        DP[L][R] =\
    \ DP[SA[i - 1]][SA[i - 1] + k];\n      else\n        DP[L][R] = nxt++;\n    }\n\
    \  }\n  return DP;\n}\n\n// \u9577\u3055\u306E\u4E0A\u9650\u3042\u308A\n// (\u958B\
    \u59CB\u4F4D\u7F6E\u3001\u9577\u3055) \u306B\u5BFE\u3057\u3066\u30BD\u30FC\u30C8\
    \u9806\u3092\u57CB\u3081\u308B\ntemplate <typename STRING>\nvc<vc<int>> sort_all_substring_limit(STRING\
    \ S, ll LIM) {\n  int n = len(S);\n  SuffixArray sa(S);\n  auto& SA = sa.SA;\n\
    \  auto& LCP = sa.LCP;\n  int nxt = 0;\n  vv(int, DP, n, LIM + 1, -1);\n  FOR(i,\
    \ len(SA)) {\n    auto L = SA[i];\n    FOR3(k, 1, min(n - L, LIM) + 1) {\n   \
    \   int R = L + k;\n      if (i > 0 && LCP[i - 1] >= k)\n        DP[L][R - L]\
    \ = DP[SA[i - 1]][k];\n      else\n        DP[L][R - L] = nxt++;\n    }\n  }\n\
    \  return DP;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/sort_all_substring.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/sort_all_substring.hpp
layout: document
redirect_from:
- /library/string/sort_all_substring.hpp
- /library/string/sort_all_substring.hpp.html
title: string/sort_all_substring.hpp
---
