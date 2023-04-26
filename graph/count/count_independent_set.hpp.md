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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/path_cycle.hpp\"\n#include \"poly/convolution.hpp\"\n\n\
    // \u72EC\u7ACB\u96C6\u5408\u6570\u3048\u4E0A\u3052\u3002\u7A7A\u96C6\u5408\u3082\
    \u8A8D\u3081\u308B\u3002N 1.381^N \u7A0B\u5EA6\u3002\ntemplate <typename GT>\n\
    u64 count_independent_set(GT& G) {\n  using U = u64;\n  const int N = G.N;\n \
    \ assert(N < 64);\n  if (N == 0) return 1;\n  vc<U> nbd(N);\n  FOR(v, N) for (auto&&\
    \ e: G[v]) nbd[v] |= U(1) << e.to;\n\n  vc<U> dp_path(N + 1), dp_cyc(N + 1);\n\
    \  dp_path[0] = 1, dp_path[1] = 2;\n  FOR(i, 2, N + 1) dp_path[i] = dp_path[i\
    \ - 1] + dp_path[i - 2];\n  FOR(i, 3, N + 1) dp_cyc[i] = dp_path[i - 1] + dp_path[i\
    \ - 3];\n\n  auto dfs = [&](auto& dfs, U s) -> U {\n    int deg0 = 0;\n    pair<int,\
    \ int> p = {-1, -1}; // (v, d)\n    FOR(v, N) if (s >> v & 1) {\n      int d =\
    \ popcnt(nbd[v] & s);\n      if (chmax(p.se, d)) p.fi = v;\n      if (d == 0)\
    \ {\n        ++deg0;\n        s &= ~(U(1) << v);\n      }\n    }\n    if (s ==\
    \ 0) return U(1) << deg0;\n    int v = p.fi;\n    if (p.se >= 3) {\n      s &=\
    \ ~(U(1) << v);\n      return (dfs(dfs, s) + dfs(dfs, s & ~nbd[v])) << deg0;\n\
    \    }\n    // d <= 2, path \u3068 cycle \u306E\u307F\n    vc<int> V;\n    FOR(v,\
    \ N) if (s >> v & 1) V.eb(v);\n    int n = len(V);\n    Graph<bool, 0> G(n);\n\
    \    FOR(i, n) {\n      U x = nbd[V[i]] & s;\n      while (x) {\n        int v\
    \ = topbit(x);\n        x ^= U(1) << v;\n        int j = LB(V, v);\n        if\
    \ (i < j) G.add(i, j);\n      }\n    }\n    G.build();\n    auto [paths, cycs]\
    \ = path_cycle(G);\n    U res = 1;\n    for (auto&& P: paths) res *= dp_path[len(P)];\n\
    \    for (auto&& C: cycs) res *= dp_cyc[len(C)];\n    return res << deg0;\n  };\n\
    \  return dfs(dfs, (U(1) << N) - 1);\n}\n\n// \u72EC\u7ACB\u96C6\u5408\u6570\u3048\
    \u4E0A\u3052\u3002\u7A7A\u96C6\u5408\u3082\u8A8D\u3081\u308B\u3002N 1.381^N \u7A0B\
    \u5EA6\u3002\ntemplate <typename GT>\nvc<u64> count_independent_set_by_size(GT&\
    \ G) {\n  using U = u64;\n  const int N = G.N;\n  assert(N < 64);\n  if (N ==\
    \ 0) return {1};\n  vc<U> nbd(N);\n  FOR(v, N) for (auto&& e: G[v]) nbd[v] |=\
    \ U(1) << e.to;\n\n  vvc<U> dp_path(N + 1), dp_cyc(N + 1);\n  dp_path[0] = {1},\
    \ dp_path[1] = {1, 1};\n  FOR(i, 2, N + 1) {\n    dp_path[i] = dp_path[i - 1];\n\
    \    dp_path[i].resize(ceil(i, 2) + 1);\n    FOR(k, len(dp_path[i - 2])) { dp_path[i][k\
    \ + 1] += dp_path[i - 2][k]; }\n  }\n  FOR(i, 3, N + 1) {\n    dp_cyc[i] = dp_path[i\
    \ - 1];\n    FOR(k, len(dp_path[i - 3])) dp_cyc[i][k + 1] += dp_path[i - 3][k];\n\
    \  }\n\n  auto dfs = [&](auto& dfs, U s) -> vc<U> {\n    vc<U> res = {1};\n  \
    \  pair<int, int> p = {-1, -1}; // (v, d)\n    FOR(v, N) if (s >> v & 1) {\n \
    \     int d = popcnt(nbd[v] & s);\n      if (chmax(p.se, d)) p.fi = v;\n     \
    \ if (d == 0) {\n        res.eb(0);\n        FOR_R(i, len(res) - 1) res[i + 1]\
    \ += res[i];\n        s &= ~(U(1) << v);\n      }\n    }\n    if (s == 0) return\
    \ res;\n    int v = p.fi;\n    if (p.se >= 3) {\n      s &= ~(U(1) << v);\n  \
    \    auto f = dfs(dfs, s), g = dfs(dfs, s & ~nbd[v]);\n      if (len(f) < len(g)\
    \ + 1) f.resize(len(g) + 1);\n      FOR(i, len(g)) f[i + 1] += g[i];\n      return\
    \ convolution_naive(f, res);\n    }\n    // d <= 2, path \u3068 cycle \u306E\u307F\
    \n    vc<int> V;\n    FOR(v, N) if (s >> v & 1) V.eb(v);\n    int n = len(V);\n\
    \    Graph<bool, 0> G(n);\n    FOR(i, n) {\n      U x = nbd[V[i]] & s;\n     \
    \ while (x) {\n        int v = topbit(x);\n        x ^= U(1) << v;\n        int\
    \ j = LB(V, v);\n        if (i < j) G.add(i, j);\n      }\n    }\n    G.build();\n\
    \    auto [paths, cycs] = path_cycle(G);\n    for (auto&& P: paths) res = convolution_naive(res,\
    \ dp_path[len(P)]);\n    for (auto&& C: cycs) res = convolution_naive(res, dp_cyc[len(C)]);\n\
    \    return res;\n  };\n  auto res = dfs(dfs, (U(1) << N) - 1);\n  res.resize(N\
    \ + 1);\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_independent_set.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_independent_set.hpp
layout: document
redirect_from:
- /library/graph/count/count_independent_set.hpp
- /library/graph/count/count_independent_set.hpp.html
title: graph/count/count_independent_set.hpp
---
