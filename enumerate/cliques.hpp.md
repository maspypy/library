---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/enumerate_cliques.test.cpp
    title: test/library_checker/graph/enumerate_cliques.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://www.slideshare.net/wata_orz/ss-12131479
  bundledCode: "#line 1 \"enumerate/cliques.hpp\"\n\n// N2^{sqrt(2m)}\n// https://www.slideshare.net/wata_orz/ss-12131479\n\
    template <typename Gr, typename F>\nvoid enumerate_cliques(Gr& G, F query) {\n\
    \  int N = G.N;\n  auto deg = G.deg_array();\n  vc<bool> done(N);\n  vv(int, can,\
    \ N, N);\n  for (auto&& e: G.edges) { can[e.frm][e.to] = can[e.to][e.frm] = 1;\
    \ }\n\n  FOR(N) {\n    // \u6B21\u6570\u6700\u5C0F\u306E\u9802\u70B9\u306E\u8FD1\
    \u508D\u3092\u8ABF\u3079\u308B\n    int v = -1;\n    int min_d = N;\n    FOR(i,\
    \ N) if (!done[i] && chmin(min_d, deg[i])) v = i;\n\n    vc<int> nbd;\n    for\
    \ (auto&& e: G[v])\n      if (!done[e.to]) nbd.eb(e.to);\n    vc<int> C = {v};\n\
    \n    auto dfs = [&](auto& dfs, int k) -> void {\n      query(C);\n      FOR(i,\
    \ k, len(nbd)) {\n        bool ok = 1;\n        for (auto&& x: C) {\n        \
    \  if (!can[x][nbd[i]]) {\n            ok = 0;\n            break;\n         \
    \ }\n        }\n        if (ok) {\n          C.eb(nbd[i]);\n          dfs(dfs,\
    \ i + 1);\n          C.pop_back();\n        }\n      }\n    };\n\n    dfs(dfs,\
    \ 0);\n    done[v] = 1;\n    for (auto&& x: nbd) deg[x]--;\n  }\n}\n"
  code: "\n// N2^{sqrt(2m)}\n// https://www.slideshare.net/wata_orz/ss-12131479\n\
    template <typename Gr, typename F>\nvoid enumerate_cliques(Gr& G, F query) {\n\
    \  int N = G.N;\n  auto deg = G.deg_array();\n  vc<bool> done(N);\n  vv(int, can,\
    \ N, N);\n  for (auto&& e: G.edges) { can[e.frm][e.to] = can[e.to][e.frm] = 1;\
    \ }\n\n  FOR(N) {\n    // \u6B21\u6570\u6700\u5C0F\u306E\u9802\u70B9\u306E\u8FD1\
    \u508D\u3092\u8ABF\u3079\u308B\n    int v = -1;\n    int min_d = N;\n    FOR(i,\
    \ N) if (!done[i] && chmin(min_d, deg[i])) v = i;\n\n    vc<int> nbd;\n    for\
    \ (auto&& e: G[v])\n      if (!done[e.to]) nbd.eb(e.to);\n    vc<int> C = {v};\n\
    \n    auto dfs = [&](auto& dfs, int k) -> void {\n      query(C);\n      FOR(i,\
    \ k, len(nbd)) {\n        bool ok = 1;\n        for (auto&& x: C) {\n        \
    \  if (!can[x][nbd[i]]) {\n            ok = 0;\n            break;\n         \
    \ }\n        }\n        if (ok) {\n          C.eb(nbd[i]);\n          dfs(dfs,\
    \ i + 1);\n          C.pop_back();\n        }\n      }\n    };\n\n    dfs(dfs,\
    \ 0);\n    done[v] = 1;\n    for (auto&& x: nbd) deg[x]--;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/cliques.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/enumerate_cliques.test.cpp
documentation_of: enumerate/cliques.hpp
layout: document
redirect_from:
- /library/enumerate/cliques.hpp
- /library/enumerate/cliques.hpp.html
title: enumerate/cliques.hpp
---
