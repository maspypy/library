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
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1154.test.cpp
    title: test/3_yukicoder/1154.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1752.test.cpp
    title: test/3_yukicoder/1752.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qoj.ac/contest/1699/problem/8518
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
    };\n\n// \u5168\u4F53\u52A0\u7B97\u304C\u3067\u304D\u308B\u3088\u3046\u306B\u3059\
    \u308B\n// path sum \u304C\u5B9F\u969B\u306E\u5024\u3068\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308C\u3070\u8FFD\u52A0\u30D5\u30A3\u30FC\u30EB\u30C9\u306A\u3057\
    \u306B\u5B9F\u73FE\u3067\u304D\u308B\n// https://qoj.ac/contest/1699/problem/8518\n\
    template <typename VAL, bool PERSISTENT, bool TOP_IS_MIN>\nstruct Lazy_Meldable_Heap\
    \ {\n  struct Node {\n    Node *l, *r;\n    VAL x;\n    u32 size;\n  };\n  Node\
    \ *pool;\n  const int NODES;\n  int pid;\n  using np = Node *;\n\n  Lazy_Meldable_Heap(int\
    \ NODES) : NODES(NODES), pid(0) { pool = new Node[NODES]; }\n  ~Lazy_Meldable_Heap()\
    \ { delete[] pool; }\n  np new_root() { return nullptr; }\n  np new_node(const\
    \ VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = x, pool[pid].size\
    \ = 1;\n    return &(pool[pid++]);\n  }\n  np copy_node(np a) {\n    if (!a ||\
    \ !PERSISTENT) return a;\n    np b = new_node(a->x);\n    b->l = a->l, b->r =\
    \ a->r;\n    b->size = a->size;\n    return b;\n  }\n  np apply(np a, VAL x) {\n\
    \    if (!a) return a;\n    a = copy_node(a);\n    a->x += x;\n    return a;\n\
    \  }\n  np meld(np a, np b, VAL add_a = 0, VAL add_b = 0) {\n    if (!a) { return\
    \ (add_b == 0 ? b : apply(b, add_b)); }\n    if (!b) { return (add_a == 0 ? a\
    \ : apply(a, add_a)); }\n    if constexpr (TOP_IS_MIN) {\n      if ((a->x + add_a)\
    \ > (b->x + add_b)) swap(a, b), swap(add_a, add_b);\n    } else {\n      if ((a->x\
    \ + add_a) < (b->x + add_b)) swap(a, b), swap(add_a, add_b);\n    }\n    a = copy_node(a);\n\
    \    a->x += add_a;\n    a->r = meld(a->r, b, 0, -a->x + add_b);\n    if (!(a->l)\
    \ || (a->l->size < a->r->size)) swap(a->l, a->r);\n    a->size = 1;\n    if (a->l)\
    \ a->size += a->l->size;\n    if (a->r) a->size += a->r->size;\n    return a;\n\
    \  }\n\n  np push(np a, VAL x) { return meld(a, new_node(x)); }\n  np pop(np a)\
    \ { return meld(a->l, a->r, a->x, a->x); }\n  VAL top(np a) { return a->x; }\n\
    \  vc<VAL> get_all(np a) {\n    vc<VAL> A;\n    auto dfs = [&](auto &dfs, np a,\
    \ VAL lazy) -> void {\n      if (!a) return;\n      A.eb(a->x + lazy);\n     \
    \ lazy += a->x;\n      dfs(dfs, a->l, lazy), dfs(dfs, a->r, lazy);\n    };\n \
    \   dfs(dfs, a, 0);\n    sort(all(A));\n    if (!TOP_IS_MIN) reverse(all(A));\n\
    \    return A;\n  }\n};\n"
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
    \    return A;\n  }\n};\n\n// \u5168\u4F53\u52A0\u7B97\u304C\u3067\u304D\u308B\
    \u3088\u3046\u306B\u3059\u308B\n// path sum \u304C\u5B9F\u969B\u306E\u5024\u3068\
    \u306A\u308B\u3088\u3046\u306B\u3059\u308C\u3070\u8FFD\u52A0\u30D5\u30A3\u30FC\
    \u30EB\u30C9\u306A\u3057\u306B\u5B9F\u73FE\u3067\u304D\u308B\n// https://qoj.ac/contest/1699/problem/8518\n\
    template <typename VAL, bool PERSISTENT, bool TOP_IS_MIN>\nstruct Lazy_Meldable_Heap\
    \ {\n  struct Node {\n    Node *l, *r;\n    VAL x;\n    u32 size;\n  };\n  Node\
    \ *pool;\n  const int NODES;\n  int pid;\n  using np = Node *;\n\n  Lazy_Meldable_Heap(int\
    \ NODES) : NODES(NODES), pid(0) { pool = new Node[NODES]; }\n  ~Lazy_Meldable_Heap()\
    \ { delete[] pool; }\n  np new_root() { return nullptr; }\n  np new_node(const\
    \ VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = x, pool[pid].size\
    \ = 1;\n    return &(pool[pid++]);\n  }\n  np copy_node(np a) {\n    if (!a ||\
    \ !PERSISTENT) return a;\n    np b = new_node(a->x);\n    b->l = a->l, b->r =\
    \ a->r;\n    b->size = a->size;\n    return b;\n  }\n  np apply(np a, VAL x) {\n\
    \    if (!a) return a;\n    a = copy_node(a);\n    a->x += x;\n    return a;\n\
    \  }\n  np meld(np a, np b, VAL add_a = 0, VAL add_b = 0) {\n    if (!a) { return\
    \ (add_b == 0 ? b : apply(b, add_b)); }\n    if (!b) { return (add_a == 0 ? a\
    \ : apply(a, add_a)); }\n    if constexpr (TOP_IS_MIN) {\n      if ((a->x + add_a)\
    \ > (b->x + add_b)) swap(a, b), swap(add_a, add_b);\n    } else {\n      if ((a->x\
    \ + add_a) < (b->x + add_b)) swap(a, b), swap(add_a, add_b);\n    }\n    a = copy_node(a);\n\
    \    a->x += add_a;\n    a->r = meld(a->r, b, 0, -a->x + add_b);\n    if (!(a->l)\
    \ || (a->l->size < a->r->size)) swap(a->l, a->r);\n    a->size = 1;\n    if (a->l)\
    \ a->size += a->l->size;\n    if (a->r) a->size += a->r->size;\n    return a;\n\
    \  }\n\n  np push(np a, VAL x) { return meld(a, new_node(x)); }\n  np pop(np a)\
    \ { return meld(a->l, a->r, a->x, a->x); }\n  VAL top(np a) { return a->x; }\n\
    \  vc<VAL> get_all(np a) {\n    vc<VAL> A;\n    auto dfs = [&](auto &dfs, np a,\
    \ VAL lazy) -> void {\n      if (!a) return;\n      A.eb(a->x + lazy);\n     \
    \ lazy += a->x;\n      dfs(dfs, a->l, lazy), dfs(dfs, a->r, lazy);\n    };\n \
    \   dfs(dfs, a, 0);\n    sort(all(A));\n    if (!TOP_IS_MIN) reverse(all(A));\n\
    \    return A;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/meldable_heap.hpp
  requiredBy:
  - graph/shortest_path/K_shortest_walk.hpp
  timestamp: '2024-11-13 18:05:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1752.test.cpp
  - test/3_yukicoder/1154.test.cpp
  - test/2_library_checker/graph/K_shortest_walk.test.cpp
documentation_of: ds/meldable_heap.hpp
layout: document
redirect_from:
- /library/ds/meldable_heap.hpp
- /library/ds/meldable_heap.hpp.html
title: ds/meldable_heap.hpp
---
