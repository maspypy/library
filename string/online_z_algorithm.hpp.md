---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/online_z.test.cpp
    title: test/2_library_checker/string/online_z.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/1286/E
    - https://heno239.hatenablog.com/entry/2020/07/07/140651
  bundledCode: "#line 1 \"string/online_z_algorithm.hpp\"\n\n// https://heno239.hatenablog.com/entry/2020/07/07/140651\n\
    // S[i] \u3092\u8FFD\u52A0\u3059\u308B\u3068\uFF0CS[j:i] \u304C lcp \u3067\u3042\
    \u308B\u3088\u3046\u306A j \u5168\u4F53\u306E vector \u304C\u304B\u3048\u308B\
    .\n// https://codeforces.com/problemset/problem/1286/E\ntemplate <typename CHAR\
    \ = char>\nstruct Online_Z_Algorithm {\n  vc<CHAR> S;\n  vc<int> Z;\n  vvc<int>\
    \ memo;\n  int p;\n\n  Online_Z_Algorithm() : p(1){};\n\n  vc<int> add(int i,\
    \ CHAR c) {\n    assert(i == len(S));\n    S.push_back(c);\n    int len = S.size();\n\
    \    Z.eb(-1);\n    memo.resize(1 + i);\n    vc<int> end;\n\n    if (len == 1)\
    \ return end;\n    if (S[0] != c) Z[i] = 0, end.eb(i);\n\n    auto del = [&](int\
    \ j) -> void { Z[j] = i - j, memo[i].eb(j), end.eb(j); };\n\n    while (p <= i)\
    \ {\n      if (Z[p] != -1) { ++p; }\n      elif (S[i - p] != S[i]) { del(p++);\
    \ }\n      else {\n        break;\n      }\n    }\n    if (p < i) {\n      for\
    \ (int j: memo[i - p]) { del(j + p); }\n    }\n    return end;\n  }\n  int query(int\
    \ i) { return (Z[i] == -1 ? len(S) - i : Z[i]); }\n};\n"
  code: "\n// https://heno239.hatenablog.com/entry/2020/07/07/140651\n// S[i] \u3092\
    \u8FFD\u52A0\u3059\u308B\u3068\uFF0CS[j:i] \u304C lcp \u3067\u3042\u308B\u3088\
    \u3046\u306A j \u5168\u4F53\u306E vector \u304C\u304B\u3048\u308B.\n// https://codeforces.com/problemset/problem/1286/E\n\
    template <typename CHAR = char>\nstruct Online_Z_Algorithm {\n  vc<CHAR> S;\n\
    \  vc<int> Z;\n  vvc<int> memo;\n  int p;\n\n  Online_Z_Algorithm() : p(1){};\n\
    \n  vc<int> add(int i, CHAR c) {\n    assert(i == len(S));\n    S.push_back(c);\n\
    \    int len = S.size();\n    Z.eb(-1);\n    memo.resize(1 + i);\n    vc<int>\
    \ end;\n\n    if (len == 1) return end;\n    if (S[0] != c) Z[i] = 0, end.eb(i);\n\
    \n    auto del = [&](int j) -> void { Z[j] = i - j, memo[i].eb(j), end.eb(j);\
    \ };\n\n    while (p <= i) {\n      if (Z[p] != -1) { ++p; }\n      elif (S[i\
    \ - p] != S[i]) { del(p++); }\n      else {\n        break;\n      }\n    }\n\
    \    if (p < i) {\n      for (int j: memo[i - p]) { del(j + p); }\n    }\n   \
    \ return end;\n  }\n  int query(int i) { return (Z[i] == -1 ? len(S) - i : Z[i]);\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/online_z_algorithm.hpp
  requiredBy: []
  timestamp: '2024-01-06 22:36:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/string/online_z.test.cpp
documentation_of: string/online_z_algorithm.hpp
layout: document
redirect_from:
- /library/string/online_z_algorithm.hpp
- /library/string/online_z_algorithm.hpp.html
title: string/online_z_algorithm.hpp
---
