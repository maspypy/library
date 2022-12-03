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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/base.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n\n\
    template <typename T>\nGraph<T, 0> Manhattan_MST(vc<pair<T, T>>& XY) {\n  int\
    \ N = XY.size();\n  vc<tuple<T, int, int>> dat;\n  dat.reserve(4 * N);\n  vc<int>\
    \ idx(N);\n  iota(all(idx), 0);\n\n  FOR(a, 2) {\n    for (auto&& [x, y]: XY)\
    \ x = -x;\n    FOR(b, 2) {\n      for (auto&& [x, y]: XY) swap(x, y);\n      sort(all(idx),\
    \ [&](const int& i, const int& j) -> bool {\n        return XY[i].fi + XY[i].se\
    \ < XY[j].fi + XY[j].se;\n      });\n\n      map<T, int> MP;\n      for (const\
    \ int i: idx) {\n        auto& [x, y] = XY[i];\n        for (auto it = MP.lower_bound(-y);\
    \ it != MP.end(); it = MP.erase(it)) {\n          const int j = it->se;\n    \
    \      auto& [xj, yj] = XY[j];\n          const int dx = x - xj;\n          const\
    \ int dy = y - yj;\n          if (dy > dx) break;\n          dat.eb(dx + dy, i,\
    \ j);\n        }\n        MP[-y] = i;\n      }\n    }\n  }\n\n  sort(all(dat));\n\
    \  Graph<T, 0> G(N);\n  UnionFind uf(N);\n  for (auto&& [cost, i, j]: dat) {\n\
    \    if (uf.merge(i, j)) G.add(i, j, cost);\n  }\n  G.build();\n  return G;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/manhattan_mst.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/manhattan_mst.hpp
layout: document
redirect_from:
- /library/geo/manhattan_mst.hpp
- /library/geo/manhattan_mst.hpp.html
title: geo/manhattan_mst.hpp
---
