---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/enum_partitions.test.cpp
    title: test/1_mytest/enum_partitions.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1263.test.cpp
    title: test/3_yukicoder/1263.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1881.test.cpp
    title: test/3_yukicoder/1881.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc390/tasks/abc390_d
  bundledCode: "#line 2 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \  UINT s;\n  struct iter {\n    UINT s;\n    int operator*() const { return lowbit(s);\
    \ }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t) const\
    \ { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t end()\
    \ const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  UINT s;\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ?\
    \ -1ULL : (1ULL << n) - 1; }\n#line 2 \"enumerate/bits.hpp\"\ntemplate <typename\
    \ BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int R, F&& f) {\n\
    \  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n  while\
    \ (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename\
    \ UINT, typename F>\ninline void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n#line 2 \"enumerate/partition.hpp\"\
    \n\n/*\npartition \u306F\u3001\u300C\u6E1B\u5C11\u5217\u300D\u3068\u3057\u3066\
    \u8F9E\u66F8\u5F0F\u306E\u964D\u9806\u306B\u5217\u6319\u3059\u308B\u3002\nN=10,20,30,40\uFF1A\
    42, 527, 5604, 37338\nN = 50\uFF08204226\uFF09\uFF1A12 ms\nN = 60\uFF08966467\uFF09\
    \uFF1A60 ms\nN = 70\uFF084087968\uFF09\uFF1A270 ms\nN = 80\uFF0815796476\uFF09\
    \uFF1A1100 ms\nN = 90\uFF0856634173\uFF09\uFF1A4800 ms\nN = 100 (190569292) :\
    \ 15600 ms\n*/\ntemplate <typename F>\nvoid enumerate_partition(int N, F query,\
    \ int LIM_len = -1, int LIM_val = -1) {\n  assert(N >= 0);\n  auto dfs = [&](auto\
    \ self, vc<int> &p, int sum) -> void {\n    if (sum == N) {\n      query(p);\n\
    \      return;\n    }\n    if (LIM_len != -1 && len(p) == LIM_len) return;\n \
    \   int nxt = (len(p) == 0 ? N : p.back());\n    if (LIM_val != -1) chmin(nxt,\
    \ LIM_val);\n    chmin(nxt, N - sum);\n    p.eb(0);\n    FOR3_R(x, 1, nxt + 1)\
    \ {\n      p.back() = x;\n      self(self, p, sum + x);\n    }\n    p.pop_back();\n\
    \  };\n  vc<int> p;\n  dfs(dfs, p, 0);\n}\n\n// N \u5143\u96C6\u5408\u306E\u5206\
    \u5272\u306E\u5217\u6319 (Bell number)\n// f({s0,s1,...}), f(vc<int>)\n// https://atcoder.jp/contests/abc390/tasks/abc390_d\n\
    // N = 11\uFF08678570\uFF09\uFF1A29 ms\n// N = 12\uFF084213597\uFF09\uFF1A208\
    \ ms\n// N = 13\uFF0827644437\uFF09\uFF1A2084 ms\ntemplate <typename F>\nvoid\
    \ enumerate_set_partition(int N, F f) {\n  vc<u32> S;\n  auto dfs = [&](auto &dfs,\
    \ u32 rest) -> void {\n    if (rest == 0) {\n      return f(S);\n    }\n    int\
    \ a = lowbit(rest);\n    rest -= u32(1) << a;\n    enumerate_all_subset<u32, true>(rest,\
    \ [&](u32 s) -> void {\n      S.eb(s | 1 << a);\n      dfs(dfs, rest - s);\n \
    \     POP(S);\n    });\n  };\n  dfs(dfs, (u32(1) << N) - 1);\n}\n"
  code: "#include \"enumerate/bits.hpp\"\n\n/*\npartition \u306F\u3001\u300C\u6E1B\
    \u5C11\u5217\u300D\u3068\u3057\u3066\u8F9E\u66F8\u5F0F\u306E\u964D\u9806\u306B\
    \u5217\u6319\u3059\u308B\u3002\nN=10,20,30,40\uFF1A42, 527, 5604, 37338\nN = 50\uFF08\
    204226\uFF09\uFF1A12 ms\nN = 60\uFF08966467\uFF09\uFF1A60 ms\nN = 70\uFF084087968\uFF09\
    \uFF1A270 ms\nN = 80\uFF0815796476\uFF09\uFF1A1100 ms\nN = 90\uFF0856634173\uFF09\
    \uFF1A4800 ms\nN = 100 (190569292) : 15600 ms\n*/\ntemplate <typename F>\nvoid\
    \ enumerate_partition(int N, F query, int LIM_len = -1, int LIM_val = -1) {\n\
    \  assert(N >= 0);\n  auto dfs = [&](auto self, vc<int> &p, int sum) -> void {\n\
    \    if (sum == N) {\n      query(p);\n      return;\n    }\n    if (LIM_len !=\
    \ -1 && len(p) == LIM_len) return;\n    int nxt = (len(p) == 0 ? N : p.back());\n\
    \    if (LIM_val != -1) chmin(nxt, LIM_val);\n    chmin(nxt, N - sum);\n    p.eb(0);\n\
    \    FOR3_R(x, 1, nxt + 1) {\n      p.back() = x;\n      self(self, p, sum + x);\n\
    \    }\n    p.pop_back();\n  };\n  vc<int> p;\n  dfs(dfs, p, 0);\n}\n\n// N \u5143\
    \u96C6\u5408\u306E\u5206\u5272\u306E\u5217\u6319 (Bell number)\n// f({s0,s1,...}),\
    \ f(vc<int>)\n// https://atcoder.jp/contests/abc390/tasks/abc390_d\n// N = 11\uFF08\
    678570\uFF09\uFF1A29 ms\n// N = 12\uFF084213597\uFF09\uFF1A208 ms\n// N = 13\uFF08\
    27644437\uFF09\uFF1A2084 ms\ntemplate <typename F>\nvoid enumerate_set_partition(int\
    \ N, F f) {\n  vc<u32> S;\n  auto dfs = [&](auto &dfs, u32 rest) -> void {\n \
    \   if (rest == 0) {\n      return f(S);\n    }\n    int a = lowbit(rest);\n \
    \   rest -= u32(1) << a;\n    enumerate_all_subset<u32, true>(rest, [&](u32 s)\
    \ -> void {\n      S.eb(s | 1 << a);\n      dfs(dfs, rest - s);\n      POP(S);\n\
    \    });\n  };\n  dfs(dfs, (u32(1) << N) - 1);\n}\n"
  dependsOn:
  - enumerate/bits.hpp
  - other/bit.hpp
  isVerificationFile: false
  path: enumerate/partition.hpp
  requiredBy: []
  timestamp: '2026-07-26 20:34:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1881.test.cpp
  - test/3_yukicoder/1263.test.cpp
  - test/1_mytest/enum_partitions.test.cpp
documentation_of: enumerate/partition.hpp
layout: document
redirect_from:
- /library/enumerate/partition.hpp
- /library/enumerate/partition.hpp.html
title: enumerate/partition.hpp
---
