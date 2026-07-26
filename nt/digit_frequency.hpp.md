---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/digit_freq.test.cpp
    title: test/1_mytest/digit_freq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/digit_frequency.hpp\"\ntemplate <typename T = ll, int\
    \ K = 10>\narray<T, K> digit_frequency_vector(vc<int> A, bool include_N) {\n \
    \ assert(len(A) > 0 && A[0] != '0');\n  ll n = len(A);\n  vc<T> pw(n + 1, T(1));\n\
    \  FOR(i, n) pw[i + 1] = pw[i] * K;\n  using ARR = array<T, K>;\n  ARR dp{}, same{};\n\
    \  same[A[0]] = 1;\n  FOR(i, 1, A[0]) dp[i] = 1;\n  T lo_cnt = SUM<T>(dp);\n \
    \ FOR(i, 1, len(A)) {\n    int a = A[i];\n    ARR newdp{};\n    FOR(k, K) newdp[k]\
    \ = dp[k] * K + lo_cnt + same[k] * a + (k < a) + (k > 0);\n    lo_cnt = lo_cnt\
    \ * K + a + (K - 1);\n    swap(dp, newdp);\n    same[a] += 1;\n  }\n  if (include_N)\
    \ {\n    FOR(k, K) dp[k] += same[k];\n  }\n  return dp;\n}\n\n// [L,R) \u3092\u3059\
    \u3079\u3066 10 \u9032\u8868\u8A18\u3057\u305F\u3068\u304D\u306B\u5404 digit \u304C\
    \u73FE\u308C\u308B\u56DE\u6570\ntemplate <typename T = ll, int K = 10>\narray<T,\
    \ K> digit_frequency(u64 L, u64 R) {\n  auto F = [&](u64 N) -> array<T, K> {\n\
    \    vc<int> A;\n    while (N) {\n      A.eb(N % K), N /= K;\n    }\n    reverse(all(A));\n\
    \    return digit_frequency_vector<T, K>(A, false);\n  };\n  array<T, K> A = F(R);\n\
    \  array<T, K> B = F(L);\n  FOR(k, K) A[k] -= B[k];\n  return A;\n}\n"
  code: "template <typename T = ll, int K = 10>\narray<T, K> digit_frequency_vector(vc<int>\
    \ A, bool include_N) {\n  assert(len(A) > 0 && A[0] != '0');\n  ll n = len(A);\n\
    \  vc<T> pw(n + 1, T(1));\n  FOR(i, n) pw[i + 1] = pw[i] * K;\n  using ARR = array<T,\
    \ K>;\n  ARR dp{}, same{};\n  same[A[0]] = 1;\n  FOR(i, 1, A[0]) dp[i] = 1;\n\
    \  T lo_cnt = SUM<T>(dp);\n  FOR(i, 1, len(A)) {\n    int a = A[i];\n    ARR newdp{};\n\
    \    FOR(k, K) newdp[k] = dp[k] * K + lo_cnt + same[k] * a + (k < a) + (k > 0);\n\
    \    lo_cnt = lo_cnt * K + a + (K - 1);\n    swap(dp, newdp);\n    same[a] +=\
    \ 1;\n  }\n  if (include_N) {\n    FOR(k, K) dp[k] += same[k];\n  }\n  return\
    \ dp;\n}\n\n// [L,R) \u3092\u3059\u3079\u3066 10 \u9032\u8868\u8A18\u3057\u305F\
    \u3068\u304D\u306B\u5404 digit \u304C\u73FE\u308C\u308B\u56DE\u6570\ntemplate\
    \ <typename T = ll, int K = 10>\narray<T, K> digit_frequency(u64 L, u64 R) {\n\
    \  auto F = [&](u64 N) -> array<T, K> {\n    vc<int> A;\n    while (N) {\n   \
    \   A.eb(N % K), N /= K;\n    }\n    reverse(all(A));\n    return digit_frequency_vector<T,\
    \ K>(A, false);\n  };\n  array<T, K> A = F(R);\n  array<T, K> B = F(L);\n  FOR(k,\
    \ K) A[k] -= B[k];\n  return A;\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/digit_frequency.hpp
  requiredBy: []
  timestamp: '2025-09-01 16:03:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/digit_freq.test.cpp
documentation_of: nt/digit_frequency.hpp
layout: document
redirect_from:
- /library/nt/digit_frequency.hpp
- /library/nt/digit_frequency.hpp.html
title: nt/digit_frequency.hpp
---
