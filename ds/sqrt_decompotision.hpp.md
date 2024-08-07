---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1234_2.test.cpp
    title: test/yukicoder/1234_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/sqrt_decompotision.hpp\"\n// B, blocks\ntemplate <typename\
    \ BLOCK>\npair<int, vc<BLOCK>> SQRT_Decomposition(int N, int b_sz = -1) {\n  int\
    \ BS, BN; // block size, num\n  vc<BLOCK> blocks;\n  if (b_sz == -1) b_sz = sqrt(N);\n\
    \  BS = b_sz, BN = ceil(N, BS);\n  blocks.reserve(BN);\n  FOR(i, BN) {\n    int\
    \ L = BS * i, R = BS * (i + 1);\n    blocks.eb(BLOCK(L, min(R, N)));\n  }\n  return\
    \ {BS, blocks};\n}\n\n// B, blocks\ntemplate <typename BLOCK, typename X>\npair<int,\
    \ vc<BLOCK>> SQRT_Decomposition(vc<X>& A, int b_sz = -1) {\n  int N = len(A);\n\
    \  int BS, BN; // block size, num\n  vc<BLOCK> blocks;\n  if (b_sz == -1) b_sz\
    \ = sqrt(N);\n  BS = b_sz, BN = ceil(N, BS);\n  blocks.reserve(BN);\n  FOR(i,\
    \ BN) {\n    int L = BS * i, R = BS * (i + 1);\n    chmin(R, N);\n    blocks.eb(BLOCK(A,\
    \ L, R));\n  }\n  return {BS, blocks};\n}\n\n/*\nstruct Block {\n  // \u4F5C\u7528\
    \u7D20\n  using A = ;\n  const A unit = ;\n  static A op(const A& a, const A&\
    \ b) {\n    // \u5B9F\u88C5\n  }\n\n  // \u5217\u306E\u30C7\u30FC\u30BF\n  using\
    \ X = ;\n  static X act(const X& x, const A& a) {\n    // \u5B9F\u88C5\n  }\n\n\
    \  //\n  int N, off;\n  A lazy;\n  vc<X> dat;\n\n  // \u30AF\u30A8\u30EA\u306B\
    \u7B54\u3048\u308B\u7528\u306E\u30C7\u30FC\u30BF\u3092\u8FFD\u52A0\u3067\u6301\
    \u3064\n  // \u5B9F\u88C5\n\n  Block(int L, int R) : N(R - L), off(L), lazy(unit),\
    \ dat(N) { build(); }\n  Block(vc<X>& xs, int L, int R)\n      : N(R - L), off(L),\
    \ lazy(unit), dat(xs.begin() + L, xs.begin() + R) {\n    build();\n  }\n\n  //\
    \ \u5168\u8981\u7D20\u306B lazy \u3092\u53CD\u6620\u3057\u3001lazy \u3092\u5358\
    \u4F4D\u5143\u306B\u623B\u3059\n  void push() {\n    if (lazy == unit) return;\n\
    \    for (auto&& x: dat) { x = act(x, lazy); }\n    lazy = unit;\n  }\n\n  //\
    \ \u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\u7528\u306E\u30C7\u30FC\u30BF\u3092\
    \u6B63\u3057\u304F\u3059\u308B\n  // \u3053\u308C\u304C\u547C\u3070\u308C\u305F\
    \u6642\u70B9\u3067\u3001lazy == unit \u304C\u4FDD\u8A3C\u3055\u308C\u308B\n  void\
    \ build() {\n    assert(lazy == unit);\n    // \u5B9F\u88C5\n  }\n\n  void set(int\
    \ i, X x) {\n    i -= off;\n    assert(0 <= i && i < N);\n    push();\n    dat[i]\
    \ = x;\n    build();\n  }\n\n  void apply(int l, int r, A a) {\n    l = max(0,\
    \ l - off), r = min(N, r - off);\n    if (l >= r) return;\n    if (r - l == N)\
    \ {\n      lazy = op(lazy, a);\n      return;\n    }\n    a = op(lazy, a);\n \
    \   FOR(i, l) dat[i] = act(dat[i], lazy);\n    FOR(i, l, r) dat[i] = act(dat[i],\
    \ a);\n    FOR(i, r, N) dat[i] = act(dat[i], lazy);\n    lazy = unit;\n    build();\n\
    \  }\n\n  int query(int l, int r) {\n    l = max(0, l - off), r = min(N, r - off);\n\
    \    if (l >= r) return 0;\n    if (r - l == N) {\n      // lazy \u3068\u8FFD\u52A0\
    \u30C7\u30FC\u30BF\u3092\u4F7F\u3063\u3066\u30AF\u30A8\u30EA\u306B\u7B54\u3048\
    \u308B\n      // \u5B9F\u88C5\n    }\n    // \u8981\u7D20\u3054\u3068\u306B\u898B\
    \u308B\u3053\u3068\u3067\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\n    int ans\
    \ = 0;\n    FOR(i, l, r) {\n      X x = act(dat[i], lazy);\n      // \u5B9F\u88C5\
    \n    }\n    return ans;\n  }\n};\n*/\n"
  code: "// B, blocks\ntemplate <typename BLOCK>\npair<int, vc<BLOCK>> SQRT_Decomposition(int\
    \ N, int b_sz = -1) {\n  int BS, BN; // block size, num\n  vc<BLOCK> blocks;\n\
    \  if (b_sz == -1) b_sz = sqrt(N);\n  BS = b_sz, BN = ceil(N, BS);\n  blocks.reserve(BN);\n\
    \  FOR(i, BN) {\n    int L = BS * i, R = BS * (i + 1);\n    blocks.eb(BLOCK(L,\
    \ min(R, N)));\n  }\n  return {BS, blocks};\n}\n\n// B, blocks\ntemplate <typename\
    \ BLOCK, typename X>\npair<int, vc<BLOCK>> SQRT_Decomposition(vc<X>& A, int b_sz\
    \ = -1) {\n  int N = len(A);\n  int BS, BN; // block size, num\n  vc<BLOCK> blocks;\n\
    \  if (b_sz == -1) b_sz = sqrt(N);\n  BS = b_sz, BN = ceil(N, BS);\n  blocks.reserve(BN);\n\
    \  FOR(i, BN) {\n    int L = BS * i, R = BS * (i + 1);\n    chmin(R, N);\n   \
    \ blocks.eb(BLOCK(A, L, R));\n  }\n  return {BS, blocks};\n}\n\n/*\nstruct Block\
    \ {\n  // \u4F5C\u7528\u7D20\n  using A = ;\n  const A unit = ;\n  static A op(const\
    \ A& a, const A& b) {\n    // \u5B9F\u88C5\n  }\n\n  // \u5217\u306E\u30C7\u30FC\
    \u30BF\n  using X = ;\n  static X act(const X& x, const A& a) {\n    // \u5B9F\
    \u88C5\n  }\n\n  //\n  int N, off;\n  A lazy;\n  vc<X> dat;\n\n  // \u30AF\u30A8\
    \u30EA\u306B\u7B54\u3048\u308B\u7528\u306E\u30C7\u30FC\u30BF\u3092\u8FFD\u52A0\
    \u3067\u6301\u3064\n  // \u5B9F\u88C5\n\n  Block(int L, int R) : N(R - L), off(L),\
    \ lazy(unit), dat(N) { build(); }\n  Block(vc<X>& xs, int L, int R)\n      : N(R\
    \ - L), off(L), lazy(unit), dat(xs.begin() + L, xs.begin() + R) {\n    build();\n\
    \  }\n\n  // \u5168\u8981\u7D20\u306B lazy \u3092\u53CD\u6620\u3057\u3001lazy\
    \ \u3092\u5358\u4F4D\u5143\u306B\u623B\u3059\n  void push() {\n    if (lazy ==\
    \ unit) return;\n    for (auto&& x: dat) { x = act(x, lazy); }\n    lazy = unit;\n\
    \  }\n\n  // \u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\u7528\u306E\u30C7\u30FC\
    \u30BF\u3092\u6B63\u3057\u304F\u3059\u308B\n  // \u3053\u308C\u304C\u547C\u3070\
    \u308C\u305F\u6642\u70B9\u3067\u3001lazy == unit \u304C\u4FDD\u8A3C\u3055\u308C\
    \u308B\n  void build() {\n    assert(lazy == unit);\n    // \u5B9F\u88C5\n  }\n\
    \n  void set(int i, X x) {\n    i -= off;\n    assert(0 <= i && i < N);\n    push();\n\
    \    dat[i] = x;\n    build();\n  }\n\n  void apply(int l, int r, A a) {\n   \
    \ l = max(0, l - off), r = min(N, r - off);\n    if (l >= r) return;\n    if (r\
    \ - l == N) {\n      lazy = op(lazy, a);\n      return;\n    }\n    a = op(lazy,\
    \ a);\n    FOR(i, l) dat[i] = act(dat[i], lazy);\n    FOR(i, l, r) dat[i] = act(dat[i],\
    \ a);\n    FOR(i, r, N) dat[i] = act(dat[i], lazy);\n    lazy = unit;\n    build();\n\
    \  }\n\n  int query(int l, int r) {\n    l = max(0, l - off), r = min(N, r - off);\n\
    \    if (l >= r) return 0;\n    if (r - l == N) {\n      // lazy \u3068\u8FFD\u52A0\
    \u30C7\u30FC\u30BF\u3092\u4F7F\u3063\u3066\u30AF\u30A8\u30EA\u306B\u7B54\u3048\
    \u308B\n      // \u5B9F\u88C5\n    }\n    // \u8981\u7D20\u3054\u3068\u306B\u898B\
    \u308B\u3053\u3068\u3067\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\n    int ans\
    \ = 0;\n    FOR(i, l, r) {\n      X x = act(dat[i], lazy);\n      // \u5B9F\u88C5\
    \n    }\n    return ans;\n  }\n};\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/sqrt_decompotision.hpp
  requiredBy: []
  timestamp: '2023-07-25 22:13:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1234_2.test.cpp
documentation_of: ds/sqrt_decompotision.hpp
layout: document
redirect_from:
- /library/ds/sqrt_decompotision.hpp
- /library/ds/sqrt_decompotision.hpp.html
title: ds/sqrt_decompotision.hpp
---
