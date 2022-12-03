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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree/dualsegtree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/tree.hpp\"\r\n#include \"ds/segtree/dualsegtree.hpp\"\r\n\
    \r\ntemplate <typename TREE, typename Monoid, bool edge = false>\r\nstruct DualTreeMonoid\
    \ {\r\n  using X = typename Monoid::value_type;\r\n  TREE &tree;\r\n  int N;\r\
    \n  DualSegTree<Monoid> seg;\r\n\r\n  DualTreeMonoid(TREE &tree) : tree(tree),\
    \ N(tree.N), seg(tree.N) {}\r\n\r\n  X get(int i) {\r\n    int v = i;\r\n    if\
    \ (edge) {\r\n      auto &&e = tree.G.edges[i];\r\n      v = (tree.parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n    }\r\n    return seg.get(tree.LID[v]);\r\n  }\r\
    \n\r\n  vc<X> get_all() {\r\n    vc<X> tmp = seg.get_all();\r\n    vc<X> res;\r\
    \n    FOR(i, N) {\r\n      if (edge && i == N - 1) break;\r\n      int v = i;\r\
    \n      if (edge) {\r\n        auto &&e = tree.G.edges[i];\r\n        v = (tree.parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n      }\r\n      res.eb(tmp[tree.LID[v]]);\r\n \
    \   }\r\n    return res;\r\n  }\r\n\r\n  void apply_path(int u, int v, X x) {\r\
    \n    auto pd = tree.get_path_decomposition(u, v, edge);\r\n    for (auto &&[a,\
    \ b]: pd) {\r\n      (a <= b ? seg.apply(a, b + 1, x) : seg.apply(b, a + 1, x));\r\
    \n    }\r\n    return;\r\n  }\r\n\r\n  void apply_subtree(int u, X x) {\r\n  \
    \  int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.apply(l + edge, r,\
    \ x);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/dual_tree_monoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/dual_tree_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/dual_tree_monoid.hpp
- /library/graph/ds/dual_tree_monoid.hpp.html
title: graph/ds/dual_tree_monoid.hpp
---
