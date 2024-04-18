---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/count/count_P3_P4_P5.hpp
    title: graph/count/count_P3_P4_P5.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/count_P3P4P5.test.cpp
    title: test/mytest/count_P3P4P5.test.cpp
  - icon: ':x:'
    path: test/mytest/find_C4.test.cpp
    title: test/mytest/find_C4.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/gym/104053/problem/K
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
    \ x4};\n}\n"
  code: "// \u5404\u70B9\u306B\u5BFE\u3057\u3066\u305D\u306E\u70B9\u3092\u542B\u3080\
    \ C3, C4 \u3092\u6570\u3048\u308B\n// simple graph \u3092\u4EEE\u5B9A\ntemplate\
    \ <typename GT>\npair<vi, vi> count_C3_C4_pointwise(GT &G) {\n  static_assert(!GT::is_directed);\n\
    \  int N = G.N;\n  auto deg = G.deg_array();\n  auto I = argsort(deg);\n  reverse(all(I));\n\
    \  vc<int> rk(N);\n  FOR(i, N) rk[I[i]] = i;\n\n  // \u9077\u79FB\u5148\u3092\u964D\
    \u9806\u306B\u4E26\u3079\u308B\n  vvc<int> TO(N);\n  for (auto &&e: G.edges) {\n\
    \    int a = rk[e.frm], b = rk[e.to];\n    TO[a].eb(b), TO[b].eb(a);\n  }\n  FOR(v,\
    \ N) { sort(all(TO[v])), reverse(all(TO[v])); }\n\n  vc<int> A(N);\n  vi C3(N),\
    \ C4(N);\n  FOR(a, N) {\n    for (auto &b: TO[a]) TO[b].pop_back();\n    for (auto\
    \ &b: TO[a]) {\n      for (auto &c: TO[b]) { C4[a] += A[c], C4[c] += A[c], A[c]\
    \ += 1; }\n    }\n    for (auto &b: TO[a]) {\n      C3[a] += A[b], C3[b] += A[b]\
    \ + A[b];\n      for (auto &c: TO[b]) { C4[b] += A[c] - 1; }\n    }\n    for (auto\
    \ &b: TO[a]) {\n      for (auto &c: TO[b]) { A[c] = 0; }\n    }\n  }\n  for (auto\
    \ &x: C3) x /= 2;\n  C3 = rearrange(C3, rk), C4 = rearrange(C4, rk);\n  return\
    \ {C3, C4};\n}\n\n// (2e5,5e5) \u3067 500 ms\n// https://codeforces.com/gym/104053/problem/K\n\
    template <typename GT>\npair<ll, ll> count_C3_C4(GT &G) {\n  static_assert(!GT::is_directed);\n\
    \  int N = G.N;\n  ll x3 = 0, x4 = 0;\n  auto deg = G.deg_array();\n  auto I =\
    \ argsort(deg);\n  reverse(all(I));\n  vc<int> rk(N);\n  FOR(i, N) rk[I[i]] =\
    \ i;\n\n  // \u9077\u79FB\u5148\u3092\u964D\u9806\u306B\u4E26\u3079\u308B\n  vvc<int>\
    \ TO(N);\n  for (auto &&e: G.edges) {\n    int a = rk[e.frm], b = rk[e.to];\n\
    \    if (a != b) TO[a].eb(b), TO[b].eb(a);\n  }\n  FOR(v, N) {\n    sort(all(TO[v]));\n\
    \    reverse(all(TO[v]));\n  }\n\n  vc<int> A(N);\n  FOR(a, N) {\n    for (auto\
    \ &&b: TO[a]) TO[b].pop_back();\n    for (auto &&b: TO[a]) {\n      for (auto\
    \ &&c: TO[b]) { x4 += A[c]++; }\n    }\n    for (auto &&b: TO[a]) { x3 += A[b];\
    \ }\n    for (auto &&b: TO[a]) {\n      for (auto &&c: TO[b]) { A[c] = 0; }\n\
    \    }\n  }\n  x3 /= 2;\n  return {x3, x4};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_C3_C4.hpp
  requiredBy:
  - graph/count/count_P3_P4_P5.hpp
  timestamp: '2024-01-01 22:23:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/find_C4.test.cpp
  - test/mytest/count_P3P4P5.test.cpp
documentation_of: graph/count/count_C3_C4.hpp
layout: document
redirect_from:
- /library/graph/count/count_C3_C4.hpp
- /library/graph/count/count_C3_C4.hpp.html
title: graph/count/count_C3_C4.hpp
---
