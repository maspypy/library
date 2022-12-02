---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/enum_partitions.test.cpp
    title: test/mytest/enum_partitions.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1263.test.cpp
    title: test/yukicoder/1263.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1881.test.cpp
    title: test/yukicoder/1881.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/partitions.hpp\"\n/*\nN \u306E partition \u306E\
    \u5217\u6319\u3057\u3066\u3001partition p \u3054\u3068\u306B query(p) \u3092\u884C\
    \u3046\npartition \u306F\u3001\u6E1B\u5C11\u5217\u3068\u3057\u3066\u8F9E\u66F8\
    \u5F0F\u306E\u964D\u9806\u306B\u5217\u6319\u3059\u308B\n\u751F\u6210\u306B\u304B\
    \u304B\u308B\u6642\u9593\n\u30FBN = 50\uFF08204226\uFF09\uFF1A12 ms\n\u30FBN =\
    \ 60\uFF08966467\uFF09\uFF1A60 ms\n\u30FBN = 70\uFF084087968\uFF09\uFF1A270 ms\n\
    \u30FBN = 80\uFF0815796476\uFF09\uFF1A1100 ms\n*/\ntemplate <typename F>\nvoid\
    \ enumerate_partitions(int N, F query, int LIM_len = -1, int LIM_val = -1) {\n\
    \  assert(N >= 0);\n  auto dfs = [&](auto self, vc<int>& p, int sum) -> void {\n\
    \    if (sum == N) {\n      query(p);\n      return;\n    }\n    if (LIM_len !=\
    \ -1 && len(p) == LIM_len) return;\n    int nxt = (len(p) == 0 ? N : p.back());\n\
    \    if (LIM_val != -1) chmin(nxt, LIM_val);\n    chmin(nxt, N - sum);\n    p.eb(0);\n\
    \    FOR3_R(x, 1, nxt + 1) {\n      p.back() = x;\n      self(self, p, sum + x);\n\
    \    }\n    p.pop_back();\n  };\n  vc<int> p;\n  dfs(dfs, p, 0);\n}\n"
  code: "/*\nN \u306E partition \u306E\u5217\u6319\u3057\u3066\u3001partition p \u3054\
    \u3068\u306B query(p) \u3092\u884C\u3046\npartition \u306F\u3001\u6E1B\u5C11\u5217\
    \u3068\u3057\u3066\u8F9E\u66F8\u5F0F\u306E\u964D\u9806\u306B\u5217\u6319\u3059\
    \u308B\n\u751F\u6210\u306B\u304B\u304B\u308B\u6642\u9593\n\u30FBN = 50\uFF08204226\uFF09\
    \uFF1A12 ms\n\u30FBN = 60\uFF08966467\uFF09\uFF1A60 ms\n\u30FBN = 70\uFF084087968\uFF09\
    \uFF1A270 ms\n\u30FBN = 80\uFF0815796476\uFF09\uFF1A1100 ms\n*/\ntemplate <typename\
    \ F>\nvoid enumerate_partitions(int N, F query, int LIM_len = -1, int LIM_val\
    \ = -1) {\n  assert(N >= 0);\n  auto dfs = [&](auto self, vc<int>& p, int sum)\
    \ -> void {\n    if (sum == N) {\n      query(p);\n      return;\n    }\n    if\
    \ (LIM_len != -1 && len(p) == LIM_len) return;\n    int nxt = (len(p) == 0 ? N\
    \ : p.back());\n    if (LIM_val != -1) chmin(nxt, LIM_val);\n    chmin(nxt, N\
    \ - sum);\n    p.eb(0);\n    FOR3_R(x, 1, nxt + 1) {\n      p.back() = x;\n  \
    \    self(self, p, sum + x);\n    }\n    p.pop_back();\n  };\n  vc<int> p;\n \
    \ dfs(dfs, p, 0);\n}"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/partitions.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1263.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/mytest/enum_partitions.test.cpp
documentation_of: enumerate/partitions.hpp
layout: document
redirect_from:
- /library/enumerate/partitions.hpp
- /library/enumerate/partitions.hpp.html
title: enumerate/partitions.hpp
---
