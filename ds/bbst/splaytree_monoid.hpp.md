---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/splay.test.cpp
    title: test/mytest/splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1441.test.cpp
    title: test/yukicoder/1441.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1441_2.test.cpp
    title: test/yukicoder/1441_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bbst/splaytree_monoid.hpp\"\n/*\n\u30FB\u3042\u308B Node\
    \ \u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u3068\u304D\u306B\u306F\u3001\u305D\
    \u306E\u5148\u7956\u306F\u4F1D\u642C\u6E08\n\u30FBprod, rev_prod \u306F\u3001\
    rev \u3092\u53CD\u6620\u6E08\u306E\u3082\u306E\u3092\u6301\u3064\n\u30FBl, r \u306B\
    \u3082 rev \u3092\u53CD\u6620\u3055\u305B\u305F\u3082\u306E\u3092\u6301\u3064\n\
    */\ntemplate <typename Monoid, int NODES = 1'000'000>\nstruct SplayTree_Monoid\
    \ {\n  using X = typename Monoid::value_type;\n\n  struct Node {\n    Node *l,\
    \ *r, *p;\n    X x, prod, rev_prod;\n    int size;\n    bool rev;\n  };\n\n  Node\
    \ *pool;\n  int pid;\n\n  SplayTree_Monoid() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  void reset() { pid = 0; }\n\n  Node *new_node(const X &x) {\n    pool[pid].l\
    \ = pool[pid].r = pool[pid].p = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod\
    \ = x;\n    pool[pid].rev_prod = x;\n    pool[pid].size = 1;\n    pool[pid].rev\
    \ = 0;\n    return &(pool[pid++]);\n  }\n\n  Node *new_node(const vc<X> &dat)\
    \ {\n    auto dfs = [&](auto &dfs, int l, int r) -> Node * {\n      if (l == r)\
    \ return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      int m\
    \ = (l + r) / 2;\n      Node *l_root = dfs(dfs, l, m);\n      Node *r_root = dfs(dfs,\
    \ m + 1, r);\n      Node *root = new_node(dat[m]);\n      root->l = l_root, root->r\
    \ = r_root;\n      if (l_root) l_root->p = root;\n      if (r_root) r_root->p\
    \ = root;\n      update(root);\n      return root;\n    };\n    return dfs(dfs,\
    \ 0, len(dat));\n  }\n\n  // k \u756A\u76EE\u304C\u6839\u306B\u6765\u308B\u3088\
    \u3046\u306B splay \u3059\u308B\n  void get_kth(Node *&root, int k) {\n    assert(root\
    \ && 0 <= k && k < (root->size));\n    while (1) {\n      prop(root);\n      int\
    \ lsize = (root->l ? root->l->size : 0);\n      if (k < lsize) root = root->l;\n\
    \      if (k == lsize) { break; }\n      if (k > lsize) {\n        k -= lsize\
    \ + 1;\n        root = root->r;\n      }\n    }\n    splay(root);\n  }\n\n  //\
    \ \u5DE6\u306B\u53F3\u3092\u30DE\u30FC\u30B8\n  void merge(Node *&root, Node *r_root)\
    \ {\n    if (!root) {\n      root = r_root;\n      return;\n    }\n    if (!r_root)\
    \ return;\n    get_kth(root, root->size - 1);\n    root->r = r_root;\n    r_root->p\
    \ = root;\n    update(root);\n  }\n\n  // \u5DE6\u53F3\u306B\u5206\u3051\u3066\
    \u3001root \u3092\u5DE6\u5074\u306B\u5909\u66F4\u3002\u53F3\u5074\u3092 return\
    \ \u3059\u308B\u3002\n  Node *split(Node *&root, int l_size) {\n    if (!root)\
    \ { return nullptr; }\n    assert(0 <= l_size && l_size <= root->size);\n    if\
    \ (l_size == 0) {\n      Node *res = root;\n      root = nullptr;\n      return\
    \ res;\n    }\n    if (l_size == root->size) return nullptr;\n    get_kth(root,\
    \ l_size - 1);\n    Node *res = root->r;\n    root->r = nullptr;\n    res->p =\
    \ nullptr;\n    update(root);\n    return res;\n  }\n\n  X prod(Node *&root, int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (l ==\
    \ r) return Monoid::unit();\n    Node *r_root = split(root, r);\n    Node *m_root\
    \ = split(root, l);\n    X res = m_root->prod;\n    merge(root, m_root);\n   \
    \ merge(root, r_root);\n    return res;\n  }\n\n  void reverse(Node *&root, int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (r - l\
    \ <= 1) return;\n    Node *r_root = split(root, r);\n    Node *m_root = split(root,\
    \ l);\n    m_root->rev ^= 1;\n    swap(m_root->l, m_root->r);\n    swap(m_root->prod,\
    \ m_root->rev_prod);\n    merge(root, m_root);\n    merge(root, r_root);\n  }\n\
    \n  // root \u306E k \u756A\u76EE\u306B n \u3092\u633F\u5165\u3059\u308B\n  void\
    \ insert(Node *&root, int k, Node *n) {\n    if (!root) {\n      assert(k == 0);\n\
    \      root = n;\n      return;\n    }\n    assert(0 <= k && k <= root->size);\n\
    \    auto r_root = split(root, k);\n    merge(root, n);\n    merge(root, r_root);\n\
    \  }\n\n  void insert(Node *&root, int k, const X &x) { insert(root, k, new_node(x));\
    \ }\n\n  void set(Node *&root, int k, const X &x) {\n    get_kth(root, k);\n \
    \   root->x = x;\n    update(root);\n  }\n\n  // root \u304B\u3089 k \u756A\u76EE\
    \u3092\u524A\u9664\u3002\u524A\u9664\u3057\u305F\u30CE\u30FC\u30C9\u3092\u304B\
    \u3048\u3059\n  Node *erase(Node *&root, int k) {\n    assert(0 <= k && k < root->size);\n\
    \    get_kth(root, k);\n    Node *l_root = root->l;\n    Node *r_root = root->r;\n\
    \    if (l_root) l_root->p = nullptr;\n    if (r_root) r_root->p = nullptr;\n\
    \    root->l = nullptr;\n    root->r = nullptr;\n    root->prod = root->x;\n \
    \   root->size = 1;\n    merge(l_root, r_root);\n    swap(root, l_root);\n   \
    \ return l_root;\n  }\n\n  vc<X> get_all(Node *root) {\n    vc<X> res;\n    auto\
    \ dfs = [&](auto &dfs, Node *n) -> void {\n      if (!n) return;\n      dfs(dfs,\
    \ n->l);\n      res.eb(n->x);\n      dfs(dfs, n->r);\n    };\n    dfs(dfs, root);\n\
    \    return res;\n  }\n\n  void debug(Node *root) {\n    print(\"splay tree\"\
    );\n    string s;\n    auto dfs = [&](auto &dfs, Node *n) -> void {\n      if\
    \ (!n) return;\n      if (n->l) assert(n->l->p == n);\n      if (n->r) assert(n->r->p\
    \ == n);\n      s += \"l\";\n      dfs(dfs, n->l);\n      s.pop_back();\n    \
    \  print(s, \"size\", n->size, \"x\", n->x, \"prod\", n->prod, \"rev_prod\",\n\
    \            n->rev_prod);\n      s += \"r\";\n      dfs(dfs, n->r);\n      s.pop_back();\n\
    \    };\n    dfs(dfs, root);\n  }\n\nprivate:\n  void prop(Node *c) {\n    if\
    \ (!c->rev) return;\n    c->rev = 0;\n    if (c->l) {\n      c->l->rev ^= 1;\n\
    \      swap(c->l->l, c->l->r);\n      swap(c->l->prod, c->l->rev_prod);\n    }\n\
    \    if (c->r) {\n      c->r->rev ^= 1;\n      swap(c->r->l, c->r->r);\n     \
    \ swap(c->r->prod, c->r->rev_prod);\n    }\n  }\n\n  void update(Node *c) {\n\
    \    c->size = 1;\n    c->prod = c->x;\n    c->rev_prod = c->x;\n    if (c->l)\
    \ {\n      c->size += c->l->size;\n      c->prod = Monoid::op(c->l->prod, c->prod);\n\
    \      c->rev_prod = Monoid::op(c->rev_prod, c->l->rev_prod);\n    }\n    if (c->r)\
    \ {\n      c->size += c->r->size;\n      c->prod = Monoid::op(c->prod, c->r->prod);\n\
    \      c->rev_prod = Monoid::op(c->r->rev_prod, c->rev_prod);\n    }\n  }\n\n\
    \  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\
    \n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n    if (p->l == n) {\n\
    \      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else {\n      c = n->l;\n\
    \      n->l = p;\n      p->r = c;\n    }\n\n    if (pp && pp->l == p) pp->l =\
    \ n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p = pp;\n    p->p = n;\n  \
    \  if (c) c->p = p;\n  }\n\n  inline int state(Node *n) {\n    if (!n->p) return\
    \ 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r == n) return -1;\n    return\
    \ 0;\n  }\n\n  // c \u306E\u5148\u7956\u306F prop \u6E08\u3067\u3042\u308B\n \
    \ void splay(Node *c) {\n    while (c->p) {\n      Node *p = c->p;\n      Node\
    \ *pp = (p ? p->p : nullptr);\n      if (state(p) == 0) { rotate(c); }\n     \
    \ elif (state(c) == state(p)) {\n        rotate(p);\n        rotate(c);\n    \
    \  }\n      else {\n        rotate(c);\n        rotate(c);\n      }\n      if\
    \ (pp) update(pp);\n      if (p) update(p);\n    }\n    update(c);\n  }\n};\n"
  code: "/*\n\u30FB\u3042\u308B Node \u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u3068\
    \u304D\u306B\u306F\u3001\u305D\u306E\u5148\u7956\u306F\u4F1D\u642C\u6E08\n\u30FB\
    prod, rev_prod \u306F\u3001rev \u3092\u53CD\u6620\u6E08\u306E\u3082\u306E\u3092\
    \u6301\u3064\n\u30FBl, r \u306B\u3082 rev \u3092\u53CD\u6620\u3055\u305B\u305F\
    \u3082\u306E\u3092\u6301\u3064\n*/\ntemplate <typename Monoid, int NODES = 1'000'000>\n\
    struct SplayTree_Monoid {\n  using X = typename Monoid::value_type;\n\n  struct\
    \ Node {\n    Node *l, *r, *p;\n    X x, prod, rev_prod;\n    int size;\n    bool\
    \ rev;\n  };\n\n  Node *pool;\n  int pid;\n\n  SplayTree_Monoid() : pid(0) { pool\
    \ = new Node[NODES]; }\n\n  void reset() { pid = 0; }\n\n  Node *new_node(const\
    \ X &x) {\n    pool[pid].l = pool[pid].r = pool[pid].p = nullptr;\n    pool[pid].x\
    \ = x;\n    pool[pid].prod = x;\n    pool[pid].rev_prod = x;\n    pool[pid].size\
    \ = 1;\n    pool[pid].rev = 0;\n    return &(pool[pid++]);\n  }\n\n  Node *new_node(const\
    \ vc<X> &dat) {\n    auto dfs = [&](auto &dfs, int l, int r) -> Node * {\n   \
    \   if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      int m = (l + r) / 2;\n      Node *l_root = dfs(dfs, l, m);\n      Node\
    \ *r_root = dfs(dfs, m + 1, r);\n      Node *root = new_node(dat[m]);\n      root->l\
    \ = l_root, root->r = r_root;\n      if (l_root) l_root->p = root;\n      if (r_root)\
    \ r_root->p = root;\n      update(root);\n      return root;\n    };\n    return\
    \ dfs(dfs, 0, len(dat));\n  }\n\n  // k \u756A\u76EE\u304C\u6839\u306B\u6765\u308B\
    \u3088\u3046\u306B splay \u3059\u308B\n  void get_kth(Node *&root, int k) {\n\
    \    assert(root && 0 <= k && k < (root->size));\n    while (1) {\n      prop(root);\n\
    \      int lsize = (root->l ? root->l->size : 0);\n      if (k < lsize) root =\
    \ root->l;\n      if (k == lsize) { break; }\n      if (k > lsize) {\n       \
    \ k -= lsize + 1;\n        root = root->r;\n      }\n    }\n    splay(root);\n\
    \  }\n\n  // \u5DE6\u306B\u53F3\u3092\u30DE\u30FC\u30B8\n  void merge(Node *&root,\
    \ Node *r_root) {\n    if (!root) {\n      root = r_root;\n      return;\n   \
    \ }\n    if (!r_root) return;\n    get_kth(root, root->size - 1);\n    root->r\
    \ = r_root;\n    r_root->p = root;\n    update(root);\n  }\n\n  // \u5DE6\u53F3\
    \u306B\u5206\u3051\u3066\u3001root \u3092\u5DE6\u5074\u306B\u5909\u66F4\u3002\u53F3\
    \u5074\u3092 return \u3059\u308B\u3002\n  Node *split(Node *&root, int l_size)\
    \ {\n    if (!root) { return nullptr; }\n    assert(0 <= l_size && l_size <= root->size);\n\
    \    if (l_size == 0) {\n      Node *res = root;\n      root = nullptr;\n    \
    \  return res;\n    }\n    if (l_size == root->size) return nullptr;\n    get_kth(root,\
    \ l_size - 1);\n    Node *res = root->r;\n    root->r = nullptr;\n    res->p =\
    \ nullptr;\n    update(root);\n    return res;\n  }\n\n  X prod(Node *&root, int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (l ==\
    \ r) return Monoid::unit();\n    Node *r_root = split(root, r);\n    Node *m_root\
    \ = split(root, l);\n    X res = m_root->prod;\n    merge(root, m_root);\n   \
    \ merge(root, r_root);\n    return res;\n  }\n\n  void reverse(Node *&root, int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (r - l\
    \ <= 1) return;\n    Node *r_root = split(root, r);\n    Node *m_root = split(root,\
    \ l);\n    m_root->rev ^= 1;\n    swap(m_root->l, m_root->r);\n    swap(m_root->prod,\
    \ m_root->rev_prod);\n    merge(root, m_root);\n    merge(root, r_root);\n  }\n\
    \n  // root \u306E k \u756A\u76EE\u306B n \u3092\u633F\u5165\u3059\u308B\n  void\
    \ insert(Node *&root, int k, Node *n) {\n    if (!root) {\n      assert(k == 0);\n\
    \      root = n;\n      return;\n    }\n    assert(0 <= k && k <= root->size);\n\
    \    auto r_root = split(root, k);\n    merge(root, n);\n    merge(root, r_root);\n\
    \  }\n\n  void insert(Node *&root, int k, const X &x) { insert(root, k, new_node(x));\
    \ }\n\n  void set(Node *&root, int k, const X &x) {\n    get_kth(root, k);\n \
    \   root->x = x;\n    update(root);\n  }\n\n  // root \u304B\u3089 k \u756A\u76EE\
    \u3092\u524A\u9664\u3002\u524A\u9664\u3057\u305F\u30CE\u30FC\u30C9\u3092\u304B\
    \u3048\u3059\n  Node *erase(Node *&root, int k) {\n    assert(0 <= k && k < root->size);\n\
    \    get_kth(root, k);\n    Node *l_root = root->l;\n    Node *r_root = root->r;\n\
    \    if (l_root) l_root->p = nullptr;\n    if (r_root) r_root->p = nullptr;\n\
    \    root->l = nullptr;\n    root->r = nullptr;\n    root->prod = root->x;\n \
    \   root->size = 1;\n    merge(l_root, r_root);\n    swap(root, l_root);\n   \
    \ return l_root;\n  }\n\n  vc<X> get_all(Node *root) {\n    vc<X> res;\n    auto\
    \ dfs = [&](auto &dfs, Node *n) -> void {\n      if (!n) return;\n      dfs(dfs,\
    \ n->l);\n      res.eb(n->x);\n      dfs(dfs, n->r);\n    };\n    dfs(dfs, root);\n\
    \    return res;\n  }\n\n  void debug(Node *root) {\n    print(\"splay tree\"\
    );\n    string s;\n    auto dfs = [&](auto &dfs, Node *n) -> void {\n      if\
    \ (!n) return;\n      if (n->l) assert(n->l->p == n);\n      if (n->r) assert(n->r->p\
    \ == n);\n      s += \"l\";\n      dfs(dfs, n->l);\n      s.pop_back();\n    \
    \  print(s, \"size\", n->size, \"x\", n->x, \"prod\", n->prod, \"rev_prod\",\n\
    \            n->rev_prod);\n      s += \"r\";\n      dfs(dfs, n->r);\n      s.pop_back();\n\
    \    };\n    dfs(dfs, root);\n  }\n\nprivate:\n  void prop(Node *c) {\n    if\
    \ (!c->rev) return;\n    c->rev = 0;\n    if (c->l) {\n      c->l->rev ^= 1;\n\
    \      swap(c->l->l, c->l->r);\n      swap(c->l->prod, c->l->rev_prod);\n    }\n\
    \    if (c->r) {\n      c->r->rev ^= 1;\n      swap(c->r->l, c->r->r);\n     \
    \ swap(c->r->prod, c->r->rev_prod);\n    }\n  }\n\n  void update(Node *c) {\n\
    \    c->size = 1;\n    c->prod = c->x;\n    c->rev_prod = c->x;\n    if (c->l)\
    \ {\n      c->size += c->l->size;\n      c->prod = Monoid::op(c->l->prod, c->prod);\n\
    \      c->rev_prod = Monoid::op(c->rev_prod, c->l->rev_prod);\n    }\n    if (c->r)\
    \ {\n      c->size += c->r->size;\n      c->prod = Monoid::op(c->prod, c->r->prod);\n\
    \      c->rev_prod = Monoid::op(c->r->rev_prod, c->rev_prod);\n    }\n  }\n\n\
    \  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\
    \n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n    if (p->l == n) {\n\
    \      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else {\n      c = n->l;\n\
    \      n->l = p;\n      p->r = c;\n    }\n\n    if (pp && pp->l == p) pp->l =\
    \ n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p = pp;\n    p->p = n;\n  \
    \  if (c) c->p = p;\n  }\n\n  inline int state(Node *n) {\n    if (!n->p) return\
    \ 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r == n) return -1;\n    return\
    \ 0;\n  }\n\n  // c \u306E\u5148\u7956\u306F prop \u6E08\u3067\u3042\u308B\n \
    \ void splay(Node *c) {\n    while (c->p) {\n      Node *p = c->p;\n      Node\
    \ *pp = (p ? p->p : nullptr);\n      if (state(p) == 0) { rotate(c); }\n     \
    \ elif (state(c) == state(p)) {\n        rotate(p);\n        rotate(c);\n    \
    \  }\n      else {\n        rotate(c);\n        rotate(c);\n      }\n      if\
    \ (pp) update(pp);\n      if (p) update(p);\n    }\n    update(c);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/bbst/splaytree_monoid.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1441.test.cpp
  - test/yukicoder/1441_2.test.cpp
  - test/mytest/splay.test.cpp
  - test/aoj/1508.test.cpp
documentation_of: ds/bbst/splaytree_monoid.hpp
layout: document
redirect_from:
- /library/ds/bbst/splaytree_monoid.hpp
- /library/ds/bbst/splaytree_monoid.hpp.html
title: ds/bbst/splaytree_monoid.hpp
---
