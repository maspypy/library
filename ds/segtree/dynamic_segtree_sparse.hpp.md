---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/double_ended_pq_2.test.cpp
    title: test/library_checker/datastructure/double_ended_pq_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_pseg_sp.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_pseg_sp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_segtree_sparse.test.cpp
    title: test/mytest/dynamic_segtree_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1649_2.test.cpp
    title: test/yukicoder/1649_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1826_2.test.cpp
    title: test/yukicoder/1826_2.test.cpp
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
    \u306B\u306F\u6271\u3048\u306A\u3044\n// \u6C38\u7D9A\u5316\u3057\u306A\u3044\u5834\
    \u5408\u306E\u30CE\u30FC\u30C9\u6570\u3092 O(N) \u306B\u6291\u3048\u308B\u3053\
    \u3068\u304C\u3067\u304D\u308B\u306E\u304C\u5229\u70B9\n// \u5BC6\u306A\u3082\u306E\
    \u3092\u6C38\u7D9A\u5316\u3059\u308B\u3068\u304D\u306F\u304B\u3048\u3063\u3066\
    \u9045\u304F\u306A\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B\ntemplate <typename\
    \ Monoid, bool PERSISTENT, int NODES>\nstruct Dynamic_SegTree_Sparse {\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node {\n    ll\
    \ idx;\n    Node *l, *r;\n    X prod, x;\n  };\n\n  const ll L0, R0;\n  Node *pool;\n\
    \  int pid;\n  using np = Node *;\n\n  Dynamic_SegTree_Sparse(ll L0, ll R0) :\
    \ L0(L0), R0(R0), pid(0) {\n    pool = new Node[NODES];\n  }\n\n  np new_root()\
    \ { return nullptr; }\n\n  np new_node(ll idx, const X x) {\n    pool[pid].idx\
    \ = idx;\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = pool[pid].prod\
    \ = x;\n    return &(pool[pid++]);\n  }\n\n  X prod(np root, ll l, ll r) {\n \
    \   assert(L0 <= l && l < r && r <= R0);\n    X x = MX::unit();\n    prod_rec(root,\
    \ L0, R0, l, r, x);\n    return x;\n  }\n\n  np set(np root, ll i, const X &x)\
    \ {\n    assert(L0 <= i && i < R0);\n    return set_rec(root, L0, R0, i, x);\n\
    \  }\n\n  np multiply(np root, ll i, const X &x) {\n    assert(L0 <= i && i <\
    \ R0);\n    return multiply_rec(root, L0, R0, i, x);\n  }\n\n  template <typename\
    \ F>\n  ll max_right(np root, F check, ll L) {\n    assert(L0 <= L && L <= R0\
    \ && check(MX::unit()));\n    X x = MX::unit();\n    return max_right_rec(root,\
    \ check, L0, R0, L, x);\n  }\n\n  template <typename F>\n  ll min_left(np root,\
    \ F check, ll R) {\n    assert(L0 <= R && R <= R0 && check(MX::unit()));\n   \
    \ X x = MX::unit();\n    return min_left_rec(root, check, L0, R0, R, x);\n  }\n\
    \n  void reset() { pid = 0; }\n\n  vc<pair<ll, X>> get_all(np root) {\n    vc<pair<ll,\
    \ X>> res;\n    auto dfs = [&](auto &dfs, np c) -> void {\n      if (!c) return;\n\
    \      dfs(dfs, c->l);\n      res.eb(c->idx, c->x);\n      dfs(dfs, c->r);\n \
    \   };\n    dfs(dfs, root);\n    return res;\n  }\n\n  X get(np root, ll idx)\
    \ {\n    auto dfs = [&](auto &dfs, np c) -> X {\n      if (!c) return Monoid::unit();\n\
    \      if (idx == c->idx) return c->x;\n      if (idx < (c->idx)) return dfs(dfs,\
    \ c->l);\n      return dfs(dfs, c->r);\n    };\n    return dfs(dfs, root);\n \
    \ }\n\nprivate:\n  void update(np c) {\n    c->prod = c->x;\n    if (c->l) c->prod\
    \ = MX::op(c->l->prod, c->prod);\n    if (c->r) c->prod = MX::op(c->prod, c->r->prod);\n\
    \  }\n\n  np copy_node(np c) {\n    if (!c || !PERSISTENT) return c;\n    pool[pid].idx\
    \ = c->idx;\n    pool[pid].l = c->l;\n    pool[pid].r = c->r;\n    pool[pid].x\
    \ = c->x;\n    pool[pid].prod = c->prod;\n    return &(pool[pid++]);\n  }\n\n\
    \  np set_rec(np c, ll l, ll r, ll i, X x) {\n    if (!c) {\n      c = new_node(i,\
    \ x);\n      return c;\n    }\n    c = copy_node(c);\n    if (c->idx == i) {\n\
    \      c->x = x;\n      update(c);\n      return c;\n    }\n    ll m = (l + r)\
    \ / 2;\n    if (i < m) {\n      if (c->idx < i) swap(c->idx, i), swap(c->x, x);\n\
    \      c->l = set_rec(c->l, l, m, i, x);\n    }\n    if (m <= i) {\n      if (i\
    \ < c->idx) swap(c->idx, i), swap(c->x, x);\n      c->r = set_rec(c->r, m, r,\
    \ i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  np multiply_rec(np c,\
    \ ll l, ll r, ll i, X x) {\n    if (!c) {\n      c = new_node(i, x);\n      return\
    \ c;\n    }\n    c = copy_node(c);\n    if (c->idx == i) {\n      c->x = MX::op(c->x,\
    \ x);\n      update(c);\n      return c;\n    }\n    ll m = (l + r) / 2;\n   \
    \ if (i < m) {\n      if (c->idx < i) swap(c->idx, i), swap(c->x, x);\n      c->l\
    \ = multiply_rec(c->l, l, m, i, x);\n    }\n    if (m <= i) {\n      if (i < c->idx)\
    \ swap(c->idx, i), swap(c->x, x);\n      c->r = multiply_rec(c->r, m, r, i, x);\n\
    \    }\n    update(c);\n    return c;\n  }\n\n  void prod_rec(np c, ll l, ll r,\
    \ ll ql, ll qr, X &x) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr\
    \ || !c) return;\n    if (l == ql && r == qr) {\n      x = MX::op(x, c->prod);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    prod_rec(c->l, l, m, ql, qr,\
    \ x);\n    if (ql <= (c->idx) && (c->idx) < qr) x = MX::op(x, c->x);\n    prod_rec(c->r,\
    \ m, r, ql, qr, x);\n  }\n\n  template <typename F>\n  ll max_right_rec(np c,\
    \ const F &check, ll l, ll r, ll ql, X &x) {\n    if (!c || r <= ql) return R0;\n\
    \    if (check(MX::op(x, c->prod))) {\n      x = MX::op(x, c->prod);\n      return\
    \ R0;\n    }\n    ll m = (l + r) / 2;\n    ll k = max_right_rec(c->l, check, l,\
    \ m, ql, x);\n    if (k != R0) return k;\n    if (ql <= (c->idx)) {\n      x =\
    \ MX::op(x, c->x);\n      if (!check(x)) return c->idx;\n    }\n    return max_right_rec(c->r,\
    \ check, m, r, ql, x);\n  }\n\n  template <typename F>\n  ll min_left_rec(np c,\
    \ const F &check, ll l, ll r, ll qr, X &x) {\n    if (!c || qr <= l) return L0;\n\
    \    if (check(MX::op(c->prod, x))) {\n      x = MX::op(c->prod, x);\n      return\
    \ L0;\n    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check, m,\
    \ r, qr, x);\n    if (k != L0) return k;\n    if (c->idx < qr) {\n      x = MX::op(c->x,\
    \ x);\n      if (!check(x)) return c->idx + 1;\n    }\n    return min_left_rec(c->l,\
    \ check, l, m, qr, x);\n  }\n};\n"
  code: "#pragma once\n\n// \u5E38\u306B\u307B\u3068\u3093\u3069\u306E\u8981\u7D20\
    \u304C unit \u3067\u3042\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\u308C\u308B\
    \u3088\u3046\u306A\u52D5\u7684\u30BB\u30B0\u6728\n// \u3057\u305F\u304C\u3063\u3066\
    \u3001default_prod \u306E\u985E\u306F\u6301\u305F\u305B\u3089\u308C\u305A\u3001\
    acted monoid \u3082\u4E00\u822C\u306B\u306F\u6271\u3048\u306A\u3044\n// \u6C38\
    \u7D9A\u5316\u3057\u306A\u3044\u5834\u5408\u306E\u30CE\u30FC\u30C9\u6570\u3092\
    \ O(N) \u306B\u6291\u3048\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u306E\u304C\
    \u5229\u70B9\n// \u5BC6\u306A\u3082\u306E\u3092\u6C38\u7D9A\u5316\u3059\u308B\u3068\
    \u304D\u306F\u304B\u3048\u3063\u3066\u9045\u304F\u306A\u308B\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\ntemplate <typename Monoid, bool PERSISTENT, int NODES>\nstruct\
    \ Dynamic_SegTree_Sparse {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \n  struct Node {\n    ll idx;\n    Node *l, *r;\n    X prod, x;\n  };\n\n  const\
    \ ll L0, R0;\n  Node *pool;\n  int pid;\n  using np = Node *;\n\n  Dynamic_SegTree_Sparse(ll\
    \ L0, ll R0) : L0(L0), R0(R0), pid(0) {\n    pool = new Node[NODES];\n  }\n\n\
    \  np new_root() { return nullptr; }\n\n  np new_node(ll idx, const X x) {\n \
    \   pool[pid].idx = idx;\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x\
    \ = pool[pid].prod = x;\n    return &(pool[pid++]);\n  }\n\n  X prod(np root,\
    \ ll l, ll r) {\n    assert(L0 <= l && l < r && r <= R0);\n    X x = MX::unit();\n\
    \    prod_rec(root, L0, R0, l, r, x);\n    return x;\n  }\n\n  np set(np root,\
    \ ll i, const X &x) {\n    assert(L0 <= i && i < R0);\n    return set_rec(root,\
    \ L0, R0, i, x);\n  }\n\n  np multiply(np root, ll i, const X &x) {\n    assert(L0\
    \ <= i && i < R0);\n    return multiply_rec(root, L0, R0, i, x);\n  }\n\n  template\
    \ <typename F>\n  ll max_right(np root, F check, ll L) {\n    assert(L0 <= L &&\
    \ L <= R0 && check(MX::unit()));\n    X x = MX::unit();\n    return max_right_rec(root,\
    \ check, L0, R0, L, x);\n  }\n\n  template <typename F>\n  ll min_left(np root,\
    \ F check, ll R) {\n    assert(L0 <= R && R <= R0 && check(MX::unit()));\n   \
    \ X x = MX::unit();\n    return min_left_rec(root, check, L0, R0, R, x);\n  }\n\
    \n  void reset() { pid = 0; }\n\n  vc<pair<ll, X>> get_all(np root) {\n    vc<pair<ll,\
    \ X>> res;\n    auto dfs = [&](auto &dfs, np c) -> void {\n      if (!c) return;\n\
    \      dfs(dfs, c->l);\n      res.eb(c->idx, c->x);\n      dfs(dfs, c->r);\n \
    \   };\n    dfs(dfs, root);\n    return res;\n  }\n\n  X get(np root, ll idx)\
    \ {\n    auto dfs = [&](auto &dfs, np c) -> X {\n      if (!c) return Monoid::unit();\n\
    \      if (idx == c->idx) return c->x;\n      if (idx < (c->idx)) return dfs(dfs,\
    \ c->l);\n      return dfs(dfs, c->r);\n    };\n    return dfs(dfs, root);\n \
    \ }\n\nprivate:\n  void update(np c) {\n    c->prod = c->x;\n    if (c->l) c->prod\
    \ = MX::op(c->l->prod, c->prod);\n    if (c->r) c->prod = MX::op(c->prod, c->r->prod);\n\
    \  }\n\n  np copy_node(np c) {\n    if (!c || !PERSISTENT) return c;\n    pool[pid].idx\
    \ = c->idx;\n    pool[pid].l = c->l;\n    pool[pid].r = c->r;\n    pool[pid].x\
    \ = c->x;\n    pool[pid].prod = c->prod;\n    return &(pool[pid++]);\n  }\n\n\
    \  np set_rec(np c, ll l, ll r, ll i, X x) {\n    if (!c) {\n      c = new_node(i,\
    \ x);\n      return c;\n    }\n    c = copy_node(c);\n    if (c->idx == i) {\n\
    \      c->x = x;\n      update(c);\n      return c;\n    }\n    ll m = (l + r)\
    \ / 2;\n    if (i < m) {\n      if (c->idx < i) swap(c->idx, i), swap(c->x, x);\n\
    \      c->l = set_rec(c->l, l, m, i, x);\n    }\n    if (m <= i) {\n      if (i\
    \ < c->idx) swap(c->idx, i), swap(c->x, x);\n      c->r = set_rec(c->r, m, r,\
    \ i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  np multiply_rec(np c,\
    \ ll l, ll r, ll i, X x) {\n    if (!c) {\n      c = new_node(i, x);\n      return\
    \ c;\n    }\n    c = copy_node(c);\n    if (c->idx == i) {\n      c->x = MX::op(c->x,\
    \ x);\n      update(c);\n      return c;\n    }\n    ll m = (l + r) / 2;\n   \
    \ if (i < m) {\n      if (c->idx < i) swap(c->idx, i), swap(c->x, x);\n      c->l\
    \ = multiply_rec(c->l, l, m, i, x);\n    }\n    if (m <= i) {\n      if (i < c->idx)\
    \ swap(c->idx, i), swap(c->x, x);\n      c->r = multiply_rec(c->r, m, r, i, x);\n\
    \    }\n    update(c);\n    return c;\n  }\n\n  void prod_rec(np c, ll l, ll r,\
    \ ll ql, ll qr, X &x) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr\
    \ || !c) return;\n    if (l == ql && r == qr) {\n      x = MX::op(x, c->prod);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    prod_rec(c->l, l, m, ql, qr,\
    \ x);\n    if (ql <= (c->idx) && (c->idx) < qr) x = MX::op(x, c->x);\n    prod_rec(c->r,\
    \ m, r, ql, qr, x);\n  }\n\n  template <typename F>\n  ll max_right_rec(np c,\
    \ const F &check, ll l, ll r, ll ql, X &x) {\n    if (!c || r <= ql) return R0;\n\
    \    if (check(MX::op(x, c->prod))) {\n      x = MX::op(x, c->prod);\n      return\
    \ R0;\n    }\n    ll m = (l + r) / 2;\n    ll k = max_right_rec(c->l, check, l,\
    \ m, ql, x);\n    if (k != R0) return k;\n    if (ql <= (c->idx)) {\n      x =\
    \ MX::op(x, c->x);\n      if (!check(x)) return c->idx;\n    }\n    return max_right_rec(c->r,\
    \ check, m, r, ql, x);\n  }\n\n  template <typename F>\n  ll min_left_rec(np c,\
    \ const F &check, ll l, ll r, ll qr, X &x) {\n    if (!c || qr <= l) return L0;\n\
    \    if (check(MX::op(c->prod, x))) {\n      x = MX::op(c->prod, x);\n      return\
    \ L0;\n    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check, m,\
    \ r, qr, x);\n    if (k != L0) return k;\n    if (c->idx < qr) {\n      x = MX::op(c->x,\
    \ x);\n      if (!check(x)) return c->idx + 1;\n    }\n    return min_left_rec(c->l,\
    \ check, l, m, qr, x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dynamic_segtree_sparse.hpp
  requiredBy: []
  timestamp: '2022-12-25 11:16:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1649_2.test.cpp
  - test/yukicoder/1826_2.test.cpp
  - test/yukicoder/789_3.test.cpp
  - test/mytest/dynamic_segtree_sparse.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_pseg_sp.test.cpp
  - test/library_checker/datastructure/double_ended_pq_2.test.cpp
documentation_of: ds/segtree/dynamic_segtree_sparse.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_segtree_sparse.hpp
- /library/ds/segtree/dynamic_segtree_sparse.hpp.html
title: ds/segtree/dynamic_segtree_sparse.hpp
---
