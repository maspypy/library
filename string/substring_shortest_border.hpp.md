---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1043/problem/G
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
  code: "#include \"string/suffix_array.hpp\"\n\n// \u6700\u77ED border \u306E\u9577\
    \u3055. \u306A\u304B\u3063\u305F\u3089 R-L. O(sqrt(N)).\n// https://codeforces.com/contest/1043/problem/G\n\
    // N=Q=200_000, 1.2sec\nint substring_shortest_border(Suffix_Array<true>& X, int\
    \ L, int R) {\n  /*\n  border \u306E border \u306F border \u306A\u306E\u3067\uFF0C\
    shortest border B \u306F borderless.\n  S \u306B\u304A\u3051\u308B B \u306E occurrence\
    \ \u306F\u91CD\u8907\u3057\u306A\u3044.\n  \u3088\u3063\u3066 B \u3092 prefix\
    \ \u306B\u6301\u3064\u6587\u5B57\u5217\u306F\u9AD8\u3005 O(N/|B|) \u3067\u3042\
    \u308B.\n  \u3053\u308C\u306F suffix array \u306B\u304A\u3051\u308B\u8FD1\u508D\
    \u3092\u898B\u308C\u3070\u898B\u3064\u304B\u308B.\n  */\n  int N = len(X.SA);\n\
    \  int K = sqrt(len(X.SA)) / 2;\n  FOR(n, 1, K + 1) {\n    if (X.lcp(L, R - n)\
    \ >= n) return n;\n  }\n  int ANS = R - L;\n  int idx = X.ISA[L];\n  int lcp =\
    \ infty<int>;\n  FOR(i, idx + 1, N) {\n    chmin(lcp, X.LCP[i - 1]);\n    if (lcp\
    \ <= K) break; // \u3053\u308C\u3067\u52DD\u624B\u306B O(sqrt(N)) \u306B\u306A\
    \u308B.\n    int M = X.SA[i];\n    if (L < M && M < R && R - M <= lcp) chmin(ANS,\
    \ R - M);\n  }\n  lcp = infty<int>;\n  FOR_R(i, idx) {\n    chmin(lcp, X.LCP[i]);\n\
    \    if (lcp <= K) break; // \u3053\u308C\u3067\u52DD\u624B\u306B O(sqrt(N)) \u306B\
    \u306A\u308B.\n    int M = X.SA[i];\n    if (L < M && M < R && R - M <= lcp) chmin(ANS,\
    \ R - M);\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/substring_shortest_border.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/substring_shortest_border.hpp
layout: document
redirect_from:
- /library/string/substring_shortest_border.hpp
- /library/string/substring_shortest_border.hpp.html
title: string/substring_shortest_border.hpp
---
