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
    - https://qoj.ac/contest/1699/problem/8518
  bundledCode: "#line 1 \"graph/tree_dp/rerooting_dp_2.hpp\"\n\n// \u4E2D\u9593\u8A08\
    \u7B97\u7D50\u679C\u3092\u5168\u90E8\u30E1\u30E2\u30EA\u306B\u6301\u3063\u3066\
    , \u53EF\u80FD\u306A\u9650\u308A\u540C\u3058\u8A08\u7B97\u3092\u8907\u6570\u56DE\
    \u3057\u306A\u3044\u3088\u3046\u306B\u3059\u308B\n// \u30E1\u30E2\u30EA\u306F\u5897\
    \u3048\u308B\u304C\u4E00\u5EA6\u306E\u8A08\u7B97\u304C\u91CD\u3044\u5834\u5408\
    \u306B\u306F\u6709\u52B9?????\n// \u6C38\u7D9A\u30C7\u30FC\u30BF\u69CB\u9020\u306E\
    \u30DE\u30FC\u30B8\u306E\u3068\u304D\u306B\u5C11\u3057\u30E1\u30E2\u30EA\u304C\
    \u7BC0\u7D04\u3067\u304D\u305F\u304C\u308F\u305A\u304B\n// https://qoj.ac/contest/1699/problem/8518\n\
    template <typename TREE, typename Data>\nstruct Rerooting_dp_2 {\n  static_assert(!TREE::Graph_type::is_directed);\n\
    \  TREE &tree;\n  vc<Data> dp;   // full tree at v\n  vc<Data> dp_1; // \u8FBA\
    \ pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\u6728 v\n  vc<Data> dp_2; // \u8FBA\
    \ pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\u6728 p\n  vc<Data> dp_3; // rootless\
    \ pv\n  vc<Data> dp_4; // dp_3 \u306E\u5DE6\u9589\u533A\u9593\u3067\u306E\u7D2F\
    \u7A4D\n\n  template <typename F1, typename F2, typename F3>\n  Rerooting_dp_2(TREE\
    \ &tree, F1 f_ee, F2 f_ev, F3 f_ve, const Data unit) : tree(tree) {\n    build(f_ee,\
    \ f_ev, f_ve, unit);\n  }\n\n  // v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\
    \u306E full tree\n  Data operator[](int v) { return dp[v]; }\n\n  // root \u3092\
    \u6839\u3068\u3057\u305F\u3068\u304D\u306E\u90E8\u5206\u6728 v\n  Data get(int\
    \ v, int root) {\n    if (root == v) return dp[v];\n    if (!tree.in_subtree(root,\
    \ v)) { return dp_1[v]; }\n    int w = tree.jump(v, root, 1);\n    return dp_2[w];\n\
    \  }\n\n  template <typename F1, typename F2, typename F3>\n  void build(F1 f_ee,\
    \ F2 f_ev, F3 f_ve, const Data unit) {\n    using Edge = typename TREE::Graph_type::edge_type;\n\
    \    int N = tree.N;\n    // dp_1: subtree\n    // dp_3: v \u307E\u3067\u306E\u5DE6\
    \u9589\u533A\u9593\n    dp_1.assign(N, unit);\n    dp_3.assign(N, unit);\n   \
    \ dp_4.assign(N, unit);\n    FOR_R(i, N) {\n      int v = tree.V[i];\n      vc<Edge>\
    \ ch;\n      for (auto &e: tree.G[v])\n        if (e.to != tree.parent[v]) ch.eb(e);\n\
    \      int n = len(ch);\n      FOR(i, n) {\n        auto &e = ch[i];\n       \
    \ int c = e.to;\n        dp_3[c] = f_ve(dp_1[c], e);\n        dp_4[c] = (i ==\
    \ 0 ? dp_3[c] : f_ee(dp_4[ch[i - 1].to], dp_3[c]));\n      }\n      dp_1[v] =\
    \ (n == 0 ? f_ev(unit, v) : f_ev(dp_4[ch[n - 1].to], v));\n    }\n\n    // dp2[v]:\
    \ subtree of p, rooted at v\n    dp_2.assign(N, unit);\n    // dp[v]: fulltree,\
    \ rooted at v\n    dp.assign(N, unit);\n    FOR(i, N) {\n      int v = tree.V[i];\n\
    \      vc<Edge> ch;\n      Data x = unit;\n      for (auto &e: tree.G[v]) {\n\
    \        if (e.to != tree.parent[v]) ch.eb(e);\n        if (e.to == tree.parent[v])\
    \ x = f_ve(dp_2[v], e);\n      }\n      int n = len(ch);\n      FOR_R(i, n) {\n\
    \        Data lprod = (i > 0 ? dp_4[ch[i - 1].to] : unit);\n        dp_2[ch[i].to]\
    \ = f_ev(f_ee(lprod, x), v);\n        x = f_ee(x, dp_3[ch[i].to]);\n      }\n\
    \      dp[v] = f_ev(x, v);\n    }\n  }\n};\n"
  code: "\n// \u4E2D\u9593\u8A08\u7B97\u7D50\u679C\u3092\u5168\u90E8\u30E1\u30E2\u30EA\
    \u306B\u6301\u3063\u3066, \u53EF\u80FD\u306A\u9650\u308A\u540C\u3058\u8A08\u7B97\
    \u3092\u8907\u6570\u56DE\u3057\u306A\u3044\u3088\u3046\u306B\u3059\u308B\n// \u30E1\
    \u30E2\u30EA\u306F\u5897\u3048\u308B\u304C\u4E00\u5EA6\u306E\u8A08\u7B97\u304C\
    \u91CD\u3044\u5834\u5408\u306B\u306F\u6709\u52B9?????\n// \u6C38\u7D9A\u30C7\u30FC\
    \u30BF\u69CB\u9020\u306E\u30DE\u30FC\u30B8\u306E\u3068\u304D\u306B\u5C11\u3057\
    \u30E1\u30E2\u30EA\u304C\u7BC0\u7D04\u3067\u304D\u305F\u304C\u308F\u305A\u304B\
    \n// https://qoj.ac/contest/1699/problem/8518\ntemplate <typename TREE, typename\
    \ Data>\nstruct Rerooting_dp_2 {\n  static_assert(!TREE::Graph_type::is_directed);\n\
    \  TREE &tree;\n  vc<Data> dp;   // full tree at v\n  vc<Data> dp_1; // \u8FBA\
    \ pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\u6728 v\n  vc<Data> dp_2; // \u8FBA\
    \ pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\u6728 p\n  vc<Data> dp_3; // rootless\
    \ pv\n  vc<Data> dp_4; // dp_3 \u306E\u5DE6\u9589\u533A\u9593\u3067\u306E\u7D2F\
    \u7A4D\n\n  template <typename F1, typename F2, typename F3>\n  Rerooting_dp_2(TREE\
    \ &tree, F1 f_ee, F2 f_ev, F3 f_ve, const Data unit) : tree(tree) {\n    build(f_ee,\
    \ f_ev, f_ve, unit);\n  }\n\n  // v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\
    \u306E full tree\n  Data operator[](int v) { return dp[v]; }\n\n  // root \u3092\
    \u6839\u3068\u3057\u305F\u3068\u304D\u306E\u90E8\u5206\u6728 v\n  Data get(int\
    \ v, int root) {\n    if (root == v) return dp[v];\n    if (!tree.in_subtree(root,\
    \ v)) { return dp_1[v]; }\n    int w = tree.jump(v, root, 1);\n    return dp_2[w];\n\
    \  }\n\n  template <typename F1, typename F2, typename F3>\n  void build(F1 f_ee,\
    \ F2 f_ev, F3 f_ve, const Data unit) {\n    using Edge = typename TREE::Graph_type::edge_type;\n\
    \    int N = tree.N;\n    // dp_1: subtree\n    // dp_3: v \u307E\u3067\u306E\u5DE6\
    \u9589\u533A\u9593\n    dp_1.assign(N, unit);\n    dp_3.assign(N, unit);\n   \
    \ dp_4.assign(N, unit);\n    FOR_R(i, N) {\n      int v = tree.V[i];\n      vc<Edge>\
    \ ch;\n      for (auto &e: tree.G[v])\n        if (e.to != tree.parent[v]) ch.eb(e);\n\
    \      int n = len(ch);\n      FOR(i, n) {\n        auto &e = ch[i];\n       \
    \ int c = e.to;\n        dp_3[c] = f_ve(dp_1[c], e);\n        dp_4[c] = (i ==\
    \ 0 ? dp_3[c] : f_ee(dp_4[ch[i - 1].to], dp_3[c]));\n      }\n      dp_1[v] =\
    \ (n == 0 ? f_ev(unit, v) : f_ev(dp_4[ch[n - 1].to], v));\n    }\n\n    // dp2[v]:\
    \ subtree of p, rooted at v\n    dp_2.assign(N, unit);\n    // dp[v]: fulltree,\
    \ rooted at v\n    dp.assign(N, unit);\n    FOR(i, N) {\n      int v = tree.V[i];\n\
    \      vc<Edge> ch;\n      Data x = unit;\n      for (auto &e: tree.G[v]) {\n\
    \        if (e.to != tree.parent[v]) ch.eb(e);\n        if (e.to == tree.parent[v])\
    \ x = f_ve(dp_2[v], e);\n      }\n      int n = len(ch);\n      FOR_R(i, n) {\n\
    \        Data lprod = (i > 0 ? dp_4[ch[i - 1].to] : unit);\n        dp_2[ch[i].to]\
    \ = f_ev(f_ee(lprod, x), v);\n        x = f_ee(x, dp_3[ch[i].to]);\n      }\n\
    \      dp[v] = f_ev(x, v);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_dp/rerooting_dp_2.hpp
  requiredBy: []
  timestamp: '2024-11-13 18:05:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_dp/rerooting_dp_2.hpp
layout: document
redirect_from:
- /library/graph/tree_dp/rerooting_dp_2.hpp
- /library/graph/tree_dp/rerooting_dp_2.hpp.html
title: graph/tree_dp/rerooting_dp_2.hpp
---
