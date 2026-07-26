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
  code: "#include \"string/suffix_array.hpp\"\n\n// dp[i][j]\uFF1AS[i:i+j) \u306E\
    \ rank\n// \u7D50\u679C\u306E\u30C6\u30FC\u30D6\u30EB\u304C\u4F7F\u3044\u306B\u304F\
    \u3044\u306A\u3089 suffix tree \u3092 dfs \u3057\u3066\u3082\u3089\u3046\u65B9\
    \u304C\u3088\u3044\u304B\u3082\ntemplate <typename STRING>\nvvc<int> sort_substrings(STRING&\
    \ S, int max_len = -1) {\n  int n = len(S);\n  if (max_len == -1) max_len = n;\n\
    \  Suffix_Array sa(S);\n  auto& SA = sa.SA;\n  auto& LCP = sa.LCP;\n  int nxt\
    \ = 0;\n  vv(int, dp, n, max_len + 1, -1);\n  FOR(i, len(SA)) {\n    auto L =\
    \ SA[i];\n    FOR(k, 1, min(n - L, max_len) + 1) {\n      int R = L + k;\n   \
    \   if (i > 0 && LCP[i - 1] >= k)\n        dp[L][R - L] = dp[SA[i - 1]][k];\n\
    \      else\n        dp[L][R - L] = nxt++;\n    }\n  }\n  return dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/sort_substrings.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/sort_substrings.hpp
layout: document
redirect_from:
- /library/string/sort_substrings.hpp
- /library/string/sort_substrings.hpp.html
title: string/sort_substrings.hpp
---
