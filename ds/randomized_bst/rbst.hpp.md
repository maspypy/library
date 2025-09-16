---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/rbst.test.cpp
    title: test/1_mytest/rbst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\ntemplate <class Node>\nstruct Node_Pool\
    \ {\n  struct Slot {\n    union alignas(Node) {\n      Slot* next;\n      unsigned\
    \ char storage[sizeof(Node)];\n    };\n  };\n  using np = Node*;\n\n  static constexpr\
    \ int CHUNK_SIZE = 1 << 16;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur =\
    \ nullptr;\n  int cur_used = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool()\
    \ { alloc_chunk(); }\n\n  template <class... Args>\n  np create(Args&&... args)\
    \ {\n    Slot* s = new_slot();\n    return ::new (s) Node(forward<Args>(args)...);\n\
    \  }\n\n  void destroy(np x) {\n    if (!x) return;\n    x->~Node();\n    auto\
    \ s = reinterpret_cast<Slot*>(x);\n    s->next = free_head;\n    free_head = s;\n\
    \  }\n\n  void reset() {\n    free_head = nullptr;\n    if (!chunks.empty()) {\n\
    \      cur = chunks[0].get();\n      cur_used = 0;\n    }\n  }\n\n private:\n\
    \  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n#line 2 \"ds/randomized_bst/rbst.hpp\"\n\n// \u5358\
    \u306B S \u306E\u5143\u306E\u5217\u3092\u7BA1\u7406\u3059\u308B\ntemplate <typename\
    \ S, bool PERSISTENT>\nstruct RBST {\n  struct Node {\n    Node *l, *r;\n    S\
    \ s;\n    u32 size;\n    bool rev;\n  };\n\n  Node_Pool<Node> pool;\n  using np\
    \ = Node *;\n\n  void reset() { pool.reset(); }\n\n  np new_node(const S &s) {\n\
    \    np c = pool.create();\n    c->l = c->r = nullptr;\n    c->s = s, c->size\
    \ = 1, c->rev = 0;\n    return c;\n  }\n\n  np new_node(const vc<S> &dat) {\n\
    \    auto dfs = [&](auto &dfs, u32 l, u32 r) -> np {\n      if (l == r) return\
    \ nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      u32 m = (l +\
    \ r) / 2;\n      np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1,\
    \ r);\n      np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n\
    \      update(root);\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  np copy_node(np &n) {\n    if (!n || !PERSISTENT) return n;\n    np\
    \ c = pool.create();\n    c->l = n->l, c->r = n->r;\n    c->s = n->s, c->size\
    \ = n->size, c->rev = n->rev;\n    return c;\n  }\n\n  np merge(np l_root, np\
    \ r_root) { return merge_rec(l_root, r_root); }\n  np merge3(np a, np b, np c)\
    \ { return merge(merge(a, b), c); }\n  np merge4(np a, np b, np c, np d) { return\
    \ merge(merge(merge(a, b), c), d); }\n  pair<np, np> split(np root, u32 k) {\n\
    \    if (!root) {\n      assert(k == 0);\n      return {nullptr, nullptr};\n \
    \   }\n    assert(0 <= k && k <= root->size);\n    return split_rec(root, k);\n\
    \  }\n  tuple<np, np, np> split3(np root, u32 l, u32 r) {\n    np nm, nr;\n  \
    \  tie(root, nr) = split(root, r);\n    tie(root, nm) = split(root, l);\n    return\
    \ {root, nm, nr};\n  }\n  tuple<np, np, np, np> split4(np root, u32 i, u32 j,\
    \ u32 k) {\n    np d;\n    tie(root, d) = split(root, k);\n    auto [a, b, c]\
    \ = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\n  np reverse(np root,\
    \ u32 l, u32 r) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (r\
    \ - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n    nm->rev\
    \ ^= 1;\n    swap(nm->l, nm->r);\n    return merge3(nl, nm, nr);\n  }\n\n  np\
    \ set(np root, u32 k, const S &s) { return set_rec(root, k, s); }\n  S get(np\
    \ root, u32 k) { return get_rec(root, k, false); }\n\n  vc<S> get_all(np root)\
    \ {\n    vc<S> res;\n    auto dfs = [&](auto &dfs, np root, bool rev) -> void\
    \ {\n      if (!root) return;\n      dfs(dfs, (rev ? root->r : root->l), rev ^\
    \ root->rev);\n      res.eb(root->s);\n      dfs(dfs, (rev ? root->l : root->r),\
    \ rev ^ root->rev);\n    };\n    dfs(dfs, root, 0);\n    return res;\n  }\n\n\
    \  // \u6700\u5F8C\u306B check(s) \u304C\u6210\u308A\u7ACB\u3064\u3068\u3053\u308D\
    \u307E\u3067\u3092\u5DE6\u3068\u3057\u3066 split\n  template <typename F>\n  pair<np,\
    \ np> split_max_right(np root, const F check) {\n    return split_max_right_rec(root,\
    \ check);\n  }\n\n private:\n  inline u32 xor128() {\n    static u32 x = 123456789;\n\
    \    static u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32\
    \ w = 88675123;\n    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n\
    \    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n\
    \    // \u81EA\u8EAB\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u306F\u306A\
    \u3044\u3002\n    // \u5B50\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\u3002\u8907\u6570\u306E\u89AA\u3092\u6301\u3064\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\u305F\u3081\u3002\n    if (c->rev) {\n      if (c->l) {\n \
    \       c->l = copy_node(c->l);\n        c->l->rev ^= 1;\n        swap(c->l->l,\
    \ c->l->r);\n      }\n      if (c->r) {\n        c->r = copy_node(c->r);\n   \
    \     c->r->rev ^= 1;\n        swap(c->r->l, c->r->r);\n      }\n      c->rev\
    \ = 0;\n    }\n  }\n\n  void update(np c) {\n    // \u30C7\u30FC\u30BF\u3092\u4FDD\
    \u3063\u305F\u307E\u307E\u6B63\u5E38\u5316\u3059\u308B\u3060\u3051\u306A\u306E\
    \u3067\u3001\u30B3\u30D4\u30FC\u4E0D\u8981\n    c->size = 1;\n    if (c->l) {\n\
    \      c->size += c->l->size;\n    }\n    if (c->r) {\n      c->size += c->r->size;\n\
    \    }\n  }\n\n  np merge_rec(np l_root, np r_root) {\n    if (!l_root) return\
    \ r_root;\n    if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
    \    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n      l_root = copy_node(l_root);\n\
    \      l_root->r = merge_rec(l_root->r, r_root);\n      update(l_root);\n    \
    \  return l_root;\n    }\n    prop(r_root);\n    r_root = copy_node(r_root);\n\
    \    r_root->l = merge_rec(l_root, r_root->l);\n    update(r_root);\n    return\
    \ r_root;\n  }\n\n  pair<np, np> split_rec(np root, u32 k) {\n    if (!root) return\
    \ {nullptr, nullptr};\n    prop(root);\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (k <= sl) {\n      auto [nl, nr] = split_rec(root->l, k);\n  \
    \    root = copy_node(root);\n      root->l = nr;\n      update(root);\n     \
    \ return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r, k - (1 + sl));\n\
    \    root = copy_node(root);\n    root->r = nl;\n    update(root);\n    return\
    \ {root, nr};\n  }\n\n  np set_rec(np root, u32 k, const S &s) {\n    if (!root)\
    \ return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (k < sl) {\n      root = copy_node(root);\n      root->l = set_rec(root->l,\
    \ k, s);\n      update(root);\n      return root;\n    }\n    if (k == sl) {\n\
    \      root = copy_node(root);\n      root->s = s;\n      update(root);\n    \
    \  return root;\n    }\n    root = copy_node(root);\n    root->r = set_rec(root->r,\
    \ k - (1 + sl), s);\n    update(root);\n    return root;\n  }\n\n  S get_rec(np\
    \ root, u32 k, bool rev) {\n    np left = (rev ? root->r : root->l);\n    np right\
    \ = (rev ? root->l : root->r);\n    u32 sl = (left ? left->size : 0);\n    if\
    \ (k == sl) return root->s;\n    rev ^= root->rev;\n    if (k < sl) return get_rec(left,\
    \ k, rev);\n    return get_rec(right, k - (1 + sl), rev);\n  }\n\n  template <typename\
    \ F>\n  pair<np, np> split_max_right_rec(np root, const F &check) {\n    if (!root)\
    \ return {nullptr, nullptr};\n    prop(root);\n    root = copy_node(root);\n \
    \   if (check(root->s)) {\n      auto [n1, n2] = split_max_right_rec(root->r,\
    \ check);\n      root->r = n1;\n      update(root);\n      return {root, n2};\n\
    \    }\n    auto [n1, n2] = split_max_right_rec(root->l, check);\n    root->l\
    \ = n2;\n    update(root);\n    return {n1, root};\n  }\n};\n"
  code: "#include \"ds/node_pool.hpp\"\n\n// \u5358\u306B S \u306E\u5143\u306E\u5217\
    \u3092\u7BA1\u7406\u3059\u308B\ntemplate <typename S, bool PERSISTENT>\nstruct\
    \ RBST {\n  struct Node {\n    Node *l, *r;\n    S s;\n    u32 size;\n    bool\
    \ rev;\n  };\n\n  Node_Pool<Node> pool;\n  using np = Node *;\n\n  void reset()\
    \ { pool.reset(); }\n\n  np new_node(const S &s) {\n    np c = pool.create();\n\
    \    c->l = c->r = nullptr;\n    c->s = s, c->size = 1, c->rev = 0;\n    return\
    \ c;\n  }\n\n  np new_node(const vc<S> &dat) {\n    auto dfs = [&](auto &dfs,\
    \ u32 l, u32 r) -> np {\n      if (l == r) return nullptr;\n      if (r == l +\
    \ 1) return new_node(dat[l]);\n      u32 m = (l + r) / 2;\n      np l_root = dfs(dfs,\
    \ l, m);\n      np r_root = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n\
    \      root->l = l_root, root->r = r_root;\n      update(root);\n      return\
    \ root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  np copy_node(np &n)\
    \ {\n    if (!n || !PERSISTENT) return n;\n    np c = pool.create();\n    c->l\
    \ = n->l, c->r = n->r;\n    c->s = n->s, c->size = n->size, c->rev = n->rev;\n\
    \    return c;\n  }\n\n  np merge(np l_root, np r_root) { return merge_rec(l_root,\
    \ r_root); }\n  np merge3(np a, np b, np c) { return merge(merge(a, b), c); }\n\
    \  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a, b), c), d);\
    \ }\n  pair<np, np> split(np root, u32 k) {\n    if (!root) {\n      assert(k\
    \ == 0);\n      return {nullptr, nullptr};\n    }\n    assert(0 <= k && k <= root->size);\n\
    \    return split_rec(root, k);\n  }\n  tuple<np, np, np> split3(np root, u32\
    \ l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n    tie(root,\
    \ nm) = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np, np, np,\
    \ np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root, d) = split(root,\
    \ k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\
    \n  np reverse(np root, u32 l, u32 r) {\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (r - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n\
    \    nm->rev ^= 1;\n    swap(nm->l, nm->r);\n    return merge3(nl, nm, nr);\n\
    \  }\n\n  np set(np root, u32 k, const S &s) { return set_rec(root, k, s); }\n\
    \  S get(np root, u32 k) { return get_rec(root, k, false); }\n\n  vc<S> get_all(np\
    \ root) {\n    vc<S> res;\n    auto dfs = [&](auto &dfs, np root, bool rev) ->\
    \ void {\n      if (!root) return;\n      dfs(dfs, (rev ? root->r : root->l),\
    \ rev ^ root->rev);\n      res.eb(root->s);\n      dfs(dfs, (rev ? root->l : root->r),\
    \ rev ^ root->rev);\n    };\n    dfs(dfs, root, 0);\n    return res;\n  }\n\n\
    \  // \u6700\u5F8C\u306B check(s) \u304C\u6210\u308A\u7ACB\u3064\u3068\u3053\u308D\
    \u307E\u3067\u3092\u5DE6\u3068\u3057\u3066 split\n  template <typename F>\n  pair<np,\
    \ np> split_max_right(np root, const F check) {\n    return split_max_right_rec(root,\
    \ check);\n  }\n\n private:\n  inline u32 xor128() {\n    static u32 x = 123456789;\n\
    \    static u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32\
    \ w = 88675123;\n    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n\
    \    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n\
    \    // \u81EA\u8EAB\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u306F\u306A\
    \u3044\u3002\n    // \u5B50\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\u3002\u8907\u6570\u306E\u89AA\u3092\u6301\u3064\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\u305F\u3081\u3002\n    if (c->rev) {\n      if (c->l) {\n \
    \       c->l = copy_node(c->l);\n        c->l->rev ^= 1;\n        swap(c->l->l,\
    \ c->l->r);\n      }\n      if (c->r) {\n        c->r = copy_node(c->r);\n   \
    \     c->r->rev ^= 1;\n        swap(c->r->l, c->r->r);\n      }\n      c->rev\
    \ = 0;\n    }\n  }\n\n  void update(np c) {\n    // \u30C7\u30FC\u30BF\u3092\u4FDD\
    \u3063\u305F\u307E\u307E\u6B63\u5E38\u5316\u3059\u308B\u3060\u3051\u306A\u306E\
    \u3067\u3001\u30B3\u30D4\u30FC\u4E0D\u8981\n    c->size = 1;\n    if (c->l) {\n\
    \      c->size += c->l->size;\n    }\n    if (c->r) {\n      c->size += c->r->size;\n\
    \    }\n  }\n\n  np merge_rec(np l_root, np r_root) {\n    if (!l_root) return\
    \ r_root;\n    if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
    \    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n      l_root = copy_node(l_root);\n\
    \      l_root->r = merge_rec(l_root->r, r_root);\n      update(l_root);\n    \
    \  return l_root;\n    }\n    prop(r_root);\n    r_root = copy_node(r_root);\n\
    \    r_root->l = merge_rec(l_root, r_root->l);\n    update(r_root);\n    return\
    \ r_root;\n  }\n\n  pair<np, np> split_rec(np root, u32 k) {\n    if (!root) return\
    \ {nullptr, nullptr};\n    prop(root);\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (k <= sl) {\n      auto [nl, nr] = split_rec(root->l, k);\n  \
    \    root = copy_node(root);\n      root->l = nr;\n      update(root);\n     \
    \ return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r, k - (1 + sl));\n\
    \    root = copy_node(root);\n    root->r = nl;\n    update(root);\n    return\
    \ {root, nr};\n  }\n\n  np set_rec(np root, u32 k, const S &s) {\n    if (!root)\
    \ return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (k < sl) {\n      root = copy_node(root);\n      root->l = set_rec(root->l,\
    \ k, s);\n      update(root);\n      return root;\n    }\n    if (k == sl) {\n\
    \      root = copy_node(root);\n      root->s = s;\n      update(root);\n    \
    \  return root;\n    }\n    root = copy_node(root);\n    root->r = set_rec(root->r,\
    \ k - (1 + sl), s);\n    update(root);\n    return root;\n  }\n\n  S get_rec(np\
    \ root, u32 k, bool rev) {\n    np left = (rev ? root->r : root->l);\n    np right\
    \ = (rev ? root->l : root->r);\n    u32 sl = (left ? left->size : 0);\n    if\
    \ (k == sl) return root->s;\n    rev ^= root->rev;\n    if (k < sl) return get_rec(left,\
    \ k, rev);\n    return get_rec(right, k - (1 + sl), rev);\n  }\n\n  template <typename\
    \ F>\n  pair<np, np> split_max_right_rec(np root, const F &check) {\n    if (!root)\
    \ return {nullptr, nullptr};\n    prop(root);\n    root = copy_node(root);\n \
    \   if (check(root->s)) {\n      auto [n1, n2] = split_max_right_rec(root->r,\
    \ check);\n      root->r = n1;\n      update(root);\n      return {root, n2};\n\
    \    }\n    auto [n1, n2] = split_max_right_rec(root->l, check);\n    root->l\
    \ = n2;\n    update(root);\n    return {n1, root};\n  }\n};\n"
  dependsOn:
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/randomized_bst/rbst.hpp
  requiredBy: []
  timestamp: '2025-09-16 15:18:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/rbst.test.cpp
documentation_of: ds/randomized_bst/rbst.hpp
layout: document
redirect_from:
- /library/ds/randomized_bst/rbst.hpp
- /library/ds/randomized_bst/rbst.hpp.html
title: ds/randomized_bst/rbst.hpp
---
