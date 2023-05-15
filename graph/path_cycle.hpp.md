---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/count_independent_set.hpp
    title: graph/count/count_independent_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_indep_set.test.cpp
    title: test/mytest/count_indep_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/path_cycle.hpp\"\n// \u3069\u306E\u70B9\u306E\u6B21\
    \u6570\u3082 2 \u4EE5\u4E0B\u306E\u30B0\u30E9\u30D5\u304C\u3042\u308B\u3068\u304D\
    \u306B\u3001\n// \u30D1\u30B9\u306E\u9802\u70B9\u5217, \u30B5\u30A4\u30AF\u30EB\
    \u306E\u9802\u70B9\u5217\n// \u306B\u5206\u89E3\u3059\u308B\ntemplate <typename\
    \ Graph>\npair<vvc<int>, vvc<int>> path_cycle(Graph& G) {\n  int N = G.N;\n  auto\
    \ deg = G.deg_array();\n  assert(MAX(deg) <= 2);\n  assert(!G.is_directed());\n\
    \n  vc<bool> done(N);\n  auto calc_frm = [&](int v) -> vc<int> {\n    vc<int>\
    \ P = {v};\n    done[v] = 1;\n    while (1) {\n      bool ok = 0;\n      for (auto&&\
    \ e: G[P.back()]) {\n        if (done[e.to]) continue;\n        P.eb(e.to);\n\
    \        done[e.to] = 1;\n        ok = 1;\n      }\n      if (!ok) break;\n  \
    \  }\n    return P;\n  };\n  vvc<int> paths, cycs;\n  FOR(v, N) {\n    if (deg[v]\
    \ == 0) {\n      done[v] = 1;\n      paths.eb(vc<int>({int(v)}));\n    }\n   \
    \ if (done[v] || deg[v] != 1) continue;\n    paths.eb(calc_frm(v));\n  }\n  FOR(v,\
    \ N) {\n    if (done[v]) continue;\n    cycs.eb(calc_frm(v));\n  }\n  return {paths,\
    \ cycs};\n}\n"
  code: "// \u3069\u306E\u70B9\u306E\u6B21\u6570\u3082 2 \u4EE5\u4E0B\u306E\u30B0\u30E9\
    \u30D5\u304C\u3042\u308B\u3068\u304D\u306B\u3001\n// \u30D1\u30B9\u306E\u9802\u70B9\
    \u5217, \u30B5\u30A4\u30AF\u30EB\u306E\u9802\u70B9\u5217\n// \u306B\u5206\u89E3\
    \u3059\u308B\ntemplate <typename Graph>\npair<vvc<int>, vvc<int>> path_cycle(Graph&\
    \ G) {\n  int N = G.N;\n  auto deg = G.deg_array();\n  assert(MAX(deg) <= 2);\n\
    \  assert(!G.is_directed());\n\n  vc<bool> done(N);\n  auto calc_frm = [&](int\
    \ v) -> vc<int> {\n    vc<int> P = {v};\n    done[v] = 1;\n    while (1) {\n \
    \     bool ok = 0;\n      for (auto&& e: G[P.back()]) {\n        if (done[e.to])\
    \ continue;\n        P.eb(e.to);\n        done[e.to] = 1;\n        ok = 1;\n \
    \     }\n      if (!ok) break;\n    }\n    return P;\n  };\n  vvc<int> paths,\
    \ cycs;\n  FOR(v, N) {\n    if (deg[v] == 0) {\n      done[v] = 1;\n      paths.eb(vc<int>({int(v)}));\n\
    \    }\n    if (done[v] || deg[v] != 1) continue;\n    paths.eb(calc_frm(v));\n\
    \  }\n  FOR(v, N) {\n    if (done[v]) continue;\n    cycs.eb(calc_frm(v));\n \
    \ }\n  return {paths, cycs};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/path_cycle.hpp
  requiredBy:
  - graph/count/count_independent_set.hpp
  timestamp: '2023-01-16 02:07:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/count_indep_set.test.cpp
documentation_of: graph/path_cycle.hpp
layout: document
redirect_from:
- /library/graph/path_cycle.hpp
- /library/graph/path_cycle.hpp.html
title: graph/path_cycle.hpp
---
