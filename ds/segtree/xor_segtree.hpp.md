---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2265.test.cpp
    title: test/yukicoder/2265.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segtree/xor_segtree.hpp\"\n\n// prod_i(A_{i xor x}) \u306E\
    \u3067\u304D\u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3002\n// set / prod \u3069\
    \u3061\u3089\u3082 O(sqrt(N)) \u6642\u9593\u3002\n// \u30E2\u30CE\u30A4\u30C9\u304C\
    \u53EF\u63DB\u306A\u3089\u666E\u901A\u306E\u30BB\u30B0\u6728\u3092\u4F7F\u3046\
    \u3053\u3068\u3002\ntemplate <class Monoid>\nstruct Xor_SegTree {\n  static_assert(!Monoid::commute);\n\
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
    \ R, int xor_val) {\n    X x = MX::unit();\n    for (int b = 0; b < (n >> H);\
    \ ++b) {\n      int l = b << H, r = (b + 1) << H;\n      if (R <= l) break;\n\
    \      if (r <= L) continue;\n      if (L <= l && r <= R) {\n        x = MX::op(x,\
    \ dat[H][l ^ xor_val]);\n        continue;\n      }\n      chmax(l, L), chmin(r,\
    \ R);\n      FOR(i, l, r) x = MX::op(x, dat[0][i ^ xor_val]);\n    }\n    return\
    \ x;\n  }\n};\n"
  code: "\n// prod_i(A_{i xor x}) \u306E\u3067\u304D\u308B\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u3002\n// set / prod \u3069\u3061\u3089\u3082 O(sqrt(N)) \u6642\u9593\
    \u3002\n// \u30E2\u30CE\u30A4\u30C9\u304C\u53EF\u63DB\u306A\u3089\u666E\u901A\u306E\
    \u30BB\u30B0\u6728\u3092\u4F7F\u3046\u3053\u3068\u3002\ntemplate <class Monoid>\n\
    struct Xor_SegTree {\n  static_assert(!Monoid::commute);\n  using MX = Monoid;\n\
    \  using X = typename MX::value_type;\n  using value_type = X;\n  vvc<X> dat;\n\
    \  int n, log, size;\n  int H; // \u5E45 2^H \u306E\u3068\u3053\u308D\u307E\u3067\
    \u4F5C\u308B\n\n  Xor_SegTree() {}\n  Xor_SegTree(int n) { build(n); }\n  template\
    \ <typename F>\n  Xor_SegTree(int n, F f) {\n    build(n, f);\n  }\n  Xor_SegTree(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    assert(n == size);\n    H = log / 2;\n    dat.assign(H + 1,\
    \ vc<X>(size));\n    FOR(i, n) dat[0][i] = f(i);\n    FOR(h, 1, H + 1) FOR(i,\
    \ n >> h) { update(h, i); }\n  }\n\n  X get(int i) { return dat[0][i]; }\n  vc<X>\
    \ get_all() { return dat[0]; }\n\n  void update(int h, int i) {\n    assert(0\
    \ < h && h <= H);\n    int cnt = 1 << (h - 1);\n    int a = i << h;\n    int b\
    \ = a + cnt;\n    FOR(k, cnt) {\n      dat[h][a + k] = MX::op(dat[h - 1][a + k],\
    \ dat[h - 1][b + k]);\n      dat[h][b + k] = MX::op(dat[h - 1][b + k], dat[h -\
    \ 1][a + k]);\n    }\n  }\n\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[0][i] = x;\n    FOR(h, 1, H + 1) {\n      i /= 2;\n      update(h, i);\n\
    \    }\n  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    dat[0][i]\
    \ = MX::op(dat[0][i], x);\n    FOR(h, 1, H + 1) {\n      i /= 2;\n      update(h,\
    \ i);\n    }\n  }\n\n  X prod(int L, int R, int xor_val) {\n    X x = MX::unit();\n\
    \    for (int b = 0; b < (n >> H); ++b) {\n      int l = b << H, r = (b + 1) <<\
    \ H;\n      if (R <= l) break;\n      if (r <= L) continue;\n      if (L <= l\
    \ && r <= R) {\n        x = MX::op(x, dat[H][l ^ xor_val]);\n        continue;\n\
    \      }\n      chmax(l, L), chmin(r, R);\n      FOR(i, l, r) x = MX::op(x, dat[0][i\
    \ ^ xor_val]);\n    }\n    return x;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/xor_segtree.hpp
  requiredBy: []
  timestamp: '2023-04-08 04:02:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2265.test.cpp
documentation_of: ds/segtree/xor_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/xor_segtree.hpp
- /library/ds/segtree/xor_segtree.hpp.html
title: ds/segtree/xor_segtree.hpp
---
