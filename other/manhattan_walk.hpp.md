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
    - https://atcoder.jp/contests/abc135/tasks/abc135_e
    - https://codeforces.com/contest/2068/problem/H
  bundledCode: "#line 1 \"other/manhattan_walk.hpp\"\n\n// Find A suth that: A[0]=s,\
    \ A[N]=t, dist(A[i],A[i+1])==D[i]. (integer points)\n// empty if it does not exists.\n\
    // https://atcoder.jp/contests/abc135/tasks/abc135_e\n// https://codeforces.com/contest/2068/problem/H\n\
    vc<pi> manhattan_path(pi s, pi t, vi D) {\n  int N = len(D);\n  ll S = SUM<ll>(D);\n\
    \  ll a = t.fi - s.fi, b = t.se - s.se;\n  if ((S + a + b) % 2 != 0) {\n    return\
    \ {};\n  }\n\n  auto nxt_range = [&](ll l, ll r, ll d) -> pi {\n    // \u76EE\u7684\
    \u5730\u304B\u3089 [l,r] \u306B\u5C45\u3066 d \u9032\u3080\n    if (r <= d)\n\
    \      return {d - r, d + r};\n    elif (d <= l) { return {l - d, r + d}; }\n\
    \    ll a = 0, b = r + d;\n    if ((b - a) & 1)\n      ++a;\n    return {a, b};\n\
    \  };\n\n  vi L(N + 1), R(N + 1);\n  L[0] = R[0] = abs(a) + abs(b);\n  FOR(i,\
    \ N) { tie(L[i + 1], R[i + 1]) = nxt_range(L[i], R[i], D[i]); }\n  if (L[N] !=\
    \ 0) {\n    return {};\n  }\n\n  // dist from (a,b)\n  vi A(N + 1);\n  FOR_R(i,\
    \ N) {\n    auto [s, t] = nxt_range(A[i + 1], A[i + 1], D[i]);\n    A[i] = max(L[i],\
    \ s);\n  }\n\n  auto step = [&](auto &step, ll a, ll b, ll X, ll Y) -> pi {\n\
    \    // (a,b) \u304B\u3089 X \u3059\u3059\u3080\n    // (0,0) \u304B\u3089 Y \u306E\
    \u4F4D\u7F6E\u306B\u884C\u304D\u305F\u3044\u3067\u3059\n    if (a < 0) {\n   \
    \   auto [dx, dy] = step(step, -a, b, X, Y);\n      return {-dx, dy};\n    }\n\
    \    if (b < 0) {\n      auto [dx, dy] = step(step, a, -b, X, Y);\n      return\
    \ {dx, -dy};\n    }\n    assert(a >= 0 && b >= 0);\n    if (a > b) {\n      auto\
    \ [dx, dy] = step(step, b, a, X, Y);\n      return {dy, dx};\n    }\n    ll k\
    \ = (a + b + X - Y) / 2;\n    if (k <= b) {\n      ll dy = -k;\n      ll dx =\
    \ X - abs(dy);\n      return {dx, dy};\n    }\n    assert(k <= a + b);\n    ll\
    \ dx = b - k;\n    ll dy = -(X - abs(dx));\n    return {dx, dy};\n  };\n\n  vc<pi>\
    \ point;\n  point.eb(0, 0);\n  FOR(i, N) {\n    auto [x, y] = point[i];\n    ll\
    \ d = D[i];\n    auto [dx, dy] = step(step, x - a, y - b, d, A[i + 1]);\n    x\
    \ += dx, y += dy;\n    point.eb(x, y);\n  }\n  for (auto &[x, y] : point)\n  \
    \  x += s.fi, y += s.se;\n  return point;\n}\n"
  code: "\n// Find A suth that: A[0]=s, A[N]=t, dist(A[i],A[i+1])==D[i]. (integer\
    \ points)\n// empty if it does not exists.\n// https://atcoder.jp/contests/abc135/tasks/abc135_e\n\
    // https://codeforces.com/contest/2068/problem/H\nvc<pi> manhattan_path(pi s,\
    \ pi t, vi D) {\n  int N = len(D);\n  ll S = SUM<ll>(D);\n  ll a = t.fi - s.fi,\
    \ b = t.se - s.se;\n  if ((S + a + b) % 2 != 0) {\n    return {};\n  }\n\n  auto\
    \ nxt_range = [&](ll l, ll r, ll d) -> pi {\n    // \u76EE\u7684\u5730\u304B\u3089\
    \ [l,r] \u306B\u5C45\u3066 d \u9032\u3080\n    if (r <= d)\n      return {d -\
    \ r, d + r};\n    elif (d <= l) { return {l - d, r + d}; }\n    ll a = 0, b =\
    \ r + d;\n    if ((b - a) & 1)\n      ++a;\n    return {a, b};\n  };\n\n  vi L(N\
    \ + 1), R(N + 1);\n  L[0] = R[0] = abs(a) + abs(b);\n  FOR(i, N) { tie(L[i + 1],\
    \ R[i + 1]) = nxt_range(L[i], R[i], D[i]); }\n  if (L[N] != 0) {\n    return {};\n\
    \  }\n\n  // dist from (a,b)\n  vi A(N + 1);\n  FOR_R(i, N) {\n    auto [s, t]\
    \ = nxt_range(A[i + 1], A[i + 1], D[i]);\n    A[i] = max(L[i], s);\n  }\n\n  auto\
    \ step = [&](auto &step, ll a, ll b, ll X, ll Y) -> pi {\n    // (a,b) \u304B\u3089\
    \ X \u3059\u3059\u3080\n    // (0,0) \u304B\u3089 Y \u306E\u4F4D\u7F6E\u306B\u884C\
    \u304D\u305F\u3044\u3067\u3059\n    if (a < 0) {\n      auto [dx, dy] = step(step,\
    \ -a, b, X, Y);\n      return {-dx, dy};\n    }\n    if (b < 0) {\n      auto\
    \ [dx, dy] = step(step, a, -b, X, Y);\n      return {dx, -dy};\n    }\n    assert(a\
    \ >= 0 && b >= 0);\n    if (a > b) {\n      auto [dx, dy] = step(step, b, a, X,\
    \ Y);\n      return {dy, dx};\n    }\n    ll k = (a + b + X - Y) / 2;\n    if\
    \ (k <= b) {\n      ll dy = -k;\n      ll dx = X - abs(dy);\n      return {dx,\
    \ dy};\n    }\n    assert(k <= a + b);\n    ll dx = b - k;\n    ll dy = -(X -\
    \ abs(dx));\n    return {dx, dy};\n  };\n\n  vc<pi> point;\n  point.eb(0, 0);\n\
    \  FOR(i, N) {\n    auto [x, y] = point[i];\n    ll d = D[i];\n    auto [dx, dy]\
    \ = step(step, x - a, y - b, d, A[i + 1]);\n    x += dx, y += dy;\n    point.eb(x,\
    \ y);\n  }\n  for (auto &[x, y] : point)\n    x += s.fi, y += s.se;\n  return\
    \ point;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/manhattan_walk.hpp
  requiredBy: []
  timestamp: '2025-03-03 17:37:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/manhattan_walk.hpp
layout: document
redirect_from:
- /library/other/manhattan_walk.hpp
- /library/other/manhattan_walk.hpp.html
title: other/manhattan_walk.hpp
---
