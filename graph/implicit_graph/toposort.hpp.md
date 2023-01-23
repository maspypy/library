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
  bundledCode: "#line 1 \"graph/implicit_graph/toposort.hpp\"\n// https://codeforces.com/contest/798/problem/E\r\
    \n// toposort \u306E\u5019\u88DC\u3092\u3072\u3068\u3064\u51FA\u529B\u3059\u308B\
    \u3002\u30C1\u30A7\u30C3\u30AF\u306F\u3057\u306A\u3044\u3002\r\n// \u967D\u306B\
    \u30B0\u30E9\u30D5\u3092\u4F5C\u3089\u305A\u3001\u4F55\u3089\u304B\u306E\u30C7\
    \u30FC\u30BF\u69CB\u9020\u3067\u672A\u8A2A\u554F\u306E\u884C\u304D\u5148\u3092\
    \u63A2\u3059\u60F3\u5B9A\u3002\r\n// set_used(v)\uFF1Av \u3092\u4F7F\u7528\u6E08\
    \u306B\u5909\u66F4\u3059\u308B\r\n// find_unused(v)\uFF1Av \u306E\u884C\u304D\u5148\
    \u3092\u63A2\u3059\u3002\u306A\u3051\u308C\u3070 -1 \u3092\u8FD4\u3059\u3053\u3068\
    \u3002\r\ntemplate <typename F1, typename F2>\r\nvc<int> toposort(int N, F1 set_used,\
    \ F2 find_unused) {\r\n  vc<int> V;\r\n  vc<bool> done(N);\r\n  auto dfs = [&](auto\
    \ self, ll v) -> void {\r\n    set_used(v);\r\n    done[v] = 1;\r\n    while (1)\
    \ {\r\n      int to = find_unused(v);\r\n      if (to == -1) break;\r\n      self(self,\
    \ to);\r\n    }\r\n    V.eb(v);\r\n  };\r\n  FOR(v, N) if (!done[v]) dfs(dfs,\
    \ v);\r\n  return V;\r\n}\r\n"
  code: "// https://codeforces.com/contest/798/problem/E\r\n// toposort \u306E\u5019\
    \u88DC\u3092\u3072\u3068\u3064\u51FA\u529B\u3059\u308B\u3002\u30C1\u30A7\u30C3\
    \u30AF\u306F\u3057\u306A\u3044\u3002\r\n// \u967D\u306B\u30B0\u30E9\u30D5\u3092\
    \u4F5C\u3089\u305A\u3001\u4F55\u3089\u304B\u306E\u30C7\u30FC\u30BF\u69CB\u9020\
    \u3067\u672A\u8A2A\u554F\u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u60F3\u5B9A\
    \u3002\r\n// set_used(v)\uFF1Av \u3092\u4F7F\u7528\u6E08\u306B\u5909\u66F4\u3059\
    \u308B\r\n// find_unused(v)\uFF1Av \u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u3002\
    \u306A\u3051\u308C\u3070 -1 \u3092\u8FD4\u3059\u3053\u3068\u3002\r\ntemplate <typename\
    \ F1, typename F2>\r\nvc<int> toposort(int N, F1 set_used, F2 find_unused) {\r\
    \n  vc<int> V;\r\n  vc<bool> done(N);\r\n  auto dfs = [&](auto self, ll v) ->\
    \ void {\r\n    set_used(v);\r\n    done[v] = 1;\r\n    while (1) {\r\n      int\
    \ to = find_unused(v);\r\n      if (to == -1) break;\r\n      self(self, to);\r\
    \n    }\r\n    V.eb(v);\r\n  };\r\n  FOR(v, N) if (!done[v]) dfs(dfs, v);\r\n\
    \  return V;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/implicit_graph/toposort.hpp
  requiredBy: []
  timestamp: '2023-01-23 17:26:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/implicit_graph/toposort.hpp
layout: document
redirect_from:
- /library/graph/implicit_graph/toposort.hpp
- /library/graph/implicit_graph/toposort.hpp.html
title: graph/implicit_graph/toposort.hpp
---
