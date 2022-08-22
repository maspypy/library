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
  code: "#include \"ds/fenwick.hpp\"\r\n#include \"graph/hld.hpp\"\r\n\r\ntemplate\
    \ <typename HLD, typename AbelGroup, bool edge = false,\r\n          bool path_query\
    \ = true, bool subtree_query = false>\r\nstruct TreeAbelGroup {\r\n  using X =\
    \ typename AbelGroup::value_type;\r\n  HLD &hld;\r\n  int N;\r\n  FenwickTree<AbelGroup>\
    \ bit, bit_subtree;\r\n\r\n  TreeAbelGroup(HLD &hld) : hld(hld), N(hld.N) {\r\n\
    \    if (path_query) { bit = FenwickTree<AbelGroup>(2 * N); }\r\n    if (subtree_query)\
    \ { bit_subtree = FenwickTree<AbelGroup>(N); }\r\n  }\r\n\r\n  TreeAbelGroup(HLD\
    \ &hld, vc<X> dat) : hld(hld), N(hld.N) {\r\n    if (path_query) {\r\n      vc<X>\
    \ bit_raw(2 * N);\r\n      if (!edge) {\r\n        assert(len(dat) == N);\r\n\
    \        FOR(v, N) {\r\n          bit_raw[hld.ELID(v)] = dat[v];\r\n         \
    \ bit_raw[hld.ERID(v)] = AbelGroup::inverse(dat[v]);\r\n        }\r\n      } else\
    \ {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1) {\r\n     \
    \     int v = hld.e_to_v(e);\r\n          bit_raw[hld.ELID(v)] = dat[e];\r\n \
    \         bit_raw[hld.ERID(v)] = AbelGroup::inverse(dat[e]);\r\n        }\r\n\
    \      }\r\n      bit = FenwickTree<AbelGroup>(bit_raw);\r\n    }\r\n    if (subtree_query)\
    \ {\r\n      vc<X> bit_raw(N);\r\n      if (!edge) {\r\n        assert(len(dat)\
    \ == N);\r\n        FOR(v, N) bit_raw[hld.LID[v]] = dat[v];\r\n      } else {\r\
    \n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1) {\r\n          int\
    \ v = hld.e_to_v(e);\r\n          bit_raw[hld.LID[v]] = dat[e];\r\n        }\r\
    \n      }\r\n      bit_subtree = FenwickTree<AbelGroup>(bit_raw);\r\n    }\r\n\
    \  }\r\n\r\n  void add(int i, X x) {\r\n    int v = (edge ? hld.e_to_v(i) : i);\r\
    \n    if (path_query) {\r\n      X inv_x = AbelGroup::inverse(x);\r\n      bit.add(hld.ELID(v),\
    \ x);\r\n      bit.add(hld.ERID(v), inv_x);\r\n    }\r\n    if (subtree_query)\
    \ bit_subtree.add(hld.LID[v], x);\r\n  }\r\n\r\n  X prod_path(int frm, int to)\
    \ {\r\n    assert(path_query);\r\n    int lca = hld.LCA(frm, to);\r\n    // [frm,\
    \ lca)\r\n    X x1 = bit.sum(hld.ELID(lca) + 1, hld.ELID(frm) + 1);\r\n    //\
    \ edge \u306A\u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\r\n    X x2 =\
    \ bit.sum(hld.ELID(lca) + edge, hld.ELID(to) + 1);\r\n    return AbelGroup::op(x1,\
    \ x2);\r\n  }\r\n\r\n  X prod_subtree(int u) {\r\n    assert(subtree_query);\r\
    \n    int l = hld.LID[u], r = hld.RID[u];\r\n    return bit_subtree.sum(l + edge,\
    \ r);\r\n  }\r\n\r\n  X sum_path(int frm, int to) { return prod_path(frm, to);\
    \ }\r\n  X sum_subtree(int u) { return prod_subtree(u); }\r\n\r\n  void debug()\
    \ {\r\n    hld.debug();\r\n    bit.debug();\r\n    bit_subtree.debug();\r\n  }\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/treeabelgroup.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/treeabelgroup.hpp
layout: document
redirect_from:
- /library/graph/treeabelgroup.hpp
- /library/graph/treeabelgroup.hpp.html
title: graph/treeabelgroup.hpp
---
