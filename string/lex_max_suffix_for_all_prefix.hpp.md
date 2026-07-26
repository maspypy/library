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
    - https://www.codechef.com/START137A/problems/CABABAA
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
  code: "#include \"string/suffix_array.hpp\"\n\n// ANS[i] := length of lex-max suffix\
    \ of S[0,i), O(|S|) time\n// https://www.codechef.com/START137A/problems/CABABAA\n\
    vc<int> lex_max_suffix_for_all_prefix(string S) {\n  // suffix array \u9806\u3092\
    \u3082\u3068\u306B\u3057\u30661\u6587\u5B57\u305A\u3064\u6D88\u3057\u3066\u3044\
    \u304F.\n  // \u624B\u524D\u306E\u3082\u306E\u306B\u629C\u304B\u3055\u308C\u308B\
    \u306E\u306F, \u81EA\u5206\u3088\u308A\u9577\u3044\u3082\u306E\u306E prefix \u306B\
    \u306A\u308B\u3068\u304D.\n  // \u4E00\u5EA6\u629C\u304B\u3055\u308C\u305F\u3089\
    \u3082\u3046\u5FA9\u6D3B\u3059\u308B\u3053\u3068\u306F\u306A\u3044.\n  int N =\
    \ len(S);\n  Suffix_Array X(S);\n  auto &SA = X.SA, &LCP = X.LCP;\n  vvc<int>\
    \ rm(N);\n  vc<pair<int, int>> st;\n  FOR(i, N) {\n    int j = SA[i];\n    int\
    \ k = (i == 0 ? infty<int> : LCP[i - 1]);\n    while (len(st) && st.back().fi\
    \ > j) {\n      chmin(k, st.back().se);\n      POP(st);\n    }\n    if (len(st))\
    \ { rm[j + k].eb(j); }\n    st.eb(j, k);\n  }\n  int p = N - 1;\n  vc<int> ANS(N\
    \ + 1);\n  vc<bool> ng(N);\n  FOR_R(i, 1, N + 1) {\n    while (ng[SA[p]] || i\
    \ <= SA[p]) --p;\n    ANS[i] = i - SA[p];\n    for (auto& j: rm[i - 1]) ng[j]\
    \ = 1;\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/lex_max_suffix_for_all_prefix.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/lex_max_suffix_for_all_prefix.hpp
layout: document
redirect_from:
- /library/string/lex_max_suffix_for_all_prefix.hpp
- /library/string/lex_max_suffix_for_all_prefix.hpp.html
title: string/lex_max_suffix_for_all_prefix.hpp
---
