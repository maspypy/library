---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508_splay.test.cpp
    title: test/aoj/1508_splay.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/splaytree_monoid.hpp\"\n\n// new_node(x) \uFF1A 1\u8981\
    \u7D20\u3060\u3051\u304B\u3089\u306A\u308B\u6728\n// new_node(A) \uFF1A \u5217\
    \u3092\u6728\u306B\u3059\u308B\u3001\u5148\u982D\u3092\u6839\u3068\u3059\u308B\
    \u3002\ntemplate <typename Monoid, int NODES = 5'000'000>\nstruct SplayTree_Monoid\
    \ {\n  using X = typename Monoid::value_type;\n\n  struct Node {\n    Node *l,\
    \ *r, *p;\n    X x;\n    X prod;\n    int size;\n    Node()\n        : l(nullptr),\n\
    \          r(nullptr),\n          p(nullptr),\n          x(Monoid::unit()),\n\
    \          prod(Monoid::unit()),\n          size(1) {}\n  };\n\n  Node *pool;\n\
    \  int pid;\n\n  SplayTree_Monoid() : pid(0) { pool = new Node[NODES]; }\n\n \
    \ X prod(Node *&root, int l, int r) {\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (l == r) return Monoid::unit();\n    Node *r_root = split(root, r);\n\
    \    Node *m_root = split(root, l);\n    X res = m_root->prod;\n    merge(root,\
    \ m_root);\n    merge(root, r_root);\n    return res;\n  }\n\n  X prod_all(Node\
    \ *root) {\n    if (!root) return Monoid::unit();\n    return root->prod;\n  }\n\
    \n  Node *new_node(const X &x) {\n    pool[pid].l = pool[pid].r = pool[pid].p\
    \ = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod = x;\n    pool[pid].size\
    \ = 1;\n    return &(pool[pid++]);\n  }\n\n  Node *new_node(const vc<X> &dat)\
    \ {\n    Node *root = nullptr;\n    FOR_R(i, len(dat)) { insert(root, 0, new_node(dat[i]));\
    \ }\n    return root;\n  }\n\n  // k \u756A\u76EE\u304C\u6839\u306B\u6765\u308B\
    \u3088\u3046\u306B splay \u3059\u308B\n  void get_kth(Node *&root, int k) {\n\
    \    assert(0 <= k && k < (root->size));\n    while (1) {\n      int lsize = (root->l\
    \ ? root->l->size : 0);\n      if (k < lsize) root = root->l;\n      if (k ==\
    \ lsize) {\n        splay(root);\n        break;\n      }\n      if (k > lsize)\
    \ {\n        k -= lsize + 1;\n        root = root->r;\n      }\n    }\n  }\n\n\
    \  // \u5DE6\u306B\u53F3\u3092\u30DE\u30FC\u30B8\n  void merge(Node *&root, Node\
    \ *r_root) {\n    if (!root) {\n      root = r_root;\n      return;\n    }\n \
    \   if (!r_root) return;\n    get_kth(root, root->size - 1);\n    root->r = r_root;\n\
    \    r_root->p = root;\n    update(root);\n  }\n\n  // \u5DE6\u53F3\u306B\u5206\
    \u3051\u3066\u3001root \u3092\u5DE6\u5074\u306B\u5909\u66F4\u3002\u53F3\u5074\u3092\
    \ return \u3059\u308B\u3002\n  Node *split(Node *&root, int l_size) {\n    assert(0\
    \ <= l_size && l_size <= root->size);\n    if (l_size == 0) {\n      Node *res\
    \ = root;\n      root = nullptr;\n      return res;\n    }\n    if (l_size ==\
    \ root->size) return nullptr;\n    get_kth(root, l_size - 1);\n    Node *res =\
    \ root->r;\n    root->r = nullptr;\n    res->p = nullptr;\n    update(root);\n\
    \    return res;\n  }\n\n  // root \u306E k \u756A\u76EE\u306B n \u3092\u633F\u5165\
    \u3059\u308B\n  void insert(Node *&root, int k, Node *n) {\n    if (!root) {\n\
    \      assert(k == 0);\n      root = n;\n      return;\n    }\n    assert(0 <=\
    \ k && k <= root->size);\n    auto r_root = split(root, k);\n    merge(root, n);\n\
    \    merge(root, r_root);\n  }\n\n  // root \u304B\u3089 k \u756A\u76EE\u3092\u524A\
    \u9664\u3002\u524A\u9664\u3057\u305F\u30CE\u30FC\u30C9\u3092\u304B\u3048\u3059\
    \n  Node *erase(Node *&root, int k) {\n    assert(0 <= k && k < root->size);\n\
    \    get_kth(root, k);\n    Node *l_root = root->l;\n    Node *r_root = root->r;\n\
    \    if (l_root) l_root->p = nullptr;\n    if (r_root) r_root->p = nullptr;\n\
    \    root->l = nullptr;\n    root->r = nullptr;\n    update(root);\n    merge(l_root,\
    \ r_root);\n    swap(root, l_root);\n    return l_root;\n  }\n\n  void set(Node\
    \ *&root, int k, const X &x) {\n    get_kth(root, k);\n    root->x = x;\n    update(root);\n\
    \  }\n\n  void debug(Node *root) {\n    print(\"splay tree\");\n    if (!root)\
    \ { return print(\"nullptr\"); }\n    print(\"root_val\", root->x);\n    vc<X>\
    \ dat;\n    auto dfs = [&](auto &dfs, Node *n) -> void {\n      if (n->l) dfs(dfs,\
    \ n->l);\n      dat.eb(n->x);\n      if (n->r) dfs(dfs, n->r);\n    };\n    dfs(dfs,\
    \ root);\n    print(\"all\", dat);\n  }\n\nprivate:\n  void update(Node *n) {\n\
    \    // n \u306E\u60C5\u5831\u3092\u518D\u8A08\u7B97\n    n->size = 1;\n    n->prod\
    \ = n->x;\n    if (n->l) n->size += n->l->size, n->prod = Monoid::op(n->l->prod,\
    \ n->prod);\n    if (n->r) n->size += n->r->size, n->prod = Monoid::op(n->prod,\
    \ n->r->prod);\n  }\n\n  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\
    \u3065\u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n \
    \   if (p->l == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    }\
    \ else {\n      c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n\n    if (pp\
    \ && pp->l == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p =\
    \ pp;\n    p->p = n;\n    if (c) c->p = p;\n\n    update(p);\n    update(n);\n\
    \  }\n\n  inline int state(Node *n) {\n    if (!n->p) return 0;\n    if (n->p->l\
    \ == n) return 1;\n    if (n->p->r == n) return -1;\n    return 0;\n  }\n\n  void\
    \ splay(Node *n) {\n    while (n->p) {\n      if (state(n->p) == 0) { rotate(n);\
    \ }\n      elif (state(n) == state(n->p)) {\n        rotate(n->p);\n        rotate(n);\n\
    \      }\n      else {\n        rotate(n);\n        rotate(n);\n      }\n    }\n\
    \  }\n};\n"
  code: "#pragma once\n\n// new_node(x) \uFF1A 1\u8981\u7D20\u3060\u3051\u304B\u3089\
    \u306A\u308B\u6728\n// new_node(A) \uFF1A \u5217\u3092\u6728\u306B\u3059\u308B\
    \u3001\u5148\u982D\u3092\u6839\u3068\u3059\u308B\u3002\ntemplate <typename Monoid,\
    \ int NODES = 5'000'000>\nstruct SplayTree_Monoid {\n  using X = typename Monoid::value_type;\n\
    \n  struct Node {\n    Node *l, *r, *p;\n    X x;\n    X prod;\n    int size;\n\
    \    Node()\n        : l(nullptr),\n          r(nullptr),\n          p(nullptr),\n\
    \          x(Monoid::unit()),\n          prod(Monoid::unit()),\n          size(1)\
    \ {}\n  };\n\n  Node *pool;\n  int pid;\n\n  SplayTree_Monoid() : pid(0) { pool\
    \ = new Node[NODES]; }\n\n  X prod(Node *&root, int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= root->size);\n    if (l == r) return Monoid::unit();\n\
    \    Node *r_root = split(root, r);\n    Node *m_root = split(root, l);\n    X\
    \ res = m_root->prod;\n    merge(root, m_root);\n    merge(root, r_root);\n  \
    \  return res;\n  }\n\n  X prod_all(Node *root) {\n    if (!root) return Monoid::unit();\n\
    \    return root->prod;\n  }\n\n  Node *new_node(const X &x) {\n    pool[pid].l\
    \ = pool[pid].r = pool[pid].p = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod\
    \ = x;\n    pool[pid].size = 1;\n    return &(pool[pid++]);\n  }\n\n  Node *new_node(const\
    \ vc<X> &dat) {\n    Node *root = nullptr;\n    FOR_R(i, len(dat)) { insert(root,\
    \ 0, new_node(dat[i])); }\n    return root;\n  }\n\n  // k \u756A\u76EE\u304C\u6839\
    \u306B\u6765\u308B\u3088\u3046\u306B splay \u3059\u308B\n  void get_kth(Node *&root,\
    \ int k) {\n    assert(0 <= k && k < (root->size));\n    while (1) {\n      int\
    \ lsize = (root->l ? root->l->size : 0);\n      if (k < lsize) root = root->l;\n\
    \      if (k == lsize) {\n        splay(root);\n        break;\n      }\n    \
    \  if (k > lsize) {\n        k -= lsize + 1;\n        root = root->r;\n      }\n\
    \    }\n  }\n\n  // \u5DE6\u306B\u53F3\u3092\u30DE\u30FC\u30B8\n  void merge(Node\
    \ *&root, Node *r_root) {\n    if (!root) {\n      root = r_root;\n      return;\n\
    \    }\n    if (!r_root) return;\n    get_kth(root, root->size - 1);\n    root->r\
    \ = r_root;\n    r_root->p = root;\n    update(root);\n  }\n\n  // \u5DE6\u53F3\
    \u306B\u5206\u3051\u3066\u3001root \u3092\u5DE6\u5074\u306B\u5909\u66F4\u3002\u53F3\
    \u5074\u3092 return \u3059\u308B\u3002\n  Node *split(Node *&root, int l_size)\
    \ {\n    assert(0 <= l_size && l_size <= root->size);\n    if (l_size == 0) {\n\
    \      Node *res = root;\n      root = nullptr;\n      return res;\n    }\n  \
    \  if (l_size == root->size) return nullptr;\n    get_kth(root, l_size - 1);\n\
    \    Node *res = root->r;\n    root->r = nullptr;\n    res->p = nullptr;\n   \
    \ update(root);\n    return res;\n  }\n\n  // root \u306E k \u756A\u76EE\u306B\
    \ n \u3092\u633F\u5165\u3059\u308B\n  void insert(Node *&root, int k, Node *n)\
    \ {\n    if (!root) {\n      assert(k == 0);\n      root = n;\n      return;\n\
    \    }\n    assert(0 <= k && k <= root->size);\n    auto r_root = split(root,\
    \ k);\n    merge(root, n);\n    merge(root, r_root);\n  }\n\n  // root \u304B\u3089\
    \ k \u756A\u76EE\u3092\u524A\u9664\u3002\u524A\u9664\u3057\u305F\u30CE\u30FC\u30C9\
    \u3092\u304B\u3048\u3059\n  Node *erase(Node *&root, int k) {\n    assert(0 <=\
    \ k && k < root->size);\n    get_kth(root, k);\n    Node *l_root = root->l;\n\
    \    Node *r_root = root->r;\n    if (l_root) l_root->p = nullptr;\n    if (r_root)\
    \ r_root->p = nullptr;\n    root->l = nullptr;\n    root->r = nullptr;\n    update(root);\n\
    \    merge(l_root, r_root);\n    swap(root, l_root);\n    return l_root;\n  }\n\
    \n  void set(Node *&root, int k, const X &x) {\n    get_kth(root, k);\n    root->x\
    \ = x;\n    update(root);\n  }\n\n  void debug(Node *root) {\n    print(\"splay\
    \ tree\");\n    if (!root) { return print(\"nullptr\"); }\n    print(\"root_val\"\
    , root->x);\n    vc<X> dat;\n    auto dfs = [&](auto &dfs, Node *n) -> void {\n\
    \      if (n->l) dfs(dfs, n->l);\n      dat.eb(n->x);\n      if (n->r) dfs(dfs,\
    \ n->r);\n    };\n    dfs(dfs, root);\n    print(\"all\", dat);\n  }\n\nprivate:\n\
    \  void update(Node *n) {\n    // n \u306E\u60C5\u5831\u3092\u518D\u8A08\u7B97\
    \n    n->size = 1;\n    n->prod = n->x;\n    if (n->l) n->size += n->l->size,\
    \ n->prod = Monoid::op(n->l->prod, n->prod);\n    if (n->r) n->size += n->r->size,\
    \ n->prod = Monoid::op(n->prod, n->r->prod);\n  }\n\n  void rotate(Node *n) {\n\
    \    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\n    Node *pp, *p, *c;\n\
    \    p = n->p;\n    pp = p->p;\n\n    if (p->l == n) {\n      c = n->r;\n    \
    \  n->r = p;\n      p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n\
    \      p->r = c;\n    }\n\n    if (pp && pp->l == p) pp->l = n;\n    if (pp &&\
    \ pp->r == p) pp->r = n;\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n\
    \n    update(p);\n    update(n);\n  }\n\n  inline int state(Node *n) {\n    if\
    \ (!n->p) return 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r == n) return\
    \ -1;\n    return 0;\n  }\n\n  void splay(Node *n) {\n    while (n->p) {\n   \
    \   if (state(n->p) == 0) { rotate(n); }\n      elif (state(n) == state(n->p))\
    \ {\n        rotate(n->p);\n        rotate(n);\n      }\n      else {\n      \
    \  rotate(n);\n        rotate(n);\n      }\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/splaytree_monoid.hpp
  requiredBy: []
  timestamp: '2022-05-17 04:29:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1508_splay.test.cpp
documentation_of: ds/splaytree_monoid.hpp
layout: document
redirect_from:
- /library/ds/splaytree_monoid.hpp
- /library/ds/splaytree_monoid.hpp.html
title: ds/splaytree_monoid.hpp
---
