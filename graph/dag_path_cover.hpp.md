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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/check_bipartite.hpp:\
    \ line -1: no such header\n"
  code: "#include \"flow/bipartite.hpp\"\n#include \"graph/toposort.hpp\"\n\n// path\
    \ \uFF08\u9802\u70B9\u5217\uFF09\u306E vector \u3092\u8FD4\u3059 O(m sqrt(n))\n\
    template <typename DAG>\nvc<vc<int>> dag_path_cover(DAG& G) {\n  assert(G.is_directed());\n\
    \  int n = G.N;\n  auto V = toposort(G);\n  vc<int> idx(n);\n  FOR(i, n) idx[V[i]]\
    \ = i;\n\n  // check dag\n  for (auto&& e: G.edges) assert(idx[e.frm] < idx[e.to]);\n\
    \n  Graph H(n + n);\n  for (auto&& e: G.edges) { H.add(e.frm, e.to + n); }\n \
    \ H.build();\n  BipartiteMatching BM(H);\n  auto match = BM.matching();\n  vc<int>\
    \ nxt(n, -1);\n  for (auto&& [a, b]: match) {\n    if (a > b) swap(a, b);\n  \
    \  nxt[a] = b - n;\n  }\n\n  vc<bool> done(n);\n\n  vvc<int> paths;\n  for (auto&&\
    \ v: V) {\n    if (done[v]) continue;\n    vc<int> P = {v};\n    while (1) {\n\
    \      int w = nxt[P.back()];\n      if (w == -1) break;\n      P.eb(w);\n   \
    \ }\n    for (auto&& x: P) done[x] = 1;\n    paths.eb(P);\n  }\n  return paths;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: graph/dag_path_cover.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dag_path_cover.hpp
layout: document
redirect_from:
- /library/graph/dag_path_cover.hpp
- /library/graph/dag_path_cover.hpp.html
title: graph/dag_path_cover.hpp
---
