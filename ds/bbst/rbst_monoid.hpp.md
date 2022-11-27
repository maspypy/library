---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508_2.test.cpp
    title: test/aoj/1508_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_test.test.cpp
    title: test/mytest/rbst_test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bbst/rbst_monoid.hpp\"\n// reverse \u306F\u3068\u308A\
    \u3042\u3048\u305A\u3001Monoid \u306E\u53EF\u63DB\u6027\u3092\u4EEE\u5B9A\u3057\
    \u3066\u3044\u308B\uFF01\ntemplate <typename Monoid, int NODES = 1'000'000>\n\
    struct RBST_Monoid {\n  using X = typename Monoid::value_type;\n\n  struct Node\
    \ {\n    Node *l, *r;\n    X x, prod;\n    u32 size;\n    bool rev;\n  };\n\n\
    \  Node *pool;\n  int pid;\n  using np = Node *;\n\n  RBST_Monoid() : pid(0) {\
    \ pool = new Node[NODES]; }\n\n  void reset() { pid = 0; }\n\n  np new_node(const\
    \ X &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = x;\n  \
    \  pool[pid].prod = x;\n    pool[pid].size = 1;\n    pool[pid].rev = 0;\n    return\
    \ &(pool[pid++]);\n  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs = [&](auto\
    \ &dfs, u32 l, u32 r) -> np {\n      if (l == r) return nullptr;\n      if (r\
    \ == l + 1) return new_node(dat[l]);\n      u32 m = (l + r) / 2;\n      np root\
    \ = new_node(dat[m]);\n      root->l = dfs(dfs, l, m), root->r = dfs(dfs, m +\
    \ 1, r);\n      update(root);\n      return root;\n    };\n    return dfs(dfs,\
    \ 0, len(dat));\n  }\n\n  np merge(np l_root, np r_root) { return merge_rec(l_root,\
    \ r_root); }\n  np merge3(np a, np b, np c) { return merge(merge(a, b), c); }\n\
    \  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a, b), c), d);\
    \ }\n  pair<np, np> split(np root, u32 k) {\n    if (!root) {\n      assert(k\
    \ == 0);\n      return {nullptr, nullptr};\n    }\n    assert(0 <= k && k <= root->size);\n\
    \    return split_rec(root, k);\n  }\n  tuple<np, np, np> split3(np root, u32\
    \ l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n    tie(root,\
    \ nm) = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np, np, np,\
    \ np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root, d) = split(root,\
    \ k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\
    \n  X prod(np root, u32 l, u32 r) {\n    if (l == r) return Monoid::unit();\n\
    \    return prod_rec(root, l, r);\n  }\n\n  np reverse(np root, u32 l, u32 r)\
    \ {\n    assert(Monoid::commute);\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (r - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n\
    \    nm->rev ^= 1;\n    return merge3(nl, nm, nr);\n  }\n\n  np set(np root, u32\
    \ k, const X &x) { return set_rec(root, k, x); }\n  np multiply(np root, u32 k,\
    \ const X &x) { return multiply_rec(root, k, x); }\n  X get(np root, u32 k) {\
    \ return get_rec(root, k); }\n\n  vc<X> get_all(np root) {\n    vc<X> res;\n \
    \   auto dfs = [&](auto &dfs, np root, bool rev) -> void {\n      if (!root) return;\n\
    \      rev ^= root->rev;\n      dfs(dfs, (rev ? root->r : root->l), rev);\n  \
    \    res.eb(root->x);\n      dfs(dfs, (rev ? root->l : root->r), rev);\n    };\n\
    \    dfs(dfs, root, 0);\n    return res;\n  }\n\n  template <typename F>\n  u32\
    \ max_right(np root, const F check, u32 L) {\n    assert(check(Monoid::unit()));\n\
    \    X x = Monoid::unit();\n    return max_right_rec(root, check, L, x);\n  }\n\
    \nprivate:\n  inline u32 xor128() {\n    static u32 x = 123456789;\n    static\
    \ u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32 w = 88675123;\n\
    \    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w\
    \ = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n    if (c->rev)\
    \ {\n      swap(c->l, c->r);\n      if (c->l) c->l->rev ^= 1;\n      if (c->r)\
    \ c->r->rev ^= 1;\n      c->rev = 0;\n    }\n  }\n\n  void update(np c) {\n  \
    \  c->size = 1;\n    c->prod = c->x;\n    if (c->l) {\n      c->size += c->l->size;\n\
    \      c->prod = Monoid::op(c->l->prod, c->prod);\n    }\n    if (c->r) {\n  \
    \    c->size += c->r->size;\n      c->prod = Monoid::op(c->prod, c->r->prod);\n\
    \    }\n  }\n\n  np merge_rec(np l_root, np r_root) {\n    if (!l_root) return\
    \ r_root;\n    if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
    \    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n      l_root->r =\
    \ merge_rec(l_root->r, r_root);\n      update(l_root);\n      return l_root;\n\
    \    }\n    prop(r_root);\n    r_root->l = merge_rec(l_root, r_root->l);\n   \
    \ update(r_root);\n    return r_root;\n  }\n\n  pair<np, np> split_rec(np root,\
    \ u32 k) {\n    if (!root) return {nullptr, nullptr};\n    prop(root);\n    u32\
    \ sl = (root->l ? root->l->size : 0);\n    if (k <= sl) {\n      auto [nl, nr]\
    \ = split_rec(root->l, k);\n      root->l = nr;\n      update(root);\n      return\
    \ {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r, k - (1 + sl));\n\
    \    root->r = nl;\n    update(root);\n    return {root, nr};\n  }\n\n  np set_rec(np\
    \ root, u32 k, const X &x) {\n    if (!root) return root;\n    prop(root);\n \
    \   u32 sl = (root->l ? root->l->size : 0);\n    if (k < sl) {\n      root->l\
    \ = set_rec(root->l, k, x);\n      update(root);\n      return root;\n    }\n\
    \    if (k == sl) {\n      root->x = x;\n      update(root);\n      return root;\n\
    \    }\n    root->r = set_rec(root->r, k - (1 + sl), x);\n    update(root);\n\
    \    return root;\n  }\n\n  np multiply_rec(np root, u32 k, const X &x) {\n  \
    \  if (!root) return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (k < sl) {\n      root->l = multiply_rec(root->l, k, x);\n   \
    \   update(root);\n      return root;\n    }\n    if (k == sl) {\n      root->x\
    \ = Monoid::op(root->x, x);\n      update(root);\n      return root;\n    }\n\
    \    root->r = multiply_rec(root->r, k - (1 + sl), x);\n    update(root);\n  \
    \  return root;\n  }\n\n  X prod_rec(np root, u32 l, u32 r) {\n    prop(root);\n\
    \    if (l == 0 && r == root->size) return root->prod;\n    u32 sl = (root->l\
    \ ? root->l->size : 0);\n    X res = Monoid::unit();\n    if (l < sl) { res =\
    \ Monoid::op(res, prod_rec(root->l, l, min(r, sl))); }\n    if (l <= sl && sl\
    \ < r) res = Monoid::op(res, root->x);\n    u32 k = 1 + sl;\n    if (k < r) res\
    \ = Monoid::op(res, prod_rec(root->r, max(k, l) - k, r - k));\n    return res;\n\
    \  }\n\n  X get_rec(np root, u32 k) {\n    prop(root);\n    u32 sl = (root->l\
    \ ? root->l->size : 0);\n    if (k < sl) return get_rec(root->l, k);\n    if (k\
    \ == sl) return root->x;\n    return get_rec(root->r, k - (1 + sl));\n  }\n\n\
    \  template <typename F>\n  u32 max_right_rec(np n, const F check, u32 L, X &x)\
    \ {\n    if (!n) return 0;\n    if (L == 0) {\n      X y = Monoid::op(x, n->prod);\n\
    \      if (check(y)) {\n        x = y;\n        return n->size;\n      }\n   \
    \ }\n    prop(n);\n    u32 sl = (n->l ? n->l->size : 0);\n    if (L < sl) {\n\
    \      u32 k = max_right_rec(n->l, check, L, x);\n      if (k < sl) return k;\n\
    \    }\n    if (L <= sl) {\n      X y = Monoid::op(x, n->x);\n      if (!check(y))\
    \ { return sl; }\n      x = y;\n    }\n    L = (L > sl ? L - (1 + sl) : 0);\n\
    \    return (1 + sl) + max_right_rec(n->r, check, L, x);\n  }\n};\n"
  code: "// reverse \u306F\u3068\u308A\u3042\u3048\u305A\u3001Monoid \u306E\u53EF\u63DB\
    \u6027\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\uFF01\ntemplate <typename Monoid,\
    \ int NODES = 1'000'000>\nstruct RBST_Monoid {\n  using X = typename Monoid::value_type;\n\
    \n  struct Node {\n    Node *l, *r;\n    X x, prod;\n    u32 size;\n    bool rev;\n\
    \  };\n\n  Node *pool;\n  int pid;\n  using np = Node *;\n\n  RBST_Monoid() :\
    \ pid(0) { pool = new Node[NODES]; }\n\n  void reset() { pid = 0; }\n\n  np new_node(const\
    \ X &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = x;\n  \
    \  pool[pid].prod = x;\n    pool[pid].size = 1;\n    pool[pid].rev = 0;\n    return\
    \ &(pool[pid++]);\n  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs = [&](auto\
    \ &dfs, u32 l, u32 r) -> np {\n      if (l == r) return nullptr;\n      if (r\
    \ == l + 1) return new_node(dat[l]);\n      u32 m = (l + r) / 2;\n      np root\
    \ = new_node(dat[m]);\n      root->l = dfs(dfs, l, m), root->r = dfs(dfs, m +\
    \ 1, r);\n      update(root);\n      return root;\n    };\n    return dfs(dfs,\
    \ 0, len(dat));\n  }\n\n  np merge(np l_root, np r_root) { return merge_rec(l_root,\
    \ r_root); }\n  np merge3(np a, np b, np c) { return merge(merge(a, b), c); }\n\
    \  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a, b), c), d);\
    \ }\n  pair<np, np> split(np root, u32 k) {\n    if (!root) {\n      assert(k\
    \ == 0);\n      return {nullptr, nullptr};\n    }\n    assert(0 <= k && k <= root->size);\n\
    \    return split_rec(root, k);\n  }\n  tuple<np, np, np> split3(np root, u32\
    \ l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n    tie(root,\
    \ nm) = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np, np, np,\
    \ np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root, d) = split(root,\
    \ k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\
    \n  X prod(np root, u32 l, u32 r) {\n    if (l == r) return Monoid::unit();\n\
    \    return prod_rec(root, l, r);\n  }\n\n  np reverse(np root, u32 l, u32 r)\
    \ {\n    assert(Monoid::commute);\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (r - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n\
    \    nm->rev ^= 1;\n    return merge3(nl, nm, nr);\n  }\n\n  np set(np root, u32\
    \ k, const X &x) { return set_rec(root, k, x); }\n  np multiply(np root, u32 k,\
    \ const X &x) { return multiply_rec(root, k, x); }\n  X get(np root, u32 k) {\
    \ return get_rec(root, k); }\n\n  vc<X> get_all(np root) {\n    vc<X> res;\n \
    \   auto dfs = [&](auto &dfs, np root, bool rev) -> void {\n      if (!root) return;\n\
    \      rev ^= root->rev;\n      dfs(dfs, (rev ? root->r : root->l), rev);\n  \
    \    res.eb(root->x);\n      dfs(dfs, (rev ? root->l : root->r), rev);\n    };\n\
    \    dfs(dfs, root, 0);\n    return res;\n  }\n\n  template <typename F>\n  u32\
    \ max_right(np root, const F check, u32 L) {\n    assert(check(Monoid::unit()));\n\
    \    X x = Monoid::unit();\n    return max_right_rec(root, check, L, x);\n  }\n\
    \nprivate:\n  inline u32 xor128() {\n    static u32 x = 123456789;\n    static\
    \ u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32 w = 88675123;\n\
    \    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w\
    \ = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n    if (c->rev)\
    \ {\n      swap(c->l, c->r);\n      if (c->l) c->l->rev ^= 1;\n      if (c->r)\
    \ c->r->rev ^= 1;\n      c->rev = 0;\n    }\n  }\n\n  void update(np c) {\n  \
    \  c->size = 1;\n    c->prod = c->x;\n    if (c->l) {\n      c->size += c->l->size;\n\
    \      c->prod = Monoid::op(c->l->prod, c->prod);\n    }\n    if (c->r) {\n  \
    \    c->size += c->r->size;\n      c->prod = Monoid::op(c->prod, c->r->prod);\n\
    \    }\n  }\n\n  np merge_rec(np l_root, np r_root) {\n    if (!l_root) return\
    \ r_root;\n    if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
    \    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n      l_root->r =\
    \ merge_rec(l_root->r, r_root);\n      update(l_root);\n      return l_root;\n\
    \    }\n    prop(r_root);\n    r_root->l = merge_rec(l_root, r_root->l);\n   \
    \ update(r_root);\n    return r_root;\n  }\n\n  pair<np, np> split_rec(np root,\
    \ u32 k) {\n    if (!root) return {nullptr, nullptr};\n    prop(root);\n    u32\
    \ sl = (root->l ? root->l->size : 0);\n    if (k <= sl) {\n      auto [nl, nr]\
    \ = split_rec(root->l, k);\n      root->l = nr;\n      update(root);\n      return\
    \ {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r, k - (1 + sl));\n\
    \    root->r = nl;\n    update(root);\n    return {root, nr};\n  }\n\n  np set_rec(np\
    \ root, u32 k, const X &x) {\n    if (!root) return root;\n    prop(root);\n \
    \   u32 sl = (root->l ? root->l->size : 0);\n    if (k < sl) {\n      root->l\
    \ = set_rec(root->l, k, x);\n      update(root);\n      return root;\n    }\n\
    \    if (k == sl) {\n      root->x = x;\n      update(root);\n      return root;\n\
    \    }\n    root->r = set_rec(root->r, k - (1 + sl), x);\n    update(root);\n\
    \    return root;\n  }\n\n  np multiply_rec(np root, u32 k, const X &x) {\n  \
    \  if (!root) return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (k < sl) {\n      root->l = multiply_rec(root->l, k, x);\n   \
    \   update(root);\n      return root;\n    }\n    if (k == sl) {\n      root->x\
    \ = Monoid::op(root->x, x);\n      update(root);\n      return root;\n    }\n\
    \    root->r = multiply_rec(root->r, k - (1 + sl), x);\n    update(root);\n  \
    \  return root;\n  }\n\n  X prod_rec(np root, u32 l, u32 r) {\n    prop(root);\n\
    \    if (l == 0 && r == root->size) return root->prod;\n    u32 sl = (root->l\
    \ ? root->l->size : 0);\n    X res = Monoid::unit();\n    if (l < sl) { res =\
    \ Monoid::op(res, prod_rec(root->l, l, min(r, sl))); }\n    if (l <= sl && sl\
    \ < r) res = Monoid::op(res, root->x);\n    u32 k = 1 + sl;\n    if (k < r) res\
    \ = Monoid::op(res, prod_rec(root->r, max(k, l) - k, r - k));\n    return res;\n\
    \  }\n\n  X get_rec(np root, u32 k) {\n    prop(root);\n    u32 sl = (root->l\
    \ ? root->l->size : 0);\n    if (k < sl) return get_rec(root->l, k);\n    if (k\
    \ == sl) return root->x;\n    return get_rec(root->r, k - (1 + sl));\n  }\n\n\
    \  template <typename F>\n  u32 max_right_rec(np n, const F check, u32 L, X &x)\
    \ {\n    if (!n) return 0;\n    if (L == 0) {\n      X y = Monoid::op(x, n->prod);\n\
    \      if (check(y)) {\n        x = y;\n        return n->size;\n      }\n   \
    \ }\n    prop(n);\n    u32 sl = (n->l ? n->l->size : 0);\n    if (L < sl) {\n\
    \      u32 k = max_right_rec(n->l, check, L, x);\n      if (k < sl) return k;\n\
    \    }\n    if (L <= sl) {\n      X y = Monoid::op(x, n->x);\n      if (!check(y))\
    \ { return sl; }\n      x = y;\n    }\n    L = (L > sl ? L - (1 + sl) : 0);\n\
    \    return (1 + sl) + max_right_rec(n->r, check, L, x);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/bbst/rbst_monoid.hpp
  requiredBy: []
  timestamp: '2022-11-28 06:35:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/rbst_test.test.cpp
  - test/aoj/1508_2.test.cpp
documentation_of: ds/bbst/rbst_monoid.hpp
layout: document
redirect_from:
- /library/ds/bbst/rbst_monoid.hpp
- /library/ds/bbst/rbst_monoid.hpp.html
title: ds/bbst/rbst_monoid.hpp
---
