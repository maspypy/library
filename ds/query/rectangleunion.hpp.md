---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group/add.hpp
    title: alg/group/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy/cntminmincnt_add.hpp
    title: alg/lazy/cntminmincnt_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/cntminmincnt.hpp
    title: alg/monoid/cntminmincnt.hpp
  - icon: ':question:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_4_A.test.cpp
    title: test/aoj/DSL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
    title: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/lazysegtree.hpp\"\n\ntemplate <typename Lazy>\nstruct\
    \ LazySegTree {\n  using Monoid_X = typename Lazy::X_structure;\n  using Monoid_A\
    \ = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  int n, log, size;\n  vc<X> dat;\n\
    \  vc<A> laz;\n\n  LazySegTree() : LazySegTree(0) {}\n  LazySegTree(int n) : LazySegTree(vc<X>(n,\
    \ Monoid_X::unit())) {}\n  LazySegTree(vc<X> v) : n(len(v)) {\n    log = 1;\n\
    \    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid_X::unit());\n    laz.assign(size, Monoid_A::unit());\n    FOR(i,\
    \ n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  template\
    \ <typename F>\n  LazySegTree(int n, F f) : n(n) {\n    log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid_X::unit());\n\
    \    laz.assign(size, Monoid_A::unit());\n    FOR(i, n) dat[size + i] = f(i);\n\
    \    FOR3_R(i, 1, size) update(i);\n  }\n\n  void reset() {\n    fill(all(dat),\
    \ Monoid_X::unit());\n    fill(all(laz), Monoid_A::unit());\n  }\n\n  void reset(const\
    \ vc<X>& v) {\n    assert(len(v) == n);\n    reset();\n    FOR(i, n) dat[size\
    \ + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  void update(int k)\
    \ { dat[k] = Monoid_X::op(dat[2 * k], dat[2 * k + 1]); }\n\n  void all_apply(int\
    \ k, A a) {\n    dat[k] = Lazy::act(dat[k], a);\n    if (k < size) laz[k] = Monoid_A::op(laz[k],\
    \ a);\n  }\n\n  void push(int k) {\n    all_apply(2 * k, laz[k]);\n    all_apply(2\
    \ * k + 1, laz[k]);\n    laz[k] = Monoid_A::unit();\n  }\n\n  void set(int p,\
    \ X x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n   \
    \ p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return dat[p];\n\
    \  }\n\n  vc<X> get_all() {\n    FOR(i, size) push(i);\n    return {dat.begin()\
    \ + size, dat.begin() + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return Monoid_X::unit();\n\n   \
    \ l += size;\n    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if\
    \ (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n    }\n\n    X xl = Monoid_X::unit(), xr = Monoid_X::unit();\n\
    \    while (l < r) {\n      if (l & 1) xl = Monoid_X::op(xl, dat[l++]);\n    \
    \  if (r & 1) xr = Monoid_X::op(dat[--r], xr);\n      l >>= 1;\n      r >>= 1;\n\
    \    }\n\n    return Monoid_X::op(xl, xr);\n  }\n\n  X prod_all() { return dat[1];\
    \ }\n\n  void apply(int p, A a) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    dat[p] = Lazy::act(dat[p], a);\n    for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n  }\n\n  void apply(int l, int r, A a) {\n    assert(0 <= l && l <=\
    \ r && r <= n);\n    if (l == r) return;\n\n    l += size;\n    r += size;\n\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\n    {\n\
    \      int l2 = l, r2 = r;\n      while (l < r) {\n        if (l & 1) all_apply(l++,\
    \ a);\n        if (r & 1) all_apply(--r, a);\n        l >>= 1;\n        r >>=\
    \ 1;\n      }\n      l = l2;\n      r = r2;\n    }\n\n    for (int i = 1; i <=\
    \ log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  template <typename\
    \ C>\n  int max_right(C& check, int l) {\n    assert(0 <= l && l <= n);\n    assert(check(Monoid_X::unit()));\n\
    \    if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--)\
    \ push(l >> i);\n    X sm = Monoid_X::unit();\n    do {\n      while (l % 2 ==\
    \ 0) l >>= 1;\n      if (!check(Monoid_X::op(sm, dat[l]))) {\n        while (l\
    \ < size) {\n          push(l);\n          l = (2 * l);\n          if (check(Monoid_X::op(sm,\
    \ dat[l]))) {\n            sm = Monoid_X::op(sm, dat[l]);\n            l++;\n\
    \          }\n        }\n        return l - size;\n      }\n      sm = Monoid_X::op(sm,\
    \ dat[l]);\n      l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n\n \
    \ template <typename C>\n  int min_left(C& check, int r) {\n    assert(0 <= r\
    \ && r <= n);\n    assert(check(Monoid_X::unit()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = Monoid_X::unit();\n    do {\n      r--;\n      while (r > 1 && (r % 2))\
    \ r >>= 1;\n      if (!check(Monoid_X::op(dat[r], sm))) {\n        while (r <\
    \ size) {\n          push(r);\n          r = (2 * r + 1);\n          if (check(Monoid_X::op(dat[r],\
    \ sm))) {\n            sm = Monoid_X::op(dat[r], sm);\n            r--;\n    \
    \      }\n        }\n        return r + 1 - size;\n      }\n      sm = Monoid_X::op(dat[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n  void debug() { print(\"\
    lazysegtree getall:\", get_all()); }\n};\n#line 2 \"alg/monoid/cntminmincnt.hpp\"\
    \n\r\n// \u5168\u4F53\u306E\u500B\u6570\u3001\u6700\u5C0F\u5024\u3001\u6700\u5C0F\
    \u5024\u306E\u500B\u6570\r\ntemplate <typename E>\r\nstruct Monoid_CntMinMincnt\
    \ {\r\n  using value_type = tuple<E, E, E>;\r\n  using X = value_type;\r\n  static\
    \ X from_element(E x) { return {1, x, 1}; }\r\n  static X op(X x, X y) {\r\n \
    \   auto [xcnt, xmin, xmincnt] = x;\r\n    auto [ycnt, ymin, ymincnt] = y;\r\n\
    \    if (xmin > ymin) return {xcnt + ycnt, ymin, ymincnt};\r\n    if (xmin ==\
    \ ymin) return {xcnt + ycnt, xmin, xmincnt + ymincnt};\r\n    return {xcnt + ycnt,\
    \ xmin, xmincnt};\r\n  }\r\n  static constexpr X unit() { return {0, numeric_limits<E>::max(),\
    \ 0}; }\r\n  static constexpr bool commute = true;\r\n};\n#line 2 \"alg/group/add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Group_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/lazy/cntminmincnt_add.hpp\"\n\r\n\
    template <typename E>\r\nstruct Lazy_CntMinMincnt_Add {\r\n  using MX = Monoid_CntMinMincnt<E>;\r\
    \n  using MA = Group_Add<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    auto [xcnt, xmin,\
    \ xmincnt] = x;\r\n    if (xmin == numeric_limits<ll>::max()) return x;\r\n  \
    \  return {xcnt, xmin + a, xmincnt};\r\n  }\r\n};\r\n#line 3 \"ds/query/rectangleunion.hpp\"\
    \n\r\ntemplate <typename XY = int>\r\nstruct RectangleUnion {\r\n  using RECT\
    \ = tuple<XY, XY, XY, XY>;\r\n  vc<RECT> rectangles;\r\n  vc<XY> X, Y;\r\n\r\n\
    \  void add_rect(int xl, int xr, int yl, int yr) {\r\n    assert(xl < xr && yl\
    \ < yr);\r\n    X.eb(xl), X.eb(xr), Y.eb(yl), Y.eb(yr);\r\n    rectangles.eb(xl,\
    \ xr, yl, yr);\r\n  }\r\n\r\n  template <typename ANS_TYPE = ll>\r\n  ANS_TYPE\
    \ calc() {\r\n    UNIQUE(X), UNIQUE(Y);\r\n    int N = len(X);\r\n    vc<vc<pair<int,\
    \ int>>> add(N), rm(N);\r\n    for (auto &&[xl, xr, yl, yr]: rectangles) {\r\n\
    \      xl = LB(X, xl), xr = LB(X, xr);\r\n      yl = LB(Y, yl), yr = LB(Y, yr);\r\
    \n      add[xl].eb(yl, yr);\r\n      rm[xr].eb(yl, yr);\r\n    }\r\n\r\n    using\
    \ Lazy = Lazy_CntMinMincnt_Add<XY>;\r\n    using T = typename Lazy::X_structure::value_type;\r\
    \n    LazySegTree<Lazy> seg(len(Y) - 1, [&](int i) -> T {\r\n      return {Y[i\
    \ + 1] - Y[i], 0, Y[i + 1] - Y[i]};\r\n    });\r\n    ANS_TYPE ANS = 0;\r\n  \
    \  FOR(i, len(X) - 1) {\r\n      ANS_TYPE dx = X[i + 1] - X[i];\r\n      for (auto\
    \ &&[yl, yr]: add[i]) seg.apply(yl, yr, 1);\r\n      for (auto &&[yl, yr]: rm[i])\
    \ seg.apply(yl, yr, -1);\r\n      auto [cnt, min, mincnt] = seg.prod_all();\r\n\
    \      ANS_TYPE n = cnt;\r\n      if (min == 0) n -= mincnt;\r\n      ANS += n\
    \ * dx;\r\n    }\r\n    return ANS;\r\n  }\r\n};\r\n"
  code: "#include \"ds/lazysegtree.hpp\"\r\n#include \"alg/lazy/cntminmincnt_add.hpp\"\
    \r\n\r\ntemplate <typename XY = int>\r\nstruct RectangleUnion {\r\n  using RECT\
    \ = tuple<XY, XY, XY, XY>;\r\n  vc<RECT> rectangles;\r\n  vc<XY> X, Y;\r\n\r\n\
    \  void add_rect(int xl, int xr, int yl, int yr) {\r\n    assert(xl < xr && yl\
    \ < yr);\r\n    X.eb(xl), X.eb(xr), Y.eb(yl), Y.eb(yr);\r\n    rectangles.eb(xl,\
    \ xr, yl, yr);\r\n  }\r\n\r\n  template <typename ANS_TYPE = ll>\r\n  ANS_TYPE\
    \ calc() {\r\n    UNIQUE(X), UNIQUE(Y);\r\n    int N = len(X);\r\n    vc<vc<pair<int,\
    \ int>>> add(N), rm(N);\r\n    for (auto &&[xl, xr, yl, yr]: rectangles) {\r\n\
    \      xl = LB(X, xl), xr = LB(X, xr);\r\n      yl = LB(Y, yl), yr = LB(Y, yr);\r\
    \n      add[xl].eb(yl, yr);\r\n      rm[xr].eb(yl, yr);\r\n    }\r\n\r\n    using\
    \ Lazy = Lazy_CntMinMincnt_Add<XY>;\r\n    using T = typename Lazy::X_structure::value_type;\r\
    \n    LazySegTree<Lazy> seg(len(Y) - 1, [&](int i) -> T {\r\n      return {Y[i\
    \ + 1] - Y[i], 0, Y[i + 1] - Y[i]};\r\n    });\r\n    ANS_TYPE ANS = 0;\r\n  \
    \  FOR(i, len(X) - 1) {\r\n      ANS_TYPE dx = X[i + 1] - X[i];\r\n      for (auto\
    \ &&[yl, yr]: add[i]) seg.apply(yl, yr, 1);\r\n      for (auto &&[yl, yr]: rm[i])\
    \ seg.apply(yl, yr, -1);\r\n      auto [cnt, min, mincnt] = seg.prod_all();\r\n\
    \      ANS_TYPE n = cnt;\r\n      if (min == 0) n -= mincnt;\r\n      ANS += n\
    \ * dx;\r\n    }\r\n    return ANS;\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/lazysegtree.hpp
  - alg/lazy/cntminmincnt_add.hpp
  - alg/monoid/cntminmincnt.hpp
  - alg/group/add.hpp
  isVerificationFile: false
  path: ds/query/rectangleunion.hpp
  requiredBy: []
  timestamp: '2022-11-14 21:12:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  - test/aoj/DSL_4_A.test.cpp
documentation_of: ds/query/rectangleunion.hpp
layout: document
redirect_from:
- /library/ds/query/rectangleunion.hpp
- /library/ds/query/rectangleunion.hpp.html
title: ds/query/rectangleunion.hpp
---
