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
  bundledCode: "#line 1 \"matroid/graphic_matroid.hpp\"\nstruct Graphic_Matroid {\n\
    \  Graph<int, 0> G;\n  vc<int> root, dep, par, que;\n\n  Graphic_Matroid(Graph<int,\
    \ 0> &G)\n      : G(G), root(G.N), dep(G.N), par(G.N), que(G.N) {}\n\n  int size()\
    \ { return G.M; }\n\n  const vc<bool> *I = nullptr;\n  void prepare(const vc<bool>\
    \ &_I) {\n    I = &_I;\n    int N = G.N, M = G.M;\n    assert(int(I->size()) ==\
    \ M);\n    root.assign(N, -1);\n    auto calc_frm = [&](int s) -> void {\n   \
    \   int ql = 0, qr = 0;\n      root[s] = s, dep[s] = 0, par[s] = -1;\n      que[qr++]\
    \ = s;\n      while (ql < qr) {\n        int v = que[ql++];\n        for (auto\
    \ &e : G[v]) {\n          if ((*I)[e.id] && root[e.to] == -1) {\n            root[e.to]\
    \ = s, dep[e.to] = dep[v] + 1, par[e.to] = e.id;\n            que[qr++] = e.to;\n\
    \          }\n        }\n      }\n    };\n    FOR(s, N) if (root[s] == -1) calc_frm(s);\n\
    \  }\n\n  bool can_add(int i) {\n    int a = G.edges[i].frm, b = G.edges[i].to;\n\
    \    return root[a] != root[b];\n  }\n\n  // i \u3092\u8FFD\u52A0\u3057\u3066\
    \ j \u3092\u524A\u9664\n  template <typename F>\n  void for_add_rm(int i, F &&f)\
    \ const {\n    assert(!(*I)[i]);\n    int a = G.edges[i].frm, b = G.edges[i].to;\n\
    \    if (root[a] != root[b]) {\n      FOR(j, G.M) {\n        if ((*I)[j]) f(j);\n\
    \      }\n      return;\n    }\n    if (dep[a] > dep[b]) swap(a, b);\n    while\
    \ (dep[a] < dep[b]) {\n      int j = par[b];\n      f(j), b = G.edges[j].frm ^\
    \ G.edges[j].to ^ b;\n    }\n    while (a != b) {\n      int j = par[a];\n   \
    \   f(j), a = G.edges[j].frm ^ G.edges[j].to ^ a;\n      j = par[b];\n      f(j),\
    \ b = G.edges[j].frm ^ G.edges[j].to ^ b;\n    }\n  }\n};\n"
  code: "struct Graphic_Matroid {\n  Graph<int, 0> G;\n  vc<int> root, dep, par, que;\n\
    \n  Graphic_Matroid(Graph<int, 0> &G)\n      : G(G), root(G.N), dep(G.N), par(G.N),\
    \ que(G.N) {}\n\n  int size() { return G.M; }\n\n  const vc<bool> *I = nullptr;\n\
    \  void prepare(const vc<bool> &_I) {\n    I = &_I;\n    int N = G.N, M = G.M;\n\
    \    assert(int(I->size()) == M);\n    root.assign(N, -1);\n    auto calc_frm\
    \ = [&](int s) -> void {\n      int ql = 0, qr = 0;\n      root[s] = s, dep[s]\
    \ = 0, par[s] = -1;\n      que[qr++] = s;\n      while (ql < qr) {\n        int\
    \ v = que[ql++];\n        for (auto &e : G[v]) {\n          if ((*I)[e.id] &&\
    \ root[e.to] == -1) {\n            root[e.to] = s, dep[e.to] = dep[v] + 1, par[e.to]\
    \ = e.id;\n            que[qr++] = e.to;\n          }\n        }\n      }\n  \
    \  };\n    FOR(s, N) if (root[s] == -1) calc_frm(s);\n  }\n\n  bool can_add(int\
    \ i) {\n    int a = G.edges[i].frm, b = G.edges[i].to;\n    return root[a] !=\
    \ root[b];\n  }\n\n  // i \u3092\u8FFD\u52A0\u3057\u3066 j \u3092\u524A\u9664\n\
    \  template <typename F>\n  void for_add_rm(int i, F &&f) const {\n    assert(!(*I)[i]);\n\
    \    int a = G.edges[i].frm, b = G.edges[i].to;\n    if (root[a] != root[b]) {\n\
    \      FOR(j, G.M) {\n        if ((*I)[j]) f(j);\n      }\n      return;\n   \
    \ }\n    if (dep[a] > dep[b]) swap(a, b);\n    while (dep[a] < dep[b]) {\n   \
    \   int j = par[b];\n      f(j), b = G.edges[j].frm ^ G.edges[j].to ^ b;\n   \
    \ }\n    while (a != b) {\n      int j = par[a];\n      f(j), a = G.edges[j].frm\
    \ ^ G.edges[j].to ^ a;\n      j = par[b];\n      f(j), b = G.edges[j].frm ^ G.edges[j].to\
    \ ^ b;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: matroid/graphic_matroid.hpp
  requiredBy: []
  timestamp: '2025-10-13 18:56:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matroid/graphic_matroid.hpp
layout: document
redirect_from:
- /library/matroid/graphic_matroid.hpp
- /library/matroid/graphic_matroid.hpp.html
title: matroid/graphic_matroid.hpp
---
