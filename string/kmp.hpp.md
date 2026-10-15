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
    - https://codeforces.com/contest/2209/problem/E
    - https://github.com/maspypy/library/blob/main/string/kmp.hpp
  bundledCode: "#line 1 \"string/kmp.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/kmp.hpp\n\
    \n// KMP[n]: longest border length of S[0,n) or 0.\n// https://codeforces.com/contest/2209/problem/E\n\
    template <typename STRING>\nvector<int> kmp(const STRING& S) {\n  int N = len(S);\n\
    \  vc<int> ANS(N + 1);\n  FOR(n, 2, N + 1) {\n    int k = ANS[n - 1];\n    while\
    \ (k > 0 && S[k] != S[n - 1]) k = ANS[k];\n    ANS[n] = k + (S[k] == S[n - 1]);\n\
    \  }\n  return ANS;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/kmp.hpp\n\n\
    // KMP[n]: longest border length of S[0,n) or 0.\n// https://codeforces.com/contest/2209/problem/E\n\
    template <typename STRING>\nvector<int> kmp(const STRING& S) {\n  int N = len(S);\n\
    \  vc<int> ANS(N + 1);\n  FOR(n, 2, N + 1) {\n    int k = ANS[n - 1];\n    while\
    \ (k > 0 && S[k] != S[n - 1]) k = ANS[k];\n    ANS[n] = k + (S[k] == S[n - 1]);\n\
    \  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/kmp.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/kmp.hpp
layout: document
redirect_from:
- /library/string/kmp.hpp
- /library/string/kmp.hpp.html
title: string/kmp.hpp
---
