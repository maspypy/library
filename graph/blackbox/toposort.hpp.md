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
    - https://codeforces.com/contest/1158/problem/C
  bundledCode: "#line 1 \"graph/blackbox/toposort.hpp\"\n// set_used(v)\uFF1Av \u3092\
    \u4F7F\u7528\u6E08\u306B\u5909\u66F4\u3059\u308B\r\n// find_unused(v)\uFF1Av \u306E\
    \u884C\u304D\u5148\u3092\u63A2\u3059\u3002\u306A\u3051\u308C\u3070 -1 \u3092\u8FD4\
    \u3059\u3053\u3068\u3002\r\n// https://codeforces.com/contest/1158/problem/C\r\
    \ntemplate <typename F0, typename F1, typename F2>\r\nvc<int> blackbox_toposort(int\
    \ N, F0 init, F1 set_used, F2 find_unused,\r\n                          bool check\
    \ = true) {\r\n  init();\r\n  vc<int> V;\r\n  vc<bool> done(N);\r\n  auto dfs\
    \ = [&](auto& dfs, int v) -> void {\r\n    set_used(v);\r\n    done[v] = 1;\r\n\
    \    while (1) {\r\n      int to = find_unused(v);\r\n      if (to == -1) break;\r\
    \n      dfs(dfs, to);\r\n    }\r\n    V.eb(v);\r\n  };\r\n  FOR(v, N) if (!done[v])\
    \ dfs(dfs, v);\r\n  reverse(all(V));\r\n  if (check) {\r\n    init();\r\n    FOR_R(i,\
    \ N) {\r\n      int v = V[i];\r\n      if (find_unused(v) != -1) {\r\n       \
    \ return {};\r\n      }\r\n      set_used(v);\r\n    }\r\n  }\r\n  return V;\r\
    \n}\r\n"
  code: "// set_used(v)\uFF1Av \u3092\u4F7F\u7528\u6E08\u306B\u5909\u66F4\u3059\u308B\
    \r\n// find_unused(v)\uFF1Av \u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u3002\u306A\
    \u3051\u308C\u3070 -1 \u3092\u8FD4\u3059\u3053\u3068\u3002\r\n// https://codeforces.com/contest/1158/problem/C\r\
    \ntemplate <typename F0, typename F1, typename F2>\r\nvc<int> blackbox_toposort(int\
    \ N, F0 init, F1 set_used, F2 find_unused,\r\n                          bool check\
    \ = true) {\r\n  init();\r\n  vc<int> V;\r\n  vc<bool> done(N);\r\n  auto dfs\
    \ = [&](auto& dfs, int v) -> void {\r\n    set_used(v);\r\n    done[v] = 1;\r\n\
    \    while (1) {\r\n      int to = find_unused(v);\r\n      if (to == -1) break;\r\
    \n      dfs(dfs, to);\r\n    }\r\n    V.eb(v);\r\n  };\r\n  FOR(v, N) if (!done[v])\
    \ dfs(dfs, v);\r\n  reverse(all(V));\r\n  if (check) {\r\n    init();\r\n    FOR_R(i,\
    \ N) {\r\n      int v = V[i];\r\n      if (find_unused(v) != -1) {\r\n       \
    \ return {};\r\n      }\r\n      set_used(v);\r\n    }\r\n  }\r\n  return V;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/blackbox/toposort.hpp
  requiredBy: []
  timestamp: '2025-07-18 14:23:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/blackbox/toposort.hpp
layout: document
redirect_from:
- /library/graph/blackbox/toposort.hpp
- /library/graph/blackbox/toposort.hpp.html
title: graph/blackbox/toposort.hpp
---
