---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/acted_monoid/cntsum_add.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"alg/monoid/add.hpp\"\
    \n#include \"graph/ds/lazytreemonoid.hpp\"\n#include \"alg/acted_monoid/cntsum_add.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  Graph<int, 0> G(N);\n  FOR(v, N) {\n    LL(k);\n\
    \    FOR(k) {\n      LL(to);\n      G.add(v, to);\n    }\n  }\n  G.build();\n\
    \  TREE<decltype(G)> tree(G);\n  vc<pi> seg_raw(N - 1, {1, 0});\n  using AM =\
    \ ActedMonoid_CntSum_Add<ll>;\n  LazyTreeMonoid<decltype(tree), AM, 1> TM(tree,\
    \ seg_raw);\n  LL(Q);\n  FOR(Q) {\n    LL(t);\n    if (t == 0) {\n      LL(v,\
    \ x);\n      TM.apply_path(0, v, x);\n      // TM.apply_path(tree.parent[v], v,\
    \ x);\n    } else {\n      LL(v);\n      print(TM.prod_path(0, v).se);\n    }\n\
    \  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/GRL_5_E.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_E.test.cpp
- /verify/test/aoj/GRL_5_E.test.cpp.html
title: test/aoj/GRL_5_E.test.cpp
---
