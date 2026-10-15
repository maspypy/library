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
    - https://codeforces.com/contest/12/problem/E
    - https://github.com/maspypy/library/blob/main/graph/decompose_complete.hpp
  bundledCode: "#line 1 \"graph/decompose_complete.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/decompose_complete.hpp\n\
    // \u5076\u6570\u9802\u70B9\u306E\u7121\u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\
    \u30CF\u30DF\u30EB\u30C8\u30F3\u30D1\u30B9\u306B\u5206\u89E3\nvvc<int> to_paths(ll\
    \ N, ll K) {\n  assert(N >= 0 && N % 2 == 0 && 0 <= K && K <= N / 2);\n  vv(int,\
    \ paths, K, N);\n  FOR(k, K) FOR(n, N) {\n    auto &x = paths[k][n];\n    x =\
    \ k + (n & 1 ? (n + 1) / 2 : -(n / 2));\n    if (x < 0) x += N;\n    if (x >=\
    \ N) x -= N;\n  }\n  return paths;\n}\n\n// \u5947\u6570\u9802\u70B9\u306E\u7121\
    \u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\u30CF\u30DF\u30EB\u30C8\u30C8\u30F3\
    \u30B5\u30A4\u30AF\u30EB\u306B\u5206\u89E3\nvvc<int> to_cycles(ll N, ll K) {\n\
    \  assert(N >= 0 && N % 2 == 1 && 0 <= K && K <= (N - 1) / 2);\n  auto paths =\
    \ to_paths(N - 1, K);\n  for (auto &&P: paths) P.eb(N - 1);\n  return paths;\n\
    }\n\n// https://codeforces.com/contest/12/problem/E\n// \u5076\u6570\u9802\u70B9\
    \u306E\u7121\u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u306B\u5206\u89E3\n// \u8FBA\u5F69\u8272\u3057\u3066\u3044\u308B\u3068\u3044\
    \u3063\u3066\u3082\u3088\u3044\n// \u3053\u306E\u3046\u3061\u3069\u306E 2 \u500B\
    \u3092\u9078\u3093\u3067\u3082\u3001\u30CF\u30DF\u30EB\u30C8\u30F3\u30B5\u30A4\
    \u30AF\u30EB\u306B\u306A\u308B\u3002\nvvc<pair<int, int>> to_matchings(ll N) {\n\
    \  assert(N > 0 && N % 2 == 0);\n  vvc<pair<int, int>> res(N - 1);\n  const int\
    \ mod = N - 1;\n  FOR(a, mod) {\n    res[a].reserve(N / 2);\n    res[a].eb(N -\
    \ 1, a);\n    int x = a, y = a;\n    FOR(N / 2 - 1) {\n      --x, ++y;\n     \
    \ if (x < 0) x += N - 1;\n      if (y >= N - 1) y -= N - 1;\n      res[a].eb(x,\
    \ y);\n    }\n  }\n  return res;\n}\n\n// \u5076\u6570\u9802\u70B9\u306E\u7121\
    \u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\u3001\u30CF\u30DF\u30EB\u30C8\u30F3\
    \u30B5\u30A4\u30AF\u30EB\u3068 1 \u3064\u306E\u30DE\u30C3\u30C1\u30F3\u30B0\u306B\
    \u5206\u89E3\npair<vc<vi>, vi> to_cycles_and_matching(ll N) {\n  assert(N > 0\
    \ && N % 2 == 0);\n  vv(ll, cycles, N / 2 - 1, N);\n  ll mod = N - 1;\n  FOR(a,\
    \ mod - 1) if (a % 2 == 0) {\n    auto &C = cycles[a / 2];\n    // \u548C\u304C\
    \ 2a, 2a+2 \u306E\u3069\u3061\u3089\u304B\u306B\u306A\u308B\u3068\u304D\u306B\u7D50\
    \u3076\n    C[0] = a;\n    FOR(i, N - 2) {\n      ll nxt = (i % 2 == 0 ? 2 * a\
    \ + 2 - C[i] : 2 * a - C[i]);\n      if (nxt < 0) nxt += mod;\n      if (nxt >=\
    \ mod) nxt -= mod;\n      C[i + 1] = nxt;\n    }\n    C[N - 1] = mod;\n  }\n \
    \ vi match(N);\n  FOR(a, mod / 2) {\n    ll b = mod - 2 - a;\n    match[2 * a]\
    \ = a, match[2 * a + 1] = b;\n  }\n  match[N - 2] = N - 2, match[N - 1] = N -\
    \ 1;\n  return {cycles, match};\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/graph/decompose_complete.hpp\n\
    // \u5076\u6570\u9802\u70B9\u306E\u7121\u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\
    \u30CF\u30DF\u30EB\u30C8\u30F3\u30D1\u30B9\u306B\u5206\u89E3\nvvc<int> to_paths(ll\
    \ N, ll K) {\n  assert(N >= 0 && N % 2 == 0 && 0 <= K && K <= N / 2);\n  vv(int,\
    \ paths, K, N);\n  FOR(k, K) FOR(n, N) {\n    auto &x = paths[k][n];\n    x =\
    \ k + (n & 1 ? (n + 1) / 2 : -(n / 2));\n    if (x < 0) x += N;\n    if (x >=\
    \ N) x -= N;\n  }\n  return paths;\n}\n\n// \u5947\u6570\u9802\u70B9\u306E\u7121\
    \u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\u30CF\u30DF\u30EB\u30C8\u30C8\u30F3\
    \u30B5\u30A4\u30AF\u30EB\u306B\u5206\u89E3\nvvc<int> to_cycles(ll N, ll K) {\n\
    \  assert(N >= 0 && N % 2 == 1 && 0 <= K && K <= (N - 1) / 2);\n  auto paths =\
    \ to_paths(N - 1, K);\n  for (auto &&P: paths) P.eb(N - 1);\n  return paths;\n\
    }\n\n// https://codeforces.com/contest/12/problem/E\n// \u5076\u6570\u9802\u70B9\
    \u306E\u7121\u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u306B\u5206\u89E3\n// \u8FBA\u5F69\u8272\u3057\u3066\u3044\u308B\u3068\u3044\
    \u3063\u3066\u3082\u3088\u3044\n// \u3053\u306E\u3046\u3061\u3069\u306E 2 \u500B\
    \u3092\u9078\u3093\u3067\u3082\u3001\u30CF\u30DF\u30EB\u30C8\u30F3\u30B5\u30A4\
    \u30AF\u30EB\u306B\u306A\u308B\u3002\nvvc<pair<int, int>> to_matchings(ll N) {\n\
    \  assert(N > 0 && N % 2 == 0);\n  vvc<pair<int, int>> res(N - 1);\n  const int\
    \ mod = N - 1;\n  FOR(a, mod) {\n    res[a].reserve(N / 2);\n    res[a].eb(N -\
    \ 1, a);\n    int x = a, y = a;\n    FOR(N / 2 - 1) {\n      --x, ++y;\n     \
    \ if (x < 0) x += N - 1;\n      if (y >= N - 1) y -= N - 1;\n      res[a].eb(x,\
    \ y);\n    }\n  }\n  return res;\n}\n\n// \u5076\u6570\u9802\u70B9\u306E\u7121\
    \u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\u3001\u30CF\u30DF\u30EB\u30C8\u30F3\
    \u30B5\u30A4\u30AF\u30EB\u3068 1 \u3064\u306E\u30DE\u30C3\u30C1\u30F3\u30B0\u306B\
    \u5206\u89E3\npair<vc<vi>, vi> to_cycles_and_matching(ll N) {\n  assert(N > 0\
    \ && N % 2 == 0);\n  vv(ll, cycles, N / 2 - 1, N);\n  ll mod = N - 1;\n  FOR(a,\
    \ mod - 1) if (a % 2 == 0) {\n    auto &C = cycles[a / 2];\n    // \u548C\u304C\
    \ 2a, 2a+2 \u306E\u3069\u3061\u3089\u304B\u306B\u306A\u308B\u3068\u304D\u306B\u7D50\
    \u3076\n    C[0] = a;\n    FOR(i, N - 2) {\n      ll nxt = (i % 2 == 0 ? 2 * a\
    \ + 2 - C[i] : 2 * a - C[i]);\n      if (nxt < 0) nxt += mod;\n      if (nxt >=\
    \ mod) nxt -= mod;\n      C[i + 1] = nxt;\n    }\n    C[N - 1] = mod;\n  }\n \
    \ vi match(N);\n  FOR(a, mod / 2) {\n    ll b = mod - 2 - a;\n    match[2 * a]\
    \ = a, match[2 * a + 1] = b;\n  }\n  match[N - 2] = N - 2, match[N - 1] = N -\
    \ 1;\n  return {cycles, match};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/decompose_complete.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/decompose_complete.hpp
layout: document
redirect_from:
- /library/graph/decompose_complete.hpp
- /library/graph/decompose_complete.hpp.html
title: graph/decompose_complete.hpp
---
