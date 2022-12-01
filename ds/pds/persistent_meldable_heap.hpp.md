---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/shortest_path/K_shortest_walk.hpp
    title: graph/shortest_path/K_shortest_walk.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/K_shortest_walk.test.cpp
    title: test/library_checker/graph/K_shortest_walk.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/pds/persistent_meldable_heap.hpp\"\n\ntemplate <typename\
    \ VAL, int NODES = 5'000'000>\nstruct Persistent_Meldable_Heap {\n  struct Node\
    \ {\n    Node *l, *r;\n    VAL x;\n    int s;\n  };\n\n  Node *pool;\n  int pid;\n\
    \n  Persistent_Meldable_Heap() : pid(0) { pool = new Node[NODES]; }\n\n  Node\
    \ *new_node(const VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x\
    \ = x;\n    pool[pid].s = 1;\n    return &(pool[pid++]);\n  }\n\n  Node *copy_node(Node\
    \ *a) {\n    if (!a) return a;\n    Node *b = new_node(a->x);\n    b->s = a->s;\n\
    \    b->l = a->l;\n    b->r = a->r;\n    return b;\n  }\n\n  Node *meld(Node *a,\
    \ Node *b) {\n    a = copy_node(a);\n    b = copy_node(b);\n    if (!a) return\
    \ b;\n    if (!b) return a;\n    if ((a->x) > (b->x)) swap(a, b);\n    a->r =\
    \ (a->r ? meld(a->r, b) : b);\n    if (!(a->l) || (a->l->s < a->r->s)) swap(a->l,\
    \ a->r);\n    a->s = (a->r ? a->r->s : 0) + 1;\n    return a;\n  }\n\n  Node *push(Node\
    \ *a, VAL x) { return meld(a, new_node(x)); }\n  Node *pop(Node *a) { return meld(a->l,\
    \ a->r); }\n  VAL top(Node *a) { return a->x; }\n\n  vc<VAL> collect(Node *a)\
    \ {\n    vc<VAL> A;\n    auto dfs = [&](auto &dfs, Node *a) -> void {\n      if\
    \ (!a) return;\n      A.eb(a->x);\n      dfs(dfs, a->l);\n      dfs(dfs, a->r);\n\
    \    };\n    dfs(dfs, a);\n    return A;\n  }\n};\n"
  code: "\ntemplate <typename VAL, int NODES = 5'000'000>\nstruct Persistent_Meldable_Heap\
    \ {\n  struct Node {\n    Node *l, *r;\n    VAL x;\n    int s;\n  };\n\n  Node\
    \ *pool;\n  int pid;\n\n  Persistent_Meldable_Heap() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  Node *new_node(const VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].x = x;\n    pool[pid].s = 1;\n    return &(pool[pid++]);\n  }\n\
    \n  Node *copy_node(Node *a) {\n    if (!a) return a;\n    Node *b = new_node(a->x);\n\
    \    b->s = a->s;\n    b->l = a->l;\n    b->r = a->r;\n    return b;\n  }\n\n\
    \  Node *meld(Node *a, Node *b) {\n    a = copy_node(a);\n    b = copy_node(b);\n\
    \    if (!a) return b;\n    if (!b) return a;\n    if ((a->x) > (b->x)) swap(a,\
    \ b);\n    a->r = (a->r ? meld(a->r, b) : b);\n    if (!(a->l) || (a->l->s < a->r->s))\
    \ swap(a->l, a->r);\n    a->s = (a->r ? a->r->s : 0) + 1;\n    return a;\n  }\n\
    \n  Node *push(Node *a, VAL x) { return meld(a, new_node(x)); }\n  Node *pop(Node\
    \ *a) { return meld(a->l, a->r); }\n  VAL top(Node *a) { return a->x; }\n\n  vc<VAL>\
    \ collect(Node *a) {\n    vc<VAL> A;\n    auto dfs = [&](auto &dfs, Node *a) ->\
    \ void {\n      if (!a) return;\n      A.eb(a->x);\n      dfs(dfs, a->l);\n  \
    \    dfs(dfs, a->r);\n    };\n    dfs(dfs, a);\n    return A;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/pds/persistent_meldable_heap.hpp
  requiredBy:
  - graph/shortest_path/K_shortest_walk.hpp
  timestamp: '2022-11-24 17:14:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/K_shortest_walk.test.cpp
documentation_of: ds/pds/persistent_meldable_heap.hpp
layout: document
redirect_from:
- /library/ds/pds/persistent_meldable_heap.hpp
- /library/ds/pds/persistent_meldable_heap.hpp.html
title: ds/pds/persistent_meldable_heap.hpp
---
