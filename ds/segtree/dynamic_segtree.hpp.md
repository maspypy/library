---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/online_uniqueproductquery.hpp
    title: ds/online_uniqueproductquery.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/double_ended_pq.test.cpp
    title: test/library_checker/datastructure/double_ended_pq.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/point_set_range_composite_dynamic.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_dynamic.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/range_kth_smallest_pseg.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_pseg.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1036.test.cpp
    title: test/yukicoder/1036.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1649.test.cpp
    title: test/yukicoder/1649.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1826.test.cpp
    title: test/yukicoder/1826.test.cpp
  - icon: ':x:'
    path: test/yukicoder/789.test.cpp
    title: test/yukicoder/789.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/dynamic_segtree.hpp\"\n\r\n// sparse \u3082\u3042\
    \u308B\u306E\u3067\u72B6\u6CC1\u306B\u3088\u3063\u3066\u306F\u305D\u3063\u3061\
    \u3067\r\ntemplate <typename Monoid, bool PERSISTENT, int NODES>\r\nstruct Dynamic_SegTree\
    \ {\r\n  using MX = Monoid;\r\n  using X = typename MX::value_type;\r\n  using\
    \ F = function<X(ll, ll)>;\r\n  F default_prod;\r\n\r\n  struct Node {\r\n   \
    \ Node *l, *r;\r\n    X x;\r\n  };\r\n\r\n  const ll L0, R0;\r\n  Node *pool;\r\
    \n  int pid;\r\n  using np = Node *;\r\n\r\n  Dynamic_SegTree(\r\n      ll L0,\
    \ ll R0, F default_prod = [](ll l, ll r) -> X { return MX::unit(); })\r\n    \
    \  : default_prod(default_prod), L0(L0), R0(R0), pid(0) {\r\n    pool = new Node[NODES];\r\
    \n  }\r\n\r\n  np new_root() { return new_node(L0, R0); }\r\n\r\n  np new_node(const\
    \ X x) {\r\n    pool[pid].l = pool[pid].r = nullptr;\r\n    pool[pid].x = x;\r\
    \n    return &(pool[pid++]);\r\n  }\r\n\r\n  np new_node(ll l, ll r) { return\
    \ new_node(default_prod(l, r)); }\r\n  np new_node() { return new_node(L0, R0);\
    \ }\r\n\r\n  np new_node(const vc<X> &dat) {\r\n    assert(L0 == 0 && R0 == len(dat));\r\
    \n    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {\r\n      if (l == r) return\
    \ nullptr;\r\n      if (r == l + 1) return new_node(dat[l]);\r\n      ll m = (l\
    \ + r) / 2;\r\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);\r\n\
    \      X x = MX::op(l_root->x, r_root->x);\r\n      np root = new_node(x);\r\n\
    \      root->l = l_root, root->r = r_root;\r\n      return root;\r\n    };\r\n\
    \    return dfs(dfs, 0, len(dat));\r\n  }\r\n\r\n  X prod(np root, ll l, ll r)\
    \ {\r\n    assert(pid && root && L0 <= l && l < r && r <= R0);\r\n    X x = MX::unit();\r\
    \n    prod_rec(root, L0, R0, l, r, x);\r\n    return x;\r\n  }\r\n\r\n  np set(np\
    \ root, ll i, const X &x) {\r\n    assert(pid && root && L0 <= i && i < R0);\r\
    \n    return set_rec(root, L0, R0, i, x);\r\n  }\r\n\r\n  np multiply(np root,\
    \ ll i, const X &x) {\r\n    assert(pid && root && L0 <= i && i < R0);\r\n   \
    \ return multiply_rec(root, L0, R0, i, x);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  ll max_right(np root, F check, ll L) {\r\n    assert(pid && root &&\
    \ L0 <= L && L <= R0 && check(MX::unit()));\r\n    X x = MX::unit();\r\n    return\
    \ max_right_rec(root, check, L0, R0, L, x);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  ll min_left(np root, F check, ll R) {\r\n    assert(pid && L0 <= R &&\
    \ R <= R0 && check(MX::unit()));\r\n    X x = MX::unit();\r\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\r\n  }\r\n\r\n  vc<X> get_all(np root) {\r\n    assert(root);\r\
    \n    vc<X> res;\r\n    res.reserve(R0 - L0);\r\n    auto dfs = [&](auto &dfs,\
    \ np c, ll l, ll r) -> void {\r\n      if (!c) c = new_node(l, r);\r\n      if\
    \ (r - l == 1) {\r\n        res.eb(c->x);\r\n        return;\r\n      }\r\n  \
    \    ll m = (l + r) / 2;\r\n      dfs(dfs, c->l, l, m);\r\n      dfs(dfs, c->r,\
    \ m, r);\r\n    };\r\n    dfs(dfs, root, L0, R0);\r\n    return res;\r\n  }\r\n\
    \r\n  void reset() { pid = 0; }\r\n\r\nprivate:\r\n  np copy_node(np c) {\r\n\
    \    if (!c || !PERSISTENT) return c;\r\n    pool[pid].l = c->l, pool[pid].r =\
    \ c->r;\r\n    pool[pid].x = c->x;\r\n    return &(pool[pid++]);\r\n  }\r\n\r\n\
    \  np set_rec(np c, ll l, ll r, ll i, const X &x) {\r\n    if (r == l + 1) {\r\
    \n      c = copy_node(c);\r\n      c->x = x;\r\n      return c;\r\n    }\r\n \
    \   ll m = (l + r) / 2;\r\n\r\n    c = copy_node(c);\r\n    if (i < m) {\r\n \
    \     if (!c->l) c->l = new_node(l, m);\r\n      c->l = set_rec(c->l, l, m, i,\
    \ x);\r\n    } else {\r\n      if (!c->r) c->r = new_node(m, r);\r\n      c->r\
    \ = set_rec(c->r, m, r, i, x);\r\n    }\r\n    X xl = (c->l ? c->l->x : default_prod(l,\
    \ m));\r\n    X xr = (c->r ? c->r->x : default_prod(m, r));\r\n    c->x = MX::op(xl,\
    \ xr);\r\n    return c;\r\n  }\r\n\r\n  np multiply_rec(np c, ll l, ll r, ll i,\
    \ const X &x) {\r\n    if (r == l + 1) {\r\n      c = copy_node(c);\r\n      c->x\
    \ = MX::op(c->x, x);\r\n      return c;\r\n    }\r\n    ll m = (l + r) / 2;\r\n\
    \    c = copy_node(c);\r\n\r\n    if (i < m) {\r\n      if (!c->l) c->l = new_node(l,\
    \ m);\r\n      c->l = multiply_rec(c->l, l, m, i, x);\r\n    } else {\r\n    \
    \  if (!c->r) c->r = new_node(m, r);\r\n      c->r = multiply_rec(c->r, m, r,\
    \ i, x);\r\n    }\r\n    X xl = (c->l ? c->l->x : default_prod(l, m));\r\n   \
    \ X xr = (c->r ? c->r->x : default_prod(m, r));\r\n    c->x = MX::op(xl, xr);\r\
    \n    return c;\r\n  }\r\n\r\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr,\
    \ X &x) {\r\n    chmax(ql, l);\r\n    chmin(qr, r);\r\n    if (ql >= qr) return;\r\
    \n    if (!c) {\r\n      x = MX::op(x, default_prod(ql, qr));\r\n      return;\r\
    \n    }\r\n    if (l == ql && r == qr) {\r\n      x = MX::op(x, c->x);\r\n   \
    \   return;\r\n    }\r\n    ll m = (l + r) / 2;\r\n    prod_rec(c->l, l, m, ql,\
    \ qr, x);\r\n    prod_rec(c->r, m, r, ql, qr, x);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x) {\r\n\
    \    if (r <= ql) return R0;\r\n    if (ql <= l && check(MX::op(x, c->x))) {\r\
    \n      x = MX::op(x, c->x);\r\n      return R0;\r\n    }\r\n    if (r == l +\
    \ 1) return l;\r\n    ll m = (l + r) / 2;\r\n    if (!c->l) c->l = new_node(l,\
    \ m);\r\n    ll k = max_right_rec(c->l, check, l, m, ql, x);\r\n    if (k != R0)\
    \ return k;\r\n    if (!c->r) c->r = new_node(m, r);\r\n    return max_right_rec(c->r,\
    \ check, m, r, ql, x);\r\n  }\r\n\r\n  template <typename F>\r\n  ll min_left_rec(np\
    \ c, const F &check, ll l, ll r, ll qr, X &x) {\r\n    if (qr <= l) return L0;\r\
    \n    if (r <= qr && check(MX::op(c->x, x))) {\r\n      x = MX::op(x, c->x);\r\
    \n      return L0;\r\n    }\r\n    if (r == l + 1) return r;\r\n    ll m = (l\
    \ + r) / 2;\r\n    if (!c->r) c->r = new_node(m, r);\r\n    ll k = min_left_rec(c->r,\
    \ check, m, r, qr, x);\r\n    if (k != L0) return k;\r\n    if (!c->l) c->l =\
    \ new_node(l, m);\r\n    return min_left_rec(c->l, check, l, m, qr, x);\r\n  }\r\
    \n};\n"
  code: "#pragma once\r\n\r\n// sparse \u3082\u3042\u308B\u306E\u3067\u72B6\u6CC1\u306B\
    \u3088\u3063\u3066\u306F\u305D\u3063\u3061\u3067\r\ntemplate <typename Monoid,\
    \ bool PERSISTENT, int NODES>\r\nstruct Dynamic_SegTree {\r\n  using MX = Monoid;\r\
    \n  using X = typename MX::value_type;\r\n  using F = function<X(ll, ll)>;\r\n\
    \  F default_prod;\r\n\r\n  struct Node {\r\n    Node *l, *r;\r\n    X x;\r\n\
    \  };\r\n\r\n  const ll L0, R0;\r\n  Node *pool;\r\n  int pid;\r\n  using np =\
    \ Node *;\r\n\r\n  Dynamic_SegTree(\r\n      ll L0, ll R0, F default_prod = [](ll\
    \ l, ll r) -> X { return MX::unit(); })\r\n      : default_prod(default_prod),\
    \ L0(L0), R0(R0), pid(0) {\r\n    pool = new Node[NODES];\r\n  }\r\n\r\n  np new_root()\
    \ { return new_node(L0, R0); }\r\n\r\n  np new_node(const X x) {\r\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\r\n    pool[pid].x = x;\r\n    return &(pool[pid++]);\r\
    \n  }\r\n\r\n  np new_node(ll l, ll r) { return new_node(default_prod(l, r));\
    \ }\r\n  np new_node() { return new_node(L0, R0); }\r\n\r\n  np new_node(const\
    \ vc<X> &dat) {\r\n    assert(L0 == 0 && R0 == len(dat));\r\n    auto dfs = [&](auto\
    \ &dfs, ll l, ll r) -> Node * {\r\n      if (l == r) return nullptr;\r\n     \
    \ if (r == l + 1) return new_node(dat[l]);\r\n      ll m = (l + r) / 2;\r\n  \
    \    np l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);\r\n      X x = MX::op(l_root->x,\
    \ r_root->x);\r\n      np root = new_node(x);\r\n      root->l = l_root, root->r\
    \ = r_root;\r\n      return root;\r\n    };\r\n    return dfs(dfs, 0, len(dat));\r\
    \n  }\r\n\r\n  X prod(np root, ll l, ll r) {\r\n    assert(pid && root && L0 <=\
    \ l && l < r && r <= R0);\r\n    X x = MX::unit();\r\n    prod_rec(root, L0, R0,\
    \ l, r, x);\r\n    return x;\r\n  }\r\n\r\n  np set(np root, ll i, const X &x)\
    \ {\r\n    assert(pid && root && L0 <= i && i < R0);\r\n    return set_rec(root,\
    \ L0, R0, i, x);\r\n  }\r\n\r\n  np multiply(np root, ll i, const X &x) {\r\n\
    \    assert(pid && root && L0 <= i && i < R0);\r\n    return multiply_rec(root,\
    \ L0, R0, i, x);\r\n  }\r\n\r\n  template <typename F>\r\n  ll max_right(np root,\
    \ F check, ll L) {\r\n    assert(pid && root && L0 <= L && L <= R0 && check(MX::unit()));\r\
    \n    X x = MX::unit();\r\n    return max_right_rec(root, check, L0, R0, L, x);\r\
    \n  }\r\n\r\n  template <typename F>\r\n  ll min_left(np root, F check, ll R)\
    \ {\r\n    assert(pid && L0 <= R && R <= R0 && check(MX::unit()));\r\n    X x\
    \ = MX::unit();\r\n    return min_left_rec(root, check, L0, R0, R, x);\r\n  }\r\
    \n\r\n  vc<X> get_all(np root) {\r\n    assert(root);\r\n    vc<X> res;\r\n  \
    \  res.reserve(R0 - L0);\r\n    auto dfs = [&](auto &dfs, np c, ll l, ll r) ->\
    \ void {\r\n      if (!c) c = new_node(l, r);\r\n      if (r - l == 1) {\r\n \
    \       res.eb(c->x);\r\n        return;\r\n      }\r\n      ll m = (l + r) /\
    \ 2;\r\n      dfs(dfs, c->l, l, m);\r\n      dfs(dfs, c->r, m, r);\r\n    };\r\
    \n    dfs(dfs, root, L0, R0);\r\n    return res;\r\n  }\r\n\r\n  void reset()\
    \ { pid = 0; }\r\n\r\nprivate:\r\n  np copy_node(np c) {\r\n    if (!c || !PERSISTENT)\
    \ return c;\r\n    pool[pid].l = c->l, pool[pid].r = c->r;\r\n    pool[pid].x\
    \ = c->x;\r\n    return &(pool[pid++]);\r\n  }\r\n\r\n  np set_rec(np c, ll l,\
    \ ll r, ll i, const X &x) {\r\n    if (r == l + 1) {\r\n      c = copy_node(c);\r\
    \n      c->x = x;\r\n      return c;\r\n    }\r\n    ll m = (l + r) / 2;\r\n\r\
    \n    c = copy_node(c);\r\n    if (i < m) {\r\n      if (!c->l) c->l = new_node(l,\
    \ m);\r\n      c->l = set_rec(c->l, l, m, i, x);\r\n    } else {\r\n      if (!c->r)\
    \ c->r = new_node(m, r);\r\n      c->r = set_rec(c->r, m, r, i, x);\r\n    }\r\
    \n    X xl = (c->l ? c->l->x : default_prod(l, m));\r\n    X xr = (c->r ? c->r->x\
    \ : default_prod(m, r));\r\n    c->x = MX::op(xl, xr);\r\n    return c;\r\n  }\r\
    \n\r\n  np multiply_rec(np c, ll l, ll r, ll i, const X &x) {\r\n    if (r ==\
    \ l + 1) {\r\n      c = copy_node(c);\r\n      c->x = MX::op(c->x, x);\r\n   \
    \   return c;\r\n    }\r\n    ll m = (l + r) / 2;\r\n    c = copy_node(c);\r\n\
    \r\n    if (i < m) {\r\n      if (!c->l) c->l = new_node(l, m);\r\n      c->l\
    \ = multiply_rec(c->l, l, m, i, x);\r\n    } else {\r\n      if (!c->r) c->r =\
    \ new_node(m, r);\r\n      c->r = multiply_rec(c->r, m, r, i, x);\r\n    }\r\n\
    \    X xl = (c->l ? c->l->x : default_prod(l, m));\r\n    X xr = (c->r ? c->r->x\
    \ : default_prod(m, r));\r\n    c->x = MX::op(xl, xr);\r\n    return c;\r\n  }\r\
    \n\r\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x) {\r\n    chmax(ql,\
    \ l);\r\n    chmin(qr, r);\r\n    if (ql >= qr) return;\r\n    if (!c) {\r\n \
    \     x = MX::op(x, default_prod(ql, qr));\r\n      return;\r\n    }\r\n    if\
    \ (l == ql && r == qr) {\r\n      x = MX::op(x, c->x);\r\n      return;\r\n  \
    \  }\r\n    ll m = (l + r) / 2;\r\n    prod_rec(c->l, l, m, ql, qr, x);\r\n  \
    \  prod_rec(c->r, m, r, ql, qr, x);\r\n  }\r\n\r\n  template <typename F>\r\n\
    \  ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x) {\r\n    if\
    \ (r <= ql) return R0;\r\n    if (ql <= l && check(MX::op(x, c->x))) {\r\n   \
    \   x = MX::op(x, c->x);\r\n      return R0;\r\n    }\r\n    if (r == l + 1) return\
    \ l;\r\n    ll m = (l + r) / 2;\r\n    if (!c->l) c->l = new_node(l, m);\r\n \
    \   ll k = max_right_rec(c->l, check, l, m, ql, x);\r\n    if (k != R0) return\
    \ k;\r\n    if (!c->r) c->r = new_node(m, r);\r\n    return max_right_rec(c->r,\
    \ check, m, r, ql, x);\r\n  }\r\n\r\n  template <typename F>\r\n  ll min_left_rec(np\
    \ c, const F &check, ll l, ll r, ll qr, X &x) {\r\n    if (qr <= l) return L0;\r\
    \n    if (r <= qr && check(MX::op(c->x, x))) {\r\n      x = MX::op(x, c->x);\r\
    \n      return L0;\r\n    }\r\n    if (r == l + 1) return r;\r\n    ll m = (l\
    \ + r) / 2;\r\n    if (!c->r) c->r = new_node(m, r);\r\n    ll k = min_left_rec(c->r,\
    \ check, m, r, qr, x);\r\n    if (k != L0) return k;\r\n    if (!c->l) c->l =\
    \ new_node(l, m);\r\n    return min_left_rec(c->l, check, l, m, qr, x);\r\n  }\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dynamic_segtree.hpp
  requiredBy:
  - ds/online_uniqueproductquery.hpp
  timestamp: '2022-12-12 00:25:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1649.test.cpp
  - test/yukicoder/789.test.cpp
  - test/yukicoder/1826.test.cpp
  - test/yukicoder/1036.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_pseg.test.cpp
  - test/library_checker/datastructure/double_ended_pq.test.cpp
  - test/library_checker/datastructure/point_set_range_composite_dynamic.test.cpp
documentation_of: ds/segtree/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_segtree.hpp
- /library/ds/segtree/dynamic_segtree.hpp.html
title: ds/segtree/dynamic_segtree.hpp
---
