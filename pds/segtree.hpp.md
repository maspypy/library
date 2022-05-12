---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/uniqueproductquery.hpp
    title: ds/uniqueproductquery.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_pseg.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_pseg.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"pds/segtree.hpp\"\ntemplate <class Monoid, int NODES = 20000000>\n\
    struct PersistentSegTree {\n  using X = typename Monoid::value_type;\n  using\
    \ value_type = X;\n\n  struct Node {\n    X x;\n    Node *lch, *rch;\n    Node()\
    \ {}\n    Node(const X &x) : x(x), lch(nullptr), rch(nullptr) {}\n  };\n\n  Node\
    \ *pool;\n  int pid;\n  ll n;\n  Node *nil;\n  vc<Node *> roots;\n\n  PersistentSegTree(int\
    \ n) : pid(0), n(n), nil(nullptr) {\n    pool = new Node[NODES];\n    nil = new_node(Monoid::unit());\n\
    \    nil->lch = nil->rch = nil;\n    roots.reserve(1 << 18);\n    roots.push_back(nil);\n\
    \  }\n\nprivate:\n  Node *new_node(const X &x) {\n    pool[pid].x = x;\n    pool[pid].lch\
    \ = pool[pid].rch = nil;\n    return &(pool[pid++]);\n  }\n\n  Node *merge(Node\
    \ *l, Node *r) {\n    pool[pid].x = Monoid::op(l->x, r->x);\n    pool[pid].lch\
    \ = l;\n    pool[pid].rch = r;\n    return &(pool[pid++]);\n  }\n\n  Node *set(ll\
    \ idx, const X &x, Node *n, ll l, ll r) {\n    if (l + 1 == r) return new_node(x);\n\
    \    ll m = (l + r) / 2;\n    if (idx < m) return merge(set(idx, x, n->lch, l,\
    \ m), n->rch);\n    return merge(n->lch, set(idx, x, n->rch, m, r));\n  }\n\n\
    \  X prod(ll a, ll b, Node *n, ll l, ll r) {\n    if (n == nil) return Monoid::unit();\n\
    \    if (r <= a || b <= l) return Monoid::unit();\n    if (a <= l && r <= b) return\
    \ n->x;\n    ll m = (l + r) / 2;\n    return Monoid::op(prod(a, b, n->lch, l,\
    \ m), prod(a, b, n->rch, m, r));\n  }\n\npublic:\n  int time() { return len(roots)\
    \ - 1; }\n\n  int set(int t, ll idx, const X &x) {\n    Node *root = set(idx,\
    \ x, roots[t], 0, n);\n    roots.eb(root);\n    return time();\n  }\n\n  X prod(int\
    \ time, ll l, ll r) { return prod(l, r, roots[time], 0, n); }\n};\n"
  code: "#pragma once\ntemplate <class Monoid, int NODES = 20000000>\nstruct PersistentSegTree\
    \ {\n  using X = typename Monoid::value_type;\n  using value_type = X;\n\n  struct\
    \ Node {\n    X x;\n    Node *lch, *rch;\n    Node() {}\n    Node(const X &x)\
    \ : x(x), lch(nullptr), rch(nullptr) {}\n  };\n\n  Node *pool;\n  int pid;\n \
    \ ll n;\n  Node *nil;\n  vc<Node *> roots;\n\n  PersistentSegTree(int n) : pid(0),\
    \ n(n), nil(nullptr) {\n    pool = new Node[NODES];\n    nil = new_node(Monoid::unit());\n\
    \    nil->lch = nil->rch = nil;\n    roots.reserve(1 << 18);\n    roots.push_back(nil);\n\
    \  }\n\nprivate:\n  Node *new_node(const X &x) {\n    pool[pid].x = x;\n    pool[pid].lch\
    \ = pool[pid].rch = nil;\n    return &(pool[pid++]);\n  }\n\n  Node *merge(Node\
    \ *l, Node *r) {\n    pool[pid].x = Monoid::op(l->x, r->x);\n    pool[pid].lch\
    \ = l;\n    pool[pid].rch = r;\n    return &(pool[pid++]);\n  }\n\n  Node *set(ll\
    \ idx, const X &x, Node *n, ll l, ll r) {\n    if (l + 1 == r) return new_node(x);\n\
    \    ll m = (l + r) / 2;\n    if (idx < m) return merge(set(idx, x, n->lch, l,\
    \ m), n->rch);\n    return merge(n->lch, set(idx, x, n->rch, m, r));\n  }\n\n\
    \  X prod(ll a, ll b, Node *n, ll l, ll r) {\n    if (n == nil) return Monoid::unit();\n\
    \    if (r <= a || b <= l) return Monoid::unit();\n    if (a <= l && r <= b) return\
    \ n->x;\n    ll m = (l + r) / 2;\n    return Monoid::op(prod(a, b, n->lch, l,\
    \ m), prod(a, b, n->rch, m, r));\n  }\n\npublic:\n  int time() { return len(roots)\
    \ - 1; }\n\n  int set(int t, ll idx, const X &x) {\n    Node *root = set(idx,\
    \ x, roots[t], 0, n);\n    roots.eb(root);\n    return time();\n  }\n\n  X prod(int\
    \ time, ll l, ll r) { return prod(l, r, roots[time], 0, n); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: pds/segtree.hpp
  requiredBy:
  - ds/uniqueproductquery.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/range_kth_smallest_pseg.test.cpp
documentation_of: pds/segtree.hpp
layout: document
redirect_from:
- /library/pds/segtree.hpp
- /library/pds/segtree.hpp.html
title: pds/segtree.hpp
---
