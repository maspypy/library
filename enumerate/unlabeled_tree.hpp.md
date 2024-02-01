---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/enumerate_unlabeled_tree.test.cpp
    title: test/mytest/enumerate_unlabeled_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://oeis.org/A000055
  bundledCode: "#line 1 \"enumerate/unlabeled_tree.hpp\"\n\n// unlabeled unrooted\
    \ trees \u3092\u540C\u578B\u3092\u9664\u3044\u3066\u5217\u6319. vc<pair<int, int>>.\n\
    // https://oeis.org/A000055\n// N=15: 7741, 0.005sec\n// N=20: 823065, 0.401sec\n\
    // N=25: 104636890, 52.368sec\ntemplate <typename F>\nvoid enumerate_unlabeled_rooted_tree(int\
    \ n, F f) {\n  assert(0 <= n && n <= 32);\n  if (n == 0) return;\n  /*\n  n/2\
    \ \u4EE5\u4E0B\u306E rooted tree \u3092\u5217\u6319\u3059\u308B\n  rooted tree\
    \ -> bracket sequence -> 1,0 \u306E\u5217 -> 32bit \u6574\u6570\n  */\n  int m\
    \ = floor<int>(n, 2);\n  vvc<u32> dat(m + 1);\n  if (1 <= m) dat[1].eb(0);\n\n\
    \  FOR(n, 2, m + 1) {\n    auto dfs = [&](auto& dfs, int m, int k, u32 now, int\
    \ now_e) -> void {\n      if (now_e == n - 1) {\n        dat[n].eb(now);\n   \
    \     return;\n      }\n      if (now_e + m >= n) {\n        m = n - 1 - now_e;\n\
    \        k = 0;\n      }\n      if (m == 0) return;\n      FOR(i, k, len(dat[m]))\
    \ {\n        u32 x = dat[m][i];\n        x = (x << 1) | 1;\n        dfs(dfs, m,\
    \ i, now | x << (2 * now_e), now_e + m);\n      }\n      dfs(dfs, m - 1, 0, now,\
    \ now_e);\n    };\n    dfs(dfs, n - 1, 0, 0, 0);\n  }\n\n  // m \u4EE5\u4E0B\u306E\
    \ rooted tree \u304C\u5217\u6319\u3067\u304D\u305F\u306E\u3067\u3053\u308C\u3092\
    \u5229\u7528\u3057\u3066\n  // n \u9802\u70B9\u306E unrooted tree \u3092\u5217\
    \u6319\n  auto decode = [&](u64 x) -> vc<pair<int, int>> {\n    vc<pair<int, int>>\
    \ edge;\n    vc<int> path = {0};\n    int p = 0;\n    FOR(i, 2 * n - 2) {\n  \
    \    if (x >> i & 1) {\n        edge.eb(path.back(), p + 1);\n        path.eb(p\
    \ + 1), p++;\n      } else {\n        path.pop_back();\n      }\n    }\n    return\
    \ edge;\n  };\n\n  auto dfs = [&](auto& dfs, int m, int k, u64 now, int now_e)\
    \ -> void {\n    if (now_e == n - 1) {\n      f(decode(now));\n      return;\n\
    \    }\n    if (now_e + m >= n) {\n      m = n - 1 - now_e;\n      k = 0;\n  \
    \  }\n    if (m == 0) return;\n    FOR(i, k, len(dat[m])) {\n      u64 x = dat[m][i];\n\
    \      x = (x << 1) | 1;\n      dfs(dfs, m, i, now | x << (2 * now_e), now_e +\
    \ m);\n    }\n    dfs(dfs, m - 1, 0, now, now_e);\n  };\n  dfs(dfs, floor<int>(n\
    \ - 1, 2), 0, 0, 0);\n\n  // \u91CD\u5FC3\u304C 2 \u3064\u306E\u5834\u5408\n \
    \ if (2 * m == n) {\n    FOR(i, len(dat[m])) {\n      FOR(j, i + 1) {\n      \
    \  u64 x = dat[m][i], y = dat[m][j];\n        y = (y << 1) | 1;\n        f(decode(x\
    \ | (y << (2 * (m - 1)))));\n      }\n    }\n  }\n}\n"
  code: "\n// unlabeled unrooted trees \u3092\u540C\u578B\u3092\u9664\u3044\u3066\u5217\
    \u6319. vc<pair<int, int>>.\n// https://oeis.org/A000055\n// N=15: 7741, 0.005sec\n\
    // N=20: 823065, 0.401sec\n// N=25: 104636890, 52.368sec\ntemplate <typename F>\n\
    void enumerate_unlabeled_rooted_tree(int n, F f) {\n  assert(0 <= n && n <= 32);\n\
    \  if (n == 0) return;\n  /*\n  n/2 \u4EE5\u4E0B\u306E rooted tree \u3092\u5217\
    \u6319\u3059\u308B\n  rooted tree -> bracket sequence -> 1,0 \u306E\u5217 -> 32bit\
    \ \u6574\u6570\n  */\n  int m = floor<int>(n, 2);\n  vvc<u32> dat(m + 1);\n  if\
    \ (1 <= m) dat[1].eb(0);\n\n  FOR(n, 2, m + 1) {\n    auto dfs = [&](auto& dfs,\
    \ int m, int k, u32 now, int now_e) -> void {\n      if (now_e == n - 1) {\n \
    \       dat[n].eb(now);\n        return;\n      }\n      if (now_e + m >= n) {\n\
    \        m = n - 1 - now_e;\n        k = 0;\n      }\n      if (m == 0) return;\n\
    \      FOR(i, k, len(dat[m])) {\n        u32 x = dat[m][i];\n        x = (x <<\
    \ 1) | 1;\n        dfs(dfs, m, i, now | x << (2 * now_e), now_e + m);\n      }\n\
    \      dfs(dfs, m - 1, 0, now, now_e);\n    };\n    dfs(dfs, n - 1, 0, 0, 0);\n\
    \  }\n\n  // m \u4EE5\u4E0B\u306E rooted tree \u304C\u5217\u6319\u3067\u304D\u305F\
    \u306E\u3067\u3053\u308C\u3092\u5229\u7528\u3057\u3066\n  // n \u9802\u70B9\u306E\
    \ unrooted tree \u3092\u5217\u6319\n  auto decode = [&](u64 x) -> vc<pair<int,\
    \ int>> {\n    vc<pair<int, int>> edge;\n    vc<int> path = {0};\n    int p =\
    \ 0;\n    FOR(i, 2 * n - 2) {\n      if (x >> i & 1) {\n        edge.eb(path.back(),\
    \ p + 1);\n        path.eb(p + 1), p++;\n      } else {\n        path.pop_back();\n\
    \      }\n    }\n    return edge;\n  };\n\n  auto dfs = [&](auto& dfs, int m,\
    \ int k, u64 now, int now_e) -> void {\n    if (now_e == n - 1) {\n      f(decode(now));\n\
    \      return;\n    }\n    if (now_e + m >= n) {\n      m = n - 1 - now_e;\n \
    \     k = 0;\n    }\n    if (m == 0) return;\n    FOR(i, k, len(dat[m])) {\n \
    \     u64 x = dat[m][i];\n      x = (x << 1) | 1;\n      dfs(dfs, m, i, now |\
    \ x << (2 * now_e), now_e + m);\n    }\n    dfs(dfs, m - 1, 0, now, now_e);\n\
    \  };\n  dfs(dfs, floor<int>(n - 1, 2), 0, 0, 0);\n\n  // \u91CD\u5FC3\u304C 2\
    \ \u3064\u306E\u5834\u5408\n  if (2 * m == n) {\n    FOR(i, len(dat[m])) {\n \
    \     FOR(j, i + 1) {\n        u64 x = dat[m][i], y = dat[m][j];\n        y =\
    \ (y << 1) | 1;\n        f(decode(x | (y << (2 * (m - 1)))));\n      }\n    }\n\
    \  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/unlabeled_tree.hpp
  requiredBy: []
  timestamp: '2024-01-07 14:20:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/enumerate_unlabeled_tree.test.cpp
documentation_of: enumerate/unlabeled_tree.hpp
layout: document
redirect_from:
- /library/enumerate/unlabeled_tree.hpp
- /library/enumerate/unlabeled_tree.hpp.html
title: enumerate/unlabeled_tree.hpp
---
