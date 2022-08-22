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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/hld.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/hld.hpp\"\n\n// add(v) : \u9802\u70B9 v \u306E\u30C7\u30FC\
    \u30BF\u3092\u8FFD\u52A0\u3059\u308B\n// query(v) : \u9802\u70B9 v \u306B\u304A\
    \u3051\u308B\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\n// reset() : \u30C7\u30FC\
    \u30BF\u304C\u7A7A\u306E\u72B6\u614B\u306B\u623B\u3059\u3002\n// \u30C7\u30FC\u30BF\
    \u69CB\u9020\u306B\u3088\u3063\u3066\u306F\u3001\u5C65\u6B74\u3092\u4F7F\u3063\
    \u3066\u9AD8\u901F\u306B reset \u3059\u308B\u3002\ntemplate <typename HLD, typename\
    \ F1, typename F2, typename F3>\nvoid DSU_on_Tree(HLD& hld, F1& add, F2& query,\
    \ F3& reset) {\n  auto& G = hld.G;\n\n  auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n    int heavy = -1;\n    // solve light edge\n    for (auto&& e: G[v]) {\n\
    \      if (e.to == hld.parent[v]) continue;\n      if (hld.head[e.to] == e.to)\
    \ {\n        dfs(dfs, e.to);\n      } else {\n        heavy = e.to;\n      }\n\
    \    }\n    // solve heavy edge (keep subtree data)\n    if (heavy != -1) { dfs(dfs,\
    \ heavy); }\n\n    // collect data in light subtree\n    for (auto&& e: G[v])\
    \ {\n      if (e.to == hld.parent[v]) continue;\n      if (e.to == heavy) continue;\n\
    \      FOR(idx, hld.LID[e.to], hld.RID[e.to]) { add(hld.V[idx]); }\n    }\n  \
    \  add(v);\n    query(v);\n\n    if (hld.head[v] == v) reset();\n  };\n\n  int\
    \ root = hld.V[0];\n  dfs(dfs, root);\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dsu_on_tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dsu_on_tree.hpp
layout: document
redirect_from:
- /library/graph/dsu_on_tree.hpp
- /library/graph/dsu_on_tree.hpp.html
title: graph/dsu_on_tree.hpp
---
