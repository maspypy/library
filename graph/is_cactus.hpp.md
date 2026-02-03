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
  bundledCode: "#line 1 \"graph/is_cactus.hpp\"\n\n// EDGE = true: \u5404\u8FBA\u304C\
    \u552F\u4E00\u306E\u30B5\u30A4\u30AF\u30EB\uFF08\u95A2\u7BC0\u70B9\u3067\u30B5\
    \u30A4\u30AF\u30EB\u307E\u305F\u306F\u8FBA\uFF09\n// EDGE = false\uFF1A \u5404\
    \u9802\u70B9\u304C\u552F\u4E00\u306E\u30B5\u30A4\u30AF\u30EB\uFF08\u6A4B\u3067\
    \u30B5\u30A4\u30AF\u30EB\u307E\u305F\u306F\u8FBA\uFF09\ntemplate <bool EDGE>\n\
    bool is_cactus(Graph<int, 0> G) {\n  if constexpr (EDGE) {\n    static_assert(EDGE);\n\
    \    auto BCT = block_cut(G);\n    int N = G.N, n = BCT.N;\n    Tree<decltype(BCT)>\
    \ tree(BCT);\n    vc<int> NV(n), NE(n);\n    FOR(i, N, n) NV[i] = BCT.deg(i);\n\
    \    for (auto& e : G.edges) {\n      int a = e.frm, b = e.to;\n      int i =\
    \ tree.jump(a, b, 1);\n      NE[i]++;\n    }\n    FOR(i, N, n) {\n      int a\
    \ = NV[i], b = NE[i];\n      if (b == 1) continue;\n      if (a < b) return false;\n\
    \    }\n    return true;\n  } else {\n    auto [nc, comp] = two_edge_component(G);\n\
    \    vc<int> NV(nc), NE(nc);\n    FOR(v, G.N) NV[comp[v]]++;\n    for (auto& e\
    \ : G.edges) {\n      int a = e.frm, b = e.to;\n      a = comp[a], b = comp[b];\n\
    \      if (a == b) NE[a]++;\n    }\n    FOR(i, nc) {\n      if (NV[i] < NE[i])\
    \ return false;\n    }\n    return true;\n  }\n}\n"
  code: "\n// EDGE = true: \u5404\u8FBA\u304C\u552F\u4E00\u306E\u30B5\u30A4\u30AF\u30EB\
    \uFF08\u95A2\u7BC0\u70B9\u3067\u30B5\u30A4\u30AF\u30EB\u307E\u305F\u306F\u8FBA\
    \uFF09\n// EDGE = false\uFF1A \u5404\u9802\u70B9\u304C\u552F\u4E00\u306E\u30B5\
    \u30A4\u30AF\u30EB\uFF08\u6A4B\u3067\u30B5\u30A4\u30AF\u30EB\u307E\u305F\u306F\
    \u8FBA\uFF09\ntemplate <bool EDGE>\nbool is_cactus(Graph<int, 0> G) {\n  if constexpr\
    \ (EDGE) {\n    static_assert(EDGE);\n    auto BCT = block_cut(G);\n    int N\
    \ = G.N, n = BCT.N;\n    Tree<decltype(BCT)> tree(BCT);\n    vc<int> NV(n), NE(n);\n\
    \    FOR(i, N, n) NV[i] = BCT.deg(i);\n    for (auto& e : G.edges) {\n      int\
    \ a = e.frm, b = e.to;\n      int i = tree.jump(a, b, 1);\n      NE[i]++;\n  \
    \  }\n    FOR(i, N, n) {\n      int a = NV[i], b = NE[i];\n      if (b == 1) continue;\n\
    \      if (a < b) return false;\n    }\n    return true;\n  } else {\n    auto\
    \ [nc, comp] = two_edge_component(G);\n    vc<int> NV(nc), NE(nc);\n    FOR(v,\
    \ G.N) NV[comp[v]]++;\n    for (auto& e : G.edges) {\n      int a = e.frm, b =\
    \ e.to;\n      a = comp[a], b = comp[b];\n      if (a == b) NE[a]++;\n    }\n\
    \    FOR(i, nc) {\n      if (NV[i] < NE[i]) return false;\n    }\n    return true;\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/is_cactus.hpp
  requiredBy: []
  timestamp: '2026-02-03 22:59:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/is_cactus.hpp
layout: document
redirect_from:
- /library/graph/is_cactus.hpp
- /library/graph/is_cactus.hpp.html
title: graph/is_cactus.hpp
---
