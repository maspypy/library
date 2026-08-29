---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: other/bit.hpp
    title: other/bit.hpp
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
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x & 0x5555555555555555ULL)\
    \ << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x = ((x & 0x3333333333333333ULL)\
    \ << 2) | ((x >> 2) & 0x3333333333333333ULL);\n  x = ((x & 0x0f0f0f0f0f0f0f0fULL)\
    \ << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n  x = ((x & 0x00ff00ff00ff00ffULL)\
    \ << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n  x = ((x & 0x0000ffff0000ffffULL)\
    \ << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n  x = (x << 32) | (x >> 32);\n\
    \  return x;\n}\n#line 2 \"ds/offline_query/static_monoid_products.hpp\"\n\n//\
    \ f(q, Lprod, Rprod)\n// f \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\u3082\u306E\
    \u306F\u3059\u3079\u3066\u5358\u9805\u8FFD\u52A0\n// https://qoj.ac/contest/1784/problem/9245\n\
    template <typename Mono, typename T, typename F>\nvoid static_monoid_products(vc<T>&\
    \ A, vc<pair<int, int>>& query, F f) {\n  int N = len(A), Q = len(query);\n  vvc<int>\
    \ IDS(N);\n  FOR(q, Q) {\n    auto [L, R] = query[q];\n    if (L == R) {\n   \
    \   f(q, Mono::unit(), Mono::unit());\n    }\n    elif (R <= L + 16) {\n     \
    \ T ans = A[L];\n      FOR(i, L + 1, R) ans = Mono::op(ans, A[i]);\n      f(q,\
    \ ans, Mono::unit());\n    }\n    else {\n      --R;\n      int k = topbit(L ^\
    \ R);\n      int M = R >> k << k;\n      IDS[M].eb(q);\n    }\n  }\n  vc<T> dp(N\
    \ + 1);\n\n  FOR(M, N) {\n    auto& I = IDS[M];\n    if (I.empty()) continue;\n\
    \    int min_a = M, max_b = M;\n    for (int q : I) {\n      auto [a, b] = query[q];\n\
    \      min_a = min(min_a, a), max_b = max(max_b, b);\n    }\n    // \u7D2F\u7A4D\
    \u7A4D\u306E\u8A08\u7B97\n    dp[M] = Mono::unit();\n    for (int i = M; i > min_a;\
    \ --i) dp[i - 1] = Mono::op(A[i - 1], dp[i]);\n    for (int i = M; i < max_b;\
    \ ++i) dp[i + 1] = Mono::op(dp[i], A[i]);\n    // \u7B54\u306E\u8A08\u7B97\n \
    \   for (int q : I) {\n      auto [a, b] = query[q];\n      f(q, dp[a], dp[b]);\n\
    \    }\n  }\n}\n"
  code: "#include \"other/bit.hpp\"\n\n// f(q, Lprod, Rprod)\n// f \u4EE5\u5916\u3067\
    \u547C\u3070\u308C\u308B\u3082\u306E\u306F\u3059\u3079\u3066\u5358\u9805\u8FFD\
    \u52A0\n// https://qoj.ac/contest/1784/problem/9245\ntemplate <typename Mono,\
    \ typename T, typename F>\nvoid static_monoid_products(vc<T>& A, vc<pair<int,\
    \ int>>& query, F f) {\n  int N = len(A), Q = len(query);\n  vvc<int> IDS(N);\n\
    \  FOR(q, Q) {\n    auto [L, R] = query[q];\n    if (L == R) {\n      f(q, Mono::unit(),\
    \ Mono::unit());\n    }\n    elif (R <= L + 16) {\n      T ans = A[L];\n     \
    \ FOR(i, L + 1, R) ans = Mono::op(ans, A[i]);\n      f(q, ans, Mono::unit());\n\
    \    }\n    else {\n      --R;\n      int k = topbit(L ^ R);\n      int M = R\
    \ >> k << k;\n      IDS[M].eb(q);\n    }\n  }\n  vc<T> dp(N + 1);\n\n  FOR(M,\
    \ N) {\n    auto& I = IDS[M];\n    if (I.empty()) continue;\n    int min_a = M,\
    \ max_b = M;\n    for (int q : I) {\n      auto [a, b] = query[q];\n      min_a\
    \ = min(min_a, a), max_b = max(max_b, b);\n    }\n    // \u7D2F\u7A4D\u7A4D\u306E\
    \u8A08\u7B97\n    dp[M] = Mono::unit();\n    for (int i = M; i > min_a; --i) dp[i\
    \ - 1] = Mono::op(A[i - 1], dp[i]);\n    for (int i = M; i < max_b; ++i) dp[i\
    \ + 1] = Mono::op(dp[i], A[i]);\n    // \u7B54\u306E\u8A08\u7B97\n    for (int\
    \ q : I) {\n      auto [a, b] = query[q];\n      f(q, dp[a], dp[b]);\n    }\n\
    \  }\n}\n"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: ds/offline_query/static_monoid_products.hpp
  requiredBy: []
  timestamp: '2026-08-19 06:34:57+09:00'
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
