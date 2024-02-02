---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/count/count_C3_C4.hpp
    title: graph/count/count_C3_C4.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_P3P4P5.test.cpp
    title: test/mytest/count_P3P4P5.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/count/count_C3_C4.hpp\"\n// \u5404\u70B9\u306B\u5BFE\
    \u3057\u3066\u305D\u306E\u70B9\u3092\u542B\u3080 C3, C4 \u3092\u6570\u3048\u308B\
    \n// simple graph \u3092\u4EEE\u5B9A\ntemplate <typename GT>\npair<vi, vi> count_C3_C4_pointwise(GT\
    \ &G) {\n  static_assert(!GT::is_directed);\n  int N = G.N;\n  auto deg = G.deg_array();\n\
    \  auto I = argsort(deg);\n  reverse(all(I));\n  vc<int> rk(N);\n  FOR(i, N) rk[I[i]]\
    \ = i;\n\n  // \u9077\u79FB\u5148\u3092\u964D\u9806\u306B\u4E26\u3079\u308B\n\
    \  vvc<int> TO(N);\n  for (auto &&e: G.edges) {\n    int a = rk[e.frm], b = rk[e.to];\n\
    \    TO[a].eb(b), TO[b].eb(a);\n  }\n  FOR(v, N) { sort(all(TO[v])), reverse(all(TO[v]));\
    \ }\n\n  vc<int> A(N);\n  vi C3(N), C4(N);\n  FOR(a, N) {\n    for (auto &b: TO[a])\
    \ TO[b].pop_back();\n    for (auto &b: TO[a]) {\n      for (auto &c: TO[b]) {\
    \ C4[a] += A[c], C4[c] += A[c], A[c] += 1; }\n    }\n    for (auto &b: TO[a])\
    \ {\n      C3[a] += A[b], C3[b] += A[b] + A[b];\n      for (auto &c: TO[b]) {\
    \ C4[b] += A[c] - 1; }\n    }\n    for (auto &b: TO[a]) {\n      for (auto &c:\
    \ TO[b]) { A[c] = 0; }\n    }\n  }\n  for (auto &x: C3) x /= 2;\n  C3 = rearrange(C3,\
    \ rk), C4 = rearrange(C4, rk);\n  return {C3, C4};\n}\n\n// (2e5,5e5) \u3067 500\
    \ ms\n// https://codeforces.com/gym/104053/problem/K\ntemplate <typename GT>\n\
    pair<ll, ll> count_C3_C4(GT &G) {\n  static_assert(!GT::is_directed);\n  int N\
    \ = G.N;\n  ll x3 = 0, x4 = 0;\n  auto deg = G.deg_array();\n  auto I = argsort(deg);\n\
    \  reverse(all(I));\n  vc<int> rk(N);\n  FOR(i, N) rk[I[i]] = i;\n\n  // \u9077\
    \u79FB\u5148\u3092\u964D\u9806\u306B\u4E26\u3079\u308B\n  vvc<int> TO(N);\n  for\
    \ (auto &&e: G.edges) {\n    int a = rk[e.frm], b = rk[e.to];\n    if (a != b)\
    \ TO[a].eb(b), TO[b].eb(a);\n  }\n  FOR(v, N) {\n    sort(all(TO[v]));\n    reverse(all(TO[v]));\n\
    \  }\n\n  vc<int> A(N);\n  FOR(a, N) {\n    for (auto &&b: TO[a]) TO[b].pop_back();\n\
    \    for (auto &&b: TO[a]) {\n      for (auto &&c: TO[b]) { x4 += A[c]++; }\n\
    \    }\n    for (auto &&b: TO[a]) { x3 += A[b]; }\n    for (auto &&b: TO[a]) {\n\
    \      for (auto &&c: TO[b]) { A[c] = 0; }\n    }\n  }\n  x3 /= 2;\n  return {x3,\
    \ x4};\n}\n#line 2 \"graph/count/count_P3_P4_P5.hpp\"\n\n// \u5404 v \u306B\u5BFE\
    \u3057\u3066\u3001v \u3092\u59CB\u70B9\u3068\u3059\u308B P4, P5, P5 \u3092\u6570\
    \u3048\u308B\uFF08\u9802\u70B9\u6570 3, 4, 5\uFF09\n// simple graph \u3092\u4EEE\
    \u5B9A\u3057\u3066\u3044\u308B\ntemplate <typename GT>\ntuple<vi, vi, vi> count_P3_P4_P5_pointwise(GT&\
    \ G) {\n  static_assert(!GT::is_directed);\n  int N = G.N;\n  auto deg = G.deg_array();\n\
    \  auto [C3, C4] = count_C3_C4_pointwise(G);\n\n  vi P3(N), P4(N), P5(N);\n\n\
    \  FOR(v, N) {\n    for (auto&& e: G[v]) {\n      if (e.frm == e.to) continue;\n\
    \      P3[v] += deg[e.to] - 1;\n    }\n  }\n\n  FOR(v, N) {\n    for (auto&& e:\
    \ G[v]) {\n      if (e.frm == e.to) continue;\n      P4[v] += P3[e.to] - (deg[v]\
    \ - 1);\n    }\n    P4[v] -= C3[v] * 2;\n  }\n  FOR(v, N) {\n    for (auto&& e:\
    \ G[v]) {\n      if (e.frm == e.to) continue;\n      P5[v] += P4[e.to];\n    }\n\
    \    P5[v] -= C4[v] * 2;\n    P5[v] -= C3[v] * 2 * (deg[v] - 3);\n    P5[v] -=\
    \ P3[v] * (deg[v] - 1);\n  }\n  return {P3, P4, P5};\n}\n"
  code: "#include \"graph/count/count_C3_C4.hpp\"\n\n// \u5404 v \u306B\u5BFE\u3057\
    \u3066\u3001v \u3092\u59CB\u70B9\u3068\u3059\u308B P4, P5, P5 \u3092\u6570\u3048\
    \u308B\uFF08\u9802\u70B9\u6570 3, 4, 5\uFF09\n// simple graph \u3092\u4EEE\u5B9A\
    \u3057\u3066\u3044\u308B\ntemplate <typename GT>\ntuple<vi, vi, vi> count_P3_P4_P5_pointwise(GT&\
    \ G) {\n  static_assert(!GT::is_directed);\n  int N = G.N;\n  auto deg = G.deg_array();\n\
    \  auto [C3, C4] = count_C3_C4_pointwise(G);\n\n  vi P3(N), P4(N), P5(N);\n\n\
    \  FOR(v, N) {\n    for (auto&& e: G[v]) {\n      if (e.frm == e.to) continue;\n\
    \      P3[v] += deg[e.to] - 1;\n    }\n  }\n\n  FOR(v, N) {\n    for (auto&& e:\
    \ G[v]) {\n      if (e.frm == e.to) continue;\n      P4[v] += P3[e.to] - (deg[v]\
    \ - 1);\n    }\n    P4[v] -= C3[v] * 2;\n  }\n  FOR(v, N) {\n    for (auto&& e:\
    \ G[v]) {\n      if (e.frm == e.to) continue;\n      P5[v] += P4[e.to];\n    }\n\
    \    P5[v] -= C4[v] * 2;\n    P5[v] -= C3[v] * 2 * (deg[v] - 3);\n    P5[v] -=\
    \ P3[v] * (deg[v] - 1);\n  }\n  return {P3, P4, P5};\n}"
  dependsOn:
  - graph/count/count_C3_C4.hpp
  isVerificationFile: false
  path: graph/count/count_P3_P4_P5.hpp
  requiredBy: []
  timestamp: '2024-01-01 22:23:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/count_P3P4P5.test.cpp
documentation_of: graph/count/count_P3_P4_P5.hpp
layout: document
redirect_from:
- /library/graph/count/count_P3_P4_P5.hpp
- /library/graph/count/count_P3_P4_P5.hpp.html
title: graph/count/count_P3_P4_P5.hpp
---
