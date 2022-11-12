---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group/add.hpp
    title: alg/group/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/pds/segtree.hpp
    title: ds/pds/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/703/problem/D
  bundledCode: "#line 2 \"alg/group/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Group_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"ds/pds/segtree.hpp\"\
    \ntemplate <typename Monoid, int NODES>\nstruct Persistent_SegTree {\n  using\
    \ X = typename Monoid::value_type;\n\n  struct Node {\n    Node *l, *r;\n    X\
    \ x;\n  };\n\n  using np = Node *;\n\n  const int n;\n  Node *pool;\n  int pid;\n\
    \n  Persistent_SegTree(int n) : n(n), pid(0) { pool = new Node[NODES]; }\n\n \
    \ Node *new_node(const X x = Monoid::unit()) {\n    pool[pid].l = pool[pid].r\
    \ = nullptr;\n    pool[pid].x = x;\n    return &(pool[pid++]);\n  }\n\n  Node\
    \ *new_node(const vc<X> &dat) {\n    assert(len(dat) == n);\n    auto dfs = [&](auto\
    \ &dfs, int l, int r) -> Node * {\n      if (l == r) return nullptr;\n      if\
    \ (r == l + 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n      Node\
    \ *l_root = dfs(dfs, l, m);\n      Node *r_root = dfs(dfs, m, r);\n      X x =\
    \ Monoid::op(l_root->x, r_root->x);\n      Node *root = new_node(x);\n      root->l\
    \ = l_root, root->r = r_root;\n      return root;\n    };\n    return dfs(dfs,\
    \ 0, len(dat));\n  }\n\n  X prod(Node *root, int l, int r) {\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    X x = Monoid::unit();\n    prod_rec(root, 0, n,\
    \ l, r, x);\n    return x;\n  }\n\n  Node *set(Node *root, int i, const X &x)\
    \ {\n    assert(0 <= i && i < n);\n    return set_rec(root, 0, n, i, x);\n  }\n\
    \n  vc<X> restore(Node *root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs,\
    \ Node *c, int node_l, int node_r) -> void {\n      if (node_r - node_l == 1)\
    \ {\n        res.eb(c->x);\n        return;\n      }\n      int node_m = (node_l\
    \ + node_r) / 2;\n      prop(c);\n      dfs(dfs, c->l, node_l, node_m);\n    \
    \  dfs(dfs, c->r, node_m, node_r);\n    };\n    dfs(dfs, root, 0, n);\n    return\
    \ res;\n  }\n\n  void reset() { pid = 0; }\n\nprivate:\n  Node *copy_node(Node\
    \ *n) {\n    if (!n) return nullptr;\n    pool[pid].l = n->l;\n    pool[pid].r\
    \ = n->r;\n    pool[pid].x = n->x;\n    return &(pool[pid++]);\n  }\n\n  Node\
    \ *set_rec(Node *c, int node_l, int node_r, int i, const X &x) {\n    if (node_r\
    \ == node_l + 1) { return new_node(x); }\n    if(!c) c = new_node();\n    int\
    \ node_m = (node_l + node_r) / 2;\n    c = copy_node(c);\n    if (i < node_m)\
    \ {\n      c->l = set_rec(c->l, node_l, node_m, i, x);\n    } else {\n      c->r\
    \ = set_rec(c->r, node_m, node_r, i, x);\n    }\n    X xl = (c->l ? c->l->x :\
    \ Monoid::unit());\n    X xr = (c->r ? c->r->x : Monoid::unit());\n    c->x =\
    \ Monoid::op(xl, xr);\n    return c;\n  }\n\n  void prod_rec(Node *c, int node_l,\
    \ int node_r, int l, int r, X &x) {\n    if(!c) return;\n    chmax(l, node_l);\n\
    \    chmin(r, node_r);\n    if (l >= r) return;\n    if (l == node_l && r == node_r)\
    \ {\n      x = Monoid::op(x, c->x);\n      return;\n    }\n    int node_m = (node_l\
    \ + node_r) / 2;\n    prod_rec(c->l, node_l, node_m, l, r, x);\n    prod_rec(c->r,\
    \ node_m, node_r, l, r, x);\n  }\n};\n#line 3 \"ds/online_uniqueproductquery.hpp\"\
    \n\r\n// sample\uFF1Ahttps://codeforces.com/contest/703/problem/D\r\n// key =\
    \ long long\r\n// [L, R) \u5185\u306E\u8981\u7D20 (long long) \u3092 UNIQUE \u3057\
    \u305F\u4E0A\u3067\u3001\r\n// f(k),\u306E\u7DCF\u7A4D\u3092\u3068\u3063\u305F\
    \u3082\u306E\u3092\u8A08\u7B97\u3002 f: key -> Monoid value\r\n// Online \u5316\
    \u3057\u305F\u3082\u306E\u306E\u3001\u30E1\u30E2\u30EA\u5B9A\u6570\u500D\u304C\
    \u91CD\u3044\r\ntemplate <typename Monoid = Group_Add<int>, int NODES = 1000000>\r\
    \nstruct OnlineUniqueProductQuery {\r\n  using X = typename Monoid::value_type;\r\
    \n  int N;\r\n  vc<ll> key;\r\n  vc<pair<int, int>> query;\r\n  vc<int> times;\r\
    \n  Persistent_SegTree<Monoid, NODES> seg;\r\n\r\n  template <typename F>\r\n\
    \  OnlineUniqueProductQuery(vc<ll>& key, F f) : N(len(key)), key(key), seg(N)\
    \ {\r\n    times.eb(seg.time());\r\n    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\
    \n    FOR(i, N) {\r\n      ll x = key[i];\r\n      int t = seg.time();\r\n   \
    \   if (pos.count(x)) { t = seg.set(t, pos[x], Monoid::unit); }\r\n      pos[x]\
    \ = i;\r\n      t = seg.set(t, i, f(key[i]));\r\n      times.eb(t);\r\n    }\r\
    \n  }\r\n\r\n  X prod(int L, int R) {\r\n    int t = times[R];\r\n    return seg.prod(t,\
    \ L, R);\r\n  }\r\n};\r\n"
  code: "#include \"alg/group/add.hpp\"\r\n#include \"pds/segtree.hpp\"\r\n\r\n//\
    \ sample\uFF1Ahttps://codeforces.com/contest/703/problem/D\r\n// key = long long\r\
    \n// [L, R) \u5185\u306E\u8981\u7D20 (long long) \u3092 UNIQUE \u3057\u305F\u4E0A\
    \u3067\u3001\r\n// f(k),\u306E\u7DCF\u7A4D\u3092\u3068\u3063\u305F\u3082\u306E\
    \u3092\u8A08\u7B97\u3002 f: key -> Monoid value\r\n// Online \u5316\u3057\u305F\
    \u3082\u306E\u306E\u3001\u30E1\u30E2\u30EA\u5B9A\u6570\u500D\u304C\u91CD\u3044\
    \r\ntemplate <typename Monoid = Group_Add<int>, int NODES = 1000000>\r\nstruct\
    \ OnlineUniqueProductQuery {\r\n  using X = typename Monoid::value_type;\r\n \
    \ int N;\r\n  vc<ll> key;\r\n  vc<pair<int, int>> query;\r\n  vc<int> times;\r\
    \n  Persistent_SegTree<Monoid, NODES> seg;\r\n\r\n  template <typename F>\r\n\
    \  OnlineUniqueProductQuery(vc<ll>& key, F f) : N(len(key)), key(key), seg(N)\
    \ {\r\n    times.eb(seg.time());\r\n    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\
    \n    FOR(i, N) {\r\n      ll x = key[i];\r\n      int t = seg.time();\r\n   \
    \   if (pos.count(x)) { t = seg.set(t, pos[x], Monoid::unit); }\r\n      pos[x]\
    \ = i;\r\n      t = seg.set(t, i, f(key[i]));\r\n      times.eb(t);\r\n    }\r\
    \n  }\r\n\r\n  X prod(int L, int R) {\r\n    int t = times[R];\r\n    return seg.prod(t,\
    \ L, R);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/group/add.hpp
  - ds/pds/segtree.hpp
  isVerificationFile: false
  path: ds/online_uniqueproductquery.hpp
  requiredBy: []
  timestamp: '2022-10-24 13:59:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/online_uniqueproductquery.hpp
layout: document
redirect_from:
- /library/ds/online_uniqueproductquery.hpp
- /library/ds/online_uniqueproductquery.hpp.html
title: ds/online_uniqueproductquery.hpp
---
