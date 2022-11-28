---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bbst/splaytree_lazy.hpp\"\n// Monoid_X \u306E\u53EF\u63DB\
    \u6027\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\ntemplate <typename Lazy, int\
    \ NODES = 1'000'000>\nstruct SplayTree_Lazy {\n  using Monoid_X = typename Lazy::Monoid_X;\n\
    \  using Monoid_A = typename Lazy::Monoid_A;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n\n  struct Node {\n    Node *l, *r,\
    \ *p;\n    X x, prod;\n    A a;\n    int size;\n    bool rev;\n  };\n\n  Node\
    \ *pool;\n  int pid;\n\n  SplayTree_Lazy() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  Node *new_node(const X &x) {\n    pool[pid].l = pool[pid].r = pool[pid].p\
    \ = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod = x;\n    pool[pid].a =\
    \ Monoid_A::unit();\n    pool[pid].size = 1;\n    pool[pid].rev = 0;\n    return\
    \ &(pool[pid++]);\n  }\n\n  Node *new_node(const vc<X> &dat) {\n    auto dfs =\
    \ [&](auto &dfs, int l, int r) -> Node * {\n      if (l == r) return nullptr;\n\
    \      if (r == l + 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n\
    \      Node *l_root = dfs(dfs, l, m);\n      Node *r_root = dfs(dfs, m + 1, r);\n\
    \      Node *root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n\
    \      if (l_root) l_root->p = root;\n      if (r_root) r_root->p = root;\n  \
    \    update(root);\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  // k \u756A\u76EE\u304C\u6839\u306B\u6765\u308B\u3088\u3046\u306B splay\
    \ \u3059\u308B\n  void get_kth(Node *&root, int k) {\n    assert(root && 0 <=\
    \ k && k < (root->size));\n    while (1) {\n      prop(root);\n      int lsize\
    \ = (root->l ? root->l->size : 0);\n      if (k < lsize) root = root->l;\n   \
    \   if (k == lsize) { break; }\n      if (k > lsize) {\n        k -= lsize + 1;\n\
    \        root = root->r;\n      }\n    }\n    splay(root);\n  }\n\n  // \u5DE6\
    \u306B\u53F3\u3092\u30DE\u30FC\u30B8\n  void merge(Node *&root, Node *r_root)\
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
    \ r) return Monoid_X::unit();\n    Node *r_root = split(root, r);\n    Node *m_root\
    \ = split(root, l);\n    X res = m_root->prod;\n    merge(root, m_root);\n   \
    \ merge(root, r_root);\n    return res;\n  }\n\n  void reverse(Node *&root, int\
    \ l, int r) {\n    assert(Monoid_X::commute);\n    assert(0 <= l && l <= r &&\
    \ r <= root->size);\n    if (r - l <= 1) return;\n    Node *r_root = split(root,\
    \ r);\n    Node *m_root = split(root, l);\n    m_root->rev ^= 1;\n    swap(m_root->l,\
    \ m_root->r);\n    merge(root, m_root);\n    merge(root, r_root);\n  }\n\n  void\
    \ apply(Node *&root, int l, int r, const A &a) {\n    assert(0 <= l && l <= r\
    \ && r <= root->size);\n    if (l == r) return;\n    Node *r_root = split(root,\
    \ r);\n    Node *m_root = split(root, l);\n    m_root->x = Lazy::act(m_root->x,\
    \ a);\n    m_root->prod = Lazy::act(m_root->prod, a);\n    m_root->a = Monoid_A::op(m_root->a,\
    \ a);\n    merge(root, m_root);\n    merge(root, r_root);\n  }\n\n  // root \u306E\
    \ k \u756A\u76EE\u306B n \u3092\u633F\u5165\u3059\u308B\n  void insert(Node *&root,\
    \ int k, Node *n) {\n    if (!root) {\n      assert(k == 0);\n      root = n;\n\
    \      return;\n    }\n    assert(0 <= k && k <= root->size);\n    auto r_root\
    \ = split(root, k);\n    merge(root, n);\n    merge(root, r_root);\n  }\n\n  void\
    \ insert(Node *&root, int k, const X &x) { insert(root, k, new_node(x)); }\n\n\
    \  // root \u304B\u3089 k \u756A\u76EE\u3092\u524A\u9664\u3002\u524A\u9664\u3057\
    \u305F\u30CE\u30FC\u30C9\u3092\u304B\u3048\u3059\n  Node *erase(Node *&root, int\
    \ k) {\n    assert(0 <= k && k < root->size);\n    get_kth(root, k);\n    Node\
    \ *l_root = root->l;\n    Node *r_root = root->r;\n    if (l_root) l_root->p =\
    \ nullptr;\n    if (r_root) r_root->p = nullptr;\n    root->l = nullptr;\n   \
    \ root->r = nullptr;\n    root->prod = root->x;\n    root->size = 1;\n    merge(l_root,\
    \ r_root);\n    swap(root, l_root);\n    return l_root;\n  }\n\n  void debug(Node\
    \ *root) {\n    print(\"splay tree\");\n    string s;\n    auto dfs = [&](auto\
    \ &dfs, Node *n) -> void {\n      if (!n) return;\n      if (n->l) assert(n->l->p\
    \ == n);\n      if (n->r) assert(n->r->p == n);\n      s += \"l\";\n      dfs(dfs,\
    \ n->l);\n      s.pop_back();\n      print(s, \"size\", n->size, \"x\", n->x,\
    \ \"prod\", n->prod, \"apply\", n->a);\n      s += \"r\";\n      dfs(dfs, n->r);\n\
    \      s.pop_back();\n    };\n    dfs(dfs, root);\n  }\n\nprivate:\n  void prop(Node\
    \ *c) {\n    A &a = c->a;\n    if (a != Monoid_A::unit()) {\n      if (c->l) {\n\
    \        c->l->x = Lazy::act(c->l->x, a);\n        c->l->prod = Lazy::act(c->l->prod,\
    \ a);\n        c->l->a = Monoid_A::op(c->l->a, a);\n      }\n      if (c->r) {\n\
    \        c->r->x = Lazy::act(c->r->x, a);\n        c->r->prod = Lazy::act(c->r->prod,\
    \ a);\n        c->r->a = Monoid_A::op(c->r->a, a);\n      }\n    }\n    a = Monoid_A::unit();\n\
    \    if (c->rev) {\n      if (c->l) {\n        c->l->rev ^= 1;\n        swap(c->l->l,\
    \ c->l->r);\n      }\n      if (c->r) {\n        c->r->rev ^= 1;\n        swap(c->r->l,\
    \ c->r->r);\n      }\n    }\n    c->rev = 0;\n  }\n\n  void update(Node *c) {\n\
    \    c->size = 1;\n    c->prod = c->x;\n    if (c->l) {\n      c->size += c->l->size;\n\
    \      c->prod = Monoid_X::op(c->l->prod, c->prod);\n    }\n    if (c->r) {\n\
    \      c->size += c->r->size;\n      c->prod = Monoid_X::op(c->prod, c->r->prod);\n\
    \    }\n  }\n\n  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\
    \u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n    if (p->l\
    \ == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else {\n \
    \     c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n\n    if (pp && pp->l\
    \ == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p = pp;\n   \
    \ p->p = n;\n    if (c) c->p = p;\n  }\n\n  inline int state(Node *n) {\n    if\
    \ (!n->p) return 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r == n) return\
    \ -1;\n    return 0;\n  }\n\n  void splay(Node *c) {\n    while (c->p) {\n   \
    \   Node *p = c->p;\n      Node *pp = (p ? p->p : nullptr);\n      if (state(p)\
    \ == 0) { rotate(c); }\n      elif (state(c) == state(p)) {\n        rotate(p);\n\
    \        rotate(c);\n      }\n      else {\n        rotate(c);\n        rotate(c);\n\
    \      }\n      if (pp) update(pp);\n      if (p) update(p);\n    }\n    update(c);\n\
    \  }\n};\n"
  code: "// Monoid_X \u306E\u53EF\u63DB\u6027\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\
    \ntemplate <typename Lazy, int NODES = 1'000'000>\nstruct SplayTree_Lazy {\n \
    \ using Monoid_X = typename Lazy::Monoid_X;\n  using Monoid_A = typename Lazy::Monoid_A;\n\
    \  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \n  struct Node {\n    Node *l, *r, *p;\n    X x, prod;\n    A a;\n    int size;\n\
    \    bool rev;\n  };\n\n  Node *pool;\n  int pid;\n\n  SplayTree_Lazy() : pid(0)\
    \ { pool = new Node[NODES]; }\n\n  Node *new_node(const X &x) {\n    pool[pid].l\
    \ = pool[pid].r = pool[pid].p = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod\
    \ = x;\n    pool[pid].a = Monoid_A::unit();\n    pool[pid].size = 1;\n    pool[pid].rev\
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
    \ r) return Monoid_X::unit();\n    Node *r_root = split(root, r);\n    Node *m_root\
    \ = split(root, l);\n    X res = m_root->prod;\n    merge(root, m_root);\n   \
    \ merge(root, r_root);\n    return res;\n  }\n\n  void reverse(Node *&root, int\
    \ l, int r) {\n    assert(Monoid_X::commute);\n    assert(0 <= l && l <= r &&\
    \ r <= root->size);\n    if (r - l <= 1) return;\n    Node *r_root = split(root,\
    \ r);\n    Node *m_root = split(root, l);\n    m_root->rev ^= 1;\n    swap(m_root->l,\
    \ m_root->r);\n    merge(root, m_root);\n    merge(root, r_root);\n  }\n\n  void\
    \ apply(Node *&root, int l, int r, const A &a) {\n    assert(0 <= l && l <= r\
    \ && r <= root->size);\n    if (l == r) return;\n    Node *r_root = split(root,\
    \ r);\n    Node *m_root = split(root, l);\n    m_root->x = Lazy::act(m_root->x,\
    \ a);\n    m_root->prod = Lazy::act(m_root->prod, a);\n    m_root->a = Monoid_A::op(m_root->a,\
    \ a);\n    merge(root, m_root);\n    merge(root, r_root);\n  }\n\n  // root \u306E\
    \ k \u756A\u76EE\u306B n \u3092\u633F\u5165\u3059\u308B\n  void insert(Node *&root,\
    \ int k, Node *n) {\n    if (!root) {\n      assert(k == 0);\n      root = n;\n\
    \      return;\n    }\n    assert(0 <= k && k <= root->size);\n    auto r_root\
    \ = split(root, k);\n    merge(root, n);\n    merge(root, r_root);\n  }\n\n  void\
    \ insert(Node *&root, int k, const X &x) { insert(root, k, new_node(x)); }\n\n\
    \  // root \u304B\u3089 k \u756A\u76EE\u3092\u524A\u9664\u3002\u524A\u9664\u3057\
    \u305F\u30CE\u30FC\u30C9\u3092\u304B\u3048\u3059\n  Node *erase(Node *&root, int\
    \ k) {\n    assert(0 <= k && k < root->size);\n    get_kth(root, k);\n    Node\
    \ *l_root = root->l;\n    Node *r_root = root->r;\n    if (l_root) l_root->p =\
    \ nullptr;\n    if (r_root) r_root->p = nullptr;\n    root->l = nullptr;\n   \
    \ root->r = nullptr;\n    root->prod = root->x;\n    root->size = 1;\n    merge(l_root,\
    \ r_root);\n    swap(root, l_root);\n    return l_root;\n  }\n\n  void debug(Node\
    \ *root) {\n    print(\"splay tree\");\n    string s;\n    auto dfs = [&](auto\
    \ &dfs, Node *n) -> void {\n      if (!n) return;\n      if (n->l) assert(n->l->p\
    \ == n);\n      if (n->r) assert(n->r->p == n);\n      s += \"l\";\n      dfs(dfs,\
    \ n->l);\n      s.pop_back();\n      print(s, \"size\", n->size, \"x\", n->x,\
    \ \"prod\", n->prod, \"apply\", n->a);\n      s += \"r\";\n      dfs(dfs, n->r);\n\
    \      s.pop_back();\n    };\n    dfs(dfs, root);\n  }\n\nprivate:\n  void prop(Node\
    \ *c) {\n    A &a = c->a;\n    if (a != Monoid_A::unit()) {\n      if (c->l) {\n\
    \        c->l->x = Lazy::act(c->l->x, a);\n        c->l->prod = Lazy::act(c->l->prod,\
    \ a);\n        c->l->a = Monoid_A::op(c->l->a, a);\n      }\n      if (c->r) {\n\
    \        c->r->x = Lazy::act(c->r->x, a);\n        c->r->prod = Lazy::act(c->r->prod,\
    \ a);\n        c->r->a = Monoid_A::op(c->r->a, a);\n      }\n    }\n    a = Monoid_A::unit();\n\
    \    if (c->rev) {\n      if (c->l) {\n        c->l->rev ^= 1;\n        swap(c->l->l,\
    \ c->l->r);\n      }\n      if (c->r) {\n        c->r->rev ^= 1;\n        swap(c->r->l,\
    \ c->r->r);\n      }\n    }\n    c->rev = 0;\n  }\n\n  void update(Node *c) {\n\
    \    c->size = 1;\n    c->prod = c->x;\n    if (c->l) {\n      c->size += c->l->size;\n\
    \      c->prod = Monoid_X::op(c->l->prod, c->prod);\n    }\n    if (c->r) {\n\
    \      c->size += c->r->size;\n      c->prod = Monoid_X::op(c->prod, c->r->prod);\n\
    \    }\n  }\n\n  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\
    \u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n    if (p->l\
    \ == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else {\n \
    \     c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n\n    if (pp && pp->l\
    \ == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p = pp;\n   \
    \ p->p = n;\n    if (c) c->p = p;\n  }\n\n  inline int state(Node *n) {\n    if\
    \ (!n->p) return 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r == n) return\
    \ -1;\n    return 0;\n  }\n\n  void splay(Node *c) {\n    while (c->p) {\n   \
    \   Node *p = c->p;\n      Node *pp = (p ? p->p : nullptr);\n      if (state(p)\
    \ == 0) { rotate(c); }\n      elif (state(c) == state(p)) {\n        rotate(p);\n\
    \        rotate(c);\n      }\n      else {\n        rotate(c);\n        rotate(c);\n\
    \      }\n      if (pp) update(pp);\n      if (p) update(p);\n    }\n    update(c);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/bbst/splaytree_lazy.hpp
  requiredBy: []
  timestamp: '2022-11-28 18:54:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
documentation_of: ds/bbst/splaytree_lazy.hpp
layout: document
redirect_from:
- /library/ds/bbst/splaytree_lazy.hpp
- /library/ds/bbst/splaytree_lazy.hpp.html
title: ds/bbst/splaytree_lazy.hpp
---
