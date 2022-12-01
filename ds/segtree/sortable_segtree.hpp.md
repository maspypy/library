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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/fastset.hpp\"\n#include \"ds/segtree.hpp\"\n\ntemplate <typename\
    \ Monoid, int NODES = 4'000'000>\nstruct Sortable_SegTree {\n  using X = typename\
    \ Monoid::value_type;\n  const int N, KEY_MAX;\n\n  struct Node {\n    X x, rev_x;\n\
    \    int size;\n    Node *l, *r;\n    Node() {}\n  };\n\n  Node* pool;\n  int\
    \ pid;\n\n  // \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\u3092\u8868\u3059 fastset\n\
    \  FastSet ss;\n  // \u533A\u9593\u3092\u96C6\u7D04\u3057\u305F\u5024\u3092\u533A\
    \u9593\u306E\u5DE6\u7AEF\u306B\u306E\u305B\u305F segtree\n  SegTree<Monoid> seg;\n\
    \  // \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001dynamic segtree \u306E node \u3092\
    \u4E57\u305B\u308B\n  vector<bool> rev;\n  vector<Node*> root;\n  Sortable_SegTree(int\
    \ KEY_MAX, vector<int> key, vector<X> dat)\n      : N(key.size()), KEY_MAX(KEY_MAX),\
    \ pid(0), ss(key.size()), seg(dat) {\n    pool = new Node[NODES];\n    init(key,\
    \ dat);\n  }\n\n  void set(int i, int key, const X& x) {\n    assert(key < KEY_MAX);\n\
    \    split_at(i);\n    split_at(i + 1);\n    rev[i] = 0;\n    root[i] = new_node();\n\
    \    set_rec_key(root[i], 0, KEY_MAX, key, x);\n    seg.set(i, x);\n  }\n\n  X\
    \ prod_all() { return seg.prod_all(); }\n\n  X prod(int l, int r) {\n    if (pid\
    \ > NODES * 0.9) rebuild();\n    split_at(l), split_at(r);\n    return seg.prod(l,\
    \ r);\n  }\n\n  void sort_inc(int l, int r) {\n    split_at(l), split_at(r);\n\
    \    while (1) {\n      if (pid > NODES * 0.9) rebuild();\n      Node* n = root[l];\n\
    \      int i = ss.next(l + 1);\n      if (i == r) break;\n      root[l] = merge(n,\
    \ root[i]);\n      ss.erase(i);\n      seg.set(i, Monoid::unit());\n    }\n  \
    \  rev[l] = 0;\n    seg.set(l, root[l]->x);\n  };\n\n  void sort_dec(int l, int\
    \ r) {\n    if (pid > NODES * 0.9) rebuild();\n    sort_inc(l, r);\n    rev[l]\
    \ = 1;\n    seg.set(l, root[l]->rev_x);\n  };\n\nprivate:\n  void init(vector<int>&\
    \ key, vector<X>& dat) {\n    rev.assign(N, 0);\n    root.clear();\n    seg.set_all(dat);\n\
    \    for (int i = 0; i < N; ++i) ss.insert(i);\n    for (int i = 0; i < N; ++i)\
    \ root.emplace_back(new_node(Monoid::unit()));\n    for (int i = 0; i < N; ++i)\
    \ {\n      assert(key[i] < KEY_MAX);\n      set_rec_key(root[i], 0, KEY_MAX, key[i],\
    \ dat[i]);\n    }\n  }\n\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n\
    \    int a = ss.prev(x);\n    int b = ss.next(a + 1);\n    ss.insert(x);\n   \
    \ if (!rev[a]) {\n      auto [nl, nr] = split(root[a], x - a);\n      root[a]\
    \ = nl;\n      root[x] = nr;\n      rev[a] = rev[x] = 0;\n      seg.set(a, root[a]->x);\n\
    \      seg.set(x, root[x]->x);\n    } else {\n      auto [nl, nr] = split(root[a],\
    \ b - x);\n      root[a] = nr;\n      root[x] = nl;\n      rev[a] = rev[x] = 1;\n\
    \      seg.set(a, root[a]->rev_x);\n      seg.set(x, root[x]->rev_x);\n    }\n\
    \  }\n\n  void rebuild() {\n    vector<int> key;\n    vector<X> dat;\n    key.reserve(N);\n\
    \    dat.reserve(N);\n    auto dfs\n        = [&](auto& dfs, Node* n, int node_l,\
    \ int node_r, bool rev) -> void {\n      if (!n) return;\n      if (node_r ==\
    \ node_l + 1) {\n        key.emplace_back(node_l);\n        dat.emplace_back(n->x);\n\
    \        return;\n      }\n      int node_m = (node_l + node_r) / 2;\n      if\
    \ (!rev) {\n        dfs(dfs, n->l, node_l, node_m, rev);\n        dfs(dfs, n->r,\
    \ node_m, node_r, rev);\n      }\n      if (rev) {\n        dfs(dfs, n->r, node_m,\
    \ node_r, rev);\n        dfs(dfs, n->l, node_l, node_m, rev);\n      }\n    };\n\
    \    for (int i = 0; i < N; ++i) {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX,\
    \ rev[i]);\n    }\n    assert(int(key.size()) == N);\n\n    pid = 0;\n    init(key,\
    \ dat);\n  }\n\n  Node* new_node(X x = Monoid::unit()) {\n    assert(pid < NODES);\n\
    \    pool[pid].x = pool[pid].rev_x = x;\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].size = 1;\n    return &(pool[pid++]);\n  }\n\n  pair<Node*, Node*>\
    \ split(Node* n, int k) {\n    if (k == 0) { return {nullptr, n}; }\n    if (k\
    \ == n->size) { return {n, nullptr}; }\n    int s = (n->l ? n->l->size : 0);\n\
    \    Node* b = new_node();\n    if (k <= s) {\n      auto [nl, nr] = split(n->l,\
    \ k);\n      b->l = nr;\n      b->r = n->r;\n      n->l = nl;\n      n->r = nullptr;\n\
    \    }\n    if (k > s) {\n      auto [nl, nr] = split(n->r, k - s);\n      n->l\
    \ = n->l;\n      n->r = nl;\n      b->l = nullptr;\n      b->r = nr;\n    }\n\
    \    update(n);\n    update(b);\n    return {n, b};\n  }\n\n  Node* merge(Node*\
    \ a, Node* b) {\n    if (!a) return b;\n    if (!b) return a;\n    a->l = merge(a->l,\
    \ b->l);\n    a->r = merge(a->r, b->r);\n    update(a);\n    return a;\n  }\n\n\
    \  void update(Node* n) {\n    if (!(n->l) && !(n->r)) { return; }\n    if (!(n->l))\
    \ {\n      n->x = n->r->x, n->rev_x = n->r->rev_x;\n      n->size = n->r->size;\n\
    \      return;\n    }\n    if (!(n->r)) {\n      n->x = n->l->x, n->rev_x = n->l->rev_x;\n\
    \      n->size = n->l->size;\n      return;\n    }\n    n->x = Monoid::op(n->l->x,\
    \ n->r->x);\n    n->rev_x = Monoid::op(n->r->rev_x, n->l->rev_x);\n    n->size\
    \ = n->l->size + n->r->size;\n  }\n\n  void set_rec_key(Node* n, int node_l, int\
    \ node_r, int k, const X& x) {\n    if (node_r == node_l + 1) {\n      n->x =\
    \ n->rev_x = x;\n      return;\n    }\n    int node_m = (node_l + node_r) / 2;\n\
    \    if (k < node_m) {\n      if (!(n->l)) n->l = new_node();\n      set_rec_key(n->l,\
    \ node_l, node_m, k, x);\n    }\n    if (node_m <= k) {\n      if (!(n->r)) n->r\
    \ = new_node();\n      set_rec_key(n->r, node_m, node_r, k, x);\n    }\n    update(n);\n\
    \  }\n\n  void set_rec_idx(Node* n, int node_l, int node_r, int idx, const X&\
    \ x) {\n    if (node_r == node_l + 1) {\n      n->x = n->rev_x = x;\n      return;\n\
    \    }\n    int node_m = (node_l + node_r) / 2;\n    int s = (n->l ? n->l->size\
    \ : 0);\n    if (idx < s) { set_rec_idx(n->l, node_l, node_m, idx, x); }\n   \
    \ if (idx >= s) { set_rec_idx(n->r, node_m, node_r, idx - s, x); }\n    update(n);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/sortable_segtree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/sortable_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/sortable_segtree.hpp
- /library/ds/segtree/sortable_segtree.hpp.html
title: ds/segtree/sortable_segtree.hpp
---
