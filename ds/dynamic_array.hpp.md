---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/unionfind/dynamic_unionfind.hpp
    title: ds/unionfind/dynamic_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/persistent_queue.test.cpp
    title: test/2_library_checker/data_structure/persistent_queue.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/persistent_unionfind.test.cpp
    title: test/2_library_checker/data_structure/persistent_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc273_e.test.cpp
    title: test/5_atcoder/abc273_e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/dynamic_array.hpp\"\n\r\ntemplate <typename T, bool PERSISTENT>\r\
    \nstruct Dynamic_Array {\r\n  static constexpr int LOG = 4;\r\n  static constexpr\
    \ int MASK = (1 << LOG) - 1;\r\n  struct Node {\r\n    T x;\r\n    Node* ch[1\
    \ << LOG] = {};\r\n  };\r\n  const int NODES;\r\n  Node* pool;\r\n  int pid;\r\
    \n  using np = Node*;\r\n  const T x0;\r\n\r\n  Dynamic_Array(int NODES, T default_value)\
    \ : NODES(NODES), pid(0), x0(default_value) { pool = new Node[NODES]; }\r\n  ~Dynamic_Array()\
    \ { delete[] pool; }\r\n  np new_root() {\r\n    pool[pid].x = x0;\r\n    fill(pool[pid].ch,\
    \ pool[pid].ch + (1 << LOG), nullptr);\r\n    return &(pool[pid++]);\r\n  }\r\n\
    \r\n  np new_node(vc<T> dat) {\r\n    np root = new_root();\r\n    FOR(i, len(dat))\
    \ root = set(root, i, dat[i], false);\r\n    return root;\r\n  }\r\n\r\n  T get(np\
    \ c, int idx) {\r\n    if (!c) return x0;\r\n    if (idx == 0) return c->x;\r\n\
    \    return get(c->ch[idx & MASK], (idx - 1) >> LOG);\r\n  }\r\n\r\n  np set(np\
    \ c, int idx, T x, bool make_copy = true) {\r\n    c = (c ? copy_node(c, make_copy)\
    \ : new_root());\r\n    if (idx == 0) {\r\n      c->x = x;\r\n      return c;\r\
    \n    }\r\n    c->ch[idx & MASK] = set(c->ch[idx & MASK], (idx - 1) >> LOG, x);\r\
    \n    return c;\r\n  }\r\n\r\nprivate:\r\n  np copy_node(np c, bool make_copy)\
    \ {\r\n    if (!make_copy || !PERSISTENT) return c;\r\n    pool[pid].x = c->x;\r\
    \n    FOR(k, (1 << LOG)) pool[pid].ch[k] = c->ch[k];\r\n    return &(pool[pid++]);\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, bool PERSISTENT>\r\nstruct Dynamic_Array\
    \ {\r\n  static constexpr int LOG = 4;\r\n  static constexpr int MASK = (1 <<\
    \ LOG) - 1;\r\n  struct Node {\r\n    T x;\r\n    Node* ch[1 << LOG] = {};\r\n\
    \  };\r\n  const int NODES;\r\n  Node* pool;\r\n  int pid;\r\n  using np = Node*;\r\
    \n  const T x0;\r\n\r\n  Dynamic_Array(int NODES, T default_value) : NODES(NODES),\
    \ pid(0), x0(default_value) { pool = new Node[NODES]; }\r\n  ~Dynamic_Array()\
    \ { delete[] pool; }\r\n  np new_root() {\r\n    pool[pid].x = x0;\r\n    fill(pool[pid].ch,\
    \ pool[pid].ch + (1 << LOG), nullptr);\r\n    return &(pool[pid++]);\r\n  }\r\n\
    \r\n  np new_node(vc<T> dat) {\r\n    np root = new_root();\r\n    FOR(i, len(dat))\
    \ root = set(root, i, dat[i], false);\r\n    return root;\r\n  }\r\n\r\n  T get(np\
    \ c, int idx) {\r\n    if (!c) return x0;\r\n    if (idx == 0) return c->x;\r\n\
    \    return get(c->ch[idx & MASK], (idx - 1) >> LOG);\r\n  }\r\n\r\n  np set(np\
    \ c, int idx, T x, bool make_copy = true) {\r\n    c = (c ? copy_node(c, make_copy)\
    \ : new_root());\r\n    if (idx == 0) {\r\n      c->x = x;\r\n      return c;\r\
    \n    }\r\n    c->ch[idx & MASK] = set(c->ch[idx & MASK], (idx - 1) >> LOG, x);\r\
    \n    return c;\r\n  }\r\n\r\nprivate:\r\n  np copy_node(np c, bool make_copy)\
    \ {\r\n    if (!make_copy || !PERSISTENT) return c;\r\n    pool[pid].x = c->x;\r\
    \n    FOR(k, (1 << LOG)) pool[pid].ch[k] = c->ch[k];\r\n    return &(pool[pid++]);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dynamic_array.hpp
  requiredBy:
  - ds/unionfind/dynamic_unionfind.hpp
  timestamp: '2024-09-09 03:53:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/5_atcoder/abc273_e.test.cpp
  - test/2_library_checker/data_structure/persistent_unionfind.test.cpp
  - test/2_library_checker/data_structure/persistent_queue.test.cpp
documentation_of: ds/dynamic_array.hpp
layout: document
redirect_from:
- /library/ds/dynamic_array.hpp
- /library/ds/dynamic_array.hpp.html
title: ds/dynamic_array.hpp
---
