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
    - https://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bfs01.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/base.hpp\"\n#include \"graph/shortest_path/bfs01.hpp\"\n\
    \n// \u9802\u70B9\u30D9\u30FC\u30B9\u306E\u91CD\u5FC3\u5206\u89E3\n// f(par, V,\
    \ indptr)\ntemplate <typename F>\nvoid centroid_decomposition_0_dfs(vc<int>& par,\
    \ vc<int>& vs, F f) {\n  const int N = len(par);\n  assert(N >= 1);\n  int c =\
    \ -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N) {\n    if (sz[i] >= ceil<int>(N, 2))\
    \ {\n      c = i;\n      break;\n    }\n    sz[par[i]] += sz[i];\n  }\n  vc<int>\
    \ color(N);\n  vc<int> V = {c};\n  int nc = 1;\n  FOR(v, 1, N) {\n    if (par[v]\
    \ == c) { V.eb(v), color[v] = nc++; }\n  }\n  if (c > 0) {\n    for (int a = par[c];\
    \ a != -1; a = par[a]) { color[a] = nc, V.eb(a); }\n    ++nc;\n  }\n  FOR(i, N)\
    \ {\n    if (i != c && color[i] == 0) color[i] = color[par[i]], V.eb(i);\n  }\n\
    \  vc<int> indptr(nc + 1);\n  FOR(i, N) indptr[1 + color[i]]++;\n  FOR(i, nc)\
    \ indptr[i + 1] += indptr[i];\n  vc<int> counter = indptr;\n  vc<int> ord(N);\n\
    \  for (auto& v: V) { ord[counter[color[v]]++] = v; }\n  vc<int> new_idx(N);\n\
    \  FOR(i, N) new_idx[ord[i]] = i;\n  vc<int> name(N);\n  FOR(i, N) name[new_idx[i]]\
    \ = vs[i];\n  {\n    vc<int> tmp(N, -1);\n    FOR(i, 1, N) {\n      int a = new_idx[i],\
    \ b = new_idx[par[i]];\n      if (a > b) swap(a, b);\n      tmp[b] = a;\n    }\n\
    \    swap(par, tmp);\n  }\n  f(par, name, indptr);\n  FOR(k, 1, nc) {\n    int\
    \ L = indptr[k], R = indptr[k + 1];\n    vc<int> par1(R - L, -1);\n    vc<int>\
    \ name1(R - L, -1);\n    name1[0] = name[0];\n    FOR(i, L, R) name1[i - L] =\
    \ name[i];\n    FOR(i, L, R) { par1[i - L] = max(par[i] - L, -1); }\n    centroid_decomposition_0_dfs(par1,\
    \ name1, f);\n  }\n}\n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    centroid_decomposition_1\uFF1A\u9577\u3055 1 \u4EE5\u4E0A\u306E\u30D1\u30B9\u5168\
    \u4F53\nf(par, V, L1, R1, L2, R2)\n[L1, R1): color 1 / [L2, R2): color 2\n*/\n\
    template <typename F>\nvoid centroid_decomposition_1_dfs(vc<int>& par, vc<int>\
    \ vs, F f) {\n  const int N = len(par);\n  assert(N > 1);\n  if (N == 2) {\n \
    \   vc<int> p = {-1, 0};\n    vc<int> v = {vs[0], vs[1]};\n    f(p, vs, 0, 1,\
    \ 1, 2);\n    return;\n  }\n  int c = -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N)\
    \ {\n    if (sz[i] >= ceil<int>(N, 2)) {\n      c = i;\n      break;\n    }\n\
    \    sz[par[i]] += sz[i];\n  }\n  vc<int> color(N, -1);\n  int take = 0;\n  vc<int>\
    \ ord(N, -1);\n  ord[c] = 0;\n  int p = 1;\n  FOR(v, 1, N) {\n    if (par[v] ==\
    \ c && take + sz[v] <= floor<int>(N - 1, 2)) { color[v] = 0, ord[v] = p++, take\
    \ += sz[v]; }\n  }\n  FOR(i, 1, N) {\n    if (color[par[i]] == 0) color[i] = 0,\
    \ ord[i] = p++;\n  }\n  int n0 = p - 1;\n  for (int a = par[c]; a != -1; a = par[a])\
    \ { color[a] = 1, ord[a] = p++; }\n  FOR(i, N) {\n    if (i != c && color[i] ==\
    \ -1) color[i] = 1, ord[i] = p++;\n  }\n  assert(p == N);\n  int n1 = N - 1 -\
    \ n0;\n  vc<int> par0(n0 + 1, -1), par1(n1 + 1, -1), par2(N, -1);\n  vc<int> V0(n0\
    \ + 1), V1(n1 + 1), V2(N);\n  FOR(v, N) {\n    int i = ord[v];\n    V2[i] = vs[v];\n\
    \    if (color[v] != 1) { V0[i] = vs[v]; }\n    if (color[v] != 0) { V1[max(i\
    \ - n0, 0)] = vs[v]; }\n  }\n  FOR(v, 1, N) {\n    int a = ord[v], b = ord[par[v]];\n\
    \    if (a > b) swap(a, b);\n    par2[b] = a;\n    if (color[v] != 1 && color[par[v]]\
    \ != 1) par0[b] = a;\n    if (color[v] != 0 && color[par[v]] != 0) par1[max(b\
    \ - n0, 0)] = max(a - n0, 0);\n  }\n  f(par2, V2, 1, 1 + n0, 1 + n0, 1 + n0 +\
    \ n1);\n  centroid_decomposition_1_dfs(par0, V0, f);\n  centroid_decomposition_1_dfs(par1,\
    \ V1, f);\n}\n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    f(par, V, color)\ncolor in [-1,0,1], -1 is virtual.\n*/\ntemplate <typename F>\n\
    void centroid_decomposition_2_dfs(vc<int>& par, vc<int>& vs, vc<int>& real, F\
    \ f) {\n  const int N = len(par);\n  assert(N > 1);\n  if (N == 2) {\n    if (real[0]\
    \ && real[1]) {\n      vc<int> color = {0, 1};\n      f(par, vs, color);\n   \
    \ }\n    return;\n  }\n  int c = -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N) {\n \
    \   if (sz[i] >= ceil<int>(N, 2)) {\n      c = i;\n      break;\n    }\n    sz[par[i]]\
    \ += sz[i];\n  }\n  vc<int> color(N, -1);\n  int take = 0;\n  vc<int> ord(N, -1);\n\
    \  ord[c] = 0;\n  int p = 1;\n  FOR(v, 1, N) {\n    if (par[v] == c && take +\
    \ sz[v] <= floor<int>(N - 1, 2)) { color[v] = 0, ord[v] = p++, take += sz[v];\
    \ }\n  }\n  FOR(i, 1, N) {\n    if (color[par[i]] == 0) color[i] = 0, ord[i] =\
    \ p++;\n  }\n  int n0 = p - 1;\n  for (int a = par[c]; a != -1; a = par[a]) {\
    \ color[a] = 1, ord[a] = p++; }\n  FOR(i, N) {\n    if (i != c && color[i] ==\
    \ -1) color[i] = 1, ord[i] = p++;\n  }\n  assert(p == N);\n  int n1 = N - 1 -\
    \ n0;\n  vc<int> par0(n0 + 1, -1), par1(n1 + 1, -1), par2(N, -1);\n  vc<int> V0(n0\
    \ + 1), V1(n1 + 1), V2(N);\n  vc<int> rea0(n0 + 1), rea1(n1 + 1), rea2(N);\n \
    \ FOR(v, N) {\n    int i = ord[v];\n    V2[i] = vs[v], rea2[i] = real[v];\n  \
    \  if (color[v] != 1) { V0[i] = vs[v], rea0[i] = real[v]; }\n    if (color[v]\
    \ != 0) { V1[max(i - n0, 0)] = vs[v], rea1[max(i - n0, 0)] = real[v]; }\n  }\n\
    \  FOR(v, 1, N) {\n    int a = ord[v], b = ord[par[v]];\n    if (a > b) swap(a,\
    \ b);\n    par2[b] = a;\n    if (color[v] != 1 && color[par[v]] != 1) par0[b]\
    \ = a;\n    if (color[v] != 0 && color[par[v]] != 0) par1[max(b - n0, 0)] = max(a\
    \ - n0, 0);\n  }\n  color.assign(N, -1);\n  FOR(i, 1, N) if (rea2[i]) color[i]\
    \ = (i <= n0 ? 0 : 1);\n  if (real[c]) color[0] = 2, rea0[0] = rea1[0] = rea2[0]\
    \ = 0;\n  f(par2, V2, color);\n  centroid_decomposition_2_dfs(par0, V0, rea0,\
    \ f);\n  centroid_decomposition_2_dfs(par1, V1, rea1, f);\n}\n\n// 0: f(par, V,\
    \ indptr)\n// 1: f(par, V, L1, R1, L2, R2)\n// 2: f(par, V, color)\ntemplate <int\
    \ MODE, typename GT, typename F>\nvoid centroid_decomposition(GT& G, F f) {\n\
    \  static_assert(!GT::is_directed);\n  const int N = G.N;\n  if (MODE != 0 &&\
    \ N == 1) return;\n  vc<int> V(N), par(N, -1);\n  int l = 0, r = 0;\n  V[r++]\
    \ = 0;\n  while (l < r) {\n    int v = V[l++];\n    for (auto& e: G[v]) {\n  \
    \    if (e.to != par[v]) V[r++] = e.to, par[e.to] = v;\n    }\n  }\n  assert(r\
    \ == N);\n  vc<int> new_idx(N);\n  FOR(i, N) new_idx[V[i]] = i;\n  vc<int> tmp(N,\
    \ -1);\n  FOR(i, 1, N) {\n    int j = par[i];\n    tmp[new_idx[i]] = new_idx[j];\n\
    \  }\n  swap(par, tmp);\n  static_assert(MODE == 0 || MODE == 1 || MODE == 2);\n\
    \  if constexpr (MODE == 0) { centroid_decomposition_0_dfs(par, V, f); }\n  elif\
    \ constexpr(MODE == 1) { centroid_decomposition_1_dfs(par, V, f); }\n  else {\n\
    \    vc<int> real(N, 1);\n    centroid_decomposition_2_dfs(par, V, real, f);\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graph/centroid_decomposition.hpp
- /library/graph/centroid_decomposition.hpp.html
title: graph/centroid_decomposition.hpp
---
