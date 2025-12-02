---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/dynamic_array.hpp
    title: ds/dynamic_array.hpp
  - icon: ':question:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/persistent_unionfind.test.cpp
    title: test/2_library_checker/data_structure/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\n// \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\
    \u30B1\u30FC\u30B9\u306B\u5F31\u3044\u306E\u3067 static \u3067\u78BA\u4FDD\u3059\
    \u308B\u3053\u3068\ntemplate <class Node>\nstruct Node_Pool {\n  struct Slot {\n\
    \    union alignas(Node) {\n      Slot* next;\n      unsigned char storage[sizeof(Node)];\n\
    \    };\n  };\n  using np = Node*;\n\n  static constexpr int CHUNK_SIZE = 1 <<\
    \ 12;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur = nullptr;\n  int cur_used\
    \ = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool() { alloc_chunk(); }\n\n \
    \ template <class... Args>\n  np create(Args&&... args) {\n    Slot* s = new_slot();\n\
    \    return ::new (s) Node(forward<Args>(args)...);\n  }\n\n  np clone(const np\
    \ x) {\n    assert(x);\n    Slot* s = new_slot();\n    return ::new (s) Node(*x);\
    \  // \u30B3\u30D4\u30FC\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u547C\u3073\
    \u51FA\u3057\n  }\n\n  void destroy(np x) {\n    if (!x) return;\n    x->~Node();\n\
    \    auto s = reinterpret_cast<Slot*>(x);\n    s->next = free_head;\n    free_head\
    \ = s;\n  }\n\n  void reset() {\n    free_head = nullptr;\n    if (!chunks.empty())\
    \ {\n      cur = chunks[0].get();\n      cur_used = 0;\n    }\n  }\n\n private:\n\
    \  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n#line 3 \"ds/dynamic_array.hpp\"\n\r\ntemplate <typename\
    \ T, bool PERSISTENT>\r\nstruct Dynamic_Array {\r\n  static constexpr int LOG\
    \ = 4;\r\n  static constexpr int MASK = (1 << LOG) - 1;\r\n  struct Node {\r\n\
    \    T x;\r\n    Node* ch[1 << LOG] = {};\r\n  };\r\n  Node_Pool<Node> pool;\r\
    \n  using np = Node*;\r\n  const T x0;\r\n\r\n  Dynamic_Array(int NODES, T default_value)\
    \ : x0(default_value) {}\r\n  np new_root() {\r\n    np c = pool.create();\r\n\
    \    c->x = x0;\r\n    fill(c->ch, c->ch + (1 << LOG), nullptr);\r\n    return\
    \ c;\r\n  }\r\n\r\n  np new_node(vc<T> dat) {\r\n    np root = new_root();\r\n\
    \    FOR(i, len(dat)) root = set(root, i, dat[i], false);\r\n    return root;\r\
    \n  }\r\n\r\n  T get(np c, int idx) {\r\n    if (!c) return x0;\r\n    if (idx\
    \ == 0) return c->x;\r\n    return get(c->ch[idx & MASK], (idx - 1) >> LOG);\r\
    \n  }\r\n\r\n  np set(np c, int idx, T x, bool make_copy = true) {\r\n    c =\
    \ (c ? clone(c, make_copy) : new_root());\r\n    if (idx == 0) {\r\n      c->x\
    \ = x;\r\n      return c;\r\n    }\r\n    c->ch[idx & MASK] = set(c->ch[idx &\
    \ MASK], (idx - 1) >> LOG, x);\r\n    return c;\r\n  }\r\n\r\n private:\r\n  np\
    \ clone(np c, bool make_copy) {\r\n    if (!make_copy || !PERSISTENT) return c;\r\
    \n    return pool.clone(c);\r\n  }\r\n};\r\n#line 2 \"ds/unionfind/dynamic_unionfind.hpp\"\
    \n\r\ntemplate <bool PERSISTENT>\r\nstruct Dynamic_UnionFind {\r\n  // \u7D4C\u8DEF\
    \u5727\u7E2E\u306A\u3057\r\n  Dynamic_Array<int, PERSISTENT> PA;\r\n  using np\
    \ = typename decltype(PA)::np;\r\n\r\n  Dynamic_UnionFind(int N) : PA(15 * N,\
    \ -1) {}\r\n\r\n  np new_root() { return PA.new_root(); }\r\n\r\n  int root(np\
    \ c, int x) {\r\n    while (1) {\r\n      int p = PA.get(c, x);\r\n      assert(x\
    \ != p);\r\n      if (p < 0) break;\r\n      x = p;\r\n    }\r\n    return x;\r\
    \n  }\r\n\r\n  pair<np, bool> merge(np c, int x, int y) {\r\n    x = root(c, x),\
    \ y = root(c, y);\r\n    if (x == y) return {c, false};\r\n    if (-PA.get(c,\
    \ x) < -PA.get(c, y)) swap(x, y);\r\n    int new_sz = PA.get(c, x) + PA.get(c,\
    \ y);\r\n    c = PA.set(c, x, new_sz);\r\n    assert(PA.get(c, x) == new_sz);\r\
    \n    c = PA.set(c, y, x);\r\n    assert(PA.get(c, y) == x);\r\n    return {c,\
    \ true};\r\n  }\r\n\r\n  ll size(np c, int x) { return -PA.get(c, root(c, x));\
    \ }\r\n};\r\n"
  code: "#include \"ds/dynamic_array.hpp\"\r\n\r\ntemplate <bool PERSISTENT>\r\nstruct\
    \ Dynamic_UnionFind {\r\n  // \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\r\n  Dynamic_Array<int,\
    \ PERSISTENT> PA;\r\n  using np = typename decltype(PA)::np;\r\n\r\n  Dynamic_UnionFind(int\
    \ N) : PA(15 * N, -1) {}\r\n\r\n  np new_root() { return PA.new_root(); }\r\n\r\
    \n  int root(np c, int x) {\r\n    while (1) {\r\n      int p = PA.get(c, x);\r\
    \n      assert(x != p);\r\n      if (p < 0) break;\r\n      x = p;\r\n    }\r\n\
    \    return x;\r\n  }\r\n\r\n  pair<np, bool> merge(np c, int x, int y) {\r\n\
    \    x = root(c, x), y = root(c, y);\r\n    if (x == y) return {c, false};\r\n\
    \    if (-PA.get(c, x) < -PA.get(c, y)) swap(x, y);\r\n    int new_sz = PA.get(c,\
    \ x) + PA.get(c, y);\r\n    c = PA.set(c, x, new_sz);\r\n    assert(PA.get(c,\
    \ x) == new_sz);\r\n    c = PA.set(c, y, x);\r\n    assert(PA.get(c, y) == x);\r\
    \n    return {c, true};\r\n  }\r\n\r\n  ll size(np c, int x) { return -PA.get(c,\
    \ root(c, x)); }\r\n};\r\n"
  dependsOn:
  - ds/dynamic_array.hpp
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/unionfind/dynamic_unionfind.hpp
  requiredBy: []
  timestamp: '2025-11-18 00:27:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/persistent_unionfind.test.cpp
documentation_of: ds/unionfind/dynamic_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/dynamic_unionfind.hpp
- /library/ds/unionfind/dynamic_unionfind.hpp.html
title: ds/unionfind/dynamic_unionfind.hpp
---
