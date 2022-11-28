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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/lazy/min_add.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/common_interval_decomposition_tree\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/common_interval_decomposition.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  VEC(int, P, N);\n  Common_Inverval_Decomposition<1000000>\
    \ X(P);\n  int nxt = 0;\n  auto dfs = [&](auto& dfs, auto n, int p) -> void {\n\
    \    string t = (n->inc || n->dec || (n->r - n->l == 1) ? \"linear\" : \"prime\"\
    );\n    print(p, n->l, n->r - 1, t);\n    int v = nxt++;\n    for (auto&& c: n->ch)\
    \ dfs(dfs, c, v);\n  };\n  print(X.pid);\n  dfs(dfs, X.root, -1);\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/graph/common_interval_decomposition.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/common_interval_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/common_interval_decomposition.test.cpp
- /verify/test/library_checker/graph/common_interval_decomposition.test.cpp.html
title: test/library_checker/graph/common_interval_decomposition.test.cpp
---
