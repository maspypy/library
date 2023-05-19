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
  bundledCode: "#line 1 \"ds/meldable_heap.hpp\"\n\ntemplate <typename VAL, bool PERSISTENT,\
    \ int NODES>\nstruct Meldable_Heap {\n  struct Node {\n    Node *l, *r;\n    VAL\
    \ x;\n    int s;\n  };\n  Node *pool;\n  int pid;\n  using np = Node *;\n\n  Meldable_Heap()\
    \ : pid(0) { pool = new Node[NODES]; }\n\n  np new_node(const VAL &x) {\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    pool[pid].s = 1;\n    return\
    \ &(pool[pid++]);\n  }\n  np copy_node(np a) {\n    if (!a || !PERSISTENT) return\
    \ a;\n    np b = new_node(a->x);\n    b->s = a->s;\n    b->l = a->l;\n    b->r\
    \ = a->r;\n    return b;\n  }\n  np meld(np a, np b) {\n    if (!a) return b;\n\
    \    if (!b) return a;\n    a = copy_node(a);\n    b = copy_node(b);\n    if ((a->x)\
    \ > (b->x)) swap(a, b);\n    a->r = (a->r ? meld(a->r, b) : b);\n    if (!(a->l)\
    \ || (a->l->s < a->r->s)) swap(a->l, a->r);\n    a->s = (a->r ? a->r->s : 0) +\
    \ 1;\n    return a;\n  }\n  np push(np a, VAL x) { return meld(a, new_node(x));\
    \ }\n  np pop(np a) { return meld(a->l, a->r); }\n  VAL top(np a) { return a->x;\
    \ }\n  vc<VAL> get_all(np a) {\n    vc<VAL> A;\n    auto dfs = [&](auto &dfs,\
    \ np a) -> void {\n      if (!a) return;\n      A.eb(a->x);\n      dfs(dfs, a->l);\n\
    \      dfs(dfs, a->r);\n    };\n    dfs(dfs, a);\n    return A;\n  }\n};\n"
  code: "\ntemplate <typename VAL, bool PERSISTENT, int NODES>\nstruct Meldable_Heap\
    \ {\n  struct Node {\n    Node *l, *r;\n    VAL x;\n    int s;\n  };\n  Node *pool;\n\
    \  int pid;\n  using np = Node *;\n\n  Meldable_Heap() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  np new_node(const VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].x = x;\n    pool[pid].s = 1;\n    return &(pool[pid++]);\n  }\n\
    \  np copy_node(np a) {\n    if (!a || !PERSISTENT) return a;\n    np b = new_node(a->x);\n\
    \    b->s = a->s;\n    b->l = a->l;\n    b->r = a->r;\n    return b;\n  }\n  np\
    \ meld(np a, np b) {\n    if (!a) return b;\n    if (!b) return a;\n    a = copy_node(a);\n\
    \    b = copy_node(b);\n    if ((a->x) > (b->x)) swap(a, b);\n    a->r = (a->r\
    \ ? meld(a->r, b) : b);\n    if (!(a->l) || (a->l->s < a->r->s)) swap(a->l, a->r);\n\
    \    a->s = (a->r ? a->r->s : 0) + 1;\n    return a;\n  }\n  np push(np a, VAL\
    \ x) { return meld(a, new_node(x)); }\n  np pop(np a) { return meld(a->l, a->r);\
    \ }\n  VAL top(np a) { return a->x; }\n  vc<VAL> get_all(np a) {\n    vc<VAL>\
    \ A;\n    auto dfs = [&](auto &dfs, np a) -> void {\n      if (!a) return;\n \
    \     A.eb(a->x);\n      dfs(dfs, a->l);\n      dfs(dfs, a->r);\n    };\n    dfs(dfs,\
    \ a);\n    return A;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/meldable_heap.hpp
  requiredBy:
  - graph/shortest_path/K_shortest_walk.hpp
  timestamp: '2022-12-05 07:09:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/K_shortest_walk.test.cpp
documentation_of: ds/meldable_heap.hpp
layout: document
redirect_from:
- /library/ds/meldable_heap.hpp
- /library/ds/meldable_heap.hpp.html
title: ds/meldable_heap.hpp
---
