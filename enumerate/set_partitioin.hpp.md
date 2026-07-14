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
  bundledCode: "#line 1 \"enumerate/set_partitioin.hpp\"\n\n// N \u5143\u96C6\u5408\
    \u306E\u5206\u5272\u306E\u5217\u6319\n// f({s0,s1,...})\ntemplate <typename F>\n\
    void set_partition(int N, F f) {\n  vc<int> S;\n  auto dfs = [&](auto &dfs, u32\
    \ rest) -> void {\n    if (rest == 0) {\n      return f(S);\n    }\n    int a\
    \ = lowbit(rest);\n    rest -= u32(1) << a;\n    for (int s : all_subset<u32>(rest))\
    \ {\n      S.eb(s | 1 << a);\n      dfs(dfs, rest - s);\n      POP(S);\n    }\n\
    \  };\n  dfs(dfs, (u32(1) << N) - 1);\n}\n"
  code: "\n// N \u5143\u96C6\u5408\u306E\u5206\u5272\u306E\u5217\u6319\n// f({s0,s1,...})\n\
    template <typename F>\nvoid set_partition(int N, F f) {\n  vc<int> S;\n  auto\
    \ dfs = [&](auto &dfs, u32 rest) -> void {\n    if (rest == 0) {\n      return\
    \ f(S);\n    }\n    int a = lowbit(rest);\n    rest -= u32(1) << a;\n    for (int\
    \ s : all_subset<u32>(rest)) {\n      S.eb(s | 1 << a);\n      dfs(dfs, rest -\
    \ s);\n      POP(S);\n    }\n  };\n  dfs(dfs, (u32(1) << N) - 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/set_partitioin.hpp
  requiredBy: []
  timestamp: '2026-07-14 09:59:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/set_partitioin.hpp
layout: document
redirect_from:
- /library/enumerate/set_partitioin.hpp
- /library/enumerate/set_partitioin.hpp.html
title: enumerate/set_partitioin.hpp
---
