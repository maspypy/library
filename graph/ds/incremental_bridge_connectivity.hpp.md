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
  bundledCode: "#line 1 \"graph/ds/incremental_bridge_connectivity.hpp\"\n\n// O((N\
    \ + Q) log N)\nstruct Incremental_Bridge_Connectivity {\n  int n;\n  UnionFind\
    \ uf, uf_bridge;\n\n  Incremental_Bridge_Connectivity(int n)\n      : n(n), uf(n),\
    \ uf_bridge(n), par(n, -1), vis(n, -1), time(0) {}\n\n  void add_edge(int a, int\
    \ b) {\n    a = uf_bridge[a], b = uf_bridge[b];\n    if (a == b) return;\n   \
    \ if (uf[a] != uf[b]) {\n      // bridge\n      if (uf.size(a) < uf.size(b)) swap(a,\
    \ b);\n      make_root(b);\n      par[b] = a;\n      uf.merge(a, b);\n      return;\n\
    \    }\n\n    // cycle. some 2ecc are merged.\n    P.clear(), Q.clear();\n   \
    \ int t = time++;\n    int p = a, q = b;\n    int lca = [&]() -> int {\n     \
    \ while (1) {\n        if (p != -1) {\n          if (vis[p] == t) return p;\n\
    \          P.eb(p), vis[p] = t, p = par[p];\n          if (p != -1) p = uf_bridge[p];\n\
    \        }\n        if (q != -1) {\n          if (vis[q] == t) return q;\n   \
    \       Q.eb(q), vis[q] = t, q = par[q];\n          if (q != -1) q = uf_bridge[q];\n\
    \        }\n      }\n      assert(0);\n      return -1;\n    }();\n    // merge\
    \ path\n    for (int i : P) {\n      uf_bridge.merge(i, a);\n      if (i == lca)\
    \ break;\n    }\n    for (int i : Q) {\n      uf_bridge.merge(i, a);\n      if\
    \ (i == lca) break;\n    }\n    int r = uf_bridge[a];\n    par[r] = par[lca];\n\
    \  }\n\n  int count_bridges() const { return uf_bridge.n_comp - uf.n_comp; }\n\
    \n private:\n  // 2 edge component \u304B\u3089\u306A\u308B\u68EE\u3092\u7BA1\u7406\
    \n  // uf_bridge \u306E\u4EE3\u8868\u5143\u306E\u89AA\u3092\u6B63\u3057\u304F\u4FDD\
    \u6301\u3059\u308B\n  // \u305F\u3060\u3057\u884C\u5148\u306F\u68EE\u306E\u4E2D\
    \u306E 1 \u70B9\u306A\u306E\u3067\u3001uf_bridge \u306B\u5165\u308C\u308B\u3068\
    \u6B63\u3057\u304F\u306A\u308B\n  vc<int> par;\n  void make_root(int v) {\n  \
    \  assert(uf_bridge[v] == v);\n    int ch = -1;\n    while (v != -1) {\n     \
    \ int p = par[v];\n      if (p != -1) p = uf_bridge[p];\n      par[v] = ch;\n\
    \      ch = v;\n      v = p;\n    }\n  }\n\n  // lca \u8A08\u7B97\u7528\n  vc<int>\
    \ vis;\n  vc<int> P, Q;\n  int time;\n};\n"
  code: "\n// O((N + Q) log N)\nstruct Incremental_Bridge_Connectivity {\n  int n;\n\
    \  UnionFind uf, uf_bridge;\n\n  Incremental_Bridge_Connectivity(int n)\n    \
    \  : n(n), uf(n), uf_bridge(n), par(n, -1), vis(n, -1), time(0) {}\n\n  void add_edge(int\
    \ a, int b) {\n    a = uf_bridge[a], b = uf_bridge[b];\n    if (a == b) return;\n\
    \    if (uf[a] != uf[b]) {\n      // bridge\n      if (uf.size(a) < uf.size(b))\
    \ swap(a, b);\n      make_root(b);\n      par[b] = a;\n      uf.merge(a, b);\n\
    \      return;\n    }\n\n    // cycle. some 2ecc are merged.\n    P.clear(), Q.clear();\n\
    \    int t = time++;\n    int p = a, q = b;\n    int lca = [&]() -> int {\n  \
    \    while (1) {\n        if (p != -1) {\n          if (vis[p] == t) return p;\n\
    \          P.eb(p), vis[p] = t, p = par[p];\n          if (p != -1) p = uf_bridge[p];\n\
    \        }\n        if (q != -1) {\n          if (vis[q] == t) return q;\n   \
    \       Q.eb(q), vis[q] = t, q = par[q];\n          if (q != -1) q = uf_bridge[q];\n\
    \        }\n      }\n      assert(0);\n      return -1;\n    }();\n    // merge\
    \ path\n    for (int i : P) {\n      uf_bridge.merge(i, a);\n      if (i == lca)\
    \ break;\n    }\n    for (int i : Q) {\n      uf_bridge.merge(i, a);\n      if\
    \ (i == lca) break;\n    }\n    int r = uf_bridge[a];\n    par[r] = par[lca];\n\
    \  }\n\n  int count_bridges() const { return uf_bridge.n_comp - uf.n_comp; }\n\
    \n private:\n  // 2 edge component \u304B\u3089\u306A\u308B\u68EE\u3092\u7BA1\u7406\
    \n  // uf_bridge \u306E\u4EE3\u8868\u5143\u306E\u89AA\u3092\u6B63\u3057\u304F\u4FDD\
    \u6301\u3059\u308B\n  // \u305F\u3060\u3057\u884C\u5148\u306F\u68EE\u306E\u4E2D\
    \u306E 1 \u70B9\u306A\u306E\u3067\u3001uf_bridge \u306B\u5165\u308C\u308B\u3068\
    \u6B63\u3057\u304F\u306A\u308B\n  vc<int> par;\n  void make_root(int v) {\n  \
    \  assert(uf_bridge[v] == v);\n    int ch = -1;\n    while (v != -1) {\n     \
    \ int p = par[v];\n      if (p != -1) p = uf_bridge[p];\n      par[v] = ch;\n\
    \      ch = v;\n      v = p;\n    }\n  }\n\n  // lca \u8A08\u7B97\u7528\n  vc<int>\
    \ vis;\n  vc<int> P, Q;\n  int time;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/incremental_bridge_connectivity.hpp
  requiredBy: []
  timestamp: '2026-05-07 01:20:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/incremental_bridge_connectivity.hpp
layout: document
redirect_from:
- /library/graph/ds/incremental_bridge_connectivity.hpp
- /library/graph/ds/incremental_bridge_connectivity.hpp.html
title: graph/ds/incremental_bridge_connectivity.hpp
---
