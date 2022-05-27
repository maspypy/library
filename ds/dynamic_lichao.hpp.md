---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"ds/dynamic_lichao.hpp\"\n// x \u5EA7\u6A19\u306F long long\
    \ \u306B\u9650\u5B9A\u3057\u3066\u3044\u308B\u3002\n// \u76F4\u7DDA\u306E\u4FC2\
    \u6570 T \u306F double \u3084 i128 \u3082\u53EF\u80FD\u3002\ntemplate <typename\
    \ T, int NODES>\nstruct Dynamic_LiChaoTree {\n  struct Line {\n    T a, b;\n \
    \   Line(T a, T b) : a(a), b(b) {}\n    Line() : Line(0, numeric_limits<T>::max())\
    \ {}\n    T operator()(T x) const { return a * x + b; }\n  };\n\n  struct Node\
    \ {\n    Line f;\n    Node *l, *r;\n  };\n\n  Node *pool;\n  int pid;\n  ll L,\
    \ R;\n  Node *root;\n\n  Dynamic_LiChaoTree(ll L, ll R) : pid(0), L(L), R(R),\
    \ root(nullptr) {\n    pool = new Node[NODES];\n  }\n\n  Node *new_node() {\n\
    \    pool[pid].f = Line();\n    return &(pool[pid++]);\n  }\n\n  void add_segment(ll\
    \ xl, ll xr, T a, T b) {\n    constexpr T INF = numeric_limits<T>::max();\n  \
    \  if (a != 0) {\n      ll xlim = (INF - abs(b)) / abs(a);\n      assert(abs(xl)\
    \ < xlim);\n      assert(abs(xr) < xlim);\n    }\n    assert(L <= xl && xl < xr\
    \ && xr <= R);\n    Line f(a, b);\n    if (!root) root = new_node();\n    add_segment_rec(root,\
    \ xl, xr, f, L, R);\n  }\n\n  void add_line(T a, T b) { add_segment(L, R, a, b);\
    \ }\n\n  T query(ll x) {\n    assert(L <= x && x < R);\n    if (!root) return\
    \ numeric_limits<T>::max();\n    return query_rec(root, x, L, R);\n  }\n\nprivate:\n\
    \  void add_segment_rec(Node *c, ll xl, ll xr, const Line &f, ll node_l,\n   \
    \                    ll node_r) {\n    chmax(xl, node_l);\n    chmin(xr, node_r);\n\
    \    if (xl >= xr) return;\n    if (node_l < xl || xr < node_r) {\n      ll node_m\
    \ = (node_l + node_r) / 2;\n      if (!c->l) c->l = new_node();\n      if (!c->r)\
    \ c->r = new_node();\n      add_segment_rec(c->l, xl, xr, f, node_l, node_m);\n\
    \      add_segment_rec(c->r, xl, xr, f, node_m, node_r);\n      return;\n    }\n\
    \    add_line_rec(c, f, node_l, node_r);\n  }\n\n  void add_line_rec(Node *c,\
    \ const Line &f, ll node_l, ll node_r) {\n    T fl = f(node_l), fr = f(node_r\
    \ - 1);\n    Line g = c->f;\n    T gl = g(node_l), gr = g(node_r - 1);\n    if\
    \ (fl <= gl && fr <= gr) {\n      c->f = f;\n      return;\n    }\n    if (fl\
    \ >= gl && fr >= gr) { return; }\n    ll node_m = (node_l + node_r) / 2;\n   \
    \ T fm = f(node_m), gm = g(node_m);\n    if (fm <= gm) {\n      c->f = f;\n  \
    \    if (fl < gl) {\n        if (!c->r) c->r = new_node();\n        add_line_rec(c->r,\
    \ g, node_m, node_r);\n      } else {\n        if (!c->l) c->l = new_node();\n\
    \        add_line_rec(c->l, g, node_l, node_m);\n      }\n    } else {\n     \
    \ if (gl < fl) {\n        if (!c->r) c->r = new_node();\n        add_line_rec(c->r,\
    \ f, node_m, node_r);\n      } else {\n        if (!c->l) c->l = new_node();\n\
    \        add_line_rec(c->l, f, node_l, node_m);\n      }\n    }\n  }\n\n  T query_rec(Node\
    \ *c, ll x, ll node_l, ll node_r) {\n    T res = c->f(x);\n    ll node_m = (node_l\
    \ + node_r) / 2;\n    if (x < node_m && c->l) chmin(res, query_rec(c->l, x, node_l,\
    \ node_m));\n    if (x >= node_m && c->r) chmin(res, query_rec(c->r, x, node_m,\
    \ node_r));\n    return res;\n  }\n};\n"
  code: "// x \u5EA7\u6A19\u306F long long \u306B\u9650\u5B9A\u3057\u3066\u3044\u308B\
    \u3002\n// \u76F4\u7DDA\u306E\u4FC2\u6570 T \u306F double \u3084 i128 \u3082\u53EF\
    \u80FD\u3002\ntemplate <typename T, int NODES>\nstruct Dynamic_LiChaoTree {\n\
    \  struct Line {\n    T a, b;\n    Line(T a, T b) : a(a), b(b) {}\n    Line()\
    \ : Line(0, numeric_limits<T>::max()) {}\n    T operator()(T x) const { return\
    \ a * x + b; }\n  };\n\n  struct Node {\n    Line f;\n    Node *l, *r;\n  };\n\
    \n  Node *pool;\n  int pid;\n  ll L, R;\n  Node *root;\n\n  Dynamic_LiChaoTree(ll\
    \ L, ll R) : pid(0), L(L), R(R), root(nullptr) {\n    pool = new Node[NODES];\n\
    \  }\n\n  Node *new_node() {\n    pool[pid].f = Line();\n    return &(pool[pid++]);\n\
    \  }\n\n  void add_segment(ll xl, ll xr, T a, T b) {\n    constexpr T INF = numeric_limits<T>::max();\n\
    \    if (a != 0) {\n      ll xlim = (INF - abs(b)) / abs(a);\n      assert(abs(xl)\
    \ < xlim);\n      assert(abs(xr) < xlim);\n    }\n    assert(L <= xl && xl < xr\
    \ && xr <= R);\n    Line f(a, b);\n    if (!root) root = new_node();\n    add_segment_rec(root,\
    \ xl, xr, f, L, R);\n  }\n\n  void add_line(T a, T b) { add_segment(L, R, a, b);\
    \ }\n\n  T query(ll x) {\n    assert(L <= x && x < R);\n    if (!root) return\
    \ numeric_limits<T>::max();\n    return query_rec(root, x, L, R);\n  }\n\nprivate:\n\
    \  void add_segment_rec(Node *c, ll xl, ll xr, const Line &f, ll node_l,\n   \
    \                    ll node_r) {\n    chmax(xl, node_l);\n    chmin(xr, node_r);\n\
    \    if (xl >= xr) return;\n    if (node_l < xl || xr < node_r) {\n      ll node_m\
    \ = (node_l + node_r) / 2;\n      if (!c->l) c->l = new_node();\n      if (!c->r)\
    \ c->r = new_node();\n      add_segment_rec(c->l, xl, xr, f, node_l, node_m);\n\
    \      add_segment_rec(c->r, xl, xr, f, node_m, node_r);\n      return;\n    }\n\
    \    add_line_rec(c, f, node_l, node_r);\n  }\n\n  void add_line_rec(Node *c,\
    \ const Line &f, ll node_l, ll node_r) {\n    T fl = f(node_l), fr = f(node_r\
    \ - 1);\n    Line g = c->f;\n    T gl = g(node_l), gr = g(node_r - 1);\n    if\
    \ (fl <= gl && fr <= gr) {\n      c->f = f;\n      return;\n    }\n    if (fl\
    \ >= gl && fr >= gr) { return; }\n    ll node_m = (node_l + node_r) / 2;\n   \
    \ T fm = f(node_m), gm = g(node_m);\n    if (fm <= gm) {\n      c->f = f;\n  \
    \    if (fl < gl) {\n        if (!c->r) c->r = new_node();\n        add_line_rec(c->r,\
    \ g, node_m, node_r);\n      } else {\n        if (!c->l) c->l = new_node();\n\
    \        add_line_rec(c->l, g, node_l, node_m);\n      }\n    } else {\n     \
    \ if (gl < fl) {\n        if (!c->r) c->r = new_node();\n        add_line_rec(c->r,\
    \ f, node_m, node_r);\n      } else {\n        if (!c->l) c->l = new_node();\n\
    \        add_line_rec(c->l, f, node_l, node_m);\n      }\n    }\n  }\n\n  T query_rec(Node\
    \ *c, ll x, ll node_l, ll node_r) {\n    T res = c->f(x);\n    ll node_m = (node_l\
    \ + node_r) / 2;\n    if (x < node_m && c->l) chmin(res, query_rec(c->l, x, node_l,\
    \ node_m));\n    if (x >= node_m && c->r) chmin(res, query_rec(c->r, x, node_m,\
    \ node_r));\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/dynamic_lichao.hpp
  requiredBy: []
  timestamp: '2022-05-27 14:32:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
  - test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
documentation_of: ds/dynamic_lichao.hpp
layout: document
redirect_from:
- /library/ds/dynamic_lichao.hpp
- /library/ds/dynamic_lichao.hpp.html
title: ds/dynamic_lichao.hpp
---
