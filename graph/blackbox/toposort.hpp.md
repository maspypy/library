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
    - https://github.com/maspypy/library/blob/main/graph/blackbox/toposort.hpp
  bundledCode: "#line 1 \"graph/blackbox/toposort.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/blackbox/toposort.hpp\n\
    // set_used(v)\uFF1Av \u3092\u4F7F\u7528\u6E08\u306B\u5909\u66F4\u3059\u308B\n\
    // find_unused(v)\uFF1Av \u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u3002\u306A\
    \u3051\u308C\u3070 -1 \u3092\u8FD4\u3059\u3053\u3068\u3002\n// https://codeforces.com/contest/1158/problem/C\n\
    template <typename F0, typename F1, typename F2>\nvc<int> blackbox_toposort(int\
    \ N, F0 init, F1 set_used, F2 find_unused,\n                          bool check\
    \ = true) {\n  init();\n  vc<int> V;\n  vc<bool> done(N);\n  auto dfs = [&](auto&\
    \ dfs, int v) -> void {\n    set_used(v);\n    done[v] = 1;\n    while (1) {\n\
    \      int to = find_unused(v);\n      if (to == -1) break;\n      dfs(dfs, to);\n\
    \    }\n    V.eb(v);\n  };\n  FOR(v, N) if (!done[v]) dfs(dfs, v);\n  reverse(all(V));\n\
    \  if (check) {\n    init();\n    FOR_R(i, N) {\n      int v = V[i];\n      if\
    \ (find_unused(v) != -1) {\n        return {};\n      }\n      set_used(v);\n\
    \    }\n  }\n  return V;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/graph/blackbox/toposort.hpp\n\
    // set_used(v)\uFF1Av \u3092\u4F7F\u7528\u6E08\u306B\u5909\u66F4\u3059\u308B\n\
    // find_unused(v)\uFF1Av \u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u3002\u306A\
    \u3051\u308C\u3070 -1 \u3092\u8FD4\u3059\u3053\u3068\u3002\n// https://codeforces.com/contest/1158/problem/C\n\
    template <typename F0, typename F1, typename F2>\nvc<int> blackbox_toposort(int\
    \ N, F0 init, F1 set_used, F2 find_unused,\n                          bool check\
    \ = true) {\n  init();\n  vc<int> V;\n  vc<bool> done(N);\n  auto dfs = [&](auto&\
    \ dfs, int v) -> void {\n    set_used(v);\n    done[v] = 1;\n    while (1) {\n\
    \      int to = find_unused(v);\n      if (to == -1) break;\n      dfs(dfs, to);\n\
    \    }\n    V.eb(v);\n  };\n  FOR(v, N) if (!done[v]) dfs(dfs, v);\n  reverse(all(V));\n\
    \  if (check) {\n    init();\n    FOR_R(i, N) {\n      int v = V[i];\n      if\
    \ (find_unused(v) != -1) {\n        return {};\n      }\n      set_used(v);\n\
    \    }\n  }\n  return V;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/blackbox/toposort.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/blackbox/toposort.hpp
layout: document
redirect_from:
- /library/graph/blackbox/toposort.hpp
- /library/graph/blackbox/toposort.hpp.html
title: graph/blackbox/toposort.hpp
---
