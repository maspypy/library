---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2995.test.cpp
    title: test/aoj/2995.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree.hpp\"\n// HLD euler tour \u3092\u3068\u3063\u3066\
    \u3044\u308D\u3044\u308D\u3002\r\n// \u6728\u4EE5\u5916\u3001\u975E\u9023\u7D50\
    \u3067\u3082 dfs \u9806\u5E8F\u3084\u89AA\u304C\u3068\u308C\u308B\u3002\r\ntemplate\
    \ <typename GT>\r\nstruct Tree {\r\n  using Graph_type = GT;\r\n  GT *G_ptr;\r\
    \n  using WT = typename GT::cost_type;\r\n  int N;\r\n  vector<int> LID, RID,\
    \ head, V, parent, VtoE;\r\n  vc<int> depth;\r\n  vc<WT> depth_weighted;\r\n\r\
    \n  Tree() {}\r\n  Tree(GT &G, int r = 0, bool hld = 1) { build(G, r, hld); }\r\
    \n\r\n  void build(GT &G, int r = 0, bool hld = 1) {\r\n    G_ptr = &G;\r\n  \
    \  N = G.N;\r\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);\r\n\
    \    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\r\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void\
    \ dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\
    \n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l\
    \ = G_ptr->indptr[v], r = G_ptr->indptr[v + 1];\r\n    auto &csr = G_ptr->csr_edges;\r\
    \n    // \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\
    \r\n    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: (*G_ptr)[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\
    \n      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n   \
    \   dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: (*G_ptr)[a]) {\r\n        if (e.to != parent[a] && head[e.to]\
    \ == v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\
    \n      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ e_to_v(int eid) {\r\n    auto e = (*G_ptr).edges[eid];\r\n    return (parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\
    \n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v)\
    \ { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int\
    \ v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n      int u\
    \ = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\n    \
    \  k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\n \
    \ int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if (LID[u]\
    \ > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n    }\r\n\
    \  }\r\n\r\n  int lca(int u, int v) { return LCA(u, v); }\r\n  int la(int u, int\
    \ v) { return LA(u, v); }\r\n\r\n  int subtree_size(int v) { return RID[v] - LID[v];\
    \ }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return\
    \ depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  WT dist(int a, int b, bool\
    \ weighted) {\r\n    assert(weighted);\r\n    int c = LCA(a, b);\r\n    return\
    \ depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\r\n  }\r\n\
    \r\n  // a is in b\r\n  bool in_subtree(int a, int b) { return LID[b] <= LID[a]\
    \ && LID[a] < RID[b]; }\r\n\r\n  int jump(int a, int b, ll k) {\r\n    if (k ==\
    \ 1) {\r\n      if (a == b) return -1;\r\n      return (in_subtree(b, a) ? LA(b,\
    \ depth[b] - depth[a] - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a, b);\r\n\
    \    int d_ac = depth[a] - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\n\
    \    if (k > d_ac + d_bc) return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\n\
    \    return LA(b, d_ac + d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int\
    \ v) {\r\n    vc<int> res;\r\n    for (auto &&e: (*G_ptr)[v])\r\n      if (e.to\
    \ != parent[v]) res.eb(e.to);\r\n    return res;\r\n  }\r\n\r\n  vc<pair<int,\
    \ int>> get_path_decomposition(int u, int v, bool edge) {\r\n    // [\u59CB\u70B9\
    , \u7D42\u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>>\
    \ up, down;\r\n    while (1) {\r\n      if (head[u] == head[v]) break;\r\n   \
    \   if (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]], LID[v]);\r\n     \
    \   v = parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\
    \n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v])\
    \ down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u],\
    \ LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(), all(down));\r\
    \n    return up;\r\n  }\r\n\r\n  vc<int> restore_path(int u, int v) {\r\n    vc<int>\
    \ P;\r\n    for (auto &&[a, b]: get_path_decomposition(u, v, 0)) {\r\n      if\
    \ (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n      } else {\r\n   \
    \     FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\n    return P;\r\n\
    \  }\r\n};\r\n#line 2 \"graph/dsu_on_tree.hpp\"\n\n// add(v) : \u9802\u70B9 v\
    \ \u306E\u30C7\u30FC\u30BF\u3092\u8FFD\u52A0\u3059\u308B\n// query(v) : \u9802\
    \u70B9 v \u306B\u304A\u3051\u308B\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\n\
    // reset() : \u30C7\u30FC\u30BF\u304C\u7A7A\u306E\u72B6\u614B\u306B\u623B\u3059\
    \u3002\n// \u30C7\u30FC\u30BF\u69CB\u9020\u306B\u3088\u3063\u3066\u306F\u3001\u5C65\
    \u6B74\u3092\u4F7F\u3063\u3066\u9AD8\u901F\u306B reset \u3059\u308B\u3002\ntemplate\
    \ <typename TREE, typename F1, typename F2, typename F3>\nvoid DSU_on_Tree(TREE&\
    \ tree, F1& add, F2& query, F3& reset) {\n  auto& G = tree.G;\n\n  auto dfs =\
    \ [&](auto& dfs, int v) -> void {\n    int heavy = -1;\n    // solve light edge\n\
    \    for (auto&& e: G[v]) {\n      if (e.to == tree.parent[v]) continue;\n   \
    \   if (tree.head[e.to] == e.to) {\n        dfs(dfs, e.to);\n      } else {\n\
    \        heavy = e.to;\n      }\n    }\n    // solve heavy edge (keep subtree\
    \ data)\n    if (heavy != -1) { dfs(dfs, heavy); }\n\n    // collect data in light\
    \ subtree\n    for (auto&& e: G[v]) {\n      if (e.to == tree.parent[v]) continue;\n\
    \      if (e.to == heavy) continue;\n      FOR(idx, tree.LID[e.to], tree.RID[e.to])\
    \ { add(tree.V[idx]); }\n    }\n    add(v);\n    query(v);\n\n    if (tree.head[v]\
    \ == v) reset();\n  };\n\n  int root = tree.V[0];\n  dfs(dfs, root);\n}\n"
  code: "#include \"graph/tree.hpp\"\n\n// add(v) : \u9802\u70B9 v \u306E\u30C7\u30FC\
    \u30BF\u3092\u8FFD\u52A0\u3059\u308B\n// query(v) : \u9802\u70B9 v \u306B\u304A\
    \u3051\u308B\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\n// reset() : \u30C7\u30FC\
    \u30BF\u304C\u7A7A\u306E\u72B6\u614B\u306B\u623B\u3059\u3002\n// \u30C7\u30FC\u30BF\
    \u69CB\u9020\u306B\u3088\u3063\u3066\u306F\u3001\u5C65\u6B74\u3092\u4F7F\u3063\
    \u3066\u9AD8\u901F\u306B reset \u3059\u308B\u3002\ntemplate <typename TREE, typename\
    \ F1, typename F2, typename F3>\nvoid DSU_on_Tree(TREE& tree, F1& add, F2& query,\
    \ F3& reset) {\n  auto& G = tree.G;\n\n  auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n    int heavy = -1;\n    // solve light edge\n    for (auto&& e: G[v]) {\n\
    \      if (e.to == tree.parent[v]) continue;\n      if (tree.head[e.to] == e.to)\
    \ {\n        dfs(dfs, e.to);\n      } else {\n        heavy = e.to;\n      }\n\
    \    }\n    // solve heavy edge (keep subtree data)\n    if (heavy != -1) { dfs(dfs,\
    \ heavy); }\n\n    // collect data in light subtree\n    for (auto&& e: G[v])\
    \ {\n      if (e.to == tree.parent[v]) continue;\n      if (e.to == heavy) continue;\n\
    \      FOR(idx, tree.LID[e.to], tree.RID[e.to]) { add(tree.V[idx]); }\n    }\n\
    \    add(v);\n    query(v);\n\n    if (tree.head[v] == v) reset();\n  };\n\n \
    \ int root = tree.V[0];\n  dfs(dfs, root);\n}\n"
  dependsOn:
  - graph/tree.hpp
  isVerificationFile: false
  path: graph/dsu_on_tree.hpp
  requiredBy: []
  timestamp: '2023-04-09 03:51:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
  - test/aoj/2995.test.cpp
documentation_of: graph/dsu_on_tree.hpp
layout: document
redirect_from:
- /library/graph/dsu_on_tree.hpp
- /library/graph/dsu_on_tree.hpp.html
title: graph/dsu_on_tree.hpp
---
