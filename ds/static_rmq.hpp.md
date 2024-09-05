---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/sparse_table/sparse_table.hpp\"\n\n// \u51AA\u7B49\u306A\
    \u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3002\
    disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\ntemplate <class Monoid>\n\
    struct Sparse_Table {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) {\
    \ build(n); }\n  template <typename F>\n  Sparse_Table(int n, F f) {\n    build(n,\
    \ f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v); }\n\n  void build(int m)\
    \ {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n    FOR(i,\
    \ n) dat[0][i] = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i])\
    \ - (1 << i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j]\
    \ = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) {\n    if (L == R) return MX::unit();\n    if (R == L + 1) return\
    \ dat[0][L];\n    int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R\
    \ - (1 << k)]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n    if (L == n) return\
    \ n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int k = (ok\
    \ + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n    \
    \  if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(0 <= R && R <= n && check(MX::unit()));\n\
    \    if (R == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n#line\
    \ 2 \"ds/static_rmq.hpp\"\n\n// \u69CB\u7BC9 O(N), \u30AF\u30A8\u30EA O(1)\n//\
    \ static_range_product \u3088\u308A\u9045\u3044\u3063\u307D\u3044\u306E\u3067\u4F7F\
    \u3046\u3053\u3068\u306F\u306A\u3055\u305D\u3046\u3060\ntemplate <typename Monoid>\n\
    struct Static_RMQ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  static constexpr int LOG = 4;\n  int N, b_num;\n  vc<X> A, pre, suf; // inclusive\n\
    \  Sparse_Table<Monoid> ST;\n\n  using u16 = unsigned short;\n  vc<u16> dat;\n\
    \n  Static_RMQ() {}\n  template <typename F>\n  Static_RMQ(int n, F f) {\n   \
    \ build(n, f);\n  }\n  Static_RMQ(const vc<X>& v) { build(v); }\n\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    N = m;\n    b_num = N >> LOG;\n\
    \    A.resize(N);\n    FOR(i, N) A[i] = f(i);\n    pre = A, suf = A;\n    FOR(i,\
    \ 1, N) {\n      if (i & 15) pre[i] = MX::op(pre[i - 1], A[i]);\n    }\n    FOR_R(i,\
    \ 1, N) {\n      if (i & 15) suf[i - 1] = MX::op(A[i - 1], suf[i]);\n    }\n \
    \   ST.build(b_num, [&](int i) -> X { return suf[i << LOG]; });\n    // \u9577\
    \u3055 16 \u4EE5\u4E0B\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\u3059\u308B\u305F\
    \u3081\u306E\u524D\u8A08\u7B97\n    // [i,i+16) \u5185\u3067 i+j \u304C [i,i+j]\
    \ \u3067\u306E\u6700\u5C0F\u5024\u3068\u306A\u308B\u5834\u5408\u306B j-th bit\
    \ \u3092\u7ACB\u3066\u308B\n    dat.resize(N);\n    u32 stack = 0;\n    FOR_R(i,\
    \ N) {\n      stack = (stack << 1) & 65535;\n      while (stack) {\n        int\
    \ k = lowbit(stack);\n        if (MX::op(A[i], A[i + k]) != A[i]) break;\n   \
    \     stack &= ~(u32(1) << k);\n      }\n      stack |= u32(1);\n      dat[i]\
    \ = stack;\n    }\n  }\n\n  X prod(int L, int R) {\n    assert(0 <= L && L <=\
    \ R && R <= N);\n    if (L == R) return MX::unit();\n    if (R - L <= 16) {\n\
    \      u32 d = dat[L] & ((u32(1) << (R - L)) - 1);\n      return A[L + topbit(d)];\n\
    \    }\n    --R;\n    int a = L >> LOG, b = R >> LOG;\n    X x = ST.prod(a + 1,\
    \ b);\n    x = MX::op(suf[L], x);\n    x = MX::op(x, pre[R]);\n    return x;\n\
    \  }\n};\n"
  code: "#include \"ds/sparse_table/sparse_table.hpp\"\n\n// \u69CB\u7BC9 O(N), \u30AF\
    \u30A8\u30EA O(1)\n// static_range_product \u3088\u308A\u9045\u3044\u3063\u307D\
    \u3044\u306E\u3067\u4F7F\u3046\u3053\u3068\u306F\u306A\u3055\u305D\u3046\u3060\
    \ntemplate <typename Monoid>\nstruct Static_RMQ {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  static constexpr int LOG = 4;\n  int N, b_num;\n\
    \  vc<X> A, pre, suf; // inclusive\n  Sparse_Table<Monoid> ST;\n\n  using u16\
    \ = unsigned short;\n  vc<u16> dat;\n\n  Static_RMQ() {}\n  template <typename\
    \ F>\n  Static_RMQ(int n, F f) {\n    build(n, f);\n  }\n  Static_RMQ(const vc<X>&\
    \ v) { build(v); }\n\n  void build(const vc<X>& v) {\n    build(len(v), [&](int\
    \ i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    N = m;\n    b_num = N >> LOG;\n    A.resize(N);\n    FOR(i, N) A[i]\
    \ = f(i);\n    pre = A, suf = A;\n    FOR(i, 1, N) {\n      if (i & 15) pre[i]\
    \ = MX::op(pre[i - 1], A[i]);\n    }\n    FOR_R(i, 1, N) {\n      if (i & 15)\
    \ suf[i - 1] = MX::op(A[i - 1], suf[i]);\n    }\n    ST.build(b_num, [&](int i)\
    \ -> X { return suf[i << LOG]; });\n    // \u9577\u3055 16 \u4EE5\u4E0B\u306E\u30AF\
    \u30A8\u30EA\u306B\u5BFE\u5FDC\u3059\u308B\u305F\u3081\u306E\u524D\u8A08\u7B97\
    \n    // [i,i+16) \u5185\u3067 i+j \u304C [i,i+j] \u3067\u306E\u6700\u5C0F\u5024\
    \u3068\u306A\u308B\u5834\u5408\u306B j-th bit \u3092\u7ACB\u3066\u308B\n    dat.resize(N);\n\
    \    u32 stack = 0;\n    FOR_R(i, N) {\n      stack = (stack << 1) & 65535;\n\
    \      while (stack) {\n        int k = lowbit(stack);\n        if (MX::op(A[i],\
    \ A[i + k]) != A[i]) break;\n        stack &= ~(u32(1) << k);\n      }\n     \
    \ stack |= u32(1);\n      dat[i] = stack;\n    }\n  }\n\n  X prod(int L, int R)\
    \ {\n    assert(0 <= L && L <= R && R <= N);\n    if (L == R) return MX::unit();\n\
    \    if (R - L <= 16) {\n      u32 d = dat[L] & ((u32(1) << (R - L)) - 1);\n \
    \     return A[L + topbit(d)];\n    }\n    --R;\n    int a = L >> LOG, b = R >>\
    \ LOG;\n    X x = ST.prod(a + 1, b);\n    x = MX::op(suf[L], x);\n    x = MX::op(x,\
    \ pre[R]);\n    return x;\n  }\n};\n"
  dependsOn:
  - ds/sparse_table/sparse_table.hpp
  isVerificationFile: false
  path: ds/static_rmq.hpp
  requiredBy: []
  timestamp: '2024-09-06 01:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/static_rmq.hpp
layout: document
redirect_from:
- /library/ds/static_rmq.hpp
- /library/ds/static_rmq.hpp.html
title: ds/static_rmq.hpp
---
