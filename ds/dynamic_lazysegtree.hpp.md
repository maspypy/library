---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/789_2.test.cpp
    title: test/yukicoder/789_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/dynamic_lazysegtree.hpp\"\n\n/*\n\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u306B\u6E21\u3059\u3082\u306E\n\u30FBL, R\uFF1A\u6700\u5927\
    \u306E\u7BC4\u56F2\uFF08root node \u306E\u8868\u3059\u7BC4\u56F2\uFF09\n\u30FB\
    function<X(ll,ll)> defulat_fn(l,r)\uFF1A\u521D\u671F\u5024\u3067\u306E [l,r) \u7A4D\
    \u306E\u8A08\u7B97\n*/\ntemplate <class Lazy, int NODES = 5'000'000>\nstruct Dynamic_LazySegTree\
    \ {\n  using Monoid_X = typename Lazy::Monoid_X;\n  using Monoid_A = typename\
    \ Lazy::Monoid_A;\n  using X = typename Monoid_X::value_type;\n  using A = typename\
    \ Monoid_A::value_type;\n\n  struct Node {\n    X x;\n    A a;\n    Node *l, *r;\n\
    \    Node() {}\n    Node(const X &x) : x(x), a(Monoid_A::unit()), l(nullptr),\
    \ r(nullptr) {}\n    X get() { return Lazy::act(x, a); }\n  };\n\n  Node *pool;\n\
    \  int pid;\n  ll L, R;\n  Node *root;\n  function<X(ll, ll)> default_fn;\n\n\
    \  Dynamic_LazySegTree(ll L, ll R, function<X(ll, ll)> f)\n      : pid(0), L(L),\
    \ R(R), default_fn(f) {\n    pool = new Node[NODES];\n    root = new_node(L, R);\n\
    \  }\n\n  void reset() {\n    pid = 0;\n    root = new_node(L, R);\n  }\n\n  void\
    \ set(ll i, const X &x) {\n    assert(L <= i && i < R);\n    set_rec(root, L,\
    \ R, i, x);\n  }\n\n  void apply(ll l, ll r, const A &a) {\n    assert(L <= l\
    \ && l <= r && r <= R);\n    apply_rec(root, L, R, l, r, a);\n  }\n\n  X prod(ll\
    \ l, ll r) {\n    assert(L <= l && l <= r && r <= R);\n    return prod_rec(root,\
    \ L, R, l, r);\n  }\n\n  X prod_all() { return root->get(); }\n\n  template <class\
    \ F>\n  ll max_right(const F &check, ll s) {\n    assert(L <= s && s <= R && check(Monoid_X::unit()));\n\
    \    X p = Monoid_X::unit();\n    return max_right_rec(root, L, R, check, s, p);\n\
    \  }\n\n  template <class F>\n  ll min_left(const F &check, ll t) {\n    assert(L\
    \ <= t && t <= R && check(Monoid_X::unit()));\n    X p = Monoid_X::unit();\n \
    \   return min_left_rec(root, L, R, check, t, p);\n  }\n\n  void debug() {\n \
    \   auto dfs = [&](auto &dfs, Node *n, ll l, ll r) -> void {\n      print(\"lr\"\
    , l, r, \"x\", n->x, \"a\", n->a);\n      ll m = (l + r) / 2;\n      if (n->l)\
    \ dfs(dfs, n->l, l, m);\n      if (n->r) dfs(dfs, n->r, m, r);\n    };\n    dfs(dfs,\
    \ root, L, R);\n  }\n\nprivate:\n  Node *new_node(ll node_l, ll node_r) {\n  \
    \  pool[pid].x = default_fn(node_l, node_r);\n    pool[pid].a = Monoid_A::unit();\n\
    \    pool[pid].l = pool[pid].r = nullptr;\n    return &(pool[pid++]);\n  }\n\n\
    \  void prop(Node *n, ll node_l, ll node_r) {\n    if (n->a == Monoid_A::unit())\
    \ return;\n    ll node_m = (node_l + node_r) / 2;\n    if (!n->l) n->l = new_node(node_l,\
    \ node_m);\n    if (!n->r) n->r = new_node(node_m, node_r);\n    (n->l)->a = Monoid_A::op((n->l)->a,\
    \ n->a);\n    (n->r)->a = Monoid_A::op((n->r)->a, n->a);\n    n->x = Lazy::act(n->x,\
    \ n->a);\n    n->a = Monoid_A::unit();\n  }\n\n  void set_rec(Node *n, ll node_l,\
    \ ll node_r, ll idx, const X &x) {\n    if (node_r - node_l == 1) {\n      n->x\
    \ = x;\n      n->a = Monoid_A::unit();\n      return;\n    }\n    ll node_m =\
    \ (node_l + node_r) / 2;\n    prop(n, node_l, node_r);\n\n    if (idx < node_m)\
    \ {\n      if (!(n->l)) n->l = new_node(node_l, node_m);\n      set_rec(n->l,\
    \ node_l, node_m, idx, x);\n    } else {\n      if (!(n->r)) n->r = new_node(node_m,\
    \ node_r);\n      set_rec(n->r, node_m, node_r, idx, x);\n    }\n    X xl = (n->l\
    \ ? (n->l)->get() : Monoid_X::unit());\n    X xr = (n->r ? (n->r)->get() : Monoid_X::unit());\n\
    \    n->x = Monoid_X::op(xl, xr);\n  }\n\n  void apply_rec(Node *n, ll node_l,\
    \ ll node_r, ll l, ll r, const A &a) {\n    chmax(l, node_l);\n    chmin(r, node_r);\n\
    \    if (l >= r) return;\n    if (l == node_l && r == node_r) {\n      n->a =\
    \ Monoid_A::op(n->a, a);\n      return;\n    }\n    ll node_m = (node_l + node_r)\
    \ / 2;\n    prop(n, node_l, node_r);\n    if (!(n->l)) n->l = new_node(node_l,\
    \ node_m);\n    if (!(n->r)) n->r = new_node(node_m, node_r);\n    apply_rec(n->l,\
    \ node_l, node_m, l, r, a);\n    apply_rec(n->r, node_m, node_r, l, r, a);\n \
    \   n->x = Monoid_X::op((n->l)->get(), (n->r)->get());\n  }\n\n  X prod_rec(Node\
    \ *n, ll node_l, ll node_r, ll l, ll r) {\n    chmax(l, node_l);\n    chmin(r,\
    \ node_r);\n    if (l >= r) return Monoid_X::unit();\n    if (l == node_l && r\
    \ == node_r) return n->get();\n    ll node_m = (node_l + node_r) / 2;\n    prop(n,\
    \ node_l, node_r);\n    X xl = (n->l ? prod_rec(n->l, node_l, node_m, l, r) :\
    \ Monoid_X::unit());\n    X xr = (n->r ? prod_rec(n->r, node_m, node_r, l, r)\
    \ : Monoid_X::unit());\n    return Monoid_X::op(xl, xr);\n  }\n\n  template <typename\
    \ F>\n  ll max_right_rec(Node *n, ll node_l, ll node_r, const F &check, ll s,\
    \ X &p) {\n    if (node_r <= s) return R;\n    if (s <= node_l) {\n      X x =\
    \ Monoid_X::op(p, n->get());\n      if (check(x)) {\n        p = x;\n        return\
    \ R;\n      }\n    }\n    if (node_r - node_l == 1) return node_l;\n    ll node_m\
    \ = (node_l + node_r) / 2;\n    if (!(n->l)) n->l = new_node(node_l, node_m);\n\
    \    if (!(n->r)) n->r = new_node(node_m, node_r);\n    prop(n, node_l, node_r);\n\
    \    ll res = max_right_rec(n->l, node_l, node_m, check, s, p);\n    if (res !=\
    \ R) return res;\n    return max_right_rec(n->r, node_m, node_r, check, s, p);\n\
    \  }\n\n  template <typename F>\n  ll min_left_rec(Node *n, ll node_l, ll node_r,\
    \ const F &check, ll t, X &p) {\n    if (t <= node_l) return L;\n    if (node_r\
    \ <= t) {\n      X x = Monoid_X::op(n->get(), p);\n      if (check(x)) {\n   \
    \     p = x;\n        return L;\n      }\n    }\n    if (node_r - node_l == 1)\
    \ return node_r;\n    ll node_m = (node_l + node_r) / 2;\n    if (!(n->l)) n->l\
    \ = new_node(node_l, node_m);\n    if (!(n->r)) n->r = new_node(node_m, node_r);\n\
    \    prop(n, node_l, node_r);\n    ll res = min_left_rec(n->r, node_m, node_r,\
    \ check, t, p);\n    if (res != L) return res;\n    return min_left_rec(n->l,\
    \ node_l, node_m, check, t, p);\n  }\n};\n"
  code: "#pragma once\n\n/*\n\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u6E21\
    \u3059\u3082\u306E\n\u30FBL, R\uFF1A\u6700\u5927\u306E\u7BC4\u56F2\uFF08root node\
    \ \u306E\u8868\u3059\u7BC4\u56F2\uFF09\n\u30FBfunction<X(ll,ll)> defulat_fn(l,r)\uFF1A\
    \u521D\u671F\u5024\u3067\u306E [l,r) \u7A4D\u306E\u8A08\u7B97\n*/\ntemplate <class\
    \ Lazy, int NODES = 5'000'000>\nstruct Dynamic_LazySegTree {\n  using Monoid_X\
    \ = typename Lazy::Monoid_X;\n  using Monoid_A = typename Lazy::Monoid_A;\n  using\
    \ X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \n  struct Node {\n    X x;\n    A a;\n    Node *l, *r;\n    Node() {}\n    Node(const\
    \ X &x) : x(x), a(Monoid_A::unit()), l(nullptr), r(nullptr) {}\n    X get() {\
    \ return Lazy::act(x, a); }\n  };\n\n  Node *pool;\n  int pid;\n  ll L, R;\n \
    \ Node *root;\n  function<X(ll, ll)> default_fn;\n\n  Dynamic_LazySegTree(ll L,\
    \ ll R, function<X(ll, ll)> f)\n      : pid(0), L(L), R(R), default_fn(f) {\n\
    \    pool = new Node[NODES];\n    root = new_node(L, R);\n  }\n\n  void reset()\
    \ {\n    pid = 0;\n    root = new_node(L, R);\n  }\n\n  void set(ll i, const X\
    \ &x) {\n    assert(L <= i && i < R);\n    set_rec(root, L, R, i, x);\n  }\n\n\
    \  void apply(ll l, ll r, const A &a) {\n    assert(L <= l && l <= r && r <= R);\n\
    \    apply_rec(root, L, R, l, r, a);\n  }\n\n  X prod(ll l, ll r) {\n    assert(L\
    \ <= l && l <= r && r <= R);\n    return prod_rec(root, L, R, l, r);\n  }\n\n\
    \  X prod_all() { return root->get(); }\n\n  template <class F>\n  ll max_right(const\
    \ F &check, ll s) {\n    assert(L <= s && s <= R && check(Monoid_X::unit()));\n\
    \    X p = Monoid_X::unit();\n    return max_right_rec(root, L, R, check, s, p);\n\
    \  }\n\n  template <class F>\n  ll min_left(const F &check, ll t) {\n    assert(L\
    \ <= t && t <= R && check(Monoid_X::unit()));\n    X p = Monoid_X::unit();\n \
    \   return min_left_rec(root, L, R, check, t, p);\n  }\n\n  void debug() {\n \
    \   auto dfs = [&](auto &dfs, Node *n, ll l, ll r) -> void {\n      print(\"lr\"\
    , l, r, \"x\", n->x, \"a\", n->a);\n      ll m = (l + r) / 2;\n      if (n->l)\
    \ dfs(dfs, n->l, l, m);\n      if (n->r) dfs(dfs, n->r, m, r);\n    };\n    dfs(dfs,\
    \ root, L, R);\n  }\n\nprivate:\n  Node *new_node(ll node_l, ll node_r) {\n  \
    \  pool[pid].x = default_fn(node_l, node_r);\n    pool[pid].a = Monoid_A::unit();\n\
    \    pool[pid].l = pool[pid].r = nullptr;\n    return &(pool[pid++]);\n  }\n\n\
    \  void prop(Node *n, ll node_l, ll node_r) {\n    if (n->a == Monoid_A::unit())\
    \ return;\n    ll node_m = (node_l + node_r) / 2;\n    if (!n->l) n->l = new_node(node_l,\
    \ node_m);\n    if (!n->r) n->r = new_node(node_m, node_r);\n    (n->l)->a = Monoid_A::op((n->l)->a,\
    \ n->a);\n    (n->r)->a = Monoid_A::op((n->r)->a, n->a);\n    n->x = Lazy::act(n->x,\
    \ n->a);\n    n->a = Monoid_A::unit();\n  }\n\n  void set_rec(Node *n, ll node_l,\
    \ ll node_r, ll idx, const X &x) {\n    if (node_r - node_l == 1) {\n      n->x\
    \ = x;\n      n->a = Monoid_A::unit();\n      return;\n    }\n    ll node_m =\
    \ (node_l + node_r) / 2;\n    prop(n, node_l, node_r);\n\n    if (idx < node_m)\
    \ {\n      if (!(n->l)) n->l = new_node(node_l, node_m);\n      set_rec(n->l,\
    \ node_l, node_m, idx, x);\n    } else {\n      if (!(n->r)) n->r = new_node(node_m,\
    \ node_r);\n      set_rec(n->r, node_m, node_r, idx, x);\n    }\n    X xl = (n->l\
    \ ? (n->l)->get() : Monoid_X::unit());\n    X xr = (n->r ? (n->r)->get() : Monoid_X::unit());\n\
    \    n->x = Monoid_X::op(xl, xr);\n  }\n\n  void apply_rec(Node *n, ll node_l,\
    \ ll node_r, ll l, ll r, const A &a) {\n    chmax(l, node_l);\n    chmin(r, node_r);\n\
    \    if (l >= r) return;\n    if (l == node_l && r == node_r) {\n      n->a =\
    \ Monoid_A::op(n->a, a);\n      return;\n    }\n    ll node_m = (node_l + node_r)\
    \ / 2;\n    prop(n, node_l, node_r);\n    if (!(n->l)) n->l = new_node(node_l,\
    \ node_m);\n    if (!(n->r)) n->r = new_node(node_m, node_r);\n    apply_rec(n->l,\
    \ node_l, node_m, l, r, a);\n    apply_rec(n->r, node_m, node_r, l, r, a);\n \
    \   n->x = Monoid_X::op((n->l)->get(), (n->r)->get());\n  }\n\n  X prod_rec(Node\
    \ *n, ll node_l, ll node_r, ll l, ll r) {\n    chmax(l, node_l);\n    chmin(r,\
    \ node_r);\n    if (l >= r) return Monoid_X::unit();\n    if (l == node_l && r\
    \ == node_r) return n->get();\n    ll node_m = (node_l + node_r) / 2;\n    prop(n,\
    \ node_l, node_r);\n    X xl = (n->l ? prod_rec(n->l, node_l, node_m, l, r) :\
    \ Monoid_X::unit());\n    X xr = (n->r ? prod_rec(n->r, node_m, node_r, l, r)\
    \ : Monoid_X::unit());\n    return Monoid_X::op(xl, xr);\n  }\n\n  template <typename\
    \ F>\n  ll max_right_rec(Node *n, ll node_l, ll node_r, const F &check, ll s,\
    \ X &p) {\n    if (node_r <= s) return R;\n    if (s <= node_l) {\n      X x =\
    \ Monoid_X::op(p, n->get());\n      if (check(x)) {\n        p = x;\n        return\
    \ R;\n      }\n    }\n    if (node_r - node_l == 1) return node_l;\n    ll node_m\
    \ = (node_l + node_r) / 2;\n    if (!(n->l)) n->l = new_node(node_l, node_m);\n\
    \    if (!(n->r)) n->r = new_node(node_m, node_r);\n    prop(n, node_l, node_r);\n\
    \    ll res = max_right_rec(n->l, node_l, node_m, check, s, p);\n    if (res !=\
    \ R) return res;\n    return max_right_rec(n->r, node_m, node_r, check, s, p);\n\
    \  }\n\n  template <typename F>\n  ll min_left_rec(Node *n, ll node_l, ll node_r,\
    \ const F &check, ll t, X &p) {\n    if (t <= node_l) return L;\n    if (node_r\
    \ <= t) {\n      X x = Monoid_X::op(n->get(), p);\n      if (check(x)) {\n   \
    \     p = x;\n        return L;\n      }\n    }\n    if (node_r - node_l == 1)\
    \ return node_r;\n    ll node_m = (node_l + node_r) / 2;\n    if (!(n->l)) n->l\
    \ = new_node(node_l, node_m);\n    if (!(n->r)) n->r = new_node(node_m, node_r);\n\
    \    prop(n, node_l, node_r);\n    ll res = min_left_rec(n->r, node_m, node_r,\
    \ check, t, p);\n    if (res != L) return res;\n    return min_left_rec(n->l,\
    \ node_l, node_m, check, t, p);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dynamic_lazysegtree.hpp
  requiredBy: []
  timestamp: '2022-11-28 18:35:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/789_2.test.cpp
documentation_of: ds/dynamic_lazysegtree.hpp
layout: document
redirect_from:
- /library/ds/dynamic_lazysegtree.hpp
- /library/ds/dynamic_lazysegtree.hpp.html
title: ds/dynamic_lazysegtree.hpp
---
