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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bit.hpp: line\
    \ -1: no such header\n"
  code: "#include \"graph/tree.hpp\"\n#include \"alg/monoid/min.hpp\"\n#include \"\
    ds/sparse_table/sparse_table.hpp\"\n\ntemplate <typename TREE>\nstruct Fast_Lca\
    \ {\n  TREE& tree;\n  Sparse_Table<Monoid_Min<int>> seg;\n  vc<int> pos;\n\n \
    \ Fast_Lca(TREE& tree) : tree(tree) {\n    int N = tree.N;\n    pos.resize(N);\n\
    \    vc<int> dat(2 * N);\n    FOR(v, N) {\n      int a = tree.ELID(v);\n     \
    \ int b = tree.ERID(v);\n      pos[v] = a;\n      dat[a] = tree.LID[v];\n    \
    \  dat[b] = (v == tree.V[0] ? -1 : tree.LID[tree.parent[v]]);\n    }\n    seg.build(dat);\n\
    \  }\n\n  int dist(int a, int b) {\n    int c = lca(a, b);\n    return tree.depth[a]\
    \ + tree.depth[b] - 2 * tree.depth[c];\n  }\n\n  using WT = typename TREE::WT;\n\
    \  WT dist_weighted(int a, int b) {\n    int c = lca(a, b);\n    return tree.depth_weighted[a]\
    \ + tree.depth_weighted[b] - 2 * tree.depth_weighted[c];\n  }\n\n  int lca(int\
    \ a, int b) {\n    int p = pos[a], q = pos[b];\n    if (p > q) swap(p, q);\n \
    \   return tree.V[seg.prod(p, q + 1)];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/fast_lca.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/fast_lca.hpp
layout: document
redirect_from:
- /library/graph/fast_lca.hpp
- /library/graph/fast_lca.hpp.html
title: graph/fast_lca.hpp
---
