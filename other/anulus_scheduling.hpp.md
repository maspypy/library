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
    - https://codeforces.com/contest/526/problem/E
  bundledCode: "#line 1 \"other/anulus_scheduling.hpp\"\n\n// return: [1\u5468\u4EE5\
    \u4E0A\u3059\u308B\u306E\u306B\u304B\u304B\u308B\u56DE\u6570, \u59CB\u70B9].\n\
    // dist[i]: i \u304B\u3089\u9032\u3081\u308B\u8DDD\u96E2.\n// \u533A\u9593\u306B\
    \u5358\u8ABF\u6027\u304C\u3042\u308B\u3068\u3059\u308B. i+dist[i]<=(i+1)+dist[i+1]\n\
    // https://codeforces.com/contest/526/problem/E\npair<int, int> anulus_scheduling(int\
    \ N, vc<int> dist) {\n  assert(len(dist) == N);\n  FOR(i, N - 1) assert(dist[i]\
    \ <= 1 + dist[i + 1]);\n  assert(dist[N - 1] <= 1 + dist[0]);\n  FOR(v, N) {\n\
    \    assert(dist[v] > 0);\n    if (dist[v] >= N) return {1, v};\n  }\n  vc<int>\
    \ end(N);\n  vc<int> cnt(N);\n  FOR_R(i, N) {\n    int j = i + dist[i];\n    if\
    \ (j >= N) {\n      end[i] = j, cnt[i] = 1;\n    } else {\n      end[i] = end[j],\
    \ cnt[i] = cnt[j] + 1;\n      if (end[i] >= N + i) return {cnt[i], i};\n    }\n\
    \  }\n  assert(0);\n}\n"
  code: "\n// return: [1\u5468\u4EE5\u4E0A\u3059\u308B\u306E\u306B\u304B\u304B\u308B\
    \u56DE\u6570, \u59CB\u70B9].\n// dist[i]: i \u304B\u3089\u9032\u3081\u308B\u8DDD\
    \u96E2.\n// \u533A\u9593\u306B\u5358\u8ABF\u6027\u304C\u3042\u308B\u3068\u3059\
    \u308B. i+dist[i]<=(i+1)+dist[i+1]\n// https://codeforces.com/contest/526/problem/E\n\
    pair<int, int> anulus_scheduling(int N, vc<int> dist) {\n  assert(len(dist) ==\
    \ N);\n  FOR(i, N - 1) assert(dist[i] <= 1 + dist[i + 1]);\n  assert(dist[N -\
    \ 1] <= 1 + dist[0]);\n  FOR(v, N) {\n    assert(dist[v] > 0);\n    if (dist[v]\
    \ >= N) return {1, v};\n  }\n  vc<int> end(N);\n  vc<int> cnt(N);\n  FOR_R(i,\
    \ N) {\n    int j = i + dist[i];\n    if (j >= N) {\n      end[i] = j, cnt[i]\
    \ = 1;\n    } else {\n      end[i] = end[j], cnt[i] = cnt[j] + 1;\n      if (end[i]\
    \ >= N + i) return {cnt[i], i};\n    }\n  }\n  assert(0);\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/anulus_scheduling.hpp
  requiredBy: []
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/anulus_scheduling.hpp
layout: document
redirect_from:
- /library/other/anulus_scheduling.hpp
- /library/other/anulus_scheduling.hpp.html
title: other/anulus_scheduling.hpp
---
