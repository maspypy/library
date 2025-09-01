---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
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
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc390/tasks/abc390_d
  bundledCode: "#line 1 \"enumerate/partition.hpp\"\n/*\npartition \u306F\u3001\u300C\
    \u6E1B\u5C11\u5217\u300D\u3068\u3057\u3066\u8F9E\u66F8\u5F0F\u306E\u964D\u9806\
    \u306B\u5217\u6319\u3059\u308B\u3002\nN = 50\uFF08204226\uFF09\uFF1A12 ms\nN =\
    \ 60\uFF08966467\uFF09\uFF1A60 ms\nN = 70\uFF084087968\uFF09\uFF1A270 ms\nN =\
    \ 80\uFF0815796476\uFF09\uFF1A1100 ms\nN = 90\uFF0856634173\uFF09\uFF1A4800 ms\n\
    N = 100 (190569292) : 15600 ms\n*/\ntemplate <typename F>\nvoid enumerate_partition(int\
    \ N, F query, int LIM_len = -1, int LIM_val = -1) {\n  assert(N >= 0);\n  auto\
    \ dfs = [&](auto self, vc<int> &p, int sum) -> void {\n    if (sum == N) {\n \
    \     query(p);\n      return;\n    }\n    if (LIM_len != -1 && len(p) == LIM_len)\n\
    \      return;\n    int nxt = (len(p) == 0 ? N : p.back());\n    if (LIM_val !=\
    \ -1)\n      chmin(nxt, LIM_val);\n    chmin(nxt, N - sum);\n    p.eb(0);\n  \
    \  FOR3_R(x, 1, nxt + 1) {\n      p.back() = x;\n      self(self, p, sum + x);\n\
    \    }\n    p.pop_back();\n  };\n  vc<int> p;\n  dfs(dfs, p, 0);\n}\n\n// N \u5143\
    \u96C6\u5408\u306E\u5206\u5272\u306E\u5217\u6319 (Bell number)\n// f({s0,s1,...}),\
    \ f(vc<int>)\n// https://atcoder.jp/contests/abc390/tasks/abc390_d\n// N = 11\uFF08\
    678570\uFF09\uFF1A29 ms\n// N = 12\uFF084213597\uFF09\uFF1A208 ms\n// N = 13\uFF08\
    27644437\uFF09\uFF1A2084 ms\ntemplate <typename F> void enumerate_set_partition(int\
    \ N, F f) {\n  vc<int> S;\n  auto dfs = [&](auto &dfs, int rest) -> void {\n \
    \   if (rest == 0) {\n      return f(S);\n    }\n    int a = lowbit(rest);\n \
    \   rest -= u32(1) << a;\n    for (int s : all_subset<u32>(rest)) {\n      S.eb(s\
    \ | 1 << a);\n      dfs(dfs, rest - s);\n      POP(S);\n    }\n  };\n  dfs(dfs,\
    \ (u32(1) << N) - 1);\n}\n"
  code: "/*\npartition \u306F\u3001\u300C\u6E1B\u5C11\u5217\u300D\u3068\u3057\u3066\
    \u8F9E\u66F8\u5F0F\u306E\u964D\u9806\u306B\u5217\u6319\u3059\u308B\u3002\nN =\
    \ 50\uFF08204226\uFF09\uFF1A12 ms\nN = 60\uFF08966467\uFF09\uFF1A60 ms\nN = 70\uFF08\
    4087968\uFF09\uFF1A270 ms\nN = 80\uFF0815796476\uFF09\uFF1A1100 ms\nN = 90\uFF08\
    56634173\uFF09\uFF1A4800 ms\nN = 100 (190569292) : 15600 ms\n*/\ntemplate <typename\
    \ F>\nvoid enumerate_partition(int N, F query, int LIM_len = -1, int LIM_val =\
    \ -1) {\n  assert(N >= 0);\n  auto dfs = [&](auto self, vc<int> &p, int sum) ->\
    \ void {\n    if (sum == N) {\n      query(p);\n      return;\n    }\n    if (LIM_len\
    \ != -1 && len(p) == LIM_len)\n      return;\n    int nxt = (len(p) == 0 ? N :\
    \ p.back());\n    if (LIM_val != -1)\n      chmin(nxt, LIM_val);\n    chmin(nxt,\
    \ N - sum);\n    p.eb(0);\n    FOR3_R(x, 1, nxt + 1) {\n      p.back() = x;\n\
    \      self(self, p, sum + x);\n    }\n    p.pop_back();\n  };\n  vc<int> p;\n\
    \  dfs(dfs, p, 0);\n}\n\n// N \u5143\u96C6\u5408\u306E\u5206\u5272\u306E\u5217\
    \u6319 (Bell number)\n// f({s0,s1,...}), f(vc<int>)\n// https://atcoder.jp/contests/abc390/tasks/abc390_d\n\
    // N = 11\uFF08678570\uFF09\uFF1A29 ms\n// N = 12\uFF084213597\uFF09\uFF1A208\
    \ ms\n// N = 13\uFF0827644437\uFF09\uFF1A2084 ms\ntemplate <typename F> void enumerate_set_partition(int\
    \ N, F f) {\n  vc<int> S;\n  auto dfs = [&](auto &dfs, int rest) -> void {\n \
    \   if (rest == 0) {\n      return f(S);\n    }\n    int a = lowbit(rest);\n \
    \   rest -= u32(1) << a;\n    for (int s : all_subset<u32>(rest)) {\n      S.eb(s\
    \ | 1 << a);\n      dfs(dfs, rest - s);\n      POP(S);\n    }\n  };\n  dfs(dfs,\
    \ (u32(1) << N) - 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/partition.hpp
  requiredBy: []
  timestamp: '2025-06-24 13:25:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1263.test.cpp
  - test/3_yukicoder/1881.test.cpp
  - test/1_mytest/enum_partitions.test.cpp
documentation_of: enumerate/partition.hpp
layout: document
redirect_from:
- /library/enumerate/partition.hpp
- /library/enumerate/partition.hpp.html
title: enumerate/partition.hpp
---
