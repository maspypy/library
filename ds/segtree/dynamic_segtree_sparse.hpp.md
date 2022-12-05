---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_segtree_sparse.test.cpp
    title: test/mytest/dynamic_segtree_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/789_3.test.cpp
    title: test/yukicoder/789_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/dynamic_segtree_sparse.hpp\"\n\n// \u5E38\u306B\
    \u307B\u3068\u3093\u3069\u306E\u8981\u7D20\u304C unit \u3067\u3042\u308B\u3053\
    \u3068\u304C\u4FDD\u8A3C\u3055\u308C\u308B\u3088\u3046\u306A\u52D5\u7684\u30BB\
    \u30B0\u6728\n// \u3057\u305F\u304C\u3063\u3066\u3001default_prod \u306E\u985E\
    \u306F\u6301\u305F\u305B\u3089\u308C\u305A\u3001acted monoid \u3082\u4E00\u822C\
    \u306B\u306F\u6271\u3048\u306A\u3044\n// \u30CE\u30FC\u30C9\u6570\u3092 O(N) \u306B\
    \u6291\u3048\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u306E\u304C\u5229\u70B9\
    \u3002\u6C38\u7D9A\u5316\u306F\u306A\u3057\u3002\ntemplate <typename Monoid, bool\
    \ PERSISTENT, int NODES>\nstruct Dynamic_SegTree_Sparse {\n  static_assert(!PERSISTENT);\n\
    \  using MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node {\n\
    \    ll idx;\n    Node *l, *r;\n    X prod, x;\n  };\n\n  const ll L0, R0;\n \
    \ Node *pool;\n  int pid;\n  using np = Node *;\n\n  Dynamic_SegTree_Sparse(ll\
    \ L0, ll R0) : L0(L0), R0(R0), pid(0) {\n    pool = new Node[NODES];\n  }\n\n\
    \  np new_node(ll idx, const X x) {\n    pool[pid].idx = idx;\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = pool[pid].prod = x;\n    return\
    \ &(pool[pid++]);\n  }\n\n  X prod(np root, ll l, ll r) {\n    assert(L0 <= l\
    \ && l < r && r <= R0);\n    X x = MX::unit();\n    prod_rec(root, L0, R0, l,\
    \ r, x);\n    return x;\n  }\n\n  np set(np root, ll i, const X &x) {\n    assert(L0\
    \ <= i && i < R0);\n    return set_rec(root, L0, R0, i, x);\n  }\n\n  np multiply(np\
    \ root, ll i, const X &x) {\n    assert(L0 <= i && i < R0);\n    return multiply_rec(root,\
    \ L0, R0, i, x);\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return max_right_rec(root, check, L0, R0, L, x);\n  }\n\n  /*\n  template\
    \ <typename F>\n  ll min_left(np root, F check, ll R) {\n    assert(L0 <= R &&\
    \ R <= R0 && check(MX::unit()));\n    X x = MX::unit();\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\n  }\n  */\n\n  void reset() { pid = 0; }\n\nprivate:\n\
    \  void update(np c) {\n    c->prod = c->x;\n    if (c->l) c->prod = MX::op(c->l->prod,\
    \ c->prod);\n    if (c->r) c->prod = MX::op(c->prod, c->r->prod);\n  }\n\n  np\
    \ set_rec(np c, ll l, ll r, ll i, X x) {\n    if (!c) {\n      c = new_node(i,\
    \ x);\n      return c;\n    }\n    if (c->idx == i) {\n      c->x = x;\n     \
    \ update(c);\n      return c;\n    }\n    ll m = (l + r) / 2;\n    if (i < m)\
    \ {\n      if (c->idx < i) swap(c->idx, i), swap(c->x, x);\n      c->l = set_rec(c->l,\
    \ l, m, i, x);\n    }\n    if (m <= i) {\n      if (i < c->idx) swap(c->idx, i),\
    \ swap(c->x, x);\n      c->r = set_rec(c->r, m, r, i, x);\n    }\n    update(c);\n\
    \    return c;\n  }\n\n  np multiply_rec(np c, ll l, ll r, ll i, X x) {\n    if\
    \ (!c) {\n      c = new_node(i, x);\n      return c;\n    }\n    if (c->idx ==\
    \ i) {\n      c->x = MX::op(c->x, x);\n      update(c);\n      return c;\n   \
    \ }\n    ll m = (l + r) / 2;\n    if (i < m) {\n      if (c->idx < i) swap(c->idx,\
    \ i), swap(c->x, x);\n      c->l = multiply_rec(c->l, l, m, i, x);\n    }\n  \
    \  if (m <= i) {\n      if (i < c->idx) swap(c->idx, i), swap(c->x, x);\n    \
    \  c->r = multiply_rec(c->r, m, r, i, x);\n    }\n    update(c);\n    return c;\n\
    \  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x) {\n    chmax(ql,\
    \ l);\n    chmin(qr, r);\n    if (ql >= qr || !c) return;\n    if (l == ql &&\
    \ r == qr) {\n      x = MX::op(x, c->prod);\n      return;\n    }\n    ll m =\
    \ (l + r) / 2;\n    prod_rec(c->l, l, m, ql, qr, x);\n    if (ql <= (c->idx) &&\
    \ (c->idx) < qr) x = MX::op(x, c->x);\n    prod_rec(c->r, m, r, ql, qr, x);\n\
    \  }\n\n  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l,\
    \ ll r, ll ql, X &x) {\n    if (!c || r <= ql) return R0;\n    if (check(MX::op(x,\
    \ c->prod))) {\n      x = MX::op(x, c->prod);\n      return R0;\n    }\n    ll\
    \ m = (l + r) / 2;\n    ll k = max_right_rec(c->l, check, l, m, ql, x);\n    if\
    \ (k != R0) return k;\n    if (ql <= (c->idx)) {\n      x = MX::op(x, c->x);\n\
    \      if (!check(x)) return c->idx;\n    }\n    return max_right_rec(c->r, check,\
    \ m, r, ql, x);\n  }\n\n  template <typename F>\n  ll min_left_rec(np c, const\
    \ F &check, ll l, ll r, ll qr, X &x) {\n    if (!c || qr <= l) return L0;\n  \
    \  if (check(MX::op(c->x, x))) {\n      x = MX::op(x, c->x);\n      return L0;\n\
    \    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check, m, r, qr,\
    \ x);\n    if (k != L0) return k;\n    if (c->idx < qr) {\n      x = MX::op(c->x,\
    \ x);\n      if (!check(x)) return c->idx + 1;\n    }\n    return min_left_rec(c->l,\
    \ check, l, m, qr, x);\n  }\n};\n"
  code: "#pragma once\n\n// \u5E38\u306B\u307B\u3068\u3093\u3069\u306E\u8981\u7D20\
    \u304C unit \u3067\u3042\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\u308C\u308B\
    \u3088\u3046\u306A\u52D5\u7684\u30BB\u30B0\u6728\n// \u3057\u305F\u304C\u3063\u3066\
    \u3001default_prod \u306E\u985E\u306F\u6301\u305F\u305B\u3089\u308C\u305A\u3001\
    acted monoid \u3082\u4E00\u822C\u306B\u306F\u6271\u3048\u306A\u3044\n// \u30CE\
    \u30FC\u30C9\u6570\u3092 O(N) \u306B\u6291\u3048\u308B\u3053\u3068\u304C\u3067\
    \u304D\u308B\u306E\u304C\u5229\u70B9\u3002\u6C38\u7D9A\u5316\u306F\u306A\u3057\
    \u3002\ntemplate <typename Monoid, bool PERSISTENT, int NODES>\nstruct Dynamic_SegTree_Sparse\
    \ {\n  static_assert(!PERSISTENT);\n  using MX = Monoid;\n  using X = typename\
    \ MX::value_type;\n\n  struct Node {\n    ll idx;\n    Node *l, *r;\n    X prod,\
    \ x;\n  };\n\n  const ll L0, R0;\n  Node *pool;\n  int pid;\n  using np = Node\
    \ *;\n\n  Dynamic_SegTree_Sparse(ll L0, ll R0) : L0(L0), R0(R0), pid(0) {\n  \
    \  pool = new Node[NODES];\n  }\n\n  np new_node(ll idx, const X x) {\n    pool[pid].idx\
    \ = idx;\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = pool[pid].prod\
    \ = x;\n    return &(pool[pid++]);\n  }\n\n  X prod(np root, ll l, ll r) {\n \
    \   assert(L0 <= l && l < r && r <= R0);\n    X x = MX::unit();\n    prod_rec(root,\
    \ L0, R0, l, r, x);\n    return x;\n  }\n\n  np set(np root, ll i, const X &x)\
    \ {\n    assert(L0 <= i && i < R0);\n    return set_rec(root, L0, R0, i, x);\n\
    \  }\n\n  np multiply(np root, ll i, const X &x) {\n    assert(L0 <= i && i <\
    \ R0);\n    return multiply_rec(root, L0, R0, i, x);\n  }\n\n  template <typename\
    \ F>\n  ll max_right(np root, F check, ll L) {\n    assert(L0 <= L && L <= R0\
    \ && check(MX::unit()));\n    X x = MX::unit();\n    return max_right_rec(root,\
    \ check, L0, R0, L, x);\n  }\n\n  /*\n  template <typename F>\n  ll min_left(np\
    \ root, F check, ll R) {\n    assert(L0 <= R && R <= R0 && check(MX::unit()));\n\
    \    X x = MX::unit();\n    return min_left_rec(root, check, L0, R0, R, x);\n\
    \  }\n  */\n\n  void reset() { pid = 0; }\n\nprivate:\n  void update(np c) {\n\
    \    c->prod = c->x;\n    if (c->l) c->prod = MX::op(c->l->prod, c->prod);\n \
    \   if (c->r) c->prod = MX::op(c->prod, c->r->prod);\n  }\n\n  np set_rec(np c,\
    \ ll l, ll r, ll i, X x) {\n    if (!c) {\n      c = new_node(i, x);\n      return\
    \ c;\n    }\n    if (c->idx == i) {\n      c->x = x;\n      update(c);\n     \
    \ return c;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) {\n      if (c->idx\
    \ < i) swap(c->idx, i), swap(c->x, x);\n      c->l = set_rec(c->l, l, m, i, x);\n\
    \    }\n    if (m <= i) {\n      if (i < c->idx) swap(c->idx, i), swap(c->x, x);\n\
    \      c->r = set_rec(c->r, m, r, i, x);\n    }\n    update(c);\n    return c;\n\
    \  }\n\n  np multiply_rec(np c, ll l, ll r, ll i, X x) {\n    if (!c) {\n    \
    \  c = new_node(i, x);\n      return c;\n    }\n    if (c->idx == i) {\n     \
    \ c->x = MX::op(c->x, x);\n      update(c);\n      return c;\n    }\n    ll m\
    \ = (l + r) / 2;\n    if (i < m) {\n      if (c->idx < i) swap(c->idx, i), swap(c->x,\
    \ x);\n      c->l = multiply_rec(c->l, l, m, i, x);\n    }\n    if (m <= i) {\n\
    \      if (i < c->idx) swap(c->idx, i), swap(c->x, x);\n      c->r = multiply_rec(c->r,\
    \ m, r, i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  void prod_rec(np\
    \ c, ll l, ll r, ll ql, ll qr, X &x) {\n    chmax(ql, l);\n    chmin(qr, r);\n\
    \    if (ql >= qr || !c) return;\n    if (l == ql && r == qr) {\n      x = MX::op(x,\
    \ c->prod);\n      return;\n    }\n    ll m = (l + r) / 2;\n    prod_rec(c->l,\
    \ l, m, ql, qr, x);\n    if (ql <= (c->idx) && (c->idx) < qr) x = MX::op(x, c->x);\n\
    \    prod_rec(c->r, m, r, ql, qr, x);\n  }\n\n  template <typename F>\n  ll max_right_rec(np\
    \ c, const F &check, ll l, ll r, ll ql, X &x) {\n    if (!c || r <= ql) return\
    \ R0;\n    if (check(MX::op(x, c->prod))) {\n      x = MX::op(x, c->prod);\n \
    \     return R0;\n    }\n    ll m = (l + r) / 2;\n    ll k = max_right_rec(c->l,\
    \ check, l, m, ql, x);\n    if (k != R0) return k;\n    if (ql <= (c->idx)) {\n\
    \      x = MX::op(x, c->x);\n      if (!check(x)) return c->idx;\n    }\n    return\
    \ max_right_rec(c->r, check, m, r, ql, x);\n  }\n\n  template <typename F>\n \
    \ ll min_left_rec(np c, const F &check, ll l, ll r, ll qr, X &x) {\n    if (!c\
    \ || qr <= l) return L0;\n    if (check(MX::op(c->x, x))) {\n      x = MX::op(x,\
    \ c->x);\n      return L0;\n    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r,\
    \ check, m, r, qr, x);\n    if (k != L0) return k;\n    if (c->idx < qr) {\n \
    \     x = MX::op(c->x, x);\n      if (!check(x)) return c->idx + 1;\n    }\n \
    \   return min_left_rec(c->l, check, l, m, qr, x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dynamic_segtree_sparse.hpp
  requiredBy: []
  timestamp: '2022-12-05 22:43:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/789_3.test.cpp
  - test/mytest/dynamic_segtree_sparse.test.cpp
documentation_of: ds/segtree/dynamic_segtree_sparse.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_segtree_sparse.hpp
- /library/ds/segtree/dynamic_segtree_sparse.hpp.html
title: ds/segtree/dynamic_segtree_sparse.hpp
---
