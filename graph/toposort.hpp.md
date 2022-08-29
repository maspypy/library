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
    - https://codeforces.com/contest/798/problem/E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/degree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/base.hpp\"\n#include \"graph/degree.hpp\"\n\n// DAG \u3058\
    \u3083\u306A\u304B\u3063\u305F\u3089\u7A7A\u914D\u5217\n// \u8F9E\u66F8\u9806\u6700\
    \u5C0F\u3082\u3067\u304D\u308B\uFF1AO(NlogN) \u2192 abc223\ntemplate <typename\
    \ Graph>\nvc<int> toposort(Graph& G, bool lex_min = false) {\n  assert(G.is_prepared());\n\
    \  assert(G.is_directed());\n  auto [indeg, outdeg] = degree_inout(G);\n  if (!lex_min)\
    \ {\n    vc<int> V;\n    ll N = G.N;\n    FOR(v, N) if (indeg[v] == 0) V.eb(v);\n\
    \    ll p = 0;\n    while (p < len(V)) {\n      auto v = V[p++];\n      for (auto&&\
    \ e: G[v]) {\n        if (--indeg[e.to] == 0) V.eb(e.to);\n      }\n    }\n  \
    \  if (len(V) < N) { V.clear(); }\n    return V;\n  } else {\n    pqg<int> que;\n\
    \    vc<int> V;\n    ll N = G.N;\n    FOR(v, N) if (indeg[v] == 0) que.push(v);\n\
    \    while (len(que)) {\n      auto v = que.top();\n      que.pop();\n      V.eb(v);\n\
    \      for (auto&& e: G[v]) {\n        if (--indeg[e.to] == 0) que.push(e.to);\n\
    \      }\n    }\n    if (len(V) < N) { V.clear(); }\n    return V;\n  }\n}\n\n\
    // https://codeforces.com/contest/798/problem/E\n// toposort \u306E\u5019\u88DC\
    \u3092\u3072\u3068\u3064\u51FA\u529B\u3059\u308B\u3002\u30C1\u30A7\u30C3\u30AF\
    \u306F\u3057\u306A\u3044\u3002\n// \u967D\u306B\u30B0\u30E9\u30D5\u3092\u4F5C\u3089\
    \u305A\u3001\u4F55\u3089\u304B\u306E\u30C7\u30FC\u30BF\u69CB\u9020\u3067\u672A\
    \u8A2A\u554F\u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u60F3\u5B9A\u3002\n// set_used(v)\uFF1A\
    v \u3092\u4F7F\u7528\u6E08\u306B\u5909\u66F4\u3059\u308B\n// find_unused(v)\uFF1A\
    v \u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u3002\u306A\u3051\u308C\u3070 -1\
    \ \u3092\u8FD4\u3059\u3053\u3068\u3002\ntemplate <typename F1, typename F2>\n\
    vc<int> toposort(int N, F1 set_used, F2 find_unused) {\n  vc<int> V;\n  vc<bool>\
    \ done(N);\n  auto dfs = [&](auto self, ll v) -> void {\n    set_used(v);\n  \
    \  done[v] = 1;\n    while (1) {\n      int to = find_unused(v);\n      if (to\
    \ == -1) break;\n      self(self, to);\n    }\n    V.eb(v);\n  };\n  FOR(v, N)\
    \ if (!done[v]) dfs(dfs, v);\n  return V;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/toposort.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/toposort.hpp
layout: document
redirect_from:
- /library/graph/toposort.hpp
- /library/graph/toposort.hpp.html
title: graph/toposort.hpp
---
