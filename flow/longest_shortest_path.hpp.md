---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/contest/1435/problem/7737
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: flow/mincostflow.hpp:\
    \ line -1: no such header\n"
  code: "#include \"flow/mincostflow.hpp\"\n#include \"graph/shortest_path/dijkstra.hpp\"\
    \n\n/*\npotential p[v]\n\u8DDD\u96E2\u3092 L \u4EE5\u4E0A\u306B\u3057\u305F\u3044\
    \ : L<=p[t]-p[s]\n\u8FBA (u,v,w)\n\u4F38\u3070\u3059\u91CF max(0,p[v]-p[u]-w)\n\
    - t \u304B\u3089 s \u306B\u8CBB\u7528-L, \u5BB9\u91CFINF\n- u \u304B\u3089 v \u306B\
    \u8CBB\u7528 w, \u5BB9\u91CF 1\n\u3053\u308C\u306E\u5FAA\u74B0\u6D41\n*/\n\n//\
    \ https://qoj.ac/contest/1435/problem/7737\ntemplate <typename T = ll, bool DAG\
    \ = false>\nstruct Longest_Shortest_Path {\n  int N, s, t;\n  T F, L, K;\n  bool\
    \ solved;\n  vc<tuple<int, int, T, T>> dat;\n  vc<T> pot;\n  Longest_Shortest_Path(int\
    \ N, int s, int t) : N(N), s(s), t(t), F(0), solved(0) {}\n\n  // \u73FE\u5728\
    \u306E\u9577\u3055, \u9577\u3055\u3092+1\u3059\u308B\u30B3\u30B9\u30C8\n  void\
    \ add(int frm, int to, T length, T cost) {\n    assert(0 <= frm && frm < N &&\
    \ 0 <= to && to < N && !solved);\n    if (DAG) assert(frm < to);\n    dat.eb(frm,\
    \ to, length, cost);\n  }\n\n  T init_dist() {\n    Graph<T, 1> G(N);\n    for\
    \ (auto& [a, b, c, d]: dat) G.add(a, b, c);\n    G.build();\n    auto [dist, par]\
    \ = dijkstra<T>(G, s);\n    return dist[t];\n  }\n\n  // \u8DDD\u96E2\u304C L\
    \ \u4EE5\u4E0A\u306B\u306A\u308B\u3088\u3046\u306B\u305B\u3088. return: min cost.\n\
    \  T solve_by_target_length(T target_length) {\n    L = target_length;\n    assert(!solved\
    \ && L >= init_dist());\n    solved = 1;\n    Min_Cost_Flow<T, T, DAG> G(N, s,\
    \ t);\n    for (auto& [a, b, length, cost]: dat) { G.add(a, b, cost, length);\
    \ }\n    T ans = -infty<T>;\n    for (auto& [x, y]: G.slope()) {\n      if (chmax(ans,\
    \ x * L - y)) F = x;\n    }\n    return K = ans;\n  }\n\n  // \u30B3\u30B9\u30C8\
    \u304C K \u3067\u6700\u5927\u8DDD\u96E2\u306B\u305B\u3088. return: max dist.\n\
    \  T solve_by_cost(T K) {}\n\n  // frm, to, cost. add_edge \u9806.\n  vc<T> get_potentials()\
    \ {\n    assert(solved);\n    if (len(pot)) return pot;\n    Min_Cost_Flow<T,\
    \ T, DAG> G(N, s, t);\n    for (auto& [a, b, length, cost]: dat) { G.add(a, b,\
    \ cost, length); }\n    G.flow(F);\n    pot = G.get_potentials();\n    Graph<T,\
    \ 1> resG(N);\n    auto add = [&](int a, int b, T x) -> void {\n      x = x +\
    \ pot[a] - pot[b];\n      resG.add(a, b, x);\n    };\n    for (auto& e: G.edges())\
    \ {\n      if (e.cap > e.flow) add(e.frm, e.to, e.cost);\n      if (e.flow > 0)\
    \ add(e.to, e.frm, -e.cost);\n    }\n    add(s, t, L), add(t, s, -L);\n    resG.build();\n\
    \    vc<T> dist = dijkstra<ll>(resG, s).fi;\n    FOR(x, N) pot[x] += dist[x];\n\
    \    return pot;\n  }\n\n  // \u5909\u66F4\u5F8C\u306E\u9577\u3055\n  vc<T> get_edges()\
    \ {\n    get_potentials();\n    vc<T> res;\n    for (auto [frm, to, length, cost]:\
    \ dat) { res.eb(max<T>(length, pot[to] - pot[frm])); }\n    return res;\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/longest_shortest_path.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/longest_shortest_path.hpp
layout: document
redirect_from:
- /library/flow/longest_shortest_path.hpp
- /library/flow/longest_shortest_path.hpp.html
title: flow/longest_shortest_path.hpp
---
