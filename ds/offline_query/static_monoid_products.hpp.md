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
  bundledCode: "#line 1 \"ds/offline_query/static_monoid_products.hpp\"\n\ntemplate\
    \ <typename Mono, typename T>\nvc<T> static_monoid_products(vc<T>& A, vc<pair<int,\
    \ int>>& query) {\n  int N = len(A), Q = len(query);\n\n  vc<T> ANS(Q);\n  vvc<int>\
    \ IDS(N);\n  FOR(q, Q) {\n    auto [L, R] = query[q];\n    if (L == R) { ANS[q]\
    \ = Mono::unit(); }\n    elif (R <= L + 32) {\n      ANS[q] = A[L];\n      FOR(i,\
    \ L + 1, R) ANS[q] = Mono::op(ANS[q], A[i]);\n    }\n    else {\n      --R;\n\
    \      int k = topbit(L ^ R);\n      int M = R >> k << k;\n      IDS[M].eb(q);\n\
    \    }\n  }\n  vc<T> dp(N + 1);\n\n  FOR(M, N) {\n    auto& I = IDS[M];\n    if\
    \ (I.empty()) continue;\n    int min_a = M, max_b = M;\n    for (int q: I) {\n\
    \      auto [a, b] = query[q];\n      min_a = min(min_a, a), max_b = max(max_b,\
    \ b);\n    }\n    // \u7D2F\u7A4D\u7A4D\u306E\u8A08\u7B97\n    dp[M] = Mono::unit();\n\
    \    for (int i = M; i > min_a; --i) dp[i - 1] = Mono::op(A[i - 1], dp[i]);\n\
    \    for (int i = M; i < max_b; ++i) dp[i + 1] = Mono::op(dp[i], A[i]);\n    //\
    \ \u7B54\u306E\u8A08\u7B97\n    for (int q: I) {\n      auto [a, b] = query[q];\n\
    \      ANS[q] = Mono::op(dp[a], dp[b]);\n    }\n  }\n  return ANS;\n}\n"
  code: "\ntemplate <typename Mono, typename T>\nvc<T> static_monoid_products(vc<T>&\
    \ A, vc<pair<int, int>>& query) {\n  int N = len(A), Q = len(query);\n\n  vc<T>\
    \ ANS(Q);\n  vvc<int> IDS(N);\n  FOR(q, Q) {\n    auto [L, R] = query[q];\n  \
    \  if (L == R) { ANS[q] = Mono::unit(); }\n    elif (R <= L + 32) {\n      ANS[q]\
    \ = A[L];\n      FOR(i, L + 1, R) ANS[q] = Mono::op(ANS[q], A[i]);\n    }\n  \
    \  else {\n      --R;\n      int k = topbit(L ^ R);\n      int M = R >> k << k;\n\
    \      IDS[M].eb(q);\n    }\n  }\n  vc<T> dp(N + 1);\n\n  FOR(M, N) {\n    auto&\
    \ I = IDS[M];\n    if (I.empty()) continue;\n    int min_a = M, max_b = M;\n \
    \   for (int q: I) {\n      auto [a, b] = query[q];\n      min_a = min(min_a,\
    \ a), max_b = max(max_b, b);\n    }\n    // \u7D2F\u7A4D\u7A4D\u306E\u8A08\u7B97\
    \n    dp[M] = Mono::unit();\n    for (int i = M; i > min_a; --i) dp[i - 1] = Mono::op(A[i\
    \ - 1], dp[i]);\n    for (int i = M; i < max_b; ++i) dp[i + 1] = Mono::op(dp[i],\
    \ A[i]);\n    // \u7B54\u306E\u8A08\u7B97\n    for (int q: I) {\n      auto [a,\
    \ b] = query[q];\n      ANS[q] = Mono::op(dp[a], dp[b]);\n    }\n  }\n  return\
    \ ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/static_monoid_products.hpp
  requiredBy: []
  timestamp: '2024-02-06 01:35:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offline_query/static_monoid_products.hpp
layout: document
redirect_from:
- /library/ds/offline_query/static_monoid_products.hpp
- /library/ds/offline_query/static_monoid_products.hpp.html
title: ds/offline_query/static_monoid_products.hpp
---
