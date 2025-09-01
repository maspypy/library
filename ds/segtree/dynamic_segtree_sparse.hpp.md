---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/my_multiset.hpp
    title: ds/my_multiset.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/range_add_range_max.hpp
    title: ds/segtree/range_add_range_max.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/dynamic_segtree_sparse.test.cpp
    title: test/1_mytest/dynamic_segtree_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_add_range_max.test.cpp
    title: test/1_mytest/range_add_range_max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/double_ended_pq_2.test.cpp
    title: test/2_library_checker/data_structure/double_ended_pq_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_kth_smallest_pseg_sp.test.cpp
    title: test/2_library_checker/data_structure/range_kth_smallest_pseg_sp.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1649_2.test.cpp
    title: test/3_yukicoder/1649_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1826_2.test.cpp
    title: test/3_yukicoder/1826_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2242.test.cpp
    title: test/3_yukicoder/2242.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2627.test.cpp
    title: test/3_yukicoder/2627.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/789_3.test.cpp
    title: test/3_yukicoder/789_3.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/671/D
  bundledCode: "#line 1 \"ds/segtree/dynamic_segtree_sparse.hpp\"\n\n// \u5E38\u306B\
    \u307B\u3068\u3093\u3069\u306E\u8981\u7D20\u304C unit \u3067\u3042\u308B\u3053\
    \u3068\u304C\u4FDD\u8A3C\u3055\u308C\u308B\u3088\u3046\u306A\u52D5\u7684\u30BB\
    \u30B0\u6728\n// \u3057\u305F\u304C\u3063\u3066\u3001default_prod \u306E\u985E\
    \u306F\u6301\u305F\u305B\u3089\u308C\u305A\u3001acted monoid \u3082\u4E00\u822C\
    \u306B\u306F\u6271\u3048\u306A\u3044\n// \u8FFD\u52A0 N \u56DE\u306E\u3068\u304D\
    \u30CE\u30FC\u30C9\u6570 N \u4EE5\u4E0B\u304C\u4FDD\u8A3C\u3055\u308C\u308B\n\
    template <typename Monoid, bool PERSISTENT>\nstruct Dynamic_SegTree_Sparse {\n\
    \  using MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node {\n\
    \    int ch[2];\n    ll idx;\n    X prod, x;\n  };\n  const ll L0, R0;\n  static\
    \ constexpr int NIL = 0;\n  vc<Node> node;\n  vc<int> FREE;\n\n  Dynamic_SegTree_Sparse(ll\
    \ L0, ll R0) : L0(L0), R0(R0) { reset(); }\n  void reserve(int n) { node.reserve(n\
    \ + 1); }\n  void reset() {\n    node.clear(), FREE.clear();\n    node.eb(Node{{NIL,\
    \ NIL}, 0, MX::unit(), MX::unit()});  // NIL\n  }\n\n  // \u6728 dp \u306E\u30DE\
    \u30FC\u30B8\u306E\u3068\u304D\u306A\u3069\u306B\u4F7F\u7528\u3059\u308B\u3068\
    \ MLE \u56DE\u907F\u3067\u304D\u308B\u3053\u3068\u304C\u3042\u308B\n  // https://codeforces.com/problemset/problem/671/D\n\
    \  void free_subtree(int c) {\n    assert(c != NIL);\n    auto dfs = [&](auto\
    \ &dfs, int c) -> void {\n      if (c == NIL) return;\n      dfs(dfs, node[c].ch[0]),\
    \ dfs(dfs, node[c].ch[1]);\n      FREE.eb(c);\n    };\n    dfs(dfs, c);\n  }\n\
    \n  inline int new_root() { return NIL; }\n\n  inline int new_node(ll idx, const\
    \ X x) {\n    if (!FREE.empty()) {\n      int id = POP(FREE);\n      node[id].ch[0]\
    \ = node[id].ch[1] = NIL;\n      node[id].idx = idx, node[id].x = x, node[id].prod\
    \ = x;\n      return id;\n    }\n    node.eb(Node{{NIL, NIL}, idx, x, x});\n \
    \   return int(node.size()) - 1;\n  }\n  inline Node operator[](int i) const {\
    \ return node[i]; }\n\n  X prod(int root, ll l, ll r) {\n    assert(L0 <= l &&\
    \ l <= r && r <= R0);\n    if (root == NIL || l == r) return MX::unit();\n   \
    \ X x = MX::unit();\n    prod_rec(root, L0, R0, l, r, x);\n    return x;\n  }\n\
    \n  X prod_all(int root) { return (root == NIL ? MX::unit() : node[root].prod);\
    \ }\n\n  int set(int root, ll i, const X &x) {\n    assert(L0 <= i && i < R0);\n\
    \    return set_rec(root, L0, R0, i, x);\n  }\n\n  int multiply(int root, ll i,\
    \ const X &x) {\n    assert(L0 <= i && i < R0);\n    return multiply_rec(root,\
    \ L0, R0, i, x);\n  }\n\n  template <typename F>\n  ll max_right(int root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return max_right_rec(root, check, L0, R0, L, x);\n  }\n\n  template <typename\
    \ F>\n  ll min_left(int root, F check, ll R) {\n    assert(L0 <= R && R <= R0\
    \ && check(MX::unit()));\n    X x = MX::unit();\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\n  }\n\n  vc<pair<ll, X>> get_all(int root) {\n    vc<pair<ll,\
    \ X>> res;\n    auto dfs = [&](auto &dfs, int c) -> void {\n      if (c == NIL)\
    \ return;\n      dfs(dfs, node[c].ch[0]);\n      res.eb(node[c].idx, node[c].x);\n\
    \      dfs(dfs, node[c].ch[1]);\n    };\n    dfs(dfs, root);\n    return res;\n\
    \  }\n\n  X get(int root, ll idx) {\n    auto dfs = [&](auto &dfs, int c) -> X\
    \ {\n      if (c == NIL) return MX::unit();\n      if (idx == node[c].idx) return\
    \ node[c].x;\n      return dfs(dfs, node[c].ch[idx > node[c].idx]);\n    };\n\
    \    return dfs(dfs, root);\n  }\n\n private:\n  inline void update(int c) {\n\
    \    node[c].prod = node[c].x;\n    node[c].prod = MX::op(node[node[c].ch[0]].prod,\
    \ node[c].prod);\n    node[c].prod = MX::op(node[c].prod, node[node[c].ch[1]].prod);\n\
    \  }\n\n  inline int copy_node(int c) {\n    if constexpr (!PERSISTENT)\n    \
    \  return c;\n    else {\n      if (c == NIL) return c;\n      node.eb(node[c]);\n\
    \      return int(node.size()) - 1;\n    }\n  }\n\n  int set_rec(int c, ll l,\
    \ ll r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c = copy_node(c);\n\
    \    if (node[c].idx == i) {\n      node[c].x = x;\n      update(c);\n      return\
    \ c;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) {\n      if (node[c].idx\
    \ < i) swap(node[c].idx, i), swap(node[c].x, x);\n      node[c].ch[0] = set_rec(node[c].ch[0],\
    \ l, m, i, x);\n    }\n    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx,\
    \ i), swap(node[c].x, x);\n      node[c].ch[1] = set_rec(node[c].ch[1], m, r,\
    \ i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  int multiply_rec(int\
    \ c, ll l, ll r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c\
    \ = copy_node(c);\n    if (node[c].idx == i) {\n      node[c].x = MX::op(node[c].x,\
    \ x);\n      update(c);\n      return c;\n    }\n    ll m = (l + r) / 2;\n   \
    \ if (i < m) {\n      if (node[c].idx < i) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[0] = multiply_rec(node[c].ch[0], l, m, i, x);\n    }\n\
    \    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[1] = multiply_rec(node[c].ch[1], m, r, i, x);\n    }\n\
    \    update(c);\n    return c;\n  }\n\n  void prod_rec(int c, ll l, ll r, ll ql,\
    \ ll qr, X &x) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr || c\
    \ == NIL) return;\n    if (l == ql && r == qr) {\n      x = MX::op(x, node[c].prod);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    prod_rec(node[c].ch[0], l,\
    \ m, ql, qr, x);\n    if (ql <= (node[c].idx) && (node[c].idx) < qr) x = MX::op(x,\
    \ node[c].x);\n    prod_rec(node[c].ch[1], m, r, ql, qr, x);\n  }\n\n  template\
    \ <typename F>\n  ll max_right_rec(int c, const F &check, ll l, ll r, ll ql, X\
    \ &x) {\n    if (c == NIL || r <= ql) return R0;\n    if (check(MX::op(x, node[c].prod)))\
    \ {\n      x = MX::op(x, node[c].prod);\n      return R0;\n    }\n    ll m = (l\
    \ + r) / 2;\n    ll k = max_right_rec(node[c].ch[0], check, l, m, ql, x);\n  \
    \  if (k != R0) return k;\n    if (ql <= node[c].idx) {\n      x = MX::op(x, node[c].x);\n\
    \      if (!check(x)) return node[c].idx;\n    }\n    return max_right_rec(node[c].ch[1],\
    \ check, m, r, ql, x);\n  }\n\n  template <typename F>\n  ll min_left_rec(int\
    \ c, const F &check, ll l, ll r, ll qr, X &x) {\n    if (c == NIL || qr <= l)\
    \ return L0;\n    if (check(MX::op(node[c].prod, x))) {\n      x = MX::op(node[c].prod,\
    \ x);\n      return L0;\n    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(node[c].ch[1],\
    \ check, m, r, qr, x);\n    if (k != L0) return k;\n    if (node[c].idx < qr)\
    \ {\n      x = MX::op(node[c].x, x);\n      if (!check(x)) return node[c].idx\
    \ + 1;\n    }\n    return min_left_rec(node[c].ch[0], check, l, m, qr, x);\n \
    \ }\n};\n"
  code: "\n// \u5E38\u306B\u307B\u3068\u3093\u3069\u306E\u8981\u7D20\u304C unit \u3067\
    \u3042\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\u308C\u308B\u3088\u3046\u306A\
    \u52D5\u7684\u30BB\u30B0\u6728\n// \u3057\u305F\u304C\u3063\u3066\u3001default_prod\
    \ \u306E\u985E\u306F\u6301\u305F\u305B\u3089\u308C\u305A\u3001acted monoid \u3082\
    \u4E00\u822C\u306B\u306F\u6271\u3048\u306A\u3044\n// \u8FFD\u52A0 N \u56DE\u306E\
    \u3068\u304D\u30CE\u30FC\u30C9\u6570 N \u4EE5\u4E0B\u304C\u4FDD\u8A3C\u3055\u308C\
    \u308B\ntemplate <typename Monoid, bool PERSISTENT>\nstruct Dynamic_SegTree_Sparse\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node\
    \ {\n    int ch[2];\n    ll idx;\n    X prod, x;\n  };\n  const ll L0, R0;\n \
    \ static constexpr int NIL = 0;\n  vc<Node> node;\n  vc<int> FREE;\n\n  Dynamic_SegTree_Sparse(ll\
    \ L0, ll R0) : L0(L0), R0(R0) { reset(); }\n  void reserve(int n) { node.reserve(n\
    \ + 1); }\n  void reset() {\n    node.clear(), FREE.clear();\n    node.eb(Node{{NIL,\
    \ NIL}, 0, MX::unit(), MX::unit()});  // NIL\n  }\n\n  // \u6728 dp \u306E\u30DE\
    \u30FC\u30B8\u306E\u3068\u304D\u306A\u3069\u306B\u4F7F\u7528\u3059\u308B\u3068\
    \ MLE \u56DE\u907F\u3067\u304D\u308B\u3053\u3068\u304C\u3042\u308B\n  // https://codeforces.com/problemset/problem/671/D\n\
    \  void free_subtree(int c) {\n    assert(c != NIL);\n    auto dfs = [&](auto\
    \ &dfs, int c) -> void {\n      if (c == NIL) return;\n      dfs(dfs, node[c].ch[0]),\
    \ dfs(dfs, node[c].ch[1]);\n      FREE.eb(c);\n    };\n    dfs(dfs, c);\n  }\n\
    \n  inline int new_root() { return NIL; }\n\n  inline int new_node(ll idx, const\
    \ X x) {\n    if (!FREE.empty()) {\n      int id = POP(FREE);\n      node[id].ch[0]\
    \ = node[id].ch[1] = NIL;\n      node[id].idx = idx, node[id].x = x, node[id].prod\
    \ = x;\n      return id;\n    }\n    node.eb(Node{{NIL, NIL}, idx, x, x});\n \
    \   return int(node.size()) - 1;\n  }\n  inline Node operator[](int i) const {\
    \ return node[i]; }\n\n  X prod(int root, ll l, ll r) {\n    assert(L0 <= l &&\
    \ l <= r && r <= R0);\n    if (root == NIL || l == r) return MX::unit();\n   \
    \ X x = MX::unit();\n    prod_rec(root, L0, R0, l, r, x);\n    return x;\n  }\n\
    \n  X prod_all(int root) { return (root == NIL ? MX::unit() : node[root].prod);\
    \ }\n\n  int set(int root, ll i, const X &x) {\n    assert(L0 <= i && i < R0);\n\
    \    return set_rec(root, L0, R0, i, x);\n  }\n\n  int multiply(int root, ll i,\
    \ const X &x) {\n    assert(L0 <= i && i < R0);\n    return multiply_rec(root,\
    \ L0, R0, i, x);\n  }\n\n  template <typename F>\n  ll max_right(int root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return max_right_rec(root, check, L0, R0, L, x);\n  }\n\n  template <typename\
    \ F>\n  ll min_left(int root, F check, ll R) {\n    assert(L0 <= R && R <= R0\
    \ && check(MX::unit()));\n    X x = MX::unit();\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\n  }\n\n  vc<pair<ll, X>> get_all(int root) {\n    vc<pair<ll,\
    \ X>> res;\n    auto dfs = [&](auto &dfs, int c) -> void {\n      if (c == NIL)\
    \ return;\n      dfs(dfs, node[c].ch[0]);\n      res.eb(node[c].idx, node[c].x);\n\
    \      dfs(dfs, node[c].ch[1]);\n    };\n    dfs(dfs, root);\n    return res;\n\
    \  }\n\n  X get(int root, ll idx) {\n    auto dfs = [&](auto &dfs, int c) -> X\
    \ {\n      if (c == NIL) return MX::unit();\n      if (idx == node[c].idx) return\
    \ node[c].x;\n      return dfs(dfs, node[c].ch[idx > node[c].idx]);\n    };\n\
    \    return dfs(dfs, root);\n  }\n\n private:\n  inline void update(int c) {\n\
    \    node[c].prod = node[c].x;\n    node[c].prod = MX::op(node[node[c].ch[0]].prod,\
    \ node[c].prod);\n    node[c].prod = MX::op(node[c].prod, node[node[c].ch[1]].prod);\n\
    \  }\n\n  inline int copy_node(int c) {\n    if constexpr (!PERSISTENT)\n    \
    \  return c;\n    else {\n      if (c == NIL) return c;\n      node.eb(node[c]);\n\
    \      return int(node.size()) - 1;\n    }\n  }\n\n  int set_rec(int c, ll l,\
    \ ll r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c = copy_node(c);\n\
    \    if (node[c].idx == i) {\n      node[c].x = x;\n      update(c);\n      return\
    \ c;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) {\n      if (node[c].idx\
    \ < i) swap(node[c].idx, i), swap(node[c].x, x);\n      node[c].ch[0] = set_rec(node[c].ch[0],\
    \ l, m, i, x);\n    }\n    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx,\
    \ i), swap(node[c].x, x);\n      node[c].ch[1] = set_rec(node[c].ch[1], m, r,\
    \ i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  int multiply_rec(int\
    \ c, ll l, ll r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c\
    \ = copy_node(c);\n    if (node[c].idx == i) {\n      node[c].x = MX::op(node[c].x,\
    \ x);\n      update(c);\n      return c;\n    }\n    ll m = (l + r) / 2;\n   \
    \ if (i < m) {\n      if (node[c].idx < i) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[0] = multiply_rec(node[c].ch[0], l, m, i, x);\n    }\n\
    \    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[1] = multiply_rec(node[c].ch[1], m, r, i, x);\n    }\n\
    \    update(c);\n    return c;\n  }\n\n  void prod_rec(int c, ll l, ll r, ll ql,\
    \ ll qr, X &x) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr || c\
    \ == NIL) return;\n    if (l == ql && r == qr) {\n      x = MX::op(x, node[c].prod);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    prod_rec(node[c].ch[0], l,\
    \ m, ql, qr, x);\n    if (ql <= (node[c].idx) && (node[c].idx) < qr) x = MX::op(x,\
    \ node[c].x);\n    prod_rec(node[c].ch[1], m, r, ql, qr, x);\n  }\n\n  template\
    \ <typename F>\n  ll max_right_rec(int c, const F &check, ll l, ll r, ll ql, X\
    \ &x) {\n    if (c == NIL || r <= ql) return R0;\n    if (check(MX::op(x, node[c].prod)))\
    \ {\n      x = MX::op(x, node[c].prod);\n      return R0;\n    }\n    ll m = (l\
    \ + r) / 2;\n    ll k = max_right_rec(node[c].ch[0], check, l, m, ql, x);\n  \
    \  if (k != R0) return k;\n    if (ql <= node[c].idx) {\n      x = MX::op(x, node[c].x);\n\
    \      if (!check(x)) return node[c].idx;\n    }\n    return max_right_rec(node[c].ch[1],\
    \ check, m, r, ql, x);\n  }\n\n  template <typename F>\n  ll min_left_rec(int\
    \ c, const F &check, ll l, ll r, ll qr, X &x) {\n    if (c == NIL || qr <= l)\
    \ return L0;\n    if (check(MX::op(node[c].prod, x))) {\n      x = MX::op(node[c].prod,\
    \ x);\n      return L0;\n    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(node[c].ch[1],\
    \ check, m, r, qr, x);\n    if (k != L0) return k;\n    if (node[c].idx < qr)\
    \ {\n      x = MX::op(node[c].x, x);\n      if (!check(x)) return node[c].idx\
    \ + 1;\n    }\n    return min_left_rec(node[c].ch[0], check, l, m, qr, x);\n \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dynamic_segtree_sparse.hpp
  requiredBy:
  - ds/segtree/range_add_range_max.hpp
  - ds/my_multiset.hpp
  timestamp: '2025-09-02 00:55:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/789_3.test.cpp
  - test/3_yukicoder/1649_2.test.cpp
  - test/3_yukicoder/2627.test.cpp
  - test/3_yukicoder/1826_2.test.cpp
  - test/3_yukicoder/2242.test.cpp
  - test/2_library_checker/data_structure/double_ended_pq_2.test.cpp
  - test/2_library_checker/data_structure/range_kth_smallest_pseg_sp.test.cpp
  - test/1_mytest/range_add_range_max.test.cpp
  - test/1_mytest/dynamic_segtree_sparse.test.cpp
documentation_of: ds/segtree/dynamic_segtree_sparse.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_segtree_sparse.hpp
- /library/ds/segtree/dynamic_segtree_sparse.hpp.html
title: ds/segtree/dynamic_segtree_sparse.hpp
---
