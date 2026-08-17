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
    - https://codeforces.com/contest/468/problem/E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/path_cycle.hpp:\
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
    \    dp_path[i].resize(ceil<int>(i, 2) + 1);\n    FOR(k, len(dp_path[i - 2]))\
    \ { dp_path[i][k + 1] += dp_path[i - 2][k]; }\n  }\n  FOR(i, 3, N + 1) {\n   \
    \ dp_cyc[i] = dp_path[i - 1];\n    FOR(k, len(dp_path[i - 3])) dp_cyc[i][k + 1]\
    \ += dp_path[i - 3][k];\n  }\n\n  auto dfs = [&](auto& dfs, U s) -> vc<U> {\n\
    \    vc<U> res = {1};\n    pair<int, int> p = {-1, -1}; // (v, d)\n    FOR(v,\
    \ N) if (s >> v & 1) {\n      int d = popcnt(nbd[v] & s);\n      if (chmax(p.se,\
    \ d)) p.fi = v;\n      if (d == 0) {\n        res.eb(0);\n        FOR_R(i, len(res)\
    \ - 1) res[i + 1] += res[i];\n        s &= ~(U(1) << v);\n      }\n    }\n   \
    \ if (s == 0) return res;\n    int v = p.fi;\n    if (p.se >= 3) {\n      s &=\
    \ ~(U(1) << v);\n      auto f = dfs(dfs, s), g = dfs(dfs, s & ~nbd[v]);\n    \
    \  if (len(f) < len(g) + 1) f.resize(len(g) + 1);\n      FOR(i, len(g)) f[i +\
    \ 1] += g[i];\n      return convolution_naive(f, res);\n    }\n    // d <= 2,\
    \ path \u3068 cycle \u306E\u307F\n    vc<int> V;\n    FOR(v, N) if (s >> v & 1)\
    \ V.eb(v);\n    int n = len(V);\n    Graph<bool, 0> G(n);\n    FOR(i, n) {\n \
    \     U x = nbd[V[i]] & s;\n      while (x) {\n        int v = topbit(x);\n  \
    \      x ^= U(1) << v;\n        int j = LB(V, v);\n        if (i < j) G.add(i,\
    \ j);\n      }\n    }\n    G.build();\n    auto [paths, cycs] = path_cycle(G);\n\
    \    for (auto&& P: paths) res = convolution_naive(res, dp_path[len(P)]);\n  \
    \  for (auto&& C: cycs) res = convolution_naive(res, dp_cyc[len(C)]);\n    return\
    \ res;\n  };\n  auto res = dfs(dfs, (U(1) << N) - 1);\n  res.resize(N + 1);\n\
    \  return res;\n}\n\n// \u91CD\u307F\u306F\u9802\u70B9\u91CD\u307F\u306E\u7A4D\
    \n// https://codeforces.com/contest/468/problem/E\ntemplate <typename T, typename\
    \ GT>\nvc<T> count_independent_set_by_size_weighted(GT& G, vc<T> wt) {\n  using\
    \ U = u64;\n  const int N = G.N;\n  assert(N < 64);\n  if (N == 0) return {1};\n\
    \  vc<U> nbd(N);\n  FOR(v, N) for (auto&& e: G[v]) nbd[v] |= U(1) << e.to;\n\n\
    \  auto solve_path = [&](const vc<T>& A) -> vc<T> {\n    int N = len(A);\n   \
    \ vv(T, dp, 2, ceil<int>(N, 2) + 2);\n    dp[0][0] = 1;\n    FOR(i, N) {\n   \
    \   FOR_R(j, ceil<int>(i, 2) + 1) {\n        T a = dp[0][j];\n        T b = dp[1][j];\n\
    \        dp[0][j] = a + b, dp[1][j] = 0;\n        dp[1][j + 1] += a * A[i];\n\
    \      }\n    }\n    vc<T> f(ceil<int>(N, 2) + 1);\n    FOR(j, len(f)) f[j] =\
    \ dp[0][j] + dp[1][j];\n    return f;\n  };\n  auto solve_cycle = [&](const vc<T>&\
    \ A) -> vc<T> {\n    int N = len(A);\n    vvv(T, dp, 2, 2, ceil<int>(N, 2) + 2);\n\
    \    dp[0][0][0] = 1;\n    dp[1][1][1] = A[0];\n    FOR(i, 1, N) {\n      FOR(k,\
    \ 2) {\n        FOR_R(j, ceil<int>(i, 2) + 1) {\n          T a = dp[k][0][j];\n\
    \          T b = dp[k][1][j];\n          dp[k][0][j] = a + b, dp[k][1][j] = 0;\n\
    \          dp[k][1][j + 1] += a * A[i];\n        }\n      }\n    }\n    vc<T>\
    \ f(N / 2 + 1);\n    FOR(k, N / 2 + 1) { f[k] = dp[0][0][k] + dp[0][1][k] + dp[1][0][k];\
    \ }\n    return f;\n  };\n\n  auto dfs = [&](auto& dfs, U s) -> vc<T> {\n    vc<T>\
    \ res = {1};\n    pair<int, int> p = {-1, -1}; // (v, d)\n    FOR(v, N) if (s\
    \ >> v & 1) {\n      int d = popcnt(nbd[v] & s);\n      if (chmax(p.se, d)) p.fi\
    \ = v;\n      if (d == 0) {\n        res.eb(0);\n        FOR_R(i, len(res) - 1)\
    \ res[i + 1] += res[i] * wt[v];\n        s &= ~(U(1) << v);\n      }\n    }\n\
    \    if (s == 0) return res;\n    int v = p.fi;\n    if (p.se >= 3) {\n      s\
    \ &= ~(U(1) << v);\n      auto f = dfs(dfs, s), g = dfs(dfs, s & ~nbd[v]);\n \
    \     if (len(f) < len(g) + 1) f.resize(len(g) + 1);\n      FOR(i, len(g)) f[i\
    \ + 1] += g[i] * wt[v];\n      return convolution<T>(f, res);\n    }\n    // d\
    \ <= 2, path \u3068 cycle \u306E\u307F\n    vc<int> V;\n    FOR(v, N) if (s >>\
    \ v & 1) V.eb(v);\n    int n = len(V);\n    Graph<bool, 0> G(n);\n    FOR(i, n)\
    \ {\n      U x = nbd[V[i]] & s;\n      while (x) {\n        int v = topbit(x);\n\
    \        x ^= U(1) << v;\n        int j = LB(V, v);\n        if (i < j) G.add(i,\
    \ j);\n      }\n    }\n    G.build();\n    auto [paths, cycs] = path_cycle(G);\n\
    \    for (auto&& P: paths) {\n      vc<T> A;\n      for (auto& i: P) A.eb(wt[V[i]]);\n\
    \      res = convolution<T>(res, solve_path(A));\n    }\n    for (auto&& P: cycs)\
    \ {\n      vc<T> A;\n      for (auto& i: P) A.eb(wt[V[i]]);\n      res = convolution(res,\
    \ solve_cycle(A));\n    }\n    return res;\n  };\n  auto res = dfs(dfs, (U(1)\
    \ << N) - 1);\n  res.resize(N + 1);\n  return res;\n}\n"
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
