---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/kupc2019/tasks/kupc2019_l
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/monoid_min_idx.hpp:\
    \ line -1: no such header\n"
  code: "\r\n#include \"alg/monoid_min_idx.hpp\"\r\n\r\n// https://atcoder.jp/contests/kupc2019/tasks/kupc2019_l\r\
    \ntemplate <typename T, int NODES>\r\nstruct Persistent_Dynamic_LiChaoTree {\r\
    \n  using Mono = Monoid_Min_Idx<T>;\r\n  struct Line {\r\n    int idx;\r\n   \
    \ T a, b;\r\n    Line(int idx, T a, T b) : idx(idx), a(a), b(b) {}\r\n    Line()\
    \ : Line(-1, 0, numeric_limits<T>::max()) {}\r\n    pair<T, int> operator()(T\
    \ x) const { return {a * x + b, idx}; }\r\n  };\r\n\r\n  struct Node {\r\n   \
    \ Line f;\r\n    Node *l, *r;\r\n  };\r\n\r\n  Node *pool;\r\n  int pid;\r\n \
    \ ll L, R;\r\n\r\n  using np = Node *;\r\n\r\n  Persistent_Dynamic_LiChaoTree(ll\
    \ L, ll R) : pid(0), L(L), R(R) {\r\n    pool = new Node[NODES];\r\n  }\r\n\r\n\
    \  Node *new_node() {\r\n    pool[pid].f = Line();\r\n    pool[pid].l = nullptr;\r\
    \n    pool[pid].r = nullptr;\r\n    return &(pool[pid++]);\r\n  }\r\n\r\n  np\
    \ add_segment(np root, ll xl, ll xr, T a, T b, int idx = -1) {\r\n    constexpr\
    \ T INF = numeric_limits<T>::max();\r\n    if (a != 0) {\r\n      ll xlim = (INF\
    \ - abs(b)) / abs(a);\r\n      assert(abs(xl) < xlim);\r\n      assert(abs(xr)\
    \ < xlim);\r\n    }\r\n    assert(L <= xl && xl < xr && xr <= R);\r\n    Line\
    \ f(idx, a, b);\r\n    if (!root) root = new_node();\r\n    return add_segment_rec(root,\
    \ xl, xr, f, L, R);\r\n  }\r\n\r\n  np add_line(np root, T a, T b, int idx = -1)\
    \ {\r\n    return add_segment(root, L, R, a, b, idx);\r\n  }\r\n\r\n  pair<T,\
    \ int> query(np root, ll x) {\r\n    assert(L <= x && x < R);\r\n    if (!root)\
    \ return Mono::unit();\r\n    return query_rec(root, x, L, R);\r\n  }\r\n\r\n\
    private:\r\n  np copy_node(Node *c) {\r\n    np nc = new_node();\r\n    nc->f\
    \ = c->f;\r\n    nc->l = c->l;\r\n    nc->r = c->r;\r\n    return nc;\r\n  }\r\
    \n\r\n  np add_segment_rec(Node *c, ll xl, ll xr, const Line &f, ll node_l,\r\n\
    \                     ll node_r) {\r\n    chmax(xl, node_l);\r\n    chmin(xr,\
    \ node_r);\r\n    if (xl >= xr) return c;\r\n    if (node_l < xl || xr < node_r)\
    \ {\r\n      c = copy_node(c);\r\n      ll node_m = (node_l + node_r) / 2;\r\n\
    \      if (!c->l) c->l = new_node();\r\n      if (!c->r) c->r = new_node();\r\n\
    \      c->l = add_segment_rec(c->l, xl, xr, f, node_l, node_m);\r\n      c->r\
    \ = add_segment_rec(c->r, xl, xr, f, node_m, node_r);\r\n      return c;\r\n \
    \   }\r\n    return add_line_rec(c, f, node_l, node_r);\r\n  }\r\n\r\n  np add_line_rec(Node\
    \ *c, const Line &f, ll node_l, ll node_r) {\r\n    auto fl = f(node_l), fr =\
    \ f(node_r - 1);\r\n    Line g = c->f;\r\n    auto gl = g(node_l), gr = g(node_r\
    \ - 1);\r\n    bool bl = Mono::is_small(fl, gl);\r\n    bool br = Mono::is_small(fr,\
    \ gr);\r\n    if (bl && br) {\r\n      c = copy_node(c);\r\n      c->f = f;\r\n\
    \      return c;\r\n    }\r\n    if (!bl && !br) { return c; }\r\n\r\n    c =\
    \ copy_node(c);\r\n    ll node_m = (node_l + node_r) / 2;\r\n    auto fm = f(node_m),\
    \ gm = g(node_m);\r\n    bool bm = Mono::is_small(fm, gm);\r\n    if (bm) {\r\n\
    \      c->f = f;\r\n      if (bl) {\r\n        if (!c->r) c->r = new_node();\r\
    \n        c->r = add_line_rec(c->r, g, node_m, node_r);\r\n      } else {\r\n\
    \        if (!c->l) c->l = new_node();\r\n        c->l = add_line_rec(c->l, g,\
    \ node_l, node_m);\r\n      }\r\n    } else {\r\n      if (!bl) {\r\n        if\
    \ (!c->r) c->r = new_node();\r\n        c->r = add_line_rec(c->r, f, node_m, node_r);\r\
    \n      } else {\r\n        if (!c->l) c->l = new_node();\r\n        c->l = add_line_rec(c->l,\
    \ f, node_l, node_m);\r\n      }\r\n    }\r\n    return c;\r\n  }\r\n\r\n  pair<T,\
    \ int> query_rec(Node *c, ll x, ll node_l, ll node_r) {\r\n    pair<T, int> res\
    \ = c->f(x);\r\n    ll node_m = (node_l + node_r) / 2;\r\n    if (x < node_m &&\
    \ c->l)\r\n      res = Mono::op(res, query_rec(c->l, x, node_l, node_m));\r\n\
    \    if (x >= node_m && c->r)\r\n      res = Mono::op(res, query_rec(c->r, x,\
    \ node_m, node_r));\r\n    return res;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: pds/persistent_dynamic_lichao.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: pds/persistent_dynamic_lichao.hpp
layout: document
redirect_from:
- /library/pds/persistent_dynamic_lichao.hpp
- /library/pds/persistent_dynamic_lichao.hpp.html
title: pds/persistent_dynamic_lichao.hpp
---
