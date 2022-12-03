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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc270/tasks/abc270_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/minimum_spanning_tree.hpp\"\
    \n#include \"graph/base.hpp\"\n\nvoid solve() {\n  LL(N, M);\n  VEC(ll, X, N);\n\
    \  VEC(ll, Y, N);\n  using T = tuple<int, int, int>;\n  VEC(T, dat, M);\n  for\
    \ (auto&& [a, b, c]: dat) { --a, --b; }\n\n  vi cand;\n\n  {\n    Graph<ll> G(N);\n\
    \    for (auto&& [a, b, c]: dat) { G.add(a, b, c); }\n    G.build();\n    auto\
    \ [val, used, tree] = minimum_spanning_tree(G);\n    if (SUM<int>(used) == N -\
    \ 1) cand.eb(val);\n  }\n  {\n    Graph<ll> G(N + 1);\n    FOR(i, N) G.add(i,\
    \ N, X[i]);\n    for (auto&& [a, b, c]: dat) { G.add(a, b, c); }\n    G.build();\n\
    \    auto [val, used, tree] = minimum_spanning_tree(G);\n    if (SUM<int>(used)\
    \ == N) cand.eb(val);\n    cand.eb(val);\n  }\n  {\n    Graph<ll> G(N + 1);\n\
    \    FOR(i, N) G.add(i, N, Y[i]);\n    for (auto&& [a, b, c]: dat) { G.add(a,\
    \ b, c); }\n    G.build();\n    auto [val, used, tree] = minimum_spanning_tree(G);\n\
    \    if (SUM<int>(used) == N) cand.eb(val);\n    cand.eb(val);\n  }\n  {\n   \
    \ Graph<ll> G(N + 2);\n    FOR(i, N) G.add(i, N, X[i]);\n    FOR(i, N) G.add(i,\
    \ N + 1, Y[i]);\n    for (auto&& [a, b, c]: dat) { G.add(a, b, c); }\n    G.build();\n\
    \    auto [val, used, tree] = minimum_spanning_tree(G);\n    if (SUM<int>(used)\
    \ == N + 1) cand.eb(val);\n  }\n\n  print(MIN(cand));\n}\n\nsigned main() {\n\
    \  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc270_f.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc270_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc270_f.test.cpp
- /verify/test/atcoder/abc270_f.test.cpp.html
title: test/atcoder/abc270_f.test.cpp
---
