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
    - https://codeforces.com/contest/2229/problem/I
  bundledCode: "#line 1 \"graph/tree_dp/O_NK_rerooting_tree_dp.hpp\"\n\n// 2\u4E57\
    \u306E\u6728DP\u578B\u306EO(NK)\u5168\u65B9\u4F4D.\n// \u5404\u9802\u70B9 v \u3092\
    \u6839\u3068\u3057\u305F\u3068\u304D\u306E\u30B5\u30A4\u30BA K \u306E DP \u5024\
    \u3060\u3051\u304C\u6700\u7D42\u7684\u306B\u5FC5\u8981\u3067\u3042\u308B\u5834\
    \u5408\n// https://codeforces.com/contest/2229/problem/I\n//\n// f_ee(A, B, L,\
    \ R)\n// f_ev(A, v, L, R)\n// f_ve(A, v, p, L, R)\n// get_ANS(A, v)\n// A, B \u3084\
    \u8FD4\u308A\u5024\u306F Offset_Vector<T> \u3067\u3001\u8FD4\u308A\u5024\u306F\
    \ [L,R) \u306B\u306A\u308B\u7D44\u3092\u5168\u8A08\u7B97\n//\n// f_ee: virtual\
    \ tree \u306E\u30DE\u30FC\u30B8\n// f_ev: virtual tree \u306B\u6839\u3092\u3064\
    \u3051\u3066 real tree \u306B\u3059\u308B\n// f_ve: real tree \u306B\u89AA\u8FBA\
    \u3092\u3064\u3051\u3066 virtual tree \u306B\u3059\u308B\n// get_ANS: virtual\
    \ tree, v \u304B\u3089\u7B54\u3092\u5F97\u308B. [K-1,K]\ntemplate <typename GT,\
    \ typename T, typename F1, typename F2, typename F3,\n          typename F4>\n\
    vc<T> O_NK_rerooting_tree_dp(GT& G, int K, F1 f_ee, F2 f_ev, F3 f_ve,\n      \
    \                       F4 get_ANS, const T unit) {\n  int N = G.N;\n  vc<int>\
    \ V(N), par(N, -1), sz(N, 1);\n  vvc<int> ch(N);\n  {\n    int t = 0;\n    V[t++]\
    \ = 0;\n    FOR(i, N) {\n      int v = V[i];\n      for (auto& e : G[v]) {\n \
    \       if (e.to == par[v]) continue;\n        V[t++] = e.to;\n        par[e.to]\
    \ = v;\n        ch[v].eb(e.to);\n      }\n    }\n    FOR_R(i, 1, N) {\n      int\
    \ v = V[i];\n      sz[par[v]] += sz[v];\n    }\n  }\n\n  /*\n  dp_down[v]: virtual\
    \ tree at v.\n  dp_prefix[c]: prefix virtual tree at v, before c. (c: not included)\n\
    \  dp_up[v]: virtual tree at v, upward.\n  */\n\n  using D = OffsetVector<T>;\n\
    \  vc<D> dp_down(N), dp_prefix(N), dp_up(N);\n  vc<T> ANS(N);\n\n  // calc dp_down,\
    \ dp_prefix\n  FOR_R(i, N) {\n    int v = V[i];\n    D X(0, 1, unit);\n    int\
    \ n = 0;\n    for (int c : ch[v]) {\n      dp_prefix[c] = X;\n      D Y = f_ev(dp_down[c],\
    \ c, 0, min<int>(K, sz[c]) + 1);\n      Y = f_ve(Y, c, v, 0, min<int>(K, sz[c])\
    \ + 1);\n      n += sz[c];\n      X = f_ee(X, Y, 0, min<int>(n, K) + 1);\n   \
    \ }\n    dp_down[v] = X;\n  }\n\n  dp_up[0] = D(0, 1, unit);\n  FOR(i, N) {\n\
    \    int v = V[i];\n    int nc = len(ch[v]);\n    D X = dp_up[v];\n    int s =\
    \ sz[v];\n    FOR_R(k, nc) {\n      int c = ch[v][k];\n      D Y = f_ee(X, dp_prefix[c],\
    \ max(K - sz[c] - 1, 0), K + 1);\n      Y = f_ev(Y, v, max(K - sz[c], 0), K +\
    \ 1);\n      dp_up[c] = f_ve(Y, v, c, max(K - sz[c], 0), K + 1);\n      s -= sz[c];\n\
    \      Y = f_ev(dp_down[c], c, 0, min(K, sz[c]) + 1);\n      Y = f_ve(Y, c, v,\
    \ 0, min(K, sz[c]) + 1);\n      X = f_ee(X, Y, max(K - s, 0), K + 1);\n    }\n\
    \    ANS[v] = get_ANS(X, v);\n  }\n  return ANS;\n}\n"
  code: "\n// 2\u4E57\u306E\u6728DP\u578B\u306EO(NK)\u5168\u65B9\u4F4D.\n// \u5404\
    \u9802\u70B9 v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u30B5\u30A4\u30BA\
    \ K \u306E DP \u5024\u3060\u3051\u304C\u6700\u7D42\u7684\u306B\u5FC5\u8981\u3067\
    \u3042\u308B\u5834\u5408\n// https://codeforces.com/contest/2229/problem/I\n//\n\
    // f_ee(A, B, L, R)\n// f_ev(A, v, L, R)\n// f_ve(A, v, p, L, R)\n// get_ANS(A,\
    \ v)\n// A, B \u3084\u8FD4\u308A\u5024\u306F Offset_Vector<T> \u3067\u3001\u8FD4\
    \u308A\u5024\u306F [L,R) \u306B\u306A\u308B\u7D44\u3092\u5168\u8A08\u7B97\n//\n\
    // f_ee: virtual tree \u306E\u30DE\u30FC\u30B8\n// f_ev: virtual tree \u306B\u6839\
    \u3092\u3064\u3051\u3066 real tree \u306B\u3059\u308B\n// f_ve: real tree \u306B\
    \u89AA\u8FBA\u3092\u3064\u3051\u3066 virtual tree \u306B\u3059\u308B\n// get_ANS:\
    \ virtual tree, v \u304B\u3089\u7B54\u3092\u5F97\u308B. [K-1,K]\ntemplate <typename\
    \ GT, typename T, typename F1, typename F2, typename F3,\n          typename F4>\n\
    vc<T> O_NK_rerooting_tree_dp(GT& G, int K, F1 f_ee, F2 f_ev, F3 f_ve,\n      \
    \                       F4 get_ANS, const T unit) {\n  int N = G.N;\n  vc<int>\
    \ V(N), par(N, -1), sz(N, 1);\n  vvc<int> ch(N);\n  {\n    int t = 0;\n    V[t++]\
    \ = 0;\n    FOR(i, N) {\n      int v = V[i];\n      for (auto& e : G[v]) {\n \
    \       if (e.to == par[v]) continue;\n        V[t++] = e.to;\n        par[e.to]\
    \ = v;\n        ch[v].eb(e.to);\n      }\n    }\n    FOR_R(i, 1, N) {\n      int\
    \ v = V[i];\n      sz[par[v]] += sz[v];\n    }\n  }\n\n  /*\n  dp_down[v]: virtual\
    \ tree at v.\n  dp_prefix[c]: prefix virtual tree at v, before c. (c: not included)\n\
    \  dp_up[v]: virtual tree at v, upward.\n  */\n\n  using D = OffsetVector<T>;\n\
    \  vc<D> dp_down(N), dp_prefix(N), dp_up(N);\n  vc<T> ANS(N);\n\n  // calc dp_down,\
    \ dp_prefix\n  FOR_R(i, N) {\n    int v = V[i];\n    D X(0, 1, unit);\n    int\
    \ n = 0;\n    for (int c : ch[v]) {\n      dp_prefix[c] = X;\n      D Y = f_ev(dp_down[c],\
    \ c, 0, min<int>(K, sz[c]) + 1);\n      Y = f_ve(Y, c, v, 0, min<int>(K, sz[c])\
    \ + 1);\n      n += sz[c];\n      X = f_ee(X, Y, 0, min<int>(n, K) + 1);\n   \
    \ }\n    dp_down[v] = X;\n  }\n\n  dp_up[0] = D(0, 1, unit);\n  FOR(i, N) {\n\
    \    int v = V[i];\n    int nc = len(ch[v]);\n    D X = dp_up[v];\n    int s =\
    \ sz[v];\n    FOR_R(k, nc) {\n      int c = ch[v][k];\n      D Y = f_ee(X, dp_prefix[c],\
    \ max(K - sz[c] - 1, 0), K + 1);\n      Y = f_ev(Y, v, max(K - sz[c], 0), K +\
    \ 1);\n      dp_up[c] = f_ve(Y, v, c, max(K - sz[c], 0), K + 1);\n      s -= sz[c];\n\
    \      Y = f_ev(dp_down[c], c, 0, min(K, sz[c]) + 1);\n      Y = f_ve(Y, c, v,\
    \ 0, min(K, sz[c]) + 1);\n      X = f_ee(X, Y, max(K - s, 0), K + 1);\n    }\n\
    \    ANS[v] = get_ANS(X, v);\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_dp/O_NK_rerooting_tree_dp.hpp
  requiredBy: []
  timestamp: '2026-05-31 16:42:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_dp/O_NK_rerooting_tree_dp.hpp
layout: document
redirect_from:
- /library/graph/tree_dp/O_NK_rerooting_tree_dp.hpp
- /library/graph/tree_dp/O_NK_rerooting_tree_dp.hpp.html
title: graph/tree_dp/O_NK_rerooting_tree_dp.hpp
---
