---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/686.test.cpp
    title: test/yukicoder/686.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bbst/rbst_lazy.hpp\"\n\n// reverse \u306F\u3068\u308A\
    \u3042\u3048\u305A\u3001Monoid_X \u306E\u53EF\u63DB\u6027\u3092\u4EEE\u5B9A\u3057\
    \u3066\u3044\u308B\uFF01\ntemplate <typename Lazy, int NODES = 1'000'000>\nstruct\
    \ RBST_Lazy {\n  using Monoid_X = typename Lazy::X_structure;\n  using Monoid_A\
    \ = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n\n  struct Node {\n    Node *l, *r;\n\
    \    X x, prod;\n    A a;\n    int size;\n    bool rev;\n    bool propagated;\n\
    \  };\n\n  Node *pool;\n  int pid;\n\n  RBST_Lazy() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  Node *new_node(const X &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].x = x;\n    pool[pid].prod = x;\n    pool[pid].a = Monoid_A::unit();\n\
    \    pool[pid].size = 1;\n    pool[pid].rev = 0;\n    pool[pid].propagated = 1;\n\
    \    return &(pool[pid++]);\n  }\n\n  Node *new_node(const vc<X> &dat) {\n   \
    \ auto dfs = [&](auto &dfs, int l, int r) -> Node * {\n      if (l == r) return\
    \ nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      int m = (l +\
    \ r) / 2;\n      Node *l_root = dfs(dfs, l, m);\n      Node *r_root = dfs(dfs,\
    \ m + 1, r);\n      Node *root = new_node(dat[m]);\n      root->l = l_root, root->r\
    \ = r_root;\n      update(root);\n      return root;\n    };\n    return dfs(dfs,\
    \ 0, len(dat));\n  }\n\n  // \u5DE6\u306B\u53F3\u3092\u30DE\u30FC\u30B8\n  void\
    \ merge(Node *&root, Node *r_root) {\n    root = merge_rec(root, r_root);\n  \
    \  return;\n  }\n\n  // \u5DE6\u53F3\u306B\u5206\u3051\u3066\u3001root \u3092\u5DE6\
    \u5074\u306B\u5909\u66F4\u3002\u53F3\u5074\u3092 return \u3059\u308B\u3002\n \
    \ Node *split(Node *&root, int k) {\n    if (!root) assert(k == 0);\n    if (root)\
    \ assert(0 <= k && k <= root->size);\n    auto [nl, nr] = split_rec(root, k);\n\
    \    root = nl;\n    return nr;\n  }\n\n  X prod(Node *&root, int l, int r) {\n\
    \    assert(0 <= l && l <= r && r <= root->size);\n    if (l == r) return Monoid_X::unit();\n\
    \    Node *r_root = split(root, r);\n    Node *m_root = split(root, l);\n    X\
    \ res = m_root->prod;\n    merge(root, m_root);\n    merge(root, r_root);\n  \
    \  return res;\n  }\n\n  void reverse(Node *&root, int l, int r) {\n    assert(Monoid_X::commute);\n\
    \    assert(0 <= l && l <= r && r <= root->size);\n    if (r - l <= 1) return;\n\
    \    Node *r_root = split(root, r);\n    Node *m_root = split(root, l);\n    m_root->rev\
    \ ^= 1;\n    prop(m_root);\n    update(m_root);\n    merge(root, m_root);\n  \
    \  merge(root, r_root);\n  }\n\n  void apply(Node *&root, int l, int r, const\
    \ A &a) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (l == r) return;\n\
    \    Node *r_root = split(root, r);\n    Node *m_root = split(root, l);\n    m_root->x\
    \ = Lazy::act(m_root->x, a);\n    m_root->prod = Lazy::act(m_root->prod, a);\n\
    \    m_root->a = Monoid_A::op(m_root->a, a);\n    m_root->propagated = 0;\n  \
    \  prop(m_root);\n    update(m_root);\n    merge(root, m_root);\n    merge(root,\
    \ r_root);\n  }\n\n  void apply(Node *&root, const A &a) {\n    root->x = Lazy::act(root->x,\
    \ a);\n    root->prod = Lazy::act(root->prod, a);\n    root->a = Monoid_A::op(root->a,\
    \ a);\n    root->propagated = 0;\n    prop(root);\n    update(root);\n  }\n\n\
    \  // root \u306E k \u756A\u76EE\u306B n \u3092\u633F\u5165\u3059\u308B\n  void\
    \ insert(Node *&root, int k, Node *n) {\n    if (!root) {\n      assert(k == 0);\n\
    \      root = n;\n      return;\n    }\n    assert(0 <= k && k <= root->size);\n\
    \    auto r_root = split(root, k);\n    merge(root, n);\n    merge(root, r_root);\n\
    \  }\n\n  void insert(Node *&root, int k, const X &x) { insert(root, k, new_node(x));\
    \ }\n\n  // root \u304B\u3089 k \u756A\u76EE\u3092\u524A\u9664\u3002\u524A\u9664\
    \u3057\u305F\u30CE\u30FC\u30C9\u3092\u304B\u3048\u3059\n  Node *erase(Node *&root,\
    \ int k) {\n    assert(0 <= k && k < root->size);\n    auto nr = split(root, k\
    \ + 1);\n    auto nm = split(root, k);\n    merge(root, nr);\n    return nm;\n\
    \  }\n\n  void debug(Node *root) {\n    print(\"RBST\");\n    string s;\n    auto\
    \ dfs = [&](auto &dfs, Node *n) -> void {\n      if (!n) return;\n      s += \"\
    l\";\n      dfs(dfs, n->l);\n      s.pop_back();\n      print(s, \"size\", n->size,\
    \ \"x\", n->x, \"prod\", n->prod, \"apply\", n->a);\n      s += \"r\";\n     \
    \ dfs(dfs, n->r);\n      s.pop_back();\n    };\n    dfs(dfs, root);\n  }\n\n \
    \ template <typename F>\n  int max_right(Node *&root, const F &check, int L) {\n\
    \    assert(check(Monoid_X::unit()));\n    Node *r_root = split(root, L);\n  \
    \  int res = L;\n    max_right_rec(r_root, check, res, Monoid_X::unit());\n  \
    \  merge(root, r_root);\n    return res;\n  }\n\nprivate:\n  inline int xor128()\
    \ {\n    static int x = 123456789;\n    static int y = 362436069;\n    static\
    \ int z = 521288629;\n    static int w = 88675123;\n    int t;\n\n    t = x ^\
    \ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w = (w ^ (w >> 19))\
    \ ^ (t ^ (t >> 8));\n  }\n\n  void prop(Node *c) {\n    if (!c->propagated) {\n\
    \      if (c->l) {\n        c->l->x = Lazy::act(c->l->x, c->a);\n        c->l->prod\
    \ = Lazy::act(c->l->prod, c->a);\n        c->l->a = Monoid_A::op(c->l->a, c->a);\n\
    \        c->l->propagated = 0;\n      }\n      if (c->r) {\n        c->r->x =\
    \ Lazy::act(c->r->x, c->a);\n        c->r->prod = Lazy::act(c->r->prod, c->a);\n\
    \        c->r->a = Monoid_A::op(c->r->a, c->a);\n        c->r->propagated = 0;\n\
    \      }\n      c->a = Monoid_A::unit();\n      c->propagated = 1;\n    }\n  \
    \  if (c->rev) {\n      swap(c->l, c->r);\n      if (c->l) c->l->rev ^= 1;\n \
    \     if (c->r) c->r->rev ^= 1;\n      c->rev = 0;\n    }\n  }\n\n  void update(Node\
    \ *c) {\n    c->size = 1;\n    c->prod = c->x;\n    if (c->l) {\n      c->size\
    \ += c->l->size;\n      c->prod = Monoid_X::op(c->l->prod, c->prod);\n    }\n\
    \    if (c->r) {\n      c->size += c->r->size;\n      c->prod = Monoid_X::op(c->prod,\
    \ c->r->prod);\n    }\n  }\n\n  Node *merge_rec(Node *l_root, Node *r_root) {\n\
    \    if (!l_root) return r_root;\n    if (!r_root) return l_root;\n    int sl\
    \ = l_root->size, sr = r_root->size;\n    if (xor128() % (sl + sr) < sl) {\n \
    \     prop(l_root);\n      l_root->r = merge_rec(l_root->r, r_root);\n      update(l_root);\n\
    \      return l_root;\n    }\n    prop(r_root);\n    r_root->l = merge_rec(l_root,\
    \ r_root->l);\n    update(r_root);\n    return r_root;\n  }\n\n  pair<Node *,\
    \ Node *> split_rec(Node *root, int k) {\n    if (!root) return {nullptr, nullptr};\n\
    \    prop(root);\n    int ls = (root->l ? root->l->size : 0);\n    if (k <= ls)\
    \ {\n      auto [nl, nr] = split_rec(root->l, k);\n      root->l = nr;\n     \
    \ update(root);\n      return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r,\
    \ k - (1 + ls));\n    root->r = nl;\n    update(root);\n    return {root, nr};\n\
    \  }\n\n  template <typename F>\n  void max_right_rec(Node *n, const F check,\
    \ int &res, X x) {\n    int l_sz = (n->l ? n->l->size : 0);\n    prop(n);\n  \
    \  if (check(Monoid_X::op(x, n->prod))) {\n      res += (n->size);\n      return;\n\
    \    }\n    X y = (n->l ? Monoid_X::op(x, n->l->prod) : x);\n    if (!check(y))\
    \ { return max_right_rec(n->l, check, res, x); }\n    if (n->l) res += n->l->size;\n\
    \    x = y;\n    y = Monoid_X::op(x, n->x);\n    if (!check(y)) { return; }\n\
    \    res += 1;\n    return max_right_rec(n->r, check, res, y);\n  }\n};\n"
  code: "\n// reverse \u306F\u3068\u308A\u3042\u3048\u305A\u3001Monoid_X \u306E\u53EF\
    \u63DB\u6027\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\uFF01\ntemplate <typename\
    \ Lazy, int NODES = 1'000'000>\nstruct RBST_Lazy {\n  using Monoid_X = typename\
    \ Lazy::X_structure;\n  using Monoid_A = typename Lazy::A_structure;\n  using\
    \ X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \n  struct Node {\n    Node *l, *r;\n    X x, prod;\n    A a;\n    int size;\n\
    \    bool rev;\n    bool propagated;\n  };\n\n  Node *pool;\n  int pid;\n\n  RBST_Lazy()\
    \ : pid(0) { pool = new Node[NODES]; }\n\n  Node *new_node(const X &x) {\n   \
    \ pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod\
    \ = x;\n    pool[pid].a = Monoid_A::unit();\n    pool[pid].size = 1;\n    pool[pid].rev\
    \ = 0;\n    pool[pid].propagated = 1;\n    return &(pool[pid++]);\n  }\n\n  Node\
    \ *new_node(const vc<X> &dat) {\n    auto dfs = [&](auto &dfs, int l, int r) ->\
    \ Node * {\n      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      int m = (l + r) / 2;\n      Node *l_root = dfs(dfs, l, m);\n      Node\
    \ *r_root = dfs(dfs, m + 1, r);\n      Node *root = new_node(dat[m]);\n      root->l\
    \ = l_root, root->r = r_root;\n      update(root);\n      return root;\n    };\n\
    \    return dfs(dfs, 0, len(dat));\n  }\n\n  // \u5DE6\u306B\u53F3\u3092\u30DE\
    \u30FC\u30B8\n  void merge(Node *&root, Node *r_root) {\n    root = merge_rec(root,\
    \ r_root);\n    return;\n  }\n\n  // \u5DE6\u53F3\u306B\u5206\u3051\u3066\u3001\
    root \u3092\u5DE6\u5074\u306B\u5909\u66F4\u3002\u53F3\u5074\u3092 return \u3059\
    \u308B\u3002\n  Node *split(Node *&root, int k) {\n    if (!root) assert(k ==\
    \ 0);\n    if (root) assert(0 <= k && k <= root->size);\n    auto [nl, nr] = split_rec(root,\
    \ k);\n    root = nl;\n    return nr;\n  }\n\n  X prod(Node *&root, int l, int\
    \ r) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (l == r) return\
    \ Monoid_X::unit();\n    Node *r_root = split(root, r);\n    Node *m_root = split(root,\
    \ l);\n    X res = m_root->prod;\n    merge(root, m_root);\n    merge(root, r_root);\n\
    \    return res;\n  }\n\n  void reverse(Node *&root, int l, int r) {\n    assert(Monoid_X::commute);\n\
    \    assert(0 <= l && l <= r && r <= root->size);\n    if (r - l <= 1) return;\n\
    \    Node *r_root = split(root, r);\n    Node *m_root = split(root, l);\n    m_root->rev\
    \ ^= 1;\n    prop(m_root);\n    update(m_root);\n    merge(root, m_root);\n  \
    \  merge(root, r_root);\n  }\n\n  void apply(Node *&root, int l, int r, const\
    \ A &a) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (l == r) return;\n\
    \    Node *r_root = split(root, r);\n    Node *m_root = split(root, l);\n    m_root->x\
    \ = Lazy::act(m_root->x, a);\n    m_root->prod = Lazy::act(m_root->prod, a);\n\
    \    m_root->a = Monoid_A::op(m_root->a, a);\n    m_root->propagated = 0;\n  \
    \  prop(m_root);\n    update(m_root);\n    merge(root, m_root);\n    merge(root,\
    \ r_root);\n  }\n\n  void apply(Node *&root, const A &a) {\n    root->x = Lazy::act(root->x,\
    \ a);\n    root->prod = Lazy::act(root->prod, a);\n    root->a = Monoid_A::op(root->a,\
    \ a);\n    root->propagated = 0;\n    prop(root);\n    update(root);\n  }\n\n\
    \  // root \u306E k \u756A\u76EE\u306B n \u3092\u633F\u5165\u3059\u308B\n  void\
    \ insert(Node *&root, int k, Node *n) {\n    if (!root) {\n      assert(k == 0);\n\
    \      root = n;\n      return;\n    }\n    assert(0 <= k && k <= root->size);\n\
    \    auto r_root = split(root, k);\n    merge(root, n);\n    merge(root, r_root);\n\
    \  }\n\n  void insert(Node *&root, int k, const X &x) { insert(root, k, new_node(x));\
    \ }\n\n  // root \u304B\u3089 k \u756A\u76EE\u3092\u524A\u9664\u3002\u524A\u9664\
    \u3057\u305F\u30CE\u30FC\u30C9\u3092\u304B\u3048\u3059\n  Node *erase(Node *&root,\
    \ int k) {\n    assert(0 <= k && k < root->size);\n    auto nr = split(root, k\
    \ + 1);\n    auto nm = split(root, k);\n    merge(root, nr);\n    return nm;\n\
    \  }\n\n  void debug(Node *root) {\n    print(\"RBST\");\n    string s;\n    auto\
    \ dfs = [&](auto &dfs, Node *n) -> void {\n      if (!n) return;\n      s += \"\
    l\";\n      dfs(dfs, n->l);\n      s.pop_back();\n      print(s, \"size\", n->size,\
    \ \"x\", n->x, \"prod\", n->prod, \"apply\", n->a);\n      s += \"r\";\n     \
    \ dfs(dfs, n->r);\n      s.pop_back();\n    };\n    dfs(dfs, root);\n  }\n\n \
    \ template <typename F>\n  int max_right(Node *&root, const F &check, int L) {\n\
    \    assert(check(Monoid_X::unit()));\n    Node *r_root = split(root, L);\n  \
    \  int res = L;\n    max_right_rec(r_root, check, res, Monoid_X::unit());\n  \
    \  merge(root, r_root);\n    return res;\n  }\n\nprivate:\n  inline int xor128()\
    \ {\n    static int x = 123456789;\n    static int y = 362436069;\n    static\
    \ int z = 521288629;\n    static int w = 88675123;\n    int t;\n\n    t = x ^\
    \ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w = (w ^ (w >> 19))\
    \ ^ (t ^ (t >> 8));\n  }\n\n  void prop(Node *c) {\n    if (!c->propagated) {\n\
    \      if (c->l) {\n        c->l->x = Lazy::act(c->l->x, c->a);\n        c->l->prod\
    \ = Lazy::act(c->l->prod, c->a);\n        c->l->a = Monoid_A::op(c->l->a, c->a);\n\
    \        c->l->propagated = 0;\n      }\n      if (c->r) {\n        c->r->x =\
    \ Lazy::act(c->r->x, c->a);\n        c->r->prod = Lazy::act(c->r->prod, c->a);\n\
    \        c->r->a = Monoid_A::op(c->r->a, c->a);\n        c->r->propagated = 0;\n\
    \      }\n      c->a = Monoid_A::unit();\n      c->propagated = 1;\n    }\n  \
    \  if (c->rev) {\n      swap(c->l, c->r);\n      if (c->l) c->l->rev ^= 1;\n \
    \     if (c->r) c->r->rev ^= 1;\n      c->rev = 0;\n    }\n  }\n\n  void update(Node\
    \ *c) {\n    c->size = 1;\n    c->prod = c->x;\n    if (c->l) {\n      c->size\
    \ += c->l->size;\n      c->prod = Monoid_X::op(c->l->prod, c->prod);\n    }\n\
    \    if (c->r) {\n      c->size += c->r->size;\n      c->prod = Monoid_X::op(c->prod,\
    \ c->r->prod);\n    }\n  }\n\n  Node *merge_rec(Node *l_root, Node *r_root) {\n\
    \    if (!l_root) return r_root;\n    if (!r_root) return l_root;\n    int sl\
    \ = l_root->size, sr = r_root->size;\n    if (xor128() % (sl + sr) < sl) {\n \
    \     prop(l_root);\n      l_root->r = merge_rec(l_root->r, r_root);\n      update(l_root);\n\
    \      return l_root;\n    }\n    prop(r_root);\n    r_root->l = merge_rec(l_root,\
    \ r_root->l);\n    update(r_root);\n    return r_root;\n  }\n\n  pair<Node *,\
    \ Node *> split_rec(Node *root, int k) {\n    if (!root) return {nullptr, nullptr};\n\
    \    prop(root);\n    int ls = (root->l ? root->l->size : 0);\n    if (k <= ls)\
    \ {\n      auto [nl, nr] = split_rec(root->l, k);\n      root->l = nr;\n     \
    \ update(root);\n      return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r,\
    \ k - (1 + ls));\n    root->r = nl;\n    update(root);\n    return {root, nr};\n\
    \  }\n\n  template <typename F>\n  void max_right_rec(Node *n, const F check,\
    \ int &res, X x) {\n    int l_sz = (n->l ? n->l->size : 0);\n    prop(n);\n  \
    \  if (check(Monoid_X::op(x, n->prod))) {\n      res += (n->size);\n      return;\n\
    \    }\n    X y = (n->l ? Monoid_X::op(x, n->l->prod) : x);\n    if (!check(y))\
    \ { return max_right_rec(n->l, check, res, x); }\n    if (n->l) res += n->l->size;\n\
    \    x = y;\n    y = Monoid_X::op(x, n->x);\n    if (!check(y)) { return; }\n\
    \    res += 1;\n    return max_right_rec(n->r, check, res, y);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/bbst/rbst_lazy.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/686.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
documentation_of: ds/bbst/rbst_lazy.hpp
layout: document
redirect_from:
- /library/ds/bbst/rbst_lazy.hpp
- /library/ds/bbst/rbst_lazy.hpp.html
title: ds/bbst/rbst_lazy.hpp
---
