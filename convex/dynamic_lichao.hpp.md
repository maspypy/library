---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
    title: test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
    title: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min_idx.hpp\"\n\r\ntemplate <typename T, bool\
    \ tie_is_left = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T,\
    \ int>;\r\n  using X = value_type;\r\n  static constexpr bool is_small(const X&\
    \ x, const X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi)\
    \ return false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\
    \n  }\r\n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static\
    \ constexpr X unit() { return {infty<T>, -1}; }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 2 \"convex/dynamic_lichao.hpp\"\n\n// x \u5EA7\u6A19\u306F\
    \ long long \u306B\u9650\u5B9A\u3057\u3066\u3044\u308B\u3002\n// \u76F4\u7DDA\u306E\
    \u4FC2\u6570 T \u306F double \u3084 i128 \u3082\u53EF\u80FD\u3002\ntemplate <typename\
    \ T, int NODES>\nstruct Dynamic_LiChaoTree {\n  using Mono = Monoid_Min_Idx<T>;\n\
    \  struct Line {\n    int idx;\n    T a, b;\n    Line(int idx, T a, T b) : idx(idx),\
    \ a(a), b(b) {}\n    Line() : Line(-1, 0, infty<T>) {}\n    pair<T, int> operator()(T\
    \ x) const { return {a * x + b, idx}; }\n  };\n\n  struct Node {\n    Line f;\n\
    \    Node *l, *r;\n  };\n\n  Node *pool;\n  int pid;\n  ll L, R;\n  Node *root;\n\
    \n  Dynamic_LiChaoTree(ll L, ll R) : pid(0), L(L), R(R), root(nullptr) {\n   \
    \ pool = new Node[NODES];\n  }\n\n  Node *new_node() {\n    pool[pid].f = Line();\n\
    \    return &(pool[pid++]);\n  }\n\n  void add_segment(ll xl, ll xr, T a, T b,\
    \ int idx = -1) {\n    if (a != 0) {\n      ll xlim = (infty<T> - abs(b)) / abs(a);\n\
    \      assert(abs(xl) < xlim);\n      assert(abs(xr) < xlim);\n    }\n    assert(L\
    \ <= xl && xl < xr && xr <= R);\n    Line f(idx, a, b);\n    if (!root) root =\
    \ new_node();\n    add_segment_rec(root, xl, xr, f, L, R);\n  }\n\n  void add_line(T\
    \ a, T b, int idx = -1) { add_segment(L, R, a, b, idx); }\n\n  pair<T, int> query(ll\
    \ x) {\n    assert(L <= x && x < R);\n    if (!root) return Mono::unit();\n  \
    \  return query_rec(root, x, L, R);\n  }\n\nprivate:\n  void add_segment_rec(Node\
    \ *c, ll xl, ll xr, const Line &f, ll node_l,\n                       ll node_r)\
    \ {\n    chmax(xl, node_l);\n    chmin(xr, node_r);\n    if (xl >= xr) return;\n\
    \    if (node_l < xl || xr < node_r) {\n      ll node_m = (node_l + node_r) /\
    \ 2;\n      if (!c->l) c->l = new_node();\n      if (!c->r) c->r = new_node();\n\
    \      add_segment_rec(c->l, xl, xr, f, node_l, node_m);\n      add_segment_rec(c->r,\
    \ xl, xr, f, node_m, node_r);\n      return;\n    }\n    add_line_rec(c, f, node_l,\
    \ node_r);\n  }\n\n  void add_line_rec(Node *c, const Line &f, ll node_l, ll node_r)\
    \ {\n    auto fl = f(node_l), fr = f(node_r - 1);\n    Line g = c->f;\n    auto\
    \ gl = g(node_l), gr = g(node_r - 1);\n    bool bl = Mono::is_small(fl, gl);\n\
    \    bool br = Mono::is_small(fr, gr);\n    if (bl && br) {\n      c->f = f;\n\
    \      return;\n    }\n    if (!bl && !br) { return; }\n    ll node_m = (node_l\
    \ + node_r) / 2;\n    auto fm = f(node_m), gm = g(node_m);\n    bool bm = Mono::is_small(fm,\
    \ gm);\n    if (bm) {\n      c->f = f;\n      if (bl) {\n        if (!c->r) c->r\
    \ = new_node();\n        add_line_rec(c->r, g, node_m, node_r);\n      } else\
    \ {\n        if (!c->l) c->l = new_node();\n        add_line_rec(c->l, g, node_l,\
    \ node_m);\n      }\n    } else {\n      if (!bl) {\n        if (!c->r) c->r =\
    \ new_node();\n        add_line_rec(c->r, f, node_m, node_r);\n      } else {\n\
    \        if (!c->l) c->l = new_node();\n        add_line_rec(c->l, f, node_l,\
    \ node_m);\n      }\n    }\n  }\n\n  pair<T, int> query_rec(Node *c, ll x, ll\
    \ node_l, ll node_r) {\n    pair<T, int> res = c->f(x);\n    ll node_m = (node_l\
    \ + node_r) / 2;\n    if (x < node_m && c->l)\n      res = Mono::op(res, query_rec(c->l,\
    \ x, node_l, node_m));\n    if (x >= node_m && c->r)\n      res = Mono::op(res,\
    \ query_rec(c->r, x, node_m, node_r));\n    return res;\n  }\n};\n"
  code: "#include \"alg/monoid/min_idx.hpp\"\n\n// x \u5EA7\u6A19\u306F long long\
    \ \u306B\u9650\u5B9A\u3057\u3066\u3044\u308B\u3002\n// \u76F4\u7DDA\u306E\u4FC2\
    \u6570 T \u306F double \u3084 i128 \u3082\u53EF\u80FD\u3002\ntemplate <typename\
    \ T, int NODES>\nstruct Dynamic_LiChaoTree {\n  using Mono = Monoid_Min_Idx<T>;\n\
    \  struct Line {\n    int idx;\n    T a, b;\n    Line(int idx, T a, T b) : idx(idx),\
    \ a(a), b(b) {}\n    Line() : Line(-1, 0, infty<T>) {}\n    pair<T, int> operator()(T\
    \ x) const { return {a * x + b, idx}; }\n  };\n\n  struct Node {\n    Line f;\n\
    \    Node *l, *r;\n  };\n\n  Node *pool;\n  int pid;\n  ll L, R;\n  Node *root;\n\
    \n  Dynamic_LiChaoTree(ll L, ll R) : pid(0), L(L), R(R), root(nullptr) {\n   \
    \ pool = new Node[NODES];\n  }\n\n  Node *new_node() {\n    pool[pid].f = Line();\n\
    \    return &(pool[pid++]);\n  }\n\n  void add_segment(ll xl, ll xr, T a, T b,\
    \ int idx = -1) {\n    if (a != 0) {\n      ll xlim = (infty<T> - abs(b)) / abs(a);\n\
    \      assert(abs(xl) < xlim);\n      assert(abs(xr) < xlim);\n    }\n    assert(L\
    \ <= xl && xl < xr && xr <= R);\n    Line f(idx, a, b);\n    if (!root) root =\
    \ new_node();\n    add_segment_rec(root, xl, xr, f, L, R);\n  }\n\n  void add_line(T\
    \ a, T b, int idx = -1) { add_segment(L, R, a, b, idx); }\n\n  pair<T, int> query(ll\
    \ x) {\n    assert(L <= x && x < R);\n    if (!root) return Mono::unit();\n  \
    \  return query_rec(root, x, L, R);\n  }\n\nprivate:\n  void add_segment_rec(Node\
    \ *c, ll xl, ll xr, const Line &f, ll node_l,\n                       ll node_r)\
    \ {\n    chmax(xl, node_l);\n    chmin(xr, node_r);\n    if (xl >= xr) return;\n\
    \    if (node_l < xl || xr < node_r) {\n      ll node_m = (node_l + node_r) /\
    \ 2;\n      if (!c->l) c->l = new_node();\n      if (!c->r) c->r = new_node();\n\
    \      add_segment_rec(c->l, xl, xr, f, node_l, node_m);\n      add_segment_rec(c->r,\
    \ xl, xr, f, node_m, node_r);\n      return;\n    }\n    add_line_rec(c, f, node_l,\
    \ node_r);\n  }\n\n  void add_line_rec(Node *c, const Line &f, ll node_l, ll node_r)\
    \ {\n    auto fl = f(node_l), fr = f(node_r - 1);\n    Line g = c->f;\n    auto\
    \ gl = g(node_l), gr = g(node_r - 1);\n    bool bl = Mono::is_small(fl, gl);\n\
    \    bool br = Mono::is_small(fr, gr);\n    if (bl && br) {\n      c->f = f;\n\
    \      return;\n    }\n    if (!bl && !br) { return; }\n    ll node_m = (node_l\
    \ + node_r) / 2;\n    auto fm = f(node_m), gm = g(node_m);\n    bool bm = Mono::is_small(fm,\
    \ gm);\n    if (bm) {\n      c->f = f;\n      if (bl) {\n        if (!c->r) c->r\
    \ = new_node();\n        add_line_rec(c->r, g, node_m, node_r);\n      } else\
    \ {\n        if (!c->l) c->l = new_node();\n        add_line_rec(c->l, g, node_l,\
    \ node_m);\n      }\n    } else {\n      if (!bl) {\n        if (!c->r) c->r =\
    \ new_node();\n        add_line_rec(c->r, f, node_m, node_r);\n      } else {\n\
    \        if (!c->l) c->l = new_node();\n        add_line_rec(c->l, f, node_l,\
    \ node_m);\n      }\n    }\n  }\n\n  pair<T, int> query_rec(Node *c, ll x, ll\
    \ node_l, ll node_r) {\n    pair<T, int> res = c->f(x);\n    ll node_m = (node_l\
    \ + node_r) / 2;\n    if (x < node_m && c->l)\n      res = Mono::op(res, query_rec(c->l,\
    \ x, node_l, node_m));\n    if (x >= node_m && c->r)\n      res = Mono::op(res,\
    \ query_rec(c->r, x, node_m, node_r));\n    return res;\n  }\n};"
  dependsOn:
  - alg/monoid/min_idx.hpp
  isVerificationFile: false
  path: convex/dynamic_lichao.hpp
  requiredBy: []
  timestamp: '2023-02-02 01:52:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
  - test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
documentation_of: convex/dynamic_lichao.hpp
layout: document
redirect_from:
- /library/convex/dynamic_lichao.hpp
- /library/convex/dynamic_lichao.hpp.html
title: convex/dynamic_lichao.hpp
---
