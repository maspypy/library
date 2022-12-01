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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#include \"flow/bipartite.hpp\"\n\n// \u6BD4\u8F03\u53EF\u80FD\u30B0\u30E9\
    \u30D5\u3092\u4E0E\u3048\u308B\u3002DAG \u306A\u3060\u3051\u3067\u306F\u30C0\u30E1\
    \u3002\ntemplate <typename T>\nvc<int> maximum_antichain(T& G) {\n  assert(G.is_directed());\n\
    \  int n = G.N;\n\n  Graph H(n + n);\n  for (auto&& e: G.edges) { H.add(e.frm,\
    \ e.to + n); }\n  H.build();\n  BipartiteMatching BM(H);\n  auto cover = BM.vertex_cover();\n\
    \  auto match = BM.matching();\n  assert(len(cover) == len(match));\n  vc<bool>\
    \ ok(n, 1);\n  for (auto&& v: cover) { ok[v % n] = 0; }\n  vc<int> antichain;\n\
    \  FOR(v, n) if (ok[v]) antichain.eb(v);\n  for (auto&& e: G.edges) { assert(!ok[e.frm]\
    \ || !ok[e.to]); }\n  return antichain;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximum_antichain.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/maximum_antichain.hpp
layout: document
redirect_from:
- /library/graph/maximum_antichain.hpp
- /library/graph/maximum_antichain.hpp.html
title: graph/maximum_antichain.hpp
---
