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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/tree.hpp\"\r\n#include \"ds/unionfind/unionfind.hpp\"\r\n\
    \r\n// N \u304C\u6839\u3068\u306A\u308B\u6728\u3092\u65B0\u305F\u306B\u4F5C\u308B\
    \r\ntemplate <typename T = int>\r\nstruct FunctionalGraph {\r\n  int N, M;\r\n\
    \  vc<int> TO;\r\n  vc<T> wt;\r\n  vc<int> root;\r\n  Graph<T, 1> G;\r\n\r\n \
    \ FunctionalGraph() {}\r\n  FunctionalGraph(int N) : N(N), M(0), TO(N, -1), wt(N),\
    \ root(N, -1) {}\r\n\r\n  void add(int a, int b, T c = 1) {\r\n    assert(0 <=\
    \ a && a < N);\r\n    assert(TO[a] == -1);\r\n    ++M;\r\n    TO[a] = b;\r\n \
    \   wt[a] = c;\r\n  }\r\n\r\n  TREE<Graph<T, 1>> build() {\r\n    assert(N ==\
    \ M);\r\n    UnionFind uf(N);\r\n    FOR(v, N) if (!uf.merge(v, TO[v])) { root[v]\
    \ = v; }\r\n    FOR(v, N) if (root[v] == v) root[uf[v]] = v;\r\n    FOR(v, N)\
    \ root[v] = root[uf[v]];\r\n\r\n    G.resize(N + 1);\r\n    FOR(v, N) {\r\n  \
    \    if (root[v] == v)\r\n        G.add(N, v, wt[v]);\r\n      else\r\n      \
    \  G.add(TO[v], v, wt[v]);\r\n    }\r\n    G.build();\r\n    TREE<Graph<T, 1>>\
    \ tree(G, N);\r\n    return tree;\r\n  }\r\n\r\n  // functional graph \u306B\u5411\
    \u304B\u3063\u3066\u9032\u3080\r\n  template <typename TREE>\r\n  int jump(TREE&\
    \ tree, int v, ll step) {\r\n    int d = tree.depth[v];\r\n    if (step <= d -\
    \ 1) return tree.jump(v, N, step);\r\n    v = root[v];\r\n    step -= d - 1;\r\
    \n    int bottom = TO[v];\r\n    int c = tree.depth[bottom];\r\n    step %= c;\r\
    \n    if (step == 0) return v;\r\n    return tree.jump(bottom, N, step - 1);\r\
    \n  }\r\n\r\n  // functional graph \u306B step \u56DE\u9032\u3080\r\n  template\
    \ <typename TREE>\r\n  vc<int> jump_all(TREE& tree, ll step) {\r\n    auto& G\
    \ = tree.G;\r\n    vc<int> res(N, -1);\r\n    // v \u306E k \u500B\u5148\u3092\
    \ res[w] \u306B\u5165\u308C\u308B\r\n    vvc<pair<int, int>> query(N);\r\n   \
    \ FOR(v, N) {\r\n      int d = tree.depth[v];\r\n      int r = root[v];\r\n  \
    \    if (d - 1 > step) { query[v].eb(v, step); }\r\n      if (d - 1 <= step) {\r\
    \n        ll k = step - (d - 1);\r\n        int bottom = TO[r];\r\n        int\
    \ c = tree.depth[bottom];\r\n        k %= c;\r\n        if (k == 0) {\r\n    \
    \      res[v] = r;\r\n          continue;\r\n        }\r\n        query[bottom].eb(v,\
    \ k - 1);\r\n      }\r\n    }\r\n\r\n    vc<int> path;\r\n    auto dfs = [&](auto&\
    \ dfs, int v) -> void {\r\n      path.eb(v);\r\n      for (auto&& [w, k]: query[v])\
    \ { res[w] = path[len(path) - 1 - k]; }\r\n      for (auto&& e: G[v]) dfs(dfs,\
    \ e.to);\r\n      path.pop_back();\r\n    };\r\n    for (auto&& e: G[N]) { dfs(dfs,\
    \ e.to); }\r\n    return res;\r\n  }\r\n\r\n  template <typename TREE>\r\n  bool\
    \ in_cycle(TREE& tree, int v) {\r\n    int r = root[v];\r\n    int bottom = TO[r];\r\
    \n    return tree.in_subtree(bottom, v);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/functional.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/functional.hpp
layout: document
redirect_from:
- /library/graph/functional.hpp
- /library/graph/functional.hpp.html
title: graph/functional.hpp
---
