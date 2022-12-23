---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/set_xor_min.test.cpp
    title: test/library_checker/datastructure/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/binary_trie.test.cpp
    title: test/mytest/binary_trie.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/binary_trie.hpp\"\n// \u975E\u6C38\u7D9A\u306A\u3089\u3070\
    \u30012 * \u8981\u7D20\u6570 \u306E\u30CE\u30FC\u30C9\u6570\ntemplate <int LOG,\
    \ bool PERSISTENT, int NODES, typename UINT = u64,\n          typename SIZE_TYPE\
    \ = int>\nstruct Binary_Trie {\n  using T = SIZE_TYPE;\n  struct Node {\n    int\
    \ width;\n    UINT val;\n    T cnt;\n    Node *l, *r;\n  };\n\n  Node *pool;\n\
    \  int pid;\n  using np = Node *;\n\n  Binary_Trie() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  void reset() { pid = 0; }\n\n  np new_root() { return nullptr; }\n\n\
    \  np new_node(int width, UINT val) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].width = width;\n    pool[pid].val = val;\n    pool[pid].cnt = 0;\n\
    \    return &(pool[pid++]);\n  }\n\n  np copy_node(np c) {\n    if (!c || !PERSISTENT)\
    \ return c;\n    np res = &(pool[pid++]);\n    res->width = c->width, res->val\
    \ = c->val;\n    res->cnt = c->cnt, res->l = c->l, res->r = c->r;\n    return\
    \ res;\n  }\n\n  np add(np root, UINT val, T cnt = 1) {\n    if (!root) root =\
    \ new_node(0, 0);\n    assert(0 <= val && val < (1LL << LOG));\n    return add_rec(root,\
    \ LOG, val, cnt);\n  }\n\n  vc<pair<UINT, T>> get_all(np root) {\n    vc<pair<UINT,\
    \ T>> res;\n    auto dfs = [&](auto &dfs, np root, UINT val, int ht) -> void {\n\
    \      if (ht == 0) {\n        res.eb(val, root->cnt);\n        return;\n    \
    \  }\n      np c = root->l;\n      if (c) { dfs(dfs, c, val << (c->width) | (c->val),\
    \ ht - (c->width)); }\n      c = root->r;\n      if (c) { dfs(dfs, c, val << (c->width)\
    \ | (c->val), ht - (c->width)); }\n    };\n    if (root) dfs(dfs, root, 0, LOG);\n\
    \    return res;\n  }\n\n  UINT kth(np root, T k, UINT xor_val) {\n    assert(root\
    \ && 0 <= k && k < root->cnt);\n    return kth_rec(root, 0, k, LOG, xor_val) ^\
    \ xor_val;\n  }\n\n  UINT min(np root, UINT xor_val) {\n    assert(root && root->cnt);\n\
    \    return kth(root, 0, xor_val);\n  }\n\n  UINT max(np root, UINT xor_val) {\n\
    \    assert(root && root->cnt);\n    return kth(root, (root->cnt) - 1, xor_val);\n\
    \  }\n\n  T prefix_count(np root, UINT upper, UINT xor_val) {\n    if (!root)\
    \ return 0;\n    return prefix_count_rec(root, LOG, upper, xor_val, 0);\n  }\n\
    \n  T count(np root, UINT lo, UINT hi, UINT xor_val) {\n    return prefix_count(root,\
    \ hi, xor_val) - prefix_count(root, lo, xor_val);\n  }\n\nprivate:\n  inline UINT\
    \ mask(int k) { return (UINT(1) << k) - 1; }\n\n  np add_rec(np root, int ht,\
    \ UINT val, T cnt) {\n    root = copy_node(root);\n    root->cnt += cnt;\n   \
    \ if (ht == 0) return root;\n\n    bool go_r = (val >> (ht - 1)) & 1;\n    np\
    \ c = (go_r ? root->r : root->l);\n    if (!c) {\n      c = new_node(ht, val);\n\
    \      c->cnt = cnt;\n      if (!go_r) root->l = c;\n      if (go_r) root->r =\
    \ c;\n      return root;\n    }\n    int w = c->width;\n    if ((val >> (ht -\
    \ w)) == c->val) {\n      c = add_rec(c, ht - w, val & mask(ht - w), cnt);\n \
    \     if (!go_r) root->l = c;\n      if (go_r) root->r = c;\n      return root;\n\
    \    }\n    int same = w - 1 - topbit((val >> (ht - w)) ^ (c->val));\n    np n\
    \ = new_node(same, (c->val) >> (w - same));\n    n->cnt = c->cnt + cnt;\n    c\
    \ = copy_node(c);\n    c->width = w - same;\n    c->val = c->val & mask(w - same);\n\
    \    if ((val >> (ht - same - 1)) & 1) {\n      n->l = c;\n      n->r = new_node(ht\
    \ - same, val & mask(ht - same));\n      n->r->cnt = cnt;\n    } else {\n    \
    \  n->r = c;\n      n->l = new_node(ht - same, val & mask(ht - same));\n     \
    \ n->l->cnt = cnt;\n    }\n    if (!go_r) root->l = n;\n    if (go_r) root->r\
    \ = n;\n    return root;\n  }\n\n  UINT kth_rec(np root, UINT val, T k, int ht,\
    \ UINT xor_val) {\n    if (ht == 0) return val;\n    np left = root->l, right\
    \ = root->r;\n    if ((xor_val >> (ht - 1)) & 1) swap(left, right);\n    T sl\
    \ = (left ? left->cnt : 0);\n    np c;\n    if (k < sl) { c = left; }\n    if\
    \ (k >= sl) { c = right, k -= sl; }\n    int w = c->width;\n    return kth_rec(c,\
    \ val << w | (c->val), k, ht - w, xor_val);\n  }\n\n  T prefix_count_rec(np root,\
    \ int ht, UINT LIM, UINT xor_val, UINT val) {\n    UINT now = (val << ht) ^ (xor_val);\n\
    \    if ((LIM >> ht) > (now >> ht)) return root->cnt;\n    if (ht == 0 || (LIM\
    \ >> ht) < (now >> ht)) return 0;\n    T res = 0;\n    FOR(k, 2) {\n      np c\
    \ = (k == 0 ? root->l : root->r);\n      if (c) {\n        int w = c->width;\n\
    \        res += prefix_count_rec(c, ht - w, LIM, xor_val, val << w | c->val);\n\
    \      }\n    }\n    return res;\n  }\n};\n"
  code: "// \u975E\u6C38\u7D9A\u306A\u3089\u3070\u30012 * \u8981\u7D20\u6570 \u306E\
    \u30CE\u30FC\u30C9\u6570\ntemplate <int LOG, bool PERSISTENT, int NODES, typename\
    \ UINT = u64,\n          typename SIZE_TYPE = int>\nstruct Binary_Trie {\n  using\
    \ T = SIZE_TYPE;\n  struct Node {\n    int width;\n    UINT val;\n    T cnt;\n\
    \    Node *l, *r;\n  };\n\n  Node *pool;\n  int pid;\n  using np = Node *;\n\n\
    \  Binary_Trie() : pid(0) { pool = new Node[NODES]; }\n\n  void reset() { pid\
    \ = 0; }\n\n  np new_root() { return nullptr; }\n\n  np new_node(int width, UINT\
    \ val) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].width = width;\n\
    \    pool[pid].val = val;\n    pool[pid].cnt = 0;\n    return &(pool[pid++]);\n\
    \  }\n\n  np copy_node(np c) {\n    if (!c || !PERSISTENT) return c;\n    np res\
    \ = &(pool[pid++]);\n    res->width = c->width, res->val = c->val;\n    res->cnt\
    \ = c->cnt, res->l = c->l, res->r = c->r;\n    return res;\n  }\n\n  np add(np\
    \ root, UINT val, T cnt = 1) {\n    if (!root) root = new_node(0, 0);\n    assert(0\
    \ <= val && val < (1LL << LOG));\n    return add_rec(root, LOG, val, cnt);\n \
    \ }\n\n  vc<pair<UINT, T>> get_all(np root) {\n    vc<pair<UINT, T>> res;\n  \
    \  auto dfs = [&](auto &dfs, np root, UINT val, int ht) -> void {\n      if (ht\
    \ == 0) {\n        res.eb(val, root->cnt);\n        return;\n      }\n      np\
    \ c = root->l;\n      if (c) { dfs(dfs, c, val << (c->width) | (c->val), ht -\
    \ (c->width)); }\n      c = root->r;\n      if (c) { dfs(dfs, c, val << (c->width)\
    \ | (c->val), ht - (c->width)); }\n    };\n    if (root) dfs(dfs, root, 0, LOG);\n\
    \    return res;\n  }\n\n  UINT kth(np root, T k, UINT xor_val) {\n    assert(root\
    \ && 0 <= k && k < root->cnt);\n    return kth_rec(root, 0, k, LOG, xor_val) ^\
    \ xor_val;\n  }\n\n  UINT min(np root, UINT xor_val) {\n    assert(root && root->cnt);\n\
    \    return kth(root, 0, xor_val);\n  }\n\n  UINT max(np root, UINT xor_val) {\n\
    \    assert(root && root->cnt);\n    return kth(root, (root->cnt) - 1, xor_val);\n\
    \  }\n\n  T prefix_count(np root, UINT upper, UINT xor_val) {\n    if (!root)\
    \ return 0;\n    return prefix_count_rec(root, LOG, upper, xor_val, 0);\n  }\n\
    \n  T count(np root, UINT lo, UINT hi, UINT xor_val) {\n    return prefix_count(root,\
    \ hi, xor_val) - prefix_count(root, lo, xor_val);\n  }\n\nprivate:\n  inline UINT\
    \ mask(int k) { return (UINT(1) << k) - 1; }\n\n  np add_rec(np root, int ht,\
    \ UINT val, T cnt) {\n    root = copy_node(root);\n    root->cnt += cnt;\n   \
    \ if (ht == 0) return root;\n\n    bool go_r = (val >> (ht - 1)) & 1;\n    np\
    \ c = (go_r ? root->r : root->l);\n    if (!c) {\n      c = new_node(ht, val);\n\
    \      c->cnt = cnt;\n      if (!go_r) root->l = c;\n      if (go_r) root->r =\
    \ c;\n      return root;\n    }\n    int w = c->width;\n    if ((val >> (ht -\
    \ w)) == c->val) {\n      c = add_rec(c, ht - w, val & mask(ht - w), cnt);\n \
    \     if (!go_r) root->l = c;\n      if (go_r) root->r = c;\n      return root;\n\
    \    }\n    int same = w - 1 - topbit((val >> (ht - w)) ^ (c->val));\n    np n\
    \ = new_node(same, (c->val) >> (w - same));\n    n->cnt = c->cnt + cnt;\n    c\
    \ = copy_node(c);\n    c->width = w - same;\n    c->val = c->val & mask(w - same);\n\
    \    if ((val >> (ht - same - 1)) & 1) {\n      n->l = c;\n      n->r = new_node(ht\
    \ - same, val & mask(ht - same));\n      n->r->cnt = cnt;\n    } else {\n    \
    \  n->r = c;\n      n->l = new_node(ht - same, val & mask(ht - same));\n     \
    \ n->l->cnt = cnt;\n    }\n    if (!go_r) root->l = n;\n    if (go_r) root->r\
    \ = n;\n    return root;\n  }\n\n  UINT kth_rec(np root, UINT val, T k, int ht,\
    \ UINT xor_val) {\n    if (ht == 0) return val;\n    np left = root->l, right\
    \ = root->r;\n    if ((xor_val >> (ht - 1)) & 1) swap(left, right);\n    T sl\
    \ = (left ? left->cnt : 0);\n    np c;\n    if (k < sl) { c = left; }\n    if\
    \ (k >= sl) { c = right, k -= sl; }\n    int w = c->width;\n    return kth_rec(c,\
    \ val << w | (c->val), k, ht - w, xor_val);\n  }\n\n  T prefix_count_rec(np root,\
    \ int ht, UINT LIM, UINT xor_val, UINT val) {\n    UINT now = (val << ht) ^ (xor_val);\n\
    \    if ((LIM >> ht) > (now >> ht)) return root->cnt;\n    if (ht == 0 || (LIM\
    \ >> ht) < (now >> ht)) return 0;\n    T res = 0;\n    FOR(k, 2) {\n      np c\
    \ = (k == 0 ? root->l : root->r);\n      if (c) {\n        int w = c->width;\n\
    \        res += prefix_count_rec(c, ht - w, LIM, xor_val, val << w | c->val);\n\
    \      }\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/binary_trie.hpp
  requiredBy: []
  timestamp: '2022-12-13 10:08:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/binary_trie.test.cpp
  - test/library_checker/datastructure/set_xor_min.test.cpp
documentation_of: ds/binary_trie.hpp
layout: document
redirect_from:
- /library/ds/binary_trie.hpp
- /library/ds/binary_trie.hpp.html
title: ds/binary_trie.hpp
---
