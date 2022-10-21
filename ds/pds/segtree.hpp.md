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
  bundledCode: "#line 1 \"ds/pds/segtree.hpp\"\ntemplate <typename Monoid, int NODES>\n\
    struct Persistent_SegTree {\n  using X = typename Monoid::value_type;\n\n  struct\
    \ Node {\n    Node *l, *r;\n    X x;\n  };\n\n  using np = Node *;\n\n  const\
    \ int n;\n  Node *pool;\n  int pid;\n\n  Persistent_SegTree(int n) : n(n), pid(0)\
    \ { pool = new Node[NODES]; }\n\n  Node *new_node(const X x = Monoid::unit())\
    \ {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    return\
    \ &(pool[pid++]);\n  }\n\n  Node *new_node(const vc<X> &dat) {\n    assert(len(dat)\
    \ == n);\n    auto dfs = [&](auto &dfs, int l, int r) -> Node * {\n      if (l\
    \ == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n    \
    \  int m = (l + r) / 2;\n      Node *l_root = dfs(dfs, l, m);\n      Node *r_root\
    \ = dfs(dfs, m, r);\n      X x = Monoid::op(l_root->x, r_root->x);\n      Node\
    \ *root = new_node(x);\n      root->l = l_root, root->r = r_root;\n      return\
    \ root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(Node *root,\
    \ int l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n    X x = Monoid::unit();\n\
    \    prod_rec(root, 0, n, l, r, x);\n    return x;\n  }\n\n  Node *set(Node *root,\
    \ int i, const X &x) {\n    assert(0 <= i && i < n);\n    return set_rec(root,\
    \ 0, n, i, x);\n  }\n\n  vc<X> restore(Node *root) {\n    vc<X> res;\n    auto\
    \ dfs = [&](auto &dfs, Node *c, int node_l, int node_r) -> void {\n      if (node_r\
    \ - node_l == 1) {\n        res.eb(c->x);\n        return;\n      }\n      int\
    \ node_m = (node_l + node_r) / 2;\n      prop(c);\n      dfs(dfs, c->l, node_l,\
    \ node_m);\n      dfs(dfs, c->r, node_m, node_r);\n    };\n    dfs(dfs, root,\
    \ 0, n);\n    return res;\n  }\n\n  void reset() { pid = 0; }\n\nprivate:\n  Node\
    \ *copy_node(Node *n) {\n    if (!n) return nullptr;\n    pool[pid].l = n->l;\n\
    \    pool[pid].r = n->r;\n    pool[pid].x = n->x;\n    return &(pool[pid++]);\n\
    \  }\n\n  Node *set_rec(Node *c, int node_l, int node_r, int i, const X &x) {\n\
    \    if (node_r == node_l + 1) { return new_node(x); }\n    if(!c) c = new_node();\n\
    \    int node_m = (node_l + node_r) / 2;\n    c = copy_node(c);\n    if (i < node_m)\
    \ {\n      c->l = set_rec(c->l, node_l, node_m, i, x);\n    } else {\n      c->r\
    \ = set_rec(c->r, node_m, node_r, i, x);\n    }\n    X xl = (c->l ? c->l->x :\
    \ Monoid::unit());\n    X xr = (c->r ? c->r->x : Monoid::unit());\n    c->x =\
    \ Monoid::op(xl, xr);\n    return c;\n  }\n\n  void prod_rec(Node *c, int node_l,\
    \ int node_r, int l, int r, X &x) {\n    if(!c) return;\n    chmax(l, node_l);\n\
    \    chmin(r, node_r);\n    if (l >= r) return;\n    if (l == node_l && r == node_r)\
    \ {\n      x = Monoid::op(x, c->x);\n      return;\n    }\n    int node_m = (node_l\
    \ + node_r) / 2;\n    prod_rec(c->l, node_l, node_m, l, r, x);\n    prod_rec(c->r,\
    \ node_m, node_r, l, r, x);\n  }\n};\n"
  code: "template <typename Monoid, int NODES>\nstruct Persistent_SegTree {\n  using\
    \ X = typename Monoid::value_type;\n\n  struct Node {\n    Node *l, *r;\n    X\
    \ x;\n  };\n\n  using np = Node *;\n\n  const int n;\n  Node *pool;\n  int pid;\n\
    \n  Persistent_SegTree(int n) : n(n), pid(0) { pool = new Node[NODES]; }\n\n \
    \ Node *new_node(const X x = Monoid::unit()) {\n    pool[pid].l = pool[pid].r\
    \ = nullptr;\n    pool[pid].x = x;\n    return &(pool[pid++]);\n  }\n\n  Node\
    \ *new_node(const vc<X> &dat) {\n    assert(len(dat) == n);\n    auto dfs = [&](auto\
    \ &dfs, int l, int r) -> Node * {\n      if (l == r) return nullptr;\n      if\
    \ (r == l + 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n      Node\
    \ *l_root = dfs(dfs, l, m);\n      Node *r_root = dfs(dfs, m, r);\n      X x =\
    \ Monoid::op(l_root->x, r_root->x);\n      Node *root = new_node(x);\n      root->l\
    \ = l_root, root->r = r_root;\n      return root;\n    };\n    return dfs(dfs,\
    \ 0, len(dat));\n  }\n\n  X prod(Node *root, int l, int r) {\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    X x = Monoid::unit();\n    prod_rec(root, 0, n,\
    \ l, r, x);\n    return x;\n  }\n\n  Node *set(Node *root, int i, const X &x)\
    \ {\n    assert(0 <= i && i < n);\n    return set_rec(root, 0, n, i, x);\n  }\n\
    \n  vc<X> restore(Node *root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs,\
    \ Node *c, int node_l, int node_r) -> void {\n      if (node_r - node_l == 1)\
    \ {\n        res.eb(c->x);\n        return;\n      }\n      int node_m = (node_l\
    \ + node_r) / 2;\n      prop(c);\n      dfs(dfs, c->l, node_l, node_m);\n    \
    \  dfs(dfs, c->r, node_m, node_r);\n    };\n    dfs(dfs, root, 0, n);\n    return\
    \ res;\n  }\n\n  void reset() { pid = 0; }\n\nprivate:\n  Node *copy_node(Node\
    \ *n) {\n    if (!n) return nullptr;\n    pool[pid].l = n->l;\n    pool[pid].r\
    \ = n->r;\n    pool[pid].x = n->x;\n    return &(pool[pid++]);\n  }\n\n  Node\
    \ *set_rec(Node *c, int node_l, int node_r, int i, const X &x) {\n    if (node_r\
    \ == node_l + 1) { return new_node(x); }\n    if(!c) c = new_node();\n    int\
    \ node_m = (node_l + node_r) / 2;\n    c = copy_node(c);\n    if (i < node_m)\
    \ {\n      c->l = set_rec(c->l, node_l, node_m, i, x);\n    } else {\n      c->r\
    \ = set_rec(c->r, node_m, node_r, i, x);\n    }\n    X xl = (c->l ? c->l->x :\
    \ Monoid::unit());\n    X xr = (c->r ? c->r->x : Monoid::unit());\n    c->x =\
    \ Monoid::op(xl, xr);\n    return c;\n  }\n\n  void prod_rec(Node *c, int node_l,\
    \ int node_r, int l, int r, X &x) {\n    if(!c) return;\n    chmax(l, node_l);\n\
    \    chmin(r, node_r);\n    if (l >= r) return;\n    if (l == node_l && r == node_r)\
    \ {\n      x = Monoid::op(x, c->x);\n      return;\n    }\n    int node_m = (node_l\
    \ + node_r) / 2;\n    prod_rec(c->l, node_l, node_m, l, r, x);\n    prod_rec(c->r,\
    \ node_m, node_r, l, r, x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/pds/segtree.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/pds/segtree.hpp
layout: document
redirect_from:
- /library/ds/pds/segtree.hpp
- /library/ds/pds/segtree.hpp.html
title: ds/pds/segtree.hpp
---
