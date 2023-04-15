---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_lazy_segtree.test.cpp
    title: test/mytest/dynamic_lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
    title: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/789_2.test.cpp
    title: test/yukicoder/789_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/dynamic_lazy_segtree.hpp\"\n\ntemplate <typename\
    \ ActedMonoid, bool PERSISTENT, int NODES>\nstruct Dynamic_Lazy_SegTree {\n  using\
    \ AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA = typename\
    \ AM::Monoid_A;\n  using X = typename AM::X;\n  using A = typename AM::A;\n  using\
    \ F = function<X(ll, ll)>;\n  F default_prod;\n\n  struct Node {\n    Node *l,\
    \ *r;\n    X x;\n    A lazy;\n  };\n\n  const ll L0, R0;\n  Node *pool;\n  int\
    \ pid;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(\n      ll L0, ll R0, F\
    \ default_prod = [](ll l, ll r) -> X { return MX::unit(); })\n      : default_prod(default_prod),\
    \ L0(L0), R0(R0), pid(0) {\n    pool = new Node[NODES];\n  }\n\n  np new_root()\
    \ { return new_node(L0, R0); }\n\n  np new_node(const X x) {\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    pool[pid].lazy = MA::unit();\n\
    \    return &(pool[pid++]);\n  }\n\n  np new_node(ll l, ll r) { return new_node(default_prod(l,\
    \ r)); }\n  np new_node() { return new_node(L0, R0); }\n\n  np new_node(const\
    \ vc<X> &dat) {\n    assert(L0 == 0 && R0 == len(dat));\n    auto dfs = [&](auto\
    \ &dfs, ll l, ll r) -> Node * {\n      if (l == r) return nullptr;\n      if (r\
    \ == l + 1) return new_node(dat[l]);\n      ll m = (l + r) / 2;\n      np l_root\
    \ = dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n      X x = MX::op(l_root->x, r_root->x);\n\
    \      np root = new_node(x);\n      root->l = l_root, root->r = r_root;\n   \
    \   return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np\
    \ root, ll l, ll r) {\n    assert(pid && L0 <= l && l < r && r <= R0);\n    X\
    \ x = MX::unit();\n    prod_rec(root, L0, R0, l, r, x, MA::unit());\n    return\
    \ x;\n  }\n\n  X prod_all(np root) { return prod(root, L0, R0); }\n\n  np set(np\
    \ root, ll i, const X &x) {\n    assert(pid && L0 <= i && i < R0);\n    return\
    \ set_rec(root, L0, R0, i, x);\n  }\n\n  np multiply(np root, ll i, const X &x)\
    \ {\n    assert(pid && L0 <= i && i < R0);\n    return multiply_rec(root, L0,\
    \ R0, i, x);\n  }\n\n  np apply(np root, ll l, ll r, const A &a) {\n    if (l\
    \ == r) return root;\n    assert(pid && L0 <= l && l < r && r <= R0);\n    return\
    \ apply_rec(root, L0, R0, l, r, a);\n  }\n\n  template <typename F>\n  ll max_right(np\
    \ root, F check, ll L) {\n    assert(pid && L0 <= L && L <= R0 && check(MX::unit()));\n\
    \    X x = MX::unit();\n    return max_right_rec(root, check, L0, R0, L, x);\n\
    \  }\n\n  template <typename F>\n  ll min_left(np root, F check, ll R) {\n   \
    \ assert(pid && L0 <= R && R <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return min_left_rec(root, check, L0, R0, R, x);\n  }\n\n  // f(idx, val)\n\
    \  template <typename F>\n  void enumerate(np root, F f) {\n    auto dfs = [&](auto\
    \ &dfs, np c, ll l, ll r, A a) -> void {\n      if (!c) return;\n      if (r -\
    \ l == 1) {\n        f(l, AM::act(c->x, a, 1));\n        return;\n      }\n  \
    \    ll m = (l + r) / 2;\n      a = MA::op(c->lazy, a);\n      dfs(dfs, c->l,\
    \ l, m, a);\n      dfs(dfs, c->r, m, r, a);\n    };\n    dfs(dfs, root, L0, R0,\
    \ MA::unit());\n  }\n\n  void reset() { pid = 0; }\n\nprivate:\n  np copy_node(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    pool[pid].l = c->l, pool[pid].r\
    \ = c->r;\n    pool[pid].x = c->x;\n    pool[pid].lazy = c->lazy;\n    return\
    \ &(pool[pid++]);\n  }\n\n  void prop(np c, ll l, ll r) {\n    assert(r - l >=\
    \ 2);\n    ll m = (l + r) / 2;\n    if (c->lazy == MA::unit()) return;\n    c->l\
    \ = (c->l ? copy_node(c->l) : new_node(l, m));\n    c->l->x = AM::act(c->l->x,\
    \ c->lazy, m - l);\n    c->l->lazy = MA::op(c->l->lazy, c->lazy);\n    c->r =\
    \ (c->r ? copy_node(c->r) : new_node(m, r));\n    c->r->x = AM::act(c->r->x, c->lazy,\
    \ r - m);\n    c->r->lazy = MA::op(c->r->lazy, c->lazy);\n    c->lazy = MA::unit();\n\
    \  }\n\n  np set_rec(np c, ll l, ll r, ll i, const X &x) {\n    if (r == l + 1)\
    \ {\n      c = copy_node(c);\n      c->x = x;\n      c->lazy = MA::unit();\n \
    \     return c;\n    }\n    prop(c, l, r);\n    ll m = (l + r) / 2;\n    if (!c->l)\
    \ c->l = new_node(l, m);\n    if (!c->r) c->r = new_node(m, r);\n\n    c = copy_node(c);\n\
    \    if (i < m) {\n      c->l = set_rec(c->l, l, m, i, x);\n    } else {\n   \
    \   c->r = set_rec(c->r, m, r, i, x);\n    }\n    c->x = MX::op(c->l->x, c->r->x);\n\
    \    return c;\n  }\n\n  np multiply_rec(np c, ll l, ll r, ll i, const X &x) {\n\
    \    if (r == l + 1) {\n      c = copy_node(c);\n      c->x = MX::op(c->x, x);\n\
    \      c->lazy = MA::unit();\n      return c;\n    }\n    prop(c, l, r);\n   \
    \ ll m = (l + r) / 2;\n    if (!c->l) c->l = new_node(l, m);\n    if (!c->r) c->r\
    \ = new_node(m, r);\n\n    c = copy_node(c);\n    if (i < m) {\n      c->l = multiply_rec(c->l,\
    \ l, m, i, x);\n    } else {\n      c->r = multiply_rec(c->r, m, r, i, x);\n \
    \   }\n    c->x = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  void prod_rec(np\
    \ c, ll l, ll r, ll ql, ll qr, X &x, A lazy) {\n    chmax(ql, l);\n    chmin(qr,\
    \ r);\n    if (ql >= qr) return;\n    if (!c) {\n      x = MX::op(x, AM::act(default_prod(ql,\
    \ qr), lazy, qr - ql));\n      return;\n    }\n    if (l == ql && r == qr) {\n\
    \      x = MX::op(x, AM::act(c->x, lazy, r - l));\n      return;\n    }\n    ll\
    \ m = (l + r) / 2;\n    lazy = MA::op(c->lazy, lazy);\n    prod_rec(c->l, l, m,\
    \ ql, qr, x, lazy);\n    prod_rec(c->r, m, r, ql, qr, x, lazy);\n  }\n\n  np apply_rec(np\
    \ c, ll l, ll r, ll ql, ll qr, const A &a) {\n    if (!c) c = new_node(l, r);\n\
    \    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr) return c;\n    if (l\
    \ == ql && r == qr) {\n      c = copy_node(c);\n      c->x = AM::act(c->x, a,\
    \ r - l);\n      c->lazy = MA::op(c->lazy, a);\n      return c;\n    }\n    prop(c,\
    \ l, r);\n    ll m = (l + r) / 2;\n    c = copy_node(c);\n    c->l = apply_rec(c->l,\
    \ l, m, ql, qr, a);\n    c->r = apply_rec(c->r, m, r, ql, qr, a);\n    c->x =\
    \ MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  template <typename F>\n \
    \ ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x) {\n    if (r\
    \ <= ql) return r;\n    if (!c) c = new_node(l, r);\n    chmax(ql, l);\n    if\
    \ (l == ql && check(MX::op(x, c->x))) {\n      x = MX::op(x, c->x);\n      return\
    \ r;\n    }\n    if (r == l + 1) return l;\n    prop(c, l, r);\n    ll m = (l\
    \ + r) / 2;\n    ll k = max_right_rec(c->l, check, l, m, ql, x);\n    if (k <\
    \ m) return k;\n    return max_right_rec(c->r, check, m, r, ql, x);\n  }\n\n \
    \ template <typename F>\n  ll min_left_rec(np c, const F &check, ll l, ll r, ll\
    \ qr, X &x) {\n    if (qr <= l) return l;\n    if (!c) c = new_node(l, r);\n \
    \   chmin(qr, r);\n    if (r == qr && check(MX::op(c->x, x))) {\n      x = MX::op(c->x,\
    \ x);\n      return l;\n    }\n    if (r == l + 1) return r;\n    prop(c, l, r);\n\
    \    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check, m, r, qr, x);\n\
    \    if (m < k) return k;\n    return min_left_rec(c->l, check, l, m, qr, x);\n\
    \  }\n};\n"
  code: "#pragma once\n\ntemplate <typename ActedMonoid, bool PERSISTENT, int NODES>\n\
    struct Dynamic_Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename\
    \ AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X = typename AM::X;\n\
    \  using A = typename AM::A;\n  using F = function<X(ll, ll)>;\n  F default_prod;\n\
    \n  struct Node {\n    Node *l, *r;\n    X x;\n    A lazy;\n  };\n\n  const ll\
    \ L0, R0;\n  Node *pool;\n  int pid;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(\n\
    \      ll L0, ll R0, F default_prod = [](ll l, ll r) -> X { return MX::unit();\
    \ })\n      : default_prod(default_prod), L0(L0), R0(R0), pid(0) {\n    pool =\
    \ new Node[NODES];\n  }\n\n  np new_root() { return new_node(L0, R0); }\n\n  np\
    \ new_node(const X x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x\
    \ = x;\n    pool[pid].lazy = MA::unit();\n    return &(pool[pid++]);\n  }\n\n\
    \  np new_node(ll l, ll r) { return new_node(default_prod(l, r)); }\n  np new_node()\
    \ { return new_node(L0, R0); }\n\n  np new_node(const vc<X> &dat) {\n    assert(L0\
    \ == 0 && R0 == len(dat));\n    auto dfs = [&](auto &dfs, ll l, ll r) -> Node\
    \ * {\n      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      ll m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs,\
    \ m, r);\n      X x = MX::op(l_root->x, r_root->x);\n      np root = new_node(x);\n\
    \      root->l = l_root, root->r = r_root;\n      return root;\n    };\n    return\
    \ dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np root, ll l, ll r) {\n    assert(pid\
    \ && L0 <= l && l < r && r <= R0);\n    X x = MX::unit();\n    prod_rec(root,\
    \ L0, R0, l, r, x, MA::unit());\n    return x;\n  }\n\n  X prod_all(np root) {\
    \ return prod(root, L0, R0); }\n\n  np set(np root, ll i, const X &x) {\n    assert(pid\
    \ && L0 <= i && i < R0);\n    return set_rec(root, L0, R0, i, x);\n  }\n\n  np\
    \ multiply(np root, ll i, const X &x) {\n    assert(pid && L0 <= i && i < R0);\n\
    \    return multiply_rec(root, L0, R0, i, x);\n  }\n\n  np apply(np root, ll l,\
    \ ll r, const A &a) {\n    if (l == r) return root;\n    assert(pid && L0 <= l\
    \ && l < r && r <= R0);\n    return apply_rec(root, L0, R0, l, r, a);\n  }\n\n\
    \  template <typename F>\n  ll max_right(np root, F check, ll L) {\n    assert(pid\
    \ && L0 <= L && L <= R0 && check(MX::unit()));\n    X x = MX::unit();\n    return\
    \ max_right_rec(root, check, L0, R0, L, x);\n  }\n\n  template <typename F>\n\
    \  ll min_left(np root, F check, ll R) {\n    assert(pid && L0 <= R && R <= R0\
    \ && check(MX::unit()));\n    X x = MX::unit();\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\n  }\n\n  // f(idx, val)\n  template <typename F>\n  void\
    \ enumerate(np root, F f) {\n    auto dfs = [&](auto &dfs, np c, ll l, ll r, A\
    \ a) -> void {\n      if (!c) return;\n      if (r - l == 1) {\n        f(l, AM::act(c->x,\
    \ a, 1));\n        return;\n      }\n      ll m = (l + r) / 2;\n      a = MA::op(c->lazy,\
    \ a);\n      dfs(dfs, c->l, l, m, a);\n      dfs(dfs, c->r, m, r, a);\n    };\n\
    \    dfs(dfs, root, L0, R0, MA::unit());\n  }\n\n  void reset() { pid = 0; }\n\
    \nprivate:\n  np copy_node(np c) {\n    if (!c || !PERSISTENT) return c;\n   \
    \ pool[pid].l = c->l, pool[pid].r = c->r;\n    pool[pid].x = c->x;\n    pool[pid].lazy\
    \ = c->lazy;\n    return &(pool[pid++]);\n  }\n\n  void prop(np c, ll l, ll r)\
    \ {\n    assert(r - l >= 2);\n    ll m = (l + r) / 2;\n    if (c->lazy == MA::unit())\
    \ return;\n    c->l = (c->l ? copy_node(c->l) : new_node(l, m));\n    c->l->x\
    \ = AM::act(c->l->x, c->lazy, m - l);\n    c->l->lazy = MA::op(c->l->lazy, c->lazy);\n\
    \    c->r = (c->r ? copy_node(c->r) : new_node(m, r));\n    c->r->x = AM::act(c->r->x,\
    \ c->lazy, r - m);\n    c->r->lazy = MA::op(c->r->lazy, c->lazy);\n    c->lazy\
    \ = MA::unit();\n  }\n\n  np set_rec(np c, ll l, ll r, ll i, const X &x) {\n \
    \   if (r == l + 1) {\n      c = copy_node(c);\n      c->x = x;\n      c->lazy\
    \ = MA::unit();\n      return c;\n    }\n    prop(c, l, r);\n    ll m = (l + r)\
    \ / 2;\n    if (!c->l) c->l = new_node(l, m);\n    if (!c->r) c->r = new_node(m,\
    \ r);\n\n    c = copy_node(c);\n    if (i < m) {\n      c->l = set_rec(c->l, l,\
    \ m, i, x);\n    } else {\n      c->r = set_rec(c->r, m, r, i, x);\n    }\n  \
    \  c->x = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  np multiply_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    if (r == l + 1) {\n      c = copy_node(c);\n\
    \      c->x = MX::op(c->x, x);\n      c->lazy = MA::unit();\n      return c;\n\
    \    }\n    prop(c, l, r);\n    ll m = (l + r) / 2;\n    if (!c->l) c->l = new_node(l,\
    \ m);\n    if (!c->r) c->r = new_node(m, r);\n\n    c = copy_node(c);\n    if\
    \ (i < m) {\n      c->l = multiply_rec(c->l, l, m, i, x);\n    } else {\n    \
    \  c->r = multiply_rec(c->r, m, r, i, x);\n    }\n    c->x = MX::op(c->l->x, c->r->x);\n\
    \    return c;\n  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A\
    \ lazy) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr) return;\n \
    \   if (!c) {\n      x = MX::op(x, AM::act(default_prod(ql, qr), lazy, qr - ql));\n\
    \      return;\n    }\n    if (l == ql && r == qr) {\n      x = MX::op(x, AM::act(c->x,\
    \ lazy, r - l));\n      return;\n    }\n    ll m = (l + r) / 2;\n    lazy = MA::op(c->lazy,\
    \ lazy);\n    prod_rec(c->l, l, m, ql, qr, x, lazy);\n    prod_rec(c->r, m, r,\
    \ ql, qr, x, lazy);\n  }\n\n  np apply_rec(np c, ll l, ll r, ll ql, ll qr, const\
    \ A &a) {\n    if (!c) c = new_node(l, r);\n    chmax(ql, l);\n    chmin(qr, r);\n\
    \    if (ql >= qr) return c;\n    if (l == ql && r == qr) {\n      c = copy_node(c);\n\
    \      c->x = AM::act(c->x, a, r - l);\n      c->lazy = MA::op(c->lazy, a);\n\
    \      return c;\n    }\n    prop(c, l, r);\n    ll m = (l + r) / 2;\n    c =\
    \ copy_node(c);\n    c->l = apply_rec(c->l, l, m, ql, qr, a);\n    c->r = apply_rec(c->r,\
    \ m, r, ql, qr, a);\n    c->x = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\
    \n  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l, ll r,\
    \ ll ql, X &x) {\n    if (r <= ql) return r;\n    if (!c) c = new_node(l, r);\n\
    \    chmax(ql, l);\n    if (l == ql && check(MX::op(x, c->x))) {\n      x = MX::op(x,\
    \ c->x);\n      return r;\n    }\n    if (r == l + 1) return l;\n    prop(c, l,\
    \ r);\n    ll m = (l + r) / 2;\n    ll k = max_right_rec(c->l, check, l, m, ql,\
    \ x);\n    if (k < m) return k;\n    return max_right_rec(c->r, check, m, r, ql,\
    \ x);\n  }\n\n  template <typename F>\n  ll min_left_rec(np c, const F &check,\
    \ ll l, ll r, ll qr, X &x) {\n    if (qr <= l) return l;\n    if (!c) c = new_node(l,\
    \ r);\n    chmin(qr, r);\n    if (r == qr && check(MX::op(c->x, x))) {\n     \
    \ x = MX::op(c->x, x);\n      return l;\n    }\n    if (r == l + 1) return r;\n\
    \    prop(c, l, r);\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check,\
    \ m, r, qr, x);\n    if (m < k) return k;\n    return min_left_rec(c->l, check,\
    \ l, m, qr, x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dynamic_lazy_segtree.hpp
  requiredBy: []
  timestamp: '2023-04-14 22:06:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - test/mytest/dynamic_lazy_segtree.test.cpp
  - test/yukicoder/789_2.test.cpp
documentation_of: ds/segtree/dynamic_lazy_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_lazy_segtree.hpp
- /library/ds/segtree/dynamic_lazy_segtree.hpp.html
title: ds/segtree/dynamic_lazy_segtree.hpp
---
