---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/1_mytest/equal_4square_sum_grid.cpp
    title: test/1_mytest/equal_4square_sum_grid.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/tupc2023/tasks/tupc2023_k
  bundledCode: "#line 1 \"other/equal_4square_sum_grid.hpp\"\n\n// https://atcoder.jp/contests/tupc2023/tasks/tupc2023_k\n\
    // [0,HW-1]\u306E\u9806\u5217\u3067\u3059\u3079\u3066\u306E(2,2)\u6B63\u65B9\u5F62\
    \u306E\u548C\u304CS, \u89E3\u3044\u305F\u5834\u5408.\n// \u4E00\u822C\u306B\u89E3\
    \u3044\u305F\u308F\u3051\u3067\u306F\u306A\u3044. mod HW \u3067\u306F\u89E3\u3051\
    \u3066\u3044\u308B.\n// (even,even) \u306F S \u304C\u78BA\u5B9A. \u4ED6\u306F\u5FAE\
    \u8ABF\u6574\u306F\u3067\u304D\u308B\u3068\u3044\u3046\u611F\u3058.\nvvc<int>\
    \ equal_4square_sum_grid(int H, int W, int S) {\n  assert(H >= 2 && W >= 2);\n\
    \  int S0 = (H * W - 1) * 2;\n  if (H % 2 == 1 && W % 2 == 0) {\n    vvc<int>\
    \ A = equal_4square_sum_grid(W, H, S);\n    A = transpose(A);\n    return A;\n\
    \  }\n  // \u89E3\u3044\u3066\u3044\u306A\u3044\u5834\u5408\n  if (H % 2 == 0\
    \ && W % 2 == 0) assert(S0 - 3 <= S && S <= S0 + 3);\n  if (W % 2 == 1 && H %\
    \ 4 == 2) { assert(S0 - 1 <= S && S <= S0 + 1); }\n  if (W % 2 == 1 && H % 4 ==\
    \ 0) { assert(S0 - 2 <= S && S <= S0 + 2); }\n\n  if (S == S0 + 1 || S == S0 -\
    \ 2) {\n    vvc<int> A = equal_4square_sum_grid(H, W, 2 * S0 - S);\n    FOR(x,\
    \ H) FOR(y, W) A[x][y] = H * W - 1 - A[x][y];\n    return A;\n  }\n\n  if (S ==\
    \ S0) {\n    vv(int, A, H, W);\n    FOR(j, W) A[j % 2][j] = j, A[(j + 1) % 2][j]\
    \ = H * W - 1 - j;\n    FOR(i, 2, H) FOR(j, W) {\n      if ((i + j) % 2 == 0)\
    \ A[i][j] = A[i - 2][j] + W;\n      if ((i + j) % 2 == 1) A[i][j] = A[i - 2][j]\
    \ - W;\n    }\n    return A;\n  }\n  if (H % 2 == 0 && W % 2 == 0) return {};\
    \ // \u89E3\u306A\u3057\n  if (S == S0 - 1) {\n    vv(int, A, H, W);\n    auto\
    \ nxt = [&](int p) -> int { return (p >= H * W / 2 ? H * W - 1 - p : H * W - 2\
    \ - p); };\n    int p = H * W - 1;\n    FOR(x, H) FOR(y, W) { A[x][y] = p, p =\
    \ nxt(p); }\n    return A;\n  }\n  assert(W % 2 == 1 && H % 4 == 0 && S == S0\
    \ + 2);\n  int n = H / 4;\n  vc<int> tmp;\n  FOR(i, 2 * n * W) {\n    if (i %\
    \ 2 == 0) tmp.eb(2 * i);\n    if (i % 2 == 1) tmp.eb(H * W - 2 * i);\n  }\n  FOR(i,\
    \ n * W) {\n    if (i % 2 == 0) tmp.eb(2 * i + 1);\n    if (i % 2 == 1) tmp.eb(H\
    \ * W - 2 * i - 1);\n  }\n  FOR(i, 3 * n * W, 4 * n * W) { tmp.eb(H * W - tmp[i\
    \ - n * W]); }\n  int p = 0;\n  vv(int, A, H, W);\n  FOR(x, H) FOR(y, W) A[x][y]\
    \ = tmp[p++];\n  if (n % 2 == 0) { FOR(x, 3 * n, 4 * n) reverse(all(A[x])); }\n\
    \  return A;\n}\n"
  code: "\n// https://atcoder.jp/contests/tupc2023/tasks/tupc2023_k\n// [0,HW-1]\u306E\
    \u9806\u5217\u3067\u3059\u3079\u3066\u306E(2,2)\u6B63\u65B9\u5F62\u306E\u548C\u304C\
    S, \u89E3\u3044\u305F\u5834\u5408.\n// \u4E00\u822C\u306B\u89E3\u3044\u305F\u308F\
    \u3051\u3067\u306F\u306A\u3044. mod HW \u3067\u306F\u89E3\u3051\u3066\u3044\u308B\
    .\n// (even,even) \u306F S \u304C\u78BA\u5B9A. \u4ED6\u306F\u5FAE\u8ABF\u6574\u306F\
    \u3067\u304D\u308B\u3068\u3044\u3046\u611F\u3058.\nvvc<int> equal_4square_sum_grid(int\
    \ H, int W, int S) {\n  assert(H >= 2 && W >= 2);\n  int S0 = (H * W - 1) * 2;\n\
    \  if (H % 2 == 1 && W % 2 == 0) {\n    vvc<int> A = equal_4square_sum_grid(W,\
    \ H, S);\n    A = transpose(A);\n    return A;\n  }\n  // \u89E3\u3044\u3066\u3044\
    \u306A\u3044\u5834\u5408\n  if (H % 2 == 0 && W % 2 == 0) assert(S0 - 3 <= S &&\
    \ S <= S0 + 3);\n  if (W % 2 == 1 && H % 4 == 2) { assert(S0 - 1 <= S && S <=\
    \ S0 + 1); }\n  if (W % 2 == 1 && H % 4 == 0) { assert(S0 - 2 <= S && S <= S0\
    \ + 2); }\n\n  if (S == S0 + 1 || S == S0 - 2) {\n    vvc<int> A = equal_4square_sum_grid(H,\
    \ W, 2 * S0 - S);\n    FOR(x, H) FOR(y, W) A[x][y] = H * W - 1 - A[x][y];\n  \
    \  return A;\n  }\n\n  if (S == S0) {\n    vv(int, A, H, W);\n    FOR(j, W) A[j\
    \ % 2][j] = j, A[(j + 1) % 2][j] = H * W - 1 - j;\n    FOR(i, 2, H) FOR(j, W)\
    \ {\n      if ((i + j) % 2 == 0) A[i][j] = A[i - 2][j] + W;\n      if ((i + j)\
    \ % 2 == 1) A[i][j] = A[i - 2][j] - W;\n    }\n    return A;\n  }\n  if (H % 2\
    \ == 0 && W % 2 == 0) return {}; // \u89E3\u306A\u3057\n  if (S == S0 - 1) {\n\
    \    vv(int, A, H, W);\n    auto nxt = [&](int p) -> int { return (p >= H * W\
    \ / 2 ? H * W - 1 - p : H * W - 2 - p); };\n    int p = H * W - 1;\n    FOR(x,\
    \ H) FOR(y, W) { A[x][y] = p, p = nxt(p); }\n    return A;\n  }\n  assert(W %\
    \ 2 == 1 && H % 4 == 0 && S == S0 + 2);\n  int n = H / 4;\n  vc<int> tmp;\n  FOR(i,\
    \ 2 * n * W) {\n    if (i % 2 == 0) tmp.eb(2 * i);\n    if (i % 2 == 1) tmp.eb(H\
    \ * W - 2 * i);\n  }\n  FOR(i, n * W) {\n    if (i % 2 == 0) tmp.eb(2 * i + 1);\n\
    \    if (i % 2 == 1) tmp.eb(H * W - 2 * i - 1);\n  }\n  FOR(i, 3 * n * W, 4 *\
    \ n * W) { tmp.eb(H * W - tmp[i - n * W]); }\n  int p = 0;\n  vv(int, A, H, W);\n\
    \  FOR(x, H) FOR(y, W) A[x][y] = tmp[p++];\n  if (n % 2 == 0) { FOR(x, 3 * n,\
    \ 4 * n) reverse(all(A[x])); }\n  return A;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/equal_4square_sum_grid.hpp
  requiredBy:
  - test/1_mytest/equal_4square_sum_grid.cpp
  timestamp: '2024-10-22 00:27:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/equal_4square_sum_grid.hpp
layout: document
redirect_from:
- /library/other/equal_4square_sum_grid.hpp
- /library/other/equal_4square_sum_grid.hpp.html
title: other/equal_4square_sum_grid.hpp
---
