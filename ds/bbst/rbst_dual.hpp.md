---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/cf702_F.test.cpp
    title: test/mytest/cf702_F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bbst/rbst_dual.hpp\"\ntemplate <typename XSet, int NODES\
    \ = 1'000'000>\nstruct RBST_Dual {\n  using Mono = typename XSet::Monoid;\n  using\
    \ X = typename XSet::operator_type;\n  using S = typename XSet::element_type;\n\
    \n  struct Node {\n    Node *l, *r;\n    X lazy;\n    S val; // lazy \u306F\u305D\
    \u306E\u30CE\u30FC\u30C9\u306B\u306F\u53CD\u6620\u6E08\n    u32 size;\n    bool\
    \ rev;\n  };\n\n  Node *pool;\n  int pid;\n\n  RBST_Dual() : pid(0) { pool = new\
    \ Node[NODES]; }\n\n  Node *new_node(const S &val) {\n    assert(pid < NODES);\n\
    \    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].lazy = Mono::unit();\n\
    \    pool[pid].val = val;\n    pool[pid].size = 1;\n    pool[pid].rev = 0;\n \
    \   return &(pool[pid++]);\n  }\n\n  Node *new_node(const vc<S> &dat) {\n    auto\
    \ dfs = [&](auto &dfs, int l, int r) -> Node * {\n      if (l == r) return nullptr;\n\
    \      int m = (l + r) / 2;\n      Node *root = new_node(dat[m]);\n      root->l\
    \ = dfs(dfs, l, m);\n      root->r = dfs(dfs, m + 1, r);\n      return root;\n\
    \    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  Node *merge(Node *l_root,\
    \ Node *r_root) { return merge_rec(l_root, r_root); }\n  Node *merge3(Node *a,\
    \ Node *b, Node *c) { return merge(merge(a, b), c); }\n\n  pair<Node *, Node *>\
    \ split(Node *root, u32 k) {\n    if (!root) {\n      assert(k == 0);\n      return\
    \ {nullptr, nullptr};\n    }\n    assert(0 <= k && k <= root->size);\n    return\
    \ split_rec(root, k);\n  }\n  tuple<Node *, Node *, Node *> split3(Node *root,\
    \ u32 l, u32 r) {\n    Node *nm, *nr;\n    tie(root, nr) = split(root, r);\n \
    \   tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n\n  Node\
    \ *reverse(Node *root, u32 l, u32 r) {\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (r - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n\
    \    nm->rev ^= 1;\n    prop(nm);\n    update(nm);\n    root = merge3(nl, nm,\
    \ nr);\n    return root;\n  }\n\n  Node *apply(Node *root, u32 l, u32 r, const\
    \ X &a) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (l == r) return\
    \ root;\n    auto [nl, nm, nr] = split3(root, l, r);\n    nm->lazy = Mono::op(nm->lazy,\
    \ a);\n    nm->val = XSet::act(nm->val, a);\n    prop(nm);\n    update(nm);\n\
    \    return merge3(nl, nm, nr);\n  }\n\n  Node *apply_all(Node *root, const X\
    \ &a) {\n    if (!root) return root;\n    root->lazy = Mono::op(root->lazy, a);\n\
    \    root->val = XSet::act(root->val, a);\n    return root;\n  }\n\n  vc<S> get_all(Node\
    \ *root) {\n    vc<S> res;\n    auto dfs = [&](auto &dfs, Node *n, X lazy) ->\
    \ void {\n      if (!n) return;\n      S me = XSet::act(n->val, lazy);\n     \
    \ lazy = Mono::op(n->lazy, lazy);\n      dfs(dfs, n->l, lazy);\n      res.eb(me);\n\
    \      dfs(dfs, n->r, lazy);\n    };\n    dfs(dfs, root, Mono::unit());\n    return\
    \ res;\n  }\n\n  S get(Node *root, u32 idx) { return get_rec(root, idx); }\n\n\
    \  // ok \u5074\u3068 ng \u5074\u306B\u5206\u5272\u3057\u3066 split \u3059\u308B\
    \n  template <typename F>\n  pair<Node *, Node *> binary_search(Node *root, F\
    \ check, bool ok_is_left) {\n    return binary_search_rec(root, check, ok_is_left);\n\
    \  }\n\n  void reset() { pid = 0; }\n\n  void debug(Node *root) {\n    print(\"\
    RBST\");\n    string s;\n    auto dfs = [&](auto &dfs, Node *n) -> void {\n  \
    \    if (!n) return;\n      s += \"l\";\n      dfs(dfs, n->l);\n      s.pop_back();\n\
    \      print(s, \"size\", \"val\", n->val, \"lazy\", n->lazy);\n      s += \"\
    r\";\n      dfs(dfs, n->r);\n      s.pop_back();\n    };\n    dfs(dfs, root);\n\
    \  }\n\nprivate:\n  inline u32 xor128() {\n    static u32 x = 123456789;\n   \
    \ static u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32 w =\
    \ 88675123;\n    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n\
    \    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void prop(Node *c)\
    \ {\n    if (c->lazy != Mono::unit()) {\n      if (c->l) {\n        c->l->val\
    \ = XSet::act(c->l->val, c->lazy);\n        c->l->lazy = Mono::op(c->l->lazy,\
    \ c->lazy);\n      }\n      if (c->r) {\n        c->r->val = XSet::act(c->r->val,\
    \ c->lazy);\n        c->r->lazy = Mono::op(c->r->lazy, c->lazy);\n      }\n  \
    \    c->lazy = Mono::unit();\n    }\n    if (c->rev) {\n      swap(c->l, c->r);\n\
    \      if (c->l) c->l->rev ^= 1;\n      if (c->r) c->r->rev ^= 1;\n      c->rev\
    \ = 0;\n    }\n  }\n\n  void update(Node *c) {\n    c->size = 1;\n    if (c->l)\
    \ { c->size += c->l->size; }\n    if (c->r) { c->size += c->r->size; }\n  }\n\n\
    \  Node *merge_rec(Node *l_root, Node *r_root) {\n    if (!l_root) return r_root;\n\
    \    if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
    \    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n      l_root->r =\
    \ merge_rec(l_root->r, r_root);\n      update(l_root);\n      return l_root;\n\
    \    }\n    prop(r_root);\n    r_root->l = merge_rec(l_root, r_root->l);\n   \
    \ update(r_root);\n    return r_root;\n  }\n\n  pair<Node *, Node *> split_rec(Node\
    \ *root, u32 k) {\n    if (!root) return {nullptr, nullptr};\n    prop(root);\n\
    \    u32 sl = (root->l ? root->l->size : 0);\n    if (k <= sl) {\n      auto [nl,\
    \ nr] = split_rec(root->l, k);\n      root->l = nr;\n      update(root);\n   \
    \   return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r, k - (1 +\
    \ sl));\n    root->r = nl;\n    update(root);\n    return {root, nr};\n  }\n\n\
    \  S get_rec(Node *root, u32 idx) {\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (idx < sl) return Mono::op(get_rec(root->l, idx), root->lazy);\n    if\
    \ (idx == sl) return root->val;\n    return Mono::op(get_rec(root->r, idx - 1\
    \ - sl), root->lazy);\n  }\n\n  template <typename F>\n  pair<Node *, Node *>\
    \ binary_search_rec(Node *root, const F &check,\n                            \
    \             bool ok_is_left) {\n    if (!root) return {nullptr, nullptr};\n\
    \    prop(root);\n    if (check(root) == ok_is_left) {\n      auto [n1, n2] =\
    \ binary_search_rec(root->r, check, ok_is_left);\n      root->r = n1;\n      update(root);\n\
    \      return {root, n2};\n    } else {\n      auto [n1, n2] = binary_search_rec(root->l,\
    \ check, ok_is_left);\n      root->l = n2;\n      update(root);\n      return\
    \ {n1, root};\n    }\n    return {nullptr, nullptr};\n  }\n};\n"
  code: "template <typename XSet, int NODES = 1'000'000>\nstruct RBST_Dual {\n  using\
    \ Mono = typename XSet::Monoid;\n  using X = typename XSet::operator_type;\n \
    \ using S = typename XSet::element_type;\n\n  struct Node {\n    Node *l, *r;\n\
    \    X lazy;\n    S val; // lazy \u306F\u305D\u306E\u30CE\u30FC\u30C9\u306B\u306F\
    \u53CD\u6620\u6E08\n    u32 size;\n    bool rev;\n  };\n\n  Node *pool;\n  int\
    \ pid;\n\n  RBST_Dual() : pid(0) { pool = new Node[NODES]; }\n\n  Node *new_node(const\
    \ S &val) {\n    assert(pid < NODES);\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].lazy = Mono::unit();\n    pool[pid].val = val;\n    pool[pid].size\
    \ = 1;\n    pool[pid].rev = 0;\n    return &(pool[pid++]);\n  }\n\n  Node *new_node(const\
    \ vc<S> &dat) {\n    auto dfs = [&](auto &dfs, int l, int r) -> Node * {\n   \
    \   if (l == r) return nullptr;\n      int m = (l + r) / 2;\n      Node *root\
    \ = new_node(dat[m]);\n      root->l = dfs(dfs, l, m);\n      root->r = dfs(dfs,\
    \ m + 1, r);\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  Node *merge(Node *l_root, Node *r_root) { return merge_rec(l_root, r_root);\
    \ }\n  Node *merge3(Node *a, Node *b, Node *c) { return merge(merge(a, b), c);\
    \ }\n\n  pair<Node *, Node *> split(Node *root, u32 k) {\n    if (!root) {\n \
    \     assert(k == 0);\n      return {nullptr, nullptr};\n    }\n    assert(0 <=\
    \ k && k <= root->size);\n    return split_rec(root, k);\n  }\n  tuple<Node *,\
    \ Node *, Node *> split3(Node *root, u32 l, u32 r) {\n    Node *nm, *nr;\n   \
    \ tie(root, nr) = split(root, r);\n    tie(root, nm) = split(root, l);\n    return\
    \ {root, nm, nr};\n  }\n\n  Node *reverse(Node *root, u32 l, u32 r) {\n    assert(0\
    \ <= l && l <= r && r <= root->size);\n    if (r - l <= 1) return root;\n    auto\
    \ [nl, nm, nr] = split3(root, l, r);\n    nm->rev ^= 1;\n    prop(nm);\n    update(nm);\n\
    \    root = merge3(nl, nm, nr);\n    return root;\n  }\n\n  Node *apply(Node *root,\
    \ u32 l, u32 r, const X &a) {\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (l == r) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n \
    \   nm->lazy = Mono::op(nm->lazy, a);\n    nm->val = XSet::act(nm->val, a);\n\
    \    prop(nm);\n    update(nm);\n    return merge3(nl, nm, nr);\n  }\n\n  Node\
    \ *apply_all(Node *root, const X &a) {\n    if (!root) return root;\n    root->lazy\
    \ = Mono::op(root->lazy, a);\n    root->val = XSet::act(root->val, a);\n    return\
    \ root;\n  }\n\n  vc<S> get_all(Node *root) {\n    vc<S> res;\n    auto dfs =\
    \ [&](auto &dfs, Node *n, X lazy) -> void {\n      if (!n) return;\n      S me\
    \ = XSet::act(n->val, lazy);\n      lazy = Mono::op(n->lazy, lazy);\n      dfs(dfs,\
    \ n->l, lazy);\n      res.eb(me);\n      dfs(dfs, n->r, lazy);\n    };\n    dfs(dfs,\
    \ root, Mono::unit());\n    return res;\n  }\n\n  S get(Node *root, u32 idx) {\
    \ return get_rec(root, idx); }\n\n  // ok \u5074\u3068 ng \u5074\u306B\u5206\u5272\
    \u3057\u3066 split \u3059\u308B\n  template <typename F>\n  pair<Node *, Node\
    \ *> binary_search(Node *root, F check, bool ok_is_left) {\n    return binary_search_rec(root,\
    \ check, ok_is_left);\n  }\n\n  void reset() { pid = 0; }\n\n  void debug(Node\
    \ *root) {\n    print(\"RBST\");\n    string s;\n    auto dfs = [&](auto &dfs,\
    \ Node *n) -> void {\n      if (!n) return;\n      s += \"l\";\n      dfs(dfs,\
    \ n->l);\n      s.pop_back();\n      print(s, \"size\", \"val\", n->val, \"lazy\"\
    , n->lazy);\n      s += \"r\";\n      dfs(dfs, n->r);\n      s.pop_back();\n \
    \   };\n    dfs(dfs, root);\n  }\n\nprivate:\n  inline u32 xor128() {\n    static\
    \ u32 x = 123456789;\n    static u32 y = 362436069;\n    static u32 z = 521288629;\n\
    \    static u32 w = 88675123;\n    u32 t = x ^ (x << 11);\n    x = y;\n    y =\
    \ z;\n    z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void\
    \ prop(Node *c) {\n    if (c->lazy != Mono::unit()) {\n      if (c->l) {\n   \
    \     c->l->val = XSet::act(c->l->val, c->lazy);\n        c->l->lazy = Mono::op(c->l->lazy,\
    \ c->lazy);\n      }\n      if (c->r) {\n        c->r->val = XSet::act(c->r->val,\
    \ c->lazy);\n        c->r->lazy = Mono::op(c->r->lazy, c->lazy);\n      }\n  \
    \    c->lazy = Mono::unit();\n    }\n    if (c->rev) {\n      swap(c->l, c->r);\n\
    \      if (c->l) c->l->rev ^= 1;\n      if (c->r) c->r->rev ^= 1;\n      c->rev\
    \ = 0;\n    }\n  }\n\n  void update(Node *c) {\n    c->size = 1;\n    if (c->l)\
    \ { c->size += c->l->size; }\n    if (c->r) { c->size += c->r->size; }\n  }\n\n\
    \  Node *merge_rec(Node *l_root, Node *r_root) {\n    if (!l_root) return r_root;\n\
    \    if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
    \    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n      l_root->r =\
    \ merge_rec(l_root->r, r_root);\n      update(l_root);\n      return l_root;\n\
    \    }\n    prop(r_root);\n    r_root->l = merge_rec(l_root, r_root->l);\n   \
    \ update(r_root);\n    return r_root;\n  }\n\n  pair<Node *, Node *> split_rec(Node\
    \ *root, u32 k) {\n    if (!root) return {nullptr, nullptr};\n    prop(root);\n\
    \    u32 sl = (root->l ? root->l->size : 0);\n    if (k <= sl) {\n      auto [nl,\
    \ nr] = split_rec(root->l, k);\n      root->l = nr;\n      update(root);\n   \
    \   return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r, k - (1 +\
    \ sl));\n    root->r = nl;\n    update(root);\n    return {root, nr};\n  }\n\n\
    \  S get_rec(Node *root, u32 idx) {\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (idx < sl) return Mono::op(get_rec(root->l, idx), root->lazy);\n    if\
    \ (idx == sl) return root->val;\n    return Mono::op(get_rec(root->r, idx - 1\
    \ - sl), root->lazy);\n  }\n\n  template <typename F>\n  pair<Node *, Node *>\
    \ binary_search_rec(Node *root, const F &check,\n                            \
    \             bool ok_is_left) {\n    if (!root) return {nullptr, nullptr};\n\
    \    prop(root);\n    if (check(root) == ok_is_left) {\n      auto [n1, n2] =\
    \ binary_search_rec(root->r, check, ok_is_left);\n      root->r = n1;\n      update(root);\n\
    \      return {root, n2};\n    } else {\n      auto [n1, n2] = binary_search_rec(root->l,\
    \ check, ok_is_left);\n      root->l = n2;\n      update(root);\n      return\
    \ {n1, root};\n    }\n    return {nullptr, nullptr};\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/bbst/rbst_dual.hpp
  requiredBy: []
  timestamp: '2022-11-28 02:17:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/cf702_F.test.cpp
documentation_of: ds/bbst/rbst_dual.hpp
layout: document
redirect_from:
- /library/ds/bbst/rbst_dual.hpp
- /library/ds/bbst/rbst_dual.hpp.html
title: ds/bbst/rbst_dual.hpp
---
