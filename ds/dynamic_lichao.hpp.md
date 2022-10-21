---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/monoid_min_idx.hpp:\
    \ line -1: no such header\n"
  code: "#include \"alg/monoid_min_idx.hpp\"\n\n// x \u5EA7\u6A19\u306F long long\
    \ \u306B\u9650\u5B9A\u3057\u3066\u3044\u308B\u3002\n// \u76F4\u7DDA\u306E\u4FC2\
    \u6570 T \u306F double \u3084 i128 \u3082\u53EF\u80FD\u3002\ntemplate <typename\
    \ T, int NODES>\nstruct Dynamic_LiChaoTree {\n  using Mono = Monoid_Min_Idx<T>;\n\
    \  struct Line {\n    int idx;\n    T a, b;\n    Line(int idx, T a, T b) : idx(idx),\
    \ a(a), b(b) {}\n    Line() : Line(-1, 0, numeric_limits<T>::max()) {}\n    pair<T,\
    \ int> operator()(T x) const { return {a * x + b, idx}; }\n  };\n\n  struct Node\
    \ {\n    Line f;\n    Node *l, *r;\n  };\n\n  Node *pool;\n  int pid;\n  ll L,\
    \ R;\n  Node *root;\n\n  Dynamic_LiChaoTree(ll L, ll R) : pid(0), L(L), R(R),\
    \ root(nullptr) {\n    pool = new Node[NODES];\n  }\n\n  Node *new_node() {\n\
    \    pool[pid].f = Line();\n    return &(pool[pid++]);\n  }\n\n  void add_segment(ll\
    \ xl, ll xr, T a, T b, int idx = -1) {\n    constexpr T INF = numeric_limits<T>::max();\n\
    \    if (a != 0) {\n      ll xlim = (INF - abs(b)) / abs(a);\n      assert(abs(xl)\
    \ < xlim);\n      assert(abs(xr) < xlim);\n    }\n    assert(L <= xl && xl < xr\
    \ && xr <= R);\n    Line f(idx, a, b);\n    if (!root) root = new_node();\n  \
    \  add_segment_rec(root, xl, xr, f, L, R);\n  }\n\n  void add_line(T a, T b, int\
    \ idx = -1) { add_segment(L, R, a, b, idx); }\n\n  pair<T, int> query(ll x) {\n\
    \    assert(L <= x && x < R);\n    if (!root) return Mono::unit();\n    return\
    \ query_rec(root, x, L, R);\n  }\n\nprivate:\n  void add_segment_rec(Node *c,\
    \ ll xl, ll xr, const Line &f, ll node_l,\n                       ll node_r) {\n\
    \    chmax(xl, node_l);\n    chmin(xr, node_r);\n    if (xl >= xr) return;\n \
    \   if (node_l < xl || xr < node_r) {\n      ll node_m = (node_l + node_r) / 2;\n\
    \      if (!c->l) c->l = new_node();\n      if (!c->r) c->r = new_node();\n  \
    \    add_segment_rec(c->l, xl, xr, f, node_l, node_m);\n      add_segment_rec(c->r,\
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
    \ + node_r) / 2;\n    if (x < node_m && c->l) res = Mono::op(res, query_rec(c->l,\
    \ x, node_l, node_m));\n    if (x >= node_m && c->r) res = Mono::op(res, query_rec(c->r,\
    \ x, node_m, node_r));\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/dynamic_lichao.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/dynamic_lichao.hpp
layout: document
redirect_from:
- /library/ds/dynamic_lichao.hpp
- /library/ds/dynamic_lichao.hpp.html
title: ds/dynamic_lichao.hpp
---
