---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/sparse_table/disjoint_sparse_table.hpp
    title: ds/sparse_table/disjoint_sparse_table.hpp
  - icon: ':question:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/staticrmq.test.cpp
    title: test/2_library_checker/data_structure/staticrmq.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/106668
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
    \ 2 \"ds/sparse_table/disjoint_sparse_table.hpp\"\n\r\ntemplate <class Monoid>\r\
    \nstruct Disjoint_Sparse_Table {\r\n  using MX = Monoid;\r\n  using X = typename\
    \ MX::value_type;\r\n  int n, log;\r\n  vvc<X> dat;\r\n\r\n  Disjoint_Sparse_Table()\
    \ {}\r\n  Disjoint_Sparse_Table(int n) { build(n); }\r\n  template <typename F>\r\
    \n  Disjoint_Sparse_Table(int n, F f) {\r\n    build(n, f);\r\n  }\r\n  Disjoint_Sparse_Table(const\
    \ vc<X>& v) { build(v); }\r\n\r\n  void build(int m) {\r\n    build(m, [](int\
    \ i) -> X { return MX::unit(); });\r\n  }\r\n  void build(const vc<X>& v) {\r\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\r\n  }\r\n  template <typename\
    \ F>\r\n  void build(int m, F f) {\r\n    n = m, log = 1;\r\n    while ((1 <<\
    \ log) < n) ++log;\r\n    dat.resize(log);\r\n    dat[0].reserve(n);\r\n    FOR(i,\
    \ n) dat[0].eb(f(i));\r\n    FOR(i, 1, log) {\r\n      auto& v = dat[i];\r\n \
    \     v = dat[0];\r\n      int b = 1 << i;\r\n      for (int m = b; m <= n; m\
    \ += 2 * b) {\r\n        int L = m - b, R = min(n, m + b);\r\n        FOR_R(j,\
    \ L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\r\n        FOR(j, m, R - 1) v[j\
    \ + 1] = MX::op(v[j], v[j + 1]);\r\n      }\r\n    }\r\n  }\r\n\r\n  X prod(int\
    \ L, int R) {\r\n    if (L == R) return MX::unit();\r\n    --R;\r\n    if (L ==\
    \ R) return dat[0][L];\r\n    int k = topbit(L ^ R);\r\n    return MX::op(dat[k][L],\
    \ dat[k][R]);\r\n  }\r\n\r\n  template <class F>\r\n  int max_right(const F check,\
    \ int L) {\r\n    assert(0 <= L && L <= n && check(MX::unit()));\r\n    if (L\
    \ == n) return n;\r\n    int ok = L, ng = n + 1;\r\n    while (ok + 1 < ng) {\r\
    \n      int k = (ok + ng) / 2;\r\n      bool bl = check(prod(L, k));\r\n     \
    \ if (bl) ok = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\n  }\r\
    \n\r\n  template <class F>\r\n  int min_left(const F check, int R) {\r\n    assert(0\
    \ <= R && R <= n && check(MX::unit()));\r\n    if (R == 0) return 0;\r\n    int\
    \ ok = R, ng = -1;\r\n    while (ng + 1 < ok) {\r\n      int k = (ok + ng) / 2;\r\
    \n      bool bl = check(prod(k, R));\r\n      if (bl) ok = k;\r\n      if (!bl)\
    \ ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n};\n#line 3 \"ds/static_range_product.hpp\"\
    \n\n/*\n\u53C2\u8003\uFF1Ahttps://judge.yosupo.jp/submission/106668\n\u9577\u3055\
    \ 2^LOG \u306E\u30D6\u30ED\u30C3\u30AF\u306B\u5206\u3051\u308B\uFF0E\u30D6\u30ED\
    \u30C3\u30AF\u5185\u306E prefix, suffix \u3092\u6301\u3064\uFF0E\n\u30D6\u30ED\
    \u30C3\u30AF\u7A4D\u306E\u5217\u3092 ST(DST) \u3067\u6301\u3064\uFF0E\u30D6\u30ED\
    \u30C3\u30AF\u3092\u307E\u305F\u3050\u7A4D\u306F O(1).\n\u77ED\u3044\u3082\u306E\
    \u306F O(1) \u3092\u8AE6\u3081\u3066\u611A\u76F4\u3068\u3044\u3046\u3053\u3068\
    \u306B\u3059\u308B\uFF0E\n\u524D\u8A08\u7B97\uFF1AO(Nlog(N)/2^LOG)\n\u30AF\u30A8\
    \u30EA\uFF1AO(1) / worst O(2^LOG)\n*/\ntemplate <typename Monoid, typename SPARSE_TABLE,\
    \ int LOG = 4>\nstruct Static_Range_Product {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  int N, b_num;\n  vc<X> A, pre, suf; // inclusive\n\
    \  SPARSE_TABLE ST;\n\n  Static_Range_Product() {}\n  template <typename F>\n\
    \  Static_Range_Product(int n, F f) {\n    build(n, f);\n  }\n  Static_Range_Product(const\
    \ vc<X>& v) { build(v); }\n\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    N = m;\n    b_num = N >> LOG;\n    A.resize(N);\n    FOR(i, N)\
    \ A[i] = f(i);\n    pre = A, suf = A;\n    constexpr int mask = (1 << LOG) - 1;\n\
    \    FOR(i, 1, N) {\n      if (i & mask) pre[i] = MX::op(pre[i - 1], A[i]);\n\
    \    }\n    FOR_R(i, 1, N) {\n      if (i & mask) suf[i - 1] = MX::op(A[i - 1],\
    \ suf[i]);\n    }\n    ST.build(b_num, [&](int i) -> X { return suf[i << LOG];\
    \ });\n  }\n\n  // O(1) or O(R-L)\n  X prod(int L, int R) {\n    if (L == R) return\
    \ MX::unit();\n    R -= 1;\n    int a = L >> LOG, b = R >> LOG;\n    if (a < b)\
    \ {\n      X x = ST.prod(a + 1, b);\n      x = MX::op(suf[L], x);\n      x = MX::op(x,\
    \ pre[R]);\n      return x;\n    }\n    X x = A[L];\n    FOR(i, L + 1, R + 1)\
    \ x = MX::op(x, A[i]);\n    return x;\n  }\n};\n"
  code: "#include \"ds/sparse_table/sparse_table.hpp\"\n#include \"ds/sparse_table/disjoint_sparse_table.hpp\"\
    \n\n/*\n\u53C2\u8003\uFF1Ahttps://judge.yosupo.jp/submission/106668\n\u9577\u3055\
    \ 2^LOG \u306E\u30D6\u30ED\u30C3\u30AF\u306B\u5206\u3051\u308B\uFF0E\u30D6\u30ED\
    \u30C3\u30AF\u5185\u306E prefix, suffix \u3092\u6301\u3064\uFF0E\n\u30D6\u30ED\
    \u30C3\u30AF\u7A4D\u306E\u5217\u3092 ST(DST) \u3067\u6301\u3064\uFF0E\u30D6\u30ED\
    \u30C3\u30AF\u3092\u307E\u305F\u3050\u7A4D\u306F O(1).\n\u77ED\u3044\u3082\u306E\
    \u306F O(1) \u3092\u8AE6\u3081\u3066\u611A\u76F4\u3068\u3044\u3046\u3053\u3068\
    \u306B\u3059\u308B\uFF0E\n\u524D\u8A08\u7B97\uFF1AO(Nlog(N)/2^LOG)\n\u30AF\u30A8\
    \u30EA\uFF1AO(1) / worst O(2^LOG)\n*/\ntemplate <typename Monoid, typename SPARSE_TABLE,\
    \ int LOG = 4>\nstruct Static_Range_Product {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  int N, b_num;\n  vc<X> A, pre, suf; // inclusive\n\
    \  SPARSE_TABLE ST;\n\n  Static_Range_Product() {}\n  template <typename F>\n\
    \  Static_Range_Product(int n, F f) {\n    build(n, f);\n  }\n  Static_Range_Product(const\
    \ vc<X>& v) { build(v); }\n\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    N = m;\n    b_num = N >> LOG;\n    A.resize(N);\n    FOR(i, N)\
    \ A[i] = f(i);\n    pre = A, suf = A;\n    constexpr int mask = (1 << LOG) - 1;\n\
    \    FOR(i, 1, N) {\n      if (i & mask) pre[i] = MX::op(pre[i - 1], A[i]);\n\
    \    }\n    FOR_R(i, 1, N) {\n      if (i & mask) suf[i - 1] = MX::op(A[i - 1],\
    \ suf[i]);\n    }\n    ST.build(b_num, [&](int i) -> X { return suf[i << LOG];\
    \ });\n  }\n\n  // O(1) or O(R-L)\n  X prod(int L, int R) {\n    if (L == R) return\
    \ MX::unit();\n    R -= 1;\n    int a = L >> LOG, b = R >> LOG;\n    if (a < b)\
    \ {\n      X x = ST.prod(a + 1, b);\n      x = MX::op(suf[L], x);\n      x = MX::op(x,\
    \ pre[R]);\n      return x;\n    }\n    X x = A[L];\n    FOR(i, L + 1, R + 1)\
    \ x = MX::op(x, A[i]);\n    return x;\n  }\n};"
  dependsOn:
  - ds/sparse_table/sparse_table.hpp
  - ds/sparse_table/disjoint_sparse_table.hpp
  isVerificationFile: false
  path: ds/static_range_product.hpp
  requiredBy: []
  timestamp: '2024-02-11 04:08:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/data_structure/staticrmq.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
documentation_of: ds/static_range_product.hpp
layout: document
redirect_from:
- /library/ds/static_range_product.hpp
- /library/ds/static_range_product.hpp.html
title: ds/static_range_product.hpp
---
