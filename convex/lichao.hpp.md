---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/lichao.hpp\"\n\n#line 2 \"alg/monoid/min_idx.hpp\"\
    \n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct Monoid_Min_Idx\
    \ {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static\
    \ constexpr bool is_small(const X& x, const X& y) {\r\n    if (x.fi < y.fi) return\
    \ true;\r\n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left ? (x.se\
    \ < y.se) : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return (is_small(x,\
    \ y) ? x : y); }\r\n  static constexpr X unit() { return {infty<T>, -1}; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 3 \"convex/lichao.hpp\"\
    \n\n// \u95A2\u6570\u306F (long long) -> T\n// evaluate \u3092\u66F8\u304D\u5909\
    \u3048\u308B\u3068\u3001totally monotone \u306A\u95A2\u6570\u7FA4\u306B\u3082\u4F7F\
    \u3048\u308B\ntemplate <typename T, bool PERSISTENT, int NODES>\nstruct Persistent_Dynamic_LiChaoTree\
    \ {\n  using FUNC = pair<T, T>;\n  vc<FUNC> funcs;\n\n  static inline T evaluate(int\
    \ i, ll x) {\n    auto [a, b] = funcs[i];\n    return a * x + b;\n  }\n\n  struct\
    \ Node {\n    int fid;\n    Node *l, *r;\n  };\n\n  Node *pool;\n  int pid;\n\
    \  ll L, R;\n\n  using np = Node *;\n\n  Persistent_Dynamic_LiChaoTree(ll L, ll\
    \ R) : pid(0), L(L), R(R) {\n    pool = new Node[NODES];\n  }\n\n  Node *new_node()\
    \ {\n    pool[pid].fid = -1;\n    pool[pid].l = nullptr;\n    pool[pid].r = nullptr;\n\
    \    return &(pool[pid++]);\n  }\n\n  np add_segment(np root, ll xl, ll xr, FUNC\
    \ f) {\n    if (a != 0) {\n      ll xlim = (infty<T> - abs(b)) / abs(a);\n   \
    \   assert(abs(xl) < xlim);\n      assert(abs(xr) < xlim);\n    }\n    assert(L\
    \ <= xl && xl < xr && xr <= R);\n    Line f(idx, a, b);\n    if (!root) root =\
    \ new_node();\n    return add_segment_rec(root, xl, xr, f, L, R);\n  }\n\n  np\
    \ add_line(np root, T a, T b, int idx = -1) {\n    return add_segment(root, L,\
    \ R, a, b, idx);\n  }\n\n  pair<T, int> query(np root, ll x) {\n    assert(L <=\
    \ x && x < R);\n    if (!root) return Mono::unit();\n    return query_rec(root,\
    \ x, L, R);\n  }\n\nprivate:\n  np copy_node(Node *c) {\n    np nc = new_node();\n\
    \    nc->f = c->f;\n    nc->l = c->l;\n    nc->r = c->r;\n    return nc;\n  }\n\
    \n  np add_segment_rec(Node *c, ll xl, ll xr, const Line &f, ll node_l,\n    \
    \                 ll node_r) {\n    chmax(xl, node_l);\n    chmin(xr, node_r);\n\
    \    if (xl >= xr) return c;\n    if (node_l < xl || xr < node_r) {\n      c =\
    \ copy_node(c);\n      ll node_m = (node_l + node_r) / 2;\n      if (!c->l) c->l\
    \ = new_node();\n      if (!c->r) c->r = new_node();\n      c->l = add_segment_rec(c->l,\
    \ xl, xr, f, node_l, node_m);\n      c->r = add_segment_rec(c->r, xl, xr, f, node_m,\
    \ node_r);\n      return c;\n    }\n    return add_line_rec(c, f, node_l, node_r);\n\
    \  }\n\n  np add_line_rec(Node *c, const Line &f, ll node_l, ll node_r) {\n  \
    \  auto fl = f(node_l), fr = f(node_r - 1);\n    Line g = c->f;\n    auto gl =\
    \ g(node_l), gr = g(node_r - 1);\n    bool bl = Mono::is_small(fl, gl);\n    bool\
    \ br = Mono::is_small(fr, gr);\n    if (bl && br) {\n      c = copy_node(c);\n\
    \      c->f = f;\n      return c;\n    }\n    if (!bl && !br) { return c; }\n\n\
    \    c = copy_node(c);\n    ll node_m = (node_l + node_r) / 2;\n    auto fm =\
    \ f(node_m), gm = g(node_m);\n    bool bm = Mono::is_small(fm, gm);\n    if (bm)\
    \ {\n      c->f = f;\n      if (bl) {\n        if (!c->r) c->r = new_node();\n\
    \        c->r = add_line_rec(c->r, g, node_m, node_r);\n      } else {\n     \
    \   if (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l, g, node_l,\
    \ node_m);\n      }\n    } else {\n      if (!bl) {\n        if (!c->r) c->r =\
    \ new_node();\n        c->r = add_line_rec(c->r, f, node_m, node_r);\n      }\
    \ else {\n        if (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l,\
    \ f, node_l, node_m);\n      }\n    }\n    return c;\n  }\n\n  pair<T, int> query_rec(Node\
    \ *c, ll x, ll node_l, ll node_r) {\n    pair<T, int> res = c->f(x);\n    ll node_m\
    \ = (node_l + node_r) / 2;\n    if (x < node_m && c->l)\n      res = Mono::op(res,\
    \ query_rec(c->l, x, node_l, node_m));\n    if (x >= node_m && c->r)\n      res\
    \ = Mono::op(res, query_rec(c->r, x, node_m, node_r));\n    return res;\n  }\n\
    };\n"
  code: "\n#include \"alg/monoid/min_idx.hpp\"\n\n// \u95A2\u6570\u306F (long long)\
    \ -> T\n// evaluate \u3092\u66F8\u304D\u5909\u3048\u308B\u3068\u3001totally monotone\
    \ \u306A\u95A2\u6570\u7FA4\u306B\u3082\u4F7F\u3048\u308B\ntemplate <typename T,\
    \ bool PERSISTENT, int NODES>\nstruct Persistent_Dynamic_LiChaoTree {\n  using\
    \ FUNC = pair<T, T>;\n  vc<FUNC> funcs;\n\n  static inline T evaluate(int i, ll\
    \ x) {\n    auto [a, b] = funcs[i];\n    return a * x + b;\n  }\n\n  struct Node\
    \ {\n    int fid;\n    Node *l, *r;\n  };\n\n  Node *pool;\n  int pid;\n  ll L,\
    \ R;\n\n  using np = Node *;\n\n  Persistent_Dynamic_LiChaoTree(ll L, ll R) :\
    \ pid(0), L(L), R(R) {\n    pool = new Node[NODES];\n  }\n\n  Node *new_node()\
    \ {\n    pool[pid].fid = -1;\n    pool[pid].l = nullptr;\n    pool[pid].r = nullptr;\n\
    \    return &(pool[pid++]);\n  }\n\n  np add_segment(np root, ll xl, ll xr, FUNC\
    \ f) {\n    if (a != 0) {\n      ll xlim = (infty<T> - abs(b)) / abs(a);\n   \
    \   assert(abs(xl) < xlim);\n      assert(abs(xr) < xlim);\n    }\n    assert(L\
    \ <= xl && xl < xr && xr <= R);\n    Line f(idx, a, b);\n    if (!root) root =\
    \ new_node();\n    return add_segment_rec(root, xl, xr, f, L, R);\n  }\n\n  np\
    \ add_line(np root, T a, T b, int idx = -1) {\n    return add_segment(root, L,\
    \ R, a, b, idx);\n  }\n\n  pair<T, int> query(np root, ll x) {\n    assert(L <=\
    \ x && x < R);\n    if (!root) return Mono::unit();\n    return query_rec(root,\
    \ x, L, R);\n  }\n\nprivate:\n  np copy_node(Node *c) {\n    np nc = new_node();\n\
    \    nc->f = c->f;\n    nc->l = c->l;\n    nc->r = c->r;\n    return nc;\n  }\n\
    \n  np add_segment_rec(Node *c, ll xl, ll xr, const Line &f, ll node_l,\n    \
    \                 ll node_r) {\n    chmax(xl, node_l);\n    chmin(xr, node_r);\n\
    \    if (xl >= xr) return c;\n    if (node_l < xl || xr < node_r) {\n      c =\
    \ copy_node(c);\n      ll node_m = (node_l + node_r) / 2;\n      if (!c->l) c->l\
    \ = new_node();\n      if (!c->r) c->r = new_node();\n      c->l = add_segment_rec(c->l,\
    \ xl, xr, f, node_l, node_m);\n      c->r = add_segment_rec(c->r, xl, xr, f, node_m,\
    \ node_r);\n      return c;\n    }\n    return add_line_rec(c, f, node_l, node_r);\n\
    \  }\n\n  np add_line_rec(Node *c, const Line &f, ll node_l, ll node_r) {\n  \
    \  auto fl = f(node_l), fr = f(node_r - 1);\n    Line g = c->f;\n    auto gl =\
    \ g(node_l), gr = g(node_r - 1);\n    bool bl = Mono::is_small(fl, gl);\n    bool\
    \ br = Mono::is_small(fr, gr);\n    if (bl && br) {\n      c = copy_node(c);\n\
    \      c->f = f;\n      return c;\n    }\n    if (!bl && !br) { return c; }\n\n\
    \    c = copy_node(c);\n    ll node_m = (node_l + node_r) / 2;\n    auto fm =\
    \ f(node_m), gm = g(node_m);\n    bool bm = Mono::is_small(fm, gm);\n    if (bm)\
    \ {\n      c->f = f;\n      if (bl) {\n        if (!c->r) c->r = new_node();\n\
    \        c->r = add_line_rec(c->r, g, node_m, node_r);\n      } else {\n     \
    \   if (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l, g, node_l,\
    \ node_m);\n      }\n    } else {\n      if (!bl) {\n        if (!c->r) c->r =\
    \ new_node();\n        c->r = add_line_rec(c->r, f, node_m, node_r);\n      }\
    \ else {\n        if (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l,\
    \ f, node_l, node_m);\n      }\n    }\n    return c;\n  }\n\n  pair<T, int> query_rec(Node\
    \ *c, ll x, ll node_l, ll node_r) {\n    pair<T, int> res = c->f(x);\n    ll node_m\
    \ = (node_l + node_r) / 2;\n    if (x < node_m && c->l)\n      res = Mono::op(res,\
    \ query_rec(c->l, x, node_l, node_m));\n    if (x >= node_m && c->r)\n      res\
    \ = Mono::op(res, query_rec(c->r, x, node_m, node_r));\n    return res;\n  }\n\
    };"
  dependsOn:
  - alg/monoid/min_idx.hpp
  isVerificationFile: false
  path: convex/lichao.hpp
  requiredBy: []
  timestamp: '2023-02-02 05:07:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/lichao.hpp
layout: document
redirect_from:
- /library/convex/lichao.hpp
- /library/convex/lichao.hpp.html
title: convex/lichao.hpp
---
