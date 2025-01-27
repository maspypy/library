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
    links: []
  bundledCode: "#line 1 \"enumerate/partition.hpp\"\n/*\npartition \u306F\u3001\u300C\
    \u6E1B\u5C11\u5217\u300D\u3068\u3057\u3066\u8F9E\u66F8\u5F0F\u306E\u964D\u9806\
    \u306B\u5217\u6319\u3059\u308B\u3002\nN = 50\uFF08204226\uFF09\uFF1A12 ms\nN =\
    \ 60\uFF08966467\uFF09\uFF1A60 ms\nN = 70\uFF084087968\uFF09\uFF1A270 ms\nN =\
    \ 80\uFF0815796476\uFF09\uFF1A1100 ms\nN = 90\uFF0856634173\uFF09\uFF1A4800 ms\n\
    N = 100 (190569292) : 15600 ms\n*/\ntemplate <typename F>\nvoid enumerate_partition(int\
    \ N, F query, int LIM_len = -1, int LIM_val = -1) {\n  assert(N >= 0);\n  auto\
    \ dfs = [&](auto self, vc<int>& p, int sum) -> void {\n    if (sum == N) {\n \
    \     query(p);\n      return;\n    }\n    if (LIM_len != -1 && len(p) == LIM_len)\
    \ return;\n    int nxt = (len(p) == 0 ? N : p.back());\n    if (LIM_val != -1)\
    \ chmin(nxt, LIM_val);\n    chmin(nxt, N - sum);\n    p.eb(0);\n    FOR3_R(x,\
    \ 1, nxt + 1) {\n      p.back() = x;\n      self(self, p, sum + x);\n    }\n \
    \   p.pop_back();\n  };\n  vc<int> p;\n  dfs(dfs, p, 0);\n}\n"
  code: "/*\npartition \u306F\u3001\u300C\u6E1B\u5C11\u5217\u300D\u3068\u3057\u3066\
    \u8F9E\u66F8\u5F0F\u306E\u964D\u9806\u306B\u5217\u6319\u3059\u308B\u3002\nN =\
    \ 50\uFF08204226\uFF09\uFF1A12 ms\nN = 60\uFF08966467\uFF09\uFF1A60 ms\nN = 70\uFF08\
    4087968\uFF09\uFF1A270 ms\nN = 80\uFF0815796476\uFF09\uFF1A1100 ms\nN = 90\uFF08\
    56634173\uFF09\uFF1A4800 ms\nN = 100 (190569292) : 15600 ms\n*/\ntemplate <typename\
    \ F>\nvoid enumerate_partition(int N, F query, int LIM_len = -1, int LIM_val =\
    \ -1) {\n  assert(N >= 0);\n  auto dfs = [&](auto self, vc<int>& p, int sum) ->\
    \ void {\n    if (sum == N) {\n      query(p);\n      return;\n    }\n    if (LIM_len\
    \ != -1 && len(p) == LIM_len) return;\n    int nxt = (len(p) == 0 ? N : p.back());\n\
    \    if (LIM_val != -1) chmin(nxt, LIM_val);\n    chmin(nxt, N - sum);\n    p.eb(0);\n\
    \    FOR3_R(x, 1, nxt + 1) {\n      p.back() = x;\n      self(self, p, sum + x);\n\
    \    }\n    p.pop_back();\n  };\n  vc<int> p;\n  dfs(dfs, p, 0);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/partition.hpp
  requiredBy: []
  timestamp: '2024-09-14 09:20:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
