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
  code: "#include \"graph/base.hpp\"\r\n#include \"graph/degree.hpp\"\r\n\r\ntemplate\
    \ <typename Gr, typename F>\r\nvoid enumerate_triangles(Gr& G, F query) {\r\n\
    \  int N = G.N;\r\n  auto deg = degree(G);\r\n  Graph<int, 1> H(N);\r\n  for (auto&&\
    \ e: G.edges) {\r\n    // \u6CE8\u610F\uFF1A\u6B21\u6570\u6BD4\u8F03\u3060\u3051\
    \u3060\u3068 DAG \u306B\u306A\u3089\u305A\u3001\u30B5\u30A4\u30AF\u30EB\u304C\u3067\
    \u304D\u3066\u3057\u307E\u3046\r\n    if (mp(deg[e.frm], e.frm) < mp(deg[e.to],\
    \ e.to))\r\n      H.add(e.frm, e.to);\r\n    else\r\n      H.add(e.to, e.frm);\r\
    \n  }\r\n  H.build();\r\n\r\n  vc<bool> table(N);\r\n  FOR(a, N) {\r\n    for\
    \ (auto&& e: H[a]) { table[e.to] = 1; }\r\n    for (auto&& e: H[a]) {\r\n    \
    \  int b = e.to;\r\n      for (auto&& f: H[b]) {\r\n        int c = f.to;\r\n\
    \        if (table[c]) query(a, b, c);\r\n      }\r\n    }\r\n    for (auto&&\
    \ e: H[a]) { table[e.to] = 0; }\r\n  }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/enumerate_triangles.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/enumerate_triangles.hpp
layout: document
redirect_from:
- /library/graph/enumerate_triangles.hpp
- /library/graph/enumerate_triangles.hpp.html
title: graph/enumerate_triangles.hpp
---
