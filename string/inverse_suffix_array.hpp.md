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
    - https://atcoder.jp/contests/arc044/tasks/arc044_d
  bundledCode: "#line 1 \"string/inverse_suffix_array.hpp\"\n\n// https://atcoder.jp/contests/arc044/tasks/arc044_d\n\
    // \u8F9E\u66F8\u6700\u5C0F OR\n// \u5165\u529B\u306F [0,N) permutation\nvc<int>\
    \ inverse_suffix_array(vc<int> A) {\n  int N = len(A);\n  vc<int> rk(N);\n  FOR(i,\
    \ N) rk[A[i]] = i;\n  FOR(i, N) assert(rk[A[i]] == i && A[rk[i]] == i);\n  vc<int>\
    \ S(N);\n  FOR(k, 1, N) {\n    int i = A[k - 1], j = A[k];\n    S[j] = S[i];\n\
    \    if (i < N - 1 && (j == N - 1 || (rk[i + 1] > rk[j + 1]))) S[j]++;\n  }\n\
    \  return S;\n}\n"
  code: "\n// https://atcoder.jp/contests/arc044/tasks/arc044_d\n// \u8F9E\u66F8\u6700\
    \u5C0F OR\n// \u5165\u529B\u306F [0,N) permutation\nvc<int> inverse_suffix_array(vc<int>\
    \ A) {\n  int N = len(A);\n  vc<int> rk(N);\n  FOR(i, N) rk[A[i]] = i;\n  FOR(i,\
    \ N) assert(rk[A[i]] == i && A[rk[i]] == i);\n  vc<int> S(N);\n  FOR(k, 1, N)\
    \ {\n    int i = A[k - 1], j = A[k];\n    S[j] = S[i];\n    if (i < N - 1 && (j\
    \ == N - 1 || (rk[i + 1] > rk[j + 1]))) S[j]++;\n  }\n  return S;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/inverse_suffix_array.hpp
  requiredBy: []
  timestamp: '2024-10-11 20:53:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/inverse_suffix_array.hpp
layout: document
redirect_from:
- /library/string/inverse_suffix_array.hpp
- /library/string/inverse_suffix_array.hpp.html
title: string/inverse_suffix_array.hpp
---
