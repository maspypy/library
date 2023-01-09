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
  bundledCode: "#line 1 \"graph/compress_tree.hpp\"\n// (\u5727\u7E2E\u3055\u308C\u305F\
    \u6728\u306E\u9802\u70B9\u30E9\u30D9\u30EB\u305F\u3061\u3001\u30B0\u30E9\u30D5\
    )\ntemplate <typename TREE>\npair<vc<int>, typename TREE::Graph_type> compress_tree(TREE&\
    \ tree, vc<int> V) {\n  // \u5927\u4E8B\u306A\u70B9\u3092\u30EA\u30B9\u30C8\u30A2\
    \u30C3\u30D7\u3059\u308B\n  // \u3082\u3068\u3082\u3068\u306E\u6839\u306F\u542B\
    \u307E\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  {\n    vc<int> VV = V;\n \
    \   sort(all(V), [&](auto& x, auto& y) { return tree.LID[x] < tree.LID[y]; });\n\
    \    FOR(i, len(V) - 1) { VV.eb(tree.lca(V[i], V[i + 1])); }\n    VV.eb(tree.lca(V[0],\
    \ V.back()));\n    VV.eb(tree.V[0]);\n    UNIQUE(VV);\n    V = VV;\n    sort(all(V),\
    \ [&](auto& x, auto& y) { return tree.LID[x] < tree.LID[y]; });\n  }\n  // \u8FBA\
    \u3092\u5F35\u3063\u3066\u30B0\u30E9\u30D5\u3092\u4F5C\u308B\n  int n = len(V);\n\
    \  using GT = typename TREE::Graph_type;\n  using WT = typename GT::cost_type;\n\
    \  GT G(n);\n  vc<int> st = {0};\n  FOR(i, 1, n) {\n    while (1) {\n      int\
    \ p = V[st.back()];\n      int v = V[i];\n      if (tree.in_subtree(v, p)) break;\n\
    \      st.pop_back();\n    }\n    int p = V[st.back()];\n    int v = V[i];\n \
    \   WT d = tree.depth_weighted[v] - tree.depth_weighted[p];\n    G.add(st.back(),\
    \ i, d);\n    st.eb(i);\n  }\n  G.build();\n  return {V, G};\n}\n"
  code: "// (\u5727\u7E2E\u3055\u308C\u305F\u6728\u306E\u9802\u70B9\u30E9\u30D9\u30EB\
    \u305F\u3061\u3001\u30B0\u30E9\u30D5)\ntemplate <typename TREE>\npair<vc<int>,\
    \ typename TREE::Graph_type> compress_tree(TREE& tree, vc<int> V) {\n  // \u5927\
    \u4E8B\u306A\u70B9\u3092\u30EA\u30B9\u30C8\u30A2\u30C3\u30D7\u3059\u308B\n  //\
    \ \u3082\u3068\u3082\u3068\u306E\u6839\u306F\u542B\u307E\u308C\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  {\n    vc<int> VV = V;\n    sort(all(V), [&](auto& x, auto&\
    \ y) { return tree.LID[x] < tree.LID[y]; });\n    FOR(i, len(V) - 1) { VV.eb(tree.lca(V[i],\
    \ V[i + 1])); }\n    VV.eb(tree.lca(V[0], V.back()));\n    VV.eb(tree.V[0]);\n\
    \    UNIQUE(VV);\n    V = VV;\n    sort(all(V), [&](auto& x, auto& y) { return\
    \ tree.LID[x] < tree.LID[y]; });\n  }\n  // \u8FBA\u3092\u5F35\u3063\u3066\u30B0\
    \u30E9\u30D5\u3092\u4F5C\u308B\n  int n = len(V);\n  using GT = typename TREE::Graph_type;\n\
    \  using WT = typename GT::cost_type;\n  GT G(n);\n  vc<int> st = {0};\n  FOR(i,\
    \ 1, n) {\n    while (1) {\n      int p = V[st.back()];\n      int v = V[i];\n\
    \      if (tree.in_subtree(v, p)) break;\n      st.pop_back();\n    }\n    int\
    \ p = V[st.back()];\n    int v = V[i];\n    WT d = tree.depth_weighted[v] - tree.depth_weighted[p];\n\
    \    G.add(st.back(), i, d);\n    st.eb(i);\n  }\n  G.build();\n  return {V, G};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/compress_tree.hpp
  requiredBy: []
  timestamp: '2023-01-09 23:28:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/compress_tree.hpp
layout: document
redirect_from:
- /library/graph/compress_tree.hpp
- /library/graph/compress_tree.hpp.html
title: graph/compress_tree.hpp
---
