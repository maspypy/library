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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/dsu_on_tree.hpp\"\
    \n#include \"ds/fenwick.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n\
    \  Graph<int, 1> G(N);\n  FOR(v, 1, N) {\n    LL(p);\n    G.add(p, v);\n  }\n\
    \  G.build();\n  TREE tree(G);\n\n  vi ANS(Q, -1);\n  vvc<pair<int, int>> query(N);\n\
    \  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(v, x);\n      query[v].eb(q,\
    \ x);\n    }\n    if (t == 1) {\n      LL(v);\n      query[v].eb(q, -1);\n   \
    \ }\n  }\n\n  FenwickTree<Group_Add<ll>> bit(Q);\n  vc<pair<int, int>> history;\n\
    \  ll base_sum = 0;\n\n  auto ADD = [&](int v) -> void {\n    base_sum += A[v];\n\
    \    for (auto&& [q, x]: query[v]) {\n      if (x != -1) {\n        bit.add(q,\
    \ x);\n        history.eb(q, x);\n      }\n    }\n  };\n  auto QUERY = [&](int\
    \ v) -> void {\n    for (auto&& [q, x]: query[v]) {\n      if (x == -1) ANS[q]\
    \ = base_sum + bit.sum(q);\n    }\n  };\n  auto RESET = [&]() -> void {\n    base_sum\
    \ = 0;\n    for (auto&& [q, x]: history) bit.add(q, -x);\n    history.clear();\n\
    \  };\n  DSU_on_Tree(tree, ADD, QUERY, RESET);\n  for (auto&& ans: ANS)\n    if\
    \ (ans != -1) print(ans);\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
- /verify/test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp.html
title: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
---
