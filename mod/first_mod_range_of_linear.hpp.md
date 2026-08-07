---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/min_of_linear_segments.hpp
    title: mod/min_of_linear_segments.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/first_mod_range_of_linear.test.cpp
    title: test/1_mytest/first_mod_range_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/min_of_linear_segments.hpp\"\n\n/*\nax + b (x>=0) \u304C\
    \u6700\u5C0F\u3068\u306A\u308B\u3068\u3053\u308D\u306E\u60C5\u5831\u3092\u8FD4\
    \u3059\u3002\nprefix min \u3092\u66F4\u65B0\u3059\u308B x \u5168\u4F53\u304C\u3001\
    \u7B49\u5DEE\u6570\u5217\u306E\u548C\u96C6\u5408\u3002\u6B21\u3092\u8FD4\u3059\
    \u3002\n\u30FB\u7B49\u5DEE\u6570\u5217\u306E\u5883\u754C\u3068\u306A\u308B x_0,\
    \ x_1, ..., x_n\n\u30FB\u5404\u5883\u754C\u306E\u9593\u3067\u306E\u4EA4\u5DEE\
    \ dx_0, ..., dx_{n-1}\n*/\npair<vc<int>, vc<int>> min_of_linear_segments(int a,\
    \ int b, int mod) {\n  assert(0 <= a && a < mod);\n  assert(0 <= b && b < mod);\n\
    \  vc<int> X = {0};\n  vc<int> DX;\n  int g = gcd(a, mod);\n  a /= g, b /= g,\
    \ mod /= g;\n  // p/q <= (mod-a)/mod <= r/s\n  int p = 0, q = 1, r = 1, s = 1;\n\
    \  int det_l = mod - a, det_r = a;\n  int x = 0, y = b;\n\n  while (y) {\n   \
    \ // upd r/s\n    int k = det_r / det_l;\n    det_r %= det_l;\n    if (det_r ==\
    \ 0) {\n      --k;\n      det_r = det_l;\n    }\n    r += k * p;\n    s += k *\
    \ q;\n    while (1) {\n      int k = max(0, ceil(det_l - y, det_r));\n      if\
    \ (det_l - k * det_r <= 0) break;\n      det_l -= k * det_r;\n      p += k * r;\n\
    \      q += k * s;\n      // p/q <= a/mod\n      // (aq - pmod) = det_l \u3092\
    \ y \u304B\u3089\u5F15\u304F\n      k = y / det_l;\n      y -= k * det_l;\n  \
    \    x += q * k;\n      X.eb(x);\n      DX.eb(q);\n    }\n    k = det_l / det_r;\n\
    \    det_l -= k * det_r;\n    p += k * r;\n    q += k * s;\n    assert(min({p,\
    \ q, r, s}) >= 0);\n  }\n  return {X, DX};\n}\n#line 2 \"mod/first_mod_range_of_linear.hpp\"\
    \n\n// ax+b in {L, ..., R-1} mod \u3068\u306A\u308B\u6700\u5C0F\u306E x>=0 \u3092\
    \u8FD4\u3059\n// \u4F8B\u3048\u3070 ax+b=1 \u306A\u3089 ax+b in {-1} mod 2 \u306E\
    \u3088\u3046\u306B\u3059\u308B\n// \u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    \ -1\n// L<0 \u3084 mod<=R \u3082 ok\nint first_mod_range_of_linear(ll L, ll R,\
    \ ll a, ll b, int mod) {\n  assert(L <= R);\n  b -= L, R -= L;\n  if (R >= mod)\
    \ return 0;\n  a = bmod<ll>(a, mod), b = bmod<ll>(b, mod);\n  // ax+b<R\n  if\
    \ (b < R) return 0;\n  auto [X, DX] = min_of_linear_segments(a, b, mod);\n  FOR(i,\
    \ len(DX)) {\n    ll x1 = X[i], x2 = X[i + 1];\n    ll y2 = (a * x2 + b) % mod;\n\
    \    if (y2 >= R) continue;\n    ll y1 = (a * x1 + b) % mod;\n    ll d = (y1 -\
    \ y2) * DX[i] / (x2 - x1);\n    ll k = floor(y1 - R, d) + 1;\n    return x1 +\
    \ k * DX[i];\n  }\n  return -1;\n}\n"
  code: "#include \"mod/min_of_linear_segments.hpp\"\n\n// ax+b in {L, ..., R-1} mod\
    \ \u3068\u306A\u308B\u6700\u5C0F\u306E x>=0 \u3092\u8FD4\u3059\n// \u4F8B\u3048\
    \u3070 ax+b=1 \u306A\u3089 ax+b in {-1} mod 2 \u306E\u3088\u3046\u306B\u3059\u308B\
    \n// \u5B58\u5728\u3057\u306A\u3051\u308C\u3070 -1\n// L<0 \u3084 mod<=R \u3082\
    \ ok\nint first_mod_range_of_linear(ll L, ll R, ll a, ll b, int mod) {\n  assert(L\
    \ <= R);\n  b -= L, R -= L;\n  if (R >= mod) return 0;\n  a = bmod<ll>(a, mod),\
    \ b = bmod<ll>(b, mod);\n  // ax+b<R\n  if (b < R) return 0;\n  auto [X, DX] =\
    \ min_of_linear_segments(a, b, mod);\n  FOR(i, len(DX)) {\n    ll x1 = X[i], x2\
    \ = X[i + 1];\n    ll y2 = (a * x2 + b) % mod;\n    if (y2 >= R) continue;\n \
    \   ll y1 = (a * x1 + b) % mod;\n    ll d = (y1 - y2) * DX[i] / (x2 - x1);\n \
    \   ll k = floor(y1 - R, d) + 1;\n    return x1 + k * DX[i];\n  }\n  return -1;\n\
    }"
  dependsOn:
  - mod/min_of_linear_segments.hpp
  isVerificationFile: false
  path: mod/first_mod_range_of_linear.hpp
  requiredBy: []
  timestamp: '2024-05-14 16:33:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/first_mod_range_of_linear.test.cpp
documentation_of: mod/first_mod_range_of_linear.hpp
layout: document
redirect_from:
- /library/mod/first_mod_range_of_linear.hpp
- /library/mod/first_mod_range_of_linear.hpp.html
title: mod/first_mod_range_of_linear.hpp
---
