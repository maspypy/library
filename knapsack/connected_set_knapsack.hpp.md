---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/connected_set_knapsack.test.cpp
    title: test/1_mytest/connected_set_knapsack.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://arxiv.org/pdf/1807.04942
  bundledCode: "#line 1 \"knapsack/connected_set_knapsack.hpp\"\n\n// https://arxiv.org/pdf/1807.04942\n\
    // Example 5.\n// O(LIM n log n)\ntemplate <typename TREE, typename VAL>\nvc<VAL>\
    \ connected_set_knapsack(TREE& tree, vc<int> weight, vc<VAL> val,\n          \
    \                     int LIM) {\n  // \u3059\u3079\u3066\u306E rooted subtree\
    \ \u3067 ancestor_closed \u3092\u89E3\u304F\u611F\u3058\u306E\u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0\n  using V = vc<VAL>;\n\n  V ANS(LIM + 1, -infty<VAL>);\n\n\
    \  auto dfs = [&](auto& dfs, int v, const V& X, bool upd_ans) -> V {\n    assert(len(X)\
    \ == LIM + 1);\n    int heavy = tree.heavy_child(v);\n    V Y(LIM + 1, -infty<VAL>);\n\
    \    if (heavy == -1) {\n      FOR(i, LIM + 1) { chmax(Y[i], X[i]); }\n      FOR(i,\
    \ LIM - weight[v] + 1) chmax(Y[i + weight[v]], X[i] + val[v]);\n      if (upd_ans)\
    \ {\n        FOR(i, LIM - weight[v] + 1) chmax(ANS[i + weight[v]], X[i] + val[v]);\n\
    \      }\n      return Y;\n    }\n    auto Z = dfs(dfs, heavy, X, upd_ans);\n\
    \    auto ch = tree.collect_light(v);\n\n    // not take v.\n    FOR(i, LIM +\
    \ 1) chmax(Y[i], X[i]);\n\n    // take v.\n    V cur = move(Z);\n    for (int\
    \ w : ch) {\n      cur = dfs(dfs, w, cur, false);\n    }\n    FOR(i, LIM - weight[v]\
    \ + 1) chmax(Y[i + weight[v]], cur[i] + val[v]);\n    if (upd_ans) {\n      FOR(i,\
    \ LIM - weight[v] + 1) chmax(ANS[i + weight[v]], cur[i] + val[v]);\n    }\n  \
    \  return Y;\n  };\n\n  FOR(v, tree.N) {\n    if (tree.head[v] == v) {\n     \
    \ V X(LIM + 1, -infty<VAL>);\n      X[0] = 0;\n      dfs(dfs, v, X, true);\n \
    \   }\n  }\n\n  for (auto& x : ANS)\n    if (x < 0) x = -infty<VAL>;\n  return\
    \ ANS;\n}\n"
  code: "\n// https://arxiv.org/pdf/1807.04942\n// Example 5.\n// O(LIM n log n)\n\
    template <typename TREE, typename VAL>\nvc<VAL> connected_set_knapsack(TREE& tree,\
    \ vc<int> weight, vc<VAL> val,\n                               int LIM) {\n  //\
    \ \u3059\u3079\u3066\u306E rooted subtree \u3067 ancestor_closed \u3092\u89E3\u304F\
    \u611F\u3058\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n  using V = vc<VAL>;\n\
    \n  V ANS(LIM + 1, -infty<VAL>);\n\n  auto dfs = [&](auto& dfs, int v, const V&\
    \ X, bool upd_ans) -> V {\n    assert(len(X) == LIM + 1);\n    int heavy = tree.heavy_child(v);\n\
    \    V Y(LIM + 1, -infty<VAL>);\n    if (heavy == -1) {\n      FOR(i, LIM + 1)\
    \ { chmax(Y[i], X[i]); }\n      FOR(i, LIM - weight[v] + 1) chmax(Y[i + weight[v]],\
    \ X[i] + val[v]);\n      if (upd_ans) {\n        FOR(i, LIM - weight[v] + 1) chmax(ANS[i\
    \ + weight[v]], X[i] + val[v]);\n      }\n      return Y;\n    }\n    auto Z =\
    \ dfs(dfs, heavy, X, upd_ans);\n    auto ch = tree.collect_light(v);\n\n    //\
    \ not take v.\n    FOR(i, LIM + 1) chmax(Y[i], X[i]);\n\n    // take v.\n    V\
    \ cur = move(Z);\n    for (int w : ch) {\n      cur = dfs(dfs, w, cur, false);\n\
    \    }\n    FOR(i, LIM - weight[v] + 1) chmax(Y[i + weight[v]], cur[i] + val[v]);\n\
    \    if (upd_ans) {\n      FOR(i, LIM - weight[v] + 1) chmax(ANS[i + weight[v]],\
    \ cur[i] + val[v]);\n    }\n    return Y;\n  };\n\n  FOR(v, tree.N) {\n    if\
    \ (tree.head[v] == v) {\n      V X(LIM + 1, -infty<VAL>);\n      X[0] = 0;\n \
    \     dfs(dfs, v, X, true);\n    }\n  }\n\n  for (auto& x : ANS)\n    if (x <\
    \ 0) x = -infty<VAL>;\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: knapsack/connected_set_knapsack.hpp
  requiredBy: []
  timestamp: '2026-05-06 04:02:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/connected_set_knapsack.test.cpp
documentation_of: knapsack/connected_set_knapsack.hpp
layout: document
redirect_from:
- /library/knapsack/connected_set_knapsack.hpp
- /library/knapsack/connected_set_knapsack.hpp.html
title: knapsack/connected_set_knapsack.hpp
---
