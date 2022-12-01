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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/unionfind.hpp\"\n\n// \u9802\u70B9\u3092\u524A\u9664\u3057\u306A\
    \u304C\u3089\u3001\u9069\u5F53\u306A\u30C7\u30FC\u30BF\u69CB\u9020\u306B\u3088\
    \u308A\u6B21\u306E\u8FBA\u3092\u63A2\u3059\u3002\n// \u4E2D\u8EAB\u306F\u305F\u3060\
    \u306E bfs \u3057\u3066\u3044\u308B\u306E\u3067\u300101 \u6700\u77ED\u8DEF\u306B\
    \u3082\u6D41\u7528\u53EF\u80FD\ntemplate <typename F1, typename F2>\nUnionFind\
    \ online_unionfind(int N, F1 set_used, F2 find_unused) {\n  UnionFind uf(N);\n\
    \  vc<bool> done(N);\n  deque<int> que;\n  FOR(v, N) if (!done[v]) {\n    que.eb(v);\n\
    \    done[v] = 1;\n    set_used(v);\n    while (!que.empty()) {\n      int x =\
    \ que.front();\n      que.pop_front();\n      set_used(x);\n      done[x] = 1;\n\
    \      while (1) {\n        int to = find_unused(x);\n        if (to == -1) break;\n\
    \        uf.merge(v, to);\n        que.eb(to);\n        done[to] = 1;\n      \
    \  set_used(to);\n      }\n    }\n  }\n  return uf;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/online_unionfind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/online_unionfind.hpp
layout: document
redirect_from:
- /library/graph/online_unionfind.hpp
- /library/graph/online_unionfind.hpp.html
title: graph/online_unionfind.hpp
---
