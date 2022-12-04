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
  bundledCode: "#line 2 \"ds/segtree/dynamic_lazy_segtree.hpp\"\n\ntemplate <typename\
    \ ActedMonoid, bool PERSISTENT, int NODES>\nstruct Dynamic_Lazy_SegTree {\n  using\
    \ AM = ActedMonoid;\n  using MX = typename AM::MX;\n  using MA = typename AM::MA;\n\
    \  using X = typename AM::X;\n  using A = typename AM::A;\n  using F = function<X<ll,\
    \ ll>>;\n  F default_prod;\n\n  struct Node {\n    Node *l, *r;\n    X x;\n  \
    \  A a;\n  };\n\n  const ll n;\n  Node *pool;\n  int pid;\n  using np = Node *;\n\
    \n  Dynamic_Lazy_SegTree(\n      ll n, F default_prod = [](ll l, ll r) -> X {\
    \ return MX::unit(); })\n      : default_prod(default_prod), n(n), pid(0) {\n\
    \    pool = new Node[NODES];\n  }\n\n  np new_node(const X &x) {\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    pool[pid].a = Monoid_A::unit();\n\
    \    return &(pool[pid++]);\n  }\n\n  np new_node(ll l, ll r) {\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = default_prod(l, r);\n    pool[pid].a\
    \ = Monoid_A::unit();\n    return &(pool[pid++]);\n  }\n\n  np new_node(const\
    \ vc<X> &dat) {\n    assert(len(dat) == n);\n    auto dfs = [&](auto &dfs, ll\
    \ l, ll r) -> Node * {\n      if (l == r) return nullptr;\n      if (r == l +\
    \ 1) return new_node(dat[l]);\n      ll m = (l + r) / 2;\n      np l_root = dfs(dfs,\
    \ l, m), r_root = dfs(dfs, m, r);\n      X x = Monoid_X::op(l_root->x, r_root->x);\n\
    \      np root = new_node(x);\n      root->l = l_root, root->r = r_root;\n   \
    \   return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np,\
    \ ll l, ll r) {\n    assert(0 <= l && l < r && r <= n);\n    X x = Monoid_X::unit();\n\
    \    prod_rec(root, 0, n, l, r, x, Monoid_A::unit());\n    return x;\n  }\n\n\
    \  np set(np root, ll i, const X &x) {\n    assert(0 <= i && i < n);\n    return\
    \ set_rec(root, 0, n, i, x);\n  }\n\n  np apply(Node *root, ll l, ll r, const\
    \ A &a) {\n    assert(0 <= l && l < r && r <= n);\n    return apply_rec(root,\
    \ 0, n, l, r, a);\n  }\n\n  vc<X> restore(np root) {\n    vc<X> res;\n    res.reserve(n);\n\
    \    auto dfs = [&](auto &dfs, Node *c, ll l, ll r, A a) -> void {\n      if (r\
    \ - l == 1) { res.eb(AM::act(c->x, a)), return; }\n      ll m = (l + r) / 2;\n\
    \      a = MA::op(c->a, a);\n      dfs(dfs, c->l, l, m, a);\n      dfs(dfs, c->r,\
    \ m, r, a);\n    };\n    dfs(dfs, root, 0, n, MA::unit());\n    return res;\n\
    \  }\n\n  void reset() { pid = 0; }\n\nprivate:\n  np copy_node(np n) {\n    if\
    \ (!n || !PRESISTENT) return nullptr;\n    pool[pid].l = n->l, pool[pid].r = n->r;\n\
    \    pool[pid].x = n->x;\n    pool[pid].a = n->a;\n    return &(pool[pid++]);\n\
    \  }\n\n  void prop(np c, ll l, ll r) {\n    assert(r - l >= 2);\n    if (c->a\
    \ == MA::unit()) return;\n    c->l = (c->l ? copy_node(c->l) : new_node(l, (l\
    \ + r) / 2));\n    c->l->x = AM::act(c->l->x, c->a);\n    c->l->a = MA::op(c->l->a,\
    \ c->a);\n    c->r = (c->r ? copy_node(c->r) : new_node((l + r) / 2, r));\n  \
    \  c->r->x = AM::act(c->r->x, c->a);\n    c->r->a = MA::op(c->r->a, c->a);\n \
    \   c->a = MA::unit();\n  }\n\n  np set_rec(np c, ll l, ll r, ll i, const X &x)\
    \ {\n    if (node_r == node_l + 1) { return new_node(x); }\n    prop(c);\n   \
    \ c = copy_node(c);\n    ll m = (l + r) / 2;\n    if (i < m) {\n      c->l = set_rec(c->l,\
    \ node_l, node_m, i, x);\n    } else {\n      c->r = set_rec(c->r, node_m, node_r,\
    \ i, x);\n    }\n    c->x = Monoid_X::op(c->l->x, c->r->x);\n    return c;\n \
    \ }\n\n  void prod_rec(np c, ll node_l, ll node_r, ll l, ll r, X &x, A lazy) {\n\
    \    chmax(l, node_l);\n    chmin(r, node_r);\n    if (l >= r) return;\n    if\
    \ (!c) {\n      x = MX::op(x, AM::act(default_prod(l, r), lazy));\n      return;\n\
    \    }\n    if (l == node_l && r == node_r) {\n      x = MX::op(x, AM::act(c->x,\
    \ lazy));\n      return;\n    }\n    ll node_m = (node_l + node_r) / 2;\n    lazy\
    \ = MA::op(c->lazy, lazy);\n    prod_rec(c->l, node_l, node_m, l, r, x, lazy);\n\
    \    prod_rec(c->r, node_m, node_r, l, r, x, lazy);\n  }\n\n  np apply_rec(np\
    \ c, ll node_l, ll node_r, ll l, ll r, const A &a) {\n    if (!c) c = new_node(node_l,\
    \ node_r);\n    chmax(l, node_l);\n    chmin(r, node_r);\n    if (l >= r) return\
    \ c;\n    if (l == node_l && r == node_r) {\n      c = copy_node(c);\n      c->x\
    \ = Lazy::act(c->x, a);\n      c->a = Monoid_A::op(c->a, a);\n      return c;\n\
    \    }\n    prop(c);\n    ll node_m = (node_l + node_r) / 2;\n    c = copy_node(c);\n\
    \    c->l = apply_rec(c->l, node_l, node_m, l, r, a);\n    c->r = apply_rec(c->r,\
    \ node_m, node_r, l, r, a);\n    c->x = Monoid_X::op(c->l->x, c->r->x);\n    return\
    \ c;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename ActedMonoid, bool PERSISTENT, int NODES>\n\
    struct Dynamic_Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename\
    \ AM::MX;\n  using MA = typename AM::MA;\n  using X = typename AM::X;\n  using\
    \ A = typename AM::A;\n  using F = function<X<ll, ll>>;\n  F default_prod;\n\n\
    \  struct Node {\n    Node *l, *r;\n    X x;\n    A a;\n  };\n\n  const ll n;\n\
    \  Node *pool;\n  int pid;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(\n\
    \      ll n, F default_prod = [](ll l, ll r) -> X { return MX::unit(); })\n  \
    \    : default_prod(default_prod), n(n), pid(0) {\n    pool = new Node[NODES];\n\
    \  }\n\n  np new_node(const X &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].x = x;\n    pool[pid].a = Monoid_A::unit();\n    return &(pool[pid++]);\n\
    \  }\n\n  np new_node(ll l, ll r) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].x = default_prod(l, r);\n    pool[pid].a = Monoid_A::unit();\n\
    \    return &(pool[pid++]);\n  }\n\n  np new_node(const vc<X> &dat) {\n    assert(len(dat)\
    \ == n);\n    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {\n      if (l ==\
    \ r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      ll\
    \ m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n\
    \      X x = Monoid_X::op(l_root->x, r_root->x);\n      np root = new_node(x);\n\
    \      root->l = l_root, root->r = r_root;\n      return root;\n    };\n    return\
    \ dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np, ll l, ll r) {\n    assert(0 <= l\
    \ && l < r && r <= n);\n    X x = Monoid_X::unit();\n    prod_rec(root, 0, n,\
    \ l, r, x, Monoid_A::unit());\n    return x;\n  }\n\n  np set(np root, ll i, const\
    \ X &x) {\n    assert(0 <= i && i < n);\n    return set_rec(root, 0, n, i, x);\n\
    \  }\n\n  np apply(Node *root, ll l, ll r, const A &a) {\n    assert(0 <= l &&\
    \ l < r && r <= n);\n    return apply_rec(root, 0, n, l, r, a);\n  }\n\n  vc<X>\
    \ restore(np root) {\n    vc<X> res;\n    res.reserve(n);\n    auto dfs = [&](auto\
    \ &dfs, Node *c, ll l, ll r, A a) -> void {\n      if (r - l == 1) { res.eb(AM::act(c->x,\
    \ a)), return; }\n      ll m = (l + r) / 2;\n      a = MA::op(c->a, a);\n    \
    \  dfs(dfs, c->l, l, m, a);\n      dfs(dfs, c->r, m, r, a);\n    };\n    dfs(dfs,\
    \ root, 0, n, MA::unit());\n    return res;\n  }\n\n  void reset() { pid = 0;\
    \ }\n\nprivate:\n  np copy_node(np n) {\n    if (!n || !PRESISTENT) return nullptr;\n\
    \    pool[pid].l = n->l, pool[pid].r = n->r;\n    pool[pid].x = n->x;\n    pool[pid].a\
    \ = n->a;\n    return &(pool[pid++]);\n  }\n\n  void prop(np c, ll l, ll r) {\n\
    \    assert(r - l >= 2);\n    if (c->a == MA::unit()) return;\n    c->l = (c->l\
    \ ? copy_node(c->l) : new_node(l, (l + r) / 2));\n    c->l->x = AM::act(c->l->x,\
    \ c->a);\n    c->l->a = MA::op(c->l->a, c->a);\n    c->r = (c->r ? copy_node(c->r)\
    \ : new_node((l + r) / 2, r));\n    c->r->x = AM::act(c->r->x, c->a);\n    c->r->a\
    \ = MA::op(c->r->a, c->a);\n    c->a = MA::unit();\n  }\n\n  np set_rec(np c,\
    \ ll l, ll r, ll i, const X &x) {\n    if (node_r == node_l + 1) { return new_node(x);\
    \ }\n    prop(c);\n    c = copy_node(c);\n    ll m = (l + r) / 2;\n    if (i <\
    \ m) {\n      c->l = set_rec(c->l, node_l, node_m, i, x);\n    } else {\n    \
    \  c->r = set_rec(c->r, node_m, node_r, i, x);\n    }\n    c->x = Monoid_X::op(c->l->x,\
    \ c->r->x);\n    return c;\n  }\n\n  void prod_rec(np c, ll node_l, ll node_r,\
    \ ll l, ll r, X &x, A lazy) {\n    chmax(l, node_l);\n    chmin(r, node_r);\n\
    \    if (l >= r) return;\n    if (!c) {\n      x = MX::op(x, AM::act(default_prod(l,\
    \ r), lazy));\n      return;\n    }\n    if (l == node_l && r == node_r) {\n \
    \     x = MX::op(x, AM::act(c->x, lazy));\n      return;\n    }\n    ll node_m\
    \ = (node_l + node_r) / 2;\n    lazy = MA::op(c->lazy, lazy);\n    prod_rec(c->l,\
    \ node_l, node_m, l, r, x, lazy);\n    prod_rec(c->r, node_m, node_r, l, r, x,\
    \ lazy);\n  }\n\n  np apply_rec(np c, ll node_l, ll node_r, ll l, ll r, const\
    \ A &a) {\n    if (!c) c = new_node(node_l, node_r);\n    chmax(l, node_l);\n\
    \    chmin(r, node_r);\n    if (l >= r) return c;\n    if (l == node_l && r ==\
    \ node_r) {\n      c = copy_node(c);\n      c->x = Lazy::act(c->x, a);\n     \
    \ c->a = Monoid_A::op(c->a, a);\n      return c;\n    }\n    prop(c);\n    ll\
    \ node_m = (node_l + node_r) / 2;\n    c = copy_node(c);\n    c->l = apply_rec(c->l,\
    \ node_l, node_m, l, r, a);\n    c->r = apply_rec(c->r, node_m, node_r, l, r,\
    \ a);\n    c->x = Monoid_X::op(c->l->x, c->r->x);\n    return c;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dynamic_lazy_segtree.hpp
  requiredBy: []
  timestamp: '2022-12-04 12:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/dynamic_lazy_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_lazy_segtree.hpp
- /library/ds/segtree/dynamic_lazy_segtree.hpp.html
title: ds/segtree/dynamic_lazy_segtree.hpp
---
