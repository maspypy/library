---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/dynamic_array.hpp
    title: ds/dynamic_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/persistent_unionfind.test.cpp
    title: test/library_checker/datastructure/persistent_unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \n  }\r\n};\r\n#line 2 \"ds/unionfind/dynamic_unionfind.hpp\"\n\r\ntemplate <bool\
    \ PERSISTENT, int NODES>\r\nstruct Dynamic_UnionFind {\r\n  // \u7D4C\u8DEF\u5727\
    \u7E2E\u306A\u3057\r\n  Dynamic_Array<int, PERSISTENT, NODES> PA;\r\n  using np\
    \ = typename decltype(PA)::np;\r\n\r\n  Dynamic_UnionFind() : PA(-1) {}\r\n\r\n\
    \  np new_node() { return PA.new_node(); }\r\n\r\n  int root(np c, int x) {\r\n\
    \    while (1) {\r\n      int p = PA.get(c, x);\r\n      assert(x != p);\r\n \
    \     if (p < 0) break;\r\n      x = p;\r\n    }\r\n    return x;\r\n  }\r\n\r\
    \n  pair<np, bool> merge(np c, int x, int y) {\r\n    x = root(c, x), y = root(c,\
    \ y);\r\n    if (x == y) return {false, c};\r\n    if (-PA.get(c, x) < -PA.get(c,\
    \ y)) swap(x, y);\r\n    int new_sz = PA.get(c, x) + PA.get(c, y);\r\n    c =\
    \ PA.set(c, x, new_sz);\r\n    assert(PA.get(c, x) == new_sz);\r\n    c = PA.set(c,\
    \ y, x);\r\n    assert(PA.get(c, y) == x);\r\n    return {true, c};\r\n  }\r\n\
    \r\n  int size(np c, int x) { return -PA.get(c, root(c, x)); }\r\n};\r\n"
  code: "#include \"ds/dynamic_array.hpp\"\r\n\r\ntemplate <bool PERSISTENT, int NODES>\r\
    \nstruct Dynamic_UnionFind {\r\n  // \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\r\n\
    \  Dynamic_Array<int, PERSISTENT, NODES> PA;\r\n  using np = typename decltype(PA)::np;\r\
    \n\r\n  Dynamic_UnionFind() : PA(-1) {}\r\n\r\n  np new_node() { return PA.new_node();\
    \ }\r\n\r\n  int root(np c, int x) {\r\n    while (1) {\r\n      int p = PA.get(c,\
    \ x);\r\n      assert(x != p);\r\n      if (p < 0) break;\r\n      x = p;\r\n\
    \    }\r\n    return x;\r\n  }\r\n\r\n  pair<np, bool> merge(np c, int x, int\
    \ y) {\r\n    x = root(c, x), y = root(c, y);\r\n    if (x == y) return {false,\
    \ c};\r\n    if (-PA.get(c, x) < -PA.get(c, y)) swap(x, y);\r\n    int new_sz\
    \ = PA.get(c, x) + PA.get(c, y);\r\n    c = PA.set(c, x, new_sz);\r\n    assert(PA.get(c,\
    \ x) == new_sz);\r\n    c = PA.set(c, y, x);\r\n    assert(PA.get(c, y) == x);\r\
    \n    return {true, c};\r\n  }\r\n\r\n  int size(np c, int x) { return -PA.get(c,\
    \ root(c, x)); }\r\n};\r\n"
  dependsOn:
  - ds/dynamic_array.hpp
  isVerificationFile: false
  path: ds/unionfind/dynamic_unionfind.hpp
  requiredBy: []
  timestamp: '2022-12-05 10:41:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/persistent_unionfind.test.cpp
documentation_of: ds/unionfind/dynamic_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/dynamic_unionfind.hpp
- /library/ds/unionfind/dynamic_unionfind.hpp.html
title: ds/unionfind/dynamic_unionfind.hpp
---
