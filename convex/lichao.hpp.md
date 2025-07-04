---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/line_add_get_min_lichao_2.test.cpp
    title: test/2_library_checker/data_structure/line_add_get_min_lichao_2.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/segment_add_get_min_2.test.cpp
    title: test/2_library_checker/data_structure/segment_add_get_min_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1867.test.cpp
    title: test/3_yukicoder/1867.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/705_2.test.cpp
    title: test/3_yukicoder/705_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/lichao.hpp\"\n/*\nstruct F {\n  using value_type\
    \ = ll;  // operator() \u306E\u623B\u308A\u5024\n  int a;\n  ll b;\n  ll operator()(ll\
    \ x) { return a * x + b; }\n};\n*/\n\n// \u8A55\u4FA1\u70B9\u306F ll\n// FUNC\
    \ f \u306B\u306F T operator() \u3092\u5B9A\u7FA9\u3059\u308B, T \u306F\u6BD4\u8F03\
    \u53EF\u80FD\u306A\u578B\n// 1\u6B21\u5F0F\uFF1AFUNC = LiChaoTree_Line\ntemplate\
    \ <typename FUNC, bool COMPRESS, bool MINIMIZE>\nstruct LiChao_Tree {\n  using\
    \ T = typename FUNC::value_type;\n  vc<ll> X;\n  ll lo, hi;\n  vc<FUNC> dat;\n\
    \  int n, log, size;\n\n  inline int get_idx(ll x) {\n    if constexpr (COMPRESS)\
    \ { return LB(X, x); }\n    assert(lo <= x && x <= hi);\n    return x - lo;\n\
    \  }\n\n  LiChao_Tree(const vc<ll>& pts, FUNC default_fn) {\n    static_assert(COMPRESS);\n\
    \    for (auto&& x: pts) X.eb(x);\n    UNIQUE(X);\n    if (X.empty()) X.eb(0);\n\
    \    n = len(X), log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 <<\
    \ log;\n    dat.assign(size << 1, default_fn);\n  }\n\n  LiChao_Tree(ll lo, ll\
    \ hi, FUNC default_fn) : lo(lo), hi(hi) {\n    static_assert(!COMPRESS);\n   \
    \ n = hi - lo, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n\
    \    dat.assign(size << 1, default_fn);\n  }\n\n  void chmin_line(FUNC f) {\n\
    \    static_assert(MINIMIZE);\n    return add_line_at(1, f);\n  }\n  void chmax_line(FUNC\
    \ f) {\n    static_assert(!MINIMIZE);\n    return add_line_at(1, f);\n  }\n\n\
    \  void chmin_segment(ll xl, ll xr, FUNC f) {\n    static_assert(MINIMIZE);\n\
    \    xl = get_idx(xl), xr = get_idx(xr);\n    xl += size, xr += size;\n    while\
    \ (xl < xr) {\n      if (xl & 1) add_line_at(xl++, f);\n      if (xr & 1) add_line_at(--xr,\
    \ f);\n      xl >>= 1, xr >>= 1;\n    }\n  }\n\n  void chmax_segment(ll xl, ll\
    \ xr, FUNC f) {\n    static_assert(!MINIMIZE);\n    xl = get_idx(xl), xr = get_idx(xr);\n\
    \    xl += size, xr += size;\n    while (xl < xr) {\n      if (xl & 1) add_line_at(xl++,\
    \ f);\n      if (xr & 1) add_line_at(--xr, f);\n      xl >>= 1, xr >>= 1;\n  \
    \  }\n  }\n\n  // \u6700\u9069\u306A\u5024\u3068 FUNC \u306E pair\n  pair<T, FUNC>\
    \ query(ll x) {\n    FUNC f = dat[0]; // default_fn\n    T fx = f(x);\n    int\
    \ i = get_idx(x) + size;\n    while (i) {\n      FUNC g = dat[i];\n      T gx\
    \ = g(x);\n      if ((MINIMIZE && gx < fx) || (!MINIMIZE && gx > fx)) { f = g,\
    \ fx = gx; }\n      i >>= 1;\n    }\n    return {fx, f};\n  }\n\n  void add_line_at(int\
    \ i, FUNC f) {\n    int upper_bit = 31 - __builtin_clz(i);\n    int l = (size\
    \ >> upper_bit) * (i - (1 << upper_bit));\n    int r = l + (size >> upper_bit);\n\
    \    while (l < r) {\n      FUNC g = dat[i];\n      T fl = evaluate_inner(f, l),\
    \ fr = evaluate_inner(f, r - 1);\n      T gl = evaluate_inner(g, l), gr = evaluate_inner(g,\
    \ r - 1);\n      bool bl = (MINIMIZE ? fl < gl : fl > gl);\n      bool br = (MINIMIZE\
    \ ? fr < gr : fr > gr);\n      if (bl && br) {\n        dat[i] = f;\n        return;\n\
    \      }\n      if (!bl && !br) return;\n      int m = (l + r) / 2;\n      T fm\
    \ = evaluate_inner(f, m), gm = evaluate_inner(g, m);\n      bool bm = (MINIMIZE\
    \ ? fm < gm : fm > gm);\n      if (bm) {\n        dat[i] = f;\n        f = g;\n\
    \        if (!bl) { i = 2 * i + 0, r = m; }\n        if (bl) { i = 2 * i + 1,\
    \ l = m; }\n      }\n      if (!bm) {\n        if (bl) { i = 2 * i + 0, r = m;\
    \ }\n        if (!bl) { i = 2 * i + 1, l = m; }\n      }\n    }\n  }\n\nprivate:\n\
    \  inline T evaluate_inner(FUNC& f, ll x) { return f((COMPRESS ? X[min<int>(x,\
    \ n - 1)] : min<int>(x + lo, hi - 1))); }\n};\n"
  code: "/*\nstruct F {\n  using value_type = ll;  // operator() \u306E\u623B\u308A\
    \u5024\n  int a;\n  ll b;\n  ll operator()(ll x) { return a * x + b; }\n};\n*/\n\
    \n// \u8A55\u4FA1\u70B9\u306F ll\n// FUNC f \u306B\u306F T operator() \u3092\u5B9A\
    \u7FA9\u3059\u308B, T \u306F\u6BD4\u8F03\u53EF\u80FD\u306A\u578B\n// 1\u6B21\u5F0F\
    \uFF1AFUNC = LiChaoTree_Line\ntemplate <typename FUNC, bool COMPRESS, bool MINIMIZE>\n\
    struct LiChao_Tree {\n  using T = typename FUNC::value_type;\n  vc<ll> X;\n  ll\
    \ lo, hi;\n  vc<FUNC> dat;\n  int n, log, size;\n\n  inline int get_idx(ll x)\
    \ {\n    if constexpr (COMPRESS) { return LB(X, x); }\n    assert(lo <= x && x\
    \ <= hi);\n    return x - lo;\n  }\n\n  LiChao_Tree(const vc<ll>& pts, FUNC default_fn)\
    \ {\n    static_assert(COMPRESS);\n    for (auto&& x: pts) X.eb(x);\n    UNIQUE(X);\n\
    \    if (X.empty()) X.eb(0);\n    n = len(X), log = 1;\n    while ((1 << log)\
    \ < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, default_fn);\n\
    \  }\n\n  LiChao_Tree(ll lo, ll hi, FUNC default_fn) : lo(lo), hi(hi) {\n    static_assert(!COMPRESS);\n\
    \    n = hi - lo, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 <<\
    \ log;\n    dat.assign(size << 1, default_fn);\n  }\n\n  void chmin_line(FUNC\
    \ f) {\n    static_assert(MINIMIZE);\n    return add_line_at(1, f);\n  }\n  void\
    \ chmax_line(FUNC f) {\n    static_assert(!MINIMIZE);\n    return add_line_at(1,\
    \ f);\n  }\n\n  void chmin_segment(ll xl, ll xr, FUNC f) {\n    static_assert(MINIMIZE);\n\
    \    xl = get_idx(xl), xr = get_idx(xr);\n    xl += size, xr += size;\n    while\
    \ (xl < xr) {\n      if (xl & 1) add_line_at(xl++, f);\n      if (xr & 1) add_line_at(--xr,\
    \ f);\n      xl >>= 1, xr >>= 1;\n    }\n  }\n\n  void chmax_segment(ll xl, ll\
    \ xr, FUNC f) {\n    static_assert(!MINIMIZE);\n    xl = get_idx(xl), xr = get_idx(xr);\n\
    \    xl += size, xr += size;\n    while (xl < xr) {\n      if (xl & 1) add_line_at(xl++,\
    \ f);\n      if (xr & 1) add_line_at(--xr, f);\n      xl >>= 1, xr >>= 1;\n  \
    \  }\n  }\n\n  // \u6700\u9069\u306A\u5024\u3068 FUNC \u306E pair\n  pair<T, FUNC>\
    \ query(ll x) {\n    FUNC f = dat[0]; // default_fn\n    T fx = f(x);\n    int\
    \ i = get_idx(x) + size;\n    while (i) {\n      FUNC g = dat[i];\n      T gx\
    \ = g(x);\n      if ((MINIMIZE && gx < fx) || (!MINIMIZE && gx > fx)) { f = g,\
    \ fx = gx; }\n      i >>= 1;\n    }\n    return {fx, f};\n  }\n\n  void add_line_at(int\
    \ i, FUNC f) {\n    int upper_bit = 31 - __builtin_clz(i);\n    int l = (size\
    \ >> upper_bit) * (i - (1 << upper_bit));\n    int r = l + (size >> upper_bit);\n\
    \    while (l < r) {\n      FUNC g = dat[i];\n      T fl = evaluate_inner(f, l),\
    \ fr = evaluate_inner(f, r - 1);\n      T gl = evaluate_inner(g, l), gr = evaluate_inner(g,\
    \ r - 1);\n      bool bl = (MINIMIZE ? fl < gl : fl > gl);\n      bool br = (MINIMIZE\
    \ ? fr < gr : fr > gr);\n      if (bl && br) {\n        dat[i] = f;\n        return;\n\
    \      }\n      if (!bl && !br) return;\n      int m = (l + r) / 2;\n      T fm\
    \ = evaluate_inner(f, m), gm = evaluate_inner(g, m);\n      bool bm = (MINIMIZE\
    \ ? fm < gm : fm > gm);\n      if (bm) {\n        dat[i] = f;\n        f = g;\n\
    \        if (!bl) { i = 2 * i + 0, r = m; }\n        if (bl) { i = 2 * i + 1,\
    \ l = m; }\n      }\n      if (!bm) {\n        if (bl) { i = 2 * i + 0, r = m;\
    \ }\n        if (!bl) { i = 2 * i + 1, l = m; }\n      }\n    }\n  }\n\nprivate:\n\
    \  inline T evaluate_inner(FUNC& f, ll x) { return f((COMPRESS ? X[min<int>(x,\
    \ n - 1)] : min<int>(x + lo, hi - 1))); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/lichao.hpp
  requiredBy: []
  timestamp: '2025-01-16 21:29:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/data_structure/line_add_get_min_lichao_2.test.cpp
  - test/2_library_checker/data_structure/segment_add_get_min_2.test.cpp
  - test/3_yukicoder/1867.test.cpp
  - test/3_yukicoder/705_2.test.cpp
documentation_of: convex/lichao.hpp
layout: document
redirect_from:
- /library/convex/lichao.hpp
- /library/convex/lichao.hpp.html
title: convex/lichao.hpp
---
