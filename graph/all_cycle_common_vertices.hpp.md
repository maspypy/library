---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/982/problem/F
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/strongly_connected_component.hpp\"\n#include \"graph/toposort.hpp\"\
    \n#include \"graph/find_cycle.hpp\"\n\n// v \u3092\u901A\u308B\u30B5\u30A4\u30AF\
    \u30EB\u304C\u5B58\u5728\u3057, v \u3092\u6D88\u3059\u3068 DAG \u306B\u306A\u308B\
    \u3088\u3046\u306A v \u3092\u6607\u9806\u5168\u5217\u6319\u3059\u308B\n// v \u3092\
    \u6D88\u3059\u3068 \u975EDAG -> DAG\n// loop \u306F\u306A\u3044\u3082\u306E\u3068\
    \u3057\u305F\u304B\u3082\n// https://codeforces.com/contest/982/problem/F\ntemplate\
    \ <typename GT>\nvc<int> all_cycle_common_vertices(GT& G, bool strongly_connected)\
    \ {\n  static_assert(GT::is_directed);\n  int N = G.N;\n  if (!strongly_connected)\
    \ {\n    auto [nc, comp] = strongly_connected_component(G);\n    vc<int> sz(nc);\n\
    \    FOR(v, N) sz[comp[v]]++;\n    int k = -1;\n    FOR(i, nc) {\n      if (sz[i]\
    \ >= 2) {\n        if (k != -1) return {};\n        k = i;\n      }\n    }\n \
    \   if (k == -1) return {};  // DAG\n    vc<int> V;\n    FOR(v, N) if (comp[v]\
    \ == k) V.eb(v);\n    Graph<int, 1> H = G.rearrange(V);\n    vc<int> ANS = all_cycle_common_vertices(H,\
    \ true);\n    for (int& x : ANS) x = V[x];\n    return ANS;\n  }\n\n  assert(strongly_connected);\n\
    \  if (N == 1) return {};  // DAG\n\n  // main cycle\n  vc<int> C = find_cycle_directed(G).fi;\n\
    \n  int n = len(C);\n  vc<int> idx(N, -1);\n  FOR(i, n) idx[C[i]] = i;\n\n  vc<int>\
    \ other;\n  FOR(i, N) if (idx[i] == -1) other.eb(i);\n  if (len(other)) {\n  \
    \  Graph<int, 1> H = G.rearrange(other);\n    if (toposort(H).empty()) return\
    \ {};  // two vertex disjoint cycle\n  }\n\n  vc<int> F(N + 1);\n  auto arc =\
    \ [&](int s, int t) -> void {\n    if (s < t) {\n      F[s + 1]++, F[t]--;\n \
    \   } else {\n      F[s + 1]++, F[n]--;\n      F[0]++, F[t]--;\n    }\n  };\n\n\
    \  vc<int> dp(N, -2);\n\n  FOR(s, n) {\n    auto eval = [&](int i) -> int {\n\
    \      if (i < 0) return i;\n      return (s < i ? i - s : i + n - s);\n    };\n\
    \n    auto dfs = [&](auto& dfs, int v) -> int {\n      if (idx[v] != -1) return\
    \ idx[v];\n      if (dp[v] != -2) return dp[v];\n      int ans = -1;\n      for\
    \ (auto& e : G[v]) {\n        int i = dfs(dfs, e.to);\n        if (eval(ans) <\
    \ eval(i)) ans = i;\n      }\n      return dp[v] = ans;\n    };\n    int i = -1;\n\
    \    for (auto& e : G[C[s]]) {\n      int j = dfs(dfs, e.to);\n      if (eval(i)\
    \ < eval(j)) i = j;\n    }\n    if (i != -1) arc(s, i);\n  }\n  FOR(i, n) F[i\
    \ + 1] += F[i];\n  F.pop_back();\n\n  vc<int> ANS;\n  FOR(i, n) if (F[i] == 0)\
    \ ANS.eb(C[i]);\n\n  if (ANS.empty()) return {};\n  vc<int> V;\n  FOR(v, N) if\
    \ (v != ANS[0]) V.eb(v);\n  {\n    Graph<int, 1> H = G.rearrange(V);\n    if (toposort(H).empty())\
    \ return {};\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/all_cycle_common_vertices.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/all_cycle_common_vertices.hpp
layout: document
redirect_from:
- /library/graph/all_cycle_common_vertices.hpp
- /library/graph/all_cycle_common_vertices.hpp.html
title: graph/all_cycle_common_vertices.hpp
---
