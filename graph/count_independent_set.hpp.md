---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/path_cycle.hpp
    title: graph/path_cycle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/path_cycle.hpp\"\n// \u3069\u306E\u70B9\u306E\u6B21\
    \u6570\u3082 2 \u4EE5\u4E0B\u306E\u30B0\u30E9\u30D5\u304C\u3042\u308B\u3068\u304D\
    \u306B\u3001\n// \u30D1\u30B9\u306E\u9802\u70B9\u5217, \u30B5\u30A4\u30AF\u30EB\
    \u306E\u9802\u70B9\u5217\n// \u306B\u5206\u89E3\u3059\u308B\ntemplate <typename\
    \ Graph>\npair<vvc<int>, vvc<int>> path_cycle(Graph& G) {\n  int N = G.N;\n  auto\
    \ deg = G.deg_array();\n  assert(MAX(deg) <= 2);\n\n  vc<bool> done(N);\n  auto\
    \ calc_frm = [&](int v) -> vc<int> {\n    vc<int> P = {v};\n    done[v] = 1;\n\
    \    while (1) {\n      bool ok = 0;\n      for (auto&& e: G[P.back()]) {\n  \
    \      if (done[e.to]) continue;\n        P.eb(e.to);\n        done[e.to] = 1;\n\
    \        ok = 1;\n      }\n      if (!ok) break;\n    }\n    return P;\n  };\n\
    \  vvc<int> paths, cycs;\n  FOR(v, N) {\n    if (deg[v] == 0) {\n      done[v]\
    \ = 1;\n      paths.eb(vc<int>({int(v)}));\n    }\n    if (done[v] || deg[v] !=\
    \ 1) continue;\n    paths.eb(calc_frm(v));\n  }\n  FOR(v, N) {\n    if (done[v])\
    \ continue;\n    cycs.eb(calc_frm(v));\n  }\n  return {paths, cycs};\n}\n#line\
    \ 2 \"graph/count_independent_set.hpp\"\n\n// \u72EC\u7ACB\u96C6\u5408\u6570\u3048\
    \u4E0A\u3052\u3002\u7A7A\u96C6\u5408\u3082\u8A8D\u3081\u308B\u3002N 1.381^N \u7A0B\
    \u5EA6\u3002\ntemplate <typename GT>\nu64 count_independent_set(GT& G) {\n  using\
    \ U = u64;\n  const int N = G.N;\n  assert(N < 64);\n  if (N == 0) return 1;\n\
    \  vc<U> nbd(N);\n  FOR(v, N) for (auto&& e: G[v]) nbd[v] |= U(1) << e.to;\n\n\
    \  vc<U> dp_path(N + 1), dp_cyc(N + 1);\n  dp_path[0] = 1, dp_path[1] = 2;\n \
    \ FOR(i, 2, N + 1) dp_path[i] = dp_path[i - 1] + dp_path[i - 2];\n  FOR(i, 3,\
    \ N + 1) dp_cyc[i] = dp_path[i - 1] + dp_path[i - 3];\n\n  auto dfs = [&](auto&\
    \ dfs, U s) -> U {\n    int deg0 = 0;\n    pair<int, int> p = {-1, -1}; // (v,\
    \ d)\n    FOR(v, N) if (s >> v & 1) {\n      int d = popcnt(nbd[v] & s);\n   \
    \   if (chmax(p.se, d)) p.fi = v;\n      if (d == 0) {\n        ++deg0;\n    \
    \    s &= ~(U(1) << v);\n      }\n    }\n    if (s == 0) return U(1) << deg0;\n\
    \    int v = p.fi;\n    if (p.se >= 3) {\n      s &= ~(U(1) << v);\n      return\
    \ (dfs(dfs, s) + dfs(dfs, s & ~nbd[v])) << deg0;\n    }\n    // d <= 2, path \u3068\
    \ cycle \u306E\u307F\n    vc<int> V;\n    FOR(v, N) if (s >> v & 1) V.eb(v);\n\
    \    int n = len(V);\n    Graph<bool, 0> G(n);\n    FOR(i, n) {\n      U x = nbd[V[i]]\
    \ & s;\n      while (x) {\n        int v = topbit(x);\n        x ^= U(1) << v;\n\
    \        int j = LB(V, v);\n        if (i < j) G.add(i, j);\n      }\n    }\n\
    \    G.build();\n    auto [paths, cycs] = path_cycle(G);\n    U res = 1;\n   \
    \ for (auto&& P: paths) res *= dp_path[len(P)];\n    for (auto&& C: cycs) res\
    \ *= dp_cyc[len(C)];\n    return res << deg0;\n  };\n  return dfs(dfs, (U(1) <<\
    \ N) - 1);\n}\n"
  code: "#include \"graph/path_cycle.hpp\"\n\n// \u72EC\u7ACB\u96C6\u5408\u6570\u3048\
    \u4E0A\u3052\u3002\u7A7A\u96C6\u5408\u3082\u8A8D\u3081\u308B\u3002N 1.381^N \u7A0B\
    \u5EA6\u3002\ntemplate <typename GT>\nu64 count_independent_set(GT& G) {\n  using\
    \ U = u64;\n  const int N = G.N;\n  assert(N < 64);\n  if (N == 0) return 1;\n\
    \  vc<U> nbd(N);\n  FOR(v, N) for (auto&& e: G[v]) nbd[v] |= U(1) << e.to;\n\n\
    \  vc<U> dp_path(N + 1), dp_cyc(N + 1);\n  dp_path[0] = 1, dp_path[1] = 2;\n \
    \ FOR(i, 2, N + 1) dp_path[i] = dp_path[i - 1] + dp_path[i - 2];\n  FOR(i, 3,\
    \ N + 1) dp_cyc[i] = dp_path[i - 1] + dp_path[i - 3];\n\n  auto dfs = [&](auto&\
    \ dfs, U s) -> U {\n    int deg0 = 0;\n    pair<int, int> p = {-1, -1}; // (v,\
    \ d)\n    FOR(v, N) if (s >> v & 1) {\n      int d = popcnt(nbd[v] & s);\n   \
    \   if (chmax(p.se, d)) p.fi = v;\n      if (d == 0) {\n        ++deg0;\n    \
    \    s &= ~(U(1) << v);\n      }\n    }\n    if (s == 0) return U(1) << deg0;\n\
    \    int v = p.fi;\n    if (p.se >= 3) {\n      s &= ~(U(1) << v);\n      return\
    \ (dfs(dfs, s) + dfs(dfs, s & ~nbd[v])) << deg0;\n    }\n    // d <= 2, path \u3068\
    \ cycle \u306E\u307F\n    vc<int> V;\n    FOR(v, N) if (s >> v & 1) V.eb(v);\n\
    \    int n = len(V);\n    Graph<bool, 0> G(n);\n    FOR(i, n) {\n      U x = nbd[V[i]]\
    \ & s;\n      while (x) {\n        int v = topbit(x);\n        x ^= U(1) << v;\n\
    \        int j = LB(V, v);\n        if (i < j) G.add(i, j);\n      }\n    }\n\
    \    G.build();\n    auto [paths, cycs] = path_cycle(G);\n    U res = 1;\n   \
    \ for (auto&& P: paths) res *= dp_path[len(P)];\n    for (auto&& C: cycs) res\
    \ *= dp_cyc[len(C)];\n    return res << deg0;\n  };\n  return dfs(dfs, (U(1) <<\
    \ N) - 1);\n}"
  dependsOn:
  - graph/path_cycle.hpp
  isVerificationFile: false
  path: graph/count_independent_set.hpp
  requiredBy: []
  timestamp: '2022-12-15 05:39:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count_independent_set.hpp
layout: document
redirect_from:
- /library/graph/count_independent_set.hpp
- /library/graph/count_independent_set.hpp.html
title: graph/count_independent_set.hpp
---
