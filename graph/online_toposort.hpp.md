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
  bundledCode: "#line 1 \"graph/online_toposort.hpp\"\n// https://codeforces.com/contest/798/problem/E\r\
    \n// \u967D\u306B\u30B0\u30E9\u30D5\u3092\u4F5C\u3089\u305A\u3001\u4F55\u3089\u304B\
    \u306E\u30C7\u30FC\u30BF\u69CB\u9020\u3067\u672A\u8A2A\u554F\u306E\u884C\u304D\
    \u5148\u3092\u63A2\u3059\u60F3\u5B9A\u3002\r\n// set_used(v)\uFF1Av \u3092\u4F7F\
    \u7528\u6E08\u306B\u5909\u66F4\u3059\u308B\r\n// find_unused(v)\uFF1Av \u306E\u884C\
    \u304D\u5148\u3092\u63A2\u3059\u3002\u306A\u3051\u308C\u3070 -1 \u3092\u8FD4\u3059\
    \u3053\u3068\u3002\r\ntemplate <typename F0, typename F1, typename F2>\r\nvc<int>\
    \ online_toposort(int N, F0 init, F1 set_used, F2 find_unused,\r\n           \
    \             bool check = true) {\r\n  init();\r\n  vc<int> V;\r\n  vc<bool>\
    \ done(N);\r\n  auto dfs = [&](auto self, ll v) -> void {\r\n    set_used(v);\r\
    \n    done[v] = 1;\r\n    while (1) {\r\n      int to = find_unused(v);\r\n  \
    \    if (to == -1) break;\r\n      self(self, to);\r\n    }\r\n    V.eb(v);\r\n\
    \  };\r\n  FOR(v, N) if (!done[v]) dfs(dfs, v);\r\n  if (check) {\r\n    init();\r\
    \n    for (auto&& v: V) {\r\n      set_used(v);\r\n      int to = find_unused(v);\r\
    \n      if (to != -1) {\r\n        // not DAG\r\n        return {};\r\n      }\r\
    \n    }\r\n  }\r\n  reverse(all(V));\r\n  return V;\r\n}\r\n"
  code: "// https://codeforces.com/contest/798/problem/E\r\n// \u967D\u306B\u30B0\u30E9\
    \u30D5\u3092\u4F5C\u3089\u305A\u3001\u4F55\u3089\u304B\u306E\u30C7\u30FC\u30BF\
    \u69CB\u9020\u3067\u672A\u8A2A\u554F\u306E\u884C\u304D\u5148\u3092\u63A2\u3059\
    \u60F3\u5B9A\u3002\r\n// set_used(v)\uFF1Av \u3092\u4F7F\u7528\u6E08\u306B\u5909\
    \u66F4\u3059\u308B\r\n// find_unused(v)\uFF1Av \u306E\u884C\u304D\u5148\u3092\u63A2\
    \u3059\u3002\u306A\u3051\u308C\u3070 -1 \u3092\u8FD4\u3059\u3053\u3068\u3002\r\
    \ntemplate <typename F0, typename F1, typename F2>\r\nvc<int> online_toposort(int\
    \ N, F0 init, F1 set_used, F2 find_unused,\r\n                        bool check\
    \ = true) {\r\n  init();\r\n  vc<int> V;\r\n  vc<bool> done(N);\r\n  auto dfs\
    \ = [&](auto self, ll v) -> void {\r\n    set_used(v);\r\n    done[v] = 1;\r\n\
    \    while (1) {\r\n      int to = find_unused(v);\r\n      if (to == -1) break;\r\
    \n      self(self, to);\r\n    }\r\n    V.eb(v);\r\n  };\r\n  FOR(v, N) if (!done[v])\
    \ dfs(dfs, v);\r\n  if (check) {\r\n    init();\r\n    for (auto&& v: V) {\r\n\
    \      set_used(v);\r\n      int to = find_unused(v);\r\n      if (to != -1) {\r\
    \n        // not DAG\r\n        return {};\r\n      }\r\n    }\r\n  }\r\n  reverse(all(V));\r\
    \n  return V;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/online_toposort.hpp
  requiredBy: []
  timestamp: '2022-05-06 13:21:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/online_toposort.hpp
layout: document
redirect_from:
- /library/graph/online_toposort.hpp
- /library/graph/online_toposort.hpp.html
title: graph/online_toposort.hpp
---
