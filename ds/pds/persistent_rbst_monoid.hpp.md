---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/pds/persistent_rbst_monoid.hpp\"\n// reverse \u306F\u3068\
    \u308A\u3042\u3048\u305A\u3001Monoid \u306E\u53EF\u63DB\u6027\u3092\u4EEE\u5B9A\
    \u3057\u3066\u3044\u308B\uFF01\ntemplate <typename Monoid, int NODES = 1'000'000>\n\
    struct Persistent_RBST_Monoid {\n  using X = typename Monoid::value_type;\n\n\
    \  struct Node {\n    Node *l, *r;\n    X x, prod;\n    int size;\n    bool rev;\n\
    \  };\n\n  Node *pool;\n  int pid;\n\n  Persistent_RBST_Monoid() : pid(0) { pool\
    \ = new Node[NODES]; }\n\n  Node *new_node(const X &x) {\n    pool[pid].l = pool[pid].r\
    \ = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod = x;\n    pool[pid].size\
    \ = 1;\n    pool[pid].rev = 0;\n    return &(pool[pid++]);\n  }\n\n  Node *new_node(const\
    \ vc<X> &dat) {\n    auto dfs = [&](auto &dfs, int l, int r) -> Node * {\n   \
    \   if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      int m = (l + r) / 2;\n      Node *l_root = dfs(dfs, l, m);\n      Node\
    \ *r_root = dfs(dfs, m + 1, r);\n      Node *root = new_node(dat[m]);\n      root->l\
    \ = l_root, root->r = r_root;\n      update(root);\n      return root;\n    };\n\
    \    return dfs(dfs, 0, len(dat));\n  }\n\n  Node *merge(Node *root, Node *r_root)\
    \ {\n    root = merge_rec(root, r_root);\n    return root;\n  }\n\n  Node *merge3(Node\
    \ *a, Node *b, Node *c) { return merge(merge(a, b), c); }\n\n  tuple<Node *, Node\
    \ *, Node *> split3(Node *root, int l, int r) {\n    auto [nlm, nr] = split(root,\
    \ r);\n    auto [nl, nm] = split(nlm, l);\n    return {nl, nm, nr};\n  }\n\n \
    \ // \u5DE6\u53F3\u306B\u5206\u3051\u3066\u3001root \u3092\u5DE6\u5074\u306B\u5909\
    \u66F4\u3002\u53F3\u5074\u3092 return \u3059\u308B\u3002\n  pair<Node *, Node\
    \ *> split(Node *root, int k) {\n    if (!root) assert(k == 0);\n    if (root)\
    \ assert(0 <= k && k <= root->size);\n    return split_rec(root, k);\n  }\n\n\
    \  X prod(Node *root, int l, int r) {\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (l == r) return Monoid::unit();\n    auto [nl, nm, nr] = split3(root,\
    \ l, r);\n    return nm->prod;\n  }\n\n  Node *reverse(Node *root, int l, int\
    \ r) {\n    assert(Monoid::commute);\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (r - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n\
    \    nm = copy_node(nm);\n    nm->rev ^= 1;\n    prop(nm);\n    update(nm);\n\
    \    root = merge3(nl, nm, nr);\n    return root;\n  }\n\n  // root \u306E k \u756A\
    \u76EE\u306B n \u3092\u633F\u5165\u3059\u308B\n  Node *insert(Node *root, int\
    \ k, Node *n) {\n    if (!root) {\n      assert(k == 0);\n      return n;\n  \
    \  }\n    assert(0 <= k && k <= root->size);\n    auto [nl, nr] = split(root,\
    \ k);\n    return merge3(nl, n, nr);\n  }\n\n  Node *insert(Node *root, int k,\
    \ const X &x) {\n    return insert(root, k, new_node(x));\n  }\n\n  pair<Node\
    \ *, Node *> erase(Node *root, int k) {\n    assert(0 <= k && k < root->size);\n\
    \    auto [nl, nm, nr] = split(root, k, k + 1);\n    root = merge(nl, nr);\n \
    \   return {root, nm};\n  }\n\n  vc<X> restore(Node *root) {\n    vc<X> res;\n\
    \    auto dfs = [&](auto &dfs, Node *n) -> void {\n      if (!n) return;\n   \
    \   prop(n);\n      dfs(dfs, n->l);\n      res.eb(n->x);\n      dfs(dfs, n->r);\n\
    \    };\n    dfs(dfs, root);\n    return res;\n  }\n\n  void reset() { pid = 0;\
    \ }\n\n  void debug(Node *root) {\n    print(\"RBST\");\n    string s;\n    auto\
    \ dfs = [&](auto &dfs, Node *n) -> void {\n      if (!n) return;\n      s += \"\
    l\";\n      dfs(dfs, n->l);\n      s.pop_back();\n      print(s, \"size\", n->size,\
    \ \"x\", n->x, \"prod\", n->prod, \"apply\", n->a);\n      s += \"r\";\n     \
    \ dfs(dfs, n->r);\n      s.pop_back();\n    };\n    dfs(dfs, root);\n  }\n\nprivate:\n\
    \  Node *copy_node(Node *n) {\n    if (!n) return nullptr;\n    pool[pid].l =\
    \ n->l;\n    pool[pid].r = n->r;\n    pool[pid].x = n->x;\n    pool[pid].prod\
    \ = n->prod;\n    pool[pid].size = n->size;\n    pool[pid].rev = n->rev;\n   \
    \ return &(pool[pid++]);\n  }\n\n  inline int xor128() {\n    static int x = 123456789;\n\
    \    static int y = 362436069;\n    static int z = 521288629;\n    static int\
    \ w = 88675123;\n    int t;\n\n    t = x ^ (x << 11);\n    x = y;\n    y = z;\n\
    \    z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void prop(Node\
    \ *c) {\n    if (c->rev) {\n      c->l = copy_node(c->l);\n      c->r = copy_node(c->r);\n\
    \      swap(c->l, c->r);\n      if (c->l) c->l->rev ^= 1;\n      if (c->r) c->r->rev\
    \ ^= 1;\n      c->rev = 0;\n    }\n  }\n\n  void update(Node *c) {\n    c->size\
    \ = 1;\n    c->prod = c->x;\n    if (c->l) {\n      c->size += c->l->size;\n \
    \     c->prod = Monoid::op(c->l->prod, c->prod);\n    }\n    if (c->r) {\n   \
    \   c->size += c->r->size;\n      c->prod = Monoid::op(c->prod, c->r->prod);\n\
    \    }\n  }\n\n  Node *merge_rec(Node *l_root, Node *r_root) {\n    if (!l_root)\
    \ return r_root;\n    if (!r_root) return l_root;\n    int sl = l_root->size,\
    \ sr = r_root->size;\n    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n\
    \      l_root->r = merge_rec(l_root->r, r_root);\n      update(l_root);\n    \
    \  return l_root;\n    }\n    prop(r_root);\n    r_root->l = merge_rec(l_root,\
    \ r_root->l);\n    update(r_root);\n    return r_root;\n  }\n\n  pair<Node *,\
    \ Node *> split_rec(Node *root, int k) {\n    if (!root) return {nullptr, nullptr};\n\
    \    prop(root);\n    int ls = (root->l ? root->l->size : 0);\n    if (k <= ls)\
    \ {\n      auto [nl, nr] = split_rec(root->l, k);\n      root = copy_node(root);\n\
    \      root->l = nr;\n      update(root);\n      return {nl, root};\n    }\n \
    \   auto [nl, nr] = split_rec(root->r, k - (1 + ls));\n    root = copy_node(root);\n\
    \    root->r = nl;\n    update(root);\n    return {root, nr};\n  }\n};\n"
  code: "// reverse \u306F\u3068\u308A\u3042\u3048\u305A\u3001Monoid \u306E\u53EF\u63DB\
    \u6027\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\uFF01\ntemplate <typename Monoid,\
    \ int NODES = 1'000'000>\nstruct Persistent_RBST_Monoid {\n  using X = typename\
    \ Monoid::value_type;\n\n  struct Node {\n    Node *l, *r;\n    X x, prod;\n \
    \   int size;\n    bool rev;\n  };\n\n  Node *pool;\n  int pid;\n\n  Persistent_RBST_Monoid()\
    \ : pid(0) { pool = new Node[NODES]; }\n\n  Node *new_node(const X &x) {\n   \
    \ pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod\
    \ = x;\n    pool[pid].size = 1;\n    pool[pid].rev = 0;\n    return &(pool[pid++]);\n\
    \  }\n\n  Node *new_node(const vc<X> &dat) {\n    auto dfs = [&](auto &dfs, int\
    \ l, int r) -> Node * {\n      if (l == r) return nullptr;\n      if (r == l +\
    \ 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n      Node *l_root\
    \ = dfs(dfs, l, m);\n      Node *r_root = dfs(dfs, m + 1, r);\n      Node *root\
    \ = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n      update(root);\n\
    \      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  Node\
    \ *merge(Node *root, Node *r_root) {\n    root = merge_rec(root, r_root);\n  \
    \  return root;\n  }\n\n  Node *merge3(Node *a, Node *b, Node *c) { return merge(merge(a,\
    \ b), c); }\n\n  tuple<Node *, Node *, Node *> split3(Node *root, int l, int r)\
    \ {\n    auto [nlm, nr] = split(root, r);\n    auto [nl, nm] = split(nlm, l);\n\
    \    return {nl, nm, nr};\n  }\n\n  // \u5DE6\u53F3\u306B\u5206\u3051\u3066\u3001\
    root \u3092\u5DE6\u5074\u306B\u5909\u66F4\u3002\u53F3\u5074\u3092 return \u3059\
    \u308B\u3002\n  pair<Node *, Node *> split(Node *root, int k) {\n    if (!root)\
    \ assert(k == 0);\n    if (root) assert(0 <= k && k <= root->size);\n    return\
    \ split_rec(root, k);\n  }\n\n  X prod(Node *root, int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= root->size);\n    if (l == r) return Monoid::unit();\n\
    \    auto [nl, nm, nr] = split3(root, l, r);\n    return nm->prod;\n  }\n\n  Node\
    \ *reverse(Node *root, int l, int r) {\n    assert(Monoid::commute);\n    assert(0\
    \ <= l && l <= r && r <= root->size);\n    if (r - l <= 1) return root;\n    auto\
    \ [nl, nm, nr] = split3(root, l, r);\n    nm = copy_node(nm);\n    nm->rev ^=\
    \ 1;\n    prop(nm);\n    update(nm);\n    root = merge3(nl, nm, nr);\n    return\
    \ root;\n  }\n\n  // root \u306E k \u756A\u76EE\u306B n \u3092\u633F\u5165\u3059\
    \u308B\n  Node *insert(Node *root, int k, Node *n) {\n    if (!root) {\n     \
    \ assert(k == 0);\n      return n;\n    }\n    assert(0 <= k && k <= root->size);\n\
    \    auto [nl, nr] = split(root, k);\n    return merge3(nl, n, nr);\n  }\n\n \
    \ Node *insert(Node *root, int k, const X &x) {\n    return insert(root, k, new_node(x));\n\
    \  }\n\n  pair<Node *, Node *> erase(Node *root, int k) {\n    assert(0 <= k &&\
    \ k < root->size);\n    auto [nl, nm, nr] = split(root, k, k + 1);\n    root =\
    \ merge(nl, nr);\n    return {root, nm};\n  }\n\n  vc<X> restore(Node *root) {\n\
    \    vc<X> res;\n    auto dfs = [&](auto &dfs, Node *n) -> void {\n      if (!n)\
    \ return;\n      prop(n);\n      dfs(dfs, n->l);\n      res.eb(n->x);\n      dfs(dfs,\
    \ n->r);\n    };\n    dfs(dfs, root);\n    return res;\n  }\n\n  void reset()\
    \ { pid = 0; }\n\n  void debug(Node *root) {\n    print(\"RBST\");\n    string\
    \ s;\n    auto dfs = [&](auto &dfs, Node *n) -> void {\n      if (!n) return;\n\
    \      s += \"l\";\n      dfs(dfs, n->l);\n      s.pop_back();\n      print(s,\
    \ \"size\", n->size, \"x\", n->x, \"prod\", n->prod, \"apply\", n->a);\n     \
    \ s += \"r\";\n      dfs(dfs, n->r);\n      s.pop_back();\n    };\n    dfs(dfs,\
    \ root);\n  }\n\nprivate:\n  Node *copy_node(Node *n) {\n    if (!n) return nullptr;\n\
    \    pool[pid].l = n->l;\n    pool[pid].r = n->r;\n    pool[pid].x = n->x;\n \
    \   pool[pid].prod = n->prod;\n    pool[pid].size = n->size;\n    pool[pid].rev\
    \ = n->rev;\n    return &(pool[pid++]);\n  }\n\n  inline int xor128() {\n    static\
    \ int x = 123456789;\n    static int y = 362436069;\n    static int z = 521288629;\n\
    \    static int w = 88675123;\n    int t;\n\n    t = x ^ (x << 11);\n    x = y;\n\
    \    y = z;\n    z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\
    \n  void prop(Node *c) {\n    if (c->rev) {\n      c->l = copy_node(c->l);\n \
    \     c->r = copy_node(c->r);\n      swap(c->l, c->r);\n      if (c->l) c->l->rev\
    \ ^= 1;\n      if (c->r) c->r->rev ^= 1;\n      c->rev = 0;\n    }\n  }\n\n  void\
    \ update(Node *c) {\n    c->size = 1;\n    c->prod = c->x;\n    if (c->l) {\n\
    \      c->size += c->l->size;\n      c->prod = Monoid::op(c->l->prod, c->prod);\n\
    \    }\n    if (c->r) {\n      c->size += c->r->size;\n      c->prod = Monoid::op(c->prod,\
    \ c->r->prod);\n    }\n  }\n\n  Node *merge_rec(Node *l_root, Node *r_root) {\n\
    \    if (!l_root) return r_root;\n    if (!r_root) return l_root;\n    int sl\
    \ = l_root->size, sr = r_root->size;\n    if (xor128() % (sl + sr) < sl) {\n \
    \     prop(l_root);\n      l_root->r = merge_rec(l_root->r, r_root);\n      update(l_root);\n\
    \      return l_root;\n    }\n    prop(r_root);\n    r_root->l = merge_rec(l_root,\
    \ r_root->l);\n    update(r_root);\n    return r_root;\n  }\n\n  pair<Node *,\
    \ Node *> split_rec(Node *root, int k) {\n    if (!root) return {nullptr, nullptr};\n\
    \    prop(root);\n    int ls = (root->l ? root->l->size : 0);\n    if (k <= ls)\
    \ {\n      auto [nl, nr] = split_rec(root->l, k);\n      root = copy_node(root);\n\
    \      root->l = nr;\n      update(root);\n      return {nl, root};\n    }\n \
    \   auto [nl, nr] = split_rec(root->r, k - (1 + ls));\n    root = copy_node(root);\n\
    \    root->r = nl;\n    update(root);\n    return {root, nr};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/pds/persistent_rbst_monoid.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/pds/persistent_rbst_monoid.hpp
layout: document
redirect_from:
- /library/ds/pds/persistent_rbst_monoid.hpp
- /library/ds/pds/persistent_rbst_monoid.hpp.html
title: ds/pds/persistent_rbst_monoid.hpp
---
