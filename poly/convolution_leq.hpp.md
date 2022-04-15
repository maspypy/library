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
    - https://codeforces.com/contest/1641/problem/E
  bundledCode: "#line 1 \"poly/convolution_leq.hpp\"\n// https://codeforces.com/contest/1641/problem/E\r\
    \ntemplate <typename T>\r\nvc<T> convolution_leq(vc<T> f, vc<T> g, bool strict)\
    \ {\r\n  /*\r\n  h[k] = sum_{i+j=k and i<=j} f_ig_j\r\n  if strict: i < j\r\n\
    \  */\r\n  vc<T> h(len(f) + len(g) - 1);\r\n  ll THRESH = 60;\r\n\r\n  ll N =\
    \ max(len(f), len(g));\r\n  vc<pair<int, int>> que;\r\n  que.eb(0, N);\r\n  while\
    \ (!que.empty()) {\r\n    auto [L, R] = que.back();\r\n    que.pop_back();\r\n\
    \    if (R - L <= THRESH) {\r\n      FOR3(i, L, min<int>(R, len(f))) FOR3(j, i\
    \ + 1, min<int>(R, len(g))) {\r\n        h[i + j] += f[i] * g[j];\r\n      }\r\
    \n      continue;\r\n    }\r\n    ll M = (L + R) / 2;\r\n    que.eb(L, M), que.eb(M,\
    \ R);\r\n    if (len(f) <= L || len(g) <= M) continue;\r\n    auto p = convolution<T>({f.begin()\
    \ + L, f.begin() + min<int>(M, len(f))},\r\n                            {g.begin()\
    \ + M, g.begin() + min<int>(R, len(g))});\r\n    FOR(i, len(p)) h[L + M + i] +=\
    \ p[i];\r\n  }\r\n  if (!strict) { FOR(i, min(len(f), len(g))) h[i + i] += f[i]\
    \ * g[i]; }\r\n  return h;\r\n}\n"
  code: "// https://codeforces.com/contest/1641/problem/E\r\ntemplate <typename T>\r\
    \nvc<T> convolution_leq(vc<T> f, vc<T> g, bool strict) {\r\n  /*\r\n  h[k] = sum_{i+j=k\
    \ and i<=j} f_ig_j\r\n  if strict: i < j\r\n  */\r\n  vc<T> h(len(f) + len(g)\
    \ - 1);\r\n  ll THRESH = 60;\r\n\r\n  ll N = max(len(f), len(g));\r\n  vc<pair<int,\
    \ int>> que;\r\n  que.eb(0, N);\r\n  while (!que.empty()) {\r\n    auto [L, R]\
    \ = que.back();\r\n    que.pop_back();\r\n    if (R - L <= THRESH) {\r\n     \
    \ FOR3(i, L, min<int>(R, len(f))) FOR3(j, i + 1, min<int>(R, len(g))) {\r\n  \
    \      h[i + j] += f[i] * g[j];\r\n      }\r\n      continue;\r\n    }\r\n   \
    \ ll M = (L + R) / 2;\r\n    que.eb(L, M), que.eb(M, R);\r\n    if (len(f) <=\
    \ L || len(g) <= M) continue;\r\n    auto p = convolution<T>({f.begin() + L, f.begin()\
    \ + min<int>(M, len(f))},\r\n                            {g.begin() + M, g.begin()\
    \ + min<int>(R, len(g))});\r\n    FOR(i, len(p)) h[L + M + i] += p[i];\r\n  }\r\
    \n  if (!strict) { FOR(i, min(len(f), len(g))) h[i + i] += f[i] * g[i]; }\r\n\
    \  return h;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_leq.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_leq.hpp
layout: document
redirect_from:
- /library/poly/convolution_leq.hpp
- /library/poly/convolution_leq.hpp.html
title: poly/convolution_leq.hpp
---
