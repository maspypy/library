---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/contest/1516/problem/8240
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\ntemplate <class Node>\nstruct Node_Pool\
    \ {\n  struct Slot {\n    union alignas(Node) {\n      Slot* next;\n      unsigned\
    \ char storage[sizeof(Node)];\n    };\n  };\n  using np = Node*;\n\n  static constexpr\
    \ int CHUNK_SIZE = 1 << 16;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur =\
    \ nullptr;\n  int cur_used = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool()\
    \ { alloc_chunk(); }\n\n  template <class... Args>\n  np create(Args&&... args)\
    \ {\n    Slot* s = new_slot();\n    return ::new (s) Node(forward<Args>(args)...);\n\
    \  }\n\n  np clone(const np x) {\n    assert(x);\n    Slot* s = new_slot();\n\
    \    return ::new (s) Node(*x);  // \u30B3\u30D4\u30FC\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u547C\u3073\u51FA\u3057\n  }\n\n  void destroy(np x) {\n  \
    \  if (!x) return;\n    x->~Node();\n    auto s = reinterpret_cast<Slot*>(x);\n\
    \    s->next = free_head;\n    free_head = s;\n  }\n\n  void reset() {\n    free_head\
    \ = nullptr;\n    if (!chunks.empty()) {\n      cur = chunks[0].get();\n     \
    \ cur_used = 0;\n    }\n  }\n\n private:\n  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n#line 2 \"ds/segtree/dynamic_dual_segtree.hpp\"\n\
    \n// Q*2logN \u7A0B\u5EA6\u5FC5\u8981\n// https://qoj.ac/contest/1516/problem/8240\n\
    template <typename Monoid, bool PERSISTENT>\nstruct Dynamic_Dual_SegTree {\n \
    \ using MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node {\n\
    \    Node *l, *r;\n    X x;\n  };\n\n  const ll L0, R0;\n  Node_Pool<Node> pool;\n\
    \  using np = Node *;\n\n  Dynamic_Dual_SegTree(ll L0, ll R0) : L0(L0), R0(R0)\
    \ {}\n\n  np new_root() { return new_node(MX::unit()); }\n\n  np new_node(const\
    \ X x = MX::unit()) {\n    np c = pool.create();\n    c->l = c->r = nullptr, c->x\
    \ = x;\n    return c;\n  }\n\n  np new_node(const vc<X> &dat) {\n    assert(L0\
    \ == 0 && R0 == len(dat));\n    auto dfs = [&](auto &dfs, ll l, ll r) -> Node\
    \ * {\n      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      ll m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs,\
    \ m, r);\n      X x = MX::op(l_root->x, r_root->x);\n      np root = new_node();\n\
    \      root->l = l_root, root->r = r_root;\n      return root;\n    };\n    return\
    \ dfs(dfs, 0, len(dat));\n  }\n\n  X get(np root, ll i) {\n    if (!root) return\
    \ MX::unit();\n    X x = MX::unit();\n    get_rec(root, L0, R0, i, x);\n    return\
    \ x;\n  }\n\n  np apply(np root, ll l, ll r, const X &x) {\n    if (l == r) return\
    \ root;\n    assert(root && L0 <= l && l < r && r <= R0);\n    root = clone(root);\n\
    \    apply_rec(root, L0, R0, l, r, x);\n    return root;\n  }\n\n  // root[l:r)\
    \ \u3092 other[l:r)*x \u3067\u4E0A\u66F8\u304D\u3057\u305F\u3082\u306E\u3092\u8FD4\
    \u3059\n  np copy_interval(np root, np other, ll l, ll r, X x) {\n    if (root\
    \ == other) return root;\n    root = clone(root);\n    copy_interval_rec(root,\
    \ other, L0, R0, l, r, x);\n    return root;\n  }\n\n  void reset() { pool.reset();\
    \ }\n\n  vc<X> get_all(np root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs,\
    \ np c, ll L, ll R, X x) -> void {\n      if (!c) {\n        FOR(R - L) res.eb(x);\n\
    \        return;\n      }\n      x = MX::op(c->x, x);\n      if (R == L + 1) {\n\
    \        res.eb(x);\n        return;\n      }\n      ll M = (L + R) / 2;\n   \
    \   dfs(dfs, c->l, L, M, x);\n      dfs(dfs, c->r, M, R, x);\n    };\n    dfs(dfs,\
    \ root, L0, R0, MX::unit());\n    return res;\n  }\n\n private:\n  np clone(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    return pool.clone(c);\n  }\n\
    \n  void apply_rec(np c, ll l, ll r, ll ql, ll qr, const X &a) {\n    // \u3082\
    \u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    assert(c);\n  \
    \  chmax(ql, l), chmin(qr, r);\n    if (a == MX::unit() || ql >= qr) return;\n\
    \    if (l == ql && r == qr) {\n      c->x = MX::op(c->x, a);\n      return;\n\
    \    }\n    // push\n    c->l = (c->l ? clone(c->l) : new_node());\n    c->r =\
    \ (c->r ? clone(c->r) : new_node());\n    c->l->x = MX::op(c->l->x, c->x);\n \
    \   c->r->x = MX::op(c->r->x, c->x);\n    c->x = MX::unit();\n    ll m = (l +\
    \ r) / 2;\n    apply_rec(c->l, l, m, ql, qr, a), apply_rec(c->r, m, r, ql, qr,\
    \ a);\n    return;\n  }\n\n  void copy_interval_rec(np c, np d, ll l, ll r, ll\
    \ ql, ll qr, X x) {\n    // c[ql,qr) <- d[ql,qr) * x\n    // \u3082\u3046 c \u306F\
    \u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    assert(c);\n    chmax(ql, l),\
    \ chmin(qr, r);\n    if (ql >= qr) return;\n    if (l == ql && r == qr) {\n  \
    \    if (d)\n        c->x = MX::op(d->x, x), c->l = d->l, c->r = d->r;\n     \
    \ else\n        c->x = x, c->l = nullptr, c->r = nullptr;\n      return;\n   \
    \ }\n    // push\n    c->l = (c->l ? clone(c->l) : new_node());\n    c->r = (c->r\
    \ ? clone(c->r) : new_node());\n    c->l->x = MX::op(c->l->x, c->x);\n    c->r->x\
    \ = MX::op(c->r->x, c->x);\n    c->x = MX::unit();\n    ll m = (l + r) / 2;\n\
    \    if (d) x = MX::op(d->x, x);\n    copy_interval_rec(c->l, (d && d->l ? d->l\
    \ : nullptr), l, m, ql, qr, x);\n    copy_interval_rec(c->r, (d && d->r ? d->r\
    \ : nullptr), m, r, ql, qr, x);\n    return;\n  }\n\n  void get_rec(np c, ll l,\
    \ ll r, ll i, X &x) {\n    if (!c) return;\n    x = MX::op(c->x, x);\n    if (r\
    \ == l + 1) {\n      return;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) return\
    \ get_rec(c->l, l, m, i, x);\n    return get_rec(c->r, m, r, i, x);\n  }\n};\n"
  code: "#include \"ds/node_pool.hpp\"\n\n// Q*2logN \u7A0B\u5EA6\u5FC5\u8981\n//\
    \ https://qoj.ac/contest/1516/problem/8240\ntemplate <typename Monoid, bool PERSISTENT>\n\
    struct Dynamic_Dual_SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \n  struct Node {\n    Node *l, *r;\n    X x;\n  };\n\n  const ll L0, R0;\n  Node_Pool<Node>\
    \ pool;\n  using np = Node *;\n\n  Dynamic_Dual_SegTree(ll L0, ll R0) : L0(L0),\
    \ R0(R0) {}\n\n  np new_root() { return new_node(MX::unit()); }\n\n  np new_node(const\
    \ X x = MX::unit()) {\n    np c = pool.create();\n    c->l = c->r = nullptr, c->x\
    \ = x;\n    return c;\n  }\n\n  np new_node(const vc<X> &dat) {\n    assert(L0\
    \ == 0 && R0 == len(dat));\n    auto dfs = [&](auto &dfs, ll l, ll r) -> Node\
    \ * {\n      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      ll m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs,\
    \ m, r);\n      X x = MX::op(l_root->x, r_root->x);\n      np root = new_node();\n\
    \      root->l = l_root, root->r = r_root;\n      return root;\n    };\n    return\
    \ dfs(dfs, 0, len(dat));\n  }\n\n  X get(np root, ll i) {\n    if (!root) return\
    \ MX::unit();\n    X x = MX::unit();\n    get_rec(root, L0, R0, i, x);\n    return\
    \ x;\n  }\n\n  np apply(np root, ll l, ll r, const X &x) {\n    if (l == r) return\
    \ root;\n    assert(root && L0 <= l && l < r && r <= R0);\n    root = clone(root);\n\
    \    apply_rec(root, L0, R0, l, r, x);\n    return root;\n  }\n\n  // root[l:r)\
    \ \u3092 other[l:r)*x \u3067\u4E0A\u66F8\u304D\u3057\u305F\u3082\u306E\u3092\u8FD4\
    \u3059\n  np copy_interval(np root, np other, ll l, ll r, X x) {\n    if (root\
    \ == other) return root;\n    root = clone(root);\n    copy_interval_rec(root,\
    \ other, L0, R0, l, r, x);\n    return root;\n  }\n\n  void reset() { pool.reset();\
    \ }\n\n  vc<X> get_all(np root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs,\
    \ np c, ll L, ll R, X x) -> void {\n      if (!c) {\n        FOR(R - L) res.eb(x);\n\
    \        return;\n      }\n      x = MX::op(c->x, x);\n      if (R == L + 1) {\n\
    \        res.eb(x);\n        return;\n      }\n      ll M = (L + R) / 2;\n   \
    \   dfs(dfs, c->l, L, M, x);\n      dfs(dfs, c->r, M, R, x);\n    };\n    dfs(dfs,\
    \ root, L0, R0, MX::unit());\n    return res;\n  }\n\n private:\n  np clone(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    return pool.clone(c);\n  }\n\
    \n  void apply_rec(np c, ll l, ll r, ll ql, ll qr, const X &a) {\n    // \u3082\
    \u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    assert(c);\n  \
    \  chmax(ql, l), chmin(qr, r);\n    if (a == MX::unit() || ql >= qr) return;\n\
    \    if (l == ql && r == qr) {\n      c->x = MX::op(c->x, a);\n      return;\n\
    \    }\n    // push\n    c->l = (c->l ? clone(c->l) : new_node());\n    c->r =\
    \ (c->r ? clone(c->r) : new_node());\n    c->l->x = MX::op(c->l->x, c->x);\n \
    \   c->r->x = MX::op(c->r->x, c->x);\n    c->x = MX::unit();\n    ll m = (l +\
    \ r) / 2;\n    apply_rec(c->l, l, m, ql, qr, a), apply_rec(c->r, m, r, ql, qr,\
    \ a);\n    return;\n  }\n\n  void copy_interval_rec(np c, np d, ll l, ll r, ll\
    \ ql, ll qr, X x) {\n    // c[ql,qr) <- d[ql,qr) * x\n    // \u3082\u3046 c \u306F\
    \u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    assert(c);\n    chmax(ql, l),\
    \ chmin(qr, r);\n    if (ql >= qr) return;\n    if (l == ql && r == qr) {\n  \
    \    if (d)\n        c->x = MX::op(d->x, x), c->l = d->l, c->r = d->r;\n     \
    \ else\n        c->x = x, c->l = nullptr, c->r = nullptr;\n      return;\n   \
    \ }\n    // push\n    c->l = (c->l ? clone(c->l) : new_node());\n    c->r = (c->r\
    \ ? clone(c->r) : new_node());\n    c->l->x = MX::op(c->l->x, c->x);\n    c->r->x\
    \ = MX::op(c->r->x, c->x);\n    c->x = MX::unit();\n    ll m = (l + r) / 2;\n\
    \    if (d) x = MX::op(d->x, x);\n    copy_interval_rec(c->l, (d && d->l ? d->l\
    \ : nullptr), l, m, ql, qr, x);\n    copy_interval_rec(c->r, (d && d->r ? d->r\
    \ : nullptr), m, r, ql, qr, x);\n    return;\n  }\n\n  void get_rec(np c, ll l,\
    \ ll r, ll i, X &x) {\n    if (!c) return;\n    x = MX::op(c->x, x);\n    if (r\
    \ == l + 1) {\n      return;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) return\
    \ get_rec(c->l, l, m, i, x);\n    return get_rec(c->r, m, r, i, x);\n  }\n};\n"
  dependsOn:
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/segtree/dynamic_dual_segtree.hpp
  requiredBy: []
  timestamp: '2025-09-16 20:23:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/dynamic_dual_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_dual_segtree.hpp
- /library/ds/segtree/dynamic_dual_segtree.hpp.html
title: ds/segtree/dynamic_dual_segtree.hpp
---
