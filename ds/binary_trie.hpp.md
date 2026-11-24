---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/binary_trie.test.cpp
    title: test/1_mytest/binary_trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/set_xor_min.test.cpp
    title: test/2_library_checker/data_structure/set_xor_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/node_pool.hpp\n\
    // \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u3067\u3082\u78BA\u4FDD\
    \u6E08\u307F chunk \u3092\u518D\u5229\u7528\u3059\u308B\ntemplate <class Node>\n\
    struct Node_Pool {\n  union Slot {\n    Node node;\n    Slot* next;\n\n    Slot()\
    \ {}\n    ~Slot() {}\n  };\n  using np = Node*;\n\n  static constexpr int CHUNK_SIZE\
    \ = 1 << 12;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  int chunk_id = 0;\n  int pos\
    \ = 0;\n  Slot* free_head = nullptr;\n\n  ~Node_Pool() {\n    auto& cache = chunk_cache();\n\
    \    for (auto& p : chunks) cache.eb(std::move(p));\n  }\n\n  template <class...\
    \ Args>\n  np create(Args&&... args) {\n    Slot* s = new_slot();\n    return\
    \ ::new (&s->node) Node(forward<Args>(args)...);\n  }\n\n  np clone(const np x)\
    \ {\n    assert(x);\n    Slot* s = new_slot();\n    return ::new (&s->node) Node(*x);\n\
    \  }\n\n  void destroy(np x) {\n    if (!x) return;\n    x->~Node();\n    Slot*\
    \ s = reinterpret_cast<Slot*>(x);\n    s->next = free_head;\n    free_head = s;\n\
    \  }\n\n  // \u5168 node \u3092\u7121\u52B9\u5316\u3059\u308B\u3002\n  // \u78BA\
    \u4FDD\u6E08\u307F chunk \u306F\u89E3\u653E\u305B\u305A\u3001\u6B21\u56DE\u4EE5\
    \u964D\u306B\u518D\u5229\u7528\u3059\u308B\u3002\n  void reset() {\n    free_head\
    \ = nullptr;\n    chunk_id = 0;\n    pos = 0;\n  }\n\n  int used() const { return\
    \ chunk_id * CHUNK_SIZE + pos; }\n\n private:\n  static vc<unique_ptr<Slot[]>>&\
    \ chunk_cache() {\n    // static Node_Pool \u306E destructor \u3088\u308A\u5148\
    \u306B\u7834\u68C4\u3055\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u3002\
    \n    static auto* cache = new vc<unique_ptr<Slot[]>>();\n    return *cache;\n\
    \  }\n\n  void alloc_chunk() {\n    auto& cache = chunk_cache();\n    if (cache.empty())\
    \ {\n      chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\n    } else {\n      chunks.eb(std::move(cache.back()));\n\
    \      cache.pop_back();\n    }\n  }\n\n  Slot* new_slot() {\n    if (free_head)\
    \ {\n      Slot* s = free_head;\n      free_head = free_head->next;\n      return\
    \ s;\n    }\n\n    if (chunk_id == len(chunks)) alloc_chunk();\n\n    Slot* s\
    \ = &chunks[chunk_id][pos++];\n    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n\
    \      pos = 0;\n    }\n    return s;\n  }\n};\n#line 2 \"ds/binary_trie.hpp\"\
    \n\ntemplate <int LOG, bool PERSISTENT, typename UINT = u64,\n    typename SIZE_TYPE\
    \ = u32>\nstruct Binary_Trie {\n  using T = SIZE_TYPE;\n  static_assert(is_same_v<T,\
    \ u32> || is_same_v<T, u64>);\n  static_assert(0 < LOG && LOG <= numeric_limits<UINT>::digits);\n\
    \n  struct Node {\n    T cnt;\n    Node *l, *r;\n  };\n\n  Node_Pool<Node> pool;\n\
    \  using np = Node*;\n\n  void reset() { pool.reset(); }\n\n  np new_root() {\
    \ return nullptr; }\n\n  np add(np root, UINT val, T cnt = 1) {\n    if constexpr\
    \ (LOG < numeric_limits<UINT>::digits) {\n      assert((val >> LOG) == 0);\n \
    \   }\n    return add_rec(root, LOG, val, cnt);\n  }\n\n  // f(val, cnt, end)\n\
    \  template <typename F>\n  void enumerate(np root, F f) {\n    bool end = false;\n\
    \    auto dfs = [&](auto& dfs, np root, UINT val, int ht) -> void {\n      if\
    \ (!root || end) return;\n      if (ht == 0) {\n        f(val, root->cnt, end);\n\
    \        return;\n      }\n      dfs(dfs, root->l, 2 * val + 0, ht - 1);\n   \
    \   dfs(dfs, root->r, 2 * val + 1, ht - 1);\n    };\n    dfs(dfs, root, 0, LOG);\n\
    \  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6607\u9806 k\
    \ \u756A\u76EE\n  UINT kth(np root, T k, UINT xor_val) {\n    assert(root && k\
    \ < root->cnt);\n    UINT val = 0;\n    for (int d = LOG - 1; d >= 0; --d) {\n\
    \      bool b = (xor_val >> d) & 1;\n      np c = (b ? root->r : root->l);\n \
    \     T sl = (c ? c->cnt : 0);\n      if (k >= sl) {\n        k -= sl;\n     \
    \   b = !b;\n      }\n      val = 2 * val + b;\n      root = (b ? root->r : root->l);\n\
    \    }\n    return val ^ xor_val;\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\
    \u306E\u5024\u3067\u6700\u5C0F\u5024\n  UINT min(np root, UINT xor_val) {\n  \
    \  assert(root && root->cnt);\n    return kth(root, 0, xor_val);\n  }\n\n  //\
    \ xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6700\u5927\u5024\n  UINT\
    \ max(np root, UINT xor_val) {\n    assert(root && root->cnt);\n    return kth(root,\
    \ root->cnt - 1, xor_val);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\
    \u5024\u3067 [0, upper) \u5185\u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\
    \n  T prefix_count(np root, UINT upper, UINT xor_val) {\n    if (!root) return\
    \ 0;\n    if constexpr (LOG < numeric_limits<UINT>::digits) {\n      UINT a =\
    \ upper >> LOG, b = xor_val >> LOG;\n      if (a != b) return (a > b ? root->cnt\
    \ : 0);\n    }\n    T res = 0;\n    for (int d = LOG - 1; d >= 0 && root; --d)\
    \ {\n      np l = root->l, r = root->r;\n      if ((xor_val >> d) & 1) swap(l,\
    \ r);\n      if ((upper >> d) & 1) {\n        if (l) res += l->cnt;\n        root\
    \ = r;\n      } else {\n        root = l;\n      }\n    }\n    return res;\n \
    \ }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067 [lo, hi) \u5185\
    \u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\n  T count(np root, UINT lo,\
    \ UINT hi, UINT xor_val) {\n    return prefix_count(root, hi, xor_val) - prefix_count(root,\
    \ lo, xor_val);\n  }\n\n private:\n  np new_node() {\n    np c = pool.create();\n\
    \    c->l = c->r = nullptr;\n    c->cnt = 0;\n    return c;\n  }\n\n  np clone(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    return pool.clone(c);\n  }\n\
    \n  np add_rec(np root, int ht, UINT val, T cnt) {\n    root = (root ? clone(root)\
    \ : new_node());\n    root->cnt += cnt;\n    if (ht == 0) return root;\n    bool\
    \ b = (val >> (ht - 1)) & 1;\n    np& c = (b ? root->r : root->l);\n    c = add_rec(c,\
    \ ht - 1, val, cnt);\n    return root;\n  }\n};\n"
  code: "#include \"ds/node_pool.hpp\"\n\ntemplate <int LOG, bool PERSISTENT, typename\
    \ UINT = u64,\n    typename SIZE_TYPE = u32>\nstruct Binary_Trie {\n  using T\
    \ = SIZE_TYPE;\n  static_assert(is_same_v<T, u32> || is_same_v<T, u64>);\n  static_assert(0\
    \ < LOG && LOG <= numeric_limits<UINT>::digits);\n\n  struct Node {\n    T cnt;\n\
    \    Node *l, *r;\n  };\n\n  Node_Pool<Node> pool;\n  using np = Node*;\n\n  void\
    \ reset() { pool.reset(); }\n\n  np new_root() { return nullptr; }\n\n  np add(np\
    \ root, UINT val, T cnt = 1) {\n    if constexpr (LOG < numeric_limits<UINT>::digits)\
    \ {\n      assert((val >> LOG) == 0);\n    }\n    return add_rec(root, LOG, val,\
    \ cnt);\n  }\n\n  // f(val, cnt, end)\n  template <typename F>\n  void enumerate(np\
    \ root, F f) {\n    bool end = false;\n    auto dfs = [&](auto& dfs, np root,\
    \ UINT val, int ht) -> void {\n      if (!root || end) return;\n      if (ht ==\
    \ 0) {\n        f(val, root->cnt, end);\n        return;\n      }\n      dfs(dfs,\
    \ root->l, 2 * val + 0, ht - 1);\n      dfs(dfs, root->r, 2 * val + 1, ht - 1);\n\
    \    };\n    dfs(dfs, root, 0, LOG);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\
    \u306E\u5024\u3067\u6607\u9806 k \u756A\u76EE\n  UINT kth(np root, T k, UINT xor_val)\
    \ {\n    assert(root && k < root->cnt);\n    UINT val = 0;\n    for (int d = LOG\
    \ - 1; d >= 0; --d) {\n      bool b = (xor_val >> d) & 1;\n      np c = (b ? root->r\
    \ : root->l);\n      T sl = (c ? c->cnt : 0);\n      if (k >= sl) {\n        k\
    \ -= sl;\n        b = !b;\n      }\n      val = 2 * val + b;\n      root = (b\
    \ ? root->r : root->l);\n    }\n    return val ^ xor_val;\n  }\n\n  // xor_val\
    \ \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6700\u5C0F\u5024\n  UINT min(np\
    \ root, UINT xor_val) {\n    assert(root && root->cnt);\n    return kth(root,\
    \ 0, xor_val);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\
    \u6700\u5927\u5024\n  UINT max(np root, UINT xor_val) {\n    assert(root && root->cnt);\n\
    \    return kth(root, root->cnt - 1, xor_val);\n  }\n\n  // xor_val \u3057\u305F\
    \u3042\u3068\u306E\u5024\u3067 [0, upper) \u5185\u306B\u5165\u308B\u3082\u306E\
    \u306E\u500B\u6570\n  T prefix_count(np root, UINT upper, UINT xor_val) {\n  \
    \  if (!root) return 0;\n    if constexpr (LOG < numeric_limits<UINT>::digits)\
    \ {\n      UINT a = upper >> LOG, b = xor_val >> LOG;\n      if (a != b) return\
    \ (a > b ? root->cnt : 0);\n    }\n    T res = 0;\n    for (int d = LOG - 1; d\
    \ >= 0 && root; --d) {\n      np l = root->l, r = root->r;\n      if ((xor_val\
    \ >> d) & 1) swap(l, r);\n      if ((upper >> d) & 1) {\n        if (l) res +=\
    \ l->cnt;\n        root = r;\n      } else {\n        root = l;\n      }\n   \
    \ }\n    return res;\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\
    \u3067 [lo, hi) \u5185\u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\n  T count(np\
    \ root, UINT lo, UINT hi, UINT xor_val) {\n    return prefix_count(root, hi, xor_val)\
    \ - prefix_count(root, lo, xor_val);\n  }\n\n private:\n  np new_node() {\n  \
    \  np c = pool.create();\n    c->l = c->r = nullptr;\n    c->cnt = 0;\n    return\
    \ c;\n  }\n\n  np clone(np c) {\n    if (!c || !PERSISTENT) return c;\n    return\
    \ pool.clone(c);\n  }\n\n  np add_rec(np root, int ht, UINT val, T cnt) {\n  \
    \  root = (root ? clone(root) : new_node());\n    root->cnt += cnt;\n    if (ht\
    \ == 0) return root;\n    bool b = (val >> (ht - 1)) & 1;\n    np& c = (b ? root->r\
    \ : root->l);\n    c = add_rec(c, ht - 1, val, cnt);\n    return root;\n  }\n\
    };"
  dependsOn:
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/binary_trie.hpp
  requiredBy: []
  timestamp: '2026-11-24 20:56:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/binary_trie.test.cpp
  - test/2_library_checker/data_structure/set_xor_min.test.cpp
documentation_of: ds/binary_trie.hpp
layout: document
redirect_from:
- /library/ds/binary_trie.hpp
- /library/ds/binary_trie.hpp.html
title: ds/binary_trie.hpp
---
