---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/rerooting_classify_subtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/rerooting_classify_subtree.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  int root = RNG(0, N);\n  Graph<int, 0> G(N);\n\
    \n  G.read_parent(0);\n  Tree<decltype(G)> tree(G, root);\n\n  Rerooting_classify_subtree<decltype(tree)>\
    \ X(tree);\n  vc<ll> dp(N);\n  FOR(v, N) dp[v] = X.get(0, v);\n  auto key = dp;\n\
    \  UNIQUE(key);\n  for (auto&& x: dp) x = LB(key, x);\n  print(MAX(dp) + 1);\n\
    \  print(dp);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/graph/rerooting_classify_subtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/rerooting_classify_subtree.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/rerooting_classify_subtree.test.cpp
- /verify/test/library_checker/graph/rerooting_classify_subtree.test.cpp.html
title: test/library_checker/graph/rerooting_classify_subtree.test.cpp
---
