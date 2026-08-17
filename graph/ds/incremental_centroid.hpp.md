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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/ds/tree_abelgroup.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/ds/tree_abelgroup.hpp\"\n#include \"ds/fastset.hpp\"\n\n\
    // \u6728\u306F\u56FA\u5B9A\u3002\u9802\u70B9\u91CD\u307F\u3092 +1 \u3067\u304D\
    \u308B\u3002\n// cent: \u91CD\u5FC3\n// max_subtree\ntemplate <typename TREE>\n\
    struct Incremental_Centroid {\n  TREE& tree;\n  int N;\n  int cent;\n  pair<int,\
    \ int> max_subtree;  // (adj, size)\n  int wt_sm;\n  Tree_AbelianGroup<TREE, Monoid_Add<int>,\
    \ 0, 0, 1> TA;\n  FastSet ss;\n\n  Incremental_Centroid(TREE& tree)\n      : tree(tree),\n\
    \        N(tree.N),\n        cent(0),\n        max_subtree(0, 0),\n        wt_sm(0),\n\
    \        TA(tree),\n        ss(N) {}\n\n  int get_subtree_wt(int v) {\n    assert(v\
    \ != cent);\n    // cent \u304B\u3089\u898B\u3066 v \u65B9\u5411\n    if (tree.in_subtree(v,\
    \ cent)) {\n      return TA.prod_subtree(tree.jump(cent, v, 1));\n    }\n    return\
    \ wt_sm - TA.prod_subtree(cent);\n  }\n\n  int move_to(int v) {\n    // \u5727\
    \u7E2E\u6728\u4E0A\u3067 cent \u304B\u3089 v \u306B\u9032\u3080\n    if (tree.in_subtree(v,\
    \ cent)) {\n      // v \u65B9\u5411\u306B\u3042\u308B\u91CD\u307F\u306E lca\n\
    \      int a = tree.jump(cent, v, 1);\n      int L = tree.LID[a], R = tree.RID[a];\n\
    \      L = ss.next(L), R = ss.prev(R - 1);\n      int x = tree.V[L], y = tree.V[R];\n\
    \      return tree.LCA(x, y);\n    }\n    int L = tree.LID[cent], R = tree.RID[cent];\n\
    \    int x = v;\n    vc<int> I;\n    I.eb(ss.next(0));\n    if (1 < L) I.eb(ss.prev(L\
    \ - 1));\n    if (R < N - 1) I.eb(ss.next(R));\n    I.eb(ss.prev(N - 1));\n  \
    \  for (auto&& idx : I) {\n      if (idx == -1 || idx == N) continue;\n      if\
    \ (L <= idx && idx < R) continue;\n      int y = tree.V[idx];\n      x = tree.meet(x,\
    \ y, cent);\n    }\n    return x;\n  }\n\n  void add(int v) {\n    ss.insert(tree.LID[v]),\
    \ TA.add(v, 1), wt_sm++;\n    if (v == cent) return;\n    int wt = get_subtree_wt(v);\n\
    \    if (max_subtree.se < wt) max_subtree = {tree.jump(cent, v, 1), wt};\n   \
    \ if (2 * wt <= wt_sm) return;\n    int k = wt;\n    assert(wt_sm == 2 * k - 1);\n\
    \    int to = move_to(v);\n    max_subtree = {tree.jump(to, cent, 1), k - 1};\n\
    \    cent = to;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/incremental_centroid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/incremental_centroid.hpp
layout: document
redirect_from:
- /library/graph/ds/incremental_centroid.hpp
- /library/graph/ds/incremental_centroid.hpp.html
title: graph/ds/incremental_centroid.hpp
---
