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
  bundledCode: "#line 1 \"graph/degree_sequence.hpp\"\n// \u5358\u7D14\u30B0\u30E9\
    \u30D5\u306E\u5B58\u5728\u5224\u5B9A\u3002Erdos-Gallai \u306E\u5B9A\u7406\u3002\
    \nbool check_degree_sequence(vc<int> deg) {\n  const int N = len(deg);\n  if (N\
    \ == 0) return true;\n  if (MAX(deg) >= N) return false;\n  if (SUM<ll>(deg) %\
    \ 2 != 0) return false;\n  vc<int> CNT(N);\n  for (auto&& x: deg) CNT[x]++;\n\
    \  int p = 0;\n  FOR(x, N) FOR(CNT[x]) deg[p++] = x;\n\n  vi A(N + 1), B(N + 1);\n\
    \  FOR(i, N) {\n    int d = deg[i];\n    A[i + 1] += 2 * i - d;\n    if (d < i)\
    \ { B[0] += 1, B[d] -= 1, A[d] += d, A[i + 1] -= d; }\n    if (d >= i) { B[0]\
    \ += 1, B[i + 1] -= 1; }\n  }\n  A = cumsum<ll>(A, 0);\n  B = cumsum<ll>(B, 0);\n\
    \  FOR(k, N + 1) {\n    ll x = A[k] + B[k] * k;\n    if (x < 0) return false;\n\
    \  }\n  return true;\n}\n\nvc<pair<int, int>> construct_from_degree_sequence(vc<int>\
    \ deg) {\n  if (!check_degree_sequence(deg)) return {};\n  int N = len(deg);\n\
    \  vvc<int> dat(N);\n  FOR(v, N) dat[deg[v]].eb(v);\n  vc<pair<int, int>> edges;\n\
    \  int mx = N - 1;\n  FOR(N) {\n    while (mx >= 0 && len(dat[mx]) == 0) --mx;\n\
    \    int v = POP(dat[mx]);\n    vc<int> nbd;\n    int k = mx;\n    while (len(nbd)\
    \ < deg[v]) {\n      if (k == 0) return {};\n      if (len(dat[k]) == 0) {\n \
    \       --k;\n        continue;\n      }\n      int x = POP(dat[k]);\n      nbd.eb(x);\n\
    \    }\n    for (auto&& x: nbd) {\n      edges.eb(v, x);\n      --deg[x];\n  \
    \    dat[deg[x]].eb(x);\n    }\n    deg[v] = 0;\n  }\n  return edges;\n}\n"
  code: "// \u5358\u7D14\u30B0\u30E9\u30D5\u306E\u5B58\u5728\u5224\u5B9A\u3002Erdos-Gallai\
    \ \u306E\u5B9A\u7406\u3002\nbool check_degree_sequence(vc<int> deg) {\n  const\
    \ int N = len(deg);\n  if (N == 0) return true;\n  if (MAX(deg) >= N) return false;\n\
    \  if (SUM<ll>(deg) % 2 != 0) return false;\n  vc<int> CNT(N);\n  for (auto&&\
    \ x: deg) CNT[x]++;\n  int p = 0;\n  FOR(x, N) FOR(CNT[x]) deg[p++] = x;\n\n \
    \ vi A(N + 1), B(N + 1);\n  FOR(i, N) {\n    int d = deg[i];\n    A[i + 1] +=\
    \ 2 * i - d;\n    if (d < i) { B[0] += 1, B[d] -= 1, A[d] += d, A[i + 1] -= d;\
    \ }\n    if (d >= i) { B[0] += 1, B[i + 1] -= 1; }\n  }\n  A = cumsum<ll>(A, 0);\n\
    \  B = cumsum<ll>(B, 0);\n  FOR(k, N + 1) {\n    ll x = A[k] + B[k] * k;\n   \
    \ if (x < 0) return false;\n  }\n  return true;\n}\n\nvc<pair<int, int>> construct_from_degree_sequence(vc<int>\
    \ deg) {\n  if (!check_degree_sequence(deg)) return {};\n  int N = len(deg);\n\
    \  vvc<int> dat(N);\n  FOR(v, N) dat[deg[v]].eb(v);\n  vc<pair<int, int>> edges;\n\
    \  int mx = N - 1;\n  FOR(N) {\n    while (mx >= 0 && len(dat[mx]) == 0) --mx;\n\
    \    int v = POP(dat[mx]);\n    vc<int> nbd;\n    int k = mx;\n    while (len(nbd)\
    \ < deg[v]) {\n      if (k == 0) return {};\n      if (len(dat[k]) == 0) {\n \
    \       --k;\n        continue;\n      }\n      int x = POP(dat[k]);\n      nbd.eb(x);\n\
    \    }\n    for (auto&& x: nbd) {\n      edges.eb(v, x);\n      --deg[x];\n  \
    \    dat[deg[x]].eb(x);\n    }\n    deg[v] = 0;\n  }\n  return edges;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/degree_sequence.hpp
  requiredBy: []
  timestamp: '2023-07-06 13:21:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/degree_sequence.hpp
layout: document
redirect_from:
- /library/graph/degree_sequence.hpp
- /library/graph/degree_sequence.hpp.html
title: graph/degree_sequence.hpp
---