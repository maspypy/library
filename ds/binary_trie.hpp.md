---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/binary_trie.test.cpp
    title: test/1_mytest/binary_trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/set_xor_min.test.cpp
    title: test/2_library_checker/data_structure/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"ds/node_pool.hpp\"\n\
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
    \ = nullptr;\n    chunk_id = 0;\n    pos = 0;\n  }\n\n private:\n  static vc<unique_ptr<Slot[]>>&\
    \ chunk_cache() {\n    // static Node_Pool \u306E destructor \u3088\u308A\u5148\
    \u306B\u7834\u68C4\u3055\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u3002\
    \n    static auto* cache = new vc<unique_ptr<Slot[]>>();\n    return *cache;\n\
    \  }\n\n  void alloc_chunk() {\n    auto& cache = chunk_cache();\n    if (cache.empty())\
    \ {\n      chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\n    } else {\n      chunks.eb(std::move(cache.back()));\n\
    \      cache.pop_back();\n    }\n  }\n\n  Slot* new_slot() {\n    if (free_head)\
    \ {\n      Slot* s = free_head;\n      free_head = free_head->next;\n      return\
    \ s;\n    }\n\n    if (chunk_id == len(chunks)) alloc_chunk();\n\n    Slot* s\
    \ = &chunks[chunk_id][pos++];\n    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n\
    \      pos = 0;\n    }\n    return s;\n  }\n};\n#line 3 \"ds/binary_trie.hpp\"\
    \n\n// \u975E\u6C38\u7D9A\u306A\u3089\u3070\u30012 * \u8981\u7D20\u6570 \u306E\
    \u30CE\u30FC\u30C9\u6570\ntemplate <int LOG, bool PERSISTENT, typename UINT =\
    \ u64,\n          typename SIZE_TYPE = u32>\nstruct Binary_Trie {\n  using T =\
    \ SIZE_TYPE;\n  static_assert(is_same_v<T, u32> || is_same_v<T, u64>);\n  static_assert(0\
    \ < LOG && LOG <= numeric_limits<UINT>::digits);\n\n  struct Node {\n    int width;\n\
    \    UINT val;\n    T cnt;\n    Node *l, *r;\n  };\n\n  Node_Pool<Node> pool;\n\
    \  using np = Node *;\n\n  void reset() { pool.reset(); }\n\n  np new_root() {\
    \ return nullptr; }\n\n  np add(np root, UINT val, T cnt = 1) {\n    if (!root)\
    \ root = new_node(0, 0);\n    assert((val >> LOG) == 0);\n    return add_rec(root,\
    \ LOG, val, cnt);\n  }\n\n  // f(val, cnt)\n  template <typename F>\n  void enumerate(np\
    \ root, F f) {\n    auto dfs = [&](auto &dfs, np root, UINT val, int ht) -> void\
    \ {\n      if (ht == 0) {\n        f(val, root->cnt);\n        return;\n     \
    \ }\n      np c = root->l;\n      if (c) {\n        dfs(dfs, c, val << (c->width)\
    \ | (c->val), ht - (c->width));\n      }\n      c = root->r;\n      if (c) {\n\
    \        dfs(dfs, c, val << (c->width) | (c->val), ht - (c->width));\n      }\n\
    \    };\n    if (root) dfs(dfs, root, 0, LOG);\n  }\n\n  // xor_val \u3057\u305F\
    \u3042\u3068\u306E\u5024\u3067\u6607\u9806 k \u756A\u76EE\n  UINT kth(np root,\
    \ T k, UINT xor_val) {\n    assert(root && k < root->cnt);\n    return kth_rec(root,\
    \ 0, k, LOG, xor_val) ^ xor_val;\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\
    \u306E\u5024\u3067\u6700\u5C0F\u5024\n  UINT min(np root, UINT xor_val) {\n  \
    \  assert(root && root->cnt);\n    return kth(root, 0, xor_val);\n  }\n\n  //\
    \ xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6700\u5927\u5024\n  UINT\
    \ max(np root, UINT xor_val) {\n    assert(root && root->cnt);\n    return kth(root,\
    \ (root->cnt) - 1, xor_val);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\
    \u5024\u3067 [0, upper) \u5185\u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\
    \n  T prefix_count(np root, UINT upper, UINT xor_val) {\n    if (!root) return\
    \ 0;\n    return prefix_count_rec(root, LOG, upper, xor_val, 0);\n  }\n\n  //\
    \ xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067 [lo, hi) \u5185\u306B\u5165\
    \u308B\u3082\u306E\u306E\u500B\u6570\n  T count(np root, UINT lo, UINT hi, UINT\
    \ xor_val) {\n    return prefix_count(root, hi, xor_val) - prefix_count(root,\
    \ lo, xor_val);\n  }\n\n private:\n  inline UINT mask(int k) { return (UINT(1)\
    \ << k) - 1; }\n\n  np new_node(int width, UINT val) {\n    np c = pool.create();\n\
    \    c->l = c->r = nullptr;\n    c->width = width, c->val = val, c->cnt = 0;\n\
    \    return c;\n  }\n\n  np clone(np c) {\n    if (!c || !PERSISTENT) return c;\n\
    \    return pool.clone(c);\n  }\n\n  np add_rec(np root, int ht, UINT val, T cnt)\
    \ {\n    root = clone(root);\n    root->cnt += cnt;\n    if (ht == 0) return root;\n\
    \n    bool go_r = (val >> (ht - 1)) & 1;\n    np c = (go_r ? root->r : root->l);\n\
    \    if (!c) {\n      c = new_node(ht, val);\n      c->cnt = cnt;\n      if (!go_r)\
    \ root->l = c;\n      if (go_r) root->r = c;\n      return root;\n    }\n    int\
    \ w = c->width;\n    if ((val >> (ht - w)) == c->val) {\n      c = add_rec(c,\
    \ ht - w, val & mask(ht - w), cnt);\n      if (!go_r) root->l = c;\n      if (go_r)\
    \ root->r = c;\n      return root;\n    }\n    int same = w - 1 - topbit((val\
    \ >> (ht - w)) ^ (c->val));\n    np n = new_node(same, (c->val) >> (w - same));\n\
    \    n->cnt = c->cnt + cnt;\n    c = clone(c);\n    c->width = w - same;\n   \
    \ c->val = c->val & mask(w - same);\n    if ((val >> (ht - same - 1)) & 1) {\n\
    \      n->l = c;\n      n->r = new_node(ht - same, val & mask(ht - same));\n \
    \     n->r->cnt = cnt;\n    } else {\n      n->r = c;\n      n->l = new_node(ht\
    \ - same, val & mask(ht - same));\n      n->l->cnt = cnt;\n    }\n    if (!go_r)\
    \ root->l = n;\n    if (go_r) root->r = n;\n    return root;\n  }\n\n  UINT kth_rec(np\
    \ root, UINT val, T k, int ht, UINT xor_val) {\n    if (ht == 0) return val;\n\
    \    np left = root->l, right = root->r;\n    if ((xor_val >> (ht - 1)) & 1) swap(left,\
    \ right);\n    T sl = (left ? left->cnt : 0);\n    np c;\n    if (k < sl) {\n\
    \      c = left;\n    }\n    if (k >= sl) {\n      c = right, k -= sl;\n    }\n\
    \    int w = c->width;\n    return kth_rec(c, val << w | (c->val), k, ht - w,\
    \ xor_val);\n  }\n\n  T prefix_count_rec(np root, int ht, UINT LIM, UINT xor_val,\
    \ UINT val) {\n    UINT now = (val << ht) ^ (xor_val);\n    if ((LIM >> ht) >\
    \ (now >> ht)) return root->cnt;\n    if (ht == 0 || (LIM >> ht) < (now >> ht))\
    \ return 0;\n    T res = 0;\n    FOR(k, 2) {\n      np c = (k == 0 ? root->l :\
    \ root->r);\n      if (c) {\n        int w = c->width;\n        res += prefix_count_rec(c,\
    \ ht - w, LIM, xor_val, val << w | c->val);\n      }\n    }\n    return res;\n\
    \  }\n};\n"
  code: "#include \"other/bit.hpp\"\n#include \"ds/node_pool.hpp\"\n\n// \u975E\u6C38\
    \u7D9A\u306A\u3089\u3070\u30012 * \u8981\u7D20\u6570 \u306E\u30CE\u30FC\u30C9\u6570\
    \ntemplate <int LOG, bool PERSISTENT, typename UINT = u64,\n          typename\
    \ SIZE_TYPE = u32>\nstruct Binary_Trie {\n  using T = SIZE_TYPE;\n  static_assert(is_same_v<T,\
    \ u32> || is_same_v<T, u64>);\n  static_assert(0 < LOG && LOG <= numeric_limits<UINT>::digits);\n\
    \n  struct Node {\n    int width;\n    UINT val;\n    T cnt;\n    Node *l, *r;\n\
    \  };\n\n  Node_Pool<Node> pool;\n  using np = Node *;\n\n  void reset() { pool.reset();\
    \ }\n\n  np new_root() { return nullptr; }\n\n  np add(np root, UINT val, T cnt\
    \ = 1) {\n    if (!root) root = new_node(0, 0);\n    assert((val >> LOG) == 0);\n\
    \    return add_rec(root, LOG, val, cnt);\n  }\n\n  // f(val, cnt)\n  template\
    \ <typename F>\n  void enumerate(np root, F f) {\n    auto dfs = [&](auto &dfs,\
    \ np root, UINT val, int ht) -> void {\n      if (ht == 0) {\n        f(val, root->cnt);\n\
    \        return;\n      }\n      np c = root->l;\n      if (c) {\n        dfs(dfs,\
    \ c, val << (c->width) | (c->val), ht - (c->width));\n      }\n      c = root->r;\n\
    \      if (c) {\n        dfs(dfs, c, val << (c->width) | (c->val), ht - (c->width));\n\
    \      }\n    };\n    if (root) dfs(dfs, root, 0, LOG);\n  }\n\n  // xor_val \u3057\
    \u305F\u3042\u3068\u306E\u5024\u3067\u6607\u9806 k \u756A\u76EE\n  UINT kth(np\
    \ root, T k, UINT xor_val) {\n    assert(root && k < root->cnt);\n    return kth_rec(root,\
    \ 0, k, LOG, xor_val) ^ xor_val;\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\
    \u306E\u5024\u3067\u6700\u5C0F\u5024\n  UINT min(np root, UINT xor_val) {\n  \
    \  assert(root && root->cnt);\n    return kth(root, 0, xor_val);\n  }\n\n  //\
    \ xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6700\u5927\u5024\n  UINT\
    \ max(np root, UINT xor_val) {\n    assert(root && root->cnt);\n    return kth(root,\
    \ (root->cnt) - 1, xor_val);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\
    \u5024\u3067 [0, upper) \u5185\u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\
    \n  T prefix_count(np root, UINT upper, UINT xor_val) {\n    if (!root) return\
    \ 0;\n    return prefix_count_rec(root, LOG, upper, xor_val, 0);\n  }\n\n  //\
    \ xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067 [lo, hi) \u5185\u306B\u5165\
    \u308B\u3082\u306E\u306E\u500B\u6570\n  T count(np root, UINT lo, UINT hi, UINT\
    \ xor_val) {\n    return prefix_count(root, hi, xor_val) - prefix_count(root,\
    \ lo, xor_val);\n  }\n\n private:\n  inline UINT mask(int k) { return (UINT(1)\
    \ << k) - 1; }\n\n  np new_node(int width, UINT val) {\n    np c = pool.create();\n\
    \    c->l = c->r = nullptr;\n    c->width = width, c->val = val, c->cnt = 0;\n\
    \    return c;\n  }\n\n  np clone(np c) {\n    if (!c || !PERSISTENT) return c;\n\
    \    return pool.clone(c);\n  }\n\n  np add_rec(np root, int ht, UINT val, T cnt)\
    \ {\n    root = clone(root);\n    root->cnt += cnt;\n    if (ht == 0) return root;\n\
    \n    bool go_r = (val >> (ht - 1)) & 1;\n    np c = (go_r ? root->r : root->l);\n\
    \    if (!c) {\n      c = new_node(ht, val);\n      c->cnt = cnt;\n      if (!go_r)\
    \ root->l = c;\n      if (go_r) root->r = c;\n      return root;\n    }\n    int\
    \ w = c->width;\n    if ((val >> (ht - w)) == c->val) {\n      c = add_rec(c,\
    \ ht - w, val & mask(ht - w), cnt);\n      if (!go_r) root->l = c;\n      if (go_r)\
    \ root->r = c;\n      return root;\n    }\n    int same = w - 1 - topbit((val\
    \ >> (ht - w)) ^ (c->val));\n    np n = new_node(same, (c->val) >> (w - same));\n\
    \    n->cnt = c->cnt + cnt;\n    c = clone(c);\n    c->width = w - same;\n   \
    \ c->val = c->val & mask(w - same);\n    if ((val >> (ht - same - 1)) & 1) {\n\
    \      n->l = c;\n      n->r = new_node(ht - same, val & mask(ht - same));\n \
    \     n->r->cnt = cnt;\n    } else {\n      n->r = c;\n      n->l = new_node(ht\
    \ - same, val & mask(ht - same));\n      n->l->cnt = cnt;\n    }\n    if (!go_r)\
    \ root->l = n;\n    if (go_r) root->r = n;\n    return root;\n  }\n\n  UINT kth_rec(np\
    \ root, UINT val, T k, int ht, UINT xor_val) {\n    if (ht == 0) return val;\n\
    \    np left = root->l, right = root->r;\n    if ((xor_val >> (ht - 1)) & 1) swap(left,\
    \ right);\n    T sl = (left ? left->cnt : 0);\n    np c;\n    if (k < sl) {\n\
    \      c = left;\n    }\n    if (k >= sl) {\n      c = right, k -= sl;\n    }\n\
    \    int w = c->width;\n    return kth_rec(c, val << w | (c->val), k, ht - w,\
    \ xor_val);\n  }\n\n  T prefix_count_rec(np root, int ht, UINT LIM, UINT xor_val,\
    \ UINT val) {\n    UINT now = (val << ht) ^ (xor_val);\n    if ((LIM >> ht) >\
    \ (now >> ht)) return root->cnt;\n    if (ht == 0 || (LIM >> ht) < (now >> ht))\
    \ return 0;\n    T res = 0;\n    FOR(k, 2) {\n      np c = (k == 0 ? root->l :\
    \ root->r);\n      if (c) {\n        int w = c->width;\n        res += prefix_count_rec(c,\
    \ ht - w, LIM, xor_val, val << w | c->val);\n      }\n    }\n    return res;\n\
    \  }\n};"
  dependsOn:
  - other/bit.hpp
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/binary_trie.hpp
  requiredBy: []
  timestamp: '2026-08-31 12:03:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
