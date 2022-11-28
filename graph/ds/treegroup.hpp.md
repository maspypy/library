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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/monoid/reverse_group.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/segtree.hpp\"\r\n#include \"graph/tree.hpp\"\r\n#include \"\
    alg/monoid/reverse_group.hpp\"\r\n\r\n// \u4F5C\u3063\u3066\u307F\u305F\u3082\u306E\
    \u306E\u3001HLD(log^2N)\u3088\u308A\u9045\u3044\u304C\u3061\uFF1F\r\ntemplate\
    \ <typename TREE, typename Group, bool edge = false,\r\n          bool path_query\
    \ = true, bool subtree_query = false>\r\nstruct TreeGroup {\r\n  using RevGroup\
    \ = Group_Reverse<Group>;\r\n  using X = typename Group::value_type;\r\n  TREE\
    \ &tree;\r\n  int N;\r\n  SegTree<Group> seg, seg_subtree;\r\n  SegTree<RevGroup>\
    \ seg_r;\r\n\r\n  TreeGroup(TREE &tree) : tree(tree), N(tree.N) {\r\n    if (path_query)\
    \ {\r\n      seg = SegTree<Group>(2 * N);\r\n      if (!Group::commute) seg_r\
    \ = SegTree<RevGroup>(2 * N);\r\n    }\r\n    if (subtree_query) {\r\n      assert(Group::commute);\r\
    \n      seg_subtree = SegTree<Group>(N);\r\n    }\r\n  }\r\n\r\n  TreeGroup(TREE\
    \ &tree, vc<X> dat) : tree(tree), N(tree.N) {\r\n    if (path_query) {\r\n   \
    \   vc<X> seg_raw(2 * N);\r\n      if (!edge) {\r\n        assert(len(dat) ==\
    \ N);\r\n        FOR(v, N) {\r\n          seg_raw[tree.ELID(v)] = dat[v];\r\n\
    \          seg_raw[tree.ERID(v)] = Group::inverse(dat[v]);\r\n        }\r\n  \
    \    } else {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1) {\r\
    \n          int v = tree.e_to_v(e);\r\n          seg_raw[tree.ELID(v)] = dat[e];\r\
    \n          seg_raw[tree.ERID(v)] = Group::inverse(dat[e]);\r\n        }\r\n \
    \     }\r\n      seg = SegTree<Group>(seg_raw);\r\n      if (!Group::commute)\
    \ seg_r = SegTree<RevGroup>(seg_raw);\r\n    }\r\n    if (subtree_query) {\r\n\
    \      assert(Group::commute);\r\n      vc<X> seg_raw(N);\r\n      if (!edge)\
    \ {\r\n        assert(len(dat) == N);\r\n        FOR(v, N) seg_raw[tree.LID[v]]\
    \ = dat[v];\r\n      } else {\r\n        assert(len(dat) == N - 1);\r\n      \
    \  FOR(e, N - 1) {\r\n          int v = tree.e_to_v(e);\r\n          seg_raw[tree.LID[v]]\
    \ = dat[e];\r\n        }\r\n      }\r\n      seg_subtree = SegTree<Group>(seg_raw);\r\
    \n    }\r\n  }\r\n\r\n  void set_path(int v, X x) {\r\n    X inv_x = Group::inverse(x);\r\
    \n    seg.set(tree.ELID(v), x);\r\n    seg.set(tree.ERID(v), inv_x);\r\n    if\
    \ (!Group::commute) {\r\n      seg_r.set(tree.ELID(v), x);\r\n      seg_r.set(tree.ERID(v),\
    \ inv_x);\r\n    }\r\n  }\r\n\r\n  void set_subtree(int v, X x) { seg_subtree.set(tree.LID[v],\
    \ x); }\r\n\r\n  void set(int i, X x) {\r\n    int v = (edge ? tree.e_to_v(i)\
    \ : i);\r\n    if (path_query) set_path(v, x);\r\n    if (subtree_query) set_subtree(v,\
    \ x);\r\n  }\r\n\r\n  X prod_path(int frm, int to) {\r\n    assert(path_query);\r\
    \n    int lca = tree.LCA(frm, to);\r\n    // [frm, lca)\r\n    X x1\r\n      \
    \  = (Group::commute ? seg.prod(tree.ELID(lca) + 1, tree.ELID(frm) + 1)\r\n  \
    \                        : seg_r.prod(tree.ELID(lca) + 1, tree.ELID(frm) + 1));\r\
    \n    // edge \u306A\u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\r\n  \
    \  X x2 = seg.prod(tree.ELID(lca) + edge, tree.ELID(to) + 1);\r\n    return Group::op(x1,\
    \ x2);\r\n  }\r\n\r\n  X prod_subtree(int u) {\r\n    assert(subtree_query);\r\
    \n    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg_subtree.prod(l +\
    \ edge, r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"tree\");\r\n    tree.debug();\r\
    \n    print(\"seg\");\r\n    seg.debug();\r\n    print(\"seg_r\");\r\n    seg_r.debug();\r\
    \n    print(\"seg_subtree\");\r\n    seg_subtree.debug();\r\n  }\r\n\r\n  void\
    \ doc() {\r\n    print(\"EulerTour + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\
    \u9006\u5143\u3092\u5229\u7528\u3057\u3066\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\
    \u3092 O(logN) \u6642\u9593\u3067\u884C\u3046\u3002\");\r\n    print(\"\u90E8\u5206\
    \u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\
    \ O(logN) \u6642\u9593\u3002\");\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/treegroup.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/treegroup.hpp
layout: document
redirect_from:
- /library/graph/ds/treegroup.hpp
- /library/graph/ds/treegroup.hpp.html
title: graph/ds/treegroup.hpp
---
