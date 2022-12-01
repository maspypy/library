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
  bundledCode: "#line 2 \"ds/segtree/dynamic_segtree.hpp\"\n\r\n/*\r\n\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u6E21\u3059\u3082\u306E\r\n\u30FBL, R\uFF1A\
    \u6700\u5927\u306E\u7BC4\u56F2\uFF08root node \u306E\u8868\u3059\u7BC4\u56F2\uFF09\
    \r\n\u30FBfunction<X(ll,ll)> defulat_fn(l,r)\uFF1A\u521D\u671F\u5024\u3067\u306E\
    \ [l,r) \u7A4D\u306E\u8A08\u7B97\r\n*/\r\ntemplate <class Monoid, int NODES =\
    \ 5'000'000>\r\nstruct Dynamic_SegTree {\r\n  using X = typename Monoid::value_type;\r\
    \n\r\n  struct Node {\r\n    X x;\r\n    Node *l, *r;\r\n    Node() {}\r\n   \
    \ Node(const X &x) : x(x), l(nullptr), r(nullptr) {}\r\n  };\r\n\r\n  Node *pool;\r\
    \n  int pid;\r\n  ll L, R;\r\n  Node *root;\r\n  function<X(ll, ll)> default_fn;\r\
    \n\r\n  Dynamic_SegTree(ll L, ll R)\r\n      : Dynamic_SegTree(L, R, [](ll L,\
    \ ll R){return Monoid::unit();}) {}\r\n\r\n  Dynamic_SegTree(ll L, ll R, function<X(ll,\
    \ ll)> f)\r\n      : pid(0), L(L), R(R), default_fn(f) {\r\n    pool = new Node[NODES];\r\
    \n    root = new_node(L, R);\r\n  }\r\n\r\n  void reset() {\r\n    pid = 0;\r\n\
    \    root = new_node(L, R);\r\n  }\r\n\r\n  void set(ll i, const X &x) {\r\n \
    \   assert(L <= i && i < R);\r\n    set_rec(root, L, R, i, x);\r\n  }\r\n\r\n\
    \  void multiply(ll i, const X &x) {\r\n    assert(L <= i && i < R);\r\n    multiply_rec(root,\
    \ L, R, i, x);\r\n  }\r\n\r\n  X prod(ll l, ll r) {\r\n    assert(L <= l && l\
    \ <= r && r <= R);\r\n    return prod_rec(root, L, R, l, r);\r\n  }\r\n\r\n  X\
    \ prod_all() { return root->x; }\r\n\r\n  void debug() {\r\n    auto dfs = [&](auto\
    \ &dfs, Node *n, ll l, ll r) -> void {\r\n      print(\"lr\", l, r, \"x\", n->x,\
    \ \"a\", n->a);\r\n      ll m = (l + r) / 2;\r\n      if (n->l) dfs(dfs, n->l,\
    \ l, m);\r\n      if (n->r) dfs(dfs, n->r, m, r);\r\n    };\r\n    dfs(dfs, root,\
    \ L, R);\r\n  }\r\n\r\n  template <class F>\r\n  ll max_right(const F &check,\
    \ ll s) {\r\n    assert(L <= s && s <= R && check(Monoid::unit()));\r\n    X p\
    \ = Monoid::unit();\r\n    return max_right_rec(root, L, R, check, s, p);\r\n\
    \  }\r\n\r\n  template <class F>\r\n  ll min_left(const F &check, ll t) {\r\n\
    \    assert(L <= t && t <= R && check(Monoid::unit()));\r\n    X p = Monoid::unit();\r\
    \n    return min_left_rec(root, L, R, check, t, p);\r\n  }\r\n\r\nprivate:\r\n\
    \  Node *new_node(ll node_l, ll node_r) {\r\n    pool[pid].x = default_fn(node_l,\
    \ node_r);\r\n    pool[pid].l = pool[pid].r = nullptr;\r\n    return &(pool[pid++]);\r\
    \n  }\r\n\r\n  void set_rec(Node *n, ll node_l, ll node_r, ll idx, const X &x)\
    \ {\r\n    if (node_r - node_l == 1) {\r\n      n->x = x;\r\n      return;\r\n\
    \    }\r\n    ll node_m = (node_l + node_r) / 2;\r\n\r\n    if (idx < node_m)\
    \ {\r\n      if (!(n->l)) n->l = new_node(node_l, node_m);\r\n      set_rec(n->l,\
    \ node_l, node_m, idx, x);\r\n    } else {\r\n      if (!(n->r)) n->r = new_node(node_m,\
    \ node_r);\r\n      set_rec(n->r, node_m, node_r, idx, x);\r\n    }\r\n    X xl\
    \ = (n->l ? (n->l)->x : Monoid::unit());\r\n    X xr = (n->r ? (n->r)->x : Monoid::unit());\r\
    \n    n->x = Monoid::op(xl, xr);\r\n  }\r\n\r\n  void multiply_rec(Node *n, ll\
    \ node_l, ll node_r, ll idx, const X &x) {\r\n    if (node_r - node_l == 1) {\r\
    \n      n->x = Monoid::op(n->x, x);\r\n      return;\r\n    }\r\n    ll node_m\
    \ = (node_l + node_r) / 2;\r\n\r\n    if (idx < node_m) {\r\n      if (!(n->l))\
    \ n->l = new_node(node_l, node_m);\r\n      multiply_rec(n->l, node_l, node_m,\
    \ idx, x);\r\n    } else {\r\n      if (!(n->r)) n->r = new_node(node_m, node_r);\r\
    \n      multiply_rec(n->r, node_m, node_r, idx, x);\r\n    }\r\n    X xl = (n->l\
    \ ? (n->l)->x : Monoid::unit());\r\n    X xr = (n->r ? (n->r)->x : Monoid::unit());\r\
    \n    n->x = Monoid::op(xl, xr);\r\n  }\r\n\r\n  X prod_rec(Node *n, ll node_l,\
    \ ll node_r, ll l, ll r) {\r\n    chmax(l, node_l);\r\n    chmin(r, node_r);\r\
    \n    if (l >= r) return Monoid::unit();\r\n    if (l == node_l && r == node_r)\
    \ return n->x;\r\n    ll node_m = (node_l + node_r) / 2;\r\n    X xl = (n->l ?\
    \ prod_rec(n->l, node_l, node_m, l, r) : Monoid::unit());\r\n    X xr = (n->r\
    \ ? prod_rec(n->r, node_m, node_r, l, r) : Monoid::unit());\r\n    return Monoid::op(xl,\
    \ xr);\r\n  }\r\n\r\n  template <typename F>\r\n  ll max_right_rec(Node *n, ll\
    \ node_l, ll node_r, const F &check, ll s, X &p) {\r\n    if (node_r <= s) return\
    \ R;\r\n    if (s <= node_l) {\r\n      X x = Monoid::op(p, n->x);\r\n      if\
    \ (check(x)) {\r\n        p = x;\r\n        return R;\r\n      }\r\n    }\r\n\
    \    if (node_r - node_l == 1) return node_l;\r\n    ll node_m = (node_l + node_r)\
    \ / 2;\r\n    if (!(n->l)) n->l = new_node(node_l, node_m);\r\n    ll res = max_right_rec(n->l,\
    \ node_l, node_m, check, s, p);\r\n    if (res != R) return res;\r\n    if (!(n->r))\
    \ n->r = new_node(node_m, node_r);\r\n    return max_right_rec(n->r, node_m, node_r,\
    \ check, s, p);\r\n  }\r\n\r\n  template <typename F>\r\n  ll min_left_rec(Node\
    \ *n, ll node_l, ll node_r, const F &check, ll t, X &p) {\r\n    if (t <= node_l)\
    \ return L;\r\n    if (node_r <= t) {\r\n      X x = Monoid::op(n->x, p);\r\n\
    \      if (check(x)) {\r\n        p = x;\r\n        return L;\r\n      }\r\n \
    \   }\r\n    if (node_r - node_l == 1) return node_r;\r\n    ll node_m = (node_l\
    \ + node_r) / 2;\r\n    if (!(n->r)) n->r = new_node(node_m, node_r);\r\n    ll\
    \ res = min_left_rec(n->r, node_m, node_r, check, t, p);\r\n    if (res != L)\
    \ return res;\r\n    if (!(n->l)) n->l = new_node(node_l, node_m);\r\n    return\
    \ min_left_rec(n->l, node_l, node_m, check, t, p);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n/*\r\n\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\
    \u6E21\u3059\u3082\u306E\r\n\u30FBL, R\uFF1A\u6700\u5927\u306E\u7BC4\u56F2\uFF08\
    root node \u306E\u8868\u3059\u7BC4\u56F2\uFF09\r\n\u30FBfunction<X(ll,ll)> defulat_fn(l,r)\uFF1A\
    \u521D\u671F\u5024\u3067\u306E [l,r) \u7A4D\u306E\u8A08\u7B97\r\n*/\r\ntemplate\
    \ <class Monoid, int NODES = 5'000'000>\r\nstruct Dynamic_SegTree {\r\n  using\
    \ X = typename Monoid::value_type;\r\n\r\n  struct Node {\r\n    X x;\r\n    Node\
    \ *l, *r;\r\n    Node() {}\r\n    Node(const X &x) : x(x), l(nullptr), r(nullptr)\
    \ {}\r\n  };\r\n\r\n  Node *pool;\r\n  int pid;\r\n  ll L, R;\r\n  Node *root;\r\
    \n  function<X(ll, ll)> default_fn;\r\n\r\n  Dynamic_SegTree(ll L, ll R)\r\n \
    \     : Dynamic_SegTree(L, R, [](ll L, ll R){return Monoid::unit();}) {}\r\n\r\
    \n  Dynamic_SegTree(ll L, ll R, function<X(ll, ll)> f)\r\n      : pid(0), L(L),\
    \ R(R), default_fn(f) {\r\n    pool = new Node[NODES];\r\n    root = new_node(L,\
    \ R);\r\n  }\r\n\r\n  void reset() {\r\n    pid = 0;\r\n    root = new_node(L,\
    \ R);\r\n  }\r\n\r\n  void set(ll i, const X &x) {\r\n    assert(L <= i && i <\
    \ R);\r\n    set_rec(root, L, R, i, x);\r\n  }\r\n\r\n  void multiply(ll i, const\
    \ X &x) {\r\n    assert(L <= i && i < R);\r\n    multiply_rec(root, L, R, i, x);\r\
    \n  }\r\n\r\n  X prod(ll l, ll r) {\r\n    assert(L <= l && l <= r && r <= R);\r\
    \n    return prod_rec(root, L, R, l, r);\r\n  }\r\n\r\n  X prod_all() { return\
    \ root->x; }\r\n\r\n  void debug() {\r\n    auto dfs = [&](auto &dfs, Node *n,\
    \ ll l, ll r) -> void {\r\n      print(\"lr\", l, r, \"x\", n->x, \"a\", n->a);\r\
    \n      ll m = (l + r) / 2;\r\n      if (n->l) dfs(dfs, n->l, l, m);\r\n     \
    \ if (n->r) dfs(dfs, n->r, m, r);\r\n    };\r\n    dfs(dfs, root, L, R);\r\n \
    \ }\r\n\r\n  template <class F>\r\n  ll max_right(const F &check, ll s) {\r\n\
    \    assert(L <= s && s <= R && check(Monoid::unit()));\r\n    X p = Monoid::unit();\r\
    \n    return max_right_rec(root, L, R, check, s, p);\r\n  }\r\n\r\n  template\
    \ <class F>\r\n  ll min_left(const F &check, ll t) {\r\n    assert(L <= t && t\
    \ <= R && check(Monoid::unit()));\r\n    X p = Monoid::unit();\r\n    return min_left_rec(root,\
    \ L, R, check, t, p);\r\n  }\r\n\r\nprivate:\r\n  Node *new_node(ll node_l, ll\
    \ node_r) {\r\n    pool[pid].x = default_fn(node_l, node_r);\r\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\r\n    return &(pool[pid++]);\r\n  }\r\n\r\n  void\
    \ set_rec(Node *n, ll node_l, ll node_r, ll idx, const X &x) {\r\n    if (node_r\
    \ - node_l == 1) {\r\n      n->x = x;\r\n      return;\r\n    }\r\n    ll node_m\
    \ = (node_l + node_r) / 2;\r\n\r\n    if (idx < node_m) {\r\n      if (!(n->l))\
    \ n->l = new_node(node_l, node_m);\r\n      set_rec(n->l, node_l, node_m, idx,\
    \ x);\r\n    } else {\r\n      if (!(n->r)) n->r = new_node(node_m, node_r);\r\
    \n      set_rec(n->r, node_m, node_r, idx, x);\r\n    }\r\n    X xl = (n->l ?\
    \ (n->l)->x : Monoid::unit());\r\n    X xr = (n->r ? (n->r)->x : Monoid::unit());\r\
    \n    n->x = Monoid::op(xl, xr);\r\n  }\r\n\r\n  void multiply_rec(Node *n, ll\
    \ node_l, ll node_r, ll idx, const X &x) {\r\n    if (node_r - node_l == 1) {\r\
    \n      n->x = Monoid::op(n->x, x);\r\n      return;\r\n    }\r\n    ll node_m\
    \ = (node_l + node_r) / 2;\r\n\r\n    if (idx < node_m) {\r\n      if (!(n->l))\
    \ n->l = new_node(node_l, node_m);\r\n      multiply_rec(n->l, node_l, node_m,\
    \ idx, x);\r\n    } else {\r\n      if (!(n->r)) n->r = new_node(node_m, node_r);\r\
    \n      multiply_rec(n->r, node_m, node_r, idx, x);\r\n    }\r\n    X xl = (n->l\
    \ ? (n->l)->x : Monoid::unit());\r\n    X xr = (n->r ? (n->r)->x : Monoid::unit());\r\
    \n    n->x = Monoid::op(xl, xr);\r\n  }\r\n\r\n  X prod_rec(Node *n, ll node_l,\
    \ ll node_r, ll l, ll r) {\r\n    chmax(l, node_l);\r\n    chmin(r, node_r);\r\
    \n    if (l >= r) return Monoid::unit();\r\n    if (l == node_l && r == node_r)\
    \ return n->x;\r\n    ll node_m = (node_l + node_r) / 2;\r\n    X xl = (n->l ?\
    \ prod_rec(n->l, node_l, node_m, l, r) : Monoid::unit());\r\n    X xr = (n->r\
    \ ? prod_rec(n->r, node_m, node_r, l, r) : Monoid::unit());\r\n    return Monoid::op(xl,\
    \ xr);\r\n  }\r\n\r\n  template <typename F>\r\n  ll max_right_rec(Node *n, ll\
    \ node_l, ll node_r, const F &check, ll s, X &p) {\r\n    if (node_r <= s) return\
    \ R;\r\n    if (s <= node_l) {\r\n      X x = Monoid::op(p, n->x);\r\n      if\
    \ (check(x)) {\r\n        p = x;\r\n        return R;\r\n      }\r\n    }\r\n\
    \    if (node_r - node_l == 1) return node_l;\r\n    ll node_m = (node_l + node_r)\
    \ / 2;\r\n    if (!(n->l)) n->l = new_node(node_l, node_m);\r\n    ll res = max_right_rec(n->l,\
    \ node_l, node_m, check, s, p);\r\n    if (res != R) return res;\r\n    if (!(n->r))\
    \ n->r = new_node(node_m, node_r);\r\n    return max_right_rec(n->r, node_m, node_r,\
    \ check, s, p);\r\n  }\r\n\r\n  template <typename F>\r\n  ll min_left_rec(Node\
    \ *n, ll node_l, ll node_r, const F &check, ll t, X &p) {\r\n    if (t <= node_l)\
    \ return L;\r\n    if (node_r <= t) {\r\n      X x = Monoid::op(n->x, p);\r\n\
    \      if (check(x)) {\r\n        p = x;\r\n        return L;\r\n      }\r\n \
    \   }\r\n    if (node_r - node_l == 1) return node_r;\r\n    ll node_m = (node_l\
    \ + node_r) / 2;\r\n    if (!(n->r)) n->r = new_node(node_m, node_r);\r\n    ll\
    \ res = min_left_rec(n->r, node_m, node_r, check, t, p);\r\n    if (res != L)\
    \ return res;\r\n    if (!(n->l)) n->l = new_node(node_l, node_m);\r\n    return\
    \ min_left_rec(n->l, node_l, node_m, check, t, p);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_segtree.hpp
- /library/ds/segtree/dynamic_segtree.hpp.html
title: ds/segtree/dynamic_segtree.hpp
---
