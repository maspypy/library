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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/scc.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/scc.hpp\"\r\nstruct TwoSat {\r\n  vc<int> values;\r\n\r\n\
    \  Graph<int, 1> G;\r\n  TwoSat(ll n) : G(n + n), values(n, -1) {}\r\n  void add(int\
    \ a, int b) {\r\n    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));\r\n    b = (b >= 0 ?\
    \ 2 * b + 1 : 2 * (~b));\r\n    G.add(a ^ 1, b);\r\n    G.add(b ^ 1, a);\r\n \
    \ }\r\n  void set(int a) {\r\n    if (a >= 0)\r\n      values[a] = 1;\r\n    else\r\
    \n      values[~a] = 0;\r\n    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));\r\n    G.add(a\
    \ ^ 1, a);\r\n  }\r\n  void implies(int a, int b) { add(~a, b); }\r\n\r\n  bool\
    \ calc() {\r\n    G.build();\r\n    ll n = len(values);\r\n    SCC<Graph<int,\
    \ 1>> scc(G);\r\n    FOR(i, n) {\r\n      if (scc[2 * i] == scc[2 * i + 1]) return\
    \ false;\r\n      values[i] = scc[2 * i] < scc[2 * i + 1];\r\n    }\r\n    return\
    \ true;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/twosat.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/twosat.hpp
layout: document
redirect_from:
- /library/graph/twosat.hpp
- /library/graph/twosat.hpp.html
title: graph/twosat.hpp
---
