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
  code: "#include \"string/lyndon.hpp\"\n#include \"string/zalgorithm.hpp\"\n\n//\
    \ suffix X,Y \u306B\u3064\u3044\u3066, Y<X \u304B\u3064 Y notin prefix(X) \u3068\
    \u306A\u308B Y \u304C\u306A\u3044 X \u305F\u3061.\n// \u9577\u3055\u306E\u5217\
    \u3092\u8FD4\u3059. \u4E92\u3044\u306B border \u306B\u306A\u3063\u3066\u3044\u308B\
    .\n// donimate \u3068\u3044\u3046\u547C\u79F0\u306F\u898B\u304B\u3051\u306F\u3057\
    \u305F\u3051\u3069\u6A19\u6E96\u7684\u3067\u306A\u3044\u6C17\u304C\u3059\u308B\
    \nvc<int> non_dominated_suffix(string S) {\n  // Lyndon \u306E\u3068\u3053\u308D\
    \u304C\u5019\u88DC\u306A\u306E\u3060\u304C, \u3069\u3046\u3084\u3063\u3066\u8A08\
    \u7B97\u3057\u3088\u3046.\n  // \u305F\u3076\u3093 Duval algo \u306E\u4E2D\u3092\
    \u898B\u308C\u3070\u3044\u3044\u3093\u3060\u3051\u3069\n  // \u8003\u3048\u308B\
    \u306E\u304C\u9762\u5012\u306A\u306E\u3067 Z algorithm \u3067\u5224\u5B9A\u3057\
    \u3066\u307F\u308B\u304B.\n  int N = len(S);\n  Incremental_Lyndon_Factorization<char>\
    \ LDN;\n  FOR(i, N) LDN.add(S[i]);\n  string RS = {S.rbegin(), S.rend()};\n  vc<int>\
    \ Z = zalgorithm(RS);\n\n  vc<int> ANS;\n  vc<int> cut = LDN.factorize();\n  while\
    \ (len(cut) >= 2) {\n    int r = POP(cut);\n    int l = cut.back();\n    int n\
    \ = r - l;\n    int m = N - r;\n    if (Z[n] < m) break;\n    ANS.eb(n + m);\n\
    \  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/non_dominated_suffix.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/non_dominated_suffix.hpp
layout: document
redirect_from:
- /library/string/non_dominated_suffix.hpp
- /library/string/non_dominated_suffix.hpp.html
title: string/non_dominated_suffix.hpp
---
