---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2265.test.cpp
    title: test/yukicoder/2265.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segtree/xor_segtree.hpp\"\n// set,prod \u3069\u3061\u3089\
    \u3082 O(sqrt(N)) \u6642\u9593\u3002\n// \u30E2\u30CE\u30A4\u30C9\u304C\u53EF\u63DB\
    \u306A\u3089\u666E\u901A\u306E\u30BB\u30B0\u6728\u3092\u4F7F\u3046\u3053\u3068\
    \u3002\ntemplate <class Monoid>\nstruct Xor_SegTree {\n  static_assert(!Monoid::commute);\n\
    \  using MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type\
    \ = X;\n  vvc<X> dat;\n  int n, log, size;\n  int H; // \u5E45 2^H \u306E\u3068\
    \u3053\u308D\u307E\u3067\u4F5C\u308B\n\n  Xor_SegTree() {}\n  Xor_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Xor_SegTree(int n, F f) {\n   \
    \ build(n, f);\n  }\n  Xor_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    assert(n == size);\n    H = log\
    \ / 2;\n    dat.assign(H + 1, vc<X>(size));\n    FOR(i, n) dat[0][i] = f(i);\n\
    \    FOR(h, 1, H + 1) FOR(i, n >> h) { update(h, i); }\n  }\n\n  X get(int i)\
    \ { return dat[0][i]; }\n  vc<X> get_all() { return dat[0]; }\n\n  void update(int\
    \ h, int i) {\n    assert(0 < h && h <= H);\n    int cnt = 1 << (h - 1);\n   \
    \ int a = i << h;\n    int b = a + cnt;\n    FOR(k, cnt) {\n      dat[h][a + k]\
    \ = MX::op(dat[h - 1][a + k], dat[h - 1][b + k]);\n      dat[h][b + k] = MX::op(dat[h\
    \ - 1][b + k], dat[h - 1][a + k]);\n    }\n  }\n\n  void set(int i, const X& x)\
    \ {\n    assert(i < n);\n    dat[0][i] = x;\n    FOR(h, 1, H + 1) {\n      i /=\
    \ 2;\n      update(h, i);\n    }\n  }\n\n  void multiply(int i, const X& x) {\n\
    \    assert(i < n);\n    dat[0][i] = MX::op(dat[0][i], x);\n    FOR(h, 1, H +\
    \ 1) {\n      i /= 2;\n      update(h, i);\n    }\n  }\n\n  X prod(int L, int\
    \ R, int xor_val) {\n    X x1 = MX::unit(), x2 = MX::unit();\n    FOR(h, H) {\n\
    \      if (L >= R) break;\n      if (L & (1 << h)) {\n        x1 = MX::op(x1,\
    \ dat[h][L ^ xor_val]);\n        L += 1 << h;\n      }\n      if (R & (1 << h))\
    \ {\n        R -= 1 << h;\n        x2 = MX::op(dat[h][R ^ xor_val], x2);\n   \
    \   }\n    }\n    while (L < R) {\n      x1 = MX::op(x1, dat[H][L ^ xor_val]);\n\
    \      L += 1 << H;\n    }\n    return MX::op(x1, x2);\n  }\n};\n"
  code: "// set,prod \u3069\u3061\u3089\u3082 O(sqrt(N)) \u6642\u9593\u3002\n// \u30E2\
    \u30CE\u30A4\u30C9\u304C\u53EF\u63DB\u306A\u3089\u666E\u901A\u306E\u30BB\u30B0\
    \u6728\u3092\u4F7F\u3046\u3053\u3068\u3002\ntemplate <class Monoid>\nstruct Xor_SegTree\
    \ {\n  static_assert(!Monoid::commute);\n  using MX = Monoid;\n  using X = typename\
    \ MX::value_type;\n  using value_type = X;\n  vvc<X> dat;\n  int n, log, size;\n\
    \  int H; // \u5E45 2^H \u306E\u3068\u3053\u308D\u307E\u3067\u4F5C\u308B\n\n \
    \ Xor_SegTree() {}\n  Xor_SegTree(int n) { build(n); }\n  template <typename F>\n\
    \  Xor_SegTree(int n, F f) {\n    build(n, f);\n  }\n  Xor_SegTree(const vc<X>&\
    \ v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return\
    \ MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int\
    \ i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1\
    \ << log;\n    assert(n == size);\n    H = log / 2;\n    dat.assign(H + 1, vc<X>(size));\n\
    \    FOR(i, n) dat[0][i] = f(i);\n    FOR(h, 1, H + 1) FOR(i, n >> h) { update(h,\
    \ i); }\n  }\n\n  X get(int i) { return dat[0][i]; }\n  vc<X> get_all() { return\
    \ dat[0]; }\n\n  void update(int h, int i) {\n    assert(0 < h && h <= H);\n \
    \   int cnt = 1 << (h - 1);\n    int a = i << h;\n    int b = a + cnt;\n    FOR(k,\
    \ cnt) {\n      dat[h][a + k] = MX::op(dat[h - 1][a + k], dat[h - 1][b + k]);\n\
    \      dat[h][b + k] = MX::op(dat[h - 1][b + k], dat[h - 1][a + k]);\n    }\n\
    \  }\n\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[0][i] = x;\n\
    \    FOR(h, 1, H + 1) {\n      i /= 2;\n      update(h, i);\n    }\n  }\n\n  void\
    \ multiply(int i, const X& x) {\n    assert(i < n);\n    dat[0][i] = MX::op(dat[0][i],\
    \ x);\n    FOR(h, 1, H + 1) {\n      i /= 2;\n      update(h, i);\n    }\n  }\n\
    \n  X prod(int L, int R, int xor_val) {\n    X x1 = MX::unit(), x2 = MX::unit();\n\
    \    FOR(h, H) {\n      if (L >= R) break;\n      if (L & (1 << h)) {\n      \
    \  x1 = MX::op(x1, dat[h][L ^ xor_val]);\n        L += 1 << h;\n      }\n    \
    \  if (R & (1 << h)) {\n        R -= 1 << h;\n        x2 = MX::op(dat[h][R ^ xor_val],\
    \ x2);\n      }\n    }\n    while (L < R) {\n      x1 = MX::op(x1, dat[H][L ^\
    \ xor_val]);\n      L += 1 << H;\n    }\n    return MX::op(x1, x2);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/xor_segtree.hpp
  requiredBy: []
  timestamp: '2023-04-08 04:27:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2265.test.cpp
documentation_of: ds/segtree/xor_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/xor_segtree.hpp
- /library/ds/segtree/xor_segtree.hpp.html
title: ds/segtree/xor_segtree.hpp
---
