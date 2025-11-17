---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/staticrmq_dc.test.cpp
    title: test/2_library_checker/data_structure/staticrmq_dc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qoj.ac/contest/1784/problem/9245
  bundledCode: "#line 1 \"ds/offline_query/static_monoid_products.hpp\"\n// f(q, Lprod,\
    \ Rprod)\n// f \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\u3082\u306E\u306F\u3059\
    \u3079\u3066\u5358\u9805\u8FFD\u52A0\n// https://qoj.ac/contest/1784/problem/9245\n\
    template <typename Mono, typename T, typename F>\nvoid static_monoid_products(vc<T>&\
    \ A, vc<pair<int, int>>& query, F f) {\n  int N = len(A), Q = len(query);\n  vvc<int>\
    \ IDS(N);\n  FOR(q, Q) {\n    auto [L, R] = query[q];\n    if (L == R) { f(q,\
    \ Mono::unit(), Mono::unit()); }\n    elif (R <= L + 16) {\n      T ans = A[L];\n\
    \      FOR(i, L + 1, R) ans = Mono::op(ans, A[i]);\n      f(q, ans, Mono::unit());\n\
    \    }\n    else {\n      --R;\n      int k = topbit(L ^ R);\n      int M = R\
    \ >> k << k;\n      IDS[M].eb(q);\n    }\n  }\n  vc<T> dp(N + 1);\n\n  FOR(M,\
    \ N) {\n    auto& I = IDS[M];\n    if (I.empty()) continue;\n    int min_a = M,\
    \ max_b = M;\n    for (int q: I) {\n      auto [a, b] = query[q];\n      min_a\
    \ = min(min_a, a), max_b = max(max_b, b);\n    }\n    // \u7D2F\u7A4D\u7A4D\u306E\
    \u8A08\u7B97\n    dp[M] = Mono::unit();\n    for (int i = M; i > min_a; --i) dp[i\
    \ - 1] = Mono::op(A[i - 1], dp[i]);\n    for (int i = M; i < max_b; ++i) dp[i\
    \ + 1] = Mono::op(dp[i], A[i]);\n    // \u7B54\u306E\u8A08\u7B97\n    for (int\
    \ q: I) {\n      auto [a, b] = query[q];\n      f(q, dp[a], dp[b]);\n    }\n \
    \ }\n}\n"
  code: "// f(q, Lprod, Rprod)\n// f \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\u3082\
    \u306E\u306F\u3059\u3079\u3066\u5358\u9805\u8FFD\u52A0\n// https://qoj.ac/contest/1784/problem/9245\n\
    template <typename Mono, typename T, typename F>\nvoid static_monoid_products(vc<T>&\
    \ A, vc<pair<int, int>>& query, F f) {\n  int N = len(A), Q = len(query);\n  vvc<int>\
    \ IDS(N);\n  FOR(q, Q) {\n    auto [L, R] = query[q];\n    if (L == R) { f(q,\
    \ Mono::unit(), Mono::unit()); }\n    elif (R <= L + 16) {\n      T ans = A[L];\n\
    \      FOR(i, L + 1, R) ans = Mono::op(ans, A[i]);\n      f(q, ans, Mono::unit());\n\
    \    }\n    else {\n      --R;\n      int k = topbit(L ^ R);\n      int M = R\
    \ >> k << k;\n      IDS[M].eb(q);\n    }\n  }\n  vc<T> dp(N + 1);\n\n  FOR(M,\
    \ N) {\n    auto& I = IDS[M];\n    if (I.empty()) continue;\n    int min_a = M,\
    \ max_b = M;\n    for (int q: I) {\n      auto [a, b] = query[q];\n      min_a\
    \ = min(min_a, a), max_b = max(max_b, b);\n    }\n    // \u7D2F\u7A4D\u7A4D\u306E\
    \u8A08\u7B97\n    dp[M] = Mono::unit();\n    for (int i = M; i > min_a; --i) dp[i\
    \ - 1] = Mono::op(A[i - 1], dp[i]);\n    for (int i = M; i < max_b; ++i) dp[i\
    \ + 1] = Mono::op(dp[i], A[i]);\n    // \u7B54\u306E\u8A08\u7B97\n    for (int\
    \ q: I) {\n      auto [a, b] = query[q];\n      f(q, dp[a], dp[b]);\n    }\n \
    \ }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/static_monoid_products.hpp
  requiredBy: []
  timestamp: '2024-09-10 04:34:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/data_structure/staticrmq_dc.test.cpp
documentation_of: ds/offline_query/static_monoid_products.hpp
layout: document
redirect_from:
- /library/ds/offline_query/static_monoid_products.hpp
- /library/ds/offline_query/static_monoid_products.hpp.html
title: ds/offline_query/static_monoid_products.hpp
---
