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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bfs01.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/centroid_decomposition.hpp\"\n\n// \u8DDD\u96E2 0 \u306F\
    \u542B\u3081\u3066\u3044\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\uFF01\ntemplate\
    \ <typename GT, bool WEIGHTED>\nstruct Contour_Query_Range {\n  using WT = std::conditional_t<WEIGHTED,\
    \ typename GT::cost_type, int>;\n  int N;\n  vc<int> V;\n  vc<int> comp;\n  vc<WT>\
    \ dep;\n  vc<int> info_idx, info_indptr;\n  vc<int> comp_range;\n\n  Contour_Query_Range(GT&\
    \ G0) : N(G0.N) {\n    int p = 0;\n    comp_range = {0};\n    auto f = [&](vc<int>&\
    \ par, vc<int>& vs, vc<int>& color) -> void {\n      const int n = len(par);\n\
    \      vc<WT> dist(n);\n      FOR(v, 1, n) {\n        static_assert(!WEIGHTED);\n\
    \        dist[v] = dist[par[v]] + 1;\n      }\n      FOR(c1, 2) {\n        vc<int>\
    \ A, B;\n        FOR(v, n) {\n          if (color[v] == c1) A.eb(v);\n       \
    \   if (color[v] > c1) B.eb(v);\n        }\n        if (A.empty() || B.empty())\
    \ continue;\n        int mx_A = 0, mx_B = 0;\n        for (auto& v: A) {\n   \
    \       V.eb(vs[v]), comp.eb(p), dep.eb(dist[v]), chmax(mx_A, dist[v]);\n    \
    \    }\n        comp_range.eb(comp_range.back() + mx_A + 1), ++p;\n        for\
    \ (auto& v: B) {\n          V.eb(vs[v]), comp.eb(p), dep.eb(dist[v]), chmax(mx_B,\
    \ dist[v]);\n        }\n        comp_range.eb(comp_range.back() + mx_B + 1), ++p;\n\
    \      }\n    };\n    centroid_decomposition<2>(G0, f);\n    info_indptr.assign(N\
    \ + 1, 0);\n    for (auto& v: V) info_indptr[1 + v]++;\n    FOR(v, N) { info_indptr[v\
    \ + 1] += info_indptr[v]; }\n    auto counter = info_indptr;\n    info_idx.resize(info_indptr.back());\n\
    \    FOR(i, len(V)) { info_idx[counter[V[i]]++] = i; }\n  }\n\n  int size() {\
    \ return comp_range.back(); }\n\n  vc<pair<int, int>> get_contour_range(int v,\
    \ WT l, WT r) {\n    vc<pair<int, int>> res;\n    FOR(k, info_indptr[v], info_indptr[v\
    \ + 1]) {\n      int idx = info_idx[k];\n      int p = comp[idx] ^ 1;\n      int\
    \ lo = l - dep[idx], hi = r - dep[idx];\n      int L = comp_range[p], R = comp_range[p\
    \ + 1];\n      int n = R - L;\n      chmax(lo, 0), chmin(hi, n);\n      if (lo\
    \ < hi) { res.eb(comp_range[p] + lo, comp_range[p] + hi); }\n    }\n    return\
    \ res;\n  }\n\n  vc<int> get_indices(int v) {\n    vc<int> res;\n    FOR(k, info_indptr[v],\
    \ info_indptr[v + 1]) {\n      int idx = info_idx[k];\n      int p = comp[idx];\n\
    \      res.eb(comp_range[p] + dep[idx]);\n    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/contour_query_range.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/contour_query_range.hpp
layout: document
redirect_from:
- /library/graph/ds/contour_query_range.hpp
- /library/graph/ds/contour_query_range.hpp.html
title: graph/ds/contour_query_range.hpp
---
