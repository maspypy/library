---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/153948?#comment-1367191
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
    \ : (1ULL << n) - 1; }\n#line 2 \"setfunc/maxmin_partition.hpp\"\n\n// https://codeforces.com/blog/entry/153948?#comment-1367191\n\
    // O(n 2^n)\ntemplate <typename WT>\nWT maxmin_partition(int K, vc<WT> A) {\n\
    \  int N = len(A);\n  if (N < K) return 0;\n  assert(1 <= K && K <= N);\n  vc<WT>\
    \ S(1 << N);\n  FOR(i, N) FOR(s, 1 << i) S[s | 1 << i] = S[s] + A[i];\n\n  WT\
    \ ANS = 0;\n  int full = full_mask(N);\n  using P = pair<int, WT>;\n  vc<P> dp(1\
    \ << N);\n  for (int s = 0; s < (1 << N); ++s) {\n    int other = full ^ s;\n\
    \    auto [k, w] = dp[s];\n    WT W = S[other] + w;\n    if (k == K - 1) {\n \
    \     chmax(ANS, W);\n      continue;\n    }\n    while (other) {\n      int i\
    \ = lowbit(other);\n      other &= other - 1;\n      int t = s | 1 << i;\n   \
    \   WT x = w + A[i];\n      P nxt = (x * (K - k) >= W ? P(k + 1, 0) : P(k, x));\n\
    \      chmax(dp[t], nxt);\n    }\n  }\n  return ANS;\n}\n"
  code: "#include \"other/bit.hpp\"\n\n// https://codeforces.com/blog/entry/153948?#comment-1367191\n\
    // O(n 2^n)\ntemplate <typename WT>\nWT maxmin_partition(int K, vc<WT> A) {\n\
    \  int N = len(A);\n  if (N < K) return 0;\n  assert(1 <= K && K <= N);\n  vc<WT>\
    \ S(1 << N);\n  FOR(i, N) FOR(s, 1 << i) S[s | 1 << i] = S[s] + A[i];\n\n  WT\
    \ ANS = 0;\n  int full = full_mask(N);\n  using P = pair<int, WT>;\n  vc<P> dp(1\
    \ << N);\n  for (int s = 0; s < (1 << N); ++s) {\n    int other = full ^ s;\n\
    \    auto [k, w] = dp[s];\n    WT W = S[other] + w;\n    if (k == K - 1) {\n \
    \     chmax(ANS, W);\n      continue;\n    }\n    while (other) {\n      int i\
    \ = lowbit(other);\n      other &= other - 1;\n      int t = s | 1 << i;\n   \
    \   WT x = w + A[i];\n      P nxt = (x * (K - k) >= W ? P(k + 1, 0) : P(k, x));\n\
    \      chmax(dp[t], nxt);\n    }\n  }\n  return ANS;\n}\n"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: setfunc/maxmin_partition.hpp
  requiredBy: []
  timestamp: '2026-08-17 12:47:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/maxmin_partition.hpp
layout: document
redirect_from:
- /library/setfunc/maxmin_partition.hpp
- /library/setfunc/maxmin_partition.hpp.html
title: setfunc/maxmin_partition.hpp
---
