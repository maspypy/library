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
  bundledCode: "#line 1 \"graph/decompose_complete.hpp\"\nvc<vi> to_paths(ll N) {\r\
    \n  // \u5076\u6570\u9802\u70B9\u306E\u7121\u5411\u5B8C\u5168\u30B0\u30E9\u30D5\
    \u3092\u30CF\u30DF\u30EB\u30C8\u30F3\u30D1\u30B9\u306B\u5206\u89E3\r\n  assert(N\
    \ >= 0 && N % 2 == 0);\r\n  ll K = N / 2;\r\n  vv(ll, paths, K, N);\r\n  FOR(k,\
    \ K) FOR(n, N) {\r\n    auto &x = paths[k][n];\r\n    x = k + (n & 1 ? (n + 1)\
    \ / 2 : -(n / 2));\r\n    if (x < 0)\r\n      x += N;\r\n    if (x >= N)\r\n \
    \     x -= N;\r\n  }\r\n  return paths;\r\n}\r\n\r\nvc<vi> to_cycles(ll N) {\r\
    \n  // \u5947\u6570\u9802\u70B9\u306E\u7121\u5411\u5B8C\u5168\u30B0\u30E9\u30D5\
    \u3092\u30CF\u30DF\u30EB\u30C8\u30C8\u30F3\u30B5\u30A4\u30AF\u30EB\u306B\u5206\
    \u89E3\r\n  assert(N >= 0 && N % 2 == 1);\r\n  auto paths = to_paths(N - 1);\r\
    \n  FORIN(P, paths) P.eb(N - 1);\r\n  return paths;\r\n}\r\n\r\nvc<vi> to_matchings(ll\
    \ N) {\r\n  // \u5076\u6570\u9802\u70B9\u306E\u7121\u5411\u5B8C\u5168\u30B0\u30E9\
    \u30D5\u3092\u30DE\u30C3\u30C1\u30F3\u30B0\u306B\u5206\u89E3\r\n  // \u8FBA\u5F69\
    \u8272\u3057\u3066\u3044\u308B\u3068\u3044\u3063\u3066\u3082\u3088\u3044\r\n \
    \ // \u3053\u306E\u3046\u3061\u3069\u306E 2 \u500B\u3092\u9078\u3093\u3067\u3082\
    \u3001\u30CF\u30DF\u30EB\u30C8\u30F3\u30B5\u30A4\u30AF\u30EB\u306B\u306A\u308B\
    \u3002\r\n  assert(N > 0 && N % 2 == 0);\r\n  vv(ll, match, N - 1, N);\r\n  ll\
    \ mod = N - 1;\r\n  FOR(a, mod) {\r\n    match[a][0] = N - 1, match[a][1] = a;\r\
    \n    FOR3(k, 1, N / 2) {\r\n      ll b = a - k, c = a + k;\r\n      if (b < 0)\r\
    \n        b += mod;\r\n      if (c >= mod)\r\n        c -= mod;\r\n      match[a][2\
    \ * k] = b, match[a][2 * k + 1] = c;\r\n    }\r\n  }\r\n  return match;\r\n}\r\
    \n\r\npair<vc<vi>, vi> to_cycles_and_matching(ll N) {\r\n  // \u5076\u6570\u9802\
    \u70B9\u306E\u7121\u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\u3001\u30CF\u30DF\
    \u30EB\u30C8\u30F3\u30B5\u30A4\u30AF\u30EB\u3068 1 \u3064\u306E\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u306B\u5206\u89E3\r\n  assert(N > 0 && N % 2 == 0);\r\n  vv(ll, cycles,\
    \ N / 2 - 1, N);\r\n  ll mod = N - 1;\r\n  FOR(a, mod - 1) if (a % 2 == 0) {\r\
    \n    auto &C = cycles[a / 2];\r\n    // \u548C\u304C 2a, 2a+2 \u306E\u3069\u3061\
    \u3089\u304B\u306B\u306A\u308B\u3068\u304D\u306B\u7D50\u3076\r\n    C[0] = a;\r\
    \n    FOR(i, N - 2) {\r\n      ll nxt = (i % 2 == 0 ? 2 * a + 2 - C[i] : 2 * a\
    \ - C[i]);\r\n      if (nxt < 0)\r\n        nxt += mod;\r\n      if (nxt >= mod)\r\
    \n        nxt -= mod;\r\n      C[i + 1] = nxt;\r\n    }\r\n    C[N - 1] = mod;\r\
    \n  }\r\n  vi match(N);\r\n  FOR(a, mod / 2) {\r\n    ll b = mod - 2 - a;\r\n\
    \    match[2 * a] = a, match[2 * a + 1] = b;\r\n  }\r\n  match[N - 2] = N - 2,\
    \ match[N - 1] = N - 1;\r\n  return {cycles, match};\r\n}\n"
  code: "vc<vi> to_paths(ll N) {\r\n  // \u5076\u6570\u9802\u70B9\u306E\u7121\u5411\
    \u5B8C\u5168\u30B0\u30E9\u30D5\u3092\u30CF\u30DF\u30EB\u30C8\u30F3\u30D1\u30B9\
    \u306B\u5206\u89E3\r\n  assert(N >= 0 && N % 2 == 0);\r\n  ll K = N / 2;\r\n \
    \ vv(ll, paths, K, N);\r\n  FOR(k, K) FOR(n, N) {\r\n    auto &x = paths[k][n];\r\
    \n    x = k + (n & 1 ? (n + 1) / 2 : -(n / 2));\r\n    if (x < 0)\r\n      x +=\
    \ N;\r\n    if (x >= N)\r\n      x -= N;\r\n  }\r\n  return paths;\r\n}\r\n\r\n\
    vc<vi> to_cycles(ll N) {\r\n  // \u5947\u6570\u9802\u70B9\u306E\u7121\u5411\u5B8C\
    \u5168\u30B0\u30E9\u30D5\u3092\u30CF\u30DF\u30EB\u30C8\u30C8\u30F3\u30B5\u30A4\
    \u30AF\u30EB\u306B\u5206\u89E3\r\n  assert(N >= 0 && N % 2 == 1);\r\n  auto paths\
    \ = to_paths(N - 1);\r\n  FORIN(P, paths) P.eb(N - 1);\r\n  return paths;\r\n\
    }\r\n\r\nvc<vi> to_matchings(ll N) {\r\n  // \u5076\u6570\u9802\u70B9\u306E\u7121\
    \u5411\u5B8C\u5168\u30B0\u30E9\u30D5\u3092\u30DE\u30C3\u30C1\u30F3\u30B0\u306B\
    \u5206\u89E3\r\n  // \u8FBA\u5F69\u8272\u3057\u3066\u3044\u308B\u3068\u3044\u3063\
    \u3066\u3082\u3088\u3044\r\n  // \u3053\u306E\u3046\u3061\u3069\u306E 2 \u500B\
    \u3092\u9078\u3093\u3067\u3082\u3001\u30CF\u30DF\u30EB\u30C8\u30F3\u30B5\u30A4\
    \u30AF\u30EB\u306B\u306A\u308B\u3002\r\n  assert(N > 0 && N % 2 == 0);\r\n  vv(ll,\
    \ match, N - 1, N);\r\n  ll mod = N - 1;\r\n  FOR(a, mod) {\r\n    match[a][0]\
    \ = N - 1, match[a][1] = a;\r\n    FOR3(k, 1, N / 2) {\r\n      ll b = a - k,\
    \ c = a + k;\r\n      if (b < 0)\r\n        b += mod;\r\n      if (c >= mod)\r\
    \n        c -= mod;\r\n      match[a][2 * k] = b, match[a][2 * k + 1] = c;\r\n\
    \    }\r\n  }\r\n  return match;\r\n}\r\n\r\npair<vc<vi>, vi> to_cycles_and_matching(ll\
    \ N) {\r\n  // \u5076\u6570\u9802\u70B9\u306E\u7121\u5411\u5B8C\u5168\u30B0\u30E9\
    \u30D5\u3092\u3001\u30CF\u30DF\u30EB\u30C8\u30F3\u30B5\u30A4\u30AF\u30EB\u3068\
    \ 1 \u3064\u306E\u30DE\u30C3\u30C1\u30F3\u30B0\u306B\u5206\u89E3\r\n  assert(N\
    \ > 0 && N % 2 == 0);\r\n  vv(ll, cycles, N / 2 - 1, N);\r\n  ll mod = N - 1;\r\
    \n  FOR(a, mod - 1) if (a % 2 == 0) {\r\n    auto &C = cycles[a / 2];\r\n    //\
    \ \u548C\u304C 2a, 2a+2 \u306E\u3069\u3061\u3089\u304B\u306B\u306A\u308B\u3068\
    \u304D\u306B\u7D50\u3076\r\n    C[0] = a;\r\n    FOR(i, N - 2) {\r\n      ll nxt\
    \ = (i % 2 == 0 ? 2 * a + 2 - C[i] : 2 * a - C[i]);\r\n      if (nxt < 0)\r\n\
    \        nxt += mod;\r\n      if (nxt >= mod)\r\n        nxt -= mod;\r\n     \
    \ C[i + 1] = nxt;\r\n    }\r\n    C[N - 1] = mod;\r\n  }\r\n  vi match(N);\r\n\
    \  FOR(a, mod / 2) {\r\n    ll b = mod - 2 - a;\r\n    match[2 * a] = a, match[2\
    \ * a + 1] = b;\r\n  }\r\n  match[N - 2] = N - 2, match[N - 1] = N - 1;\r\n  return\
    \ {cycles, match};\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/decompose_complete.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/decompose_complete.hpp
layout: document
redirect_from:
- /library/graph/decompose_complete.hpp
- /library/graph/decompose_complete.hpp.html
title: graph/decompose_complete.hpp
---
