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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/pds/rollbackunionfind.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/pds/rollbackunionfind.hpp\"\
    \n#include \"ds/pds/rollbackarray.hpp\"\n#include \"ds/query/addremove_query.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A0, N);\n\n  using P = pair<int, int>;\n\
    \  AddRemove_Query<P, 1> X;\n  RollbackArray<ll> A(A0);\n\n  vc<int> query;\n\
    \  FOR(Q) {\n    LL(t);\n    if (t == 0) {\n      LL(u, v);\n      if (u > v)\
    \ swap(u, v);\n      X.add(len(query), {u, v});\n    }\n    if (t == 1) {\n  \
    \    LL(u, v);\n      if (u > v) swap(u, v);\n      X.remove(len(query), {u, v});\n\
    \    }\n    if (t == 2) {\n      LL(v, x);\n      X.add(len(query), {~v, x});\n\
    \    }\n    if (t == 3) {\n      LL(v);\n      query.eb(v);\n    }\n  }\n  RollbackUnionFind\
    \ uf(N);\n  // rollback_dfs\n  auto upd = X.calc(len(query));\n  vi ANS(len(query));\n\
    \  vc<int> I(len(upd));\n  iota(all(I), 0);\n  auto dfs = [&](auto& dfs, vc<int>&\
    \ upd_query_I, int begin, int end) -> void {\n    // snapshot\n    int a_time\
    \ = A.time();\n    int uf_time = uf.time();\n\n    vc<int> IL, IR;\n    int mid\
    \ = (begin + end) / 2;\n    for (auto&& i: upd_query_I) {\n      auto [a, b, X]\
    \ = upd[i];\n      if (a <= begin && end <= b) {\n        // X \u3067\u8868\u3055\
    \u308C\u308B update query \u3092\u51E6\u7406\u3059\u308B\n        auto [p, q]\
    \ = X;\n        if (p >= 0) {\n          int u = p, v = q;\n          u = uf[u],\
    \ v = uf[v];\n          if (u == v) continue;\n          uf.merge(u, v);\n   \
    \       int r = uf[u];\n          A.set(r, A.get(u) + A.get(v));\n        } else\
    \ {\n          int v = ~p, x = q;\n          v = uf[v];\n          A.set(v, A.get(v)\
    \ + x);\n        }\n        continue;\n      }\n      if (a < mid) IL.eb(i);\n\
    \      if (mid < b) IR.eb(i);\n    }\n    if (begin + 1 == end) {\n      int v\
    \ = query[begin];\n      ANS[begin] = A.get(uf[v]);\n    } else {\n      dfs(dfs,\
    \ IL, begin, mid);\n      dfs(dfs, IR, mid, end);\n    }\n    // rollback\n  \
    \  A.rollback(a_time);\n    uf.rollback(uf_time);\n  };\n  dfs(dfs, I, 0, len(query));\n\
    \  for (auto&& x: ANS) print(x);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  ll T = 1;\n\
    \  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
- /verify/test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp.html
title: test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
---
