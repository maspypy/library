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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/fenwick.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/fenwick.hpp\"\r\n#include \"graph/tree.hpp\"\r\n\r\ntemplate\
    \ <typename TREE, typename AbelGroup, bool edge = false,\r\n          bool path_query\
    \ = true, bool subtree_query = false>\r\nstruct TreeAbelGroup {\r\n  using X =\
    \ typename AbelGroup::value_type;\r\n  TREE &tree;\r\n  int N;\r\n  FenwickTree<AbelGroup>\
    \ bit, bit_subtree;\r\n\r\n  TreeAbelGroup(TREE &tree) : tree(tree), N(tree.N)\
    \ {\r\n    if (path_query) { bit = FenwickTree<AbelGroup>(2 * N); }\r\n    if\
    \ (subtree_query) { bit_subtree = FenwickTree<AbelGroup>(N); }\r\n  }\r\n\r\n\
    \  TreeAbelGroup(TREE &tree, vc<X> dat) : tree(tree), N(tree.N) {\r\n    if (path_query)\
    \ {\r\n      vc<X> bit_raw(2 * N);\r\n      if (!edge) {\r\n        assert(len(dat)\
    \ == N);\r\n        FOR(v, N) {\r\n          bit_raw[tree.ELID(v)] = dat[v];\r\
    \n          bit_raw[tree.ERID(v)] = AbelGroup::inverse(dat[v]);\r\n        }\r\
    \n      } else {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1)\
    \ {\r\n          int v = tree.e_to_v(e);\r\n          bit_raw[tree.ELID(v)] =\
    \ dat[e];\r\n          bit_raw[tree.ERID(v)] = AbelGroup::inverse(dat[e]);\r\n\
    \        }\r\n      }\r\n      bit = FenwickTree<AbelGroup>(bit_raw);\r\n    }\r\
    \n    if (subtree_query) {\r\n      vc<X> bit_raw(N);\r\n      if (!edge) {\r\n\
    \        assert(len(dat) == N);\r\n        FOR(v, N) bit_raw[tree.LID[v]] = dat[v];\r\
    \n      } else {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1)\
    \ {\r\n          int v = tree.e_to_v(e);\r\n          bit_raw[tree.LID[v]] = dat[e];\r\
    \n        }\r\n      }\r\n      bit_subtree = FenwickTree<AbelGroup>(bit_raw);\r\
    \n    }\r\n  }\r\n\r\n  void add(int i, X x) {\r\n    int v = (edge ? tree.e_to_v(i)\
    \ : i);\r\n    if (path_query) {\r\n      X inv_x = AbelGroup::inverse(x);\r\n\
    \      bit.add(tree.ELID(v), x);\r\n      bit.add(tree.ERID(v), inv_x);\r\n  \
    \  }\r\n    if (subtree_query) bit_subtree.add(tree.LID[v], x);\r\n  }\r\n\r\n\
    \  X prod_path(int frm, int to) {\r\n    assert(path_query);\r\n    int lca =\
    \ tree.LCA(frm, to);\r\n    // [frm, lca)\r\n    X x1 = bit.prod(tree.ELID(lca)\
    \ + 1, tree.ELID(frm) + 1);\r\n    // edge \u306A\u3089 (lca, to]\u3001vertex\
    \ \u306A\u3089 [lca, to]\r\n    X x2 = bit.prod(tree.ELID(lca) + edge, tree.ELID(to)\
    \ + 1);\r\n    return AbelGroup::op(x1, x2);\r\n  }\r\n\r\n  X prod_subtree(int\
    \ u) {\r\n    assert(subtree_query);\r\n    int l = tree.LID[u], r = tree.RID[u];\r\
    \n    return bit_subtree.prod(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n\
    \    tree.debug();\r\n    bit.debug();\r\n    bit_subtree.debug();\r\n  }\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/treeabelgroup.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/treeabelgroup.hpp
layout: document
redirect_from:
- /library/graph/ds/treeabelgroup.hpp
- /library/graph/ds/treeabelgroup.hpp.html
title: graph/ds/treeabelgroup.hpp
---
