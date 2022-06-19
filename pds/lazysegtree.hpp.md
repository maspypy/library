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
  bundledCode: "#line 2 \"pds/lazysegtree.hpp\"\n\ntemplate <typename Lazy, int NODES\
    \ = 1'000'000>\nstruct Persistent_LazySegTree {\n  using Monoid_X = typename Lazy::X_structure;\n\
    \  using Monoid_A = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n\n  struct Node {\n    Node *l, *r;\n\
    \    X x;\n    A a;\n    bool propagated;\n  };\n\n  const int n;\n  Node *pool;\n\
    \  int pid;\n\n  Persistent_LazySegTree(int n) : n(n), pid(0) { pool = new Node[NODES];\
    \ }\n\n  Node *new_node(const X &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].x = x;\n    pool[pid].a = Monoid_A::unit();\n    pool[pid].propagated\
    \ = 1;\n    return &(pool[pid++]);\n  }\n\n  Node *new_node(const vc<X> &dat)\
    \ {\n    assert(len(dat) == n);\n    auto dfs = [&](auto &dfs, int l, int r) ->\
    \ Node * {\n      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      int m = (l + r) / 2;\n      Node *l_root = dfs(dfs, l, m);\n      Node\
    \ *r_root = dfs(dfs, m, r);\n      X x = Monoid_X::op(l_root->x, r_root->x);\n\
    \      Node *root = new_node(x);\n      root->l = l_root, root->r = r_root;\n\
    \      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(Node\
    \ *root, int l, int r) {\n    assert(0 <= l && l < r && r <= n);\n    X x = Monoid_X::unit();\n\
    \    prod_rec(root, 0, n, l, r, x);\n    return x;\n  }\n\n  Node *set(Node *root,\
    \ int i, const X &x) {\n    assert(0 <= i && i < n);\n    return set_rec(root,\
    \ 0, n, i, x);\n  }\n\n  Node *apply(Node *root, int l, int r, const A &a) {\n\
    \    assert(0 <= l && l < r && r <= n);\n    return apply_rec(root, 0, n, l, r,\
    \ a);\n  }\n\n  vc<X> restore(Node *root) {\n    vc<X> res;\n    auto dfs = [&](auto\
    \ &dfs, Node *c, int node_l, int node_r) -> void {\n      if (node_r - node_l\
    \ == 1) {\n        res.eb(c->x);\n        return;\n      }\n      int node_m =\
    \ (node_l + node_r) / 2;\n      prop(c);\n      dfs(dfs, c->l, node_l, node_m);\n\
    \      dfs(dfs, c->r, node_m, node_r);\n    };\n    dfs(dfs, root, 0, n);\n  \
    \  return res;\n  }\n\n  void reset() { pid = 0; }\n\nprivate:\n  Node *copy_node(Node\
    \ *n) {\n    if (!n) return nullptr;\n    pool[pid].l = n->l;\n    pool[pid].r\
    \ = n->r;\n    pool[pid].x = n->x;\n    pool[pid].a = n->a;\n    return &(pool[pid++]);\n\
    \  }\n\n  void prop(Node *c) {\n    assert(c->l && c->r);\n    if (!c->propagated)\
    \ {\n      c->l = copy_node(c->l);\n      c->l->x = Lazy::act(c->l->x, c->a);\n\
    \      c->l->a = Monoid_A::op(c->l->a, c->a);\n      c->l->propagated = 0;\n\n\
    \      c->r = copy_node(c->r);\n      c->r->x = Lazy::act(c->r->x, c->a);\n  \
    \    c->r->a = Monoid_A::op(c->r->a, c->a);\n      c->r->propagated = 0;\n\n \
    \     c->a = Monoid_A::unit();\n      c->propagated = 1;\n    }\n  }\n\n  Node\
    \ *set_rec(Node *c, int node_l, int node_r, int i, const X &x) {\n    if (node_r\
    \ == node_l + 1) { return new_node(x); }\n    c = copy_node(c);\n    prop(c);\n\
    \    int node_m = (node_l + node_r) / 2;\n    if (i < node_m) {\n      c->l =\
    \ set_rec(c->l, node_l, node_m, i, x);\n    } else {\n      c->r = set_rec(c->r,\
    \ node_m, node_r, i, x);\n    }\n    c->x = Monoid_X::op(c->l->x, c->r->x);\n\
    \    return c;\n  }\n\n  void prod_rec(Node *c, int node_l, int node_r, int l,\
    \ int r, X &x) {\n    chmax(l, node_l);\n    chmin(r, node_r);\n    if (l >= r)\
    \ return;\n    if (l == node_l && r == node_r) {\n      x = Monoid_X::op(x, c->x);\n\
    \      return;\n    }\n    prop(c);\n    int node_m = (node_l + node_r) / 2;\n\
    \    prod_rec(c->l, node_l, node_m, l, r, x);\n    prod_rec(c->r, node_m, node_r,\
    \ l, r, x);\n  }\n\n  Node *apply_rec(Node *c, int node_l, int node_r, int l,\
    \ int r, const A &a) {\n    chmax(l, node_l);\n    chmin(r, node_r);\n    if (l\
    \ >= r) return c;\n    if (l == node_l && r == node_r) {\n      c = copy_node(c);\n\
    \      c->x = Lazy::act(c->x, a);\n      c->a = Monoid_A::op(c->a, a);\n     \
    \ return c;\n    }\n    c = copy_node(c);\n    prop(c);\n    int node_m = (node_l\
    \ + node_r) / 2;\n    c->l = apply_rec(c->l, node_l, node_m, l, r, a);\n    c->r\
    \ = apply_rec(c->r, node_m, node_r, l, r, a);\n    c->x = Monoid_X::op(c->l->x,\
    \ c->r->x);\n    return c;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename Lazy, int NODES = 1'000'000>\nstruct Persistent_LazySegTree\
    \ {\n  using Monoid_X = typename Lazy::X_structure;\n  using Monoid_A = typename\
    \ Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n  using A =\
    \ typename Monoid_A::value_type;\n\n  struct Node {\n    Node *l, *r;\n    X x;\n\
    \    A a;\n    bool propagated;\n  };\n\n  const int n;\n  Node *pool;\n  int\
    \ pid;\n\n  Persistent_LazySegTree(int n) : n(n), pid(0) { pool = new Node[NODES];\
    \ }\n\n  Node *new_node(const X &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].x = x;\n    pool[pid].a = Monoid_A::unit();\n    pool[pid].propagated\
    \ = 1;\n    return &(pool[pid++]);\n  }\n\n  Node *new_node(const vc<X> &dat)\
    \ {\n    assert(len(dat) == n);\n    auto dfs = [&](auto &dfs, int l, int r) ->\
    \ Node * {\n      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      int m = (l + r) / 2;\n      Node *l_root = dfs(dfs, l, m);\n      Node\
    \ *r_root = dfs(dfs, m, r);\n      X x = Monoid_X::op(l_root->x, r_root->x);\n\
    \      Node *root = new_node(x);\n      root->l = l_root, root->r = r_root;\n\
    \      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(Node\
    \ *root, int l, int r) {\n    assert(0 <= l && l < r && r <= n);\n    X x = Monoid_X::unit();\n\
    \    prod_rec(root, 0, n, l, r, x);\n    return x;\n  }\n\n  Node *set(Node *root,\
    \ int i, const X &x) {\n    assert(0 <= i && i < n);\n    return set_rec(root,\
    \ 0, n, i, x);\n  }\n\n  Node *apply(Node *root, int l, int r, const A &a) {\n\
    \    assert(0 <= l && l < r && r <= n);\n    return apply_rec(root, 0, n, l, r,\
    \ a);\n  }\n\n  vc<X> restore(Node *root) {\n    vc<X> res;\n    auto dfs = [&](auto\
    \ &dfs, Node *c, int node_l, int node_r) -> void {\n      if (node_r - node_l\
    \ == 1) {\n        res.eb(c->x);\n        return;\n      }\n      int node_m =\
    \ (node_l + node_r) / 2;\n      prop(c);\n      dfs(dfs, c->l, node_l, node_m);\n\
    \      dfs(dfs, c->r, node_m, node_r);\n    };\n    dfs(dfs, root, 0, n);\n  \
    \  return res;\n  }\n\n  void reset() { pid = 0; }\n\nprivate:\n  Node *copy_node(Node\
    \ *n) {\n    if (!n) return nullptr;\n    pool[pid].l = n->l;\n    pool[pid].r\
    \ = n->r;\n    pool[pid].x = n->x;\n    pool[pid].a = n->a;\n    return &(pool[pid++]);\n\
    \  }\n\n  void prop(Node *c) {\n    assert(c->l && c->r);\n    if (!c->propagated)\
    \ {\n      c->l = copy_node(c->l);\n      c->l->x = Lazy::act(c->l->x, c->a);\n\
    \      c->l->a = Monoid_A::op(c->l->a, c->a);\n      c->l->propagated = 0;\n\n\
    \      c->r = copy_node(c->r);\n      c->r->x = Lazy::act(c->r->x, c->a);\n  \
    \    c->r->a = Monoid_A::op(c->r->a, c->a);\n      c->r->propagated = 0;\n\n \
    \     c->a = Monoid_A::unit();\n      c->propagated = 1;\n    }\n  }\n\n  Node\
    \ *set_rec(Node *c, int node_l, int node_r, int i, const X &x) {\n    if (node_r\
    \ == node_l + 1) { return new_node(x); }\n    c = copy_node(c);\n    prop(c);\n\
    \    int node_m = (node_l + node_r) / 2;\n    if (i < node_m) {\n      c->l =\
    \ set_rec(c->l, node_l, node_m, i, x);\n    } else {\n      c->r = set_rec(c->r,\
    \ node_m, node_r, i, x);\n    }\n    c->x = Monoid_X::op(c->l->x, c->r->x);\n\
    \    return c;\n  }\n\n  void prod_rec(Node *c, int node_l, int node_r, int l,\
    \ int r, X &x) {\n    chmax(l, node_l);\n    chmin(r, node_r);\n    if (l >= r)\
    \ return;\n    if (l == node_l && r == node_r) {\n      x = Monoid_X::op(x, c->x);\n\
    \      return;\n    }\n    prop(c);\n    int node_m = (node_l + node_r) / 2;\n\
    \    prod_rec(c->l, node_l, node_m, l, r, x);\n    prod_rec(c->r, node_m, node_r,\
    \ l, r, x);\n  }\n\n  Node *apply_rec(Node *c, int node_l, int node_r, int l,\
    \ int r, const A &a) {\n    chmax(l, node_l);\n    chmin(r, node_r);\n    if (l\
    \ >= r) return c;\n    if (l == node_l && r == node_r) {\n      c = copy_node(c);\n\
    \      c->x = Lazy::act(c->x, a);\n      c->a = Monoid_A::op(c->a, a);\n     \
    \ return c;\n    }\n    c = copy_node(c);\n    prop(c);\n    int node_m = (node_l\
    \ + node_r) / 2;\n    c->l = apply_rec(c->l, node_l, node_m, l, r, a);\n    c->r\
    \ = apply_rec(c->r, node_m, node_r, l, r, a);\n    c->x = Monoid_X::op(c->l->x,\
    \ c->r->x);\n    return c;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: pds/lazysegtree.hpp
  requiredBy: []
  timestamp: '2022-06-19 11:28:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: pds/lazysegtree.hpp
layout: document
redirect_from:
- /library/pds/lazysegtree.hpp
- /library/pds/lazysegtree.hpp.html
title: pds/lazysegtree.hpp
---
