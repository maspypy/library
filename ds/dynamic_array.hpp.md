---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/dynamic_unionfind.hpp
    title: ds/unionfind/dynamic_unionfind.hpp
  - icon: ':warning:'
    path: string/aho_corasick_for_general_trie.hpp
    title: string/aho_corasick_for_general_trie.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/persistent_queue.test.cpp
    title: test/2_library_checker/data_structure/persistent_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/persistent_unionfind.test.cpp
    title: test/2_library_checker/data_structure/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\n// \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\
    \u30B1\u30FC\u30B9\u3067\u3082\u78BA\u4FDD\u6E08\u307F chunk \u3092\u518D\u5229\
    \u7528\u3059\u308B\ntemplate <class Node>\nstruct Node_Pool {\n  union Slot {\n\
    \    Node node;\n    Slot* next;\n\n    Slot() {}\n    ~Slot() {}\n  };\n  using\
    \ np = Node*;\n\n  static constexpr int CHUNK_SIZE = 1 << 12;\n\n  vc<unique_ptr<Slot[]>>\
    \ chunks;\n  int chunk_id = 0;\n  int pos = 0;\n  Slot* free_head = nullptr;\n\
    \n  ~Node_Pool() {\n    auto& cache = chunk_cache();\n    for (auto& p : chunks)\
    \ cache.eb(std::move(p));\n  }\n\n  template <class... Args>\n  np create(Args&&...\
    \ args) {\n    Slot* s = new_slot();\n    return ::new (&s->node) Node(forward<Args>(args)...);\n\
    \  }\n\n  np clone(const np x) {\n    assert(x);\n    Slot* s = new_slot();\n\
    \    return ::new (&s->node) Node(*x);\n  }\n\n  void destroy(np x) {\n    if\
    \ (!x) return;\n    x->~Node();\n    Slot* s = reinterpret_cast<Slot*>(x);\n \
    \   s->next = free_head;\n    free_head = s;\n  }\n\n  // \u5168 node \u3092\u7121\
    \u52B9\u5316\u3059\u308B\u3002\n  // \u78BA\u4FDD\u6E08\u307F chunk \u306F\u89E3\
    \u653E\u305B\u305A\u3001\u6B21\u56DE\u4EE5\u964D\u306B\u518D\u5229\u7528\u3059\
    \u308B\u3002\n  void reset() {\n    free_head = nullptr;\n    chunk_id = 0;\n\
    \    pos = 0;\n  }\n\n private:\n  static vc<unique_ptr<Slot[]>>& chunk_cache()\
    \ {\n    // static Node_Pool \u306E destructor \u3088\u308A\u5148\u306B\u7834\u68C4\
    \u3055\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u3002\n    static auto*\
    \ cache = new vc<unique_ptr<Slot[]>>();\n    return *cache;\n  }\n\n  void alloc_chunk()\
    \ {\n    auto& cache = chunk_cache();\n    if (cache.empty()) {\n      chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    } else {\n      chunks.eb(std::move(cache.back()));\n      cache.pop_back();\n\
    \    }\n  }\n\n  Slot* new_slot() {\n    if (free_head) {\n      Slot* s = free_head;\n\
    \      free_head = free_head->next;\n      return s;\n    }\n\n    if (chunk_id\
    \ == len(chunks)) alloc_chunk();\n\n    Slot* s = &chunks[chunk_id][pos++];\n\
    \    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n      pos = 0;\n    }\n    return\
    \ s;\n  }\n};\n#line 2 \"ds/dynamic_array.hpp\"\n\ntemplate <typename T, bool\
    \ PERSISTENT>\nstruct Dynamic_Array {\n  static constexpr int LOG = 4;\n  static\
    \ constexpr int MASK = (1 << LOG) - 1;\n  struct Node {\n    T x;\n    Node* ch[1\
    \ << LOG] = {};\n  };\n  Node_Pool<Node> pool;\n  using np = Node*;\n  const T\
    \ x0;\n\n  Dynamic_Array(int NODES, T default_value) : x0(default_value) {}\n\
    \  np new_root() {\n    np c = pool.create();\n    c->x = x0;\n    fill(c->ch,\
    \ c->ch + (1 << LOG), nullptr);\n    return c;\n  }\n\n  np new_node(vc<T> dat)\
    \ {\n    np root = new_root();\n    FOR(i, len(dat)) root = set(root, i, dat[i],\
    \ false);\n    return root;\n  }\n\n  T get(np c, int idx) {\n    if (!c) return\
    \ x0;\n    if (idx == 0) return c->x;\n    return get(c->ch[idx & MASK], (idx\
    \ - 1) >> LOG);\n  }\n\n  np set(np c, int idx, T x, bool make_copy = true) {\n\
    \    c = (c ? clone(c, make_copy) : new_root());\n    if (idx == 0) {\n      c->x\
    \ = x;\n      return c;\n    }\n    c->ch[idx & MASK] = set(c->ch[idx & MASK],\
    \ (idx - 1) >> LOG, x);\n    return c;\n  }\n\n private:\n  np clone(np c, bool\
    \ make_copy) {\n    if (!make_copy || !PERSISTENT) return c;\n    return pool.clone(c);\n\
    \  }\n};\n"
  code: "#include \"ds/node_pool.hpp\"\n\ntemplate <typename T, bool PERSISTENT>\n\
    struct Dynamic_Array {\n  static constexpr int LOG = 4;\n  static constexpr int\
    \ MASK = (1 << LOG) - 1;\n  struct Node {\n    T x;\n    Node* ch[1 << LOG] =\
    \ {};\n  };\n  Node_Pool<Node> pool;\n  using np = Node*;\n  const T x0;\n\n \
    \ Dynamic_Array(int NODES, T default_value) : x0(default_value) {}\n  np new_root()\
    \ {\n    np c = pool.create();\n    c->x = x0;\n    fill(c->ch, c->ch + (1 <<\
    \ LOG), nullptr);\n    return c;\n  }\n\n  np new_node(vc<T> dat) {\n    np root\
    \ = new_root();\n    FOR(i, len(dat)) root = set(root, i, dat[i], false);\n  \
    \  return root;\n  }\n\n  T get(np c, int idx) {\n    if (!c) return x0;\n   \
    \ if (idx == 0) return c->x;\n    return get(c->ch[idx & MASK], (idx - 1) >> LOG);\n\
    \  }\n\n  np set(np c, int idx, T x, bool make_copy = true) {\n    c = (c ? clone(c,\
    \ make_copy) : new_root());\n    if (idx == 0) {\n      c->x = x;\n      return\
    \ c;\n    }\n    c->ch[idx & MASK] = set(c->ch[idx & MASK], (idx - 1) >> LOG,\
    \ x);\n    return c;\n  }\n\n private:\n  np clone(np c, bool make_copy) {\n \
    \   if (!make_copy || !PERSISTENT) return c;\n    return pool.clone(c);\n  }\n\
    };\n"
  dependsOn:
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/dynamic_array.hpp
  requiredBy:
  - ds/unionfind/dynamic_unionfind.hpp
  - string/aho_corasick_for_general_trie.hpp
  timestamp: '2026-08-31 12:03:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/persistent_queue.test.cpp
  - test/2_library_checker/data_structure/persistent_unionfind.test.cpp
documentation_of: ds/dynamic_array.hpp
layout: document
redirect_from:
- /library/ds/dynamic_array.hpp
- /library/ds/dynamic_array.hpp.html
title: ds/dynamic_array.hpp
---
