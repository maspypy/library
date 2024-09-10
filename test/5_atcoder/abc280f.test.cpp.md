---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind/weighted_unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc280/tasks/abc280_f\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/unionfind/weighted_unionfind.hpp\"\
    \n#include \"alg/monoid/add.hpp\"\n\nvoid solve() {\n  LL(N, M, Q);\n  Weighted_UnionFind<Monoid_Add<ll>>\
    \ uf(N);\n  vi neg(N);\n\n  FOR(M) {\n    LL(a, b, c);\n    --a, --b;\n    auto\
    \ [ra, xa] = uf[a];\n    auto [rb, xb] = uf[b];\n    if (ra != rb) {\n      uf.merge(a,\
    \ b, c);\n      continue;\n    }\n    if (xa + c == xb) continue;\n    neg[a]\
    \ = 1;\n  }\n  FOR(v, N) if (neg[v]) {\n    auto [r, x] = uf[v];\n    neg[r] =\
    \ 1;\n  }\n\n  FOR(Q) {\n    LL(a, b);\n    --a, --b;\n    auto [ra, xa] = uf[a];\n\
    \    auto [rb, xb] = uf[b];\n    if (ra != rb) {\n      print(\"nan\");\n    }\
    \ else {\n      if (neg[ra]) {\n        print(\"inf\");\n      } else {\n    \
    \    print(xb - xa);\n      }\n    }\n  }\n}\n\nsigned main() {\n  int T = 1;\n\
    \  // INT(T);\n  FOR(T) solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/5_atcoder/abc280f.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/5_atcoder/abc280f.test.cpp
layout: document
redirect_from:
- /verify/test/5_atcoder/abc280f.test.cpp
- /verify/test/5_atcoder/abc280f.test.cpp.html
title: test/5_atcoder/abc280f.test.cpp
---
