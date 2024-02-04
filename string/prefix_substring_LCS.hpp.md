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
    - https://codeforces.com/blog/entry/111625
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/wavelet_matrix.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/wavelet_matrix.hpp\"\n\n// https://codeforces.com/blog/entry/111625\n\
    struct Prefix_Substring_LCS {\n  int N, M;\n  vc<Wavelet_Matrix<int, 0>> WM;\n\
    \n  template <typename STRING>\n  Prefix_Substring_LCS(STRING S, STRING T) {\n\
    \    build(S, T);\n  }\n\n  template <typename STRING>\n  void build(STRING S,\
    \ STRING T) {\n    N = len(S), M = len(T);\n    vv(int, dph, N + 1, M + 1);\n\
    \    vv(int, dpv, N + 1, M + 1);\n    FOR(j, M + 1) dph[0][j] = j;\n    FOR(i,\
    \ 1, N + 1) FOR(j, 1, M + 1) {\n      bool same = S[i - 1] == T[j - 1];\n    \
    \  int a = dph[i - 1][j], b = dpv[i][j - 1];\n      dph[i][j] = (same ? b : max(a,\
    \ b));\n      dpv[i][j] = (same ? a : min(a, b));\n    }\n    FOR(i, N + 1) {\
    \ WM.eb(Wavelet_Matrix<int, 0>(dph[i])); }\n  }\n\n  // LCS(S[0:n], T[L:R])\n\
    \  int query(int n, int L, int R) { return WM[n].count(L + 1, R + 1, 0, L + 1);\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/prefix_substring_LCS.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/prefix_substring_LCS.hpp
layout: document
redirect_from:
- /library/string/prefix_substring_LCS.hpp
- /library/string/prefix_substring_LCS.hpp.html
title: string/prefix_substring_LCS.hpp
---
