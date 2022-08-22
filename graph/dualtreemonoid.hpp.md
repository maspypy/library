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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/hld.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/lazysegtree.hpp\"\r\n#include \"graph/hld.hpp\"\r\n#include\
    \ \"ds/dualsegtree.hpp\"\r\n\r\ntemplate <typename HLD, typename Monoid, bool\
    \ edge = false>\r\nstruct DualTreeMonoid {\r\n  using X = typename Monoid::value_type;\r\
    \n  HLD &hld;\r\n  int N;\r\n  DualSegTree<Monoid> seg;\r\n\r\n  DualTreeMonoid(HLD\
    \ &hld) : hld(hld), N(hld.N), seg(hld.N) {}\r\n\r\n  X get(int i) {\r\n    int\
    \ v = i;\r\n    if (edge) {\r\n      auto &&e = hld.G.edges[i];\r\n      v = (hld.parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n    }\r\n    return seg.get(hld.LID[v]);\r\n  }\r\
    \n\r\n  vc<X> get_all() {\r\n    vc<X> tmp = seg.get_all();\r\n    vc<X> res;\r\
    \n    FOR(i, N) {\r\n      if (edge && i == N - 1) break;\r\n      int v = i;\r\
    \n      if (edge) {\r\n        auto &&e = hld.G.edges[i];\r\n        v = (hld.parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n      }\r\n      res.eb(tmp[hld.LID[v]]);\r\n  \
    \  }\r\n    return res;\r\n  }\r\n\r\n  void apply_path(int u, int v, X x) {\r\
    \n    auto pd = hld.get_path_decomposition(u, v, edge);\r\n    for (auto &&[a,\
    \ b]: pd) {\r\n      (a <= b ? seg.apply(a, b + 1, x) : seg.apply(b, a + 1, x));\r\
    \n    }\r\n    return;\r\n  }\r\n\r\n  void apply_subtree(int u, X x) {\r\n  \
    \  int l = hld.LID[u], r = hld.RID[u];\r\n    return seg.apply(l + edge, r, x);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dualtreemonoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dualtreemonoid.hpp
layout: document
redirect_from:
- /library/graph/dualtreemonoid.hpp
- /library/graph/dualtreemonoid.hpp.html
title: graph/dualtreemonoid.hpp
---
