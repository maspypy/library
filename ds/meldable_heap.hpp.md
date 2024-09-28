---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/K_shortest_walk.hpp
    title: graph/shortest_path/K_shortest_walk.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/K_shortest_walk.test.cpp
    title: test/2_library_checker/graph/K_shortest_walk.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1154.test.cpp
    title: test/3_yukicoder/1154.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1752.test.cpp
    title: test/3_yukicoder/1752.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/meldable_heap.hpp\"\n\ntemplate <typename VAL, bool PERSISTENT,\
    \ bool TOP_IS_MIN>\nstruct Meldable_Heap {\n  struct Node {\n    Node *l, *r;\n\
    \    VAL x;\n    u32 size, dist; // dist: leaf \u307E\u3067\u306E\u8DDD\u96E2\n\
    \  };\n  Node *pool;\n  const int NODES;\n  int pid;\n  using np = Node *;\n\n\
    \  Meldable_Heap(int NODES) : NODES(NODES), pid(0) { pool = new Node[NODES]; }\n\
    \  ~Meldable_Heap() { delete[] pool; }\n  np new_root() { return nullptr; }\n\
    \  np new_node(const VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n   \
    \ pool[pid].x = x, pool[pid].size = 1, pool[pid].dist = 1;\n    return &(pool[pid++]);\n\
    \  }\n  np copy_node(np a) {\n    if (!a || !PERSISTENT) return a;\n    np b =\
    \ new_node(a->x);\n    b->l = a->l, b->r = a->r;\n    b->size = a->size, b->dist\
    \ = a->dist;\n    return b;\n  }\n  np meld(np a, np b) {\n    if (!a) return\
    \ b;\n    if (!b) return a;\n    a = copy_node(a);\n    b = copy_node(b);\n  \
    \  if constexpr (TOP_IS_MIN) {\n      if ((a->x) > (b->x)) swap(a, b);\n    }\
    \ else {\n      if ((a->x) < (b->x)) swap(a, b);\n    }\n    a->r = meld(a->r,\
    \ b);\n    if (!(a->l) || (a->l->dist < a->r->dist)) swap(a->l, a->r);\n    a->dist\
    \ = (a->r ? a->r->dist : 0) + 1;\n    a->size = 1;\n    if (a->l) a->size += a->l->size;\n\
    \    if (a->r) a->size += a->r->size;\n    return a;\n  }\n  np push(np a, VAL\
    \ x) { return meld(a, new_node(x)); }\n  np pop(np a) { return meld(a->l, a->r);\
    \ }\n  VAL top(np a) { return a->x; }\n  vc<VAL> get_all(np a) {\n    vc<VAL>\
    \ A;\n    auto dfs = [&](auto &dfs, np a) -> void {\n      if (!a) return;\n \
    \     A.eb(a->x), dfs(dfs, a->l), dfs(dfs, a->r);\n    };\n    dfs(dfs, a);\n\
    \    sort(all(A));\n    if (!TOP_IS_MIN) reverse(all(A));\n    return A;\n  }\n\
    };\n"
  code: "\ntemplate <typename VAL, bool PERSISTENT, bool TOP_IS_MIN>\nstruct Meldable_Heap\
    \ {\n  struct Node {\n    Node *l, *r;\n    VAL x;\n    u32 size, dist; // dist:\
    \ leaf \u307E\u3067\u306E\u8DDD\u96E2\n  };\n  Node *pool;\n  const int NODES;\n\
    \  int pid;\n  using np = Node *;\n\n  Meldable_Heap(int NODES) : NODES(NODES),\
    \ pid(0) { pool = new Node[NODES]; }\n  ~Meldable_Heap() { delete[] pool; }\n\
    \  np new_root() { return nullptr; }\n  np new_node(const VAL &x) {\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = x, pool[pid].size = 1, pool[pid].dist\
    \ = 1;\n    return &(pool[pid++]);\n  }\n  np copy_node(np a) {\n    if (!a ||\
    \ !PERSISTENT) return a;\n    np b = new_node(a->x);\n    b->l = a->l, b->r =\
    \ a->r;\n    b->size = a->size, b->dist = a->dist;\n    return b;\n  }\n  np meld(np\
    \ a, np b) {\n    if (!a) return b;\n    if (!b) return a;\n    a = copy_node(a);\n\
    \    b = copy_node(b);\n    if constexpr (TOP_IS_MIN) {\n      if ((a->x) > (b->x))\
    \ swap(a, b);\n    } else {\n      if ((a->x) < (b->x)) swap(a, b);\n    }\n \
    \   a->r = meld(a->r, b);\n    if (!(a->l) || (a->l->dist < a->r->dist)) swap(a->l,\
    \ a->r);\n    a->dist = (a->r ? a->r->dist : 0) + 1;\n    a->size = 1;\n    if\
    \ (a->l) a->size += a->l->size;\n    if (a->r) a->size += a->r->size;\n    return\
    \ a;\n  }\n  np push(np a, VAL x) { return meld(a, new_node(x)); }\n  np pop(np\
    \ a) { return meld(a->l, a->r); }\n  VAL top(np a) { return a->x; }\n  vc<VAL>\
    \ get_all(np a) {\n    vc<VAL> A;\n    auto dfs = [&](auto &dfs, np a) -> void\
    \ {\n      if (!a) return;\n      A.eb(a->x), dfs(dfs, a->l), dfs(dfs, a->r);\n\
    \    };\n    dfs(dfs, a);\n    sort(all(A));\n    if (!TOP_IS_MIN) reverse(all(A));\n\
    \    return A;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/meldable_heap.hpp
  requiredBy:
  - graph/shortest_path/K_shortest_walk.hpp
  timestamp: '2024-09-09 03:53:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/graph/K_shortest_walk.test.cpp
  - test/3_yukicoder/1154.test.cpp
  - test/3_yukicoder/1752.test.cpp
documentation_of: ds/meldable_heap.hpp
layout: document
redirect_from:
- /library/ds/meldable_heap.hpp
- /library/ds/meldable_heap.hpp.html
title: ds/meldable_heap.hpp
---
