---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2288.test.cpp
    title: test/yukicoder/2288.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/stable_matching.hpp\"\n\n// \u30B0\u30EB\u30FC\u30D7\
    \ 1 \u306B\u3068\u3063\u3066\u6700\u9069\u306A stable matching \u304C\u5B58\u5728\
    \u3059\u308B\u306E\u3067\u305D\u308C\u3092\u304B\u3048\u3059.\n// O((N+M)logM)\n\
    struct Stable_Matching {\n  int N1, N2;\n  vvc<tuple<int, int, int>> dat;\n  vc<int>\
    \ match_1, match_2;\n  vc<int> val_1, val_2;\n\n  Stable_Matching(int N1, int\
    \ N2) : N1(N1), N2(N2), dat(N1) {}\n\n  // x \u306F\u4FA1\u5024, \u5927\u304D\u3044\
    \u65B9\u304C\u512A\u5148\u3055\u308C\u308B\n  void add(int v1, int v2, int x1,\
    \ int x2) { dat[v1].eb(v2, x1, x2); }\n\n  vc<pair<int, int>> calc() {\n    FOR(v1,\
    \ N1) {\n      sort(all(dat[v1]),\n           [&](auto& a, auto& b) -> bool {\
    \ return get<1>(a) < get<1>(b); });\n    }\n    match_1.assign(N1, -1), match_2.assign(N2,\
    \ -1);\n    val_1.assign(N1, -infty<int>), val_2.assign(N2, -infty<int>);\n  \
    \  vc<int> que(N1);\n    FOR(v, N1) que[v] = v;\n    while (len(que)) {\n    \
    \  auto v1 = POP(que);\n      match_1[v1] = -1, val_1[v1] = -infty<int>;\n   \
    \   if (dat[v1].empty()) continue;\n      auto [v2, x1, x2] = POP(dat[v1]);\n\
    \      if (!chmax(val_2[v2], x2)) {\n        que.eb(v1);\n        continue;\n\
    \      }\n      if (match_2[v2] != -1) que.eb(match_2[v2]);\n      match_1[v1]\
    \ = v2, match_2[v2] = v1, val_1[v1] = x1, val_2[v2] = x2;\n    }\n    vc<pair<int,\
    \ int>> match;\n    FOR(v1, N1) {\n      int v2 = match_1[v1];\n      if (v2 !=\
    \ -1) match.eb(v1, v2);\n    }\n    return match;\n  }\n};\n"
  code: "\n// \u30B0\u30EB\u30FC\u30D7 1 \u306B\u3068\u3063\u3066\u6700\u9069\u306A\
    \ stable matching \u304C\u5B58\u5728\u3059\u308B\u306E\u3067\u305D\u308C\u3092\
    \u304B\u3048\u3059.\n// O((N+M)logM)\nstruct Stable_Matching {\n  int N1, N2;\n\
    \  vvc<tuple<int, int, int>> dat;\n  vc<int> match_1, match_2;\n  vc<int> val_1,\
    \ val_2;\n\n  Stable_Matching(int N1, int N2) : N1(N1), N2(N2), dat(N1) {}\n\n\
    \  // x \u306F\u4FA1\u5024, \u5927\u304D\u3044\u65B9\u304C\u512A\u5148\u3055\u308C\
    \u308B\n  void add(int v1, int v2, int x1, int x2) { dat[v1].eb(v2, x1, x2); }\n\
    \n  vc<pair<int, int>> calc() {\n    FOR(v1, N1) {\n      sort(all(dat[v1]),\n\
    \           [&](auto& a, auto& b) -> bool { return get<1>(a) < get<1>(b); });\n\
    \    }\n    match_1.assign(N1, -1), match_2.assign(N2, -1);\n    val_1.assign(N1,\
    \ -infty<int>), val_2.assign(N2, -infty<int>);\n    vc<int> que(N1);\n    FOR(v,\
    \ N1) que[v] = v;\n    while (len(que)) {\n      auto v1 = POP(que);\n      match_1[v1]\
    \ = -1, val_1[v1] = -infty<int>;\n      if (dat[v1].empty()) continue;\n     \
    \ auto [v2, x1, x2] = POP(dat[v1]);\n      if (!chmax(val_2[v2], x2)) {\n    \
    \    que.eb(v1);\n        continue;\n      }\n      if (match_2[v2] != -1) que.eb(match_2[v2]);\n\
    \      match_1[v1] = v2, match_2[v2] = v1, val_1[v1] = x1, val_2[v2] = x2;\n \
    \   }\n    vc<pair<int, int>> match;\n    FOR(v1, N1) {\n      int v2 = match_1[v1];\n\
    \      if (v2 != -1) match.eb(v1, v2);\n    }\n    return match;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/stable_matching.hpp
  requiredBy: []
  timestamp: '2023-11-30 16:32:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2288.test.cpp
documentation_of: graph/stable_matching.hpp
layout: document
redirect_from:
- /library/graph/stable_matching.hpp
- /library/graph/stable_matching.hpp.html
title: graph/stable_matching.hpp
---
