---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/dynamic_unionfind.hpp
    title: ds/unionfind/dynamic_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc273_e.test.cpp
    title: test/atcoder/abc273_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/persistent_queue.test.cpp
    title: test/library_checker/datastructure/persistent_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/persistent_unionfind.test.cpp
    title: test/library_checker/datastructure/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/dynamic_array.hpp\"\n\r\ntemplate <typename T, bool PERSISTENT,\
    \ int NODES>\r\nstruct Dynamic_Array {\r\n  struct Node {\r\n    T x;\r\n    Node*\
    \ ch[16] = {};\r\n  };\r\n  Node* pool;\r\n  int pid;\r\n  using np = Node*;\r\
    \n  const T x0;\r\n\r\n  Dynamic_Array(T default_value) : pid(0), x0(default_value)\
    \ {\r\n    pool = new Node[NODES];\r\n  }\r\n\r\n  np new_node() {\r\n    pool[pid].x\
    \ = x0;\r\n    fill(pool[pid].ch, pool[pid].ch + 16, nullptr);\r\n    return &(pool[pid++]);\r\
    \n  }\r\n\r\n  np new_node(vc<T> dat) {\r\n    np root = new_node();\r\n    FOR(i,\
    \ len(dat)) root = set(root, i, dat[i], false);\r\n    return root;\r\n  }\r\n\
    \r\n  T get(np c, int idx) {\r\n    if (!c) return x0;\r\n    if (idx == 0) return\
    \ c->x;\r\n    return get(c->ch[idx & 15], (idx - 1) >> 4);\r\n  }\r\n\r\n  np\
    \ set(np c, int idx, T x, bool make_copy = true) {\r\n    c = (c ? copy_node(c,\
    \ make_copy) : new_node());\r\n    if (idx == 0) {\r\n      c->x = x;\r\n    \
    \  return c;\r\n    }\r\n    c->ch[idx & 15] = set(c->ch[idx & 15], (idx - 1)\
    \ >> 4, x);\r\n    return c;\r\n  }\r\n\r\nprivate:\r\n  np copy_node(np c, bool\
    \ make_copy) {\r\n    if (!make_copy || !PERSISTENT) return c;\r\n    pool[pid].x\
    \ = c->x;\r\n    FOR(k, 16) pool[pid].ch[k] = c->ch[k];\r\n    return &(pool[pid++]);\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, bool PERSISTENT, int NODES>\r\n\
    struct Dynamic_Array {\r\n  struct Node {\r\n    T x;\r\n    Node* ch[16] = {};\r\
    \n  };\r\n  Node* pool;\r\n  int pid;\r\n  using np = Node*;\r\n  const T x0;\r\
    \n\r\n  Dynamic_Array(T default_value) : pid(0), x0(default_value) {\r\n    pool\
    \ = new Node[NODES];\r\n  }\r\n\r\n  np new_node() {\r\n    pool[pid].x = x0;\r\
    \n    fill(pool[pid].ch, pool[pid].ch + 16, nullptr);\r\n    return &(pool[pid++]);\r\
    \n  }\r\n\r\n  np new_node(vc<T> dat) {\r\n    np root = new_node();\r\n    FOR(i,\
    \ len(dat)) root = set(root, i, dat[i], false);\r\n    return root;\r\n  }\r\n\
    \r\n  T get(np c, int idx) {\r\n    if (!c) return x0;\r\n    if (idx == 0) return\
    \ c->x;\r\n    return get(c->ch[idx & 15], (idx - 1) >> 4);\r\n  }\r\n\r\n  np\
    \ set(np c, int idx, T x, bool make_copy = true) {\r\n    c = (c ? copy_node(c,\
    \ make_copy) : new_node());\r\n    if (idx == 0) {\r\n      c->x = x;\r\n    \
    \  return c;\r\n    }\r\n    c->ch[idx & 15] = set(c->ch[idx & 15], (idx - 1)\
    \ >> 4, x);\r\n    return c;\r\n  }\r\n\r\nprivate:\r\n  np copy_node(np c, bool\
    \ make_copy) {\r\n    if (!make_copy || !PERSISTENT) return c;\r\n    pool[pid].x\
    \ = c->x;\r\n    FOR(k, 16) pool[pid].ch[k] = c->ch[k];\r\n    return &(pool[pid++]);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dynamic_array.hpp
  requiredBy:
  - ds/unionfind/dynamic_unionfind.hpp
  timestamp: '2022-12-05 10:24:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/persistent_unionfind.test.cpp
  - test/library_checker/datastructure/persistent_queue.test.cpp
  - test/atcoder/abc273_e.test.cpp
documentation_of: ds/dynamic_array.hpp
layout: document
redirect_from:
- /library/ds/dynamic_array.hpp
- /library/ds/dynamic_array.hpp.html
title: ds/dynamic_array.hpp
---
