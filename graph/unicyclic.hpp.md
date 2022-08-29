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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/degree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/degree.hpp\"\n\nstruct UnicyclicGraph {\n  int root;\n \
    \ Graph<int, 1> tree;\n  vc<int> TO;\n  vc<int> cycle; // \u6839\u306B\u5411\u304B\
    \u3046\u3088\u3046\u306A\u9802\u70B9\u5217\n  vc<bool> in_cycle;\n\n  template\
    \ <typename Graph>\n  UnicyclicGraph(Graph& G) : tree(G.N) {\n    int N = G.N;\n\
    \    assert(N == G.M);\n    TO.assign(N, -1);\n    vc<bool> done(N);\n    vc<int>\
    \ que;\n    auto deg = degree(G);\n    FOR(v, N) if (deg[v] == 1) que.eb(v);\n\
    \    while (len(que)) {\n      auto v = que.back();\n      que.pop_back();\n \
    \     for (auto&& e: G[v]) {\n        if (done[e.id]) continue;\n        done[e.id]\
    \ = 1;\n        int to = e.to;\n        TO[v] = to;\n        deg[to] -= 1;\n \
    \       if (deg[to] == 1) que.eb(to);\n      }\n      deg[v] = 0;\n    }\n   \
    \ root = -1;\n    FOR(v, N) if (deg[v] == 2) root = v;\n    assert(root != -1);\n\
    \    vc<int> P = {root};\n    while (1) {\n      int v = P.back();\n      bool\
    \ upd = 0;\n      for (auto&& e: G[v]) {\n        if (done[e.id]) continue;\n\
    \        done[e.id] = 1;\n        P.eb(e.to);\n        upd = 1;\n        break;\n\
    \      }\n      if (!upd) break;\n    }\n    FOR(i, len(P) - 1) TO[P[i]] = P[i\
    \ + 1];\n    cycle = {P.begin() + 1, P.end()};\n    reverse(all(cycle));\n   \
    \ in_cycle.assign(N, false);\n    for(auto&& v : cycle) in_cycle[v] = 1;\n   \
    \ FOR(v, N) if (v != root) tree.add(TO[v], v);\n    tree.build();\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/unicyclic.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/unicyclic.hpp
layout: document
redirect_from:
- /library/graph/unicyclic.hpp
- /library/graph/unicyclic.hpp.html
title: graph/unicyclic.hpp
---
